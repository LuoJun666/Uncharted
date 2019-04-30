#pragma once

#include "platform_global_type.h"

#ifndef PLATFORM_WINDOWS
#define PLATFORM_WINDOWS 0
#endif

#ifdef PLATFORM_WINDOWS
#include "platform/windows/platform_windows_window.h"
#endif 