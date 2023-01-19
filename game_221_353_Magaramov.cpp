#include <iostream>
#include <vector>

#include "game_magaramov.h"

Game_Magaramov::Game_Magaramov(int num_players)
{
	year = 1;
	phase = 1;
	players = std::vector<Player>(num_players);
}

void Game_Magaramov::phase1()
{
	phase = 2;
}

void Game_Magaramov::phase2()
{
	phase = 3;
}

void Game_Magaramov::phase3()
{
	phase = 4;
}

void Game_Magaramov::phase4()
{
	phase = 5;
}

void Game_Magaramov::phase5()
{
	phase = 6;
}

void Game_Magaramov::phase6()
{
	phase = 7;
}

void Game_Magaramov::phase7()
{
	phase = 8;
}

void Game_Magaramov::phase8()
{
	phase = 1;
	year++;
}

void defense_level(const char* enemy_name, int king_help, Player &player)
{
}
