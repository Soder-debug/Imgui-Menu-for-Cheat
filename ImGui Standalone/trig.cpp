#include "trig.h"
#include "Glob.h"
#include <iostream>

HBRUSH EnemyBrush = CreateSolidBrush(0x000000FF);
HDC screenDC = GetDC(HWND_DESKTOP);


void DrawFilledRect(int x, int y, int w, int h, HDC screenDC) {
    RECT rect = { x, y, x + w, y + h };
    FillRect(screenDC, &rect, EnemyBrush);
}

void DrawBorderBox(int x, int y, int w, int h, int thickness, HDC screenDC) {
    DrawFilledRect(x, y, w, thickness, screenDC);
    DrawFilledRect(x, y, thickness, h, screenDC);
    DrawFilledRect(x + w - thickness, y, thickness, h, screenDC);
    DrawFilledRect(x, y + h - thickness, w, thickness, screenDC);
}

bool isPurple(byte red, byte green, byte blue) {
    return red >= 110 && blue >= 100 && abs(red - blue) <= 13 && abs(red - green) >= 60 && green < 170;
}

void colorDetectionThread(int startX, int endX, int startY, int endY, Gdiplus::Bitmap& bitmap, int screenCenterX, int screenCenterY, std::atomic<bool>& stop_loop) {
    Gdiplus::Color color;

    for (int i = startY; i < endY && !stop_loop; ++i) {
        for (int j = startX; j < endX && !stop_loop; ++j) {
            bitmap.GetPixel(i, j, &color);

            byte red = color.GetR();
            byte green = color.GetG();
            byte blue = color.GetB();

            if (red >= 110 && blue >= 100 && abs(red - blue) <= 13 && abs(red - green) >= 60 && green < 170) {
                stop_loop = true;

                mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

                DrawBorderBox(screenCenterX + j - 15, screenCenterY + i - 10, 30, 30, 2, screenDC);
                Sleep(30);
            }
        }
    }
}

void PerformColorDetection(HDC screenDC) {
    int screenCenterX = GetSystemMetrics(SM_CXSCREEN) / 2;
    int screenCenterY = GetSystemMetrics(SM_CYSCREEN) / 2;

    int width = 5;
    int height = 5;

    int x = screenCenterX - width / 2;
    int y = screenCenterY - height / 2;

    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

    HDC memoryDC = CreateCompatibleDC(screenDC);
    HBITMAP memoryBitmap = CreateCompatibleBitmap(screenDC, width, height);

    HGDIOBJ oldBitmap = SelectObject(memoryDC, memoryBitmap);
    BitBlt(memoryDC, 0, 0, width, height, screenDC, x, y, SRCCOPY);
    SelectObject(memoryDC, oldBitmap);

    Gdiplus::Bitmap bitmap(memoryBitmap, nullptr);
    std::atomic<bool> stop_loop(false);

    int numThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    int threadWidth = width / numThreads;

    for (int i = 0; i < numThreads; ++i) {
        int startX = i * threadWidth;
        int endX = (i == numThreads - 1) ? width : startX + threadWidth;

        threads.emplace_back(colorDetectionThread, startX, endX, 0, height, std::ref(bitmap), screenCenterX, screenCenterY, std::ref(stop_loop));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    Gdiplus::GdiplusShutdown(gdiplusToken);
}