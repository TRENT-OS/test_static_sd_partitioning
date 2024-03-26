/*
 * Copyright (C) 2019-2024, HENSOLDT Cyber GmbH
 * 
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * For commercial licensing, contact: info.cyber@hensoldt.net
 */

#pragma once

#include "OS_Error.h"
#include "OS_ConfigService.h"

OS_Error_t initializeWithFileBackends(OS_ConfigServiceLib_t* configLib,
                                      OS_FileSystem_Handle_t hFs);

