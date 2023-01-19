#include <iostream>
#include <vector>

class Advisor {
public:
	std::string name;
	std::string player_name;

};

class Building {
public:
	std::string name;
};

class Goods {
public:
	int gold;
	int wood;
	int stone;

	int total() {
		return gold + wood + stone;
	}
};

class Cubic {
public:
	int min;
	int max;
	int value;

	Cubic() {
		min = 1;
		max = 6;
		value = min;
	}

	Cubic(int min_in, int max_in) {
		min = min_in;
		max = max_in;
		value = min;
	}

	void roll();
};

class Resource {
public:
	Goods goods;
	int tokens;
	Cubic cubic[3];
	Cubic cubic_white;
	bool has_cubic_white;
};

class Player {
public:
	std::string name;
	Resource resource;
	std::vector<Building> buildings;
	Advisor advisor;
	bool has_messenger;
	int po;
	int military;

	void roll_cubices();
	int total_cubices();
};

class Enemy {
public:
	std::string name;
	int force;
	int lost_po;
	Goods lost_goods;
	int got_po;
	int got_goods;
};

class Game_Magaramov {
public:
	Game_Magaramov(int num_players);
	void phase1();
	void phase3();
	void phase5();
	void phase7();
	void phase8();
	void phase246();

	std::vector<Player> players;
	std::vector<Advisor> advisors;
	int year;
	int phase;
	Enemy enemy;

private:
	void phase246_bones();
	void phase246_advisor();
	void advisor_help(const char *advisor_name, Player &player);
	void building(const char *advisor_name, Player &player);
	void select_good(Player &player, int num);
};
