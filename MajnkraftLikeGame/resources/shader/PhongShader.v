#version 330

uniform mat4 trans;
uniform mat4 view;
uniform mat4 proj;

in vec3 position;
in vec2 texcoord;
in vec3 normal;
out vec2 Texcoord;
out vec3 normal0;
out vec3 worldPos0;

void main() {
	Texcoord = texcoord;
	gl_Position = proj * view * trans * vec4(position, 1.0);
	normal0 = (trans * vec4(normal,0.0f)).xyz;
	worldPos0 = (trans * vec4(position,1.0f)).xyz;
}