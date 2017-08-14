#include "Input_Lite.h"
#include "InputManager.h"

#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace SL {
    namespace Input_Lite {

        void SendInput(const KeyEvent& e) {
            INPUT k = { 0 };
            k.type = INPUT_KEYBOARD;
            k.ki.dwFlags = e.Pressed ? 0 : KEYEVENTF_KEYUP;
            k.ki.wVk = static_cast<WORD>(ConvertToNative(e.Key));
            SendInput(1, &k, sizeof(INPUT));
        }
        void SendInput(const MouseButtonEvent& e) {
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

        void SendInput(const MouseScrollEvent& e) {
            INPUT inp = { 0 };
            inp.type = INPUT_MOUSE;
            inp.mi.dwFlags = MOUSEEVENTF_WHEEL;
            inp.mi.mouseData = e.Offset * 120;
            SendInput(1, &inp, sizeof(INPUT));
        }


        void SendMousePosition_Impl(int x, int y, int modifier) {
            INPUT inp = { 0 };
            inp.type = INPUT_MOUSE;
            inp.mi.dwFlags = MOUSEEVENTF_MOVE | modifier;
            inp.mi.dx = x;
            inp.mi.dy = y;
            SendInput(1, &inp, sizeof(INPUT));
        }
        void SendInput(const MousePositionOffsetEvent& e) {
            SendMousePosition_Impl(e.X, e.Y, 0);
        }
        void SendInput(const MousePositionAbsoluteEvent& e) {
            SendMousePosition_Impl(
                (e.X * 65536) / GetSystemMetrics(SM_CXSCREEN),
                (e.Y * 65536) / GetSystemMetrics(SM_CYSCREEN),
                MOUSEEVENTF_ABSOLUTE);
        }
    }
}