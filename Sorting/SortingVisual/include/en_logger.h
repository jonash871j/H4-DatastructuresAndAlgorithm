#pragma once
#include "en_def.h"

namespace GLEngine
{
	class Logger
	{
	public:
		export static void PrintlnInfo(const char* format, ...);
		export static void PrintlnWarning(const char* format, ...);
		export static void PrintlnError(const char* format, ...);
		export static void PrintlnErrorLocation(const char* name, const char* function, const char* file, int line);
		export static void PrintBuffer(char* buffer, int32_t length);
	};
}