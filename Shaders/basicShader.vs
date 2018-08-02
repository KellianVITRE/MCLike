#version 450 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec2 tcoords;
layout (location = 2) in vec4 normal;

out vec2 tcoord;

uniform mat4 MVP;

void main() {

	tcoord = tcoords;

	vec4 glpos = position;
	
	gl_Position = MVP * position;

}