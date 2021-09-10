#include "exec_provider.h"
#include "kube_config_yaml.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define ARGS_DELIM " "
#define KUBECONFIG_EXEC_ARGS_BUFFER_SIZE 1024
#define KUBECONFIG_EXEC_COMMAND_BUFFER_SIZE 1024
#define KUBECONFIG_STRING_BUFFER_SIZE 1024
#define KUBECONFIG_EXEC_RESULT_BUFFER_SIZE 4096

int kube_exec_and_get_result(ExecCredential_t * exec_credential, const kubeconfig_property_t * exec)
{
    static char fname[] = "kube_exec_and_get_result()";
    int rc = 0;

    if (!exec || exec->type != KUBECONFIG_PROPERTY_TYPE_USER_EXEC) {
        fprintf(stderr, "%s: This is not a valid kubeconfig exec configuration.\n", fname);
        return -1;
    }
    if (!exec->command) {
        fprintf(stderr, "%s: The kubeconfig exec command is not specified.\n", fname);
        return -1;
    }

    if (exec->envs_count > 0 && exec->envs != NULL) {
        for (int i = 0; i < exec->envs_count; i++) {
            keyValuePair_t *pair = exec->envs[i];
            if (pair && pair->key && pair->value) {

#ifndef _WIN32
                rc = setenv(pair->key, (char *) (pair->value), 1);  /* 1 means to overwrite the existing environment variable */
#else
                rc = _putenv_s(pair->key, (char *) (pair->value));
#endif
                if (0 != rc) {
                    fprintf(stderr, "%s: Cannot set environment variable %s=%s.[%s]\n", fname, pair->key, (char *) (pair->value), strerror(errno));
                    return -1;
                }
            } else {
                fprintf(stderr, "%s: The environment variable does not exist in exec->envs[%d].\n", fname, i);
                return -1;
            }
        }
    }

    char args_string[KUBECONFIG_EXEC_ARGS_BUFFER_SIZE];
    memset(args_string, 0, sizeof(args_string));
    int args_string_remaining_size = sizeof(args_string) - 1;   /* 1 for the end of string ('\n') */
    if (exec->args_count > 0 && exec->args != NULL) {
        for (int i = 0; i < exec->args_count; i++) {
            args_string_remaining_size -= (strlen(ARGS_DELIM) + strlen(exec->args[i]));
            if (args_string_remaining_size <= 0) {
                fprintf(stderr, "%s: The buffer for exec args is not sufficient.\n", fname);
                return -1;
            }
            strncat(args_string, ARGS_DELIM, strlen(ARGS_DELIM));
            strncat(args_string, exec->args[i], strlen(exec->args[i]));
        }
    }

    char command_string[KUBECONFIG_EXEC_COMMAND_BUFFER_SIZE];
    memset(command_string, 0, sizeof(command_string));
    snprintf(command_string, sizeof(command_string), "%s%s", exec->command, args_string);

    char *result_string = NULL;
    FILE *fp = NULL;
#ifndef _WIN32
    fp = popen(command_string, "r");    /* r means read from stdout */
#else
    fp = _popen(command_string, "r");    /* r means read from stdout */
#endif
    if (fp) {
        result_string = calloc(1, KUBECONFIG_EXEC_RESULT_BUFFER_SIZE);
        if (!result_string) {
            fprintf(stderr, "%s: Cannot allocate memory for command result.[%s]\n", fname, strerror(errno));
            return -1;
        }
        int result_string_remaining_size = KUBECONFIG_EXEC_RESULT_BUFFER_SIZE - 1;
        char string_buf[KUBECONFIG_STRING_BUFFER_SIZE];
        memset(string_buf, 0, sizeof(string_buf));
        while (fgets(string_buf, sizeof(string_buf), fp) != NULL) {
            result_string_remaining_size -= strlen(string_buf);
            if (result_string_remaining_size <= 0) {
                fprintf(stderr, "%s: The buffer for exec result is not sufficient.\n", fname);
                rc = -1;
                goto end;
            }
            strncat(result_string, string_buf, strlen(string_buf));
            memset(string_buf, 0, sizeof(string_buf));
        }
#ifndef _WIN32
        pclose(fp);
#else
        _pclose(fp);
#endif
    } else {
        fprintf(stderr, "%s: Cannot open pipe to run command.[%s]\n", fname, strerror(errno));
        return -1;
    }

    rc = kubeyaml_parse_exec_crendential(exec_credential, result_string);

  end:
    if (result_string) {
        free(result_string);
    }

    return rc;
}
