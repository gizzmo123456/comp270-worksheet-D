#pragma once
#include "Player.h"
#include "Drifter.h"

class Application
{
public:
	Application();
	~Application();

	bool run();

private:
	bool initSDL();
	void shutdownSDL();

	void processEvent(const SDL_Event &e);
	void setupScene();
	void update();
	void render();

	void shoot(float speed);
	void spawnAsteroid(Point2D pos, Vector2D vel, float maxScale, bool usePool = true);
	bool isOffscreen(const Drifter* drifter) const;

	const int c_windowWidth = 800;
	const int c_windowHeight = 700;

	// Ship controles settings
	const float c_shipRotateSpeed = 0.1f;
	const float c_shipThrust = 0.5f;
	const float c_shipShootVelocity = 0.5f;

	// Asteroid generation settings
	const int c_spawnRate = 1;				// Likelihood of a new asteroid being spawned each update
	const int c_numInitialAsteriods = 10;	// Number of asteroids when the game starts
	const float c_asteroidMinScale = 5.0f;	// min size for asteroid
	const float c_asteroidMaxScale = 20.0f;	// Size limit for each asteroid
	const float c_asteroidMaxRotationSpeed = 0.01f;	// Angular speed limit
	const int c_maxFragments = 5;			// Maximum number of new asteroids created when one is destroyed

	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;

	// Game objects
	Player m_player;
	std::vector<Bullet> m_bullets;
	std::vector<Asteroid> m_asteroids;

	bool m_quit = false;

	// Debuging and preformance testing options
	void debugUpdate();

	const bool c_debuging = true;

	const int c_debug_numInitialAsteriods = 1000;	// why not :)
	const int c_debug_bulletsToFire = 150;
	const bool c_fireOneRound = false;

	int m_debug_bulletsFired = 0;
	bool m_debug_fireringRest = false;

	

};
