#include "OgreStableHeaders.h"
#include "LiteRoot.h"
#include "LiteRenderSystem.h"
#include "OgreException.h"

using namespace Ogre;

LiteRenderSystem* Ogre::LiteRoot::createRenderSystem( const String& instanceName, const String& typeName )
{
	if (m_rsList.find(instanceName) != m_rsList.end())
	{
		OGRE_EXCEPT(Exception::ERR_DUPLICATE_ITEM, 
			"RenderSystem instance called '" + instanceName + "' already exists",
			"LiteRoot::createRenderSystem");
	}

	LiteRenderSystem* inst = 0;
	String name = instanceName;
	if (name.empty())
	{
		// generate a name
		StringUtil::StrStreamType s;
		s << "SceneManagerInstance" << mRSCreateCount;
		name = s.str();
	}

	// Iterate backwards to find the matching factory registered last
	for(RenderSystemFactoryList::reverse_iterator i = m_rsFactories.rbegin(); i != m_rsFactories.rend(); ++i)
	{
		LiteRenderSystemFactory* factory = *i;
		if (factory->getTypeName()==typeName)
		{
			inst = factory->createInstance(name, this);
			break;
		}
	}

	//// use default factory if none
	if(!inst)
	{
		OGRE_EXCEPT(Exception::ERR_INTERNAL_ERROR, 
			"can not create RenderSystem instance with Type is '" + typeName,
			"LiteRoot::createRenderSystem");
		return 0;
	}

	++mRSCreateCount;
	m_rsList[inst->getName()] = inst;

	return inst;
}

void Ogre::LiteRoot::addRenderSystemFactory( LiteRenderSystemFactory * newRSFactory )
{
	m_rsFactories.push_back(newRSFactory);
}




