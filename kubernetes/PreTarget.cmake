list(APPEND SRCS
        config/kube_config_model.c
        config/kube_config_yaml.c
        config/kube_config_util.c
        config/kube_config.c
        config/incluster_config.c
        config/exec_provider.c
        config/authn_plugin/authn_plugin_util.c
        config/authn_plugin/authn_plugin.c
        watch/watch_util.c
        websocket/wsclient.c
        websocket/kube_exec.c
        src/generic.c)

list(APPEND HDRS
        config/kube_config_common.h
        config/kube_config_model.h
        config/kube_config_yaml.h
        config/kube_config_util.h
        config/kube_config.h
        config/incluster_config.h
        config/exec_provider.h
        config/authn_plugin/authn_plugin_util.h
        config/authn_plugin/authn_plugin.h
        watch/watch_util.h
        websocket/wsclient.h
        websocket/kube_exec.h
        include/generic.h)

find_package(libwebsockets REQUIRED)
find_package(yaml CONFIG REQUIRED)