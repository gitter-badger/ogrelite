#include "OgreStableHeaders.h"
#include "LiteRenderSystem.h"

void Ogre::LiteRenderSystem::_updateAllRenderTargets( bool swapBuffers )
{
	// Update all in order of priority
	// This ensures render-to-texture targets get updated before render windows
	RenderTargetPriorityMap::iterator itarg, itargend;
	itargend = mPrioritisedRenderTargets.end();
	for( itarg = mPrioritisedRenderTargets.begin(); itarg != itargend; ++itarg )
	{
		if( itarg->second->isActive() && itarg->second->isAutoUpdated())
			itarg->second->update(swapBuffers);
	}
}

void Ogre::LiteRenderSystem::_swapAllRenderTargetBuffers()
{
	// Update all in order of priority
	// This ensures render-to-texture targets get updated before render windows
	RenderTargetPriorityMap::iterator itarg, itargend;
	itargend = mPrioritisedRenderTargets.end();
	for( itarg = mPrioritisedRenderTargets.begin(); itarg != itargend; ++itarg )
	{
		if( itarg->second->isActive() && itarg->second->isAutoUpdated())
			itarg->second->swapBuffers();
	}
}
