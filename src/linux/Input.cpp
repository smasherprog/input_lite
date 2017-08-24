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
        KeySym k;
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
}
}