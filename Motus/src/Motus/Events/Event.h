// Currently Motus Engine uses blocking Event System.
// It means that if any event happens, it will be
// immediately dispatched and block whole engine execution.
// --------------------------------------------------------
// TODO: Buffer Event system
// Buffer Event system will dispatch all events which happened
// during main cycle and dispatch it in OnUpdate() stage,
// which will not block execution of whole engine.


#pragma once
#include <Motus/Core/Base.h>

#include <spdlog/fmt/fmt.h>
#include <string>
#include <functional>

#ifdef MT_DEBUG
	#define MT_TRACE_EVENTS
#endif

namespace Motus {

	// All possible event types
	enum class EventType {
		None = 0,
		WindowClose, WindowMoved, WindowResize, WindowFocus, WindowUnfocus,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonHold, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// All possible event categories, stored as bit value to be able to 
	// store event with 2 or more categories in one `int` variable.
	enum EventCategory {
		None = 0,
		ApplicationEventCategory	= BIT(1),
		InputEventCategory			= BIT(2),
		KeyboardEventCategory		= BIT(3),
		MouseEventCategory			= BIT(4)
	};

// Macros to minimize code further
#define EVENT_CLASS_TYPE(type)  static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetEventName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetEventCategoryFlags() const override { return category; }
// ===============================



	// Event base class
	class MOTUS_API Event {
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual int GetEventCategoryFlags() const = 0;

		// DEBUG ONLY methods.
		// TODO: disable these methods in all builds except Debug
		virtual const char* GetEventName() const = 0;
		virtual std::string GetLogInfo() const { return GetEventName(); };
		// ======================================================
		
		inline bool IsInCategory(EventCategory category) {
			return GetEventCategoryFlags() & category;
		}

		bool m_IsHandled = false;
	};


	// Event Dispatcher Class implementation 
	class EventDispatcher
	{
		template <typename T>
		using EventFunction = std::function<bool(T&)>;
	public:
		// Constructor
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFunction<T> function)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_IsHandled |= function(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	
} // namespace Motus


// TODO: Custom format type for logging events
/* ------------------------------------
template<> struct fmt::formatter<const Motus::Event&> {
	char presentation = 'f';
	constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
		auto it = ctx.begin(), end = ctx.end();
		if (it != end && (*it == 'f' || *it == 'e'))presentation = *it++;
		if (it != end && *it != '}') throw format_error("Invalid format");
		return it;
	}
};

template <typename FormatContext>
auto format(const Motus::Event& e, FormatContext& ctx) -> decltype(ctx.out()) {
	return presentation == 'f'
		? format_to(ctx.out(), "{}", e.GetLogInfo().c_str())
		: format_to(ctx.out(), "{}", e.GetLogInfo().c_str());
};

*/