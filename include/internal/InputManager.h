#pragma once
#include <functional>
#include "Input_Lite.h"

namespace SL {
    namespace Input_Lite {

        class InputManager : public IInputManager
        {
        public:
            virtual ~InputManager() {}

            std::function<void(const PlatformIndependentKeyEvent&)> OnPlatformIndependentKeyEvent;
            std::function<void(const PlatformIndependentMouseEvent&)> OnPlatformIndependentMouseEvent;
            std::function<void(const MouseMoveEvent<MouseScroll>&)> OnMouseScroll;
            std::function<void(const MouseMoveEvent<MousePositionOffset>&)> OnMousePositionOffset;
            std::function<void(const MouseMoveEvent<MousePositionAbsolute>&)> OnMousePositionAbsolute;

        };

    }
}
