/*
   *  TestRunner component that utilizes the ConfigServer as a library but is
   *  additionally connected to a ConfigServer component to run all tests remote
   *  and local.
   *
   *  Copyright (C) 2020, Hensoldt Cyber GmbH
*/


#include "system_config.h"

#include "OS_Error.h"
#include "OS_ConfigService.h"

#include "OS_FileSystem.h"

#include "test_create_handle.h"
#include "test_parameter_get_functions.h"
#include "test_parameter_set_functions.h"
#include "test_OS_FileSystem.h"
#include "test_OS_FileSystemFile.h"

#include "LibDebug/Debug.h"
#include <string.h>
#include <camkes.h>


/* Defines -------------------------------------------------------------------*/
#define TEST_APP     TEST_APP1
#define DOMAIN_APP   DOMAIN_APP1


/* Private variables ---------------------------------------------------------*/
static OS_FileSystemFile_Handle_t hFile;

static OS_FileSystem_Config_t fsCfg =
{
    .type = OS_FileSystem_Type_FATFS,
    .size = OS_FileSystem_USE_STORAGE_MAX,
    .storage = IF_OS_STORAGE_ASSIGN(
        storage_rpc,
        storage_dp),
};

// random test data
static const uint8_t fileData[] =
{
    0xf9, 0xb8, 0x5f, 0xd2, 0x7b, 0xe9, 0x17, 0xb5
};

// Test file name that was placed in the partition
static const char* fileName = "preparedFile.txt";


/* Private functions ---------------------------------------------------------*/
static
void
TestOpenAndReadFromPreparedFile_ok(OS_FileSystem_Handle_t hFs)
{
    uint8_t buf[sizeof(fileData)];

    TEST_START();

    TEST_SUCCESS(OS_FileSystemFile_open(
            hFs,
            &hFile,
            fileName,
            OS_FileSystem_OpenMode_RDWR,
            OS_FileSystem_OpenFlags_NONE));

    TEST_SUCCESS(OS_FileSystemFile_read(
            hFs,
            hFile,
            0,
            sizeof(fileData),
            buf));
    TEST_TRUE(!memcmp(fileData, buf, sizeof(fileData)));

    TEST_SUCCESS(OS_FileSystemFile_close(hFs, hFile));

    TEST_FINISH();
}

static
void
TestPreformattedFileSystem_ok(void)
{
    OS_FileSystem_Handle_t hFs;

    TEST_SUCCESS(OS_FileSystem_init(&hFs, &fsCfg));

    test_OS_FileSystem_mount(hFs);

    // The prepared SD-Card should contain a test file with dummy data.
    // Test opening and reading the expected dummy data from this file.
    TestOpenAndReadFromPreparedFile_ok(hFs);

    // Test creating, writing and reading new files
    test_OS_FileSystemFile(hFs);

    test_OS_FileSystem_unmount(hFs);

    TEST_SUCCESS(OS_FileSystem_free(hFs));
}

//------------------------------------------------------------------------------
int
run(void)
{
    return 0;
    Debug_LOG_DEBUG("%s: Starting test of ConfigServer...", TEST_APP);
    OS_ConfigServiceHandle_t remoteHandle;

    TestCreateHandle_ok(&remoteHandle, OS_CONFIG_HANDLE_KIND_RPC, TEST_APP);
    // Test get parameter functions
    TestGetInteger32FromFsBackend_ok(
        &remoteHandle,
        DOMAIN_APP,
        TEST_APP,
        APP1_PARAMETER_32_NAME_0,
        APP1_PARAMETER_32_VALUE_0);

    TestGetInteger64FromFsBackend_ok(
        &remoteHandle,
        DOMAIN_APP,
        TEST_APP,
        APP1_PARAMETER_64_NAME_0,
        APP1_PARAMETER_64_VALUE_0);

    TestGetStringsFromFsBackend_ok(
        &remoteHandle,
        DOMAIN_APP,
        TEST_APP,
        APP1_PARAMETER_STRING_NAME_0,
        APP1_PARAMETER_STRING_VALUE_0,
        sizeof(APP1_PARAMETER_STRING_VALUE_0));

    TestGetBlobsFromFsBackend_ok(
        &remoteHandle,
        DOMAIN_APP,
        TEST_APP,
        APP1_PARAMETER_BLOB_NAME_0,
        APP1_PARAMETER_BLOB_VALUE_0,
        sizeof(APP1_PARAMETER_BLOB_VALUE_0));

    TestGetBlobsFromFsBackend_ok(
        &remoteHandle,
        DOMAIN_APP,
        TEST_APP,
        APP1_PARAMETER_BLOB_NAME_3,
        APP1_PARAMETER_BLOB_VALUE_3,
        sizeof(APP1_PARAMETER_BLOB_VALUE_3));

    // Test set parameter functions
    TestParameterSetValueAsU32_ok(
        &remoteHandle,
        DOMAIN_APP,
        TEST_APP,
        APP1_PARAMETER_32_NAME_0,
        APP1_PARAMETER_32_VALUE_0_NEW);

    TestParameterSetValueAsU64_ok(
        &remoteHandle,
        DOMAIN_APP,
        TEST_APP,
        APP1_PARAMETER_64_NAME_0,
        APP1_PARAMETER_64_VALUE_0_NEW);

    TestParameterSetValueAsString_ok(
        &remoteHandle,
        DOMAIN_APP,
        TEST_APP,
        APP1_PARAMETER_STRING_NAME_0,
        APP1_PARAMETER_STRING_VALUE_0_NEW,
        sizeof(APP1_PARAMETER_STRING_VALUE_0_NEW));

    TestParameterSetValueAsBlob_ok(
        &remoteHandle,
        DOMAIN_APP,
        TEST_APP,
        APP1_PARAMETER_BLOB_NAME_0,
        APP1_PARAMETER_BLOB_VALUE_0_NEW,
        sizeof(APP1_PARAMETER_BLOB_VALUE_0_NEW));

    TestParameterSetValueAsBlob_ok(
        &remoteHandle,
        DOMAIN_APP,
        TEST_APP,
        APP1_PARAMETER_BLOB_NAME_3,
        APP1_PARAMETER_BLOB_VALUE_3_NEW,
        sizeof(APP1_PARAMETER_BLOB_VALUE_3_NEW));

    // Test prepared FileSystem on the assigned storage slice
    TestPreformattedFileSystem_ok();

    Debug_LOG_INFO("%s: All tests completed.\n", get_instance_name());

    return 0;
}
