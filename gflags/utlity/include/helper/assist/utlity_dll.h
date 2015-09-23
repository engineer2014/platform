#pragma once

#include <windows.h>
#ifdef  UTLITY_EXPORTS
#define UTLITY_EXT_CLASS	__declspec(dllexport)
#else
#define UTLITY_EXT_CLASS	__declspec(dllimport)
#endif