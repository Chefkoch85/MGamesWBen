#include "MainGame.h"
#include <SDLopenGL_Engine/EngineError.h>
#include <SDLopenGL_Engine/ResourceManager.h>

#include <iostream>
#include <string>

void MainGame::initializeKeyMap() 
{
	m_keymap[SDLK_1] = CEGUI::Key::One;
	m_keymap[SDLK_2] = CEGUI::Key::Two;
	m_keymap[SDLK_3] = CEGUI::Key::Three;
	m_keymap[SDLK_4] = CEGUI::Key::Four;
	m_keymap[SDLK_5] = CEGUI::Key::Five;
	m_keymap[SDLK_6] = CEGUI::Key::Six;
	m_keymap[SDLK_7] = CEGUI::Key::Seven;
	m_keymap[SDLK_8] = CEGUI::Key::Eight;
	m_keymap[SDLK_9] = CEGUI::Key::Nine;
	m_keymap[SDLK_0] = CEGUI::Key::Zero;

	m_keymap[SDLK_q] = CEGUI::Key::Q;
	m_keymap[SDLK_w] = CEGUI::Key::W;
	m_keymap[SDLK_e] = CEGUI::Key::E;
	m_keymap[SDLK_r] = CEGUI::Key::R;
	m_keymap[SDLK_t] = CEGUI::Key::T;
	m_keymap[SDLK_y] = CEGUI::Key::Y;
	m_keymap[SDLK_u] = CEGUI::Key::U;
	m_keymap[SDLK_i] = CEGUI::Key::I;
	m_keymap[SDLK_o] = CEGUI::Key::O;
	m_keymap[SDLK_p] = CEGUI::Key::P;
	m_keymap[SDLK_a] = CEGUI::Key::A;
	m_keymap[SDLK_s] = CEGUI::Key::S;
	m_keymap[SDLK_d] = CEGUI::Key::D;
	m_keymap[SDLK_f] = CEGUI::Key::F;
	m_keymap[SDLK_g] = CEGUI::Key::G;
	m_keymap[SDLK_h] = CEGUI::Key::H;
	m_keymap[SDLK_j] = CEGUI::Key::J;
	m_keymap[SDLK_k] = CEGUI::Key::K;
	m_keymap[SDLK_l] = CEGUI::Key::L;
	m_keymap[SDLK_z] = CEGUI::Key::Z;
	m_keymap[SDLK_x] = CEGUI::Key::X;
	m_keymap[SDLK_c] = CEGUI::Key::C;
	m_keymap[SDLK_v] = CEGUI::Key::V;
	m_keymap[SDLK_b] = CEGUI::Key::B;
	m_keymap[SDLK_n] = CEGUI::Key::N;
	m_keymap[SDLK_m] = CEGUI::Key::M;

	m_keymap[SDLK_COMMA] = CEGUI::Key::Comma;
	m_keymap[SDLK_PERIOD] = CEGUI::Key::Period;
	m_keymap[SDLK_SLASH] = CEGUI::Key::Slash;
	m_keymap[SDLK_BACKSLASH] = CEGUI::Key::Backslash;
	m_keymap[SDLK_MINUS] = CEGUI::Key::Minus;
	m_keymap[SDLK_EQUALS] = CEGUI::Key::Equals;
	m_keymap[SDLK_SEMICOLON] = CEGUI::Key::Semicolon;
	m_keymap[SDLK_LEFTBRACKET] = CEGUI::Key::LeftBracket;
	m_keymap[SDLK_RIGHTBRACKET] = CEGUI::Key::RightBracket;
	m_keymap[SDLK_QUOTE] = CEGUI::Key::Apostrophe;
	m_keymap[SDLK_BACKQUOTE] = CEGUI::Key::Grave;

	m_keymap[SDLK_RETURN] = CEGUI::Key::Return;
	m_keymap[SDLK_SPACE] = CEGUI::Key::Space;
	m_keymap[SDLK_BACKSPACE] = CEGUI::Key::Backspace;
	m_keymap[SDLK_TAB] = CEGUI::Key::Tab;

	m_keymap[SDLK_ESCAPE] = CEGUI::Key::Escape;
	m_keymap[SDLK_PAUSE] = CEGUI::Key::Pause;
	m_keymap[SDLK_SYSREQ] = CEGUI::Key::SysRq;
	m_keymap[SDLK_POWER] = CEGUI::Key::Power;

	//m_keymap[SDLK_NUMLOCK] = CEGUI::Key::NumLock;
	//m_keymap[SDLK_SCROLLOCK] = CEGUI::Key::ScrollLock;

	m_keymap[SDLK_F1] = CEGUI::Key::F1;
	m_keymap[SDLK_F2] = CEGUI::Key::F2;
	m_keymap[SDLK_F3] = CEGUI::Key::F3;
	m_keymap[SDLK_F4] = CEGUI::Key::F4;
	m_keymap[SDLK_F5] = CEGUI::Key::F5;
	m_keymap[SDLK_F6] = CEGUI::Key::F6;
	m_keymap[SDLK_F7] = CEGUI::Key::F7;
	m_keymap[SDLK_F8] = CEGUI::Key::F8;
	m_keymap[SDLK_F9] = CEGUI::Key::F9;
	m_keymap[SDLK_F10] = CEGUI::Key::F10;
	m_keymap[SDLK_F11] = CEGUI::Key::F11;
	m_keymap[SDLK_F12] = CEGUI::Key::F12;
	m_keymap[SDLK_F13] = CEGUI::Key::F13;
	m_keymap[SDLK_F14] = CEGUI::Key::F14;
	m_keymap[SDLK_F15] = CEGUI::Key::F15;

	m_keymap[SDLK_LCTRL] = CEGUI::Key::LeftControl;
	m_keymap[SDLK_LALT] = CEGUI::Key::LeftAlt;
	m_keymap[SDLK_LSHIFT] = CEGUI::Key::LeftShift;
	//m_keymap[SDLK_LSUPER] = CEGUI::Key::LeftWindows;
	m_keymap[SDLK_RCTRL] = CEGUI::Key::RightControl;
	m_keymap[SDLK_RALT] = CEGUI::Key::RightAlt;
	m_keymap[SDLK_RSHIFT] = CEGUI::Key::RightShift;
	//m_keymap[SDLK_RSUPER] = CEGUI::Key::RightWindows;
	m_keymap[SDLK_MENU] = CEGUI::Key::AppMenu;

	m_keymap[SDLK_KP_0] = CEGUI::Key::Numpad0;
	m_keymap[SDLK_KP_1] = CEGUI::Key::Numpad1;
	m_keymap[SDLK_KP_2] = CEGUI::Key::Numpad2;
	m_keymap[SDLK_KP_3] = CEGUI::Key::Numpad3;
	m_keymap[SDLK_KP_4] = CEGUI::Key::Numpad4;
	m_keymap[SDLK_KP_5] = CEGUI::Key::Numpad5;
	m_keymap[SDLK_KP_6] = CEGUI::Key::Numpad6;
	m_keymap[SDLK_KP_7] = CEGUI::Key::Numpad7;
	m_keymap[SDLK_KP_8] = CEGUI::Key::Numpad8;
	m_keymap[SDLK_KP_9] = CEGUI::Key::Numpad9;
	m_keymap[SDLK_KP_PERIOD] = CEGUI::Key::Decimal;
	m_keymap[SDLK_KP_PLUS] = CEGUI::Key::Add;
	m_keymap[SDLK_KP_MINUS] = CEGUI::Key::Subtract;
	m_keymap[SDLK_KP_MULTIPLY] = CEGUI::Key::Multiply;
	m_keymap[SDLK_KP_DIVIDE] = CEGUI::Key::Divide;
	m_keymap[SDLK_KP_ENTER] = CEGUI::Key::NumpadEnter;

	m_keymap[SDLK_UP] = CEGUI::Key::ArrowUp;
	m_keymap[SDLK_LEFT] = CEGUI::Key::ArrowLeft;
	m_keymap[SDLK_RIGHT] = CEGUI::Key::ArrowRight;
	m_keymap[SDLK_DOWN] = CEGUI::Key::ArrowDown;

	m_keymap[SDLK_HOME] = CEGUI::Key::Home;
	m_keymap[SDLK_END] = CEGUI::Key::End;
	m_keymap[SDLK_PAGEUP] = CEGUI::Key::PageUp;
	m_keymap[SDLK_PAGEDOWN] = CEGUI::Key::PageDown;
	m_keymap[SDLK_INSERT] = CEGUI::Key::Insert;
	m_keymap[SDLK_DELETE] = CEGUI::Key::Delete;
}
void MainGame::handle_mouse_down(Uint8 button)
{
	switch (button)
	{
	case SDL_BUTTON_LEFT:
		mContext->injectMouseButtonDown(CEGUI::LeftButton);
		break;
	case SDL_BUTTON_MIDDLE:
		mContext->injectMouseButtonDown(CEGUI::MiddleButton);
		break;
	case SDL_BUTTON_RIGHT:
		mContext->injectMouseButtonDown(CEGUI::RightButton);
		break;

	//case SDL_BUTTON_WHEELDOWN:
	//	context.injectMouseWheelChange(-1);
	//	break;
	//case SDL_BUTTON_WHEELUP:
	//	context.injectMouseWheelChange(+1);
	//	break;
	}
}
void MainGame::handle_mouse_up(Uint8 button)
{
	CEGUI::GUIContext& context = CEGUI::System::getSingleton().getDefaultGUIContext();
	switch (button)
	{
	case SDL_BUTTON_LEFT:
		mContext->injectMouseButtonUp(CEGUI::LeftButton);
		break;
	case SDL_BUTTON_MIDDLE:
		mContext->injectMouseButtonUp(CEGUI::MiddleButton);
		break;
	case SDL_BUTTON_RIGHT:
		mContext->injectMouseButtonUp(CEGUI::RightButton);
		break;
	}
}

bool MainGame::CloseFrameWin(const CEGUI::EventArgs & args)
{
	printf("CloseFrameWin()\n");
	
	return false;
}

bool MainGame::ExitButtonClick(const CEGUI::EventArgs & args)
{
	printf("ExitButtonClick()\n");

	return false;
}

//Constructor, just initializes private member variables
MainGame::MainGame() : 
    _screenWidth(1024),
    _screenHeight(768), 
    _time(0.0f),
    _gameState(GameState::PLAY),
    _maxFPS(60.0f)
{
    _camera.init(_screenWidth, _screenHeight);
}

//Destructor
MainGame::~MainGame()
{
}

//This runs the game
void MainGame::run() 
{
    initSystems();

    //This only returns when the game ends
    gameLoop();

	shutdown();
}

//Initialize SDL and Opengl and whatever else we need
void MainGame::initSystems() 
{
    SDLopenGL::init();
	initializeKeyMap();

    _window.create("Game Engine", _screenWidth, _screenHeight, 0);

    initShaders();

    _spriteBatch.init();
    _fpsLimiter.init(SDLopenGL::FpsLimiter::SwapInterval::ONE, _maxFPS);

	// Bootstrap CEGUI::System with an OpenGL3Renderer object that uses the
	// current GL viewport, the DefaultResourceProvider, and the default
	// ImageCodec.
	//
	// NB: Your OpenGL context must already be initialised when you call this; CEGUI
	// will not create the OpenGL context itself. Nothing special has to be done to
	// choose between desktop OpenGL and OpenGL ES: the type is automatically
	// determined by the type of the current OpenGL context.
	mGuiRenderer = &CEGUI::OpenGL3Renderer::bootstrapSystem();

	// initialise the required dirs for the DefaultResourceProvider
	CEGUI::DefaultResourceProvider* rp = static_cast<CEGUI::DefaultResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider());
	rp->setResourceGroupDirectory("schemes", "GuiData/schemes");
	rp->setResourceGroupDirectory("imagesets", "GuiData/imagesets");
	rp->setResourceGroupDirectory("fonts", "GuiData/fonts");
	rp->setResourceGroupDirectory("layouts", "GuiData/layouts");
	rp->setResourceGroupDirectory("looknfeels", "GuiData/looknfeel");
	rp->setResourceGroupDirectory("lua_scripts", "GuiData/lua_scripts");

	// set the default resource groups to be used
	CEGUI::ImageManager::setImagesetDefaultResourceGroup("imagesets");
	CEGUI::Font::setDefaultResourceGroup("fonts");
	CEGUI::Scheme::setDefaultResourceGroup("schemes");
	CEGUI::WidgetLookManager::setDefaultResourceGroup("looknfeels");
	CEGUI::WindowManager::setDefaultResourceGroup("layouts");
	CEGUI::ScriptModule::setDefaultResourceGroup("lua_scripts");

	// create (load) the TaharezLook scheme file
	// (this auto-loads the TaharezLook looknfeel and imageset files)
	CEGUI::SchemeManager::getSingleton().createFromFile("TaharezLook.scheme");

	// create (load) a font.
	// The first font loaded automatically becomes the default font, but note
	// that the scheme might have already loaded a font, so there may already
	// be a default set - if we want the "DejaVuSans-10" font to definitely
	// be the default, we should set the default explicitly afterwards.
	CEGUI::FontManager::getSingleton().createFromFile("DejaVuSans-10.font"); 
	CEGUI::System::getSingleton().getDefaultGUIContext().setDefaultFont("DejaVuSans-10");
	CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().setDefaultImage("TaharezLook/MouseArrow");
	CEGUI::System::getSingleton().getDefaultGUIContext().setDefaultTooltipType("TaharezLook/Tooltip");

	CEGUI::WindowManager& wmgr = CEGUI::WindowManager::getSingleton();
	CEGUI::Window* myRoot = wmgr.createWindow("DefaultWindow", "root");
	CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(myRoot);
	CEGUI::FrameWindow* fWnd = static_cast<CEGUI::FrameWindow*>(wmgr.createWindow("TaharezLook/FrameWindow", "testWindow"));
	myRoot->addChild(fWnd);
	// position a quarter of the way in from the top-left of parent.
	fWnd->setPosition(CEGUI::UVector2(CEGUI::UDim(0.00f, 150.0f), CEGUI::UDim(0.0f, 10.0f)));
	// set size to be half the size of the parent
	fWnd->setSize(CEGUI::USize(CEGUI::UDim(0.0f, 200.0f), CEGUI::UDim(0.0f, 200.0f)));
	fWnd->setText("Hello World!");
	fWnd->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::SubscriberSlot(&MainGame::CloseFrameWin, this));

	mContext = &CEGUI::System::getSingleton().getDefaultGUIContext();

	CEGUI::PushButton* pBut = static_cast<CEGUI::PushButton*>(wmgr.createWindow("TaharezLook/Button", "ExitBut"));  // Create Window for button
	pBut->setPosition(CEGUI::UVector2(CEGUI::UDim(0.0, 500.0), CEGUI::UDim(0.0, 20.0)));
	pBut->setSize(CEGUI::USize(CEGUI::UDim(0, 50), CEGUI::UDim(0, 20)));
	pBut->setText("EXIT");
	pBut->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::SubscriberSlot(&MainGame::ExitButtonClick, this));
	myRoot->addChild(pBut);

	SDL_ShowCursor(0);
}

void MainGame::initShaders()
{
    _colorProgram.compileShaders("Shaders/ColorTexture.glvs", "Shaders/ColorTexture.glfs");
    _colorProgram.addAttribute("vertexPosition");
    _colorProgram.addAttribute("vertexColor");
    _colorProgram.addAttribute("vertexUV");
    _colorProgram.linkShaders();
}

void MainGame::shutdown()
{
	if (mGuiRenderer)
		CEGUI::OpenGL3Renderer::destroy(*mGuiRenderer);
}

//This is the main game loop for our program
void MainGame::gameLoop() 
{

    //Will loop until we set _gameState to EXIT
    while (_gameState != GameState::EXIT)
	{
       
        _fpsLimiter.begin();

        processInput();
        _time += 0.1f;

        _camera.update();

        // Update all bullets
        for (unsigned int i = 0; i < _bullets.size();)
		{
            if (_bullets[i].update() == true)
			{
                _bullets[i] = _bullets.back();
                _bullets.pop_back();
            } 
			else 
			{
                i++;
            }
        }

        drawGame();

        _fps = _fpsLimiter.end();

		static SDLopenGL::CTimer timer;
        if (timer.TimeOver(1000)) 
		{
			std::cout << SDLopenGL::string_format("FPS: %7.2f\n", _fps);
        }
    }
}

void MainGame::drawGui()
{	
	// make sure that before calling renderAllGUIContexts, that any bound textures
	// and shaders used to render the scene above are disabled using
	// glBindTexture(0) and glUseProgram(0) respectively also set
	// glActiveTexture(GL_TEXTURE_0) 
    // draw GUI
    // NB: When using the old desktop OpenGL 1.2 renderer, this call should not
    // occur between glBegin/glEnd calls.
	CEGUI::System::getSingleton().renderAllGUIContexts();
}

//Processes input with SDL
void MainGame::processInput() 
{
    SDL_Event evnt;

    const float CAMERA_SPEED = 2.0f;
    const float SCALE_SPEED = 0.1f;

    //Will keep looping until there are no more events to process
    while (SDL_PollEvent(&evnt)) 
	{
        switch (evnt.type) 
		{
            case SDL_QUIT:
                _gameState = GameState::EXIT;
                break;

            case SDL_MOUSEMOTION:
                _inputManager.setMouseCoords((float)evnt.motion.x, (float)evnt.motion.y);
				mContext->injectMousePosition((float)evnt.motion.x, (float)evnt.motion.y);
                break;

            case SDL_KEYDOWN:
                _inputManager.pressKey(evnt.key.keysym.sym);
				mContext->injectKeyDown(m_keymap[evnt.key.keysym.sym]);
                break;

            case SDL_KEYUP:
                _inputManager.releaseKey(evnt.key.keysym.sym);
				mContext->injectKeyUp(m_keymap[evnt.key.keysym.sym]);
                break;

            case SDL_MOUSEBUTTONDOWN:
                _inputManager.pressKey(evnt.button.button);
				handle_mouse_down(evnt.button.button);
                break;

            case SDL_MOUSEBUTTONUP:
                _inputManager.releaseKey(evnt.button.button);
				handle_mouse_up(evnt.button.button);
                break;
        }
    }

    if (_inputManager.isKeyPressed(SDLK_w)) 
	{
        _camera.setPosition(_camera.getPosition() + glm::vec2(0.0f, CAMERA_SPEED));
    }
    if (_inputManager.isKeyPressed(SDLK_s))
	{
        _camera.setPosition(_camera.getPosition() + glm::vec2(0.0f, -CAMERA_SPEED));
    }
    if (_inputManager.isKeyPressed(SDLK_a)) 
	{
        _camera.setPosition(_camera.getPosition() + glm::vec2(-CAMERA_SPEED, 0.0f));
    }
    if (_inputManager.isKeyPressed(SDLK_d)) 
	{
        _camera.setPosition(_camera.getPosition() + glm::vec2(CAMERA_SPEED, 0.0f));
    }
    if (_inputManager.isKeyPressed(SDLK_q))
	{
        _camera.setScale(_camera.getScale() + SCALE_SPEED);
    }
    if (_inputManager.isKeyPressed(SDLK_e))
	{
        _camera.setScale(_camera.getScale() - SCALE_SPEED);
    }

    if (_inputManager.isKeyPressed(SDL_BUTTON_LEFT)) 
	{
        glm::vec2 mouseCoords = _inputManager.getMouseCoords();
        mouseCoords = _camera.convertScreenToWorld(mouseCoords);
        
        glm::vec2 playerPosition(0.0f);
        glm::vec2 direction = mouseCoords - playerPosition;
        direction = glm::normalize(direction);

        _bullets.emplace_back(playerPosition, direction, 5.00f, 50);
    }
}

//Draws the game using the almighty OpenGL
void MainGame::drawGame() 
{
	// Enable alpha blend
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //Set the base depth to 1.0
    glClearDepth(1.0);
    //Clear the color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Enable the shader
    _colorProgram.use();

    //We are using texture unit 0
    glActiveTexture(GL_TEXTURE0);
    //Get the uniform location
    GLint textureLocation = _colorProgram.getUniformLocation("texData");
    //Tell the shader that the texture is in texture unit 0
    glUniform1i(textureLocation, 0);

    //Set the camera matrix
    GLint pLocation = _colorProgram.getUniformLocation("mVP");
    glm::mat4 cameraMatrix = _camera.getCameraMatrix();

    glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

    _spriteBatch.begin();

    glm::vec4 pos(0.0f, 0.0f, 50.0f, 50.0f);
    glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);
    static SDLopenGL::GLTexture texture = SDLopenGL::ResourceManager::getTexture("Textures/jimmyJump_pack/PNG/CharacterRight_Standing.png");
	SDLopenGL::Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;

    _spriteBatch.draw(pos, uv, texture.id, 0.0f, color);

    for (unsigned int i = 0; i < _bullets.size(); i++) 
	{
        _bullets[i].draw(_spriteBatch);
    }

    _spriteBatch.end();

    _spriteBatch.renderBatch();

    //unbind the texture
    glBindTexture(GL_TEXTURE_2D, 0);

    //disable the shader
    _colorProgram.unuse();

	drawGui();

    //Swap our buffer and draw everything to the screen!
    _window.swapBuffer();
}    