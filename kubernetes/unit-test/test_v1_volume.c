#ifndef v1_volume_TEST
#define v1_volume_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_volume_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_volume.h"
v1_volume_t* instantiate_v1_volume(int include_optional);

#include "test_v1_aws_elastic_block_store_volume_source.c"
#include "test_v1_azure_disk_volume_source.c"
#include "test_v1_azure_file_volume_source.c"
#include "test_v1_ceph_fs_volume_source.c"
#include "test_v1_cinder_volume_source.c"
#include "test_v1_config_map_volume_source.c"
#include "test_v1_csi_volume_source.c"
#include "test_v1_downward_api_volume_source.c"
#include "test_v1_empty_dir_volume_source.c"
#include "test_v1_fc_volume_source.c"
#include "test_v1_flex_volume_source.c"
#include "test_v1_flocker_volume_source.c"
#include "test_v1_gce_persistent_disk_volume_source.c"
#include "test_v1_git_repo_volume_source.c"
#include "test_v1_glusterfs_volume_source.c"
#include "test_v1_host_path_volume_source.c"
#include "test_v1_iscsi_volume_source.c"
#include "test_v1_nfs_volume_source.c"
#include "test_v1_persistent_volume_claim_volume_source.c"
#include "test_v1_photon_persistent_disk_volume_source.c"
#include "test_v1_portworx_volume_source.c"
#include "test_v1_projected_volume_source.c"
#include "test_v1_quobyte_volume_source.c"
#include "test_v1_rbd_volume_source.c"
#include "test_v1_scale_io_volume_source.c"
#include "test_v1_secret_volume_source.c"
#include "test_v1_storage_os_volume_source.c"
#include "test_v1_vsphere_virtual_disk_volume_source.c"


v1_volume_t* instantiate_v1_volume(int include_optional) {
  v1_volume_t* v1_volume = NULL;
  if (include_optional) {
    v1_volume = v1_volume_create(
       // false, not to have infinite recursion
      instantiate_v1_aws_elastic_block_store_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_azure_disk_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_azure_file_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_ceph_fs_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_cinder_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_config_map_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_csi_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_downward_api_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_empty_dir_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_fc_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_flex_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_flocker_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_gce_persistent_disk_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_git_repo_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_glusterfs_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_host_path_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_iscsi_volume_source(0),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_nfs_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_persistent_volume_claim_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_photon_persistent_disk_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_portworx_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_projected_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_quobyte_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_rbd_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_scale_io_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_secret_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_storage_os_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_vsphere_virtual_disk_volume_source(0)
    );
  } else {
    v1_volume = v1_volume_create(
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      "0",
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    );
  }

  return v1_volume;
}


#ifdef v1_volume_MAIN

void test_v1_volume(int include_optional) {
    v1_volume_t* v1_volume_1 = instantiate_v1_volume(include_optional);

	cJSON* jsonv1_volume_1 = v1_volume_convertToJSON(v1_volume_1);
	printf("v1_volume :\n%s\n", cJSON_Print(jsonv1_volume_1));
	v1_volume_t* v1_volume_2 = v1_volume_parseFromJSON(jsonv1_volume_1);
	cJSON* jsonv1_volume_2 = v1_volume_convertToJSON(v1_volume_2);
	printf("repeating v1_volume:\n%s\n", cJSON_Print(jsonv1_volume_2));
}

int main() {
  test_v1_volume(1);
  test_v1_volume(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_volume_MAIN
#endif // v1_volume_TEST
