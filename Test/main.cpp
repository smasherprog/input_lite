#include "Input_Lite.h"
#include <string>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

int main(int argc, char* argv[])
{
    std::this_thread::sleep_for(4s);
    for (auto c = ' '; c < 127; c++) {
        SL::Input_Lite::SendKey(c);
    }
    
    SL::Input_Lite::SendKey(SL::Input_Lite::SpecialKeyCodes::ENTER);
    // UNICODE SUPPORT!
    SL::Input_Lite::SendKeyDown((wchar_t)294); // the letter Ħ
    SL::Input_Lite::SendKeyDown((wchar_t)274); // the letter Ē
    SL::Input_Lite::SendKeyDown((wchar_t)315); // the letter Ļ
    SL::Input_Lite::SendKeyDown((wchar_t)315); // the letter Ļ
    SL::Input_Lite::SendKeyDown((wchar_t)526); // the letter Ȏ
    SL::Input_Lite::SendKey(SL::Input_Lite::SpecialKeyCodes::ENTER);
    SL::Input_Lite::SendKey(SL::Input_Lite::SpecialKeyCodes::TAB);
    SL::Input_Lite::SendKeys(std::string("this is a std::string"));
    SL::Input_Lite::SendKey(SL::Input_Lite::SpecialKeyCodes::ENTER);
    // unicode
    SL::Input_Lite::SendKeys(L"ĦĒĻĻȎ");
    SL::Input_Lite::SendKey(SL::Input_Lite::SpecialKeyCodes::ENTER);
    SL::Input_Lite::SendKeys(std::wstring(L"ĦĒĻĻȎ"));
    // SPECIAL KEYS
    SL::Input_Lite::SendKey(SL::Input_Lite::SpecialKeyCodes::ENTER);
    SL::Input_Lite::SendKey(SL::Input_Lite::SpecialKeyCodes::NUMPAD0);
    SL::Input_Lite::SendKey(SL::Input_Lite::SpecialKeyCodes::CAPSLOCK);
    SL::Input_Lite::SendKey(SL::Input_Lite::SpecialKeyCodes::TAB);

    SL::Input_Lite::SendKey(SL::Input_Lite::SpecialKeyCodes::ARROWLEFT);
    SL::Input_Lite::SendKey(SL::Input_Lite::SpecialKeyCodes::ARROWLEFT);
    SL::Input_Lite::SendKey(SL::Input_Lite::SpecialKeyCodes::ARROWLEFT);
    SL::Input_Lite::SendKey(SL::Input_Lite::SpecialKeyCodes::ARROWLEFT);
    SL::Input_Lite::SendKey(SL::Input_Lite::SpecialKeyCodes::ARROWLEFT);

    std::cout << "Starting Mouse move tests" << std::endl;
    for (auto x = 0; x < 500; x++) {
        SL::Input_Lite::SendMousePosition_AsAbsolute(SL::Input_Lite::Pos{ x, 300 });
        std::this_thread::sleep_for(10ms);
    }
    for (auto y= 0;y< 500; y++) {
        SL::Input_Lite::SendMousePosition_AsAbsolute(SL::Input_Lite::Pos{ 500, y });
        std::this_thread::sleep_for(10ms);
    }

    return 0;
}
