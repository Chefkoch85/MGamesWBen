#pragma once

#include <SDL\SDL.h>
#include <CEGUI\CEGUI.h>
#include <GLM\glm.hpp>

#include <map>

class IGuiScene
{
public:
	IGuiScene();
	virtual ~IGuiScene();

	virtual void Create() = 0;
	virtual void Destroy() = 0;

protected:
	void CreateScene(const std::string& sheme, const std::string& font, bool mCursor = false);
	void DestroyScene();
	
	void SubscribeEvent(const std::string& name, const CEGUI::String& evnt, CEGUI::SubscriberSlot subscriber);

	void SetPosition(const std::string& name, glm::vec2 pos);
	void SetSize(const std::string& name, glm::vec2 size);
	void SetText(const std::string& name, const std::string& text);

protected:
	typedef std::map<const std::string, CEGUI::Window*> tGUI_MAP;
	bool mIsInitialized = false;
	CEGUI::WindowManager* mWinMgr = nullptr;
	CEGUI::Window* mRoot = nullptr;
	tGUI_MAP mGuiElems;
	std::string mShemeName;

};

