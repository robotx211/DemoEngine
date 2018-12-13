uniform sampler2D in_Texture;

uniform vec3 in_LightCol;

uniform float in_AmbientLightStrength;

uniform vec3 in_LightPos;

uniform vec3 in_ViewPos;
uniform float in_SpecularStrength;

varying vec2 ex_TexCoord;
varying vec3 ex_FragPos;
varying vec3 ex_Normal;

void main()
{
  //frag colour based on tex
  vec4 tex = texture2D(in_Texture, ex_TexCoord);

  //ambient lighting colour
  vec3 ambient = in_LightCol * in_AmbientLightStrength;

  //diffuse lighting colour
  vec3 normal = normalize(ex_Normal);
  vec3 lightDir = normalize(in_LightPos - ex_FragPos);

  float diff = max(dot(normal, lightDir), 0.0);
  vec3 diffuse = diff * in_LightCol;
  
  //specular lighting colour
  vec3 viewDir = normalize(in_ViewPos - ex_FragPos);
  vec3 reflectDir = reflect(-lightDir, normal);
  
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
  vec3 specular = in_SpecularStrength * spec * in_LightCol * 1;

  //final colour calculation
  vec4 result = tex * vec4( ambient + diffuse + specular, 1);

  gl_FragColor = result;
}
