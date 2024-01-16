#include "Drawing.h"
#include "func.h"


LPCSTR Drawing::lpWindowName = "PASTER NAME";
ImVec2 Drawing::vWindowSize = { 550, 400 };
ImGuiWindowFlags Drawing::WindowFlags = 0;
bool Drawing::bDraw = true;


const int AIMBOT_TAB = 0;
const int ESP_TAB = 1;
const int MISC_TAB = 2;
const int CFG_TAB = 3;




int currentTab = AIMBOT_TAB;

void Drawing::Active()
{
	bDraw = true;
}

bool Drawing::isActive()
{
	return bDraw == true;
}

void Spacing(float pixels)
{
    ImGui::Dummy(ImVec2(0.0f, pixels));
}



void Drawing::Draw()
{
    if (isActive())
    {
        ImGui::SetNextWindowSize(vWindowSize, ImGuiCond_Once);
        ImGui::SetNextWindowBgAlpha(1.0f);
        ImGui::Begin(lpWindowName, &bDraw, WindowFlags | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoClose);
        {

            
            ImGui::BeginGroup();
            {
                
                ImGui::BeginChild("Tabs", ImVec2(100, 0), true);

                {
                    // Tab 1
                    if (ImGui::Button("AIMBOT", ImVec2(-1,50))) 
                    {
                        currentTab = AIMBOT_TAB;
                    }

                    Spacing(30.f);

                    // Tab 2
                    if (ImGui::Button("ESP", ImVec2(-1, 50)))
                    {
                        currentTab = ESP_TAB;
                    }

                    Spacing(30.f);

                    
                    if (ImGui::Button("MISC", ImVec2(-1, 50)))
                    {
                        currentTab = MISC_TAB;
                    }

                    Spacing(30.f);

                    if (ImGui::Button("CFG", ImVec2(-1, 50))) 
                    {
                        currentTab = CFG_TAB;
                    }
                }
                ImGui::EndChild();
            }
            ImGui::SameLine();  // Align content to the right of the tab bar
            {
                // Content for the selected tab
                if (currentTab == AIMBOT_TAB)
                {
                    ImGui::BeginChild("AIM", ImVec2(0, 0), false);
                    {
                        Spacing(20.f);

                        ImGui::Checkbox("Enable AIMBOT    ", &AIM);
                        ImGui::SameLine();
                        ImGui::PushItemWidth(100);
                        ImGui::SliderFloat("Smoothing", &smoothing, 0.f, 10.f);

                        Spacing(10.f);

                        ImGui::Checkbox("Draw FOV         ", &FOV);
                        ImGui::SameLine();
                        ImGui::PushItemWidth(100);
                        ImGui::SliderFloat("FOV Size", &FOVS, 0.f, 10.f);

                        Spacing(10.f);

                        ImGui::Checkbox("Visibility Check", &VISCHECK);

                        Spacing(10.f);

                        ImGui::Checkbox("Silent Aim", &Silent);

                        Spacing(10.f);

                        ImGui::Checkbox("MagicBullet", &Magic);

                    }
                    ImGui::EndChild();
                }
                else if (currentTab == ESP_TAB)
                {
                    ImGui::BeginChild("ESP", ImVec2(0, 0), false);
                    {
                        Spacing(20.f);

                        ImGui::Checkbox("ESP     ", &ESP);

                        Spacing(10.f);

                        ImGui::Checkbox("Box ESP     ", &Box);
                        ImGui::SameLine();
                        ImGui::ColorEdit4("##BoxColorPicker", &BoxColor.x, ImGuiColorEditFlags_NoInputs);

                        Spacing(10.f);

                        ImGui::Checkbox("Skeleton ESP", &Skeleton);
                        ImGui::SameLine();
                        ImGui::ColorEdit4("##SkeletonColorPicker", &SkeletonColor.x, ImGuiColorEditFlags_NoInputs);

                        Spacing(10.f);

                        ImGui::Checkbox("HeadDot", &HeadDot);

                    }
                    ImGui::EndChild();
                }
                else if (currentTab == MISC_TAB)
                {
                    ImGui::BeginChild("MISC", ImVec2(0, 0), false);
                    {
                        Spacing(20.f);

                        ImGui::Text("Put what you want here");
                        ImGui::Text("dont know what kind of cheat your making");
                    }
                    ImGui::EndChild();
                }
                else if (currentTab == CFG_TAB)
                {
                    ImGui::BeginChild("CFG", ImVec2(0, 0), false);
                    {
                        Spacing(20.f);

                        ImGui::Text("Make your own Congfig system nerd");

                    }
                    ImGui::EndChild();
                

                
            }
        }
            ImGui::EndGroup();
    }
        ImGui::End();
}

#ifdef _WINDLL
    if (GetAsyncKeyState(VK_INSERT) & 1)
        bDraw = !bDraw;
#endif
}

