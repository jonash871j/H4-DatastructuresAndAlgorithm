#pragma once
#include "en_def.h"
#include "en_modifer.h"
#include "en_camera.h"
#include "en_drawing.h"
#include "en_geometry_binder.h"
#include "en_renderer_settings.h"
#include "en_frame_buffer.h"

namespace GLEngine
{
	using GLEngine::Drawing::Geometry;

	class RendererBase abstract
 	{
	protected:
		Window& window;
		Modifier modifier;
		RendererSettings rendererSettings;
		Camera camera;
		FrameBuffer frameBuffer;

	public:
		export RendererBase(Window& window);

	public:
		export void Initialize();
		export void DrawGeometry(Geometry& geometry);

	public:
		export void Update();
		export void UpdateResoulution();

	public:
		export void SetBackgroundColor(vec3 color);
		export Modifier& GetModifier();
		export RendererSettings& GetRendererSettings();
		export Camera& GetCamera();
	};
}
