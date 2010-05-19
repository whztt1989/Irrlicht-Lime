#pragma once

#include "stdafx.h"
#include "Texture.h"
#include "VideoDriver.h"

using namespace irr;
using namespace System;
using namespace IrrlichtLime::Core;

namespace IrrlichtLime {
namespace Video {

VideoDriver::VideoDriver(video::IVideoDriver* videoDriver)
{
	LIME_ASSERT(videoDriver != nullptr);
	m_VideoDriver = videoDriver;
}

bool VideoDriver::BeginScene(bool backBuffer, bool zBuffer, Coloru ^color)
{
	LIME_ASSERT(color != nullptr);
	return m_VideoDriver->beginScene(backBuffer, zBuffer, *color->m_NativeValue);
}

bool VideoDriver::BeginScene(bool backBuffer, bool zBuffer)
{
	return m_VideoDriver->beginScene(backBuffer, zBuffer);
}

bool VideoDriver::BeginScene(bool backBuffer)
{
	return m_VideoDriver->beginScene(backBuffer);
}

bool VideoDriver::BeginScene()
{
	return m_VideoDriver->beginScene();
}

bool VideoDriver::EndScene()
{
	return m_VideoDriver->endScene();
}

Texture^ VideoDriver::GetTexture(String^ filename)
{
	return LIME_SAFEWRAP(Texture, m_VideoDriver->getTexture(Lime::StringToPath(filename)));
}

Video::DriverType VideoDriver::DriverType::get()
{
	return (Video::DriverType)m_VideoDriver->getDriverType();
}

Recti^ VideoDriver::ViewPort::get()
{
	return gcnew Recti(m_VideoDriver->getViewPort());
}

void VideoDriver::ViewPort::set(Recti^ value)
{
	m_VideoDriver->setViewPort(*value->m_NativeValue);
}

Dimension2Du^ VideoDriver::ScreenSize::get()
{
	return gcnew Dimension2Du(m_VideoDriver->getScreenSize());
}

Dimension2Du^ VideoDriver::CurrentRenderTargetSize::get()
{
	return gcnew Dimension2Du(m_VideoDriver->getCurrentRenderTargetSize());
}

Dimension2Du^ VideoDriver::MaxTextureSize::get()
{
	return gcnew Dimension2Du(m_VideoDriver->getMaxTextureSize());
}

int VideoDriver::FPS::get()
{
	return m_VideoDriver->getFPS();
}

unsigned int VideoDriver::PrimitiveCountDrawn::get()
{
	return m_VideoDriver->getPrimitiveCountDrawn();
}

unsigned int VideoDriver::MaximalDynamicLightAmount::get()
{
	return m_VideoDriver->getMaximalDynamicLightAmount();
}

unsigned int VideoDriver::DynamicLightCount::get()
{
	return m_VideoDriver->getDynamicLightCount();
}

unsigned int VideoDriver::MaximalPrimitiveCount::get()
{
	return m_VideoDriver->getMaximalPrimitiveCount();
}

unsigned int VideoDriver::MaterialRendererCount::get()
{
	return m_VideoDriver->getMaterialRendererCount();
}

String^ VideoDriver::Name::get()
{
	return gcnew String(m_VideoDriver->getName());
}

String^ VideoDriver::VendorInfo::get()
{
	return gcnew String(m_VideoDriver->getVendorInfo().c_str());
}

String^ VideoDriver::ToString()
{
	return Name;
}

} // end namespace Video
} // end namespace IrrlichtLime