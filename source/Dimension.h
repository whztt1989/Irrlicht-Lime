#pragma once

#include "stdafx.h"

using namespace irr;
using namespace System;

namespace IrrlichtLime {
namespace Core {

public ref class Dimension2Du : Lime::NativeValue<core::dimension2du>
{
public:

	Dimension2Du(unsigned int width, unsigned int height)
	{
		m_NativeValue = new core::dimension2du(width, height);
	}

	property unsigned int Width
	{
		unsigned int get() { return m_NativeValue->Width; }
		void set(unsigned int value) { m_NativeValue->Width = value; }
	}

	property unsigned int Height
	{
		unsigned int get() { return m_NativeValue->Height; }
		void set(unsigned int value) { m_NativeValue->Height = value; }
	}

	property unsigned int Area
	{
		unsigned int get() { return m_NativeValue->getArea(); }
	}

	virtual String^ ToString() override
	{
		return String::Format("Width={0}; Height={1}", Width, Height);
	}

internal:

	Dimension2Du(core::dimension2du value)
	{
		m_NativeValue = new core::dimension2du(value);
	}
};

} // end namespace Core
} // end namespace IrrlichtLime