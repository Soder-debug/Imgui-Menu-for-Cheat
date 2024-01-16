#ifndef DRAWING_H
#define DRAWING_H

#include "pch.h"
#include "ImGui/imgui.h"

#define ImGuiWindowFlags_NoClose 0x0080

class Drawing
{
private:
	static LPCSTR lpWindowName;
	static ImVec2 vWindowSize;
	static ImGuiWindowFlags WindowFlags;
	static bool bDraw;

public:
	static void Active();
	static bool isActive();
	static void Draw();
};

#endif
