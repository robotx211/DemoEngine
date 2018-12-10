uniform sampler2D in_Texture;

varying vec2 ex_TexCoord;

void main()
{
  vec4 tex = texture2D(in_Texture, ex_TexCoord);

  if(tex.x > 0.8 || tex.y > 0.8 || tex.z > 0.8)
  {
    tex = vec4(tex.x, tex.y, tex.z, 1);
    //tex = tex * vec4(1.2, 1.2, 1.2, 1);
    //tex = max(tex, vec4(1, 1, 1, 1));
  }
  else
  {
    tex = vec4(0, 0, 0, 1);
  }

  gl_FragColor = tex;
}
