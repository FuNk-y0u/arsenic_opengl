# pragma once

#include "renderer.h"
#include "logs.h"
#include "vertexbufferlayout.h"
#include "vertexbuffer.h"

class vertex_array
{
    private:
        unsigned int buffer_id;

    public:
        ARC_API vertex_array();
        ARC_API ~vertex_array();

        ARC_API void bind();
        ARC_API void unbind();
        ARC_API void add_buffer(const vertex_buffer& vb, const vertex_buffer_layout& layout);

};