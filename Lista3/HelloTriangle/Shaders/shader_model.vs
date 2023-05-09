// Código fonte do Vertex Shader (em GLSL)
#version 400
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 tex_coord;

uniform mat4 projection;
uniform mat4 model;

out vec2 texCoord;

void main()
{
	//...pode ter mais linhas de código aqui!
	gl_Position = projection * model * vec4(position, 1.0);
	texCoord = vec2(tex_coord.x, 1 - tex_coord.y);
}