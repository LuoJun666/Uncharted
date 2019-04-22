#pragma once

#include "platform/platform_common_type.h"

struct PlatformWindowsTypes : public PlatformCommonType
{
#ifdef _WIN64
	typedef unsigned __int64	SIZE_T;
	typedef __int64				SSIZE_T;
#else
	typedef unsigned long		SIZE_T;
	typedef long				SSIZE_T;
#endif
};

typedef PlatformWindowsTypes PlatformTypes;