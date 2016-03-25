#pragma once

#include "IGuiScene.h"

class CMainGui : public IGuiScene
{
public:
	CMainGui();
	~CMainGui();

	// Geerbt �ber IGuiScene
	virtual void Create() override;
	virtual void Destroy() override;

private:
	bool ExitButtonClick(const CEGUI::EventArgs & args);

};

