#pragma once
#include "Creature.h"
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
	int m_nameColor;
	int m_monsterType;
	bool isBleeding = false;
public:
	Monster(int monsterType) : Creature(CT_MONSTER), m_monsterType(monsterType), m_giveExp(0), m_name(""), m_nameColor(15) {

	}
	bool Die() { return m_hp <= 0; }
};

class Slime : public Monster {
public:
	Slime() : Monster(MT_SLIME) {
		m_name = "½½¶óÀÓ";
		m_nameColor = 10;
		m_hp = 160;
		m_mana = 80;
		m_maxHp = m_hp;
		m_maxMana = m_mana;
		m_attack = 15;
		m_magic = 6;
		m_defence = 2;
		m_giveExp = 11;
		m_skillName = "»ê¼º¾×";
		m_skillMana = 9;
	}
};

class Wolf : public Monster {
public:
	Wolf() : Monster(MT_WOLF) {
		m_name = "´Á´ë";
		m_nameColor = 8;
		m_hp = 300;
		m_mana = 40;
		m_maxHp = m_hp;
		m_maxMana = m_mana;
		m_attack = 35;
		m_magic = 11;
		m_defence = 9;
		m_giveExp = 23;
		m_skillName = "Âõ¾î¹ß±â±â";
		m_skillMana = 8;
	}
};

class Goblin : public Monster {
public:
	Goblin() : Monster(MT_GOBLIN) {
		m_name = "°íºí¸°";
		m_nameColor = 10;
		m_hp = 730;
		m_mana = 90;
		m_maxHp = m_hp;
		m_maxMana = m_mana;
		m_attack = 75;
		m_magic = 26;
		m_defence = 14;
		m_giveExp = 61;
		m_skillName = "¾àÅ»! °­Å»!";
		m_skillMana = 15;
	}
};

class Orc : public Monster {
public:
	Orc() : Monster(MT_ORC) {
		m_name = "¿ÀÅ©";
		m_nameColor = 2;
		m_hp = 1200;
		m_mana = 50;
		m_maxHp = m_hp;
		m_maxMana = m_mana;
		m_attack = 155;
		m_magic = 10;
		m_defence = 30;
		m_giveExp = 177;
		m_skillName = "Áþ¹¶°³±â";
		m_skillMana = 4;
	}
};

class Dragon : public Monster {
public:
	Dragon() : Monster(MT_DRAGON) {
		m_name = "µå·¡°ï";
		m_nameColor = 13;
		m_hp = 10000;
		m_mana = 10000;
		m_maxHp = m_hp;
		m_maxMana = m_mana;
		m_attack = 1000;
		m_magic = 300;
		m_defence = 100;
		m_giveExp = 100000;
		m_skillName = "ºê·¹½º";
		m_skillMana = 1;
	}
};