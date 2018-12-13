uniform sampler2D in_Texture;

varying vec2 ex_TexCoord;

void main()
{
  vec4 tex = texture2D(in_Texture, ex_TexCoord);

  //calculates the average value of the texture fragment colour
  float avg = (tex.x + tex.y + tex.z) / 3.0f;

  //sets the rgb of the fragment colour to the average texture fragment colour value
  gl_FragColor = vec4(avg, avg, avg, tex.a);
}
