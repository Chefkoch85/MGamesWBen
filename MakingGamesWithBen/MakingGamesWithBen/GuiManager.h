#pragma once

#include <CEGUI\CEGUI.h>
#include <CEGUI\RendererModules\OpenGL\GL3Renderer.h>
#include <SDL\SDL.h>

#include <vector>

#include "IGuiScene.h"

typedef int GUISCENE_ID;
const GUISCENE_ID FIRST_ELEM = 0x0;
const GUISCENE_ID LAST_ELEM = 0x0FFFFFFF;

class CGuiManager
{
public:
	CGuiManager();
	~CGuiManager();

	void Init(const std::string& guiDataPath);
	void Destroy();
	void Update(const SDL_Event& sdlEvent, float dt = 0.016f);
	void Draw();

	GUISCENE_ID AddScene(IGuiScene* scene);

	GUISCENE_ID SetActiveScene(GUISCENE_ID index);

private:
	void CGuiManager::initializeKeyMap();
	void handle_mouse_down(Uint8 button);
	void handle_mouse_up(Uint8 button);

	std::map<SDL_Keycode, CEGUI::Key::Scan> m_keymap;
	CEGUI::OpenGL3Renderer* mGuiRenderer = nullptr;
	CEGUI::GUIContext* mContext = nullptr;

	std::vector<IGuiScene*> mGuiScenes;
	GUISCENE_ID mCurGuiScene = -1;

};

