#pragma once
#include <string>

namespace SL {
    namespace Input_Lite {
       
        void SendKeyUp(char key);
        void SendKeyUp(wchar_t key);
        template <class T> void SendKeyUp(T) = delete;

        void SendKeyDown(char key);
        void SendKeyDown(wchar_t key);
        template <class T> void SendKeyDown(T) = delete;
    
        inline void SendKey(char key) {
            SendKeyDown(key);
            SendKeyUp(key);
        }
        inline void SendKey(wchar_t key) {
            SendKeyDown(key);
            SendKeyUp(key);
        }
        template <class T> void SendKey(T) = delete;

        inline void SendKeys(std::string keys) {
            for (auto k : keys) {
                SendKey(k);
            }
        }

        inline void SendKeys(std::wstring keys) {
            for (auto k : keys) {
                SendKey(k);
            }
        }
        template<typename T, size_t ELEMENTSIZE>inline void SendKeys(T (&keys)[ELEMENTSIZE]) {
            for (auto k : keys) {
                SendKey(k);
            }
        }
        template <class T> void SendKeys(T) = delete;
    }
}