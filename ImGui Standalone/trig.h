#pragma once

#include <windows.h>
#include <gdiplus.h>
#include <thread>
#include <vector>
#include <atomic>

#pragma comment(lib, "gdiplus.lib")


void PerformColorDetection(HDC screenDC);
