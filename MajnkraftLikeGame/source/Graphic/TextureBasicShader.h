/* 
 * File:   TextureBasicShader.h
 * Author: Lukas
 *
 * Created on Utorok, 2015, marec 3, 17:06
 */

#ifndef TEXTUREBASICSHADER_H
#define	TEXTUREBASICSHADER_H

#include "Shader.h"

class TextureBasicShader :public Shader{
public:
    static TextureBasicShader& getInstance();
private:
    TextureBasicShader();
    TextureBasicShader(const TextureBasicShader& orig);
};

#endif	/* TEXTUREBASICSHADER_H */

