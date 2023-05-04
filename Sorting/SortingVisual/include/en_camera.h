#pragma once
#include "en_def.h"

namespace GLEngine
{
	class Camera
	{
	private:
		mat4 _view;
		vec3 _position = { 0.0f, 0.0f, 0.0f };
		vec3 _movementX;
		vec3 _movementY;
		vec3 _movementZ;
		vec3 _directionVector;
		float _pitch = 0.0f;
		float _yaw;

	public:
		export Camera();

	public:
		export float PointSelectionDistance(vec3 point);
		export void SetPitch(float pitch);
		export float GetPitch();
		export void SetYaw(float yaw);
		export float GetYaw();
		export void SetPosition(vec3 position);
		export void SetCameraView(vec3 position, vec3 magic1, vec3 magic2);
		export vec3 GetPosition();
		export vec3 GetMovementX();
		export vec3 GetMovementY();
		export vec3 GetMovementZ();
		export vec3 GetDirectionVector();
		export mat4 GetView();

	private:
		void UpdateMovement();
	};
}


