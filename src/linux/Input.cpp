#include "Input_Lite.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/extensions/XInput.h>
#include <X11/extensions/XTest.h>
#include <X11/keysym.h>

#include <iostream>
namespace SL
{
namespace Input_Lite
{
    void SendInput(const KeyEvent& e)
    {
        auto display = XOpenDisplay(NULL);
        XTestFakeKeyEvent(display, ConvertToNative(e.Key), e.Pressed ? True : False, CurrentTime);
        XCloseDisplay(display);
    }
    void SendInput(const MouseButtonEvent& e)
    {
        auto display = XOpenDisplay(NULL);
        switch(e.Button) {
        case MouseButtons::LEFT:
            XTestFakeButtonEvent(display, Button1, e.Pressed ? True : False, CurrentTime);
            break;
        case MouseButtons::MIDDLE:
            XTestFakeButtonEvent(display, Button2, e.Pressed ? True : False, CurrentTime);
            break;
        case MouseButtons::RIGHT:
            XTestFakeButtonEvent(display, Button3, e.Pressed ? True : False, CurrentTime);
            break;
        default:
            break;
        }
        XCloseDisplay(display);
    }
    void SendInput(const MouseScrollEvent& e)
    {
        auto display = XOpenDisplay(NULL);
        if(e.Offset < 0) {
            for(auto i = 0; i < abs(e.Offset) && i < 5; i++) { /// cap at 5
                XTestFakeButtonEvent(display, Button5, True, CurrentTime);
                XTestFakeButtonEvent(display, Button5, False, CurrentTime);
            }
        } else if(e.Offset > 0) {
            for(auto i = 0; i < e.Offset && i < 5; i++) { /// cap at 5
                XTestFakeButtonEvent(display, Button4, True, CurrentTime);
                XTestFakeButtonEvent(display, Button4, False, CurrentTime);
            }
        }
        XCloseDisplay(display);
    }
    void SendInput(const MousePositionOffsetEvent& e)
    {
        auto display = XOpenDisplay(NULL);
        XTestFakeRelativeMotionEvent(display, -1, e.X, e.Y);
        XCloseDisplay(display);
    }
    void SendInput(const MousePositionAbsoluteEvent& e)
    {
        auto display = XOpenDisplay(NULL);
        XTestFakeMotionEvent(display, -1, e.X, e.Y, CurrentTime);
        XCloseDisplay(display);
    }
    int ConvertToNative(KeyCodes key)
    { 
        switch(key) {

        case KeyCodes::KEY_A:
        case KeyCodes::KEY_B:
        case KeyCodes::KEY_C:
        case KeyCodes::KEY_D:
        case KeyCodes::KEY_E:
        case KeyCodes::KEY_F:
        case KeyCodes::KEY_G:
        case KeyCodes::KEY_H:
        case KeyCodes::KEY_I:
        case KeyCodes::KEY_J:
        case KeyCodes::KEY_K:
        case KeyCodes::KEY_L:
        case KeyCodes::KEY_M:
        case KeyCodes::KEY_N:
        case KeyCodes::KEY_O:
        case KeyCodes::KEY_P:
        case KeyCodes::KEY_Q:
        case KeyCodes::KEY_R:
        case KeyCodes::KEY_S:
        case KeyCodes::KEY_T:
        case KeyCodes::KEY_U:
        case KeyCodes::KEY_V:
        case KeyCodes::KEY_W:
        case KeyCodes::KEY_X:
        case KeyCodes::KEY_Y:
        case KeyCodes::KEY_Z:
            return static_cast<int>('A') + (key - KeyCodes::KEY_A);
        case KeyCodes::KEY_1:
        case KeyCodes::KEY_2:
        case KeyCodes::KEY_3:
        case KeyCodes::KEY_4:
        case KeyCodes::KEY_5:
        case KeyCodes::KEY_6:
        case KeyCodes::KEY_7:
        case KeyCodes::KEY_8:
        case KeyCodes::KEY_9:
            return static_cast<int>('1') + (key - KeyCodes::KEY_1);
        case KeyCodes::KEY_0:
            return static_cast<int>('0');
        case KeyCodes::KEY_Enter:
            return XK_Return;
        case KeyCodes::KEY_Escape:
            return XK_Escape;
        case KeyCodes::KEY_Backspace:
            return XK_BackSpace;
        case KeyCodes::KEY_Tab:
            return XK_Tab;
        case KeyCodes::KEY_Space:
            return XK_KP_Space;
        case KeyCodes::KEY_Minus:
            return XK_minus;
        case KeyCodes::KEY_Equals:
            return XK_equal; // this is correct and not a mistype
        case KeyCodes::KEY_LeftBracket:
            return XK_bracketleft;
        case KeyCodes::KEY_RightBracket:
            return XK_bracketright;
        case KeyCodes::KEY_Backslash:
            return XK_backslash;
        case KeyCodes::KEY_Semicolon:
            return XK_semicolon;
        case KeyCodes::KEY_Quote:
            return XK_quotedbl;
        case KeyCodes::KEY_Grave:
            return XK_grave;
        case KeyCodes::KEY_Comma:
            return XK_comma;
        case KeyCodes::KEY_Period:
            return XK_period;
        case KeyCodes::KEY_Slash:
            return XK_slash;
        case KeyCodes::KEY_CapsLock:
            return XK_Caps_Lock;
        case KeyCodes::KEY_F1:
        case KeyCodes::KEY_F2:
        case KeyCodes::KEY_F3:
        case KeyCodes::KEY_F4:
        case KeyCodes::KEY_F5:
        case KeyCodes::KEY_F6:
        case KeyCodes::KEY_F7:
        case KeyCodes::KEY_F8:
        case KeyCodes::KEY_F9:
        case KeyCodes::KEY_F10:
        case KeyCodes::KEY_F11:
        case KeyCodes::KEY_F12:
            return XK_F1 + (key - KeyCodes::KEY_F1);
        case KeyCodes::KEY_F13:
        case KeyCodes::KEY_F14:
        case KeyCodes::KEY_F15:
        case KeyCodes::KEY_F16:
        case KeyCodes::KEY_F17:
        case KeyCodes::KEY_F18:
        case KeyCodes::KEY_F19:
        case KeyCodes::KEY_F20:
        case KeyCodes::KEY_F21:
        case KeyCodes::KEY_F22:
        case KeyCodes::KEY_F23:
        case KeyCodes::KEY_F24:
            return XK_F13 + (key - KeyCodes::KEY_F13);
        case KeyCodes::KEY_PrintScreen:
            return XK_Print;
        case KeyCodes::KEY_ScrollLock:
            return XK_Scroll_Lock;
        case KeyCodes::KEY_Pause:
            return XK_Pause;
        case KeyCodes::KEY_Insert:
            return XK_Insert;
        case KeyCodes::KEY_Home:
            return XK_Home;
        case KeyCodes::KEY_PageUp:
            return XK_Page_Up;
        case KeyCodes::KEY_Delete:
            return XK_Delete;
        case KeyCodes::KEY_End:
            return XK_End;
        case KeyCodes::KEY_PageDown:
            return XK_Page_Down;
        case KeyCodes::KEY_Right:
            return XK_Right;
        case KeyCodes::KEY_Left:
            return XK_Left;
        case KeyCodes::KEY_Down:
            return XK_Down;
        case KeyCodes::KEY_Up:
            return XK_Up;
        case KeyCodes::KP_NumLock:
            return XK_Num_Lock;
        case KeyCodes::KP_Divide:
            return XK_KP_Divide;
        case KeyCodes::KP_Multiply:
            return XK_KP_Multiply;
        case KeyCodes::KP_Subtract:
            return XK_KP_Subtract;
        case KeyCodes::KP_Add:
            return XK_KP_Add;
        case KeyCodes::KP_Enter:
            return XK_KP_Enter;
        case KeyCodes::KP_1:
        case KeyCodes::KP_2:
        case KeyCodes::KP_3:
        case KeyCodes::KP_4:
        case KeyCodes::KP_5:
        case KeyCodes::KP_6:
        case KeyCodes::KP_7:
        case KeyCodes::KP_8:
        case KeyCodes::KP_9:
            return XK_KP_1 + (key - KeyCodes::KP_1);
        case KeyCodes::KP_0:
            return XK_KP_0;
        case KeyCodes::KP_Point:
            return XK_KP_Decimal;
        case KeyCodes::KEY_Help:
            return XK_Help;
        case KeyCodes::KEY_Menu:
            return XK_Menu;
        case KeyCodes::KEY_LeftControl:
            return XK_Control_L;
        case KeyCodes::KEY_LeftShift:
            return XK_Shift_L;
        case KeyCodes::KEY_LeftAlt:
            return XK_Alt_L;
        case KeyCodes::KEY_LeftMeta:
            return XK_Meta_L;

        case KeyCodes::KEY_RightControl:
            return XK_Control_R;
        case KeyCodes::KEY_RightShift:
            return XK_Shift_R;
        case KeyCodes::KEY_RightAlt:
            return XK_Alt_R;
        case KeyCodes::KEY_RightMeta:
            return XK_Meta_R;
        default:
            return 255;
        }
    }

    KeyCodes ConvertToKeyCode(int key)
    {

        switch(key) {
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
        case XK_Return:
            return KeyCodes::KEY_Enter;
        case XK_Escape:
            return KeyCodes::KEY_Escape;
        case XK_BackSpace:
            return KeyCodes::KEY_Backspace;
        case XK_Tab:
            return KeyCodes::KEY_Tab;
        case XK_KP_Space:
            return KeyCodes::KEY_Space;
        case XK_minus:
            return KeyCodes::KEY_Minus;
        case XK_equal:
            return KeyCodes::KEY_Equals; // this is correct and not a mistype
        case XK_bracketleft:
            return KeyCodes::KEY_LeftBracket;
        case XK_bracketright:
            return KeyCodes::KEY_RightBracket;
        case XK_backslash:
            return KeyCodes::KEY_Backslash;
        case XK_semicolon:
            return KeyCodes::KEY_Semicolon;
        case XK_quotedbl:
            return KeyCodes::KEY_Quote;
        case XK_grave:
            return KeyCodes::KEY_Grave;
        case XK_comma:
            return KeyCodes::KEY_Comma;
        case XK_period:
            return KeyCodes::KEY_Period;
        case XK_slash:
            return KeyCodes::KEY_Slash;
        case XK_Caps_Lock:
            return KeyCodes::KEY_CapsLock;
        case XK_F1:
        case XK_F2:
        case XK_F3:
        case XK_F4:
        case XK_F5:
        case XK_F6:
        case XK_F7:
        case XK_F8:
        case XK_F9:
        case XK_F10:
        case XK_F11:
        case XK_F12:
            return static_cast<KeyCodes>(KeyCodes::KEY_F1 + (key - XK_F1));
        case XK_F13:
        case XK_F14:
        case XK_F15:
        case XK_F16:
        case XK_F17:
        case XK_F18:
        case XK_F19:
        case XK_F20:
        case XK_F21:
        case XK_F22:
        case XK_F23:
        case XK_F24:
            return static_cast<KeyCodes>(KeyCodes::KEY_F13 + (key - XK_F13));
        case XK_Print:
            return KeyCodes::KEY_PrintScreen;
        case XK_Scroll_Lock:
            return KeyCodes::KEY_ScrollLock;
        case XK_Pause:
            return KeyCodes::KEY_Pause;
        case XK_Insert:
            return KeyCodes::KEY_Insert;
        case XK_Home:
            return KeyCodes::KEY_Home;
        case XK_Page_Up:
            return KeyCodes::KEY_PageUp;
        case XK_Delete:
            return KeyCodes::KEY_Delete;
        case XK_End:
            return KeyCodes::KEY_End;
        case XK_Page_Down:
            return KeyCodes::KEY_PageDown;
        case XK_Right:
            return KeyCodes::KEY_Right;
        case XK_Left:
            return KeyCodes::KEY_Left;
        case XK_Down:
            return KeyCodes::KEY_Down;
        case XK_Up:
            return KeyCodes::KEY_Up;
        case XK_Num_Lock:
            return KeyCodes::KP_NumLock;
        case XK_KP_Divide:
            return KeyCodes::KP_Divide;
        case XK_KP_Multiply:
            return KeyCodes::KP_Multiply;
        case XK_KP_Subtract:
            return KeyCodes::KP_Subtract;
        case XK_KP_Add:
            return KeyCodes::KP_Add;
        case XK_KP_Enter:
            return KeyCodes::KP_Enter;
        case XK_KP_1:
        case XK_KP_2:
        case XK_KP_3:
        case XK_KP_4:
        case XK_KP_5:
        case XK_KP_6:
        case XK_KP_7:
        case XK_KP_8:
        case XK_KP_9:
            return static_cast<KeyCodes>(KeyCodes::KP_1 + (key - XK_KP_1));
        case XK_KP_0:
            return KeyCodes::KP_0;
        case XK_KP_Decimal:
            return KeyCodes::KP_Point;
        case XK_Help:
            return KeyCodes::KEY_Help;
        case XK_Menu:
            return KeyCodes::KEY_Menu;
        case XK_Alt_L:
            return KeyCodes::KEY_LeftAlt;
        case XK_Alt_R:
            return KeyCodes::KEY_RightAlt;
        case XK_Control_L:
            return KeyCodes::KEY_LeftControl;
        case XK_Control_R:
            return KeyCodes::KEY_RightControl;
        case XK_Shift_L:
            return KeyCodes::KEY_LeftShift;
        case XK_Shift_R:
            return KeyCodes::KEY_RightShift;
        case XK_Meta_L:
            return KeyCodes::KEY_LeftMeta;
        case XK_Meta_R:
            return KeyCodes::KEY_RightMeta;
        default:
            return SL::Input_Lite::KeyCodes::INVALID;
        }
    }
}
}