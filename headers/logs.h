
// error checking
# pragma once


#define ARC_API __declspec(dllexport)
#define ASSERT(x) if(!(x)) __debugbreak();
#define glc(x) gl_clear_error();\
  x;\
  ASSERT(gl_log_call(#x, __FILE__, __LINE__))