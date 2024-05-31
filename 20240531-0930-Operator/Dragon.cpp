#include "Dragon.h"
#include <iostream>

using namespace std;

Dragon::Dragon(string name, int health, int attack, int defense, int replenishesQuantity)
	: Monster(name, health, attack, defense), _replenishesQuantity(replenishesQuantity) {}


int Dragon::GetReplenishesQuantity() {
	return _replenishesQuantity;
}

void Dragon::Info() {
	Monster::Info();
	cout << "��ü ȸ����: " << _replenishesQuantity << endl;
}