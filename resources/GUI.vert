attribute vec3 in_Position;
attribute vec2 in_TexCoord;

varying vec2 ex_TexCoord;

void main()
{
  gl_Position = vec4(in_Position, 1.0);
  ex_TexCoord = in_TexCoord;
}