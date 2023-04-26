# pragma once

#include <GL/glew.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>

#include "logs.h"

ARC_API void gl_clear_error();
ARC_API bool gl_log_call(const char* function, const char* file, int line);
