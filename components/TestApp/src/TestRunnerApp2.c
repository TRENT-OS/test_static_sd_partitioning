/*
   *  TestRunnerApp connected to a ConfigServer component to run all tests remote
   *  in in a multiclient setup with other TestRunnerApps.
   *
   *  Copyright (C) 2020, Hensoldt Cyber GmbH
*/


#include "system_config.h"

#include "test_OS_FileSystem.h"
#include "test_OS_FileSystemFile.h"

#include <camkes.h>
#include <string.h>


//------------------------------------------------------------------------------
static OS_FileSystem_Config_t fsCfg =
{
    .type = OS_FileSystem_Type_FATFS,
    .size = OS_FileSystem_USE_STORAGE_MAX,
    .storage = IF_OS_STORAGE_ASSIGN(
        storage_rpc,
        storage_dp),
};


//------------------------------------------------------------------------------
static
OS_Error_t
TestUnformattedFileSystem_ok(void)
{
    OS_Error_t ret;
    OS_FileSystem_Handle_t hFs;

    if ((ret = OS_FileSystem_init(&hFs, &fsCfg)) != OS_SUCCESS)
    {
        Debug_LOG_ERROR("OS_FileSystem_init() failed, code %d", ret);
        return OS_ERROR_GENERIC;
    }

    test_OS_FileSystem(hFs);

    if ((ret = OS_FileSystem_free(hFs)) != OS_SUCCESS)
    {
        Debug_LOG_ERROR("OS_FileSystem_free() failed, code %d", ret);
        return OS_ERROR_GENERIC;
    }

    return OS_SUCCESS;
}


// Public Functions ------------------------------------------------------------
int
run(void)
{
    return 0;
    TestUnformattedFileSystem_ok();

    Debug_LOG_INFO("%s: All tests completed.\n", get_instance_name());

    return 0;
}
