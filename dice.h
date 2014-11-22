#ifndef __DICE_H__
#define __DICE_H__

#include <cstdlib>
#include <vector>

const int DICEMAX = 6;

class Dice {
	private:
	   //dice implemented as a singleton
		static Dice *instance;
		//represents the number of dice
		int n;

		static void cleanInstance();
		Dice(const int v);
		~Dice();
	public:
	   //if no dice exist, get a new dice with number v facing upwards, otherwise return the existing dice
		static Dice *getInstance(const int v = 0);
		//roll a dice and add the rolled value to a vector array
		std::vector <int> roll();
		//store the values in vector a into a new vector array
		std::vector <int> roll(std::vector <int> &a);
};

#endif
