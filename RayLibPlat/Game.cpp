#include "Game.h"
#include "Tile.h"
#include "Character.h"

Game::Game()
{
	InitWindow(screenWidth, screenHeight, "Plat");
    SetTargetFPS(30);
    player = new Player({ 50,50 }, 70);
}

Game::~Game()
{
}

void Game::InitGame()
{
	playerPos = { (float)screenWidth / 2,(float)screenWidth / 2 };
    for (int i = 0; i < 50; i++)
    {
        map.push_back(new Brick(i * 25, 425, 25));
    }

    //DOWN-WALL
    for (int i = 0; i < 50; i++)
    {
        map.push_back(new Wall(i * 25, 575, 25));
    }

    //UP-WALL
    for (int i = 0; i < 50; i++)
    {
        map.push_back(new Wall(i * 25, 0, 25));
    }

    //LEFT-WALL
    for (int i = 0; i < 50; i++)
    {
        map.push_back(new Wall(775, i * 25, 25));
    }

    //RIGHT-WALL
    for (int i = 0; i < 50; i++)
    {
        map.push_back(new Wall(0, i * 25, 25));
    }

    //Stair
    for (int i = 0; i < 50; i++)
    {
        map.push_back(new Stair(200, i * 6, 90));
    }

}

void Game::Update()
{
    
}

void Game::Draw()
{
    BeginDrawing();

    ClearBackground(DARKBLUE);

    DrawText("Ball Moving", 10, 10, 25, BLACK);
    
    player->Update();
    player->Draw();

    
    for (auto i : map) //auto checa que tipo de variable es y la guarda
    {
        player->Collision(*i);
        i->Draw();
    }

    EndDrawing();
}
