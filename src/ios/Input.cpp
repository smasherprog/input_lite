#include "Input_Lite.h"
#include <ApplicationServices/ApplicationServices.h>

namespace SL
{
    namespace Input_Lite
    {
        void SendInput(const KeyEvent& e){
            auto ev = CGEventCreateKeyboardEvent (NULL, (CGKeyCode)56, e.Pressed);
            if(ev){
                CGEventPost(kCGHIDEventTap, ev);
                CFRelease(ev);
            }
        }
        void SendInput(const MouseButtonEvent& e){
            auto msevent = CGEventCreate(NULL);
            auto loc = CGEventGetLocation(msevent);
            CFRelease(msevent);
            
            CGEventRef ev = nullptr;
            switch(e.Button) {
                case MouseButtons::LEFT:
                    ev = CGEventCreateMouseEvent(NULL, e.Pressed ? kCGEventLeftMouseDown: kCGEventLeftMouseUp, loc, kCGMouseButtonLeft);
                case MouseButtons::MIDDLE:
                    ev = CGEventCreateMouseEvent(NULL, e.Pressed ? kCGEventOtherMouseDown: kCGEventOtherMouseUp, loc, kCGMouseButtonCenter);
                case MouseButtons::RIGHT:
                    ev = CGEventCreateMouseEvent(NULL, e.Pressed ? kCGEventRightMouseDown: kCGEventRightMouseUp, loc, kCGMouseButtonRight);
                default:
                    break;
            }
            if(ev){
                CGEventPost(kCGHIDEventTap, ev);
                CFRelease(ev);
            }
        }
        void SendInput(const MouseScrollEvent& e){
            auto ev = CGEventCreateScrollWheelEvent(NULL, kCGScrollEventUnitLine, 1, -e.Offset);
            if(ev){
                CGEventPost(kCGHIDEventTap, ev);
                CFRelease(ev);
            }
        }
        void SendInput(const MousePositionOffsetEvent& e){
            auto msevent = CGEventCreate(NULL);
            auto loc = CGEventGetLocation(msevent);
            CFRelease(msevent);
            loc.x+=e.X;
            loc.y += e.Y;
            CGWarpMouseCursorPosition(loc);
        }
        void SendInput(const MousePositionAbsoluteEvent& e){
            CGPoint p;
            p.x = e.X;
            p.y = e.Y;
            CGWarpMouseCursorPosition(p);
        }
        CGKeyCode ConvertToNative(KeyCodes key){
            
        }
        KeyCodes ConvertToKeyCode(CGKeyCode key){
            
        }

    }
}
