/*
 * Copyright (C) 2020, Hensoldt Cyber GmbH
 */

#include "test_OS_FileSystem.h"


// Public Functions ------------------------------------------------------------

//------------------------------------------------------------------------------
void
test_OS_FileSystem_mount(
    OS_FileSystem_Handle_t hFs)
{
    TEST_START();

    TEST_SUCCESS(OS_FileSystem_mount(hFs));

    TEST_FINISH();
}


//------------------------------------------------------------------------------
void
test_OS_FileSystem_unmount(
    OS_FileSystem_Handle_t hFs)
{
    TEST_START();

    TEST_SUCCESS(OS_FileSystem_unmount(hFs));

    TEST_FINISH();
}


//------------------------------------------------------------------------------
void
test_OS_FileSystem_format(
    OS_FileSystem_Handle_t hFs)
{
    TEST_START();

    TEST_SUCCESS(OS_FileSystem_format(hFs));

    TEST_FINISH();
}


//------------------------------------------------------------------------------
void
test_OS_FileSystem(
    OS_FileSystem_Handle_t hFs)
{
    test_OS_FileSystem_format(hFs);
    test_OS_FileSystem_mount(hFs);

    test_OS_FileSystemFile(hFs);

    test_OS_FileSystem_unmount(hFs);
}


