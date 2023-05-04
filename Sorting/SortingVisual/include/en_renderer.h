#pragma once
#include "en_def.h"
#include "en_renderer_base.h"

namespace GLEngine
{
	class Renderer final : public RendererBase
	{
		friend Window;
	public:
		Renderer(Window& window);

	public:
		export void DrawLine(vec2 a, vec2 b);
		export void DrawTriangle(vec2 a, vec2 b, vec2 c);
		export void DrawRectangle(vec2 pos, vec2 size);
		export void DrawRectangle(vec2 a, vec2 b, vec2 c, vec2 d);
		export void DrawCircle(vec2 pos, float radius, int edges = 32);
		export void DrawCircle(vec2 pos, vec2 radius, int edges = 32);
		export void DrawText(string text);
		export void DrawTextf(const char* format, ...);

	public:
		export void Draw3DLine(vec3 a, vec3 b);
		export void Draw3DTriangle(vec3 a, vec3 b, vec3 c);
		export void Draw3DRectangle(vec2 pos, vec2 size, AxisPlane axisPlane = AxisPlane::XY);
		export void Draw3DRectangle(vec3 pos, vec2 size, AxisPlane axisPlane = AxisPlane::XY);
		export void Draw3DRectangle(vec2 a, vec2 b, vec2 c, vec2 d, AxisPlane axisPlane = AxisPlane::XY);
		export void Draw3DPlane(vec3 a, vec3 b, vec3 c, vec3 d);
		export void Draw3DCircle(vec3 pos, float radius, int edges = 32);
		export void Draw3DCircle(vec3 pos, vec2 radius, int edges = 32);
		export void Draw3DCircle(vec3 pos, vec3 radius, int edges = 32);
		export void Draw3DCube(vec3 pos, float size);
		export void Draw3DCube(vec3 pos, vec3 size);
		export void Draw3DVoxelModel(GLEngine::Drawing::VoxelModel& voxelModel, vec3 pos = { 0, 0, 0 }, float scale = 1.0f);
		export void Draw3DText(string text);
	};
}

