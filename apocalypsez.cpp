// ApocalypseZ.cpp by djflashpoint
//
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int createZombie() {
    if (rand() % 67 < 10)
        return 11;

    else
        return rand() % 10 + 1;
}

int main() {
		bool quit = false;
		bool restart = false;
		while (!quit)
	{
			restart = false;
			while (!quit && !restart)
	{
		srand(time(NULL));
		char enter;

    // game stats
    int playerAlive = true;
    int playerSkill = 9;
    int playerScore = 1;
    string playerName = "";
    int zombieCount = 0;
    int zombiesKilled = 0;

    // title
    cout << "<<<<A P O C A L Y P S E  Z>>>>" << endl << "PRESS [ENTER] TO BEGIN ";
    cin.get();
	_sleep(1000);

    // player name
    cout << "ENTER NAME: ";
    cin >> playerName;
	_sleep(1000);

    // ask how many zombies
    cout << "HOW MANY ZOMBIES?";
    cin >> zombieCount;
	_sleep(1000);

	cout << "YOU ARE THE LAST OF HUMANKIND, GET READY TO ENTER THE APOCALYPSE." << endl;
	_sleep(3000);

    // main game loop
    while (playerAlive && zombiesKilled < zombieCount) {
        // create a random zombie
        int zombieSkill = createZombie();

        // battle sequence
        if (zombieSkill > 10) {
            cout << endl << "ZOMBIE ATTACK!" << endl;
			_sleep(3000);
        }
        else {
            cout << endl << "HERE COMES ZOMBIE " << zombiesKilled + 1 << endl;
			_sleep(3000);
        }
		

        cout << "...F I G H T I N G... " << endl;
		_sleep(5000);
		

        // zombie killed the player
        if (playerSkill < zombieSkill) {
            playerAlive = false;
            cout << "Y O U  D I E D. " << endl;
			_sleep(1000);
        }
		
        // player killed the zombie
        else {
            if (playerSkill - zombieSkill > 7) {
				cout << "YOU OBLITERATED THE ZOMBIE! " << endl;
                playerScore = playerScore * 7;
				_sleep(1000);
            }

            else if (playerSkill - zombieSkill > 5) {
				cout << "YOU DISMEMBERED THE ZOMBIE!" << endl;
                playerScore = playerScore * 5;
				_sleep(1000);
            }
			else if (playerSkill - zombieSkill > 3) {
				cout << "YOU MASSACRED THE ZOMBIE!" << endl;
                playerScore = playerScore * 3;
				_sleep(1000);
            }

            else if (playerSkill - zombieSkill > 0) {
				cout << "YOU KILLED THE ZOMBIE!" << endl;
                playerScore = playerScore * 1;
				_sleep(1000);
            }

            else {
				cout << "YOU KILLED THE ZOMBIE, BUT SUFFERED MAJOR DAMAGE!" << endl;
				_sleep(1000);
            }

            zombiesKilled++;
        }

        cout << endl;
		_sleep(2000);
    }

    // end game
    if (zombiesKilled == zombieCount) {
        // victory
		cout << "YOU SURVIVED..." << endl;
		_sleep(3000);
		cout << "A P O C A L Y P S E  Z!" << endl;
		_sleep(3000);
    }
    else {
        // lost
		cout << "YOU HAVE BECOME VICTIM OF..." << endl;
		_sleep(3000);
		cout << "A P O C A L Y P S E  Z!" << endl;
		_sleep(3000);
		cout << "M U T A T I O N  C O M M E N C I N G..." << endl;
		_sleep(5000);
    }

	cout << "YOUR BODY COUNT: " << zombiesKilled << endl;
	_sleep(1000);
	cout << "YOUR FINAL SCORE: " << playerScore << endl << endl;
	_sleep(10000);
			{
				int counter = 05;
				_sleep(1000);
				while (counter >= 1)
				{
					cout << "\rGame restarts in: " << counter << flush;
					_sleep(1000);
					counter--;
					system("CLS");
				}
			}
		}
	}
}