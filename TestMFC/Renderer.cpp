#include "stdafx.h"
#include "Renderer.h"
#include "..\OgreLite\include\OgreRoot.h"
#include "..\OgreLite\LiteRoot.h"
#include "..\OgreLite\include\OgreRenderWindow.h"
#include "..\OgreLite\include\OgreManualObject.h"


using namespace Ogre;

bool Renderer::Init(HWND hwnd)
{

	Root* root = Root::getSingletonPtr();
	if(!root)
	{
		root = new Root();
		root->loadPlugin("RenderSystem_Direct3D9");
		root->setRenderSystem(root->getAvailableRenderers().front());
		root->initialise(false);
	}
	CString windowsName;
	windowsName.Format(_T("%d"),hwnd);
	NameValuePairList parms;
	//GetConfigOption(parms);
	parms["externalWindowHandle"] = StringConverter::toString((long)hwnd);	
	RenderWindow* window = root->createRenderWindow(windowsName.GetString(), 0,0, false, &parms);
	SceneManager* scene = root->createSceneManager(ST_GENERIC);

	ManualObject* pobj = scene->createManualObject();
	pobj->begin("",RenderOperation::OT_LINE_LIST);
	pobj->position(0,0,0);
	
	pobj->position(200,200,0);
	pobj->end();
	scene->getRootSceneNode()->attachObject(pobj);
	
	Camera* cam = scene->createCamera("main");
	cam->setPosition(0,0,10);
	cam->setOrthoWindow(100,100);
	cam->setNearClipDistance(1);
	cam->setFarClipDistance(100);
	Viewport* vp = window->addViewport(cam);
	
	return true;
}

bool Renderer::OnSize( HWND hwnd )
{
	CString windowsName;
	windowsName.Format(_T("%d"),hwnd);
	Root* root = Root::getSingletonPtr();
	if(!root)
		return true;

	RenderWindow* target  = (RenderWindow*)root->getRenderSystem()->getRenderTarget(windowsName.GetString());
	if(!target)
		return true;

	target->windowMovedOrResized();
	return true;
}

bool Renderer::Update( HWND hwnd )
{
	CString windowsName;
	windowsName.Format(_T("%d"),hwnd);
	Root* root = Root::getSingletonPtr();

	root->renderOneFrame(NULL);
	//RenderWindow* target  = (RenderWindow*)root->getRenderSystem()->getRenderTarget(windowsName.GetString());
	//target->update();
	return true;
}

bool Renderer::Destroy( HWND hwnd )
{
	CString windowsName;
	windowsName.Format(_T("%d"),hwnd);
	Root* root = Root::getSingletonPtr();
	root->getRenderSystem()->destroyRenderWindow(windowsName.GetString());
	if(!root->getRenderSystem()->getRenderTargetIterator().hasMoreElements())
	{
		 root->shutdown();
		 delete root;
	}
	return true;
}
