#pragma once
#include "en_def.h"
#include "en_renderer_base.h"

namespace OpenGLEngine
{
	class ShapeRenderer : public RendererBase
	{
    public:
        ShapeRenderer();

    public:
        export void DrawTriangle(glm::vec2 a, glm::vec2 b, glm::vec2 c, glm::vec3 color = { 1.0f, 1.0f, 1.0f });

    protected:
        virtual void UpdateShader() override;
        virtual void InitRenderData() override;
	};
}

