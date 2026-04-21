#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void clearScreen()
{
    // Standard ANSI escape code to clear terminal and move cursor to the top-left
    cout << "\033[2J\033[1;1H";
}

void continueToNextRound()
{
    cout << "\n[Press Enter to Continue...]" << endl;
    cin.clear();
    cin.ignore(10000, '\n');
    cin.get();
    clearScreen();
}

//CLASSES

class Player {
private:
    string name;
    string className;
    int hp;
    int minDamage;
    int maxDamage;

public:
    Player(string _name, string _className, int _hp, int _minDamage, int _maxDamage) {
        name = _name;
        className = _className;
        hp = _hp;
        minDamage = _minDamage;
        maxDamage = _maxDamage;
    }

    string getName() { return name; }
    
    string getClassName() { return className;  }

    int getHp() { return hp; }

    bool isAlive() { return hp > 0; }

    void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0)
            hp = 0;
    }

    int getDamage() {
        return minDamage + rand() % (maxDamage - minDamage + 1);
    }

    void showStats() {
        cout << "\n--- " << name << " the " << className << "---" << endl;
        cout << "HP: " << hp << " | Damage: " << minDamage << "-" << maxDamage << endl;
    }

};

class Enemy {
private:
    string name;
    int hp;
    int minDamage;
    int maxDamage;
    int hitChance;

public:
    Enemy(string _name, int _hp, int _minDamage, int _maxDamage, int _hitChance) {
        name = _name;
        hp = _hp;
        minDamage = _minDamage;
        maxDamage = _maxDamage;
        hitChance = _hitChance;
    }

    string getName() { return name; }
    int getHp() { return hp; }
    bool isAlive() { return hp > 0; }

    void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0)
            hp = 0;
    }

    int getDamage() {
        int roll = rand() % 100 + 1;
        if (roll <= hitChance) {
            return minDamage + rand() % (maxDamage - minDamage + 1);
        }
        else {
            return 0;
        }
    }

};

//MATH ATTACK FUNCTION

bool mathAttackChallenge() {
    int num1 = rand() % 12 + 1;
    int num2 = rand() % 12 + 1;
    int operation = rand() % 3;

    int Answer;
    char opChar;

    if (operation == 0) {
        Answer = num1 + num2;
        opChar = '+';
    }
    else if (operation == 1) {
        if (num1 < num2) 
            swap(num1, num2);
        Answer = num1 - num2;
        opChar = '-';
    }
    else {
        Answer = num1 * num2;
        opChar = '*';
    }

    int PlayerAnswer;
    cout << "\n[MATH CHALLENGE TO ATTACK!] What is " << num1 << " " << opChar << " " << num2 << "?\n>";
    cin >> PlayerAnswer;

    if (PlayerAnswer == Answer) {
        cout << "\nCorrect! You prepare to strike." << endl;
        return true;
    }
    else {
        cout << "\nIncorrect! The answer was " << Answer << " You stumble and miss your attack!" << endl;
        return false;
    }
}

int main()
{
    srand(time(0));
    clearScreen();

    cout << "---------------------------------------" << endl;
    cout << "       WELCOME TO THE MATH RPG!        " << endl;
    cout << "---------------------------------------" << endl;

    string playerName;
    cout << "Enter the hero's name: ";
    cin >> playerName;

    cout << "\nChoose your class:" << endl;
    cout << "1. Warrior (100 HP, 10-20 Damage)" << endl;
    cout << "2. Mage (60 HP, 20-35 Damage)" << endl;
    cout << "3. Rogue (80 HP, 15-25 damage)" << endl;
    cout << "> ";

    int classChoice;
    cin >> classChoice;

    Player* player = nullptr;

    if (classChoice == 1)
    {
        player = new Player(playerName, "Warrior", 100, 10, 20);
    }
    else if (classChoice == 2)
    {
        player = new Player(playerName, "Mage", 60, 20, 35);
    }
    else
    {
        player = new Player(playerName, "Rogue", 80, 15, 25);
    }

    Enemy enemyList[3] =
    {
        Enemy("Goblin", 60, 8, 15, 70),
        Enemy("Orc", 90, 15, 30, 55),
        Enemy("Slime", 110,5,12,85)
    };

    int randomEnemy = rand() % 3;
    Enemy currentEnemy = enemyList[randomEnemy];

    continueToNextRound();

    while (player->isAlive() && currentEnemy.isAlive())
    {
        cout << "---------------------------------------" << endl;
        cout << "             COMBAT ROUND              " << endl;
        cout << "---------------------------------------" << endl;
        cout << player->getName() << " HP: " << player->getHp() << "  VS  " << currentEnemy.getName() << " HP: " << currentEnemy.getHp() << endl;
        cout << "---------------------------------------" << endl;

        cout << "Your turn! Answer the math problem to attack." << endl;
        bool attackSuccess = mathAttackChallenge();

        if (attackSuccess)
        {
            int damage = player->getDamage();
            cout << " You hit the " << currentEnemy.getName() << " for " << damage << " damage!" << endl;
            currentEnemy.takeDamage(damage);
        }

        if (!currentEnemy.isAlive())
        {
            break;
        }

        cout << "---------------------------------------" << endl;
        cout << currentEnemy.getName() << "'s turn..." << endl;
        int enemyDamage = currentEnemy.getDamage();

        if (enemyDamage > 0)
        {
            cout << " The " << currentEnemy.getName() << " strikes you for " << enemyDamage << " damage!" << endl;
            player->takeDamage(enemyDamage);
        }
        else
        {
            cout << " The " << currentEnemy.getName() << " misses you!" << endl;
        }

        if (player->isAlive())
        {
            continueToNextRound();
        }
    }

    continueToNextRound();
    cout << "---------------------------------------" << endl;
    if (player->isAlive())
    {
        cout << "           VICTORY!            " << endl;
        cout << " You defeated the " << currentEnemy.getName() << " with " << player->getHp() << " HP left!" << endl;
    }
    else
    {
        cout << "           DEFEAT!         " << endl;
        cout << " You were slain by the " << currentEnemy.getName() << endl;
    }
    cout << "---------------------------------------" << endl;

    delete player;

    return 0;


}
