#pragma once
#include "LiteRenderSystem.h"

namespace Ogre
{



	//lite ogre root , manager Render systems and other singleton class object
	class _OgreExport LiteRoot
	{
	public:
		LiteRoot():mRSCreateCount(0){}
		void addRenderSystemFactory(LiteRenderSystemFactory * newRSFactory);
		LiteRenderSystem* createRenderSystem(const String& name, const String& typeName);	

	protected:
		typedef map<String, LiteRenderSystem*>::type RenderSystemInstances;
		RenderSystemInstances m_rsList;
		typedef list<LiteRenderSystemFactory*>::type RenderSystemFactoryList;
		RenderSystemFactoryList m_rsFactories;

		int mRSCreateCount; 		
	};


}
