#ifndef __DICE_H__
#define __DICE_H__

#include <cstdlib>
#include <vector>

const int DICEMAX = 6;

class Dice {
	private:
		static Dice *instance;   //dice implemented as a singleton
		int n;   //represents the number of dice

		static void cleanInstance();
		Dice(const int v);
		~Dice();
	public:
		static Dice *getInstance(const int v = 0);   //if no dice exist, get a new dice with number v facing upwards, otherwise return the existing dice
		std::vector <int> roll();   //roll a dice and add the rolled value to a vector array
		int		getNumDice();
};

#endif
