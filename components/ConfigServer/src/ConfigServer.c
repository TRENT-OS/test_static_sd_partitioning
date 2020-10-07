/*
   *  ConfigServer component that can be initialized either with a memory or a filesystem
   *  backend.
   *
   *  Copyright (C) 2019, Hensoldt Cyber GmbH
*/


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <camkes.h>

#include "LibDebug/Debug.h"
#include "OS_Error.h"

#include "OS_ConfigService.h"

#include "create_fs_backend.h"
#include "create_parameters.h"


/* Private types -------------------------------------------------------------*/
static OS_FileSystem_Config_t cfg =
{
    .type = OS_FileSystem_Type_FATFS,
    .size = OS_FileSystem_USE_STORAGE_MAX,
    .storage = IF_OS_STORAGE_ASSIGN(
        storage_rpc,
        storage_dp),
};

static bool
initializeConfigBackend(void)
{
    OS_ConfigServiceLib_t* configLib =
        OS_ConfigService_getInstance();

    OS_FileSystem_Handle_t hFs;

    if (OS_FileSystem_init(&hFs, &cfg) != OS_SUCCESS)
    {
        Debug_LOG_ERROR("OS_FileSystem_init() failed.");
        return false;
    }

    if (OS_FileSystem_mount(hFs) != OS_SUCCESS)
    {
        Debug_LOG_ERROR("OS_FileSystem_mount() failed.");
        return false;
    }

    // Create the file backends
    Debug_LOG_INFO("Initializing with file backend");
    if (initializeWithFileBackends(configLib, hFs) != OS_SUCCESS)
    {
        Debug_LOG_ERROR("initializeWithFileBackends() failed.");
        return false;
    }

    // Create the parameters in the instance.
    Debug_LOG_DEBUG("Enumerating %s", DOMAIN_APP1);
    OS_Error_t err = initializeDomainsAndParameters(configLib, DOMAIN_APP1);
    if  (err != OS_SUCCESS)
    {
        Debug_LOG_ERROR("initializeDomainAndParameters for %s failed with: %d",
                        DOMAIN_APP1, err);
        return false;
    }

    return true;
}


void post_init(void)
{
    return;
    Debug_LOG_INFO("Starting ConfigServer...");

    Debug_LOG_INFO("Creating the Configuration Backend...");
    // Create the fs backend
    if (!initializeConfigBackend())
    {
        Debug_LOG_ERROR("initializeConfigBackend failed!");
    }

    Debug_LOG_INFO("Config Server initialized.");
}
