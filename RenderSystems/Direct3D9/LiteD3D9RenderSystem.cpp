#include "LiteD3D9RenderSystem.h"
#include "LiteD3D9RenderWindow.h"
#include "OgreD3D9ResourceManager.h"
#include "OgreD3D9DeviceManager.h"


using namespace Ogre;

LiteRenderSystem* Ogre::LiteD3D9RenderSystemFactory::createInstance( const String& name,LiteRoot* root )
{
	return new LiteD3D9RenderSystem(name,root);
}

Ogre::LiteD3D9RenderSystem::LiteD3D9RenderSystem( const String& name, LiteRoot* root ) 
:LiteRenderSystem(name,root)
{

}

RenderWindow* LiteD3D9RenderSystem::_createRenderWindow( const String &name, const NameValuePairList *miscParams /*= 0*/ )
{
	// Make sure we don't already have a render target of the 
	// same name as the one supplied
	String msg;
	if( mRenderTargets.find( name ) != mRenderTargets.end() )
	{
		msg = "A render target of the same name '" + name + "' already "
			"exists.  You cannot create a new window with this name.";
		OGRE_EXCEPT( Exception::ERR_INTERNAL_ERROR, msg, "D3D9RenderSystem::_createRenderWindow" );
	}

	LiteD3D9RenderWindow* renderWindow = NULL;//new LiteD3D9RenderWindow();
	unsigned int width=0;
	unsigned int height=0;
	bool fullScreen = 0;
	renderWindow->create(name, width, height, fullScreen, miscParams);

	mResourceManager->lockDeviceAccess();

	try
	{
		//mDeviceManager->linkRenderWindow(renderWindow);
	}
	catch (const Ogre::RenderingAPIException&)
	{
		// after catching the exception, clean up
		mResourceManager->unlockDeviceAccess();
		renderWindow->destroy();

		// re-throw
		throw;
	}

	mResourceManager->unlockDeviceAccess();

	//mRenderWindows.push_back(renderWindow);		

	//updateRenderSystemCapabilities(renderWindow);

	//attachRenderTarget( *renderWindow );

	return renderWindow;
}


const String LiteD3D9RenderSystem::typeName = "D3D9";