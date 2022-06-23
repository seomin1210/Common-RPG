#include "Creature.h"

void Creature::Onattacked(Creature* attacker, int attackType)
{
	switch (attackType)
	{
	case AT_ATTACK:
		m_hp -= attacker->m_attack - m_defence;
		break;
	case AT_MAGIC:
		m_hp -= attacker->m_magic - m_defence;
		attacker->m_mana -= 0;
		break;
	default:
		break;
	}
}
