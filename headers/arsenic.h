/*

  ___  ______  _____ _____ _   _ _____ _____       _   _ 
 / _ \ | ___ \/  ___|  ___| \ | |_   _/  __ \     | | | |
/ /_\ \| |_/ /\ `--.| |__ |  \| | | | | /  \/     | |_| |
|  _  ||    /  `--. \  __|| . ` | | | | |         |  _  |
| | | || |\ \ /\__/ / |___| |\  |_| |_| \__/\  _  | | | |
\_| |_/\_| \_|\____/\____/\_| \_/\___/ \____/ (_) \_| |_/
                                                         
                                             
*/


// Required Header Files
#pragma once


//c++
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <windows.h>

//arsenic
#include "shader.h"
#include "renderer.h"
#include "vertexbuffer.h"
#include "indexbuffer.h"
#include "vertexbufferlayout.h"
#include "vertexarray.h"



// Makes Sure Program Runs On Nvidia Or Amd GPU
#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllexport)  DWORD NvOptimusEnablement = 1;
__declspec(dllexport)  int AmdPowerXpressRequestHighPerformance = 1;

#ifdef __cplusplus
}
#endif