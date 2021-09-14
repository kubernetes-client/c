#include <stdio.h>
#include "kube_exec.h"

#define WS_PATH_BUFFER_SIZE 1024
#define URL_COMMAND_STRING_BUFFER_SIZE 1024
#define COMMAND_STRING_DELIM " "
#define COMMAND_PREFIX "&command="
#define CONTAINER_PREFIX "&container="
#define ESCAPED_STRING_BUFFER_SIZE 8
#define ESCAPED_STRING_LENGTH 4
#define TRUE_STRING "true"
#define FALSE_STRING "false"

static void default_exec_data_callback(void **p_data_received, long *p_data_received_len)
{
    printf("%s: Received %ld bytes:\n%s", __func__, *p_data_received_len, (char *) (*p_data_received));
}

static void escape_character_in_url(char *escaped, int escaped_buffer_size, const char chr)
{
    if (!escaped || escaped_buffer_size < ESCAPED_STRING_LENGTH + 1) {
        return;
    }

    if ('+' == chr) {
        strncpy(escaped, "%2B", ESCAPED_STRING_LENGTH);
    } else if ('"' == chr) {
        strncpy(escaped, "%22", ESCAPED_STRING_LENGTH);
    } else if ('%' == chr) {
        strncpy(escaped, "%25", ESCAPED_STRING_LENGTH);
    } else {
        snprintf(escaped, ESCAPED_STRING_LENGTH, "%c", chr);
    }
}

static int assemble_command_in_url(char *command_string_in_url, int url_command_string_buffer_size, const char *original_command_string)
{
    int command_string_length = 0;
    const char *p = original_command_string;
    char escaped_string[ESCAPED_STRING_BUFFER_SIZE];
    while (*p) {
        if (' ' == *p) {
            command_string_length += strlen(COMMAND_PREFIX);
            if (command_string_length >= url_command_string_buffer_size) {
                fprintf(stderr, "%s: The length of command string exceeds the buffer size.", __func__);
                return -1;
            }
            strncat(command_string_in_url, COMMAND_PREFIX, strlen(COMMAND_PREFIX));
        } else {
            memset(escaped_string, 0, sizeof(escaped_string));
            escape_character_in_url(escaped_string, ESCAPED_STRING_BUFFER_SIZE, *p);
            command_string_length += strlen(escaped_string);
            if (command_string_length >= url_command_string_buffer_size) {
                fprintf(stderr, "%s: The length of command string exceeds the buffer size.", __func__);
                return -1;
            }
            strncat(command_string_in_url, escaped_string, strlen(escaped_string));
        }
        p++;
    }
    return 0;
}

int kube_exec(wsclient_t * wsc, const char *namespace_, const char *pod_name, const char *container_name, int _stdin, int _stdout, int tty, const char *command)
{
    int rc = 0;

    const char *ws_path_template = "/api/v1/namespaces/%s/pods/%s/exec?stdin=%s&stdout=%s&tty=%s&command=%s";

    /* 
     * e.g. 
     * /api/v1/namespaces/default/pods/pod1/exec?stdin=true&stdout=true&tty=false&command=ls&command=/&container=container1
     * /api/v1/namespaces/default/pods/pod1/exec?stdin=true&stdout=true&tty=true&command=bash&container=container1
     */

    char command_string_in_url[URL_COMMAND_STRING_BUFFER_SIZE];
    memset(command_string_in_url, 0, sizeof(command_string_in_url));
    rc = assemble_command_in_url(command_string_in_url, URL_COMMAND_STRING_BUFFER_SIZE, command);
    if (rc != 0) {
        return rc;
    }

    char ws_path[WS_PATH_BUFFER_SIZE];
    memset(ws_path, 0, sizeof(ws_path));
    snprintf(ws_path, WS_PATH_BUFFER_SIZE, ws_path_template,
             namespace_, pod_name, 1 == _stdin ? TRUE_STRING : FALSE_STRING, 1 == _stdout ? TRUE_STRING : FALSE_STRING, 1 == tty ? TRUE_STRING : FALSE_STRING, command_string_in_url);

    if (container_name && container_name[0] != '\0') {
        int length_of_ws_path_with_container = strlen(ws_path) + strlen(CONTAINER_PREFIX) + strlen(container_name);
        if (length_of_ws_path_with_container >= WS_PATH_BUFFER_SIZE) {
            fprintf(stderr, "%s: Error: The length of the websocket path exceeds the buffer size.", __func__);
            return -1;
        }
        strncat(ws_path, CONTAINER_PREFIX, strlen(CONTAINER_PREFIX));
        strncat(ws_path, container_name, strlen(container_name));
    }

    if (wsc->log_mask & LLL_USER) {
        printf("%s: ws_path=%s\n", __func__, ws_path);
    }
    wsc->path = ws_path;

    wsc_mode_t mode = WSC_MODE_NORMAL;
    if (tty) {
        mode = WSC_MODE_IT;
        if (NULL == wsc->data_callback_func) {
            wsc->data_callback_func = default_exec_data_callback;
        }
    }

    rc = wsclient_run(wsc, mode);

    wsc->path = NULL;
    return rc;
}
