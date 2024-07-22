#pragma once

namespace Functionality
{
	auto __strlen( const char* str ) ->  int;
	auto __fabs( int _X ) ->  int;
	auto __sqrtf( double Number ) ->  double;
	auto __wcslen( const wchar_t* s ) ->  int;
	auto __wcslen2( wchar_t* str ) ->  int;
	auto __wcsicmp_insensitive( wchar_t* cs, wchar_t* ct ) ->  int;
	auto __isxdigit( char c ) ->  bool;
	auto __strtoul( const char* str, char** endptr, int base = 16 ) ->  unsigned long;
	auto __fabs( double x ) ->  float;
	auto __memcpy( void* dest, const void* src, unsigned long long count ) ->  void*;
	auto __memset( void* dst0, int c0, unsigned int len ) ->  void*;
	auto __strncmp( const char* s1, const char* s2, size_t n ) ->  unsigned int;
	auto __strstr( const char* s, const char* find ) ->  char*;
	auto __rand( ) ->  unsigned int;
}