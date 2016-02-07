#pragma once

namespace SDLopenGL
{
	class CTimer
	{
	public:
		bool TimeOver(int time);
		bool TimeOverOnce(int time);
		void Reset();

	private:
		unsigned int _messureTicksStart = 0;
		bool _finish = false;

	};



    ///Calculates FPS and also limits FPS
    class FpsLimiter 
	{
	public:
		enum class SwapInterval
		{
			IMMEDIATE = 0,
			ONE = 1,
			TWO = 2,
			THREE = 3,
			FOUR = 4,
		};

    public:
        FpsLimiter();

        // Initializes the FPS limiter. For now, this is
        // analogous to setMaxFPS
        void init(SwapInterval swap, float maxFPS = 0.0f);

        // Sets the desired max FPS
        void setMaxFPS(SwapInterval swap, float maxFPS = 0.0f);

        void begin();

        // end() will return the current FPS as a float
        float end();

    private:
        // Calculates the current FPS
        void calculateFPS();

        // Variables
        float _fps = 0.0f;
        float _maxFPS = 0.0f;
        float _frameTime = 0.0f;
        unsigned int _startTicks = 0;

    };

}