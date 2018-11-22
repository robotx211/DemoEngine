uniform sampler2D in_Texture;

varying vec2 ex_TexCoord;

void main()
{
  vec4 tex = texture2D(in_Texture, ex_TexCoord);
  gl_FragColor = vec4(ex_TexCoord.x, ex_TexCoord.y, 0, 0) + tex;
}