#include "Monster.h"
#include "Golem.h"
#include "Goblin.h"
#include "Slime.h"
#include "Dragon.h"
#include <iostream>

using namespace std;


Monster::Monster(string name, int health, int attack, int defense)
	: _name(name), _health(health), _attack(attack), _defense(defense) {}

string Monster::GetName() {
	return _name;
}

int Monster::GetHealth() {
	return _health;
}

void Monster::SetHealth(int health) {
	_health = health;
}

int Monster::GetDefense() {
	return _defense;
}

void Monster::GetDamage(int attack) {
	int damage = _attack - _defense;

	if (damage <= 0) {
		damage = 0;
	}

	int health = _health - damage;

	_health = health;
}

void Monster::Attack(Monster& enemy) {
	/*
	int damage = _attack - enemy._defense;

	if (damage <= 0) {
		damage = 0;
	}

	int health = enemy._health - damage;

	enemy._health = health;

	*/
	enemy.GetDamage(_attack);

	cout << _name << "가 " << enemy._name << "을 공격해서 생명력이 " << enemy._health << "로 줄음." << endl;

}

void Monster::Attack(Goblin& enemy) {
	/*
	int damage = _attack - enemy.GetDefense() - enemy.GetPhysicalAttackRegist();

	if (damage <= 0) {
		damage = 0;
	}

	int health = enemy.GetHealth() - damage;

	enemy.SetHealth(health);
	*/

	enemy.GetDamage(_attack);

	cout << "Monster::Attack(Goblin)" << endl;
	cout << GetName() << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemy.GetHealth() << "로 줄음." << endl;

}

void Monster::Attack(Slime& enemy) {
	/*
	int damage = _attack - enemy.GetDefense() - enemy.GetDefense();

	if (damage <= 0) {
		damage = 0;
	}

	int health = enemy.GetHealth() - damage;

	enemy.SetHealth(health);
	*/

	enemy.GetDamage(_attack);

	cout << "Monster::Attack(Slime)" << endl;
	cout << GetName() << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemy.GetHealth() << "로 줄음." << endl;

}

void Monster::Attack(Golem& enemy) {
	/*
	int damage = _attack - enemy.GetDefense() - enemy.GetDefense();

	if (damage <= 0) {
		damage = 0;
	}

	int health = enemy.GetHealth() - damage;

	enemy.SetHealth(health);
	*/

	enemy.GetDamage(_attack);

	cout << "Monster::Attack(Golem)" << endl;
	cout << GetName() << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemy.GetHealth() << "로 줄음." << endl;

}

void Monster::Attack(Dragon& enemy) {
	/*
	int damage = _attack - enemy.GetDefense();


	if (damage <= 0) {
		damage = 0;
	}

	enemy._health -= damage;
	if (enemy._health < 0) {
		enemy._health = 0;
	}

	int health = enemy._health -= damage;
	if (enemy._health < 0) {
		enemy._health = 0;
	}

	enemy.SetHealth(health);
	*/

	enemy.GetDamage(_attack);

	enemy._health += enemy.GetReplenishesQuantity();

	cout << _name << "가 " << enemy._name << "을 공격해서 생명력이 " << enemy._health << "로 줄었다." << endl;
	cout << enemy._name << "가 자체 회복해서 생명력이 " << enemy._health + enemy.GetReplenishesQuantity() << "로 늘었다." << endl;
	enemy._health += enemy.GetReplenishesQuantity();

}

void Monster::Info() {
	cout << "이름: " << _name << endl;
	cout << "생명력: " << _health << endl;
	cout << "방어력: " << _defense << endl;
	cout << "공격력: " << _attack << endl;
}