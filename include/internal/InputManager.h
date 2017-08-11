#pragma once
#include <functional>
#include "Input_Lite.h"

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#elif __APPLE__

#elif __linux__

#else
#error "Unknown Operating System!"
#endif


namespace SL {
    namespace Input_Lite {

        class InputManager : public IInputManager
        {
        public:
            virtual ~InputManager() {}

#ifdef WIN32
            virtual bool WindowProc(
                _In_ HWND   hwnd,
                _In_ UINT   uMsg,
                _In_ WPARAM wParam,
                _In_ LPARAM lParam
            );
#elif __APPLE__

#elif __linux__

#else
#error "Unknown Operating System!"
#endif

            std::function<void(char, bool)> onKeyc;
            std::function<void(wchar_t, bool)> onKeywc;
            std::function<void(SpecialKeyCodes, bool)> onKeysk;
            std::function<void(MouseButtons, bool)> onMouse;
        };

    }
}
