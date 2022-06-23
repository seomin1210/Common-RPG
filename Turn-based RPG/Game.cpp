#include "Game.h"
#include "map.h"
#include "Player.h"
#include <iostream>
using namespace std;

Game::Game() : m_player(nullptr), m_field(nullptr)
{

}

Game::~Game()
{
	if(m_player == nullptr)
		delete m_player;
	if (m_field == nullptr)
		delete m_field;
}

void Game::Init()
{
	m_field = new Field();
	Createplayer();
}

void Game::Createplayer()
{
	while (m_player == nullptr) {
		system("cls");
		cout << "==================================================" << endl;
		cout << "설명 : x를 누르면 메뉴가 열립니다. c는 선택입니다." << endl;
		cout << "       방향키로 움직일 수 있습니다." << endl;
		cout << "==================================================" << endl;
		cout << "캐릭터를 생성합니다." << endl;
		cout << "직업을 선택하세요." << endl;
		cout << "1) 검사, 2) 궁수, 3) 마법사" << endl;
		cout << "==============================" << endl;
		cout << ">";
		int iInput = 0;
		cin >> iInput;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		if (iInput == PT_KNIGHT)
			m_player = new Knight();
		else if (iInput == PT_ARCHER)
			m_player = new Archer();
		else if (iInput == PT_MAGE)
			m_player = new Mage();
	}
}

void Game::Attack()
{
	float miss = rand() % 20;
	if (miss <= 1) {
		gotoxy(33, 41);
		cout << "빗나감!";
		MonsterAction();
		return;
	}
	int damageArr[11];
	for (int i = 0; i <= 10; i++) {
		damageArr[i] = m_player->m_attack - 5 + i;
	}
	int idx = rand() % 11;
	int damage = damageArr[idx] - m_field->m_monster->m_defence;
	gotoxy(33, 41);
	if (damage <= 0) {
		cout << "공격을 방어!";
		Sleep(500);
		MonsterAction();
		return;
	}
	int critical = rand() % 10;
	if (critical < 1) {
		cout << "크리티컬!!  ";
		damage *= 2;
	}
	m_field->m_monster->m_hp -= damage;
	cout << m_field->m_monster->m_name << "에게 " << damage << "데미지!";
	Sleep(500);
	MonsterAction();
}

void Game::Magic()
{
	gotoxy(33, 41);
	cout << "구현중입니다...";
	return;
}

void Game::Shield()
{
	gotoxy(33, 41);
	cout << "방어력이 상승합니다!";
	int deffence = m_player->m_defence / 4;
	m_player->m_defence += deffence; // 25%상승
	MonsterAction();
	m_player->m_defence -= deffence;
}

void Game::Item()
{
	gotoxy(33, 41);
	cout << "구현중입니다...";
	return;
}

void Game::MonsterAction()
{
	MonsterAttack();
	/*int action = rand() % 10;
	if (action <= 7) {
		MonsterAttack();
	}
	else {
		MonsterMagic();
	}*/
}

void Game::MonsterAttack()
{
	float miss = rand() % 20;
	if (miss <= 1) {
		gotoxy(33, 42);
		cout << "몬스터의 공격이 빗나감!";
		return;
	}
	int damageArr[11];
	for (int i = 0; i <= 10; i++) {
		damageArr[i] = m_field->m_monster->m_attack - 5 + i;
	}
	int idx = rand() % 11;
	int damage = damageArr[idx] - m_player->m_defence;
	gotoxy(33, 42);
	if (damage <= 0) {
		cout << "공격을 방어!";
		return;
	}
	m_player->m_hp -= damage;
	cout << "플레이어에게 " << damage << "데미지!";
}

void Game::MonsterMagic()
{

}
