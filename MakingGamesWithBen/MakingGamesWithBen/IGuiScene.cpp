#include "IGuiScene.h"



IGuiScene::IGuiScene()
{
}


IGuiScene::~IGuiScene()
{
}

void IGuiScene::CreateScene(const std::string & sheme, const std::string& font, bool mCursor)
{
	if (mIsInitialized)
		return;

	// create (load) the TaharezLook scheme file
	// (this auto-loads the TaharezLook looknfeel and imageset files)
	CEGUI::SchemeManager::getSingleton().createFromFile(sheme + ".scheme");

	// create (load) a font.
	// The first font loaded automatically becomes the default font, but note
	// that the scheme might have already loaded a font, so there may already
	// be a default set - if we want the "DejaVuSans-10" font to definitely
	// be the default, we should set the default explicitly afterwards.
	CEGUI::FontManager::getSingleton().createFromFile(font + ".font");
	CEGUI::System::getSingleton().getDefaultGUIContext().setDefaultFont(font);
	if (mCursor)
	{
		CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().setDefaultImage(sheme + "/MouseArrow");
		CEGUI::System::getSingleton().getDefaultGUIContext().setDefaultTooltipType(sheme + "/Tooltip");
	}

	mWinMgr = &CEGUI::WindowManager::getSingleton();
	mRoot = mWinMgr->createWindow("DefaultWindow", "root");
	CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(mRoot);

	mShemeName = sheme;

	mIsInitialized = true;
}

void IGuiScene::DestroyScene()
{
	for each (auto var in mGuiElems)
	{
		var.second->removeAllEvents();
	}
	mGuiElems.clear();
	mWinMgr->destroyAllWindows();
	mIsInitialized = false;
}

void IGuiScene::SubscribeEvent(const std::string & name, const CEGUI::String & evnt, CEGUI::SubscriberSlot subscriber)
{
	tGUI_MAP::iterator it = mGuiElems.find(name);

	if (it != mGuiElems.end())
	{
		try
		{
			it->second->subscribeEvent(evnt, subscriber);
		}
		catch (CEGUI::Exception ex)
		{
			printf("%s", ex.getMessage().c_str());
		}
	}
}

void IGuiScene::SetPosition(const std::string & name, glm::vec2 pos)
{
	tGUI_MAP::iterator it = mGuiElems.find(name);

	if (it != mGuiElems.end())
	{
		it->second->setPosition(CEGUI::UVector2(CEGUI::UDim(0.0, pos.x), CEGUI::UDim(0.0, pos.y)));
	}
}
void IGuiScene::SetSize(const std::string & name, glm::vec2 size)
{
	tGUI_MAP::iterator it = mGuiElems.find(name);

	if (it != mGuiElems.end())
	{
		it->second->setSize(CEGUI::USize(CEGUI::UDim(0, size.x), CEGUI::UDim(0, size.y)));
	}
}
void IGuiScene::SetText(const std::string & name, const std::string & text)
{
	tGUI_MAP::iterator it = mGuiElems.find(name);

	if (it != mGuiElems.end())
	{
		it->second->setText(text);
	}
}