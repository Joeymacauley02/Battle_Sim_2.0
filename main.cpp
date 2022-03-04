/*
Name: Joey Macauley
Date: December 6, 2021
*/

#include "header.h"

int main(void)
{

	Player1 p1;
	Player2 p2;
	srand(time(0));
	char keepGoing = 'y';
	int turn = 1, randIndx = 0;
	bool hit1 = false, hit2 = false;
	string tempWep = "";
	int tempDmg = 0;

	// declare and initialize an instance of InheritedClass1 and InheritedClass2
	p1.initializePlayer("Xavi");
	p2.initializePlayer("Iniesta");

	// Initilaize Objects
	p1.fillInventory();
	p2.fillInventory();

	cout << "Filled the list...\nDemonstrating printing the list..." << endl;

	p1.displayAllItems();
	cout << "size: " << p1.size() << endl
		 << endl;

	p1.pop(tempWep, tempDmg);
	cout << "Demonstrating removing an item from the list..." << endl;
	p1.displayAllItems();
	cout << "size: " << p1.size() << endl;
	randIndx = rand() % 5;
	p1.push(possibleItems.at(randIndx).weaponName, possibleItems.at(randIndx).damage);

	// print out starting info
	cout << "\nWelcome to the battle area!\nToday we will see a battle between two Futbol Stars!" << endl;
	cout << "Our first participant is: \n"
		 << endl;
	p1.printPlayerClassInfo();
	cout << "\nAnd our second participant is: \n"
		 << endl;
	p2.printPlayerClassInfo();
	cout << "\nLet the battle begin!" << endl;

	while ((p1.getHealth() > 0) && (p2.getHealth() > 0))
	{

		cout << "\n|------- Turn " << turn << " ------- | " << endl;
		cout << p1.getName() << "'s Health: " << p1.getHealth() << " - " << p2.getName() << "'s Health: " << p2.getHealth() << endl;

		hit1 = p1.attackPlayerSuccess(p1, p2);
		hit2 = p2.attackPlayerSuccess(p2, p1);

		p1.pop(tempWep, tempDmg);
		if (hit1 == true)
		{
			cout << p1.getName() << " attacks " << p2.getName() << " with a " << tempWep << "! ... hits for " << tempDmg << "!" << endl;
			p2.setHealth(p2.getHealth() - tempDmg);
		}
		else
		{
			cout << p1.getName() << " attacks " << p2.getName() << " with a " << tempWep << "! ... misses!" << endl;
		}

		p2.pop(tempWep, tempDmg);
		if (hit2 == true)
		{
			cout << p2.getName() << " attacks " << p1.getName() << " with a " << tempWep << "! ... hits for " << tempDmg << "!" << endl;
			tempDmg = tempDmg * p2.getMultiplier();
			p1.setHealth(p1.getHealth() - tempDmg);
		}
		else
		{
			cout << p2.getName() << " attacks " << p1.getName() << " with a " << tempWep << "! ... misses!" << endl;
		}
		turn++;
	}

	cout << endl;
	if (p1.getHealth() > p2.getHealth())
	{
		cout << p1.getName() << " WINS!" << endl;
	}
	else
	{
		cout << p2.getName() << " WINS!" << endl;
	}

	cout << endl;
	p1.printPlayerInfo();
	p2.printPlayerInfo();

	return 0;
}