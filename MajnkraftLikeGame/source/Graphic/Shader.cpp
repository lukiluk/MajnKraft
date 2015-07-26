#include <SDL2/begin_code.h>
#include <stdlib.h>

#include "Shader.h"

Shader::Shader() {
    fragmentShader = 0;
    shaderProgram = 0;
}

/*Skontroluje shader na chyby*/
void Shader::checkShader(GLuint shader, GLuint flag, bool isProgram) {
    GLint succes = 0;
    GLchar errorMsg[2048] = {0};
    (isProgram) ?
            glGetProgramiv(shader, flag, &succes) :
            glGetShaderiv(shader, flag, &succes);
    if (succes == GL_FALSE) {
        (isProgram) ?
                glGetProgramInfoLog(shader, sizeof (errorMsg), NULL, errorMsg) :
                glGetShaderInfoLog(shader, sizeof (errorMsg), NULL, errorMsg);
        fprintf(stderr, errorMsg);
    }
}

/*Nacita textureShader*/
void Shader::createShaders(std::string vertexSource,std::string fragmentSource) {
    const char* vsource = vertexSource.c_str();
    const char* fsource = fragmentSource.c_str();
    vertexShader = glCreateShader(GL_VERTEX_SHADER); //vytvori identifikator pre shader
    glShaderSource(vertexShader, 1, &vsource, NULL);
    glCompileShader(vertexShader);
    Shader::checkShader(shaderProgram, GL_COMPILE_STATUS, false);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fsource, NULL);
    glCompileShader(fragmentShader);
    checkShader(shaderProgram, GL_COMPILE_STATUS, false);
    
    // Link the vertex and fragment shader into a shader program
    shaderProgram = glCreateProgram(); //vytvori identifikator pre shader
    glAttachShader(shaderProgram, vertexShader); //prideli k shaderu vertex shader
    glAttachShader(shaderProgram, fragmentShader);
    glBindFragDataLocation(shaderProgram, 0, "pixel"); //ktory atribut je vysledna farba
    glLinkProgram(shaderProgram); //zlinkuje shader
    checkShader(shaderProgram, GL_LINK_STATUS, true);
    glUseProgram(shaderProgram); //prikaze pouzivat shader
}

std::string Shader::loadShader(std::string filename){
    std::string filePath;
    filePath.append(SHADER_PATH).append(filename);
    std::ifstream inf(filePath);
    std::string code;
    if(!inf){
        printf("Couldnt open shader %s",filePath.c_str());
        exit(-1);
    }
    std::string line;
    while ( std::getline (inf,line) )
    {
        code.append(line);
        code.append("\n");
        printf("%s\n",line.c_str());
    }
    inf.close();
    return code;
}

void Shader::bindProgram() {
    glUseProgram(shaderProgram);
}

GLuint Shader::getShaderProgram() const {
    return shaderProgram;
}

void Shader::addUniform(std::string name) {
    int location = glGetUniformLocation(shaderProgram, name.c_str());
    if (location == -1) {
        printf(((std::string)("Bad uniform name " + name + "\n")).c_str());
    }
    uniforms[name] = location;
}

void Shader::setUniform(std::string name, int value) {
    try {
        glUniform1i(uniforms[name], value);
    } catch (std::out_of_range e) {
        printf("Cannot set unexisting uniform %s", name.c_str());
    }
}

void Shader::setUniform(std::string name, float value) {
    try {
        glUniform1f(uniforms[name], value);
    } catch (std::out_of_range e) {
        printf("Cannot set unexisting uniform %s", name.c_str());
    }
}

void Shader::setUniform(std::string name, glm::vec3 value) {
    try {
        glUniform3f(uniforms[name], value.x, value.y, value.z);
    } catch (std::out_of_range e) {
        printf("Cannot set unexisting uniform %s", name.c_str());
    }
}

void Shader::setUniform(std::string name, glm::mat4 value) {
    try {
        glUniformMatrix4fv(uniforms[name], 1, GL_FALSE, glm::value_ptr(value));
    } catch (std::out_of_range e) {
        printf("Cannot set unexisting uniform %s", name.c_str());
    }
}

Shader::~Shader() {
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteProgram(shaderProgram);
}
