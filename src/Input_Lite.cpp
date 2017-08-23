#include "InputManager.h"
#include "Input_Lite.h"
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

    int ConvertToNative(KeyCodes key)
    {
        switch (key) {
        case SL::Input_Lite::KEY_A:
        case SL::Input_Lite::KEY_B:
        case SL::Input_Lite::KEY_C:
        case SL::Input_Lite::KEY_D:
        case SL::Input_Lite::KEY_E:
        case SL::Input_Lite::KEY_F:
        case SL::Input_Lite::KEY_G:
        case SL::Input_Lite::KEY_H:
        case SL::Input_Lite::KEY_I:
        case SL::Input_Lite::KEY_J:
        case SL::Input_Lite::KEY_K:
        case SL::Input_Lite::KEY_L:
        case SL::Input_Lite::KEY_M:
        case SL::Input_Lite::KEY_N:
        case SL::Input_Lite::KEY_O:
        case SL::Input_Lite::KEY_P:
        case SL::Input_Lite::KEY_Q:
        case SL::Input_Lite::KEY_R:
        case SL::Input_Lite::KEY_S:
        case SL::Input_Lite::KEY_T:
        case SL::Input_Lite::KEY_U:
        case SL::Input_Lite::KEY_V:
        case SL::Input_Lite::KEY_W:
        case SL::Input_Lite::KEY_X:
        case SL::Input_Lite::KEY_Y:
        case SL::Input_Lite::KEY_Z:
            return static_cast<int>('A') + (key - SL::Input_Lite::KEY_A);
        case SL::Input_Lite::KEY_1:
        case SL::Input_Lite::KEY_2:
        case SL::Input_Lite::KEY_3:
        case SL::Input_Lite::KEY_4:
        case SL::Input_Lite::KEY_5:
        case SL::Input_Lite::KEY_6:
        case SL::Input_Lite::KEY_7:
        case SL::Input_Lite::KEY_8:
        case SL::Input_Lite::KEY_9:
            return static_cast<int>('1') + (key - SL::Input_Lite::KEY_1);
        case SL::Input_Lite::KEY_0:
            return static_cast<int>('0');
        case SL::Input_Lite::KEY_Enter:
            return VK_RETURN;
        case SL::Input_Lite::KEY_Escape:
            return VK_ESCAPE;
        case SL::Input_Lite::KEY_Backspace:
            return VK_BACK;
        case SL::Input_Lite::KEY_Tab:
            return VK_TAB;
        case SL::Input_Lite::KEY_Space:
            return VK_SPACE;
        case SL::Input_Lite::KEY_Minus:
            return VK_OEM_MINUS;
        case SL::Input_Lite::KEY_Equals:
            return VK_OEM_PLUS; // this is correct and not a mistype
        case SL::Input_Lite::KEY_LeftBracket:
            return VK_OEM_4;
        case SL::Input_Lite::KEY_RightBracket:
            return VK_OEM_6;
        case SL::Input_Lite::KEY_Backslash:
            return VK_OEM_5;
        case SL::Input_Lite::KEY_Semicolon:
            return VK_OEM_1;
        case SL::Input_Lite::KEY_Quote:
            return VK_OEM_7;
        case SL::Input_Lite::KEY_Grave:
            return VK_OEM_3;
        case SL::Input_Lite::KEY_Comma:
            return VK_OEM_COMMA;
        case SL::Input_Lite::KEY_Period:
            return VK_OEM_PERIOD;
        case SL::Input_Lite::KEY_Slash:
            return VK_OEM_2;
        case SL::Input_Lite::KEY_CapsLock:
            return VK_CAPITAL;
        case SL::Input_Lite::KEY_F1:
        case SL::Input_Lite::KEY_F2:
        case SL::Input_Lite::KEY_F3:
        case SL::Input_Lite::KEY_F4:
        case SL::Input_Lite::KEY_F5:
        case SL::Input_Lite::KEY_F6:
        case SL::Input_Lite::KEY_F7:
        case SL::Input_Lite::KEY_F8:
        case SL::Input_Lite::KEY_F9:
        case SL::Input_Lite::KEY_F10:
        case SL::Input_Lite::KEY_F11:
        case SL::Input_Lite::KEY_F12:
            return VK_F1 + (key - SL::Input_Lite::KEY_F1);
        case SL::Input_Lite::KEY_F13:
        case SL::Input_Lite::KEY_F14:
        case SL::Input_Lite::KEY_F15:
        case SL::Input_Lite::KEY_F16:
        case SL::Input_Lite::KEY_F17:
        case SL::Input_Lite::KEY_F18:
        case SL::Input_Lite::KEY_F19:
        case SL::Input_Lite::KEY_F20:
        case SL::Input_Lite::KEY_F21:
        case SL::Input_Lite::KEY_F22:
        case SL::Input_Lite::KEY_F23:
        case SL::Input_Lite::KEY_F24:
            return VK_F13 + (key - SL::Input_Lite::KEY_F13);
        case SL::Input_Lite::KEY_PrintScreen:
            return VK_SNAPSHOT;
        case SL::Input_Lite::KEY_ScrollLock:
            return VK_SCROLL;
        case SL::Input_Lite::KEY_Pause:
            return VK_PAUSE;
        case SL::Input_Lite::KEY_Insert:
            return VK_INSERT;
        case SL::Input_Lite::KEY_Home:
            return VK_HOME;
        case SL::Input_Lite::KEY_PageUp:
            return VK_PRIOR;
        case SL::Input_Lite::KEY_Delete:
            return VK_DELETE;
        case SL::Input_Lite::KEY_End:
            return VK_END;
        case SL::Input_Lite::KEY_PageDown:
            return VK_NEXT;
        case SL::Input_Lite::KEY_Right:
            return VK_RIGHT;
        case SL::Input_Lite::KEY_Left:
            return VK_LEFT;
        case SL::Input_Lite::KEY_Down:
            return VK_DOWN;
        case SL::Input_Lite::KEY_Up:
            return VK_UP;
        case SL::Input_Lite::KP_NumLock:
            return VK_NUMLOCK;
        case SL::Input_Lite::KP_Divide:
            return VK_DIVIDE;
        case SL::Input_Lite::KP_Multiply:
            return VK_MULTIPLY;
        case SL::Input_Lite::KP_Subtract:
            return VK_SUBTRACT;
        case SL::Input_Lite::KP_Add:
            return VK_ADD;
        case SL::Input_Lite::KP_Enter:
            return VK_RETURN;
        case SL::Input_Lite::KP_1:
        case SL::Input_Lite::KP_2:
        case SL::Input_Lite::KP_3:
        case SL::Input_Lite::KP_4:
        case SL::Input_Lite::KP_5:
        case SL::Input_Lite::KP_6:
        case SL::Input_Lite::KP_7:
        case SL::Input_Lite::KP_8:
        case SL::Input_Lite::KP_9:
            return VK_NUMPAD1 + (key - SL::Input_Lite::KP_1);
        case SL::Input_Lite::KP_0:
            return VK_NUMPAD0;
        case SL::Input_Lite::KP_Point:
            return VK_DECIMAL;
        case SL::Input_Lite::KEY_Help:
            return VK_HELP;
        case SL::Input_Lite::KEY_Menu:
            return VK_MENU;
        case SL::Input_Lite::KEY_LeftControl:
            return VK_CONTROL;
        case SL::Input_Lite::KEY_LeftShift:
            return VK_SHIFT;
        case SL::Input_Lite::KEY_LeftAlt:
            return VK_MENU;
        case SL::Input_Lite::KEY_LeftMeta:
            return VK_LWIN;
        case SL::Input_Lite::KEY_RightControl:
            return VK_CONTROL;
        case SL::Input_Lite::KEY_RightShift:
            return VK_SHIFT;
        case SL::Input_Lite::KEY_RightAlt:
            return VK_MENU;
        case SL::Input_Lite::KEY_RightMeta:
            return VK_RWIN;
        default:
            return 255;
        }
    }
    KeyCodes ConvertToKeyCode(int key)
    {

        switch (key) {
        case '0':
            return KeyCodes::KEY_0;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return static_cast<KeyCodes>(KeyCodes::KEY_1 + (key - static_cast<int>('1')));
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            return static_cast<KeyCodes>(KeyCodes::KEY_A + (key - static_cast<int>('A')));
        case VK_RETURN:
            return KeyCodes::KEY_Enter;
        case VK_ESCAPE:
            return KeyCodes::KEY_Escape;
        case VK_BACK:
            return KeyCodes::KEY_Backspace;
        case VK_TAB:
            return KeyCodes::KEY_Tab;
        case VK_SPACE:
            return KeyCodes::KEY_Space;
        case VK_OEM_MINUS:
            return KeyCodes::KEY_Minus;
        case VK_OEM_PLUS:
            return KeyCodes::KEY_Equals; // this is correct and not a mistype
        case VK_OEM_4:
            return KeyCodes::KEY_LeftBracket;
        case VK_OEM_6:
            return KeyCodes::KEY_RightBracket;
        case VK_OEM_5:
            return KeyCodes::KEY_Backslash;
        case VK_OEM_1:
            return KeyCodes::KEY_Semicolon;
        case VK_OEM_7:
            return KeyCodes::KEY_Quote;
        case VK_OEM_3:
            return KeyCodes::KEY_Grave;
        case VK_OEM_COMMA:
            return KeyCodes::KEY_Comma;
        case VK_OEM_PERIOD:
            return KeyCodes::KEY_Period;
        case VK_OEM_2:
            return KeyCodes::KEY_Slash;
        case VK_CAPITAL:
            return KeyCodes::KEY_CapsLock;
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
            return static_cast<KeyCodes>(KeyCodes::KEY_F1 + (key - VK_F1));
        case VK_F13:
        case VK_F14:
        case VK_F15:
        case VK_F16:
        case VK_F17:
        case VK_F18:
        case VK_F19:
        case VK_F20:
        case VK_F21:
        case VK_F22:
        case VK_F23:
        case VK_F24:
            return static_cast<KeyCodes>(KeyCodes::KEY_F13 + (key - VK_F13));
        case VK_SNAPSHOT:
            return KeyCodes::KEY_PrintScreen;
        case VK_SCROLL:
            return KeyCodes::KEY_ScrollLock;
        case VK_PAUSE:
            return KeyCodes::KEY_Pause;
        case VK_INSERT:
            return KeyCodes::KEY_Insert;
        case VK_HOME:
            return KeyCodes::KEY_Home;
        case VK_PRIOR:
            return KeyCodes::KEY_PageUp;
        case VK_DELETE:
            return KeyCodes::KEY_Delete;
        case VK_END:
            return KeyCodes::KEY_End;
        case VK_NEXT:
            return KeyCodes::KEY_PageDown;
        case VK_RIGHT:
            return KeyCodes::KEY_Right;
        case VK_LEFT:
            return KeyCodes::KEY_Left;
        case VK_DOWN:
            return KeyCodes::KEY_Down;
        case VK_UP:
            return KeyCodes::KEY_Up;
        case VK_NUMLOCK:
            return KeyCodes::KP_NumLock;
        case VK_DIVIDE:
            return KeyCodes::KP_Divide;
        case VK_MULTIPLY:
            return KeyCodes::KP_Multiply;
        case VK_SUBTRACT:
            return KeyCodes::KP_Subtract;
        case VK_ADD:
            return KeyCodes::KP_Add;
        case VK_NUMPAD1:
        case VK_NUMPAD2:
        case VK_NUMPAD3:
        case VK_NUMPAD4:
        case VK_NUMPAD5:
        case VK_NUMPAD6:
        case VK_NUMPAD7:
        case VK_NUMPAD8:
        case VK_NUMPAD9:
            return static_cast<KeyCodes>(KeyCodes::KP_1 + (key - VK_NUMPAD1));
        case VK_NUMPAD0:
            return KeyCodes::KP_0;
        case VK_DECIMAL:
            return KeyCodes::KP_Point;
        case VK_HELP:
            return KeyCodes::KEY_Help;
        case VK_MENU:
        case VK_LMENU:
        case VK_RMENU:
            return KeyCodes::KEY_Menu;
        case VK_CONTROL:
        case VK_LCONTROL:
        case VK_RCONTROL:
            return KeyCodes::KEY_LeftControl;
        case VK_SHIFT:
        case VK_LSHIFT:
        case VK_RSHIFT:
            return KeyCodes::KEY_LeftShift;
        case VK_LWIN:
            return KeyCodes::KEY_LeftMeta;
        case VK_RWIN:
            return KeyCodes::KEY_RightMeta;
        default:
            return SL::Input_Lite::KeyCodes::INVALID;
        }
    }

#elif __APPLE__
    int ConvertToNative(KeyCodes key) {}
    KeyCodes ConvertToKeyCode(int key) {}
#elif __linux__
    int ConvertToNative(KeyCodes key) {}
    KeyCodes ConvertToKeyCode(int key) {}
#else
#error "Unknown Operating System!"
#endif
    class InputConfiguration : public IInputConfiguration {
        std::shared_ptr<InputManager> Impl;

      public:
        InputConfiguration(const std::shared_ptr<InputManager> &impl) : Impl(impl) {}
        virtual ~InputConfiguration() {}

        virtual std::shared_ptr<IInputConfiguration> onEvent(const std::function<void(const KeyEvent &)> &cb) override
        {
            assert(!Impl->OnKeyEvent);
            Impl->OnKeyEvent = cb;
            return std::make_shared<InputConfiguration>(Impl);
        }
        virtual std::shared_ptr<IInputConfiguration> onEvent(const std::function<void(const MouseButtonEvent &)> &cb) override
        {
            assert(!Impl->OnMouseButtonEvent);
            Impl->OnMouseButtonEvent = cb;
            return std::make_shared<InputConfiguration>(Impl);
        }
        virtual std::shared_ptr<IInputConfiguration> onEvent(const std::function<void(const MouseScrollEvent &)> &cb) override
        {
            assert(!Impl->OnMouseScroll);
            Impl->OnMouseScroll = cb;
            return std::make_shared<InputConfiguration>(Impl);
        }
        virtual std::shared_ptr<IInputConfiguration> onEvent(const std::function<void(const MousePositionOffsetEvent &)> &cb) override
        {
            assert(!Impl->OnMousePositionOffset);
            Impl->OnMousePositionOffset = cb;
            return std::make_shared<InputConfiguration>(Impl);
        }

        virtual std::shared_ptr<IInputConfiguration> onEvent(const std::function<void(const MousePositionAbsoluteEvent &)> &cb) override
        {
            assert(!Impl->OnMousePositionAbsolute);
            Impl->OnMousePositionAbsolute = cb;
            return std::make_shared<InputConfiguration>(Impl);
        }
        virtual std::shared_ptr<IInputManager> Build() override { return Impl; }
    };
    std::shared_ptr<IInputConfiguration> CreateInputConfiguration() { return std::make_shared<InputConfiguration>(std::make_shared<InputManager>()); }
}; // namespace Input_Lite
} // namespace SL