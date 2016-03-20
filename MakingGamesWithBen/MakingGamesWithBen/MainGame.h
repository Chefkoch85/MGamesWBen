#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>

#include <SDLopenGL_Engine/SDLopenGL.h>
#include <SDLopenGL_Engine/GLSLProgram.h>
#include <SDLopenGL_Engine/GLTexture.h>
#include <SDLopenGL_Engine/Sprite.h>
#include <SDLopenGL_Engine/Window.h>
#include <SDLopenGL_Engine/InputManager.h>
#include <SDLopenGL_Engine/Timing.h>
#include <SDLopenGL_Engine/SpriteBatch.h>
#include <SDLopenGL_Engine/Camera2D.h>

#include <CEGUI\CEGUI.h>
#include <CEGUI\RendererModules\OpenGL\GL3Renderer.h>

#include "Bullet.h"

#include <vector>
#include <map>

enum class GameState {PLAY, EXIT};

//Our example game class, just for testing purposes right now
class MainGame
{
public:

    MainGame();
    ~MainGame();

    void run();

private:
    void initSystems();
    void initShaders();
	void shutdown();
    void gameLoop();
	void drawGui();
    void processInput();
	void drawGame();

	void initializeKeyMap();
	void handle_mouse_down(Uint8 button);
	void handle_mouse_up(Uint8 button);

    SDLopenGL::Window _window;
    int _screenWidth;
    int _screenHeight;
    GameState _gameState;

	SDLopenGL::GLSLProgram _colorProgram;
	SDLopenGL::Camera2D _camera;

	SDLopenGL::SpriteBatch _spriteBatch;

	SDLopenGL::InputManager _inputManager;
	SDLopenGL::FpsLimiter _fpsLimiter;

    std::vector<Bullet> _bullets;
    
    float _maxFPS;
    float _fps;
    float _time;

	std::map<SDL_Keycode, CEGUI::Key::Scan> m_keymap;
	CEGUI::OpenGL3Renderer* mGuiRenderer = nullptr;
	CEGUI::GUIContext* mContext = nullptr;

	bool CloseFrameWin(const CEGUI::EventArgs& args);
	bool ExitButtonClick(const CEGUI::EventArgs& args);
};

