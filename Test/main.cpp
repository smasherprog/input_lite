#include "Input_Lite.h"
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <assert.h>

using namespace std::chrono_literals;

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#elif __APPLE__

#elif __linux__

#else
#error "Unknown Operating System!"
#endif

int main(int argc, char* argv[])
{
    std::this_thread::sleep_for(4s);

#ifdef WIN32
    //windows ascii codes are the char representations 
    assert(SL::Input_Lite::ConvertToKeyCode('0') == SL::Input_Lite::KeyCodes::KEY_0);
    assert(SL::Input_Lite::ConvertToKeyCode('1') == SL::Input_Lite::KeyCodes::KEY_1);
    assert(SL::Input_Lite::ConvertToKeyCode('2') == SL::Input_Lite::KeyCodes::KEY_2);
    assert(SL::Input_Lite::ConvertToKeyCode('3') == SL::Input_Lite::KeyCodes::KEY_3);
    assert(SL::Input_Lite::ConvertToKeyCode('4') == SL::Input_Lite::KeyCodes::KEY_4);
    assert(SL::Input_Lite::ConvertToKeyCode('5') == SL::Input_Lite::KeyCodes::KEY_5);
    assert(SL::Input_Lite::ConvertToKeyCode('6') == SL::Input_Lite::KeyCodes::KEY_6);
    assert(SL::Input_Lite::ConvertToKeyCode('7') == SL::Input_Lite::KeyCodes::KEY_7);
    assert(SL::Input_Lite::ConvertToKeyCode('8') == SL::Input_Lite::KeyCodes::KEY_8);
    assert(SL::Input_Lite::ConvertToKeyCode('9') == SL::Input_Lite::KeyCodes::KEY_9);

    assert(SL::Input_Lite::ConvertToKeyCode('A') == SL::Input_Lite::KeyCodes::KEY_A);
    assert(SL::Input_Lite::ConvertToKeyCode('B') == SL::Input_Lite::KeyCodes::KEY_B);
    assert(SL::Input_Lite::ConvertToKeyCode('C') == SL::Input_Lite::KeyCodes::KEY_C);
    assert(SL::Input_Lite::ConvertToKeyCode('D') == SL::Input_Lite::KeyCodes::KEY_D);
    assert(SL::Input_Lite::ConvertToKeyCode('E') == SL::Input_Lite::KeyCodes::KEY_E);
    assert(SL::Input_Lite::ConvertToKeyCode('F') == SL::Input_Lite::KeyCodes::KEY_F);
    assert(SL::Input_Lite::ConvertToKeyCode('G') == SL::Input_Lite::KeyCodes::KEY_G);
    assert(SL::Input_Lite::ConvertToKeyCode('H') == SL::Input_Lite::KeyCodes::KEY_H);
    assert(SL::Input_Lite::ConvertToKeyCode('I') == SL::Input_Lite::KeyCodes::KEY_I);
    assert(SL::Input_Lite::ConvertToKeyCode('J') == SL::Input_Lite::KeyCodes::KEY_J);
    assert(SL::Input_Lite::ConvertToKeyCode('K') == SL::Input_Lite::KeyCodes::KEY_K);
    assert(SL::Input_Lite::ConvertToKeyCode('L') == SL::Input_Lite::KeyCodes::KEY_L);
    assert(SL::Input_Lite::ConvertToKeyCode('M') == SL::Input_Lite::KeyCodes::KEY_M);
    assert(SL::Input_Lite::ConvertToKeyCode('N') == SL::Input_Lite::KeyCodes::KEY_N);
    assert(SL::Input_Lite::ConvertToKeyCode('O') == SL::Input_Lite::KeyCodes::KEY_O);
    assert(SL::Input_Lite::ConvertToKeyCode('P') == SL::Input_Lite::KeyCodes::KEY_P);
    assert(SL::Input_Lite::ConvertToKeyCode('Q') == SL::Input_Lite::KeyCodes::KEY_Q);
    assert(SL::Input_Lite::ConvertToKeyCode('R') == SL::Input_Lite::KeyCodes::KEY_R);
    assert(SL::Input_Lite::ConvertToKeyCode('S') == SL::Input_Lite::KeyCodes::KEY_S);
    assert(SL::Input_Lite::ConvertToKeyCode('T') == SL::Input_Lite::KeyCodes::KEY_T);
    assert(SL::Input_Lite::ConvertToKeyCode('U') == SL::Input_Lite::KeyCodes::KEY_U);
    assert(SL::Input_Lite::ConvertToKeyCode('V') == SL::Input_Lite::KeyCodes::KEY_V);
    assert(SL::Input_Lite::ConvertToKeyCode('W') == SL::Input_Lite::KeyCodes::KEY_W);
    assert(SL::Input_Lite::ConvertToKeyCode('X') == SL::Input_Lite::KeyCodes::KEY_X);
    assert(SL::Input_Lite::ConvertToKeyCode('Y') == SL::Input_Lite::KeyCodes::KEY_Y);
    assert(SL::Input_Lite::ConvertToKeyCode('Z') == SL::Input_Lite::KeyCodes::KEY_Z);

    assert(SL::Input_Lite::ConvertToKeyCode(VK_RETURN) == SL::Input_Lite::KeyCodes::KEY_Enter);
    assert(SL::Input_Lite::ConvertToKeyCode(VK_ESCAPE) == SL::Input_Lite::KeyCodes::KEY_Escape);
    assert(SL::Input_Lite::ConvertToKeyCode(VK_DELETE) == SL::Input_Lite::KeyCodes::KEY_Delete);
    assert(SL::Input_Lite::ConvertToKeyCode(VK_TAB) == SL::Input_Lite::KeyCodes::KEY_Tab);
    assert(SL::Input_Lite::ConvertToKeyCode(VK_SPACE) == SL::Input_Lite::KeyCodes::KEY_Space);
    assert(SL::Input_Lite::ConvertToKeyCode(VK_OEM_MINUS) == SL::Input_Lite::KeyCodes::KEY_Minus);
    assert(SL::Input_Lite::ConvertToKeyCode(VK_OEM_PLUS) == SL::Input_Lite::KeyCodes::KEY_Equals);//this is correct and not a mistype

    assert(SL::Input_Lite::ConvertToKeyCode(VK_OEM_4) == SL::Input_Lite::KeyCodes::KEY_LeftBracket);
    assert(SL::Input_Lite::ConvertToKeyCode(VK_OEM_6) == SL::Input_Lite::KeyCodes::KEY_RightBracket);
    assert(SL::Input_Lite::ConvertToKeyCode(VK_OEM_5) == SL::Input_Lite::KeyCodes::KEY_Backslash);
    assert(SL::Input_Lite::ConvertToKeyCode(VK_OEM_1) == SL::Input_Lite::KeyCodes::KEY_Semicolon);
    assert(SL::Input_Lite::ConvertToKeyCode(VK_OEM_7) == SL::Input_Lite::KeyCodes::KEY_Quote);
#elif __APPLE__

#elif __linux__

#else
#error "Unknown Operating System!"
#endif

    std::cout << "Starting Mouse move tests by Offset" << std::endl;
    SL::Input_Lite::SendInput(SL::Input_Lite::MousePositionAbsoluteEvent{ 100, 100 });
    for (auto x = 0; x < 500; x++) {
        SL::Input_Lite::SendInput(SL::Input_Lite::MousePositionOffsetEvent{ 1, 0 });
        std::this_thread::sleep_for(10ms);
    }
    for (auto y = 0; y < 500; y++) {
        SL::Input_Lite::SendInput(SL::Input_Lite::MousePositionOffsetEvent{ 0, 1 });
        std::this_thread::sleep_for(10ms);
    }
    std::cout << "Starting Mouse move tests by Absolute" << std::endl;
    for (auto x = 0; x < 500; x++) {
        SL::Input_Lite::SendInput(SL::Input_Lite::MousePositionAbsoluteEvent{ x, 300 });
        std::this_thread::sleep_for(10ms);
    }
    for (auto y = 0; y < 500; y++) {
        SL::Input_Lite::SendInput(SL::Input_Lite::MousePositionAbsoluteEvent{ 500, y });
        std::this_thread::sleep_for(10ms);
    }
    std::cout << "Starting Mouse Click tests right down up" << std::endl;
    SL::Input_Lite::SendInput(SL::Input_Lite::MouseButtonEvent{ true, SL::Input_Lite::MouseButtons::RIGHT });
    SL::Input_Lite::SendInput(SL::Input_Lite::MouseButtonEvent{ false, SL::Input_Lite::MouseButtons::RIGHT });

    std::cout << "Starting Mouse Click tests left down up" << std::endl;
    SL::Input_Lite::SendInput(SL::Input_Lite::MouseButtonEvent{ true, SL::Input_Lite::MouseButtons::LEFT });
    SL::Input_Lite::SendInput(SL::Input_Lite::MouseButtonEvent{ false, SL::Input_Lite::MouseButtons::LEFT });

    std::cout << "Starting Mouse wheel tests " << std::endl;
    for (auto y = 0; y < 500; y++) {
        SL::Input_Lite::SendInput(SL::Input_Lite::MouseScrollEvent{ 1 });
        std::this_thread::sleep_for(10ms);
    }
    for (auto y = 0; y < 500; y++) {
        SL::Input_Lite::SendInput(SL::Input_Lite::MouseScrollEvent{ -1 });
        std::this_thread::sleep_for(10ms);
    }
    return 0;
}
