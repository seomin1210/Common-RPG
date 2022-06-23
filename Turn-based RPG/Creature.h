#pragma once
#include <iostream>
#include <string>
using namespace std;

enum CreatureType
{
	CT_PLAYER,
	CT_MONSTER
};

enum AttackType
{
	AT_ATTACK = 1,
	AT_MAGIC
};

class Creature
{
public:
	int m_maxHp;
	int m_maxMana;
	int m_creaturetype;
	int m_hp;
	int m_mana;
	int m_attack;
	int m_magic;
	int m_defence;
	int m_skillMana;
	string m_skillName;
public:
	Creature(int creatureType) : m_creaturetype(creatureType), m_hp(0), m_mana(0), m_attack(0), m_magic(0), m_defence(0), m_skillName(""), m_skillMana(0), m_maxHp(0), m_maxMana(0) {

	}
	virtual ~Creature() {

	}
	void Onattacked(Creature* attacker, int attackType);
};

