#include <Motus/Core/Base.h>
#include <Motus/Core/Input.h>


#ifdef MT_PLATFORM_WINDOWS

namespace Motus {

	class MOTUS_API WinInput : public Input {
	private:
		virtual bool IsKeyPressedImpl(int keycode) const final override;
		virtual bool IsMouseButtonPressedImpl(int button) const final override;
		virtual std::pair<float, float> GetMousePosImpl() const final override;
		virtual float GetMousePosXImpl() const final override;
		virtual float GetMousePosYImpl() const final override;
	};

}

#endif