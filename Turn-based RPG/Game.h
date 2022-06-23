#pragma once

class Player;
class Field;
class Game
{
public:
	Player* m_player;
	Field* m_field;
	int turn = 0;
	int skillTurn = 0;
	Game();
	~Game();
	void Init();
	void Createplayer();
	void Attack();
	void Magic();
	void Shield();
	void Item();
	void MonsterAction();
	void MonsterAttack();
	void MonsterMagic();
	void EndTurn();
};

