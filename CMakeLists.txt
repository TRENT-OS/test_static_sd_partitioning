#
# Test Configuration Server
#
# Copyright (C) 2020-2024, HENSOLDT Cyber GmbH
# 
# SPDX-License-Identifier: GPL-2.0-or-later
#
# For commercial licensing, contact: info.cyber@hensoldt.net
#

cmake_minimum_required(VERSION 3.7.2)

os_set_config_file(system_config.h)


#-------------------------------------------------------------------------------
project(system_config C)
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR})


#-------------------------------------------------------------------------------
project(test_config_server C)

DeclareCAmkESComponent(
    ConfigServer
    INCLUDES
        util
    SOURCES
        components/ConfigServer/src/ConfigServer.c
        components/common/common.c
        util/create_parameters.c
        util/create_fs_backend.c
    C_FLAGS
        -Wall
        -Werror
        -DOS_CONFIG_SERVICE_CAMKES_SERVER
        -DOS_CONFIG_SERVICE_BACKEND_FILESYSTEM
    LIBS
        system_config
        os_libs
        os_core_api
        os_configuration
        os_filesystem
        os_logger
)

DeclareCAmkESComponent(
    LogServer
    SOURCES
        components/LogServer/src/LogServer.c
    C_FLAGS
        -Wall
        -Werror
        # We need to remove the Debug_Logs from the FS
        -DOS_FILESYSTEM_REMOVE_DEBUG_LOGGING
    LIBS
        os_core_api
        os_log_server_backend_filesystem
        os_libs
        os_logger
        os_filesystem
        TimeServer_client
)

# contains an additional local configServer as lib
DeclareCAmkESComponent(
    TestApp1
    INCLUDES
        util
        tests
    SOURCES
        components/TestApp/src/TestRunnerApp1.c
        components/common/common.c
        util/init_lib_with_fs_backend.c
        util/create_parameters.c
        util/helper_func.c
        tests/test_create_handle.c
        tests/test_parameter_get_functions.c
        tests/test_parameter_set_functions.c
        tests/test_OS_FileSystemFile.c
        tests/test_OS_FileSystem.c
    C_FLAGS
        -Wall
        -Werror
        -DOS_CONFIG_SERVICE_BACKEND_FILESYSTEM
        -DOS_CONFIG_SERVICE_CAMKES_CLIENT
    LIBS
        system_config
        os_libs
        os_core_api
        os_logger
        os_configuration
        os_filesystem
)

DeclareCAmkESComponent(
    TestApp2
    INCLUDES
        util
        tests
    SOURCES
        components/TestApp/src/TestRunnerApp2.c
        components/common/common.c
        tests/test_OS_FileSystemFile.c
        tests/test_OS_FileSystem.c
    C_FLAGS
        -Wall
        -Werror
        -DOS_CONFIG_SERVICE_CAMKES_CLIENT
    LIBS
        system_config
        os_libs
        os_core_api
        os_configuration
        os_logger
        os_filesystem
)

DeclareCAmkESComponent_TimeServer(
    TimeServer
)

DeclareCAmkESComponent_StorageServer(
    StorageServer
)

DeclareCAmkESComponent_SdHostController(
    Sdhc
)

DeclareAndCreateCamkESSystem(StaticSdPartitioningTests.camkes)
GenerateSimulateScript()
