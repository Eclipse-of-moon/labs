#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include "game_magaramov.h"

int main()
{
	int players_num;

	srand(time(NULL));

	std::cout << "Enter players num (2-5): ";
	std::cin >> players_num;

	if (players_num < 2 || players_num > 5) {
		std::cout << "Invalid players num" << std::endl;
		return 0;
	}

	Game_Magaramov game(players_num);

	for (int i = 0; i < game.players.size(); i++) {
		std::cout << "Enter player " << i + 1 << " name: ";
		std::cin >> game.players[i].name;
	}
	
	for (int year = 1; year <= 5; year++) {
		game.phase1();
		game.phase246();
		game.phase3();
		game.phase246();
		game.phase5();
		game.phase246();
		game.phase7();
		game.phase8();
	}

	std::vector<Player> win_players;
	int max_po = INT_MIN;

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
	int max_resource = INT_MIN;

	for (int i = 0; i < players_copy.size(); i++) {
		int total = players_copy[i].resource.goods.total();

		if (total > max_resource) {
			win_players.clear();
			win_players.push_back(players_copy[i]);
			max_resource = total;
		}
		else if (total == max_resource) {
			win_players.push_back(players_copy[i]);
		}
	}

	players_copy = win_players;
	int max_building = INT_MIN;

	for (int i = 0; i < players_copy.size(); i++) {

		if (players_copy[i].buildings.size() > max_building) {
			win_players.clear();
			win_players.push_back(players_copy[i]);
			max_building = players_copy[i].buildings.size();
		}
		else if (players_copy[i].buildings.size() == max_building) {
			win_players.push_back(players_copy[i]);
		}
	}

	std::cout << "Win players:" << std::endl;
	for (int i = 0; i < win_players.size(); i++) {
		std::cout << "    " << win_players[i].name << std::endl;
	}

	return 0;
}
