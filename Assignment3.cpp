#include <string>
#include <istream>
#include <time.h>
#include <iostream>
using namespace std;

//Class

class Fighters
{
	private:
		int HP;						//Health for characters
		string Name;				//Will hold player input for name
		
	public:
		Fighters(int);				//Constructor to set health
		void setHP(int);			//Sets HP in private class; mutator
		int getHP();				//Returns HP from private class; acessor 
		void setName(string);		//Sets Name in private clas; mutator
		string getName();			//Gets Name from private class; acessor

		int Weaponattack();			//Player attack sequence
		int Attack();				//Enemy attack sequence
		void takeDamage(int);		//Damage taken for each character
		struct Bag					//Struct for bag, holds true/false flag for when sword is found
		{
			bool hasSword;
		};
};

//*********************//
//Class implementations//
//*********************//

Fighters::Bag Sword;					//Makes Sword variable out of struct bool

Fighters::Fighters(int Health)			//Set int health in constructor
{
	HP = Health;
}

void Fighters::setHP(int Health)		//Sets HP in private class
{
	HP = Health;
}

int Fighters::getHP()					//Returns HP from private class
{
	return HP;
}

void Fighters::setName(string userName)	//Sets name in private class	
{
	Name = userName;
}

string Fighters::getName()				//Returns name from private class
{
	return Name;
}

int Fighters::Weaponattack()			//Player attack sequence; returns roll from 5-10; if sword is found multiplies attacks by 3
{
	int lowest = 5;
	int highest = 10;
	int roll;
	Sword.hasSword;
	
	roll =(rand() % (highest - lowest + 1)) + lowest;
	
	if (Sword.hasSword == false)
	{
		return roll;
	}
	else if (Sword.hasSword == true)
	{
		return roll * 3;
	}

}

int Fighters::Attack()					//Enemy attack sequence;  returns roll from 10-15; 13 and 15 registering as miss
{
	int lowest = 10;
	int highest = 15;
	int roll;

	roll = (rand() % (highest - lowest + 1)) + lowest;
	if (roll == 13 || roll == 15)
	{
		roll = 0;
	}
	return roll;
}

void Fighters::takeDamage(int damage)	//To display and adjust health based on damage taken
{
	HP = HP - damage;
}
					




void Startgame();						//Function prototype to start the game

//Main 
int main()
{
	int choice;												//Holds player choice to start game
	cout << "Hello Player" << endl;
	cout << "1)Play Game\n" << "2)Exit Game" << endl;		//Main menu
	cin >> choice;											//Asks user to pick start game or exit game

	if (choice == 2)
	{
		cout << "Exiting Game";								//Exits game
	}
	if (choice == 1)
	{
		srand(time(NULL));									//Random number generator
		Startgame();										//Call start game function
	}
}

//*********************************************//
// Function to start game; to be called in main//
//*********************************************//

void Startgame()
{
	string userName;
	Fighters Player(150);									//Creates Player object from constructor
	Fighters Enemy(175);									//Creates Enemy object from constructor

//************************//
//User choice to pick name//
//************************//

	cout << "Pick a name for your fighter: " << endl;
	cin >> userName;
	Player.setName(userName);

//********************************************************//
//Explore action, 3 finds sword and multiplies attack by 3//
//********************************************************//

	cout << "Rolling dice: Roll a 3 for sword!" << endl;
	
		int lowest = 1;
		int highest = 4;
		int roll;

		roll = (rand() % (highest - lowest + 1)) + lowest;
		if (roll == 3)
		{
			cout << "You have found a sword! Attack multiplied by 3." << endl;
			Sword.hasSword = true;
		} 

	cout << "You rolled " << roll << endl;

//***********************//
//Initiate fight sequence//
//***********************//

	bool fightIsover = false;
	while(!fightIsover)
	{
		

		int playerAttack = Player.Weaponattack();
		int enemyAttack = Player.Attack();
		
		cout << userName << " attacks the enemy! Attack value: " << playerAttack << endl;
		cout << "Enemy attacks! Attack value: " << enemyAttack << endl;

		Player.takeDamage(enemyAttack);
		Enemy.takeDamage(playerAttack);

		cout << userName << " HP is now " << Player.getHP() << endl;
		cout << "Enemy HP is now " << Enemy.getHP() << endl;

		if (Player.getHP() <= 0 || Enemy.getHP() <= 0)
		{
			fightIsover = true;

			if (Player.getHP() > 0)
			{
				cout << "You win!" << endl;
			}
			else
			{
				cout << "You have lost the battle." << endl;
			}
		}
		
	}
}
