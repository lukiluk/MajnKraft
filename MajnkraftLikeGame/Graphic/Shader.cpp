#include "Shader.h"

Shader::Shader() {
    fragmentShader = 0;
    shaderProgram = 0;
}

/*Skontroluje shader na chyby*/
void Shader::checkShader(GLuint shader, GLuint flag, bool isProgram) {
    GLint succes = 0;
    GLchar errorMsg[1024] = {0};
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
void Shader::createShaders(char* vertexSource, char* fragmentSource) {
    //vytvori shader ktory urci body "trojuholnikov"
    /* const char* vertexSource = GLSL(
         uniform mat4 trans;
         uniform mat4 view;
         uniform mat4 proj;
         uniform vec3 overrideColor;

         in vec3 position;
         in vec3 color;
         in vec2 texcoord;

         out vec3 Color;
         out vec2 Texcoord;
        
         void main() {
             Color = overrideColor * color;
             Texcoord = texcoord;
             gl_Position = proj * view * trans * vec4(position, 1.0);
         }
     );*/

    vertexShader = glCreateShader(GL_VERTEX_SHADER); //vytvori identifikator pre shader
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    Shader::checkShader(shaderProgram, GL_COMPILE_STATUS, false);

    // Create and compile the fragment shader
    /* const char* fragmentSource = GLSL(
         uniform sampler2D tex0;
         uniform sampler2D tex1;

         in vec3 Color;
         in vec2 Texcoord;

         out vec4 outColor;
        
         void main() {
             outColor = mix(texture(tex0, Texcoord), texture(tex1, Texcoord), 0.5) * vec4(Color, 1.0);
         }
     );*/

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
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

void Shader::setUniform(std::string name, BaseLight baseLight) {
    setUniform(name + ".color", baseLight.GetColor());
    setUniform(name + ".intensity", baseLight.GetIntensity());
}

void Shader::setUniform(std::string name, DirectionalLight directionalLight) {

    setUniform((name + ".base"), directionalLight.GetBase());
    setUniform((name + ".direction"), directionalLight.GetDirection());
}

Shader::~Shader() {
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteProgram(shaderProgram);
}
