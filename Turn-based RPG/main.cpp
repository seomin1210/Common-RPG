#include "map.h"
#include "console.h"
#include "Game.h"

char strMap[20][HEIGHT][WEIGHT];

int main() {
	Cursorhide();
	fullscreen();
	Game game;
	game.Init();
	BATTLE tBattle;
	int mapCnt = 0;
	int uiCnt = 0;
	srand((unsigned int)time(NULL));
	SetMap(strMap, game.m_player);
	while (game.m_player->isGameStop == false && game.m_player->isGameOver == false)
	{
		gotoxy(0, 0);
		OutputMap(strMap, game.m_player, mapCnt);
		if (game.m_player->isOpenMenu == true) {
			OutputMenu(game.m_player, uiCnt);
		}
		char cInput = _getch();
		if ((cInput == 'x' || cInput == 'X') && tBattle.isBattle == false && game.m_player->isOpenMenu == false) {
			OutputMenu(game.m_player, uiCnt);
		}
		else if ((cInput == 'x' || cInput == 'X') && tBattle.isBattle == false && game.m_player->isOpenMenu == true) {
			CloseMenu(game.m_player, &uiCnt);
		}
		else if ((cInput == 'c' || cInput == 'C') && game.m_player->isOpenMenu == true) {
			SelectMenu(game.m_player, uiCnt);
		}
		if (game.m_player->isOpenMenu == false)
			mapCnt = Moveplayer(strMap, game.m_player, mapCnt, &tBattle);
		else
			MoveMenuUI(&uiCnt);
		if (tBattle.isBattle) {
			game.m_field->Startbattle(&game, &tBattle);
		}
	}
	system("cls");
	gotoxy(0, 0);
	cout << "게임을 종료합니다." << endl;
	return 0;
}