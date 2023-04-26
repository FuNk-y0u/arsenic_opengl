#include "renderer.h"

// clearing errors
void gl_clear_error()
{
  while(glGetError() != GL_NO_ERROR)
  {

  }
}

// error handeling
bool gl_log_call(const char* function, const char* file, int line)
{
  while(GLenum error = glGetError())
  {
    std::cout << "" << std::endl;
    std::cout << "--==OPENGL ERROR (" << error << ")==--" <<  std::endl;
    std::cout << "FILE: "<< file << std::endl;
    std::cout << "FUNCTION:  " << function << std::endl;
    std::cout << "LINE: " << line << std::endl;
    std::cout << "MSG: " << gluErrorString(error) << std::endl;
    std::cout << "" << std::endl;
    return false;
  }
  return true;
}
