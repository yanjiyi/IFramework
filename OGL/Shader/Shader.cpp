#include "Shader.h"
#include "CoreService/IOService.h"
#include "CoreService/UIService.h"

Shader::Shader(IObject* parent) : IObject(parent)
{

}

Shader::~Shader()
{
	if(_shader_program_id>0)
		glDeleteProgram(_shader_program_id);
}

bool Shader::CompileFromSource(const char *vertexSource, const char *fragmentSource)
{
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader,1,(const GLchar* const*)&vertexSource,NULL);
	glShaderSource(fragmentShader,1,(const GLchar* const*)&fragmentSource,NULL);

	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	GLint isCompiled = GL_FALSE;
	glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&isCompiled);
	if(GL_FALSE == isCompiled)	{
		GLint maxLength = 0;
		glGetShaderiv(vertexShader,GL_INFO_LOG_LENGTH,&maxLength);

		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(vertexShader,maxLength,&maxLength,&infoLog[0]);
		
		UIService::MessageBox("OGL - Vertex Shader", (char*)&infoLog[0], IMSGBOX_ICON_ERROR|IMSGBOX_OK);		
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return false;
	}

	glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&isCompiled);
	if(GL_FALSE == isCompiled)
	{
		GLint maxLength = 0;
		glGetShaderiv(fragmentShader,GL_INFO_LOG_LENGTH,&maxLength);

		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(fragmentShader,maxLength,&maxLength,&infoLog[0]);
		
		UIService::MessageBox("OGL - Fragment Shader", (char*)&infoLog[0], IMSGBOX_ICON_ERROR|IMSGBOX_OK);		
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return false;

	}

	if(_shader_program_id>0)
		glDeleteProgram(_shader_program_id);

	_shader_program_id = glCreateProgram();
	glAttachShader(_shader_program_id,vertexShader);
	glAttachShader(_shader_program_id,fragmentShader);

	glLinkProgram(_shader_program_id);

	GLint isLinked = GL_FALSE;
	glGetProgramiv(_shader_program_id,GL_LINK_STATUS,&isLinked);
	if(GL_FALSE == isLinked)
	{
		GLint maxLength = 0;
		glGetProgramiv(_shader_program_id,GL_INFO_LOG_LENGTH,&maxLength);

		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(_shader_program_id,maxLength,&maxLength,&infoLog[0]);

		UIService::MessageBox("OGL - Shader Linking", (char*)&infoLog[0], IMSGBOX_ICON_ERROR|IMSGBOX_OK);

		glDetachShader(_shader_program_id,vertexShader);
		glDetachShader(_shader_program_id,fragmentShader);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		glDeleteProgram(_shader_program_id);

		_shader_program_id = 0;
		return false;
	}

	glDetachShader(_shader_program_id,vertexShader);
	glDetachShader(_shader_program_id,fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	return true;	
}

bool Shader::CompileFromFile(const char *vertexPath, const char *fragmentPath)
{
	auto vertex_buffer = IOService::ReadFile(vertexPath);
	auto fragment_buffer = IOService::ReadFile(fragmentPath);

	return CompileFromSource(vertex_buffer.data(), fragment_buffer.data());
}

void Shader::Apply()
{
	if(_shader_program_id>0)
		glUseProgram(_shader_program_id);
}

void Shader::Revoke()
{
	glUseProgram(0);
}

GLint Shader::getUniformLocation(const char *name)
{
	if(_shader_program_id<=0)
		return -1;

	return glGetUniformLocation(_shader_program_id,name);
}

void Shader::setUniform1i(GLint location, int value)
{
	if(location < 0)
	   return;

	glUniform1i(location,value);	
}

void Shader::setUniform1i(const char *name, int value)
{
	GLint location = getUniformLocation(name);
	if(location<0)
		return;
	
	setUniform1i(location,value);
}

void Shader::setUniform1f(GLint location, float value)
{
	if(location<0)
		return;

	glUniform1f(location,value);
}

void Shader::setUniform1f(const char *name, float value)
{
	GLint location = getUniformLocation(name);
	if(location<0)
		return;

	return setUniform1f(location,value);
}

void Shader::setUniform2f(GLint location, float *value)
{
	if(location<0)
		return;

	glUniform2f(location,value[0],value[1]);
}

void Shader::setUniform2f(const char *name, float *value)
{
	GLint location = getUniformLocation(name);
	if(location<0)
		return;

	setUniform2f(location,value);
}

void Shader::setUniform3f(GLint location, float *value)
{
	if(location<0)
		return;

	glUniform3f(location,value[0],value[1],value[2]);
}

void Shader::setUniform3f(const char *name, float *value)
{
	GLint location = getUniformLocation(name);
	if(location<0)
		return;

	setUniform3f(location,value);
}

void Shader::setUniform4f(GLint location, float *value)
{
	if(location<0)
		return;

	glUniform4f(location,value[0],value[1],value[2],value[3]);
}

void Shader::setUniform4f(const char *name, float *value)
{
	GLint location = getUniformLocation(name);
	if(location<0)
		return;

	setUniform4f(location, value);
}
