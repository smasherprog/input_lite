#include "Input_Lite.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>

using namespace std::chrono_literals;

void SendSingleKeys() {
    SL::Input_Lite::SendKeyDown('H');
    SL::Input_Lite::SendKeyUp('H');
    SL::Input_Lite::SendKeyDown('e');
    SL::Input_Lite::SendKeyUp('e');
    SL::Input_Lite::SendKeyDown('l');
    SL::Input_Lite::SendKeyUp('l');
    SL::Input_Lite::SendKey('o');
    SL::Input_Lite::SendKey('o');

    //UNICODE SUPPORT!
    SL::Input_Lite::SendKeyDown((wchar_t)294);//the letter Ħ
    SL::Input_Lite::SendKeyDown((wchar_t)274);//the letter Ē
    SL::Input_Lite::SendKeyDown((wchar_t)315);//the letter Ļ
    SL::Input_Lite::SendKeyDown((wchar_t)315);//the letter Ļ
    SL::Input_Lite::SendKeyDown((wchar_t)526);//the letter Ȏ

}
void SendStrings() {
    SL::Input_Lite::SendKeys("Hey there");
    SL::Input_Lite::SendKeys(std::string("this is a std::string"));
    //unicode
    SL::Input_Lite::SendKeys(L"ĦĒĻĻȎ");
    SL::Input_Lite::SendKeys(std::wstring(L"ĦĒĻĻȎ"));
}
int main(int argc, char* argv[]) {

    std::cout << "Input Example running" << std::endl;


    std::this_thread::sleep_for(2s);
    SendSingleKeys();
    std::this_thread::sleep_for(2s);
    SendStrings();
    std::this_thread::sleep_for(10s);

    return 0;
}
