#ifndef ENUMS_H
#define ENUMS_H

#include <string>

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
			in_Normal,
			in_ModelMat,
			in_ViewMat,
			in_ProjMat
		};

	}

}

#endif //!ENUMS_H