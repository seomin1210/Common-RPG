#pragma once
#include "Creature.h"
#include <string>
#include <iostream>
using namespace std;

enum MonsterType
{
	MT_SLIME = 1,
	MT_WOLF,
	MT_GOBLIN,
	MT_ORC,
	MT_DRAGON
};

class Monster : public Creature
{
public:
	string m_name;
	int m_giveExp;
public:
	Monster(int monsterType) : Creature(CT_MONSTER), m_monsterType(monsterType), m_giveExp(0), m_name("") {

	}
	bool Die() { return m_hp <= 0; }
protected:
	int m_monsterType;
};

class Slime : public Monster {
public:
	Slime() : Monster(MT_SLIME) {
		m_name = "슬라임";
		m_hp = 160;
		m_mana = 80;
		m_attack = 15;
		m_magic = 6;
		m_defence = 2;
		m_giveExp = 11;
	}
};

class Wolf : public Monster {
public:
	Wolf() : Monster(MT_WOLF) {
		m_name = "늑대";
		m_hp = 300;
		m_mana = 40;
		m_attack = 35;
		m_magic = 11;
		m_defence = 9;
		m_giveExp = 23;
	}
};

class Goblin : public Monster {
public:
	Goblin() : Monster(MT_GOBLIN) {
		m_name = "고블린";
		m_hp = 730;
		m_mana = 90;
		m_attack = 75;
		m_magic = 26;
		m_defence = 14;
		m_giveExp = 61;
	}
};

class Orc : public Monster {
public:
	Orc() : Monster(MT_ORC) {
		m_name = "오크";
		m_hp = 1200;
		m_mana = 50;
		m_attack = 155;
		m_magic = 10;
		m_defence = 30;
		m_giveExp = 177;
	}
};

class Dragon : public Monster {
public:
	Dragon() : Monster(MT_DRAGON) {
		m_name = "드래곤";
		m_hp = 10000;
		m_mana = 10000;
		m_attack = 1000;
		m_magic = 300;
		m_defence = 100;
		m_giveExp = 100000;
	}
};