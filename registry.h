#pragma once

#include "windows.h"
#include <winreg.h>
#include <stdio.h>

#define MULTIOTP_SETTINGS         L"CLSID\\"
#define MULTIOTP_PATH             L"multiOTPPath"
#define MULTIOTP_TIMEOUT          L"multiOTPTimeout"
#define MULTIOTP_RDPONLY          L"multiOTPRDPOnly"
#define MULTIOTP_PREFIX_PASSWORD  L"multiOTPPrefixPass"
#define MULTIOTP_DISPLAY_SMS_LINK L"multiOTPDisplaySmsLink"
#define MULTIOTP_UPN_FORMAT       L"multiOTPUPNFormat"
#define MULTIOTP_LOGIN_TITLE      L"multiOTPLoginTitle"
#define MULTIOTP_CACHE_ENABLED    L"multiOTPCacheEnabled"
#define MULTIOTP_SERVERS          L"multiOTPServers"
#define MULTIOTP_SERVER_TIMEOUT   L"multiOTPServerTimeout"
#define MULTIOTP_SHARED_SECRET    L"multiOTPSharedSecret"

#define RDP_SETTINGS              L"SYSTEM\\CurrentControlSet\\Control\\Terminal Server\\WinStations\\RDP-Tcp"
#define RDP_PORT                  L"PortNumber"

#define TCPIP_SETTINGS            L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters"
#define TCPIP_DOMAIN              L"Domain"
#define TCPIP_HOSTNAME            L"Hostname"

struct REGISTRY_KEY
{
	HKEY ROOT_KEY;
	PWSTR KEY_NAME;
	PWSTR VALUE_NAME;
};

enum CONF_VALUE
{
	CONF_PATH                 = 0,
	CONF_TIMEOUT              = 1,
	CONF_RDP_ONLY             = 2,
	CONF_PREFIX_PASSWORD      = 3,
	CONF_DISPLAY_SMS_LINK     = 4,
	CONF_UPN_FORMAT           = 5,
	CONF_LOGIN_TITLE          = 6,
	CONF_CACHE_ENABLED        = 7,
	CONF_SERVERS              = 8,
	CONF_SERVER_TIMEOUT       = 9,
	CONF_SHARED_SECRET        = 10,

	CONF_RDP_PORT             = 11,

	CONF_DOMAIN_NAME          = 12,
	CONF_HOST_NAME            = 13,

	CONF_NUM_VALUES           = 14,
};

static const REGISTRY_KEY s_CONF_VALUES[] =
{
	{ HKEY_CLASSES_ROOT, MULTIOTP_SETTINGS, MULTIOTP_PATH },
	{ HKEY_CLASSES_ROOT, MULTIOTP_SETTINGS, MULTIOTP_TIMEOUT },
	{ HKEY_CLASSES_ROOT, MULTIOTP_SETTINGS, MULTIOTP_RDPONLY },
	{ HKEY_CLASSES_ROOT, MULTIOTP_SETTINGS, MULTIOTP_PREFIX_PASSWORD },
	{ HKEY_CLASSES_ROOT, MULTIOTP_SETTINGS, MULTIOTP_DISPLAY_SMS_LINK },
	{ HKEY_CLASSES_ROOT, MULTIOTP_SETTINGS, MULTIOTP_UPN_FORMAT },
	{ HKEY_CLASSES_ROOT, MULTIOTP_SETTINGS, MULTIOTP_LOGIN_TITLE },
	{ HKEY_CLASSES_ROOT, MULTIOTP_SETTINGS, MULTIOTP_CACHE_ENABLED },
	{ HKEY_CLASSES_ROOT, MULTIOTP_SETTINGS, MULTIOTP_SERVERS },
	{ HKEY_CLASSES_ROOT, MULTIOTP_SETTINGS, MULTIOTP_SERVER_TIMEOUT },
	{ HKEY_CLASSES_ROOT, MULTIOTP_SETTINGS, MULTIOTP_SHARED_SECRET },

	{ HKEY_LOCAL_MACHINE, RDP_SETTINGS, RDP_PORT },

	{ HKEY_LOCAL_MACHINE, TCPIP_SETTINGS, TCPIP_DOMAIN },
	{ HKEY_LOCAL_MACHINE, TCPIP_SETTINGS, TCPIP_HOSTNAME },
};

DWORD readRegistryValueString( _In_ CONF_VALUE conf_value, _Outptr_result_nullonfailure_ PWSTR *data, _In_ PWSTR defaultValue);
DWORD readRegistryValueInteger(_In_ CONF_VALUE conf_value, _In_ DWORD defaultValue );
