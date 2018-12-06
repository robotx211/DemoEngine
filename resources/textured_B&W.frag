uniform sampler2D in_Texture;

varying vec2 ex_TexCoord;

void main()
{
  vec4 tex = texture2D(in_Texture, ex_TexCoord);

  float avg = (tex.x + tex.y + tex.z) / 3.0f;

  gl_FragColor = vec4(avg, avg, avg, 1.0f);
}
