#version 450 core

in vec2 tcoord;

out vec4 pixelColor;

uniform sampler2D sampler;

void main() {
	pixelColor = texture2D(sampler, tcoord);

	if(pixelColor.a < 0.1) {
		discard;
	}
}