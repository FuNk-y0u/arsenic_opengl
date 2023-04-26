#include "indexbuffer.h"
#include "renderer.h"

index_buffer::index_buffer(const void* data, unsigned int count)
    : m_count(count)
{
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));

    glc(glGenBuffers(1, &buffer_id));
    glc(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_id));
    glc(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

index_buffer::~index_buffer()
{
    glc(glDeleteBuffers(1, &buffer_id));
}

void index_buffer::bind()
{
    glc(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_id));
}

void index_buffer::unbind()
{
    glc(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}


