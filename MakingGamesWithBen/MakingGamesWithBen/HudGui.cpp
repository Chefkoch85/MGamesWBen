#include "HudGui.h"

#include "Gui.h"

CHudGui::CHudGui()
{
}


CHudGui::~CHudGui()
{
}

void CHudGui::Create()
{
	CreateScene("TaharezLook", "DejaVuSans-10");
	mGuiElems.insert(std::make_pair("btnKill", CGui::CreatePushButton(mShemeName, "btnKill", "Kill Enemy", { 200.0f,100.0f, 175.0f, 100.0f }, mRoot)));
	SubscribeEvent("btnKill", CEGUI::PushButton::EventClicked, CEGUI::SubscriberSlot(&CHudGui::KillBtnClicked, this));
}

void CHudGui::Destroy()
{
	DestroyScene();
}

bool CHudGui::KillBtnClicked(const CEGUI::EventArgs & args)
{
	printf("KillBtnClicked()\n");


	return false;
}