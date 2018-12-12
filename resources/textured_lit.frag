uniform sampler2D in_Texture;

uniform vec3 in_AmbientLightCol;
uniform float in_AmbientLightStrength;

varying vec2 ex_TexCoord;
varying vec3 ex_Normal;

void main()
{
  vec3 ambientLight = in_AmbientLightCol * in_AmbientLightStrength;

  vec4 tex = texture2D(in_Texture, ex_TexCoord);

  vec4 result = tex * vec4(ambientLight, 1);

  gl_FragColor = result;
}
