#include "shader.h"

shader::shader(const std::string& file_path)
    : m_file_path(file_path), program_id(0)
{
    shader_program_source source_code = parse_shader(file_path);
    program_id = create_shader(source_code.vertex_src, source_code.fragment_src);
}

shader::~shader()
{
    glc(glDeleteProgram(program_id))
}


shader_program_source shader::parse_shader(const std::string& file_path)
{
  std::ifstream stream(file_path);

  enum class shader_type
  {
    NONE = -1, VERTEX = 0, FRAGMENT = 1
  };

  std::string line;
  std::stringstream str_str[2];
  shader_type type = shader_type::NONE;
  while(getline(stream, line))
  {
    if(line.find("#shader") != std::string::npos)
    {
      if(line.find("vertex") != std::string::npos)
        type = shader_type::VERTEX;
      else if(line.find("fragment") != std::string::npos)
        type = shader_type::FRAGMENT;
    }
    else
    {
      str_str[(int)type] << line << "\n";
    }
  }
  return {str_str[0].str(), str_str[1].str()};
}


unsigned int shader::compile_shader(unsigned int type,  std::string& source)
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

unsigned int shader::create_shader(std::string& vertex_shader, std::string& fragment_shader)
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

void shader::bind() const
{
    glc(glUseProgram(program_id));
}

void shader::unbind() const
{
    glc(glUseProgram(0));
}

void shader::set_uniform_4f(const std::string& name, float f0, float f1, float f2, float f3)
{
    glc(glUniform4f(get_uniform_location(name), f0, f1, f2, f3));
}

int shader::get_uniform_location(const std::string& name)
{

    glc(int location = glGetUniformLocation(program_id, name.c_str()));
    if(location == -1)
    {
        std::cout << "[warning]: uniform" << name << " doesnot exist" << std::endl;
    }

    return location;
}