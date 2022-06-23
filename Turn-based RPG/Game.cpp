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
		cout << "���� : x�� ������ �޴��� �����ϴ�. c�� �����Դϴ�." << endl;
		cout << "       ����Ű�� ������ �� �ֽ��ϴ�." << endl;
		cout << "==================================================" << endl;
		cout << "ĳ���͸� �����մϴ�." << endl;
		cout << "������ �����ϼ���." << endl;
		cout << "1) �˻�, 2) �ü�, 3) ������" << endl;
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
		cout << "������!";
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
		cout << "������ ���!";
		Sleep(500);
		MonsterAction();
		return;
	}
	int critical = rand() % 10;
	if (critical < 1) {
		cout << "ũ��Ƽ��!!  ";
		damage *= 2;
	}
	m_field->m_monster->m_hp -= damage;
	cout << m_field->m_monster->m_name << "���� " << damage << "������!";
	Sleep(500);
	MonsterAction();
}

void Game::Magic()
{
	gotoxy(33, 41);
	cout << "�������Դϴ�...";
	return;
}

void Game::Shield()
{
	gotoxy(33, 41);
	cout << "������ ����մϴ�!";
	int deffence = m_player->m_defence / 4;
	m_player->m_defence += deffence; // 25%���
	MonsterAction();
	m_player->m_defence -= deffence;
}

void Game::Item()
{
	gotoxy(33, 41);
	cout << "�������Դϴ�...";
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
		cout << "������ ������ ������!";
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
		cout << "������ ���!";
		return;
	}
	m_player->m_hp -= damage;
	cout << "�÷��̾�� " << damage << "������!";
}

void Game::MonsterMagic()
{

}
