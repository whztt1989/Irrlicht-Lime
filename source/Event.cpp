#include "stdafx.h"
#include "Event.h"

using namespace irr;
using namespace System;

namespace IrrlichtLime {

Event::Event(const SEvent& other)
{
	m_NativeValue = new SEvent(other);
}

Event::GUIEvent Event::GUI::get()
{
	LIME_ASSERT(Type == EventType::GUI);
	return Event::GUIEvent(m_NativeValue->GUIEvent);
}

Event::JoystickEvent Event::Joystick::get()
{
	LIME_ASSERT(Type == EventType::Joystick);
	return Event::JoystickEvent(m_NativeValue->JoystickEvent);
}

Event::KeyEvent Event::Key::get()
{
	LIME_ASSERT(Type == EventType::Key);
	return Event::KeyEvent(m_NativeValue->KeyInput);
}

Event::LogEvent Event::Log::get()
{
	LIME_ASSERT(Type == EventType::Log);
	return Event::LogEvent(m_NativeValue->LogEvent);
}

Event::MouseEvent Event::Mouse::get()
{
	LIME_ASSERT(Type == EventType::Mouse);
	return Event::MouseEvent(m_NativeValue->MouseInput);
}

Event::UserEvent Event::User::get()
{
	LIME_ASSERT(Type == EventType::User);
	return Event::UserEvent(m_NativeValue->UserEvent);
}

EventType Event::Type::get()
{
	return (EventType)m_NativeValue->EventType;
}

String^ Event::ToString()
{
	return String::Format("Type={0}", Type);
}

} // end namespace IrrlichtLime