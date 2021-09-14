#include "authn_plugin.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef _WIN32
#include <dlfcn.h>
#endif
#include <errno.h>

#define PLUGIN_NAME_TEMPLATE "libkubernetes_%s.so"
#define PLUGIN_LIB_NAME_SIZE 64

#define PLUGIN_FUNCTION_GET_TOKEN "get_token"
#define PLUGIN_FUNCTION_IS_EXPIRED "is_expired"
#define PLUGIN_FUNCTION_REFRESH "refresh"

authn_plugin_t *create_authn_plugin(const char *name)
{
    static char fname[] = "create_authn_plugin()";

#ifndef _WIN32
    authn_plugin_t *plugin = calloc(1, sizeof(authn_plugin_t));
    if (!plugin) {
        fprintf(stderr, "%s: Cannot allocate memory for plugin library %s.[%s]\n", fname, name, strerror(errno));
        return NULL;
    }

    char plugin_lib_name[PLUGIN_LIB_NAME_SIZE];
    memset(plugin_lib_name, 0, sizeof(plugin_lib_name));
    snprintf(plugin_lib_name, sizeof(plugin_lib_name), PLUGIN_NAME_TEMPLATE, name);
    void *dlhandler = dlopen(plugin_lib_name, RTLD_LAZY);

    if (!dlhandler) {
        fprintf(stderr, "%s: Cannot load the library %s.[%s]\n", fname, plugin_lib_name, dlerror());
        goto error;
    }

    plugin->name = strdup(name);
    plugin->dlhandler = dlhandler;
    plugin->get_token = dlsym(dlhandler, PLUGIN_FUNCTION_GET_TOKEN);
    if (!plugin->get_token) {
        fprintf(stderr, "%s: Cannot find the function %s in library %s.[%s]\n", fname, PLUGIN_FUNCTION_GET_TOKEN, plugin_lib_name, dlerror());
        goto error;
    }
    plugin->is_expired = dlsym(dlhandler, PLUGIN_FUNCTION_IS_EXPIRED);
    if (!plugin->is_expired) {
        fprintf(stderr, "%s: Cannot find the function %s in library %s.[%s]\n", fname, PLUGIN_FUNCTION_IS_EXPIRED, plugin_lib_name, dlerror());
        goto error;
    }
    plugin->refresh = dlsym(dlhandler, PLUGIN_FUNCTION_REFRESH);
    if (!plugin->refresh) {
        fprintf(stderr, "%s: Cannot find the function %s in library %s.[%s]\n", fname, PLUGIN_FUNCTION_REFRESH, plugin_lib_name, dlerror());
        goto error;
    }

    return plugin;

  error:
    free_authn_plugin(plugin);
    plugin = NULL;
    return plugin;
#else
    return NULL;
#endif
}

void free_authn_plugin(authn_plugin_t * plugin)
{
    if (!plugin) {
        return;
    }

    if (plugin->dlhandler) {
#ifndef _WIN32
        dlclose(plugin->dlhandler);
#endif
        plugin->dlhandler = NULL;
    }

    if (plugin->name) {
        free(plugin->name);
        plugin->name = NULL;
    }

    plugin->get_token = NULL;
    plugin->is_expired = NULL;
    plugin->refresh = NULL;

    free(plugin);
}
