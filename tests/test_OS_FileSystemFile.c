/*
 * Copyright (C) 2020, Hensoldt Cyber GmbH
 */

#include "test_OS_FileSystemFile.h"


//------------------------------------------------------------------------------
static const char* fileNames[] =
{
    "testFile1.txt",
    "testFile2.txt",
    "testFile3.txt",
    "testFile4.txt",
    "testFile5.txt"
};

// random test data
static const uint8_t fileData[] =
{
    0xf9, 0xb8, 0x5f, 0xd2, 0x7b, 0xe9, 0x17, 0xb5,
    0x21, 0x8c, 0x3c, 0xd1, 0xff, 0x10, 0x0a, 0xff,
    0xe1, 0x2b, 0x39, 0x59, 0xb4, 0xd1, 0xff, 0x16,
    0x5f, 0x10, 0xe4, 0xad, 0x21, 0x14, 0xb0, 0xf4,
    0x29, 0xdd, 0x83, 0x86, 0x75, 0x1e, 0x84, 0x94
};

static OS_FileSystemFile_Handle_t hFile[5];


// Public Functions ------------------------------------------------------------

//------------------------------------------------------------------------------
void
test_OS_FileSystemFile_open(
    OS_FileSystem_Handle_t hFs)
{
    TEST_START();

    for(uint8_t i = 0; i < 5; i++)
    {
        TEST_SUCCESS(OS_FileSystemFile_open(
            hFs,
            &hFile[i],
            fileNames[i],
            OS_FileSystem_OpenMode_RDWR,
            OS_FileSystem_OpenFlags_CREATE));
    }

    TEST_FINISH();
}

void
test_OS_FileSystemFile_close(
    OS_FileSystem_Handle_t hFs)
{
    TEST_START();

    for(uint8_t i = 0; i < 5; i++)
    {
        TEST_SUCCESS(OS_FileSystemFile_close(hFs, hFile[i]));
    }

    TEST_FINISH();
}

void
test_OS_FileSystemFile_read(
    OS_FileSystem_Handle_t hFs)
{
    uint8_t buf[sizeof(fileData)];

    TEST_START();

    for(uint8_t i = 0; i < 5; i++)
    {
        TEST_SUCCESS(OS_FileSystemFile_read(
            hFs,
            hFile[i],
            0,
            sizeof(fileData),
            buf));
        TEST_TRUE(!memcmp(fileData, buf, sizeof(fileData)));
    }

    TEST_FINISH();
}

void
test_OS_FileSystemFile_write(
    OS_FileSystem_Handle_t hFs)
{
    TEST_START();

    for (uint8_t i = 0; i < 5; i++)
    {
        TEST_SUCCESS(OS_FileSystemFile_write(
            hFs,
            hFile[i],
            0,
            sizeof(fileData),
            fileData));
    }

    TEST_FINISH();
}

void
test_OS_FileSystemFile_delete(
    OS_FileSystem_Handle_t hFs)
{
    TEST_START();

    for (uint8_t i = 0; i < 5; i++)
    {
        TEST_SUCCESS(OS_FileSystemFile_delete(hFs, fileNames[i]));
    }

    TEST_FINISH();
}

void
test_OS_FileSystemFile_getSize(
    OS_FileSystem_Handle_t hFs)
{
    off_t size;

    TEST_START();

    for (uint8_t i = 0; i < 5; i++)
    {
        TEST_SUCCESS(OS_FileSystemFile_getSize(hFs, fileNames[i], &size));
    }

    TEST_TRUE(size == sizeof(fileData));

    TEST_FINISH();
}

void
test_OS_FileSystemFile(
    OS_FileSystem_Handle_t hFs)
{
    test_OS_FileSystemFile_open(hFs);
    test_OS_FileSystemFile_write(hFs);
    test_OS_FileSystemFile_read(hFs);
    test_OS_FileSystemFile_close(hFs);

    test_OS_FileSystemFile_getSize(hFs);
    test_OS_FileSystemFile_delete(hFs);
}