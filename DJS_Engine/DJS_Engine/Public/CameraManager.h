#pragma once

class CameraManager {
private:
	float posX = 0.f;
	float posY = 0.f;
	float zoom = 1.f;

	bool isCameraOn = false;

public:
	void SetCameraPosition(float x, float y);
	void SetCameraZoom(float z);
	void SetCameraOn(bool isCameraOn);

	float GetCameraPositionX() const;
	float GetCameraPositionY() const;
	float GetCameraZoom() const;
	bool GetCameraOn() const;
};