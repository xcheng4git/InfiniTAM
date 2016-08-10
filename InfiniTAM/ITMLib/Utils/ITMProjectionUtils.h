// Copyright 2014-2016 Isis Innovation Limited and the authors of InfiniTAM

#pragma once
#ifndef __METALC__
#include <math.h>
#endif

#include "ITMMath.h"
#include "../../ORUtils/PlatformIndependence.h"

// Templated to handle both Vector3f and Vector4f as inputs
template<typename T> _CPU_AND_GPU_CODE_ inline Vector2f project(const THREADPTR(T) &point_3d, const THREADPTR(Vector4f) &intrinsics)
{
	return Vector2f(intrinsics.x * (float)point_3d.x / (float)point_3d.z + intrinsics.z,
					intrinsics.y * (float)point_3d.y / (float)point_3d.z + intrinsics.w);
}

template<typename T> _CPU_AND_GPU_CODE_ inline Vector3f reproject(const THREADPTR(T) &point_2d, const THREADPTR(float) depth, const THREADPTR(Vector4f) &intrinsics)
{
	return Vector3f(depth * (((float)point_2d.x - intrinsics.z) / intrinsics.x),
					depth * (((float)point_2d.y - intrinsics.w) / intrinsics.y),
					depth);
}

template<typename T> _CPU_AND_GPU_CODE_ inline Vector3f reproject(const THREADPTR(T) x, const THREADPTR(T) y, const THREADPTR(float) depth, const THREADPTR(Vector4f) &intrinsics)
{
	return Vector3f(depth * (((float)x - intrinsics.z) / intrinsics.x),
					depth * (((float)y - intrinsics.w) / intrinsics.y),
					depth);
}
