#pragma once

#include <GL/glew.h>
#include <GLM\glm.hpp>

namespace SDLopenGL
{
    struct Color 
	{
        GLubyte r;
        GLubyte g;
        GLubyte b;
        GLubyte a;

		Color()
			:
			r(255),
			g(255),
			b(255),
			a(255)
		{	}

		Color(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha = 255)
			:
			r(red),
			g(green),
			b(blue),
			a(alpha)
		{	}
    };

    struct TexCoord
	{
        float u;
        float v;

		TexCoord()
			:
			u(0.0f),
			v(0.0f)
		{	}

		TexCoord(float texU, float texV)
			:
			u(texU),
			v(texV)
		{	}
    };

    //The vertex definition
    struct SColorTextureVertex
	{
        //This is the position struct. When you store a struct or class
        //inside of another struct or class, it is called composition. This is
        //layed out exactly the same in memory as if we had a float position[2],
        //but doing it this way makes more sense.
        glm::vec2 position;

        //4 bytes for r g b a color.
        Color color;

        //UV texture coordinates.
		TexCoord uv;

        void setPosition(float x, float y)
		{
            position.x = x;
            position.y = y;
        }

        void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a = 255)
		{
            color.r = r;
            color.g = g;
            color.b = b;
            color.a = a;
        }

        void setUV(float u, float v) 
		{
            uv.u = u;
            uv.v = v;
        }
    };

}