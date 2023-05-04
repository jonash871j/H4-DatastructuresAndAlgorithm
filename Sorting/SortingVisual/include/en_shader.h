#pragma once
#include "en_def.h"

namespace GLEngine
{
	class export Shader
	{
	private:
		unsigned _id;
		string _vertexPath;
		string _fragmentPath;

	public:
		Shader(string vertexPath, string fragmentPath);

	public:
		static Shader LoadShader(string vertexPath, string fragmentPath);
		void Load();
		int GetId();
		void Use();

		void SetBool(const char* name, bool value);
		void SetInt(const char* name, int value);
		void SetFloat(const char* name, float value);
		void SetMat4(const char* name, mat4 value);
		void SetVec2(const char* name, vec2 value);
		void SetVec3(const char* name, vec3 value);
		void SetVec4(const char* name, vec4 value);
		void SetFloatArray(const char* name, float values[], int size);

	private:
		void CreateShader(char* source, const char* name, int type);
		void CreateShaderProgram();
	};
}