#include "Player.h"

void Player::LevelUp()
{
	m_lv++;
	m_exp -= m_maxExp;
	m_maxExp *= 1.1f;
	gotoxy(33, 42);
	cout << "Level Up";
	StatUp();
	m_hp = m_maxHp;
	m_mana = m_maxMana;
	Sleep(700);
}

void Player::GiveExp(int exp)
{
	m_exp += exp;
	while (m_exp >= m_maxExp) LevelUp();
}

void Knight::StatUp()
{
	m_maxHp += 10;
	m_maxMana += 2;
	m_attack += 3;
	m_magic += 1;
	m_defence += 1;
	if((m_lv % 2) == 0)
		m_defence += 1;
}

void Archer::StatUp()
{
	m_maxHp += 7;
	m_maxMana += 2;
	m_attack += 4;
	m_magic += 1;
	m_defence += 1;
}

void Mage::StatUp()
{
	m_maxHp += 5;
	m_maxMana += 5;
	m_attack += 1;
	m_magic += 3;
	if ((m_lv % 2) == 0)
		m_defence += 1;
}
