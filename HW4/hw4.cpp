#include <iostream>
#include <stdlib.h>

#include <time.h>
using namespace std;
class Die // this is from book page 778 in section 8 method

{
private:

	int sides; // Number of sides

	int value; // The die's value
public :
	Die(int =6);
	int getSides(); // Returns the number of sides
	int roll();
	int getValue(); // Returns the die's value
};
Die::Die(int numSides)
{
	// Get the system time.
	unsigned seed = time(0);
	// Seed the random number generator.
	srand(seed);
	// Set the number of sides.
	sides = numSides;
}
int Die::roll()
{
	const int MIN = 1;
	value = (rand() % (sides - MIN + 1)) + MIN;
	return value;
}
int Die::getSides()
{
	return sides;
}
int Die::getValue()

{
	return value;
}
int main()
{
	Die d1, d2;
	int star = 0;
	char ch;
	int user = 0;
	int computer = 0;
	do {
		
		cout << "Do you want to roll the dice to accumulate points? Y/N: ";
		cin >> ch;
		if (ch == 'Y' || ch == 'y') {
			computer += d1.roll() + d2.roll();
			user += d1.roll() + d2.roll();
			cout << "Your current total is " << user << "\n";
			if (user > 21) {
				break;
			}
			else {
				star = 0;
			}
		}
		if (ch == 'N' || ch == 'n') {
			 break;
		}

	} while ( star = 1);
	cout << "Your total: " << user << "\n";
	cout << "Computer total: " << computer << "\n";

	if (user <= 21 && user == computer)
	{
		cout << "Match tie\n";
	}
	else if (user <= 21 && user > computer)
	{
		cout << "You win\n";
	}
	else if (computer <= 21 && user < computer)
	{
		cout << "computer win\n";
	}
	else
	{
		cout << "You lose because your total got over 21\n";
	}

	return 0;
}