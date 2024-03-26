/*
 * Copyright (C) 2020-2024, HENSOLDT Cyber GmbH
 * 
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * For commercial licensing, contact: info.cyber@hensoldt.net
 */

#include "test_parameter_set_functions.h"

// -----------------------------------------------------------------------------
void
TestParameterSetValueAsU32_ok(
    OS_ConfigServiceHandle_t* handle,
    const char* domainName,
    const char* componentName,
    const char* parameterName,
    const uint32_t parameterValue)
{
    OS_Error_t err;

    TEST_START();

    err = set_integer32_parameter(handle,
                                  domainName,
                                  parameterName,
                                  parameterValue);
    Debug_ASSERT_PRINTFLN(OS_SUCCESS == err, "err %d", err);

    err = verify_integer32_parameter(handle,
                                     domainName,
                                     parameterName,
                                     parameterValue);
    Debug_ASSERT_PRINTFLN(OS_SUCCESS == err, "err %d", err);

    char handleKind[15];
    if (OS_CONFIG_HANDLE_KIND_RPC == OS_ConfigServiceHandle_getHandleKind(
            *handle))
    {
        initializeName(handleKind, sizeof(handleKind), "Rpc");
    }

    else if (OS_CONFIG_HANDLE_KIND_LOCAL == OS_ConfigServiceHandle_getHandleKind(
            *handle))
    {
        initializeName(handleKind, sizeof(handleKind), "Local");
    }

    TEST_FINISH();
}

void
TestParameterSetValueAsU64_ok(
    OS_ConfigServiceHandle_t* handle,
    const char* domainName,
    const char* componentName,
    const char* parameterName,
    const uint64_t parameterValue)
{
    OS_Error_t err;

    TEST_START();

    err = set_integer64_parameter(handle,
                                  domainName,
                                  parameterName,
                                  parameterValue);
    Debug_ASSERT_PRINTFLN(OS_SUCCESS == err, "err %d", err);

    err = verify_integer64_parameter(handle,
                                     domainName,
                                     parameterName,
                                     parameterValue);
    Debug_ASSERT_PRINTFLN(OS_SUCCESS == err, "err %d", err);

    char handleKind[15];
    if (OS_CONFIG_HANDLE_KIND_RPC == OS_ConfigServiceHandle_getHandleKind(
            *handle))
    {
        initializeName(handleKind, sizeof(handleKind), "Rpc");
    }

    else if (OS_CONFIG_HANDLE_KIND_LOCAL == OS_ConfigServiceHandle_getHandleKind(
            *handle))
    {
        initializeName(handleKind, sizeof(handleKind), "Local");
    }

    TEST_FINISH();
}

void
TestParameterSetValueAsString_ok(
    OS_ConfigServiceHandle_t* handle,
    const char* domainName,
    const char* componentName,
    const char* parameterName,
    const char* parameterValue,
    size_t parameterSize)
{
    OS_Error_t err;

    TEST_START();

    err = set_string_parameter(handle,
                               domainName,
                               parameterName,
                               parameterValue,
                               parameterSize);
    Debug_ASSERT_PRINTFLN(OS_SUCCESS == err, "err %d", err);

    err = verify_string_parameter(handle,
                                  domainName,
                                  parameterName,
                                  parameterValue,
                                  parameterSize);
    Debug_ASSERT_PRINTFLN(OS_SUCCESS == err, "err %d", err);

    char handleKind[15];
    if (OS_CONFIG_HANDLE_KIND_RPC == OS_ConfigServiceHandle_getHandleKind(
            *handle))
    {
        initializeName(handleKind, sizeof(handleKind), "Rpc");
    }

    else if (OS_CONFIG_HANDLE_KIND_LOCAL == OS_ConfigServiceHandle_getHandleKind(
            *handle))
    {
        initializeName(handleKind, sizeof(handleKind), "Local");
    }

    TEST_FINISH();
}


void
TestParameterSetValueAsBlob_ok(
    OS_ConfigServiceHandle_t* handle,
    const char* domainName,
    const char* componentName,
    const char* parameterName,
    const char* parameterValue,
    size_t parameterSize)
{
    OS_Error_t err;

    TEST_START();

    err = set_blob_parameter(handle,
                             domainName,
                             parameterName,
                             parameterValue,
                             parameterSize);
    Debug_ASSERT_PRINTFLN(OS_SUCCESS == err, "err %d", err);

    err = verify_blob_parameter(handle,
                                domainName,
                                parameterName,
                                parameterValue,
                                parameterSize);
    Debug_ASSERT_PRINTFLN(OS_SUCCESS == err, "err %d", err);

    char handleKind[15];
    if (OS_CONFIG_HANDLE_KIND_RPC == OS_ConfigServiceHandle_getHandleKind(
            *handle))
    {
        initializeName(handleKind, sizeof(handleKind), "Rpc");
    }

    else if (OS_CONFIG_HANDLE_KIND_LOCAL == OS_ConfigServiceHandle_getHandleKind(
            *handle))
    {
        initializeName(handleKind, sizeof(handleKind), "Local");
    }

    TEST_FINISH();
}


void
TestParameterSetValue_ok(
    OS_ConfigServiceHandle_t* handle,
    const char* domainName,
    const char* componentName,
    const char* parameterName,
    const void* parameterValue,
    size_t parameterSize)
{
    OS_Error_t err;

    TEST_START();

    err = set_parameter(handle,
                        domainName,
                        parameterName,
                        parameterValue,
                        parameterSize);
    Debug_ASSERT_PRINTFLN(OS_SUCCESS == err, "err %d", err);

    err = verify_parameter(handle,
                           domainName,
                           parameterName,
                           parameterValue,
                           parameterSize);
    Debug_ASSERT_PRINTFLN(OS_SUCCESS == err, "err %d", err);

    char handleKind[15];
    if (OS_CONFIG_HANDLE_KIND_RPC == OS_ConfigServiceHandle_getHandleKind(
            *handle))
    {
        initializeName(handleKind, sizeof(handleKind), "Rpc");
    }

    else if (OS_CONFIG_HANDLE_KIND_LOCAL == OS_ConfigServiceHandle_getHandleKind(
            *handle))
    {
        initializeName(handleKind, sizeof(handleKind), "Local");
    }

    TEST_FINISH();
}