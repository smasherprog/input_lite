#include "Input_Lite.h"
#include "InputManager.h"

#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef DELETE 

namespace SL {
    namespace Input_Lite {

        void SendInput(const KeyEvent& e) {
            INPUT k = { 0 };
            k.type = INPUT_KEYBOARD;
            k.ki.dwFlags = e.Pressed ? 0 : KEYEVENTF_KEYUP;
            k.ki.wVk = ConvertToNative(e.Key);
            SendInput(1, &k, sizeof(INPUT));
        }
        void SendInput(const MouseEvent& e) {
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