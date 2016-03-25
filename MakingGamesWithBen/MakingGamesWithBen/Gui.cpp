#include "Gui.h"



CGui::CGui()
{
}


CGui::~CGui()
{
}

CEGUI::Window*  CGui::CreatePushButton(const std::string& sheme, const std::string & name, const std::string& text, glm::vec4 bounds, CEGUI::Window * toRoot)
{
	CEGUI::WindowManager& winMgr = CEGUI::WindowManager::getSingleton();

	CEGUI::PushButton* pBut = static_cast<CEGUI::PushButton*>(winMgr.createWindow(sheme + "/Button", name));  // Create Window for button

	pBut->setPosition(CEGUI::UVector2(CEGUI::UDim(0.0, bounds.x), CEGUI::UDim(0.0, bounds.y)));

	pBut->setSize(CEGUI::USize(CEGUI::UDim(0, bounds.z), CEGUI::UDim(0, bounds.w)));

	pBut->setText(text);

	toRoot->addChild(pBut);

	return pBut;
}


