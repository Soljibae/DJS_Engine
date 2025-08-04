#include "CameraManager.h"

void CameraManager::SetCameraPosition(float x, float y)
{
	posX = x;
	posY = y;
}

void CameraManager::SetCameraZoom(float z)
{
	zoom = z;
}

void CameraManager::SetCameraOn(bool isCameraOn)
{
	this->isCameraOn = isCameraOn;
}

float CameraManager::GetCameraPositionX() const
{
	return posX;
}

float CameraManager::GetCameraPositionY() const
{
	return posY;
}

float CameraManager::GetCameraZoom() const
{
	return zoom;
}

bool CameraManager::GetCameraOn() const
{
	return isCameraOn;
}