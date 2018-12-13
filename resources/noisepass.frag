//sourced from: https://thebookofshaders.com/10/

uniform sampler2D in_Texture;

uniform float in_Rand;

varying vec2 ex_TexCoord;

//generates a psudo random number between 0 and 0.2, taking a vec2 as the seed
float random (vec2 st) {

	//generates a psudo random float (-0.999... -> 0.999...)
	float rtn = fract(sin(dot(st.xy,vec2(12.9898,78.233)))*43758.5453123);

	//converts the random float into a positive (0.0 -> 0.999...)
	rtn = abs(rtn);
	
	//converts the random float to be between 0.0 and 0.2
	rtn = rtn/2;
	
	//converts the random float to be between 0.8 and 1.0
	rtn = rtn + 0.8;

    return rtn;
}

void main()
{
  vec4 tex = texture2D(in_Texture, ex_TexCoord);

  //generates a random float between 0.8 and 1 using the tex coord as a seed
  //an extarnal random number is used to chaneg the random number each frame
  float rnd = random( ex_TexCoord * in_Rand );

  //multiplies the texture fragment colour random number (0.8 -> 1.0)
  gl_FragColor = tex * vec4(vec3(rnd),1.0);
}
