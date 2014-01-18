#pragma once
#include "OgreNode.h"

namespace Ogre
{
	class LiteMovableObject;

	class _OgreExport LiteSceneNode : public Node
	{
	public:
		typedef HashMap<String, LiteMovableObject*> ObjectMap;
		typedef MapIterator<ObjectMap> ObjectIterator;
		typedef ConstMapIterator<ObjectMap> ConstObjectIterator;
	protected:
		 ObjectMap mObjectsByName;
	};

}