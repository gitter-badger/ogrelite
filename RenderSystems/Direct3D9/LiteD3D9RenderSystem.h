#pragma once
#include "..\LiteRenderSystem.h"


namespace Ogre
{
	class D3D9HardwareBufferManager;
	class D3D9GpuProgramManager;
	class D3D9HLSLProgramFactory;
	class D3D9ResourceManager;
	class D3D9DeviceManager;

	class LiteD3D9RenderSystem : public LiteRenderSystem
	{
	public:
		LiteD3D9RenderSystem(const String& name,LiteRoot* root);
		~LiteD3D9RenderSystem(void){}
		
		virtual const String& getTypeName(void) const{ return typeName; }

		const static String typeName; 

		virtual RenderWindow* _createRenderWindow(const String &name, const NameValuePairList *miscParams = 0);

		D3D9HardwareBufferManager* mHardwareBufferManager;
		D3D9GpuProgramManager* mGpuProgramManager;
		D3D9HLSLProgramFactory* mHLSLProgramFactory;
		D3D9ResourceManager* mResourceManager;
		D3D9DeviceManager* mDeviceManager;
	};

	class LiteD3D9RenderSystemFactory : public LiteRenderSystemFactory
	{
	public:
		virtual const String& getTypeName()const{ return LiteD3D9RenderSystem::typeName; }
		virtual LiteRenderSystem* createInstance(const String& name, LiteRoot* root);
	};
}


