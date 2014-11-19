#define GLEW_STATIC
#include <GL/glew.h>
#include "Shader.h"

#define GLSL(src) "#version 150 core\n" #src

Shader::Shader() {

}

void Shader::loadShader() {
// Create and compile the vertex shader
    const char* vertexSource = GLSL(
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
    );

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    // Create and compile the fragment shader
    const char* fragmentSource = GLSL(
        uniform sampler2D tex0;
        uniform sampler2D tex1;

        in vec3 Color;
        in vec2 Texcoord;

        out vec4 outColor;
        
        void main() {
            outColor = mix(texture(tex0, Texcoord), texture(tex1, Texcoord), 0.5) * vec4(Color, 1.0);
        }
    );

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    // Link the vertex and fragment shader into a shader program
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glBindFragDataLocation(shaderProgram, 0, "outColor");
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);
}

Shader::~Shader() {
  glDeleteShader(fragmentShader);
  glDeleteShader(vertexShader);
  glDeleteProgram(shaderProgram);
}
