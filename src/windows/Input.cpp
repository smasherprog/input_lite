#include "Input_Lite.h"
#include "InputManager.h"

#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef DELETE 

namespace SL {
    namespace Input_Lite {

        const unsigned char WIN_HID_TO_NATIVE[] = {
            255,255,255,255, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76,
            77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 49, 50,
            51, 52, 53, 54, 55, 56, 57, 48, 13, 27,  8,  9, 32,189,187,219,
            221,220,255,186,222,192,188,190,191, 20,112,113,114,115,116,117,
            118,119,120,121,122,123, 44,145, 19, 45, 36, 33, 46, 35, 34, 39,
            37, 40, 38,144,111,106,109,107,255, 97, 98, 99,100,101,102,103,
            104,105, 96,110,255,255,255,255,124,125,126,127,128,129,130,131,
            132,133,134,135,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            17, 16, 18,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255
        };
        const unsigned char WIN_NATIVE_TO_HID[] = {
            255,255,255,255,255,255,255,255, 42, 43,255,255,255, 40,255,255,
            225,224,226, 72, 57,255,255,255,255,255,255, 41,255,255,255,255,
            44, 75, 78, 77, 74, 80, 82, 79, 81,255,255,255, 70, 73, 76,255,
            39, 30, 31, 32, 33, 34, 35, 36, 37, 38,255,255,255,255,255,255,
            255,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
            19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,255,255,255,255,255,
            98, 89, 90, 91, 92, 93, 94, 95, 96, 97, 85, 87,255, 86, 99, 84,
            58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,104,105,106,107,
            108,109,110,111,112,113,114,115,255,255,255,255,255,255,255,255,
            83, 71,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255, 51, 46, 54, 45, 55, 56,
            53,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255, 47, 49, 48, 52,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255
        };

        void SendInput(const PlatformIndependentKeyEvent& e) {
            INPUT k = { 0 };
            k.type = INPUT_KEYBOARD;
            k.ki.dwFlags = e.Pressed ? 0 : KEYEVENTF_KEYUP;
            k.ki.wVk = WIN_HID_TO_NATIVE[e.Key];
            SendInput(1, &k, sizeof(INPUT));
        }
        void SendInput(const PlatformIndependentMouseEvent& e) {
            INPUT inp = { 0 };
            inp.type = INPUT_MOUSE;
            switch (e.Button) {
            case (MouseButtons::LEFT):
                inp.mi.dwFlags = e.Pressed ? MOUSEEVENTF_LEFTDOWN : MOUSEEVENTF_LEFTUP;
                break;
            case (MouseButtons::RIGHT):
                inp.mi.dwFlags = e.Pressed ? MOUSEEVENTF_RIGHTDOWN : MOUSEEVENTF_RIGHTUP;
                break;
            case (MouseButtons::MIDDLE):
                inp.mi.dwFlags = e.Pressed ? MOUSEEVENTF_MIDDLEDOWN : MOUSEEVENTF_MIDDLEUP;
                break;
            default:
                return;
            }
            SendInput(1, &inp, sizeof(INPUT));
        }

        void SendInput(const MouseMoveEvent<MouseScroll>& e) {
            INPUT inp = { 0 };
            inp.type = INPUT_MOUSE;
            inp.mi.dwFlags = MOUSEEVENTF_WHEEL;
            inp.mi.mouseData = e.Position.Offset * 120;
            SendInput(1, &inp, sizeof(INPUT));
        }
        void SendInput(const MouseMoveEvent<MousePositionOffset>& e) {
            SendMousePosition_Impl(e.Position.X, e.Position.Y, 0);
        }
        void SendInput(const MouseMoveEvent<MousePositionAbsolute>& e) {
            SendMousePosition_Impl(
                (e.Position.X * 65536) / GetSystemMetrics(SM_CXSCREEN),
                (e.Position.Y * 65536) / GetSystemMetrics(SM_CYSCREEN),
                MOUSEEVENTF_ABSOLUTE);
        }

        void SendMousePosition_Impl(int x, int y, int modifier) {
            INPUT inp = { 0 };
            inp.type = INPUT_MOUSE;
            inp.mi.dwFlags = MOUSEEVENTF_MOVE | modifier;
            inp.mi.dx = x;
            inp.mi.dy = y;
            SendInput(1, &inp, sizeof(INPUT));
        }
    };
}