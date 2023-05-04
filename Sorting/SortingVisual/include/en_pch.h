#pragma once
#include <stdarg.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include <functional>
#include <chrono>

#include "glm/glm.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/matrix_clip_space.hpp"

typedef struct GLFWwindow GLFWwindow;

enum class AxisPlane
{
	XY,
	XZ,
	ZY
};