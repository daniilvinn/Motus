#pragma once
#include "Base.h"
#include <motus_pch.h>


namespace Motus {

	class MOTUS_API Input {
	public:
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); };
		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<float, float> GetMousePos() { return s_Instance->GetMousePosImpl(); };
		inline static float GetMousePosX() { return s_Instance->GetMousePosXImpl(); };
		inline static float GetMousePosY() { return s_Instance->GetMousePosYImpl(); };

	protected:
		virtual bool IsKeyPressedImpl(int keycode) const = 0;
		virtual bool IsMouseButtonPressedImpl(int button) const = 0;
		virtual std::pair<float, float> GetMousePosImpl() const = 0;
		virtual float GetMousePosXImpl() const = 0;
		virtual float GetMousePosYImpl() const = 0;

	private:
		static Input* s_Instance;
	};

}