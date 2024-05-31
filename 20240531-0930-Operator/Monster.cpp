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

	cout << _name << "�� " << enemy._name << "�� �����ؼ� ������� " << enemy._health << "�� ����." << endl;

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
	cout << GetName() << "�� " << enemy.GetName() << "�� �����ؼ� ������� " << enemy.GetHealth() << "�� ����." << endl;

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
	cout << GetName() << "�� " << enemy.GetName() << "�� �����ؼ� ������� " << enemy.GetHealth() << "�� ����." << endl;

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
	cout << GetName() << "�� " << enemy.GetName() << "�� �����ؼ� ������� " << enemy.GetHealth() << "�� ����." << endl;

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

	cout << _name << "�� " << enemy._name << "�� �����ؼ� ������� " << enemy._health << "�� �پ���." << endl;
	cout << enemy._name << "�� ��ü ȸ���ؼ� ������� " << enemy._health + enemy.GetReplenishesQuantity() << "�� �þ���." << endl;
	enemy._health += enemy.GetReplenishesQuantity();

}

void Monster::Info() {
	cout << "�̸�: " << _name << endl;
	cout << "�����: " << _health << endl;
	cout << "����: " << _defense << endl;
	cout << "���ݷ�: " << _attack << endl;
}