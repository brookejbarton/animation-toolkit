#version 400

layout (location = 0) in vec3 vPositions;

struct MaterialInfo {
  vec3 diffuse;
};

uniform mat4 MVP;
uniform MaterialInfo Material;

out vec4 color;

void main()
{
  color.rgb = Material.diffuse;
  gl_Position = MVP * vec4(vPositions, 1.0);
}
