#pragma once

#include "stdafx.h"
#include "ReferenceCounted.h"

using namespace irr;
using namespace System;
using namespace System::Runtime::InteropServices; // for OutAttribute
using namespace IrrlichtLime::Core;

namespace IrrlichtLime {

namespace GUI { ref class CursorControl; ref class GUIEnvironment; }
namespace IO { ref class FileSystem; }
namespace Scene { ref class SceneManager; }
namespace Video { ref class VideoDriver; }

public ref class IrrlichtDevice : ReferenceCounted
{
public:

	static IrrlichtDevice^ CreateDevice(Video::DriverType driverType, Dimension2Du^ windowSize, unsigned int bits, bool fullscreen, bool stencilbuffer, bool vsync);
	static IrrlichtDevice^ CreateDevice(Video::DriverType driverType, Dimension2Du^ windowSize, unsigned int bits, bool fullscreen, bool stencilbuffer);
	static IrrlichtDevice^ CreateDevice(Video::DriverType driverType, Dimension2Du^ windowSize, unsigned int bits, bool fullscreen);
	static IrrlichtDevice^ CreateDevice(Video::DriverType driverType, Dimension2Du^ windowSize, unsigned int bits);
	static IrrlichtDevice^ CreateDevice(Video::DriverType driverType, Dimension2Du^ windowSize);
	static IrrlichtDevice^ CreateDevice(Video::DriverType driverType);
	static IrrlichtDevice^ CreateDevice();

	bool GetGammaRamp([Out] float% red, [Out] float% green, [Out] float% blue, [Out] float% relativebrightness, [Out] float% relativecontrast);
	bool Run();
	bool SetGammaRamp(float red, float green, float blue, float relativebrightness, float relativecontrast);
	void Sleep(unsigned int timeMs, bool pauseTimer);
	void Sleep(unsigned int timeMs);
	void Yield();

	property GUI::CursorControl^ CursorControl { GUI::CursorControl^ get(); }
	property IO::FileSystem^ FileSystem { IO::FileSystem^ get(); }
	property bool Fullscreen { bool get(); }
	property GUI::GUIEnvironment^ GUIEnvironment { GUI::GUIEnvironment^ get(); }
	property Scene::SceneManager^ SceneManager { Scene::SceneManager^ get(); }
	property String^ Version { String^ get(); }
	property Video::VideoDriver^ VideoDriver { Video::VideoDriver^ get(); }
	property bool WindowActive { bool get(); }
	property String^ WindowCaption { void set(String^ value); }
	property bool WindowFocused { bool get(); }
	property bool WindowMinimized { bool get(); }
	property bool WindowResizable { void set(bool value); }

	virtual String^ ToString() override;

internal:

	IrrlichtDevice(irr::IrrlichtDevice* irrlichtDevice);

	irr::IrrlichtDevice* m_IrrlichtDevice;

private:

	static void CreateDevice_start();
};

} // end namespace IrrlichtLime