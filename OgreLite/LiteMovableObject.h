#pragma once

namespace Ogre
{
	class LiteMovableObject
	{
	public:
		/// Name of this object
		String mName;
		/// Creator of this object (if created by a factory)
		//MovableObjectFactory* mCreator;
		/// SceneManager holding this object (if applicable)
		//SceneManager* mManager;
		/// node to which this object is attached
		Node* mParentNode; 

	};


	
}

