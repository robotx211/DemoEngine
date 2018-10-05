cmake_minimum_required(VERSION 2.6)
project(MYENGINE)

add_executable(game
  src/game/main.cpp
  src/myengine/Core.h
  src/myengine/Core.cpp
  src/myengine/Entity.h
  src/myengine/Entity.cpp
  src/myengine/Component.h
  src/myengine/Component.cpp
)