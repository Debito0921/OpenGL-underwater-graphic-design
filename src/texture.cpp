#include "texture.h"

texture::texture()
{
    //ctor
}

texture::~texture()
{
    //dtor
}

texture::texture(const texture& other)
{
    //copy ctor
}

texture& texture::operator=(const texture& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
