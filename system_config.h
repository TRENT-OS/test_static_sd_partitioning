/**
 * Copyright (C) 2019, Hensoldt Cyber GmbH
 *
 * OS libraries configurations
 */

#pragma once

//-----------------------------------------------------------------------------
// Debug
//-----------------------------------------------------------------------------
#if !defined(NDEBUG)
#define Debug_Config_STANDARD_ASSERT
#define Debug_Config_ASSERT_SELF_PTR
#else
#define Debug_Config_DISABLE_ASSERT
#define Debug_Config_NO_ASSERT_SELF_PTR
#endif

#define Debug_Config_LOG_LEVEL Debug_LOG_LEVEL_INFO
#define Debug_Config_INCLUDE_LEVEL_IN_MSG
#define Debug_Config_LOG_WITH_FILE_LINE

//-----------------------------------------------------------------------------
// Memory
//-----------------------------------------------------------------------------
#define Memory_Config_USE_STDLIB_ALLOC

//-----------------------------------------------------------------------------
// LogServer
//-----------------------------------------------------------------------------
#if !defined(CAMKES_TOOL_PROCESSING)

// If the belows header is included in the config file and Logger library is
// linked, the LibDebug will forward entries to the LogServer.
#include "Logger/Client/OS_Logger.h"

#endif //!defined(CAMKES_TOOL_PROCESSING)

// api interface name
#define API_LOG_SERVER_EMIT                     logServer_rpc_emit
#define API_LOG_SERVER_GET_SENDER_ID            logServer_rpc_get_sender_id
#define API_LOG_SERVER_READ_LOG_FILE            logServer_rpc_read_log_file

//-----------------------------------------------------------------------------
// StorageServer
//-----------------------------------------------------------------------------
// 1 MiB reserved for GPT
#define GPT_STORAGE_SIZE            (1024*1024)

// 128 MiB
#define TESTAPP1_STORAGE_OFFSET     GPT_STORAGE_SIZE
#define TESTAPP1_STORAGE_SIZE       (128*1024*1024)

// 128 MiB
#define TESTAPP2_STORAGE_OFFSET     (TESTAPP1_STORAGE_OFFSET + TESTAPP1_STORAGE_SIZE)
#define TESTAPP2_STORAGE_SIZE       (128*1024*1024)

// 1GiB
#define CONFIGSERVER_STORAGE_OFFSET (TESTAPP2_STORAGE_OFFSET + TESTAPP2_STORAGE_SIZE)
#define CONFIGSERVER_STORAGE_SIZE   (1024*1024*1024)

// Should be 4GiB as outlined in the partition layout of the WikiPage for this
// test system, but due to a bug in the StorageServer setup (SEOS-1745), for now
// the size is reduced to 1GiB
#define LOGSERVER_STORAGE_OFFSET    (CONFIGSERVER_STORAGE_OFFSET + CONFIGSERVER_STORAGE_SIZE)
#define LOGSERVER_STORAGE_SIZE      (1024*1024*1024)

//-----------------------------------------------------------------------------
// IDS
//-----------------------------------------------------------------------------
#define CONFIGSERVER_LOGGER_ID      10
#define TESTAPP1_LOGGER_ID          20
#define TESTAPP2_LOGGER_ID          30

#define TESTAPP1_STORAGE_ID         1
#define TESTAPP2_STORAGE_ID         2
#define CONFIGSERVER_STORAGE_ID     3
#define LOGGER_STORAGE_ID           4

//-----------------------------------------------------------------------------
// TestApps
//-----------------------------------------------------------------------------

#define CREATE_FS_BACKEND //Can be set to create the ConfigFile by the ConfigFileInjector on system startup

//App1
#define TEST_APP1   "TestApp1"
#define DOMAIN_APP1 "Domain_App1"

#define APP1_PARAMETER_32_NAME_0       "App1_Parameter_32_0"
#define APP1_PARAMETER_32_VALUE_0      0x41
#define APP1_PARAMETER_32_VALUE_0_NEW  0x7CF321

#define APP1_PARAMETER_32_NAME_1       "App1_Parameter_32_1"
#define APP1_PARAMETER_32_VALUE_1      0x100001
#define APP1_PARAMETER_32_VALUE_1_NEW  0x6215E1

#define APP1_PARAMETER_32_NAME_2       "App1_Parameter_32_2"
#define APP1_PARAMETER_32_VALUE_2      0x80000001
#define APP1_PARAMETER_32_VALUE_2_NEW  0x217721

#define APP1_PARAMETER_32_NAME_3       "App1_Parameter_32_3"
#define APP1_PARAMETER_32_VALUE_3      0xFFFFFFF1
#define APP1_PARAMETER_32_VALUE_3_NEW  0x1A24E1


#define APP1_PARAMETER_64_NAME_0       "App1_Parameter_64_0"
#define APP1_PARAMETER_64_VALUE_0      0x20001
#define APP1_PARAMETER_64_VALUE_0_NEW  0x3CB6C1

#define APP1_PARAMETER_64_NAME_1       "App1_Parameter_64_1"
#define APP1_PARAMETER_64_VALUE_1      0x106CF3B641
#define APP1_PARAMETER_64_VALUE_1_NEW  0x781F1

#define APP1_PARAMETER_64_NAME_2       "App1_Parameter_64_2"
#define APP1_PARAMETER_64_VALUE_2      0x2000000001
#define APP1_PARAMETER_64_VALUE_2_NEW  0x368671

#define APP1_PARAMETER_64_NAME_3       "App1_Parameter_64_3"
#define APP1_PARAMETER_64_VALUE_3      0xAABBCCDD00112231
#define APP1_PARAMETER_64_VALUE_3_NEW  0x128811


#define APP1_PARAMETER_STRING_NAME_0      "App1_Parameter_String_0"
#define APP1_PARAMETER_STRING_VALUE_0     "App1_Hello_World!_0"
#define APP1_PARAMETER_STRING_VALUE_0_NEW "App1_Hello_World!_0_NEW"

#define APP1_PARAMETER_STRING_NAME_1      "App1_Parameter_String_1"
#define APP1_PARAMETER_STRING_VALUE_1     "App1_Hello_World!_1"
#define APP1_PARAMETER_STRING_VALUE_1_NEW "App1_Hello_World!_1_NEW"

#define APP1_PARAMETER_STRING_NAME_2      "App1_Parameter_String_2"
#define APP1_PARAMETER_STRING_VALUE_2     "App1_Hello_World!_2"
#define APP1_PARAMETER_STRING_VALUE_2_NEW "App1_Hello_World!_2_NEW"

#define APP1_PARAMETER_STRING_NAME_3      "App1_Parameter_String_3"
#define APP1_PARAMETER_STRING_VALUE_3     "App1_Hello_World!_3"
#define APP1_PARAMETER_STRING_VALUE_3_NEW "App1_Hello_World!_3_NEW"


#define APP1_PARAMETER_BLOB_NAME_0        "App1_Parameter_Blob_0"
#define APP1_PARAMETER_BLOB_VALUE_0       "App1_Blob: Hello World!_0"
#define APP1_PARAMETER_BLOB_VALUE_0_NEW   "App1_Blob: Hello World!_0_NEW"

#define APP1_PARAMETER_BLOB_NAME_1        "App1_Parameter_Blob_1"
#define APP1_PARAMETER_BLOB_VALUE_1       "App1_Blob: Hello World!_1"
#define APP1_PARAMETER_BLOB_VALUE_1_NEW   "App1_Blob: Hello World!_1_NEW"

#define APP1_PARAMETER_BLOB_NAME_2        "App1_Parameter_Blob_2"
#define APP1_PARAMETER_BLOB_VALUE_2       "App1_Blob: Hello World!_2"
#define APP1_PARAMETER_BLOB_VALUE_2_NEW   "App1_Blob: Hello World!_2_NEW"

#define APP1_PARAMETER_BLOB_NAME_3    "App1_Parameter_Blob_3"
#define APP1_PARAMETER_BLOB_VALUE_3                                           \
    "-----BEGIN CERTIFICATE-----\r\n"                                     \
    "MIIFtDCCBJygAwIBAgIQC2qzsD6xqfbEYJJqqM3+szANBgkqhkiG9w0BAQsFADBa\r\n" \
    "MQswCQYDVQQGEwJJRTESMBAGA1UEChMJQmFsdGltb3JlMRMwEQYDVQQLEwpDeWJl\r\n" \
    "clRydXN0MSIwIAYDVQQDExlCYWx0aW1vcmUgQ3liZXJUcnVzdCBSb290MB4XDTE2\r\n" \
    "MDUyMDEyNTIzOFoXDTI0MDUyMDEyNTIzOFowgYsxCzAJBgNVBAYTAlVTMRMwEQYD\r\n" \
    "VQQIEwpXYXNoaW5ndG9uMRAwDgYDVQQHEwdSZWRtb25kMR4wHAYDVQQKExVNaWNy\r\n" \
    "b3NvZnQgQ29ycG9yYXRpb24xFTATBgNVBAsTDE1pY3Jvc29mdCBJVDEeMBwGA1UE\r\n" \
    "AxMVTWljcm9zb2Z0IElUIFRMUyBDQSA0MIICIjANBgkqhkiG9w0BAQEFAAOCAg8A\r\n" \
    "MIICCgKCAgEAq+XrXaNrOZ71NIgSux1SJl19CQvGeY6rtw7fGbLd7g/27vRW5Ebi\r\n" \
    "kg/iZwvjHHGk1EFztMuZFo6/d32wrx5s7XEuwwh3Sl6Sruxa0EiB0MXpoPV6jx6N\r\n" \
    "XtOtksDaxpE1MSC5OQTNECo8lx0AnpkYGAnPS5fkyfwA8AxanTboskDBSqyEKKo9\r\n" \
    "Rhgrp4qs9K9LqH5JQsdiIMDmpztd65Afu4rYnJDjOrFswpTOPjJry3GzQS65xeFd\r\n" \
    "2FkngvvhSA1+6ATx+QEnQfqUWn3FMLu2utcRm4j6AcxuS5K5+Hg8y5xomhZmiNCT\r\n" \
    "sCqDLpcRHX6BIGHksLmbnG5TlZUixtm9dRC62XWMPD8d0Jb4M0V7ex9UM+VIl6cF\r\n" \
    "JKLb0dyVriAqfZaJSHuSetAksd5IEfdnPLTf+Fhg9U97NGjm/awmCLbzLEPbT8QW\r\n" \
    "0JsMcYexB2uG3Y+gsftm2tjL6fLwZeWO2BzqL7otZPFe0BtQsgyFSs87yC4qanWM\r\n" \
    "wK5c2enAfH182pzjvUqwYAeCK31dyBCvLmKM3Jr94dm5WUiXQhrDUIELH4Mia+Sb\r\n" \
    "vCkigv2AUVx1Xw41wt1/L3pnnz2OW4y7r530zAz7qB+dIcHz51IaXc4UV21QuEnu\r\n" \
    "sQsn0uJpJxJuxsAmPuekKxuLUzgG+hqHOuBLf5kWTlk9WWnxcadlZRsCAwEAAaOC\r\n" \
    "AUIwggE+MB0GA1UdDgQWBBR6e4zBz+egyhzUa/r74TPDDxqinTAfBgNVHSMEGDAW\r\n" \
    "gBTlnVkwgkdYzKz6CFQ2hns6tQRN8DASBgNVHRMBAf8ECDAGAQH/AgEAMA4GA1Ud\r\n" \
    "DwEB/wQEAwIBhjAnBgNVHSUEIDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUF\r\n" \
    "BwMJMDQGCCsGAQUFBwEBBCgwJjAkBggrBgEFBQcwAYYYaHR0cDovL29jc3AuZGln\r\n" \
    "aWNlcnQuY29tMDoGA1UdHwQzMDEwL6AtoCuGKWh0dHA6Ly9jcmwzLmRpZ2ljZXJ0\r\n" \
    "LmNvbS9PbW5pcm9vdDIwMjUuY3JsMD0GA1UdIAQ2MDQwMgYEVR0gADAqMCgGCCsG\r\n" \
    "AQUFBwIBFhxodHRwczovL3d3dy5kaWdpY2VydC5jb20vQ1BTMA0GCSqGSIb3DQEB\r\n" \
    "CwUAA4IBAQAR/nIGOiEKN27I9SkiAmKeRQ7t+gaf77+eJDUX/jmIsrsB4Xjf0YuX\r\n" \
    "/bd38YpyT0k66LMp13SH5LnzF2CHiJJVgr3ZfRNIfwaQOolm552W95XNYA/X4cr2\r\n" \
    "du76mzVIoZh90pMqT4EWx6iWu9El86ZvUNoAmyqo9DUA4/0sO+3lFZt/Fg/Hjsk2\r\n" \
    "IJTwHQG5ElBQmYHgKEIsjnj/7cae1eTK6aCqs0hPpF/kixj/EwItkBE2GGYoOiKa\r\n" \
    "3pXxWe6fbSoXdZNQwwUS1d5ktLa829d2Wf6l1uVW4f5GXDuK+OwO++8SkJHOIBKB\r\n" \
    "ujxS43/jQPQMQSBmhxjaMmng9tyPKPK1\r\n"                                 \
    "-----END CERTIFICATE-----\r\n"

#define APP1_PARAMETER_BLOB_VALUE_3_NEW   "App1_Blob: Hello World!_3_NEW"
