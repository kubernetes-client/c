#ifndef v1_persistent_volume_spec_TEST
#define v1_persistent_volume_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_persistent_volume_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_persistent_volume_spec.h"
v1_persistent_volume_spec_t* instantiate_v1_persistent_volume_spec(int include_optional);

#include "test_v1_aws_elastic_block_store_volume_source.c"
#include "test_v1_azure_disk_volume_source.c"
#include "test_v1_azure_file_persistent_volume_source.c"
#include "test_v1_ceph_fs_persistent_volume_source.c"
#include "test_v1_cinder_persistent_volume_source.c"
#include "test_v1_object_reference.c"
#include "test_v1_csi_persistent_volume_source.c"
#include "test_v1_fc_volume_source.c"
#include "test_v1_flex_persistent_volume_source.c"
#include "test_v1_flocker_volume_source.c"
#include "test_v1_gce_persistent_disk_volume_source.c"
#include "test_v1_glusterfs_persistent_volume_source.c"
#include "test_v1_host_path_volume_source.c"
#include "test_v1_iscsi_persistent_volume_source.c"
#include "test_v1_local_volume_source.c"
#include "test_v1_nfs_volume_source.c"
#include "test_v1_volume_node_affinity.c"
#include "test_v1_photon_persistent_disk_volume_source.c"
#include "test_v1_portworx_volume_source.c"
#include "test_v1_quobyte_volume_source.c"
#include "test_v1_rbd_persistent_volume_source.c"
#include "test_v1_scale_io_persistent_volume_source.c"
#include "test_v1_storage_os_persistent_volume_source.c"
#include "test_v1_vsphere_virtual_disk_volume_source.c"


v1_persistent_volume_spec_t* instantiate_v1_persistent_volume_spec(int include_optional) {
  v1_persistent_volume_spec_t* v1_persistent_volume_spec = NULL;
  if (include_optional) {
    v1_persistent_volume_spec = v1_persistent_volume_spec_create(
      list_create(),
       // false, not to have infinite recursion
      instantiate_v1_aws_elastic_block_store_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_azure_disk_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_azure_file_persistent_volume_source(0),
      list_create(),
       // false, not to have infinite recursion
      instantiate_v1_ceph_fs_persistent_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_cinder_persistent_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_object_reference(0),
       // false, not to have infinite recursion
      instantiate_v1_csi_persistent_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_fc_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_flex_persistent_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_flocker_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_gce_persistent_disk_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_glusterfs_persistent_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_host_path_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_iscsi_persistent_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_local_volume_source(0),
      list_create(),
       // false, not to have infinite recursion
      instantiate_v1_nfs_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_volume_node_affinity(0),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_photon_persistent_disk_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_portworx_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_quobyte_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_rbd_persistent_volume_source(0),
       // false, not to have infinite recursion
      instantiate_v1_scale_io_persistent_volume_source(0),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_storage_os_persistent_volume_source(0),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_vsphere_virtual_disk_volume_source(0)
    );
  } else {
    v1_persistent_volume_spec = v1_persistent_volume_spec_create(
      list_create(),
      NULL,
      NULL,
      NULL,
      list_create(),
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
      list_create(),
      NULL,
      NULL,
      "0",
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      "0",
      NULL,
      "0",
      NULL
    );
  }

  return v1_persistent_volume_spec;
}


#ifdef v1_persistent_volume_spec_MAIN

void test_v1_persistent_volume_spec(int include_optional) {
    v1_persistent_volume_spec_t* v1_persistent_volume_spec_1 = instantiate_v1_persistent_volume_spec(include_optional);

	cJSON* jsonv1_persistent_volume_spec_1 = v1_persistent_volume_spec_convertToJSON(v1_persistent_volume_spec_1);
	printf("v1_persistent_volume_spec :\n%s\n", cJSON_Print(jsonv1_persistent_volume_spec_1));
	v1_persistent_volume_spec_t* v1_persistent_volume_spec_2 = v1_persistent_volume_spec_parseFromJSON(jsonv1_persistent_volume_spec_1);
	cJSON* jsonv1_persistent_volume_spec_2 = v1_persistent_volume_spec_convertToJSON(v1_persistent_volume_spec_2);
	printf("repeating v1_persistent_volume_spec:\n%s\n", cJSON_Print(jsonv1_persistent_volume_spec_2));
}

int main() {
  test_v1_persistent_volume_spec(1);
  test_v1_persistent_volume_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_persistent_volume_spec_MAIN
#endif // v1_persistent_volume_spec_TEST
