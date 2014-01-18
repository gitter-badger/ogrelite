#pragma once
#include "OgreRenderWindow.h"
#include "OgrePrerequisites.h"
#include "d3d9.h"
#include "OgreD3D9Device.h"
#include "d3d9types.h"


namespace Ogre
{
	
	class  LiteD3D9RenderWindow : public RenderWindow
	{
	public:
		/** Constructor.
		@param instance The application instance
		*/
		LiteD3D9RenderWindow					    (HINSTANCE instance);
		~LiteD3D9RenderWindow					    ();	
		
		
	};


}

