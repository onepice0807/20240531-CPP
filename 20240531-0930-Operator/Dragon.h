#pragma once
#include "Monster.h"
#include <string>

class Dragon : public Monster {
private:
	int _replenishesQuantity; // 자체 회복력
public:
	Dragon(std::string name, int health, int attack, int defense, int replenishesQuantity);

	int GetReplenishesQuantity();

	void Info();
};