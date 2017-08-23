#include "Input_Lite.h"
#include "InputManager.h"
#include <assert.h>

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

#ifdef WIN32

        const int HID_TO_NATIVE[] = {
            255,255,255,255, 'A', 'B', 'C', 'D', 'E', 'F',
            'G', 'H', 'I', 'J', 'K','L','M','N','O','P',
            'Q','R','S','T','U','V','W','X','Y','Z',
            '1','2','3','4','5','6','7','8','9','0',
            VK_RETURN, VK_ESCAPE,  VK_BACK,  VK_TAB, VK_SPACE,VK_OEM_MINUS,VK_OEM_PLUS,VK_OEM_4, VK_OEM_6,VK_OEM_5,
            255,VK_OEM_1,VK_OEM_7,VK_OEM_3,VK_OEM_COMMA,VK_OEM_PERIOD, VK_OEM_2, VK_CAPITAL,VK_F1,VK_F2,
            VK_F3,VK_F4,VK_F5,VK_F6,VK_F7, VK_F8,VK_F9,VK_F10,VK_F11,VK_F12, 
            VK_SNAPSHOT,VK_SCROLL, VK_PAUSE, VK_INSERT,VK_HOME, VK_PRIOR, VK_DELETE, VK_END, VK_NEXT, VK_RIGHT,
            VK_LEFT, VK_DOWN, VK_UP,VK_NUMLOCK,VK_DIVIDE,VK_MULTIPLY,VK_SUBTRACT,VK_ADD,VK_RETURN, VK_NUMPAD1,
            VK_NUMPAD2, VK_NUMPAD3,VK_NUMPAD4,VK_NUMPAD5,VK_NUMPAD6,VK_NUMPAD7,VK_NUMPAD8,VK_NUMPAD9, VK_NUMPAD0,VK_DECIMAL,
            255,255,255,255,VK_F13,VK_F14,VK_F15,VK_F16,VK_F17,VK_F18,
            VK_F19,VK_F20, VK_F21,VK_F22,VK_F23,VK_F24,255,255,255,255,
            255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            17, 16, 18, 255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255
        };


        const int NATIVE_TO_HID[] = {
            INVALID,INVALID,INVALID,INVALID,INVALID,INVALID,INVALID,INVALID, KEY_Delete, KEY_Tab,
            INVALID,INVALID,INVALID, KEY_Enter,INVALID,INVALID, INVALID,KEY_LeftControl,KEY_LeftAlt, KEY_Pause,
            KEY_CapsLock,INVALID,INVALID,INVALID,INVALID,INVALID,INVALID, KEY_Escape,INVALID,INVALID,
            INVALID,255,44, 75, 78, 77, 74, 80, 82, 79,
            81,255,255,255, 70, 73, 76,255, 39, 30,
            31, 32, 33, 34, 35, 36, 37, 38,INVALID,INVALID,
            INVALID,INVALID,INVALID,INVALID, INVALID,  4,  5,  6,  7,  8,
            9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
            19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
            29,255,255, 255,255,255,98, 89, 90, 91,
            92, 93, 94, 95, 96, 97, 85, 87,INVALID, 86,
            99, 84, 58, 59, 60, 61, 62, 63, 64, 65,
            66, 67, 68, 69,104,105,106,107,
            108,109,110,111,112,113,114,115,255,255,255,255,255,255,255,255,
            83, 71,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255, 51, 46, 54, 45, 55, 56,
            53, 255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255, 47, 49, 48, 52,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255
        };

#elif __APPLE__

#elif __linux__

#else
#error "Unknown Operating System!"
#endif


        int ConvertToNative(KeyCodes key) {
            return static_cast<int>(HID_TO_NATIVE[key]);
        }
        KeyCodes ConvertToKeyCode(int key) {
            if (key <= 255) {
                return static_cast<KeyCodes>(NATIVE_TO_HID[key]);
            }
            return KeyCodes::INVALID;
        }
        class InputConfiguration : public IInputConfiguration
        {
            std::shared_ptr<InputManager> Impl;
        public:

            InputConfiguration(const  std::shared_ptr<InputManager>& impl) : Impl(impl) {}
            virtual ~InputConfiguration() {}


            virtual std::shared_ptr<IInputConfiguration> onEvent(const std::function<void(const KeyEvent&)>& cb)  override {
                assert(!Impl->OnKeyEvent);
                Impl->OnKeyEvent = cb;
                return std::make_shared<InputConfiguration>(Impl);
            }
            virtual std::shared_ptr<IInputConfiguration> onEvent(const std::function<void(const MouseButtonEvent&)>& cb)  override {
                assert(!Impl->OnMouseButtonEvent);
                Impl->OnMouseButtonEvent = cb;
                return std::make_shared<InputConfiguration>(Impl);
            }
            virtual std::shared_ptr<IInputConfiguration> onEvent(const std::function<void(const MouseScrollEvent&)>& cb) override {
                assert(!Impl->OnMouseScroll);
                Impl->OnMouseScroll = cb;
                return std::make_shared<InputConfiguration>(Impl);
            }
            virtual std::shared_ptr<IInputConfiguration> onEvent(const std::function<void(const MousePositionOffsetEvent&)>& cb)  override {
                assert(!Impl->OnMousePositionOffset);
                Impl->OnMousePositionOffset = cb;
                return std::make_shared<InputConfiguration>(Impl);
            }
            virtual std::shared_ptr<IInputConfiguration> onEvent(const std::function<void(const MousePositionAbsoluteEvent&)>& cb)  override {
                assert(!Impl->OnMousePositionAbsolute);
                Impl->OnMousePositionAbsolute = cb;
                return std::make_shared<InputConfiguration>(Impl);
            }
            virtual std::shared_ptr<IInputManager> Build() override {
                return Impl;
            }
        };
        std::shared_ptr<IInputConfiguration> CreateInputConfiguration() {
            return std::make_shared<InputConfiguration>(std::make_shared<InputManager>());
        }
    };
}