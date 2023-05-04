#pragma once
#include "en_def.h"

namespace GLEngine::Math
{
	const float PI = 3.14159265358979323846f;

	export float Pow(float x, float y);
	export float Sqrt(float x);
		   
	export float Sin(float x);
	export float SinDeg(float x);
	export float Cos(float x);
	export float CosDeg(float x);
	export float Tan(float x);
	export float Sec(float x);
	export float Cot(float x);
	export float Csc(float x);
		   
	export float ASin(float x);
	export float ACos(float x);
	export float ATan(float x);
		   
	export float Log(float x);
		   
	export float Abs(float x);
	export vec3 Abs(vec3 vec);
	export float Floor(float x);
	export vec2 Floor(vec2 vec);
	export vec3 Floor(vec3 vec);
	export float Round(float x);
	export vec3 Round(vec3 vec);
	export vec2 Round(vec2 vec);
	export float Ceil(float x);
	export vec2 Ceil(vec2 vec);
	export vec3 Ceil(vec3 vec);
	export float Sign(float x);
	export vec2 Sign(vec2 vec);
	export vec3 Sign(vec3 vec);

	export float DistanceToPoint(vec2 p1, vec2 p2);
	export float DistanceToPoint(vec3 p1, vec3 p2);
	export float DistanceToZero(vec3 p);
	export vec3 CrossProduct(vec3 a, vec3 b);
	export vec3 ByAxisPlane(vec2 v, AxisPlane axisPlane);
	export vec3 ByAxisPlane(vec3 v, AxisPlane axisPlane);
	export bool LineIntersection(vec2 a, vec2 b, vec2 c, vec2 d, vec2& point);
	export bool PointInsideTriangle(vec2 point, vec2 a, vec2 b, vec2 c);
	export bool TriangulatePoints(const std::vector<vec2>& contour, std::vector<vec2>& result);

	export float Random(float min, float max);
	export int Random(int min, int max);

	template<typename T>
	static void Limit(T& value, T min, T max)
	{
		if (value < min)
		{
			value = min;
		}
		else if (value > max)
		{
			value = max;
		}
	}
}