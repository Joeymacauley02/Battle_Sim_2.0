/*
Name: Joey Macauley
Date: December 6, 2021
*/

#include "header.h"

int Player::numPlayers = 0;
vector<int> Player::playerIds;

/*************************************************************
 * Function: PlayerInventory()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: Constructor for inventory class
 * Input parameters: void
 * Returns: void
 **************************************************************/
PlayerInventory::PlayerInventory()
{
	top = nullptr;
	temp = top;
}

/*************************************************************
 * Function: ~PlayerInventory()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: Deconstructor for inventory class
 * Input parameters: void
 * Returns: void
 **************************************************************/
PlayerInventory::~PlayerInventory()
{
	WeaponNode *nodePtr = top;
	WeaponNode *nextPtr = nullptr;

	while (nodePtr != nullptr)
	{
		nextPtr = nodePtr->next;
		delete nodePtr;
		nodePtr = nextPtr;
	}
}

/*************************************************************
 * Function: push()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: Add an item to a stack linked list
 * Input parameters: string weapon, int damage
 * Returns: void
 **************************************************************/
void PlayerInventory::push(string weapon, int damage)
{
	WeaponNode *newNode = new WeaponNode;

	newNode->weaponName = weapon;
	newNode->weaponDamage = damage;

	if (empty())
	{
		top = newNode;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}
	temp = top;
}

/*************************************************************
 * Function: pop()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: Remove item from stack linked list
 * Input parameters: string& weaponName, int& damage
 * Returns: void
 **************************************************************/
void PlayerInventory::pop(string &weaponName, int &damage)
{
	WeaponNode *hold = nullptr;
	if (empty())
	{
		cout << "No Items Remain." << endl;
	}
	else
	{
		weaponName = top->weaponName;
		damage = top->weaponDamage;
		hold = top->next;
		delete top;
		top = hold;
	}
	temp = top;
}

/*************************************************************
 * Function: displayAllItems()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: Display the data in each node of the linked list
 * Input parameters: void
 * Returns: void
 **************************************************************/
void PlayerInventory::displayAllItems()
{
	WeaponNode *nodePtr = temp;
	if (nodePtr != nullptr)
	{
		cout << "Weapon: " << nodePtr->weaponName << " - Damage: " << nodePtr->weaponDamage << endl;
		temp = nodePtr->next;
		displayAllItems();
	}
}

/*************************************************************
 * Function: empty()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: Check to see if link list has any elements
 * Input parameters: void
 * Returns: void
 **************************************************************/
bool PlayerInventory::empty(void)
{
	if (!top)
	{
		return true;
	}
	return false;
}

/*************************************************************
 * Function: size()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: return the number of elements in a linked list
 * Input parameters: void
 * Returns: void
 **************************************************************/
int PlayerInventory::size(void)
{
	int numWeapons = 0;
	WeaponNode *nodePtr = top;
	while (nodePtr != nullptr)
	{
		numWeapons++;
		nodePtr = nodePtr->next;
	}
	return numWeapons;
}

/*************************************************************
 * Function: fillInventory()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: add elements in inventory object from global vector
 * Input parameters: void
 * Returns: void
 **************************************************************/
void PlayerInventory::fillInventory()
{
	int randI = 0;
	for (int i = 0; i < 10; i++)
	{
		randI = rand() % 5;
		push(possibleItems.at(randI).weaponName, possibleItems.at(randI).damage);
	}
	temp = top;
}

/*************************************************************
 * Function: generateRandomStat()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: generate a random number between min and max values
 * Input parameters: int min, int max
 * Returns: void
 **************************************************************/
int Player::generateRandomStat(int min, int max) const
{
	int randStat = 0;
	randStat = rand() % max + min;
	return randStat;
}

/*************************************************************
 * Function: playerIdIsInList()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description:n Determine if an id is already chosen
 * Input parameters: int id
 * Returns: void
 **************************************************************/
bool Player::playerIdIsInList(int id)
{
	bool inList = false;

	if (playerIds.size() == 0)
	{
		inList = false;
	}
	else
	{
		for (int i = 0; i < playerIds.size(); i++)
		{
			if (id == playerIds.at(i))
			{
				inList = true;
				return inList;
			}
		}
	}
	return inList;
}

/*************************************************************
 * Function: generatePlayerId()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: generated a random id number
 * Input parameters: void
 * Returns: void
 **************************************************************/
int Player::generatePlayerId(void) const
{
	int randId = 0;
	randId = rand() % 1000 + 1;
	while (playerIdIsInList(randId))
	{
		randId = rand() % 1000 + 1;
	}
	playerIds.push_back(randId);
	return randId;
}

/*************************************************************
 * Function: ~Player()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: Player deconstructor
 * Input parameters: void
 * Returns: void
 **************************************************************/
Player::~Player()
{
}

/*************************************************************
 * Function: ~initializePlayer()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: initialize an objects value of a player class
 * Input parameters: void
 * Returns: void
 **************************************************************/
void Player1::initializePlayer(string newName)
{
	this->name = newName;
	this->playerId = generatePlayerId();
	this->health = generateRandomStat(50, 150);
	this->experience = 0;
	this->mana = generateRandomStat(25, 75);
}

/*************************************************************
 * Function: printPlayerClassInfo()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: output information for an initialized object
 * Input parameters: void
 * Returns: void
 **************************************************************/
void Player1::printPlayerClassInfo(void) const
{
	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>|PID: " << this->getPlayerId() << "|" << endl;
	cout << ">> " << this->getName() << "'s info" << endl;
	cout << "Health: " << this->getHealth() << endl;
	cout << "Experience: " << this->getExperience() << endl;
	cout << "---------------------------------" << endl;
	cout << "Class: " << this->getClass() << endl;
	cout << "Mana: " << this->getMana() << endl;
	cout << "_________________________________" << endl;
}

/*************************************************************
 * Function: ~Player1()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: Class deconstructor
 * Input parameters: void
 * Returns: void
 **************************************************************/
Player1::~Player1()
{
}

/*************************************************************
 * Function: ~initializePlayer()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: initialize an objects value of a player class
 * Input parameters: void
 * Returns: void
 **************************************************************/
void Player2::initializePlayer(string newName)
{
	this->name = newName;
	this->playerId = generatePlayerId();
	this->health = generateRandomStat(50, 150);
	this->experience = 0;
	this->mana = generateRandomStat(25, 75);
	this->specialization = "Super-Smash";
}

/*************************************************************
 * Function: printPlayerClassInfo()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: output information for an initialized object
 * Input parameters: void
 * Returns: void
 **************************************************************/
void Player2::printPlayerClassInfo(void) const
{
	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>|PID: " << this->getPlayerId() << "|" << endl;
	cout << ">> " << this->getName() << "'s info" << endl;
	cout << "Health: " << this->getHealth() << endl;
	cout << "Experience: " << this->getExperience() << endl;
	cout << "---------------------------------" << endl;
	cout << "Class: " << this->getClass() << endl;
	cout << "Mana: " << this->getMana() << endl;
	cout << "Specialization: " << this->getSpecialization() << endl;
	cout << "Damage: " << fixed << setprecision(1) << this->getMultiplier() << endl;
	cout << "_________________________________" << endl;
}

/*************************************************************
 * Function: ~Player2()
 * Date Created: December 4, 2021
 * Date Last Modified: December 6, 2021
 * Description: Class deconstructor
 * Input parameters: void
 * Returns: void
 **************************************************************/
Player2::~Player2()
{
}
