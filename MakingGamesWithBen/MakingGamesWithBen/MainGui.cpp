#include "MainGui.h"

#include "Gui.h"

CMainGui::CMainGui()
{
}


CMainGui::~CMainGui()
{
}

void CMainGui::Create()
{
	IGuiScene::CreateScene("TaharezLook", "DejaVuSans-10");
	mGuiElems.insert(std::make_pair("btnExit", CGui::CreatePushButton(mShemeName, "btnExit", "Exit Game", { 100.0f,100.0f, 125.0f, 50.0f }, mRoot)));
	IGuiScene::SubscribeEvent("btnExit", CEGUI::PushButton::EventClicked, CEGUI::SubscriberSlot(&CMainGui::ExitButtonClick, this));
}

void CMainGui::Destroy()
{
	IGuiScene::DestroyScene();
}

bool CMainGui::ExitButtonClick(const CEGUI::EventArgs & args)
{
	printf("ExitButtonClick()\n");


	return false;
}