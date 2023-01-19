#include <iostream>
#include <algorithm>
#include "game_magaramov.h"


bool comp(Player& a, Player &b) {
	return a.po < b.po;
}

int main()
{
	Game_Magaramov game(4);
	
	for (int year = 1; year <= 5; year++) {
		game.phase1();
		game.phase2();
		game.phase3();
		game.phase4();
		game.phase5();
		game.phase6();
		game.phase7();
		game.phase8();
	}

	std::vector<Player> win_players;
	int max_po = 0;

	for (int i = 0; i < game.players.size(); i++) {
		if (game.players[i].po > max_po) {
			win_players.clear();
			win_players.push_back(game.players[i]);
			max_po = game.players[i].po;
		}
		else if (game.players[i].po == max_po) {
			win_players.push_back(game.players[i]);
		}
	}

	std::vector<Player> players_copy = win_players;
	int max_resource = win_players[0].resource.gold +
		win_players[0].resource.tree +
		win_players[0].resource.rock;

	return 0;
}
