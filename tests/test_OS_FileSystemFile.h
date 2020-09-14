/*
 * Copyright (C) 2020, Hensoldt Cyber GmbH
 */

#include "OS_FileSystem.h"

#include "TestMacros.h"

#include <string.h>


//------------------------------------------------------------------------------
void
test_OS_FileSystemFile_open(
    OS_FileSystem_Handle_t hFs);

void
test_OS_FileSystemFile_close(
    OS_FileSystem_Handle_t hFs);

void
test_OS_FileSystemFile_read(
    OS_FileSystem_Handle_t hFs);

void
test_OS_FileSystemFile_write(
    OS_FileSystem_Handle_t hFs);

void
test_OS_FileSystemFile_delete(
    OS_FileSystem_Handle_t hFs);

void
test_OS_FileSystemFile_getSize(
    OS_FileSystem_Handle_t hFs);

void
test_OS_FileSystemFile(
    OS_FileSystem_Handle_t hFs);