/*
 * Copyright (C) 2020-2024, HENSOLDT Cyber GmbH
 * 
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * For commercial licensing, contact: info.cyber@hensoldt.net
 */

#include "OS_ConfigService.h"

#include "LibDebug/Debug.h"

#include "util/helper_func.h"

#include "TestMacros.h"

#include <string.h>


// -----------------------------------------------------------------------------
void TestParameterSetValueAsU32_ok(OS_ConfigServiceHandle_t* handle,
                                   const char* domainName,
                                   const char* componentName,
                                   const char* parameterName,
                                   const uint32_t parameterValue);

void TestParameterSetValueAsU64_ok(OS_ConfigServiceHandle_t* handle,
                                   const char* domainName,
                                   const char* componentName,
                                   const char* parameterName,
                                   const uint64_t parameterValue);

void TestParameterSetValueAsString_ok(OS_ConfigServiceHandle_t* handle,
                                      const char* domainName,
                                      const char* componentName,
                                      const char* parameterName,
                                      const char* parameterValue,
                                      size_t parameterSize);

void TestParameterSetValueAsBlob_ok(OS_ConfigServiceHandle_t* handle,
                                    const char* domainName,
                                    const char* componentName,
                                    const char* parameterName,
                                    const char* parameterValue,
                                    size_t parameterSize);

void TestParameterSetValue_ok(OS_ConfigServiceHandle_t* handle,
                              const char* domainName,
                              const char* componentName,
                              const char* parameterName,
                              const void* parameterValue,
                              size_t parameterSize);
