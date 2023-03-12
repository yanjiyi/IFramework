cmake_minimum_required(VERSION 3.5)

project(IFramework)

include_directories("include" "IObject")

add_library(Ifw SHARED include/IObject.h IObject/IObject.cpp include/CoreService/IOService.h include/CoreService/UIService.h UIService/UIService.cpp include/OGL/Shader.h OGL/Shader/Shader.cpp)

target_link_libraries(Ifw SDL2 GLEW EGL GL GLU OpenGL)

