#include "Timing.h"

#include <SDL/SDL.h>

using namespace SDLopenGL;

FpsLimiter::FpsLimiter() 
{
}
void FpsLimiter::init(SwapInterval swap, float maxFPS)
{
    setMaxFPS(swap, maxFPS);
}

void FpsLimiter::setMaxFPS(SwapInterval swap, float maxFPS)
{
    _maxFPS = maxFPS;

	SDL_GL_SetSwapInterval((int)swap);

	if (swap != SwapInterval::IMMEDIATE)
		_maxFPS = 0.0f;
}

void FpsLimiter::begin()
{
    _startTicks = SDL_GetTicks();
}

float FpsLimiter::end() 
{
    calculateFPS();

    float frameTicks = SDL_GetTicks() - _startTicks;
    //Limit the FPS to the max FPS
	if (_maxFPS > 0.0f)
	{
		if (1000.0f / _maxFPS > frameTicks)
		{
			SDL_Delay((Uint32)(1000.0f / _maxFPS - frameTicks));
		}
	}

    return _fps;
}

bool SDLopenGL::CTimer::TimeOver(int time)
{
	if (_messureTicksStart <= 0)
		_messureTicksStart = SDL_GetTicks();

	if (_messureTicksStart + time <= SDL_GetTicks())
	{
		_messureTicksStart = 0;
		return true;
	}

	return false;
}

bool SDLopenGL::CTimer::TimeOverOnce(int time)
{
	if (_messureTicksStart <= 0)
		_messureTicksStart = SDL_GetTicks();

	if (!_finish && _messureTicksStart + time <= SDL_GetTicks())
	{
		_finish = true;
		return true;
	}

	return false;
}

void SDLopenGL::CTimer::Reset()
{
	_messureTicksStart = 0;
	_finish = false;
}

void FpsLimiter::calculateFPS()
{
    //The number of frames to average
    static const int NUM_SAMPLES = 10;
    //Stores all the frametimes for each frame that we will average
    static float frameTimes[NUM_SAMPLES];
    //The current frame we are on
    static int currentFrame = 0;
    //the ticks of the previous frame
    static float prevTicks = SDL_GetTicks();

    //Ticks for the current frame
    float currentTicks = SDL_GetTicks();

    //Calculate the number of ticks (ms) for this frame
    _frameTime = currentTicks - prevTicks;
    frameTimes[currentFrame % NUM_SAMPLES] = _frameTime;

    //current ticks is now previous ticks
    prevTicks = currentTicks;

    //The number of frames to average
    int count;

    currentFrame++;
    if (currentFrame < NUM_SAMPLES) 
	{
        count = currentFrame;
    } else
	{
        count = NUM_SAMPLES;
    }

    //Average all the frame times
    float frameTimeAverage = 0;
    for (int i = 0; i < count; i++) 
	{
        frameTimeAverage += frameTimes[i];
    }
    frameTimeAverage /= count;

    //Calculate FPS
    if (frameTimeAverage > 0) 
	{
        _fps = 1000.0f / frameTimeAverage;
    } else {
        _fps = 60.0f;
    }
}

