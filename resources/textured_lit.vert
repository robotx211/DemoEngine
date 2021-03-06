uniform mat4 in_ProjMat;
uniform mat4 in_ViewMat;
uniform mat4 in_ModelMat;

attribute vec3 in_Position;
attribute vec2 in_TexCoord;
attribute vec3 in_Normal;

varying vec2 ex_TexCoord;
varying vec3 ex_FragPos;
varying vec3 ex_Normal;

void main()
{
  gl_Position = in_ProjMat * in_ViewMat * in_ModelMat * vec4(in_Position, 1.0);

  ex_TexCoord = in_TexCoord;

  ex_FragPos = vec3(in_ModelMat * vec4(in_Position, 1.0));

  ex_Normal = mat3(transpose(inverse(in_ModelMat))) * in_Normal;
}

