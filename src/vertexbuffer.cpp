#include "vertexbuffer.h"


vertex_buffer::vertex_buffer(const void* data, unsigned int size)
{
    glc(glGenBuffers(1, &buffer_id));
    glc(glBindBuffer(GL_ARRAY_BUFFER, buffer_id));
    glc(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

vertex_buffer::~vertex_buffer()
{
    glc(glDeleteBuffers(1, &buffer_id));
}

void vertex_buffer::bind() const
{
    glc(glBindBuffer(GL_ARRAY_BUFFER, buffer_id));
}

void vertex_buffer::unbind() const 
{
    glc(glBindBuffer(GL_ARRAY_BUFFER, 0));
}