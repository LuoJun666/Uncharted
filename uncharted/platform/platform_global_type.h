#pragma once

#if defined(_WIN32)
#define PLATFORM_WINDOWS 1
#endif

#if defined(PLATFORM_WINDOWS)
#include "platform/windows/platform_windows_type.h"
#endif 

//~ Unsigned base types.
/// An 8-bit unsigned integer.
typedef PlatformTypes::uint8		uint8;
/// A 16-bit unsigned integer.
typedef PlatformTypes::uint16		uint16;
/// A 32-bit unsigned integer.
typedef PlatformTypes::uint32		uint32;
/// A 64-bit unsigned integer.
typedef PlatformTypes::uint64		uint64;

//~ Signed base types.
/// An 8-bit signed integer.
typedef	PlatformTypes::int8		    int8;
/// A 16-bit signed integer.
typedef PlatformTypes::int16		int16;
/// A 32-bit signed integer.
typedef PlatformTypes::int32		int32;
/// A 64-bit signed integer.
typedef PlatformTypes::int64		int64;

//~ Character types.
/// An ANSI character. Normally a signed type.
typedef PlatformTypes::ANSICHAR	ANSICHAR;
/// A wide character. Normally a signed type.
typedef PlatformTypes::WIDECHAR	WIDECHAR;
/// Either ANSICHAR or WIDECHAR, depending on whether the platform supports wide characters or the requirements of the licensee.
//typedef PlatformTypes::TCHAR		TCHAR;
/// An 8-bit character containing a UTF8 (Unicode, 8-bit, variable-width) code unit.
typedef PlatformTypes::CHAR8		UTF8CHAR;
/// A 16-bit character containing a UCS2 (Unicode, 16-bit, fixed-width) code unit, used for compatibility with 'Windows TCHAR' across multiple platforms.
typedef PlatformTypes::CHAR16		UCS2CHAR;
/// A 16-bit character containing a UTF16 (Unicode, 16-bit, variable-width) code unit.
typedef PlatformTypes::CHAR16		UTF16CHAR;
/// A 32-bit character containing a UTF32 (Unicode, 32-bit, fixed-width) code unit.
typedef PlatformTypes::CHAR32		UTF32CHAR;

/// An unsigned integer the same size as a pointer
typedef PlatformTypes::UPTRINT UPTRINT;
/// A signed integer the same size as a pointer
typedef PlatformTypes::PTRINT PTRINT;
/// An unsigned integer the same size as a pointer, the same as UPTRINT
typedef PlatformTypes::SIZE_T SIZE_T;
/// An integer the same size as a pointer, the same as PTRINT
typedef PlatformTypes::SSIZE_T SSIZE_T;

/// The type of the NULL constant.
typedef PlatformTypes::TYPE_OF_NULL	TYPE_OF_NULL;
/// The type of the C++ nullptr keyword.
typedef PlatformTypes::TYPE_OF_NULLPTR	TYPE_OF_NULLPTR;