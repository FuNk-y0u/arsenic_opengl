#include "vertexarray.h"

// creating vertex_array_object
vertex_array::vertex_array()
{
    glc(glGenVertexArrays(1, &buffer_id));
}

vertex_array::~vertex_array()
{
    glc(glDeleteVertexArrays(1, &buffer_id));
}

// adding and creating array buffer
void vertex_array::add_buffer(const vertex_buffer& vb, const vertex_buffer_layout& layout)
{
    bind();
    vb.bind();
    const auto& elements = layout.get_elements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];
        glc(glEnableVertexAttribArray(i));
        glc(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.get_stride(), (const void*)offset));

        offset += element.count * vertex_buffer_element::get_size_of_type(element.type);
        
    }

}

// binding vertex_array_object
void vertex_array::bind()
{
    glc(glBindVertexArray(buffer_id));

}

void vertex_array::unbind()
{

    glc(glBindVertexArray(0));

}