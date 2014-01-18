#pragma once
#include "include/OgreRenderSystem.h"

namespace Ogre
{
	/** \addtogroup Core
	*  @{
	*/
	/** \addtogroup RenderSystem
	*  @{
	*/

	class LiteRoot;
	class LiteRenderSystem
	{
	public:
		/** Default Constructor.
		*/
		LiteRenderSystem(const String& name,LiteRoot* pRoot):m_instanceName(name),m_pRoot(pRoot){}

		/** Destructor.
		*/
		virtual ~LiteRenderSystem(){}

		/** Returns the name of the rendering system.
		*/
		virtual const String& getTypeName(void) const = 0;

		inline const String& getName()const{ return m_instanceName; }

		/** 
		*/
		virtual RenderWindow* _createRenderWindow(const String &name, const NameValuePairList *miscParams = 0) = 0;


		void _updateAllRenderTargets(bool swapBuffers);
		//-----------------------------------------------------------------------
		void _swapAllRenderTargetBuffers();
	protected:
		/** The render targets. */
		RenderTargetMap mRenderTargets;
		/** The render targets, ordered by priority. */
		RenderTargetPriorityMap mPrioritisedRenderTargets;

		String m_instanceName;

		LiteRoot* m_pRoot;
	};
	/** @} */
	/** @} */
	class LiteRenderSystemFactory
	{
	public:
		virtual const String& getTypeName()const=0;
		virtual LiteRenderSystem* createInstance(const String& name, LiteRoot* root)=0;
	};


	

}



