uniform vec3 in_LightCol;

void main()
{
  vec3 objectCol = vec3(1.0f, 1.0f, 1.0f);

  gl_FragColor = vec4(in_LightCol * objectCol, 1.0);
}
