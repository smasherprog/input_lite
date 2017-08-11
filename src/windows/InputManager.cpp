#include "Input_Lite.h"
#include "InputManager.h"

#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef DELETE 

namespace SL {
    namespace Input_Lite {

        bool ProcessKeyImpl(size_t key, bool pressed) {
            Input_Lite::SpecialKeyCodes k;
            switch (key)
            {
            case VK_BACK:
                k = Input_Lite::SpecialKeyCodes::BACKSPACE;
                break;
            case VK_TAB:
                k = Input_Lite::SpecialKeyCodes::TAB;
                break;
            case VK_RETURN:
                k = Input_Lite::SpecialKeyCodes::ENTER;
                break;
            case VK_SHIFT:
                k = Input_Lite::SpecialKeyCodes::SHIFTLEFT;
                break;
            case VK_CONTROL:
                k = Input_Lite::SpecialKeyCodes::CONTROLLEFT;
                break;
            case VK_CAPITAL:
                k = Input_Lite::SpecialKeyCodes::CAPSLOCK;
                break;
            case VK_ESCAPE:
                k = Input_Lite::SpecialKeyCodes::ESCAPE;
                break;
            case VK_SPACE:
                k = Input_Lite::SpecialKeyCodes::SPACE;
                break;
            case VK_PRIOR:
                k = Input_Lite::SpecialKeyCodes::PAGEUP;
                break;
            case VK_NEXT:
                k = Input_Lite::SpecialKeyCodes::PAGEDOWN;
                break;

            case VK_END:
                k = Input_Lite::SpecialKeyCodes::END;
                break;
            case VK_HOME:
                k = Input_Lite::SpecialKeyCodes::HOME;
                break;
            case VK_LEFT:
                k = Input_Lite::SpecialKeyCodes::ARROWLEFT;
                break;
            case VK_UP:
                k = Input_Lite::SpecialKeyCodes::ARROWUP;
                break;

            case VK_RIGHT:
                k = Input_Lite::SpecialKeyCodes::ARROWRIGHT;
                break;
            case VK_DOWN:
                k = Input_Lite::SpecialKeyCodes::ARROWDOWN;
                break;
            case VK_SNAPSHOT:
                k = Input_Lite::SpecialKeyCodes::PRINTSCREEN;
                break;
            case VK_INSERT:
                k = Input_Lite::SpecialKeyCodes::INSERT;
                break;
            case VK_DELETE:
                k = Input_Lite::SpecialKeyCodes::DELETE;
                break;

            case VK_SCROLL:
                k = Input_Lite::SpecialKeyCodes::SCROLLLOCK;
                break;
            case VK_PAUSE:
                k = Input_Lite::SpecialKeyCodes::PAUSE;
                break;
            case VK_LWIN:
                k = Input_Lite::SpecialKeyCodes::OSLEFT;
                break;
            case VK_F1:
            case VK_F2:
            case VK_F3:
            case VK_F4:
            case VK_F5:
            case VK_F6:
            case VK_F7:
            case VK_F8:
            case VK_F9:
            case VK_F10:
            case VK_F11:
            case VK_F12:
            case VK_F13:
            case VK_F14:
            case VK_F15:
            case VK_F16:
            case VK_F17:
            case VK_F18:
                k = static_cast<Input_Lite::SpecialKeyCodes>(Input_Lite::SpecialKeyCodes::F1 + (key - VK_F1));
                break;

            case VK_NUMLOCK:
                k = Input_Lite::SpecialKeyCodes::NUMLOCK;
                break;
            case VK_NUMPAD1:
                k = Input_Lite::SpecialKeyCodes::NUMPAD1;
                break;
            case VK_NUMPAD2:
                k = Input_Lite::SpecialKeyCodes::NUMPAD2;
                break;
            case VK_NUMPAD3:
                k = Input_Lite::SpecialKeyCodes::NUMPAD3;
                break;
            case VK_NUMPAD4:
                k = Input_Lite::SpecialKeyCodes::NUMPAD4;
                break;
            case VK_NUMPAD5:
                k = Input_Lite::SpecialKeyCodes::NUMPAD5;
                break;
            case VK_NUMPAD6:
                k = Input_Lite::SpecialKeyCodes::NUMPAD6;
                break;
            case VK_NUMPAD7:
                k = Input_Lite::SpecialKeyCodes::NUMPAD7;
                break;
            case VK_NUMPAD8:
                k = Input_Lite::SpecialKeyCodes::NUMPAD8;
                break;
            case VK_NUMPAD9:
                k = Input_Lite::SpecialKeyCodes::NUMPAD9;
                break;

            case VK_ADD:
                k = Input_Lite::SpecialKeyCodes::NUMPADADD;
                break;
            case VK_DECIMAL:
                k = Input_Lite::SpecialKeyCodes::NUMPADDECIMAL;
                break;
            case VK_DIVIDE:
                k = Input_Lite::SpecialKeyCodes::NUMPADDIVIDE;
                break;
            case VK_MULTIPLY:
                k = Input_Lite::SpecialKeyCodes::NUMPADMULTIPLY;
                break;
            case VK_SUBTRACT:
                k = Input_Lite::SpecialKeyCodes::NUMPADSUBTRACT;
                break;
            default:
                return false;
            }
            return true;
        }
  
    };
}