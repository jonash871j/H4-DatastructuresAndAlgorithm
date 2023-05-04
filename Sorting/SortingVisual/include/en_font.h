#pragma once
#include "en_def.h"

namespace GLEngine
{
	enum class export FontType
	{
		TrueType,
		Bitmap
	};

	class Font
	{
	private:
		FontType _fontType;

	public:
		Font(FontType fontType);

	public:
		virtual void Dummy();
		export FontType GetFontType();
	};
}