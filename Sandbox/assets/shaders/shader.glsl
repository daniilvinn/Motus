#shadertype vertex
#version 460 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec3 a_Color;

uniform mat4 u_VP;

out vec3 VertexColor;

void main() {
	gl_Position = u_VP * vec4(a_Position, 1.0f);
	VertexColor = a_Color;
}

#shadertype fragment
#version 460 core

in vec3 VertexColor;
out vec4 color;

void main() {
	color = vec4(VertexColor, 1.0f);
}