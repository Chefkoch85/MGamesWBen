#include "MainGame.h"
#include <SDLopenGL_Engine/EngineError.h>
#include <SDLopenGL_Engine/ResourceManager.h>

#include <iostream>
#include <string>

#include "MainGui.h"
#include "HudGui.h"


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

    _window.create("Game Engine", _screenWidth, _screenHeight, 0);

    initShaders();

    _spriteBatch.init();
    _fpsLimiter.init(SDLopenGL::FpsLimiter::SwapInterval::ONE, _maxFPS);


	mGuiMgr.Init("GuiData");
	GUISCENE_ID mainScene = mGuiMgr.AddScene(new CMainGui());
	GUISCENE_ID hudScene = mGuiMgr.AddScene(new CHudGui());
	mGuiMgr.SetActiveScene(mainScene);
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
	mGuiMgr.Destroy();
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
	mGuiMgr.Draw();
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
		mGuiMgr.Update(evnt);

        switch (evnt.type) 
		{
            case SDL_QUIT:
                _gameState = GameState::EXIT;
                break;

            case SDL_MOUSEMOTION:
                _inputManager.setMouseCoords((float)evnt.motion.x, (float)evnt.motion.y);
                break;

            case SDL_KEYDOWN:
                _inputManager.pressKey(evnt.key.keysym.sym);
                break;

            case SDL_KEYUP:
                _inputManager.releaseKey(evnt.key.keysym.sym);
                break;

            case SDL_MOUSEBUTTONDOWN:
                _inputManager.pressKey(evnt.button.button);
                break;

            case SDL_MOUSEBUTTONUP:
                _inputManager.releaseKey(evnt.button.button);
                break;
        }
    }

	static bool enter = false;
	if (_inputManager.isKeyPressed(SDLK_1) && !enter)
	{
		enter = true;
		mGuiMgr.SetActiveScene(0);
	}
	else if (_inputManager.isKeyPressed(SDLK_2) && !enter)
	{
		enter = true;
		mGuiMgr.SetActiveScene(1);
	}

	if (!_inputManager.isKeyPressed(SDLK_1) &&
		!_inputManager.isKeyPressed(SDLK_2))
	{
		enter = false;
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