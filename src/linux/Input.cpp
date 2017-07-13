#include "Input_Lite.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/extensions/XInput.h>
#include <X11/extensions/XTest.h>
#include <X11/keysym.h>

namespace SL
{
namespace Input_Lite
{
    void SendKey_Impl(char key, int pressed)
    {
        auto display = XOpenDisplay(NULL);
        if(key >= ' ' && key <= '~') {
            XTestFakeKeyEvent(display, XKeysymToKeycode(display, key), pressed, CurrentTime);
        } else {
        }
        XCloseDisplay(display);
    }
    void SendKey_Impl(wchar_t key, int pressed)
    {
        auto display = XOpenDisplay(NULL);
        if(key >= ' ' && key <= '~') {
            XTestFakeKeyEvent(display, XKeysymToKeycode(display, key), pressed, CurrentTime);
        } else {
        }
        XCloseDisplay(display);
    }
    void SendKeyUp(char key)
    {
        SendKey_Impl(key, False);
    }
    void SendKeyUp(wchar_t key)
    {
        SendKey_Impl(key, False);
    }
    void SendKeyDown(wchar_t key)
    {
        SendKey_Impl(key, True);
    }
    void SendKeyDown(char key)
    {
        SendKey_Impl(key, True);
    }
    void SendKeyUp(SpecialKeyCodes key)
    {
    }
    void SendKeyDown(SpecialKeyCodes key)
    {
    }
}
}