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


            virtual std::shared_ptr<IInputConfiguration> onEvent(const std::function<void(const PlatformIndependentKeyEvent&)>& cb)  override {
                assert(!Impl->OnPlatformIndependentKeyEvent);
                Impl->OnPlatformIndependentKeyEvent = cb;
                return std::make_shared<InputConfiguration>(Impl);
            }
            virtual std::shared_ptr<IInputConfiguration> onEvent(const std::function<void(const PlatformIndependentMouseEvent&)>& cb)  override {
                assert(!Impl->OnPlatformIndependentMouseEvent);
                Impl->OnPlatformIndependentMouseEvent = cb;
                return std::make_shared<InputConfiguration>(Impl);
            }
            virtual std::shared_ptr<IInputConfiguration> onEvent(const std::function<void(const MouseMoveEvent<MouseScroll>&)>& cb) override {
                assert(!Impl->OnMouseScroll);
                Impl->OnMouseScroll = cb;
                return std::make_shared<InputConfiguration>(Impl);
            }
            virtual std::shared_ptr<IInputConfiguration> onEvent(const std::function<void(const MouseMoveEvent<MousePositionOffset>&)>& cb)  override {
                assert(!Impl->OnMousePositionOffset);
                Impl->OnMousePositionOffset = cb;
                return std::make_shared<InputConfiguration>(Impl);
            }
            virtual std::shared_ptr<IInputConfiguration> onEvent(const std::function<void(const MouseMoveEvent<MousePositionAbsolute>&)>& cb)  override {
                assert(!Impl->OnMousePositionAbsolute);
                Impl->OnMousePositionAbsolute = cb;
                return std::make_shared<InputConfiguration>(Impl);
            }
            virtual std::shared_ptr<IInputManager> Build() override {
                return Impl;
            }
        };
        std::shared_ptr<IInputConfiguration> CreateInputConfiguration() {
            return std::make_shared<InputConfiguration>();
        }
    };
}