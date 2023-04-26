#include "arsenic.h"

int main()
{

  GLFWwindow* window;

  if(!glfwInit())
    return -1;
    
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    
  window = glfwCreateWindow(640,480,"Arsenic",NULL, NULL);
  if(!window)
  {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  glfwSwapInterval(1);

  if(glewInit() != GLEW_OK)
    std::cout << "Error!" << std::endl;

  std::cout << glGetString(GL_VERSION) << std::endl;

  float positions[] = {
    -0.5f, -0.5f, //0
    0.5f,   -0.5f, //1
    0.5f,  0.5f, //2
    -0.5f, 0.5f,  //3
  };

  unsigned int indices[]
  {
    0,1,2,
    2,3,0
  };

  //creating vertexarray
  vertex_array vertexarr;

  // creating and bining vertex_buffer
  vertex_buffer vertexbuff(positions, 4 * 2 * sizeof(FLOAT));

  //generating layout
  vertex_buffer_layout vertexlay;

  // pushing number of floats
  vertexlay.push<float>(2);

  
  // adding buffer to vertexarray
  vertexarr.add_buffer(vertexbuff, vertexlay);
    
  // creating and binding index_buffer
  index_buffer indexbuff(indices, 6);
 
  shader shader("shaders/basic.shader");
  shader.bind();
  shader.set_uniform_4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

  float r = 0.0f;
  float inc = 0.1f;

  vertexarr.unbind();
  vertexbuff.unbind();
  indexbuff.unbind();
  shader.unbind();


  while(!glfwWindowShouldClose(window))
  {
    glc(glClear(GL_COLOR_BUFFER_BIT));     
    vertexarr.bind();
    indexbuff.bind();
    shader.bind();

    glc(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

    shader.set_uniform_4f("u_Color", r, 0.3f, 0.8f, 1.0f);

    if (r > 1.0f)
      inc = -0.01f;
    else if (r < 0.0f)
      inc = 0.01f;
        
    r = r + inc;

    glc(glfwSwapBuffers(window));
    glfwPollEvents();
  }

  glfwTerminate();
  return 1;
}
