#include "Input_Lite.h"
#include "InputManager.h"
#include <assert.h>

namespace SL {
    namespace Input_Lite {

 
        class InputConfiguration: public IInputConfiguration
        {
            std::shared_ptr<InputManager> Impl;
        public:
            InputConfiguration(const  std::shared_ptr<InputManager>& impl) : Impl(impl) {}
            virtual ~InputConfiguration() {}

            virtual std::shared_ptr<IInputConfiguration> onKey(const std::function<void(char, bool)>& cb) override {
                assert(!Impl->onKeyc);
                Impl->onKeyc = cb;
                return std::make_shared<InputConfiguration>(Impl);
            }
            virtual std::shared_ptr<IInputConfiguration> onKey(const std::function<void(wchar_t, bool)>& cb) override {
                assert(!Impl->onKeywc);
                Impl->onKeywc = cb;
                return std::make_shared<InputConfiguration>(Impl);
            }
            virtual std::shared_ptr<IInputConfiguration> onKey(const std::function<void(SpecialKeyCodes, bool)>& cb)override {
                assert(!Impl->onKeysk);
                Impl->onKeysk = cb;
                return std::make_shared<InputConfiguration>(Impl);
            }
            virtual std::shared_ptr<IInputConfiguration> onMouse(const std::function<void(MouseButtons, bool)>& cb) override {
                assert(!Impl->onMouse);
                Impl->onMouse = cb;
                return std::make_shared<InputConfiguration>(Impl);
            }
            virtual std::shared_ptr<IInputManager> start() override {
                return Impl;
            }
        };
        std::shared_ptr<IInputConfiguration> CreateInputConfiguration() {
            return std::make_shared<InputConfiguration>();
        }
    };
}