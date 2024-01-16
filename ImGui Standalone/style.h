#include "ImGui/imgui.h"

void SetCustomImGuiStyle()
{
    ImGuiStyle& style = ImGui::GetStyle();

    style.WindowPadding = ImVec2(10, 10);
    style.WindowRounding = 4.0f;
    style.FramePadding = ImVec2(2, 1);
    style.FrameRounding = 2.0f;
    style.ItemSpacing = ImVec2(8, 8);
    style.ItemInnerSpacing = ImVec2(4, 4);
    style.ScrollbarSize = 15.0f;
    style.ScrollbarRounding = 9.0f;
    style.GrabMinSize = 10.0f;
    style.GrabRounding = 3.0f;

    ImVec4* colors = style.Colors;
    colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.6f, 0.6f, 0.6f, 1.0f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.95f); 
    colors[ImGuiCol_Border] = ImVec4(0.1f, 0.1f, 0.1f, 0.5f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.54f); 
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.0f, 0.2f, 0.6f, 0.40f); 
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.0f, 0.2f, 0.6f, 0.67f); 
    colors[ImGuiCol_TitleBg] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f); 
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.0f, 0.0f, 0.0f, 0.75f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.47f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.53f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f); 
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.0f, 0.2f, 0.6f, 0.40f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.0f, 0.2f, 0.6f, 0.67f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f); 
    colors[ImGuiCol_SliderGrab] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f); 
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f); 
    colors[ImGuiCol_Button] = ImVec4(0.0f, 0.2f, 0.6f, 0.40f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.0f, 0.2f, 0.6f, 0.60f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f);
    colors[ImGuiCol_Header] = ImVec4(0.0f, 0.2f, 0.6f, 0.40f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.0f, 0.2f, 0.6f, 0.60f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f);
    colors[ImGuiCol_Separator] = ImVec4(0.1f, 0.1f, 0.1f, 0.50f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.0f, 0.2f, 0.6f, 0.78f); 
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f); 
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.0f, 0.2f, 0.6f, 0.25f); 
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.0f, 0.2f, 0.6f, 0.67f); 
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.0f, 0.2f, 0.6f, 0.95f);
    colors[ImGuiCol_Tab] = ImVec4(0.1f, 0.1f, 0.1f, 0.86f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.0f, 0.2f, 0.6f, 0.80f); 
    colors[ImGuiCol_TabActive] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f); 
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.1f, 0.1f, 0.1f, 0.97f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.0f, 0.2f, 0.6f, 0.97f); 
    colors[ImGuiCol_PlotLines] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f);
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f);
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f);
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f);
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.0f, 0.2f, 0.6f, 0.43f); 
    colors[ImGuiCol_DragDropTarget] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f);
    colors[ImGuiCol_NavHighlight] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f);
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.0f, 0.2f, 0.6f, 1.0f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.1f, 0.1f, 0.1f, 0.2f);
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.1f, 0.1f, 0.1f, 0.35f);
}

