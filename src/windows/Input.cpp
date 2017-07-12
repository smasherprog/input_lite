#include "Input_Lite.h"
#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace SL {
    namespace Input_Lite {

        void SendKeyUp(wchar_t key) {
            if (key < 128) {
                SendKeyUp(static_cast<char>(key));
            }
            else {
                INPUT inp = { 0 };
                inp.type = INPUT_KEYBOARD;
                inp.ki.wScan = key;
                inp.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
                SendInput(1, &inp, sizeof(INPUT));
            }
        }
        void SendKeyDown(wchar_t key) {
            if (key < 128) {
                SendKeyDown(static_cast<char>(key));
            }
            else {
                INPUT inp = { 0 };
                inp.type = INPUT_KEYBOARD;
                inp.ki.wScan = key;
                inp.ki.dwFlags = KEYEVENTF_UNICODE ;
                SendInput(1, &inp, sizeof(INPUT));
            }
        }
        void SendKeyUp(char key) {
            if (key >= ' ' && key <= '~') {
                auto vkkey = VkKeyScan(key);
                auto mappedKey = LOBYTE(vkkey);
                auto highkey = HIBYTE(vkkey);
                if (highkey == 1) {
                    INPUT inp[3] = { 0 };
                    inp[0].type = INPUT_KEYBOARD;
                    inp[0].ki.wVk = VK_LSHIFT;
                    inp[1].type = INPUT_KEYBOARD;
                    inp[1].ki.wVk = mappedKey;
                    inp[1].ki.dwFlags = KEYEVENTF_KEYUP;
                    inp[2].type = INPUT_KEYBOARD;
                    inp[2].ki.wVk = VK_LSHIFT;
                    inp[2].ki.dwFlags = KEYEVENTF_KEYUP;
                    SendInput(sizeof(inp) / sizeof(INPUT), inp, sizeof(INPUT));
                }
                else {
                    INPUT inp = { 0 };
                    inp.type = INPUT_KEYBOARD;
                    inp.ki.wVk = mappedKey;
                    inp.ki.dwFlags = KEYEVENTF_KEYUP;
                    SendInput(1, &inp, sizeof(INPUT));
                }
            }
            else {

            }
        }
        void SendKeyDown(char key) {
            if (key >= ' ' && key <= '~') {
                auto vkkey = VkKeyScan(key);
                auto mappedKey = LOBYTE(vkkey);
                auto highkey = HIBYTE(vkkey);
                if (highkey == 1) {
                    INPUT inp[3] = { 0 };
                    inp[0].type = INPUT_KEYBOARD;
                    inp[0].ki.wVk = VK_LSHIFT;
                    inp[1].type = INPUT_KEYBOARD;
                    inp[1].ki.wVk = mappedKey;
                    inp[2].type = INPUT_KEYBOARD;
                    inp[2].ki.wVk = VK_LSHIFT;
                    inp[2].ki.dwFlags = KEYEVENTF_KEYUP;
                    SendInput(sizeof(inp) / sizeof(INPUT), inp, sizeof(INPUT));
                }
                else {
                    INPUT inp = { 0 };
                    inp.type = INPUT_KEYBOARD;
                    inp.ki.wVk = mappedKey;
                    SendInput(1, &inp, sizeof(INPUT));
                }
            }
            else {
            }
        }
    };
}