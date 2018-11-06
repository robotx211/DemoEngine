#ifndef ENUMS_H
#define ENUMS_H

namespace myEngine
{

  namespace enums
  {

    enum ShaderType
    {
      Vertex,
      Fragment
    };

    enum ShaderAttribute
    {
      in_Position,  //0
			in_TexCoord,
			in_Normal
    };

  }

}

#endif //!ENUMS_H