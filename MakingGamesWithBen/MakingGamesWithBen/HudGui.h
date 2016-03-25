#pragma once

#include "IGuiScene.h"

class CHudGui : public IGuiScene
{
public:
	CHudGui();
	~CHudGui();

	// Geerbt über IGuiScene
	virtual void Create() override;
	virtual void Destroy() override;

private:
	bool CHudGui::KillBtnClicked(const CEGUI::EventArgs & args);


};

