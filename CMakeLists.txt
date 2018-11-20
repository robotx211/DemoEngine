cmake_minimum_required(VERSION 2.6)
project(MYENGINE)

include_directories(
	src
  	contrib
)

if(MSVC)
  	include_directories(
    		contrib/msvc-windows-x86/glew/include
    		contrib/msvc-windows-x86/SDL2/include
  	)

  	link_directories(
    		${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
   		${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
  	)
else()
  	include_directories(
    		/usr/X11R6/include
    		/usr/local/include
  	)

  	link_directories(
    		/usr/X11R6/lib
    		/usr/local/lib
  	)
endif()

if(MSVC)
  	add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_library(myengine

  	contrib/stb_image/stb_image.cpp

  	src/myengine/Core.cpp
 	src/myengine/Entity.cpp
 	src/myengine/Component.cpp
	src/myengine/Transform.cpp
	src/myengine/Window.cpp
	src/myengine/ShaderProgram.cpp
	src/myengine/VertexArray.cpp
	src/myengine/VertexBuffer.cpp
	src/myengine/Mesh.cpp
	src/myengine/MeshRenderer.cpp
	src/myengine/Utilities.cpp
	src/myengine/Camera.cpp
	src/myengine/Move.cpp
	src/myengine/Texture.cpp
	src/myengine/Keyboard.cpp
	src/myengine/Mouse.cpp
	src/myengine/Enviroment.cpp
	src/myengine/RenderTexture.cpp
)

if(MSVC)
  	target_link_libraries(myengine
    		SDL2 glew32 opengl32
  	)
else()
  	target_link_libraries(myengine
    		SDL2 GLU GLEW GL
  	)
endif()

add_executable(game
  	src/game/main.cpp
)

target_link_libraries(game 
	myengine
)

ADD_DEPENDENCIES(game 
	myengine
)

if(MSVC)
  	add_custom_command(TARGET game POST_BUILD
    		COMMAND ${CMAKE_COMMAND} -E copy_if_different
      			"${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
      			"$<TARGET_FILE_DIR:game>"
  	)

  	add_custom_command(TARGET game POST_BUILD
    		COMMAND ${CMAKE_COMMAND} -E copy_if_different
      			"${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/bin/glew32.dll"
      			"$<TARGET_FILE_DIR:game>"
  	)
endif()