// Filename: TowerHanoi.h
// Date Created: 04/10/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#ifndef LANCE_TOWERHANOI_H
#define LANCE_TOWERHANOI_H
#include "Disc.h"
namespace lance_project {
	static const int MAX_RODS = 5;
	
	class TowerHanoi {
		public:
			TowerHanoi(int rods, int discs);
			
			~TowerHanoi();
			
			LStack<Disc>* getTower(int index);
			
			void createTower(int index);
			
			bool move(int from, int to);
			
			bool won();
			
			std::string showTowers();
			
		private:
			LStack<Disc>* towers[MAX_RODS];
			
			int rods;
			
			int discs;
			
			bool win;
			
			void initRods();
	};
}
#endif
