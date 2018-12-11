uniform sampler2D in_TextureA;
uniform sampler2D in_TextureB;

varying vec2 ex_TexCoord;

void main()
{
  vec4 texBase = texture2D(in_TextureA, ex_TexCoord);
  vec4 texVingette = texture2D(in_TextureB, ex_TexCoord);

  gl_FragColor = texBase * texVingette;
}
