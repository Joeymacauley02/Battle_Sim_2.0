/*
Name: Joey Macauley
Date: December 6, 2021
*/

#ifndef BATTLE_PVC
#define BATTLE_PVC

#include <iostream> //need for IO
#include <string>	//need for string data type and member functions
#include <cstdlib>	//need for random
#include <ctime>	//need for random
#include <vector>	//need for vector data type
#include <iomanip>	//need to format output

using namespace std;

// Upper limit on number of playerIds generated
const int MAX_ID_VALUE = 1000;

// Populate possibleItems.
struct InventoryItem
{
	string weaponName;
	int damage;
};

// Global CONSTANT variable.
const vector<InventoryItem> possibleItems{
	{"Baseball Bat", 20},
	{"Hockey Stick", 15},
	{"Tennis Racquets", 10},
	{"Golf Club", 5},
	{"Shoe", 1}};

// Inventory Class
class PlayerInventory
{
protected:
	struct WeaponNode
	{
		string weaponName = "";
		int weaponDamage = 0;
		WeaponNode *next = nullptr;
	};
	WeaponNode *top;
	WeaponNode *temp;

public:
	PlayerInventory();
	~PlayerInventory();

	void push(string, int);
	void pop(string &, int &);
	void displayAllItems();
	bool empty(void);
	int size(void);
	void fillInventory();
};

// Abstract Base Class
class Player
{
private:
	// static member variable keeping track of the number of players generated
	static int numPlayers;
	// static list of playerIds generated.
	// used to make sure no players have the same id
	static vector<int> playerIds;

protected:
	string subclass;
	string name;
	int playerId;
	int health;
	int experience;

	double multiplier; // damage multiplier. This should vary depending on class

	// Inventory is the name of your doubly linked list, stack linked list, or queue linked list class
	PlayerInventory playerInventory;

	// mutator/setter for player id
	void setPlayerId(int id) { playerId = id; }

	// used to generate a random stat value between min and max, e.g., 50 and 150
	// used when initializing player stats
	int generateRandomStat(int min, int max) const;

	// checks if an id is already in the playerIds vector.
	static bool playerIdIsInList(int id);

	// generates a UNIQUE player id. player id can be between 1 and MAX_ID_VALUE
	// if number generated is in playerIds, generate again otherwise, add to
	// playerIds vector (to keep track of id generated) and return value to be
	// used in initialization
	int generatePlayerId(void) const;

public:
	// Default constructor
	Player()
	{
		subclass = "Player";
		name = "";
		playerId = -1;
		health = -1;
		experience = 0;
		multiplier = 1.0;

		numPlayers++;
	}

	// Destructor
	~Player();

	// accessors/getters and mutators/setters
	void setName(string newName) { name = newName; }
	string getName(void) const { return name; };
	void setHealth(int h) { health = h; }
	int getHealth(void) const { return health; }
	int getPlayerId(void) const { return playerId; }
	void setExperience(int exp) { experience = exp; }
	int getExperience(void) const { return experience; }
	string getClass(void) const { return subclass; }

	// Pure Virtual Functions
	// initializes a player of given name with randomly allocated stats
	virtual void initializePlayer(string newName) = 0;
	virtual void printPlayerClassInfo(void) const = 0;

	// Virtual Functions
	virtual double getMultiplier(void) { return multiplier; }
	const

		virtual void
		printPlayerInfo(void) final
	{
		string skull = "\n    _____\n   /     \\\n  | () () |\n   \\  ^  /\n    |||||\n";
		string tombstone = "\n       ,-=-.\n      /  +  \\\n      | ~~~ |\n      |R.I.P|\n      |_____| \n";

		string healthValue = this->health > 0 ? to_string(this->health) : tombstone; //"~RIP~"
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>|PID:" << this->playerId << "|" << endl;
		cout << ">>" << this->name << "'s info" << endl;
		cout << "Health: " << healthValue << endl;
		cout << "Experience: " << this->experience << endl;
		cout << "---------------------------------" << endl;
		cout << "Class: " << this->subclass << endl;
		printPlayerClassInfo();
		cout << "_________________________________" << endl;
		cout << endl;
	}

	/*************************************************************
	 * Function: printBattleCard()
	 * Date Created: December 4, 2021
	 * Date Last Modified: December 6, 2021
	 * Description: Output header for each round during the battle
	 * Input parameters: void
	 * Returns: void
	 **************************************************************/
	template <class T1, class T2>
	static void printBattleCard(T1 p1, T2 p2, int turn)
	{
		/*cout << "|------- Turn " << turn << " ------- | " << endl;
		cout << p1.name << "'s Health: " << p1.health << " - " << p2.name << "'s Health: " << p2.health << endl;*/

		cout << "\n|------- Turn " << turn << " ------- | " << endl;
		cout << p1.getName() << "'s Health: " << p1.getHealth() << " - " << p2.getName() << "'s Health: " << p2.getHealth() << endl;
	};

	/*************************************************************
	 * Function: attackPlayerSuccess()
	 * Date Created: December 4, 2021
	 * Date Last Modified: December 6, 2021
	 * Description: Determine if a player has a successful hit or not
	 * Input parameters: void
	 * Returns: void
	 **************************************************************/
	template <class T1, class T2>
	bool attackPlayerSuccess(T1 &p1, const T2 &p2)
	{
		int hitPercent = 0, randi = 0;
		hitPercent = rand() % 3;

		if (hitPercent == 0 || hitPercent == 2)
		{
			p1.experience = p1.experience + 20;
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Player1 : public Player, public PlayerInventory
{
private:
protected:
	int mana;
	int totalDamage;
	PlayerInventory playerInventory;
	PlayerInventory *top;

public:
	Player1()
	{
		subclass = "Player";
		name = "";
		playerId = -1;
		health = -1;
		experience = 0;
		mana = -1;
	}

	void setMana(int h) { health = h; }
	int getMana(void) const { return mana; }
	virtual void initializePlayer(string newName);
	virtual void printPlayerClassInfo(void) const;

	// Destructor
	~Player1();
};

class Player2 : public Player1
{
private:
	string specialization;
	PlayerInventory *top;

protected:
	PlayerInventory playerInventory;

public:
	Player2()
	{
		subclass = "Player";
		name = "";
		playerId = -1;
		health = -1;
		experience = 0;
		specialization = "";
		multiplier = 2.0;
		mana = -1;
	}

	string getSpecialization(void) const { return specialization; }
	double getMultiplier(void) const { return multiplier; }
	virtual void initializePlayer(string newName);
	virtual void printPlayerClassInfo(void) const;

	// Destructor
	~Player2();
};

#endif