#include "map.h"


void SetMap(char Map[20][HEIGHT][WEIGHT], Player* pPlayer)
{
	pPlayer->tposX = 15;
	pPlayer->tposY = 15;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			strcpy_s(Map[i][j], "111111111111111111111111111111");
		}
	}
	for (int i = 0; i < 20; i += 4) {
		for (int j = 0; j < 30; j++) {
			strcpy_s(Map[i][j], "011111111111111111111111111111");
		}
	}
	for (int i = 3; i < 20; i += 4) {
		for (int j = 0; j < 30; j++) {
			strcpy_s(Map[i][j], "111111111111111111111111111110");
		}
	}
	for (int i = 0; i < 4; i++) {
		strcpy_s(Map[i][0], "000000000000000000000000000000");
	}
	for (int i = 16; i < 20; i++) {
		strcpy_s(Map[i][19], "000000000000000000000000000000");
	}
}

void OutputMap(char Map[20][HEIGHT][WEIGHT], Player* pPlayer, int mapCount)
{
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WEIGHT; j++) {
			if (pPlayer->tposX == j && pPlayer->tposY == i)
				cout << "☆";
			else if (Map[mapCount][i][j] == '0')
				cout << "■";
			else if (Map[mapCount][i][j] == '1')
				cout << "  ";
		}
		cout << endl;
	}
}

void OutputMenu(Player* pPlayer, int uiCnt)
{
	pPlayer->isOpenMenu = true;
	gotoxy(60, 0);
	cout << "■■■■■■■■■■■■" << endl;
	gotoxy(60, 1);
	cout << "■ Lv: " << pPlayer->m_lv << "   " << pPlayer->m_exp << "/" << pPlayer->m_maxExp;
	gotoxy(82, 1);
	cout << "■" << endl;
	gotoxy(60, 2);
	cout << "■";
	gotoxy(82, 2);
	cout << "■" << endl;
	gotoxy(60, 3);
	cout << "■";
	gotoxy(82, 3);
	cout << "■" << endl;
	gotoxy(60, 4);
	cout << "■     스텟";
	gotoxy(82, 4);
	cout << "■" << endl;
	gotoxy(60, 5);
	cout << "■";
	gotoxy(82, 5);
	cout << "■" << endl;
	gotoxy(60, 6);
	cout << "■";
	gotoxy(82, 6);
	cout << "■" << endl;
	gotoxy(60, 7);
	cout << "■";
	gotoxy(82, 7);
	cout << "■" << endl;
	gotoxy(60, 8);
	cout << "■     장비";
	gotoxy(82, 8);
	cout << "■" << endl;
	gotoxy(60, 9);
	cout << "■";
	gotoxy(82, 9);
	cout << "■" << endl;
	gotoxy(60, 10);
	cout << "■";
	gotoxy(82, 10);
	cout << "■" << endl;
	gotoxy(60, 11);
	cout << "■";
	gotoxy(82, 11);
	cout << "■" << endl;
	gotoxy(60, 12);
	cout << "■     설정";
	gotoxy(82, 12);
	cout << "■" << endl;
	gotoxy(60, 13);
	cout << "■";
	gotoxy(82, 13);
	cout << "■" << endl;
	gotoxy(60, 14);
	cout << "■";
	gotoxy(82, 14);
	cout << "■" << endl;
	gotoxy(60, 15);
	cout << "■";
	gotoxy(82, 15);
	cout << "■" << endl;
	gotoxy(60, 16);
	cout << "■     종료";
	gotoxy(82, 16);
	cout << "■" << endl;
	gotoxy(60, 17);
	cout << "■";
	gotoxy(82, 17);
	cout << "■" << endl;
	gotoxy(60, 18);
	cout << "■";
	gotoxy(82, 18);
	cout << "■" << endl;
	gotoxy(60, 19);
	cout << "■■■■■■■■■■■■" << endl;
	gotoxy(64, 4 * (uiCnt + 1));
	cout << ">";
}

void CloseMenu(Player* pPlayer, int* uiCnt)
{
	pPlayer->isOpenMenu = false;
	*uiCnt = MNUI_Stat;
	for (int i = 0; i < 20; i++) {
		gotoxy(60, i);
		cout << "                        " << endl;
	}
}

void SelectMenu(Player* pPlayer, int uiCnt)
{
	switch (uiCnt)
	{
	case MNUI_Stat:
		gotoxy(0, 32);
		cout << "구현중입니다.." << endl;
		Sleep(500);
		gotoxy(0, 32);
		cout << "                " << endl;
		break;
	case MNUI_Armor:
		gotoxy(0, 32);
		cout << "구현중입니다.." << endl;
		Sleep(500);
		gotoxy(0, 32);
		cout << "                " << endl;
		break;
	case MNUI_Setting:
		gotoxy(0, 32);
		cout << "구현중입니다.." << endl;
		Sleep(500);
		gotoxy(0, 32);
		cout << "                " << endl;
		break;
	case MNUI_Exit:
		pPlayer->isGameStop = true;
		break;
	default:
		break;
	}
}

void MoveMenuUI(int* uiCnt)
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		MoveupMenuUI(uiCnt);
		Sleep(100);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		MovedownMenuUI(uiCnt);
		Sleep(100);
	}
}

void MoveupMenuUI(int* uiCnt)
{
	if (*uiCnt <= MNUI_Stat) {
		*uiCnt = MNUI_Exit;
		return;
	}
	*uiCnt -= 1;
}

void MovedownMenuUI(int* uiCnt)
{
	if (*uiCnt >= MNUI_Exit) {
		*uiCnt = MNUI_Stat;
		return;
	}
	*uiCnt += 1;
}

int Moveplayer(char Map[20][HEIGHT][WEIGHT], Player* pPlayer, int mapCount, BBATTLE bBattle)
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		return Moveup(Map, pPlayer, mapCount, bBattle);
		Sleep(100);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		return Movedown(Map, pPlayer, mapCount, bBattle);
		Sleep(100);
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		return Moveleft(Map, pPlayer, mapCount, bBattle);
		Sleep(100);
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		return Moveright(Map, pPlayer, mapCount, bBattle);
		Sleep(100);
	}
	else {
		return mapCount;
	}

}

int Moveup(char Map[20][HEIGHT][WEIGHT], Player* pPlayer, int mapCount, BBATTLE bBattle)
{
	if (pPlayer->tposY - 1 >= 0) {
		if (Map[mapCount][pPlayer->tposY - 1][pPlayer->tposX] != '0') {
			--pPlayer->tposY;
			EncounterMonster(bBattle, mapCount);
			return mapCount;
		}
		return mapCount;
	}
	else {
		pPlayer->tposY = HEIGHT;
		EncounterMonster(bBattle, mapCount);
		return mapCount - 4;
	}
}

int Movedown(char Map[20][HEIGHT][WEIGHT], Player* pPlayer, int mapCount, BBATTLE bBattle)
{
	if (pPlayer->tposY + 1 < HEIGHT) {
		if (Map[mapCount][pPlayer->tposY + 1][pPlayer->tposX] != '0') {
			++pPlayer->tposY;
			EncounterMonster(bBattle, mapCount);
			return mapCount;
		}
		return mapCount;
	}
	else {
		pPlayer->tposY = 0;
		EncounterMonster(bBattle, mapCount);
		return mapCount + 4;
	}
}

int Moveleft(char Map[20][HEIGHT][WEIGHT], Player* pPlayer, int mapCount, BBATTLE bBattle)
{
	if (pPlayer->tposX - 1 >= 0) {
		if (Map[mapCount][pPlayer->tposY][pPlayer->tposX - 1] != '0') {
			--pPlayer->tposX;
			EncounterMonster(bBattle, mapCount);
			return mapCount;
		}
		return mapCount;
	}
	else {
		pPlayer->tposX = WEIGHT - 2;
		EncounterMonster(bBattle, mapCount);
		return mapCount - 1;
	}
}

int Moveright(char Map[20][HEIGHT][WEIGHT], Player* pPlayer, int mapCount, BBATTLE bBattle)
{
	if (pPlayer->tposX + 1 <= WEIGHT - 2) {
		if (Map[mapCount][pPlayer->tposY][pPlayer->tposX + 1] != '0') {
			++pPlayer->tposX;
			EncounterMonster(bBattle, mapCount);
			return mapCount;
		}
		return mapCount;
	}
	else {
		pPlayer->tposX = 0;
		EncounterMonster(bBattle, mapCount);
		return mapCount + 1;
	}
}

void EncounterMonster(BBATTLE bBattle, int mapCnt)
{
	//몬스터와 마주칠 확률은 20%
	int a = rand() % 100 + 1;
	if (a <= 7) {
		bBattle->isBattle = true;
		if (mapCnt <= 7) {
			bBattle->monsterType = MT_SLIME;
		}
		else if (mapCnt <= 13) {
			bBattle->monsterType = MT_WOLF;
		}
		else if (mapCnt <= 15 || mapCnt == 18) {
			bBattle->monsterType = MT_GOBLIN;
		}
		else if (mapCnt <= 17) {
			bBattle->monsterType = MT_ORC;
		}
		else {
			bBattle->monsterType = MT_DRAGON;
		}
	}
}


Field::Field() : m_monster(nullptr)
{

}

Field::~Field()
{
	if (m_monster != nullptr) {
		delete m_monster;
	}
}

void Field::Createmonster(BBATTLE bBattle)
{
	if (m_monster != nullptr) return;
	switch (bBattle->monsterType)
	{
	case MT_SLIME:
		m_monster = new Slime();
		break;
	case MT_WOLF:
		m_monster = new Wolf();
		break;
	case MT_GOBLIN:
		m_monster = new Wolf();
		break;
	case MT_ORC:
		m_monster = new Orc();
		break;
	case MT_DRAGON:
		m_monster = new Dragon();
		break;
	default:
		break;
	}
}

void Field::Startbattle(Game* gGame, BBATTLE bBattle)
{
	system("cls");
	int uiCnt = BTUI_Attack;
	Createmonster(bBattle);
	while (bBattle->isBattle == true)
	{
		OutputBattle(gGame, uiCnt);
		if (gGame->m_player->m_hp <= 0) {
			gGame->m_player->isGameOver = true;
			bBattle->isBattle = false;
			gotoxy(33, 41);
			cout << "플레이어가 쓰러졌습니다..";
			Sleep(1000);
			break;
		}
		else if (gGame->m_field->m_monster->m_hp <= 0) {
			bBattle->isBattle = false;
			gotoxy(33, 41);
			cout << "승리했습니다! " << gGame->m_field->m_monster->m_giveExp << "만큼의 경험치를 획득했습니다.";
			Sleep(1000);
			gGame->m_player->GiveExp(gGame->m_field->m_monster->m_giveExp);
			break;
		}
		char cInput = _getch();
		if (cInput == 'c' || cInput == 'C') {
			SelectBattleUI(gGame, bBattle, uiCnt);
		}
		MoveBattleUI(&uiCnt);
	}
	delete gGame->m_field->m_monster;
	gGame->m_field->m_monster = nullptr;
	system("cls");
}

void OutputBattle(Game* gGame, int uiCnt)
{
	gotoxy(0, 0);
	cout << "=================================================================================================================================";
	gotoxy(60, 6);
	cout << gGame->m_field->m_monster->m_name;
	gotoxy(60, 7);
	cout << "HP : " << gGame->m_field->m_monster->m_hp;
	gotoxy(0, 39);
	cout << "=================================================================================================================================" << endl;
	gotoxy(10, 42);
	cout << "HP : " << gGame->m_player->m_hp;
	gotoxy(10, 44);
	cout << "MANA : " << gGame->m_player->m_mana;
	for (int i = 40; i < 54; i++) {
		gotoxy(30, i);
		cout << "|";
		gotoxy(100, i);
		cout << "|";
	}
	gotoxy(105, 41);
	cout << "     공격";
	gotoxy(105, 44);
	cout << "     스킬";
	gotoxy(105, 47);
	cout << "     방어";
	gotoxy(105, 50);
	cout << "     아이템";
	gotoxy(105, 53);
	cout << "     도망";
	gotoxy(105, 41 + (uiCnt * 3));
	cout << ">";
}

void SelectBattleUI(Game* gGame, BBATTLE bBattle, int uiCnt)
{
	switch (uiCnt)
	{
	case BTUI_Attack:
		gGame->Attack();
		break;
	case BTUI_Magic:
		gGame->Magic();
		break;
	case BTUI_Shield:
		gGame->Shield();
		break;
	case BTUI_Item:
		gGame->Item();
		break;
	case BTUI_Run:
		gotoxy(33, 41);
		cout << "도망쳤습니다...";
		bBattle->isBattle = false;
		break;
	default:
		break;
	}
	Sleep(1000);
	system("cls");
}

void MoveBattleUI(int* uiCnt)
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		MoveupBattleUI(uiCnt);
		Sleep(100);
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		MovedownBattleUI(uiCnt);
		Sleep(100);
	}
}

void MoveupBattleUI(int* uiCnt)
{
	if (*uiCnt <= BTUI_Attack) {
		*uiCnt = BTUI_Run;
		return;
	}
	*uiCnt -= 1;
}

void MovedownBattleUI(int* uiCnt)
{
	if (*uiCnt >= BTUI_Run) {
		*uiCnt = BTUI_Attack;
		return;
	}
	*uiCnt += 1;
}
