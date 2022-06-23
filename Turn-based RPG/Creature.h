#pragma once

enum CreatureTyp
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
	int m_creaturetype;
	int m_hp;
	int m_mana;
	int m_attack;
	int m_magic;
	int m_defence;
public:
	Creature(int creatureType) : m_creaturetype(creatureType), m_hp(0), m_mana(0), m_attack(0), m_magic(0), m_defence(0) {

	}
	virtual ~Creature() {

	}
	void Onattacked(Creature* attacker, int attackType);
};

