#pragma once

#include <vector>

#include "logs.h"
#include "renderer.h"
#include "vertexbufferlayout.h"
#include "indexbuffer.h"


struct vertex_buffer_element
{
    //  vertex_buffer_element properties
    unsigned int count;
    unsigned int type;
    unsigned char normalized;


    // returns the size of element
    static unsigned int get_size_of_type(unsigned int type)
    {
        switch(type)
        {
            case GL_FLOAT: return sizeof(float);
            case GL_UNSIGNED_INT: return sizeof(unsigned int);
            case GL_UNSIGNED_BYTE: return sizeof(unsigned char);

        }
        return 0;
        ASSERT(false);
    }
};

class vertex_buffer_layout
{
    private:
        // creating vertex_buffer_element
        std::vector<vertex_buffer_element> m_elements;
        unsigned int m_stride;

        // returns the type of element
        template <typename T>
        ARC_API unsigned int get_gl_type()
        {
            if (typeid(T) == typeid(float))        return GL_FLOAT;
            if (typeid(T) == typeid(int))          return GL_INT;
            if (typeid(T) == typeid(unsigned int)) return GL_UNSIGNED_INT;
            ASSERT(false);
        }
    
    public:

        // constructor
        ARC_API vertex_buffer_layout()
        : m_stride(0) {}

        template< typename T>
        ARC_API void push(unsigned int count)
        {   
            // adding value to m_elements class
            m_elements.push_back({count , get_gl_type<T>(), GL_FALSE});

            // updates stride
            m_stride += count * vertex_buffer_element::get_size_of_type(get_gl_type<T>());
        }
        
        // returns m_element
        ARC_API inline const std::vector<vertex_buffer_element> get_elements() const { return m_elements; }
        
        // returns the stride
        ARC_API inline unsigned int get_stride() const {return m_stride; }
};