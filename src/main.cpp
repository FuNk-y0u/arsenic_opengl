#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


unsigned int compile_shader(unsigned int type,  std::string& source)
{
  
  unsigned int id = glCreateShader(type);
  const char* src = source.c_str();
  glShaderSource(id,1,&src, nullptr);
  glCompileShader(id);
  int result;
  glGetShaderiv(id, GL_COMPILE_STATUS, &result);
  if(result == 0)
  {
    int length;
    glGetShaderiv(id,GL_INFO_LOG_LENGTH, &length);
    char* message = (char*)alloca(length * sizeof(char));
    glGetShaderInfoLog(id,length, &length, message);

    std::cout << "FAILED TO COMPILE SHADER" << std::endl;

    if(type == GL_VERTEX_SHADER)
    {
      std::cout << "TYPE: VERTEX_SHADER" << std::endl;
    }
    else
    {
      std::cout << "TYPE: FRAGMENT_SHADER" << std::endl;
    }
    std::cout<< message << std::endl;
    return 0;
  }
  return id;

}

unsigned int create_shader(std::string& vertex_shader, std::string& fragment_shader)
{
  unsigned int program = glCreateProgram();
  unsigned int vert_shader = compile_shader(GL_VERTEX_SHADER, vertex_shader);
  unsigned int frag_shader = compile_shader(GL_FRAGMENT_SHADER, fragment_shader);

  glAttachShader(program, vert_shader);
  glAttachShader(program, frag_shader);
  glLinkProgram(program);
  glValidateProgram(program);
 
  glDeleteShader(vert_shader);  
  glDeleteShader(frag_shader);

  return program;
}

int main()
{

    GLFWwindow* window;

    if(!glfwInit())
        return -1;
    
    
    window = glfwCreateWindow(640,480,"Arsenic",NULL, NULL);
    if(!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    float positions[6] = {
        -0.5f, -0.5f,
        0.0f,   0.5f,
        0.5f,  -0.5f,
        
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
  
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
    
    std::string vertex_shader_src = 
      "#version 330 core\n"
      "\n"
      "layout(location = 0) in vec4 position;\n"
      "void main()\n"
      "{\n"
      ""
      " gl_Position =  position;"
      ""
      ""
      "}\n";



    std::string fragment_shader_src = 
      "#version 330 core\n"
      "\n"
      "layout(location = 0) out vec4 color;"
      "void main()\n"
      "{\n"
      ""
      "color = vec4(1.0, 0.0, 0.0, 1.0);\n"
      "}\n";

    unsigned int shader  = create_shader(vertex_shader_src, fragment_shader_src);
    
    glUseProgram(shader);


    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
    
}
