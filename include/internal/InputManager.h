#pragma once
#include <functional>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>

#include "Input_Lite.h"

namespace SL {
    namespace Input_Lite {

        class InputManager final : public IInputManager
        {
            std::thread Thread;
            std::mutex Mutex;
            std::condition_variable Conditional;
            std::vector<std::function<void()>> Events;
            bool Ready = false;
            bool KeepRunning = false;

            void Run();
        public:
            virtual ~InputManager();

            virtual bool PushEvent(const KeyEvent& e) override;
            virtual bool PushEvent(const MouseEvent& e)  override;

            virtual bool PushEvent(const MouseMoveEvent<MouseScroll>& pos)  override;
            virtual bool PushEvent(const MouseMoveEvent<MousePositionOffset>& pos)  override;
            virtual bool PushEvent(const MouseMoveEvent<MousePositionAbsolute>& pos)  override;

            std::function<void(const KeyEvent&)> OnKeyEvent;
            std::function<void(const MouseEvent&)> OnMouseEvent;
            std::function<void(const MouseMoveEvent<MouseScroll>&)> OnMouseScroll;
            std::function<void(const MouseMoveEvent<MousePositionOffset>&)> OnMousePositionOffset;
            std::function<void(const MouseMoveEvent<MousePositionAbsolute>&)> OnMousePositionAbsolute;
            void start() {
                Thread = std::thread(&SL::Input_Lite::InputManager::Run, this);
            }

        };

    }
}
