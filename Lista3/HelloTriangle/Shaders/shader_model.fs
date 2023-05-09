//Código fonte do Fragment Shader (em GLSL)
#version 400
out vec4 color;
in vec2 texCoord;

uniform sampler2D texture1;

void main()
{
    color = texture(texture1,texCoord);
}