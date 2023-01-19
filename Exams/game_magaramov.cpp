#include <iostream>
#include <vector>
#include <algorithm>

#include "game_magaramov.h"

void Cubic::roll() {
	value = rand() % (max - min + 1) + min;
}

void Player::roll_cubices()
{
	std::cout << "Player " << name << " roll cubices:" << std::endl;

	for (int i = 0; i < 3; i++) {
		resource.cubic[i].roll();
		std::cout << "    Cubice " << i << ": " << resource.cubic[i].value << std::endl;
	}

	if (resource.has_cubic_white) {
		resource.cubic_white.roll();
		std::cout << "    White cubice: " << resource.cubic_white.value << std::endl;
	}
}

int Player::total_cubices()
{
	int res = 0;

	for (int i = 0; i < 3; i++) {
		res += resource.cubic[i].value;
	}

	if (resource.has_cubic_white) {
		res += resource.cubic_white.value;
	}

	return res;
}

Game_Magaramov::Game_Magaramov(int num_players)
{
	year = 1;
	phase = 1;
	players = std::vector<Player>(num_players);
}

void Game_Magaramov::phase1()
{
	int min_resources = INT_MAX;
	int min_building = INT_MAX;
	std::vector<int> min_players;

	for (int i = 0; i < players.size(); i++) {
		if (players[i].buildings.size() < min_building) {
			min_building = players[i].buildings.size();
			min_players.clear();
			min_players.push_back(i);
			min_resources = players[i].resource.goods.total();
		}
		else if (players[i].buildings.size() == min_building) {
			int total_res = players[i].resource.goods.total();
			if (total_res < min_resources) {
				min_resources = total_res;
				min_players.clear();
				min_players.push_back(i);
			}
			else if (total_res == min_resources) {
				min_players.push_back(i);
			}
		}
	}

	if (min_players.size() == 1) {
		int index = min_players[0];
		players[index].resource.has_cubic_white = true;
	}
	else {
		for (int i = 0; i < min_players.size(); i++) {
			int index = min_players[i];
			int res;

			std::cout << "    1. Gold" << std::endl;
			std::cout << "    2. Tree" << std::endl;
			std::cout << "    3. Rock" << std::endl;
			std::cout << "Player " << players[index].name << " select resource (1 - 3): ";
			std::cin >> res;
			if (res == 1) {
				players[index].resource.goods.gold++;
			}
			else if (res == 2) {
				players[index].resource.goods.wood++;
			}
			else if (res == 3) {
				players[index].resource.goods.stone++;
			}
			else {
				std::cout << "Invalid resource" << std::endl;
			}
		}
	}

	phase = 2;
}

void Game_Magaramov::phase3()
{
	int max_building = INT_MIN;
	std::vector<int> max_players;

	for (int i = 0; i < players.size(); i++) {
		if (players[i].buildings.size() > max_building) {
			max_building = players[i].buildings.size();
			max_players.clear();
			max_players.push_back(i);
		}
		else if (players[i].buildings.size() == max_building) {
			max_players.push_back(i);
		}
	}

	for (int i = 0; i < max_players.size(); i++) {
		int index = max_players[i];
		players[i].po++;
	}

	phase = 4;
}

void Game_Magaramov::phase5()
{
	int min_resources = INT_MAX;
	int min_building = INT_MAX;
	std::vector<int> min_players;

	for (int i = 0; i < players.size(); i++) {
		players[i].has_messenger = false;

		if (players[i].buildings.size() < min_building) {
			min_building = players[i].buildings.size();
			min_players.clear();
			min_players.push_back(i);
			min_resources = players[i].resource.goods.total();
		}
		else if (players[i].buildings.size() == min_building) {
			int total_res = players[i].resource.goods.total();
			if (total_res < min_resources) {
				min_resources = total_res;
				min_players.clear();
				min_players.push_back(i);
			}
			else if (total_res == min_resources) {
				min_players.push_back(i);
			}
		}
	}

	if (min_players.size() == 1) {
		int index = min_players[0];
		std::cout << "Player " << players[index].name << " got messenger token" << std::endl;
		players[index].has_messenger = true;
	}

	phase = 6;
}

void Game_Magaramov::phase7()
{
	for (int i = 0; i < players.size(); i++) {
		int total_res = players[i].resource.goods.total();

		if (total_res >= 2) {
			int military_num;
			std::cout << "Enter military num (maximum " << total_res / 2 << "): ";
			std::cin >> military_num;

			if (military_num > (total_res / 2)) {
				std::cout << "Invalid military num" << std::endl;
				return;
			}

			int gold = 0, wood = 0, stone = 0;
			std::cout << "Enter " << military_num * 2 << " resource:" << std::endl;

			if (players[i].resource.goods.gold) {
				std::cout << "Gold (" << players[i].resource.goods.gold << "): ";
				std::cin >> gold;
			}

			if (players[i].resource.goods.wood) {
				std::cout << "Wood (" << players[i].resource.goods.wood << "): ";
				std::cin >> wood;
			}

			if (players[i].resource.goods.stone) {
				std::cout << "Stone (" << players[i].resource.goods.stone << "): ";
				std::cin >> stone;
			}

			if ((gold + wood + stone) != (military_num * 2)) {
				std::cout << "Invalid resources" << std::endl;
				return;
			}

			players[i].resource.goods.gold -= gold;
			players[i].resource.goods.wood -= wood;
			players[i].resource.goods.stone -= stone;
		}
	}
	phase = 8;
}

bool player_cmp(Player& a, Player& b)
{
	return a.total_cubices() < b.total_cubices();
};

void Game_Magaramov::phase246_bones()
{
	for (int i = 0; i < players.size(); i++) {
		players[i].roll_cubices();
	}

	std::sort(players.begin(), players.end(), player_cmp);

	std::cout << "New player order:" << std::endl;
	for (int i = 0; i < players.size(); i++) {
		std::cout << "     " << i + 1 << ". " << players[i].name << std::endl;
	}
}

void Game_Magaramov::phase246_advisor()
{
}

void Game_Magaramov::select_good(Player &player, int num)
{
	for (int i = 0; i < num; i++) {
		int select;

		std::cout << "    1. Gold" << std::endl;
		std::cout << "    2. Wood" << std::endl;
		std::cout << "    3. Stone" << std::endl;

		std::cin >> select;
		if (select == 1) {
			player.resource.goods.gold++;
		}
		else if (select == 2) {
			player.resource.goods.wood++;
		}
		else if (select == 3) {
			player.resource.goods.stone++;
		}
	}
}
void Game_Magaramov::advisor_help(const char *advisor_name, Player &player)
{
	if (advisor_name == "jester") {
		player.po++;
	}
	else if (advisor_name == "squire") {
		player.resource.goods.gold++;
	}
	else if (advisor_name == "architect") {
		player.resource.goods.wood++;
	}
	else if (advisor_name == "merchant") {
		int select;

		std::cout << "Select:" << std::endl;
		std::cout << "    1. gold" << std::endl;
		std::cout << "    2. wood" << std::endl;
		std::cin >> select;

		if (select == 1) {
			player.resource.goods.gold++;
		} else {
			player.resource.goods.wood++;
		}
	}
	else if (advisor_name == "sergeant") {
		player.military++;
	}
	else if (advisor_name == "alchemist") {
		int select;

		std::cout << "Select good to exchange:" << std::endl;
		if (player.resource.goods.gold) {
			std::cout << "    1. Gold (available " << player.resource.goods.gold << std::endl;
		}

		if (player.resource.goods.wood) {
			std::cout << "    2. Wood (available " << player.resource.goods.wood << std::endl;
		}

		if (player.resource.goods.stone) {
			std::cout << "    3. Stone (available " << player.resource.goods.stone << std::endl;
		}

		std::cin >> select;
		if (select == 1) {
			player.resource.goods.gold--;
		}
		else if (select == 2) {
			player.resource.goods.wood--;
		}
		else if (select == 3) {
			player.resource.goods.stone--;
		}

		std::cout << "Select goods:" << std::endl;
		select_good(player, 2);
	}
	else if (advisor_name == "astronomer") {
		std::cout << "Select good:" << std::endl;
		select_good(player, 1);
	}
	else if (advisor_name == "treasurer") {
		player.resource.goods.gold += 2;
	}
	else if (advisor_name == "hunter") {
		int select;

		std::cout << "Select good:" << std::endl;
		std::cout << "    1. 1 wood and 1 gold" << std::endl;
		std::cout << "    2. 1 wood and 1 stone" << std::endl;

		std::cin >> select;
		if (select == 1) {
			player.resource.goods.gold++;
			player.resource.goods.wood++;
		}
		else if (select == 2) {
			player.resource.goods.wood++;
			player.resource.goods.stone++;
		}
	}
	else if (advisor_name == "general") {
		player.military += 2;
	}
	else if (advisor_name == "swordsmith") {
		int select;

		std::cout << "Select good:" << std::endl;
		std::cout << "    1. 1 wood and 1 stone" << std::endl;
		std::cout << "    2. 1 gold and 1 stone" << std::endl;

		std::cin >> select;
		if (select == 1) {
			player.resource.goods.stone++;
			player.resource.goods.wood++;
		}
		else if (select == 2) {
			player.resource.goods.gold++;
			player.resource.goods.stone++;
		}
	}
	else if (advisor_name == "duchess") {
		std::cout << "Select goods:" << std::endl;
		select_good(player, 2);
	}
	else if (advisor_name == "champion") {
		player.resource.goods.wood += 3;
	}
	else if (advisor_name == "smuggler") {
		std::cout << "Select goods:" << std::endl;
		select_good(player, 3);
		player.po--;
	}
	else if (advisor_name == "inventor") {
		player.resource.goods.gold++;
		player.resource.goods.wood++;
		player.resource.goods.stone++;
	}
	else if (advisor_name == "queen") {
		std::cout << "Select goods:" << std::endl;
		select_good(player, 2);
		player.po += 3;
	}
	else if (advisor_name == "King") {
		player.resource.goods.gold++;
		player.resource.goods.wood++;
		player.resource.goods.stone++;
		player.military++;
	}
}

void Game_Magaramov::building(const char *advisor_name, Player &player)
{
}

void Game_Magaramov::phase246()
{
	phase246_bones();
	phase246_advisor();

	for (int i = 0; i < players.size(); i++) {
		if (players[i].advisor.name.empty()) {
			advisor_help(players[i].advisor.name.c_str(), players[i]);
		}
	}

	for (int i = 0; i < players.size(); i++) {
		building(players[i].advisor.name.c_str(), players[i]);
	}
}

void Game_Magaramov::phase8()
{
	phase = 1;
	year++;
}

void defense_level(const char* enemy_name, int king_help, Player &player)
{
}
