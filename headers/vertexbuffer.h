# pragma once

#include "renderer.h"
#include "logs.h"


class vertex_buffer
{
    private:
        unsigned int buffer_id;
    public:
        ARC_API vertex_buffer(const void* data, unsigned int size);
        ARC_API ~vertex_buffer();

        ARC_API void bind() const;
        ARC_API void unbind() const;

};