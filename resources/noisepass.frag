uniform sampler2D in_Texture;

uniform float in_Rand;

varying vec2 ex_TexCoord;

float random (vec2 st) {

	float rtn = fract(sin(dot(st.xy,vec2(12.9898,78.233)))*43758.5453123);

	rtn = (rtn/5)+0.8;

    return rtn;
}

void main()
{
  vec4 tex = texture2D(in_Texture, ex_TexCoord);

  float rnd = random( ex_TexCoord * in_Rand );

  gl_FragColor = tex * vec4(vec3(rnd),1.0);
}
