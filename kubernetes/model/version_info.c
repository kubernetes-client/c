#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "version_info.h"



version_info_t *version_info_create(
    char *build_date,
    char *compiler,
    char *git_commit,
    char *git_tree_state,
    char *git_version,
    char *go_version,
    char *major,
    char *minor,
    char *platform
    ) {
    version_info_t *version_info_local_var = malloc(sizeof(version_info_t));
    if (!version_info_local_var) {
        return NULL;
    }
    version_info_local_var->build_date = build_date;
    version_info_local_var->compiler = compiler;
    version_info_local_var->git_commit = git_commit;
    version_info_local_var->git_tree_state = git_tree_state;
    version_info_local_var->git_version = git_version;
    version_info_local_var->go_version = go_version;
    version_info_local_var->major = major;
    version_info_local_var->minor = minor;
    version_info_local_var->platform = platform;

    return version_info_local_var;
}


void version_info_free(version_info_t *version_info) {
    if(NULL == version_info){
        return ;
    }
    listEntry_t *listEntry;
    if (version_info->build_date) {
        free(version_info->build_date);
        version_info->build_date = NULL;
    }
    if (version_info->compiler) {
        free(version_info->compiler);
        version_info->compiler = NULL;
    }
    if (version_info->git_commit) {
        free(version_info->git_commit);
        version_info->git_commit = NULL;
    }
    if (version_info->git_tree_state) {
        free(version_info->git_tree_state);
        version_info->git_tree_state = NULL;
    }
    if (version_info->git_version) {
        free(version_info->git_version);
        version_info->git_version = NULL;
    }
    if (version_info->go_version) {
        free(version_info->go_version);
        version_info->go_version = NULL;
    }
    if (version_info->major) {
        free(version_info->major);
        version_info->major = NULL;
    }
    if (version_info->minor) {
        free(version_info->minor);
        version_info->minor = NULL;
    }
    if (version_info->platform) {
        free(version_info->platform);
        version_info->platform = NULL;
    }
    free(version_info);
}

cJSON *version_info_convertToJSON(version_info_t *version_info) {
    cJSON *item = cJSON_CreateObject();

    // version_info->build_date
    if (!version_info->build_date) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "buildDate", version_info->build_date) == NULL) {
    goto fail; //String
    }


    // version_info->compiler
    if (!version_info->compiler) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "compiler", version_info->compiler) == NULL) {
    goto fail; //String
    }


    // version_info->git_commit
    if (!version_info->git_commit) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "gitCommit", version_info->git_commit) == NULL) {
    goto fail; //String
    }


    // version_info->git_tree_state
    if (!version_info->git_tree_state) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "gitTreeState", version_info->git_tree_state) == NULL) {
    goto fail; //String
    }


    // version_info->git_version
    if (!version_info->git_version) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "gitVersion", version_info->git_version) == NULL) {
    goto fail; //String
    }


    // version_info->go_version
    if (!version_info->go_version) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "goVersion", version_info->go_version) == NULL) {
    goto fail; //String
    }


    // version_info->major
    if (!version_info->major) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "major", version_info->major) == NULL) {
    goto fail; //String
    }


    // version_info->minor
    if (!version_info->minor) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "minor", version_info->minor) == NULL) {
    goto fail; //String
    }


    // version_info->platform
    if (!version_info->platform) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "platform", version_info->platform) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

version_info_t *version_info_parseFromJSON(cJSON *version_infoJSON){

    version_info_t *version_info_local_var = NULL;

    // version_info->build_date
    cJSON *build_date = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "buildDate");
    if (!build_date) {
        goto end;
    }

    
    if(!cJSON_IsString(build_date))
    {
    goto end; //String
    }

    // version_info->compiler
    cJSON *compiler = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "compiler");
    if (!compiler) {
        goto end;
    }

    
    if(!cJSON_IsString(compiler))
    {
    goto end; //String
    }

    // version_info->git_commit
    cJSON *git_commit = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "gitCommit");
    if (!git_commit) {
        goto end;
    }

    
    if(!cJSON_IsString(git_commit))
    {
    goto end; //String
    }

    // version_info->git_tree_state
    cJSON *git_tree_state = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "gitTreeState");
    if (!git_tree_state) {
        goto end;
    }

    
    if(!cJSON_IsString(git_tree_state))
    {
    goto end; //String
    }

    // version_info->git_version
    cJSON *git_version = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "gitVersion");
    if (!git_version) {
        goto end;
    }

    
    if(!cJSON_IsString(git_version))
    {
    goto end; //String
    }

    // version_info->go_version
    cJSON *go_version = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "goVersion");
    if (!go_version) {
        goto end;
    }

    
    if(!cJSON_IsString(go_version))
    {
    goto end; //String
    }

    // version_info->major
    cJSON *major = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "major");
    if (!major) {
        goto end;
    }

    
    if(!cJSON_IsString(major))
    {
    goto end; //String
    }

    // version_info->minor
    cJSON *minor = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "minor");
    if (!minor) {
        goto end;
    }

    
    if(!cJSON_IsString(minor))
    {
    goto end; //String
    }

    // version_info->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "platform");
    if (!platform) {
        goto end;
    }

    
    if(!cJSON_IsString(platform))
    {
    goto end; //String
    }


    version_info_local_var = version_info_create (
        strdup(build_date->valuestring),
        strdup(compiler->valuestring),
        strdup(git_commit->valuestring),
        strdup(git_tree_state->valuestring),
        strdup(git_version->valuestring),
        strdup(go_version->valuestring),
        strdup(major->valuestring),
        strdup(minor->valuestring),
        strdup(platform->valuestring)
        );

    return version_info_local_var;
end:
    return NULL;

}
