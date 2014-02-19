// Filename: TowerHanoi.cpp
// Date Created: 04/10/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Node.h"
#include "LinkedList.h"
#include "Disc.h"
#include "LStack.h"
#include "TowerHanoi.h"

using namespace std;
using lance_project::Disc;
using lance_project::Node;
using lance_project::LinkedList;
using lance_project::TowerHanoi;
using lance_project::LStack;

namespace lance_project {
	TowerHanoi::TowerHanoi(int rods, int discs) {
		this->rods = rods;
		this->discs = discs;
		this->win = false;
		this->initRods();
	}
	
	TowerHanoi::~TowerHanoi() {
		delete [] this->towers;
	}
	
	void TowerHanoi::initRods() {
		for (int i = 0; i < this->rods; i++) {
			this->towers[i] = new LStack<Disc>();
		}
	}	
	
	void TowerHanoi::createTower(int index) {
		for (int i = this->discs; i >= 1; i--) {
			string row;
			int spaces = (this->discs + 1 - i);
			for (int s = 0; s < spaces; s++) {
				row += ' ';
			}
			int number = (2 * i - 1);
			for (int n = 0; n < number; n++) {
				row += 'X';
			}
			for (int s = 0; s < spaces; s++) {
				row += ' ';
			}
			this->towers[index]->push(new Disc(row));
		}
	}
	
	bool TowerHanoi::move(int from, int to) {
		if (!this->towers[from]->empty()) {
			Disc* objFrom = this->towers[from]->front();
			if (!this->towers[to]->empty()) {
				Disc* objTo = this->towers[to]->front();
				if (objFrom->getCount() < objTo->getCount()) {
					this->towers[to]->push(this->towers[from]->pop());
					if ((to > 0) && (this->towers[to]->size() == this->discs)) {
						this->win = true;
					}
					return true;
				}
			} else {
				this->towers[to]->push(this->towers[from]->pop());
				return true;
			}
		}
		return false;
	}

	
	std::string TowerHanoi::showTowers() {
		std::string lines[this->rods][this->discs + 1];
		for (int i = 0; i < (int)sizeof(this->towers); i++) {
			if ((this->towers[i] != NULL) && (i < this->rods)) {
				LStack<Disc>* stack = this->towers[i];
				LinkedList<Disc>* list = stack->getList();
				int space_lines = (this->discs - list->getSize());
				int index = 0;
				
				for (int l = 0; l < space_lines; l++) {
					string white_space; 
					for (int s = 0; s < ((2 * this->discs - 1) + 2); s++) {
						white_space += ' ';
					}
					lines[i][index++] = white_space;
				}
				
				for (Node<Disc>* current = list->getHead(); current != NULL; current = current->link()) {
					if (current != NULL) {
						lines[i][index++] = current->data()->getValue();
					}
				}
				
				string separator_space;
				int separator_count = ((2 * this->discs - 1) + 2);
				for (int s = 0; s < separator_count; s++) {
					if (s == (separator_count / 2)) {
						stringstream result;
						result << (i + 1);
						separator_space += result.str();
					} else {
						separator_space += '-';
					}
					
				}
				lines[i][index++] = separator_space;
			}	
		}
		
		std::string tower_str;
		for (int i = 0; i < this->discs + 1; i++) {
			for (int rod = 0; rod < this->rods; rod++) {
				tower_str += lines[rod][i];
			}
			tower_str += "\n";
		}
		return tower_str;
	}
	
	bool TowerHanoi::won() {
		return this->win;
	}
	
	LStack<Disc>* TowerHanoi::getTower(int index) {
		return this->towers[index];
	}
}
