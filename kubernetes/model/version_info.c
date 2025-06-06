#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "version_info.h"



static version_info_t *version_info_create_internal(
    char *build_date,
    char *compiler,
    char *emulation_major,
    char *emulation_minor,
    char *git_commit,
    char *git_tree_state,
    char *git_version,
    char *go_version,
    char *major,
    char *min_compatibility_major,
    char *min_compatibility_minor,
    char *minor,
    char *platform
    ) {
    version_info_t *version_info_local_var = malloc(sizeof(version_info_t));
    if (!version_info_local_var) {
        return NULL;
    }
    version_info_local_var->build_date = build_date;
    version_info_local_var->compiler = compiler;
    version_info_local_var->emulation_major = emulation_major;
    version_info_local_var->emulation_minor = emulation_minor;
    version_info_local_var->git_commit = git_commit;
    version_info_local_var->git_tree_state = git_tree_state;
    version_info_local_var->git_version = git_version;
    version_info_local_var->go_version = go_version;
    version_info_local_var->major = major;
    version_info_local_var->min_compatibility_major = min_compatibility_major;
    version_info_local_var->min_compatibility_minor = min_compatibility_minor;
    version_info_local_var->minor = minor;
    version_info_local_var->platform = platform;

    version_info_local_var->_library_owned = 1;
    return version_info_local_var;
}

__attribute__((deprecated)) version_info_t *version_info_create(
    char *build_date,
    char *compiler,
    char *emulation_major,
    char *emulation_minor,
    char *git_commit,
    char *git_tree_state,
    char *git_version,
    char *go_version,
    char *major,
    char *min_compatibility_major,
    char *min_compatibility_minor,
    char *minor,
    char *platform
    ) {
    return version_info_create_internal (
        build_date,
        compiler,
        emulation_major,
        emulation_minor,
        git_commit,
        git_tree_state,
        git_version,
        go_version,
        major,
        min_compatibility_major,
        min_compatibility_minor,
        minor,
        platform
        );
}

void version_info_free(version_info_t *version_info) {
    if(NULL == version_info){
        return ;
    }
    if(version_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "version_info_free");
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
    if (version_info->emulation_major) {
        free(version_info->emulation_major);
        version_info->emulation_major = NULL;
    }
    if (version_info->emulation_minor) {
        free(version_info->emulation_minor);
        version_info->emulation_minor = NULL;
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
    if (version_info->min_compatibility_major) {
        free(version_info->min_compatibility_major);
        version_info->min_compatibility_major = NULL;
    }
    if (version_info->min_compatibility_minor) {
        free(version_info->min_compatibility_minor);
        version_info->min_compatibility_minor = NULL;
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


    // version_info->emulation_major
    if(version_info->emulation_major) {
    if(cJSON_AddStringToObject(item, "emulationMajor", version_info->emulation_major) == NULL) {
    goto fail; //String
    }
    }


    // version_info->emulation_minor
    if(version_info->emulation_minor) {
    if(cJSON_AddStringToObject(item, "emulationMinor", version_info->emulation_minor) == NULL) {
    goto fail; //String
    }
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


    // version_info->min_compatibility_major
    if(version_info->min_compatibility_major) {
    if(cJSON_AddStringToObject(item, "minCompatibilityMajor", version_info->min_compatibility_major) == NULL) {
    goto fail; //String
    }
    }


    // version_info->min_compatibility_minor
    if(version_info->min_compatibility_minor) {
    if(cJSON_AddStringToObject(item, "minCompatibilityMinor", version_info->min_compatibility_minor) == NULL) {
    goto fail; //String
    }
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
    if (cJSON_IsNull(build_date)) {
        build_date = NULL;
    }
    if (!build_date) {
        goto end;
    }

    
    if(!cJSON_IsString(build_date))
    {
    goto end; //String
    }

    // version_info->compiler
    cJSON *compiler = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "compiler");
    if (cJSON_IsNull(compiler)) {
        compiler = NULL;
    }
    if (!compiler) {
        goto end;
    }

    
    if(!cJSON_IsString(compiler))
    {
    goto end; //String
    }

    // version_info->emulation_major
    cJSON *emulation_major = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "emulationMajor");
    if (cJSON_IsNull(emulation_major)) {
        emulation_major = NULL;
    }
    if (emulation_major) { 
    if(!cJSON_IsString(emulation_major) && !cJSON_IsNull(emulation_major))
    {
    goto end; //String
    }
    }

    // version_info->emulation_minor
    cJSON *emulation_minor = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "emulationMinor");
    if (cJSON_IsNull(emulation_minor)) {
        emulation_minor = NULL;
    }
    if (emulation_minor) { 
    if(!cJSON_IsString(emulation_minor) && !cJSON_IsNull(emulation_minor))
    {
    goto end; //String
    }
    }

    // version_info->git_commit
    cJSON *git_commit = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "gitCommit");
    if (cJSON_IsNull(git_commit)) {
        git_commit = NULL;
    }
    if (!git_commit) {
        goto end;
    }

    
    if(!cJSON_IsString(git_commit))
    {
    goto end; //String
    }

    // version_info->git_tree_state
    cJSON *git_tree_state = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "gitTreeState");
    if (cJSON_IsNull(git_tree_state)) {
        git_tree_state = NULL;
    }
    if (!git_tree_state) {
        goto end;
    }

    
    if(!cJSON_IsString(git_tree_state))
    {
    goto end; //String
    }

    // version_info->git_version
    cJSON *git_version = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "gitVersion");
    if (cJSON_IsNull(git_version)) {
        git_version = NULL;
    }
    if (!git_version) {
        goto end;
    }

    
    if(!cJSON_IsString(git_version))
    {
    goto end; //String
    }

    // version_info->go_version
    cJSON *go_version = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "goVersion");
    if (cJSON_IsNull(go_version)) {
        go_version = NULL;
    }
    if (!go_version) {
        goto end;
    }

    
    if(!cJSON_IsString(go_version))
    {
    goto end; //String
    }

    // version_info->major
    cJSON *major = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "major");
    if (cJSON_IsNull(major)) {
        major = NULL;
    }
    if (!major) {
        goto end;
    }

    
    if(!cJSON_IsString(major))
    {
    goto end; //String
    }

    // version_info->min_compatibility_major
    cJSON *min_compatibility_major = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "minCompatibilityMajor");
    if (cJSON_IsNull(min_compatibility_major)) {
        min_compatibility_major = NULL;
    }
    if (min_compatibility_major) { 
    if(!cJSON_IsString(min_compatibility_major) && !cJSON_IsNull(min_compatibility_major))
    {
    goto end; //String
    }
    }

    // version_info->min_compatibility_minor
    cJSON *min_compatibility_minor = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "minCompatibilityMinor");
    if (cJSON_IsNull(min_compatibility_minor)) {
        min_compatibility_minor = NULL;
    }
    if (min_compatibility_minor) { 
    if(!cJSON_IsString(min_compatibility_minor) && !cJSON_IsNull(min_compatibility_minor))
    {
    goto end; //String
    }
    }

    // version_info->minor
    cJSON *minor = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "minor");
    if (cJSON_IsNull(minor)) {
        minor = NULL;
    }
    if (!minor) {
        goto end;
    }

    
    if(!cJSON_IsString(minor))
    {
    goto end; //String
    }

    // version_info->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(version_infoJSON, "platform");
    if (cJSON_IsNull(platform)) {
        platform = NULL;
    }
    if (!platform) {
        goto end;
    }

    
    if(!cJSON_IsString(platform))
    {
    goto end; //String
    }


    version_info_local_var = version_info_create_internal (
        strdup(build_date->valuestring),
        strdup(compiler->valuestring),
        emulation_major && !cJSON_IsNull(emulation_major) ? strdup(emulation_major->valuestring) : NULL,
        emulation_minor && !cJSON_IsNull(emulation_minor) ? strdup(emulation_minor->valuestring) : NULL,
        strdup(git_commit->valuestring),
        strdup(git_tree_state->valuestring),
        strdup(git_version->valuestring),
        strdup(go_version->valuestring),
        strdup(major->valuestring),
        min_compatibility_major && !cJSON_IsNull(min_compatibility_major) ? strdup(min_compatibility_major->valuestring) : NULL,
        min_compatibility_minor && !cJSON_IsNull(min_compatibility_minor) ? strdup(min_compatibility_minor->valuestring) : NULL,
        strdup(minor->valuestring),
        strdup(platform->valuestring)
        );

    return version_info_local_var;
end:
    return NULL;

}
