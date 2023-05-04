#pragma once

namespace GLEngine::Drawing
{
	__interface IBasicVerticies
	{
		void GenerateBasicVerticies();
	};

	__interface ITexturedVerticies : public IBasicVerticies
	{
		void GenerateTexturedVerticies();
	};

	__interface ILightVerticies : public IBasicVerticies
	{
		void GenerateLightVerticies();
	};

	__interface ITexturedLightVerticies: public ITexturedVerticies, public ILightVerticies
	{
		void GenerateTexturedLightVerticies();
	};
}