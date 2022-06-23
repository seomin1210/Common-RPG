#pragma once
#include "Creature.h"
#include "console.h"
using namespace std;

enum PlayerType
{
	PT_KNIGHT = 1,
	PT_ARCHER = 2,
	PT_MAGE = 3
};
class Player : public Creature
{
public:
	int m_maxHp;
	int m_maxMana;
	int m_exp;
	int m_maxExp;
	int m_lv;
	int tposX;
	int tposY;
	bool isOpenMenu = false;
	bool isGameStop = false;
	bool isGameOver = false;
public:
	Player(int playerType) : Creature(CT_PLAYER), m_playerType(playerType), m_exp(0), m_lv(1), m_maxExp(10), m_maxHp(0), m_maxMana(0) {
		tposX = 0;
		tposY = 0;
	}
	virtual ~Player() {

	}
	void LevelUp();
	void GiveExp(int exp);
	virtual void StatUp() {

	}
protected:
	int m_playerType;
};

class Knight : public Player {
public:
	Knight() : Player(PT_KNIGHT) {
		m_hp = 180;
		m_mana = 30;
		m_maxHp = m_hp;
		m_maxMana = m_mana;
		m_attack = 10;
		m_magic = 4;
		m_defence = 9;
	}
	void StatUp() override;
};

class Archer : public Player {
public:
	Archer() : Player(PT_ARCHER) {
		m_hp = 130;
		m_mana = 50;
		m_maxHp = m_hp;
		m_maxMana = m_mana;
		m_attack = 15;
		m_magic = 8;
		m_defence = 6;
	}
	void StatUp() override;
};

class Mage : public Player {
public:
	Mage() : Player(PT_MAGE) {
		m_hp = 105;
		m_mana = 100;
		m_maxHp = m_hp;
		m_maxMana = m_mana;
		m_attack = 7;
		m_magic = 11;
		m_defence = 4;
	}
	void StatUp() override;
};

