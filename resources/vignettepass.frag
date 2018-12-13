uniform sampler2D in_TextureA;
uniform sampler2D in_TextureB;

varying vec2 ex_TexCoord;

void main()
{
  vec4 texBase = texture2D(in_TextureA, ex_TexCoord);
  vec4 texVingette = texture2D(in_TextureB, ex_TexCoord);

  //multiplies the texture fragment colour by the vignette fragment colour
  //(ie if vignette frag colour is (1,1,1), texture frag colour remains unchanged
  //(if vignette frag colour is (0,0,0), texture frag colour becomes (0,0,0)
  gl_FragColor = texBase * texVingette;
}
