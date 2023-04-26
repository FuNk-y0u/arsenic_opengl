#pragma once

#include<string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "logs.h"
#include "renderer.h"

struct shader_program_source
{
  std::string vertex_src;
  std::string fragment_src;
};

class shader
{
    public:
        // constructor stuff
        ARC_API shader(const std::string& filepath);
        ARC_API ~shader();

        // shader binding
        ARC_API void bind() const;
        ARC_API void unbind() const;
        
        // settings value of unifrom
        ARC_API void set_uniform_4f(const std::string& name, float f0, float f1, float f2, float f3);
    
    private:
        std::string m_file_path;
        unsigned int program_id;
    
    private:
        // unifrom location finding
        ARC_API int get_uniform_location(const std::string& name);

        ARC_API shader_program_source parse_shader(const std::string& file_path);
        ARC_API unsigned int compile_shader(unsigned int type,  std::string& source);
        ARC_API unsigned int create_shader(std::string& vertex_shader, std::string& fragment_shader);


};