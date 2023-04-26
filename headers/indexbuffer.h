# pragma once

#include "logs.h"

class index_buffer
{
    private:
        unsigned int buffer_id;
        unsigned int m_count;
    public:

        ARC_API index_buffer(const void* data, unsigned int count);
        ARC_API ~index_buffer();

        ARC_API void bind();
        ARC_API void unbind();

        ARC_API inline unsigned int get_count() { return m_count; }

};