#pragma once

class Player;
class Field;
class Game
{
public:
	Player* m_player;
	Field* m_field;
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
};

