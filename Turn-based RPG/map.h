#pragma once
#include "Player.h"
#include "Monster.h"
#include "Game.h"
using namespace std;

enum MenuUIType {
	MNUI_Stat = 0,
	MNUI_Armor,
	MNUI_Setting,
	MNUI_Exit
};

enum BattleUIType {
	BTUI_Attack = 0,
	BTUI_Magic,
	BTUI_Shield,
	BTUI_Item,
	BTUI_Run
};

typedef struct _battle {
	bool isBattle = false;
	int monsterType = 0;
}BATTLE, * BBATTLE;

//세로
const int HEIGHT = 30;
//가로
const int WEIGHT = 31;

typedef struct _pos
{
	int x;
	int y;
}POS, * PPOS;

class Field
{
public:
	Field();
	~Field();
	void Createmonster(BBATTLE bBattle);
	void Startbattle(Game* gGame, BBATTLE bBattle);
	Monster* m_monster = nullptr;
};

void SetMap(char Map[20][HEIGHT][WEIGHT], Player* pPlayer);
void OutputMap(char Map[20][HEIGHT][WEIGHT], Player* pPlayer, int mapCount);
void OutputMenu(Player* pPlayer, int uiCnt);
void CloseMenu(Player* pPlayer, int* uiCnt);
void SelectMenu(Player* pPlayer, int uiCnt);
void MoveMenuUI(int* uiCnt);
void MoveupMenuUI(int* uiCnt);
void MovedownMenuUI(int* uiCnt);
int Moveplayer(char Map[20][HEIGHT][WEIGHT], Player* pPlayer, int mapCount, BBATTLE bBattle);
int Moveup(char Map[20][HEIGHT][WEIGHT], Player* pPlayer, int mapCount, BBATTLE bBattle);
int Movedown(char Map[20][HEIGHT][WEIGHT], Player* pPlayer, int mapCount, BBATTLE bBattle);
int Moveleft(char Map[20][HEIGHT][WEIGHT], Player* pPlayer, int mapCount, BBATTLE bBattle);
int Moveright(char Map[20][HEIGHT][WEIGHT], Player* pPlayer, int mapCount, BBATTLE bBattle);
void EncounterMonster(BBATTLE bBattle, int mapCnt);
void OutputBattle(Game* gGame, int uiCnt);
void SelectBattleUI(Game* gGame, BBATTLE bBattle, int uiCnt);
void MoveBattleUI(int* uiCnt);
void MoveupBattleUI(int* uiCnt);
void MovedownBattleUI(int* uiCnt);