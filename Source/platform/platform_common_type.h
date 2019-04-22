#pragma once

template <typename bits32, typename bits64, int point_size>
struct SelectIntPointerType
{
};

template <typename bits32, typename bits64>
struct SelectIntPointerType<bits32, bits64, 4>
{
	typedef bits32 TIntPointer;
};

template <typename bits32, typename bits64>
struct SelectIntPointerType<bits32, bits64, 8>
{
	typedef bits64 TIntPointer ;
};

struct PlatformCommonType
{
	// Unsigned base types.
	typedef unsigned char 		uint8;		// 8-bit  unsigned.
	typedef unsigned short int	uint16;		// 16-bit unsigned.
	typedef unsigned int		uint32;		// 32-bit unsigned.
	typedef unsigned long long	uint64;		// 64-bit unsigned.

	// Signed base types.
	typedef	signed char			int8;		// 8-bit  signed.
	typedef signed short int	int16;		// 16-bit signed.
	typedef signed int	 		int32;		// 32-bit signed.
	typedef signed long long	int64;		// 64-bit signed.

	// Character types.
	typedef char				ANSICHAR;	// An ANSI character       -                  8-bit fixed-width representation of 7-bit characters.
	typedef wchar_t				WIDECHAR;	// A wide character        - In-memory only.  ?-bit fixed-width representation of the platform's natural wide character set.  Could be different sizes on different platforms.
	typedef uint8				CHAR8;		// An 8-bit character type - In-memory only.  8-bit representation.  Should really be char8_t but making this the generic option is easier for compilers which don't fully support C++11 yet (i.e. MSVC).
	typedef uint16				CHAR16;		// A 16-bit character type - In-memory only.  16-bit representation.  Should really be char16_t but making this the generic option is easier for compilers which don't fully support C++11 yet (i.e. MSVC).
	typedef uint32				CHAR32;		// A 32-bit character type - In-memory only.  32-bit representation.  Should really be char32_t but making this the generic option is easier for compilers which don't fully support C++11 yet (i.e. MSVC).
	typedef WIDECHAR			TCHAR;		// A switchable character  - In-memory only.  Either ANSICHAR or WIDECHAR, depending on a licensee's requirements.

	typedef SelectIntPointerType<uint32, uint64, sizeof(void*)>::TIntPointer UPTRINT;	// unsigned int the same size as a pointer
	typedef SelectIntPointerType<int32, int64, sizeof(void*)>::TIntPointer PTRINT;		// signed int the same size as a pointer
	typedef UPTRINT SIZE_T;																// unsigned int the same size as a pointer
	typedef PTRINT SSIZE_T;																// signed int the same size as a pointer

	typedef int32					TYPE_OF_NULL;
	typedef decltype(nullptr)		TYPE_OF_NULLPTR;
};