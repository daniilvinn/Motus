#shadertype vertex
#version 460 core

layout(location = 0) in vec3 a_Pos;

void main() {
	gl_Position = vec4(a_Pos, 1.0f);
}

#shadertype fragment
#version 460 core

out vec4 color;

void main() {
	color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}