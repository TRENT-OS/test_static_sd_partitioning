/*
 * Copyright (C) 2020, Hensoldt Cyber GmbH
 */

#include "OS_FileSystem.h"

#include "TestMacros.h"

#include <camkes.h>

#include <string.h>


//------------------------------------------------------------------------------
void test_OS_FileSystemFile(
    OS_FileSystem_Handle_t hFs);

void
test_OS_FileSystem_mount(
    OS_FileSystem_Handle_t hFs);

void
test_OS_FileSystem_unmount(
    OS_FileSystem_Handle_t hFs);

void
test_OS_FileSystem_format(
    OS_FileSystem_Handle_t hFs);

void
test_OS_FileSystem(
    OS_FileSystem_Handle_t hFs);