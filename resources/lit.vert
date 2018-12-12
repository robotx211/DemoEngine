uniform mat4 in_ProjMat;
uniform mat4 in_ViewMat;
uniform mat4 in_ModelMat;

attribute vec3 in_Position;

void main()
{
  gl_Position = in_ProjMat * in_ViewMat * in_ModelMat * vec4(in_Position, 1.0);
}

