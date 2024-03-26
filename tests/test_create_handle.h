/**
 * Copyright (C) 2020-2024, HENSOLDT Cyber GmbH
 * 
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * For commercial licensing, contact: info.cyber@hensoldt.net
 */

#include "OS_ConfigService.h"

#include "LibDebug/Debug.h"

#include "util/helper_func.h"

#include <string.h>


// -----------------------------------------------------------------------------
void TestCreateHandle_ok(OS_ConfigServiceHandle_t* handle,
                         OS_ConfigServiceHandle_HandleKind_t handleKind,
                         const char* componentName);
