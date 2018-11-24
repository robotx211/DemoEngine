varying vec2 ex_TexCoord;

void main()
{
  gl_FragColor = vec4(ex_TexCoord.x, ex_TexCoord.y, 0, 0);
}