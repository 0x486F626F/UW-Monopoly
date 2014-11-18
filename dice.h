#ifndef __DICE_H__
#define __DICE_H__

#include <cstdlib>
#include <ctime>
#include <vector>

const int DICEMAX = 6;

class Dice {
	private:
		static Dice *instance;
		int n;

		static void cleanInstance();
		Dice(const int v);
		~Dice();
	public:
		static Dice *getInstance(const int v);
		std::vector <int> roll();
		std::vector <int> roll(std::vector <int> &a);
};

#endif
