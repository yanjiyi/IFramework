cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)

project(IFramework)

#find_package(PkgConfig REQUIRED)
#pkg_check_modules(GTK4 REQUIRED gtk4)

#include_directories(${GTK4_INCLUDE_DIRS})
include_directories("include" "IObject")
#link_directories(${GTK4_LIBRARY_DIRS})

add_library(Ifw SHARED include/IObject.h IObject/IObject.cpp include/CoreService/IOService.h include/CoreService/UIService.h UIService/UIService.cpp include/UIApplication.h UIService/UIApplication.cpp include/OGL/Shader.h OGL/Shader/Shader.cpp include/OGL/Texture.h OGL/Texture/Texture.cpp)

target_link_libraries(Ifw SDL2 GLEW EGL GL GLU OpenGL)

