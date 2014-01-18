#pragma once

class Renderer
{
public:
	static bool Init(HWND hwnd);
	static bool OnSize(HWND hwnd);
	static bool Update(HWND hwnd);
	static bool Destroy(HWND hwnd);
};