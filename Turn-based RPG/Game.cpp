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
		cout << "          ````````````                       ```     ``##`                                                                            " << endl;
		cout << "          ############              ########## `    ` `##`                  ##########````   ```##########` `       ` ` #########` ```" << endl;
		cout << "                    ` `             `        ``     ` `##`                ``###`````######     `##``````#####       `#####`````#####` " << endl;
		cout << "    `######################`    ##################  ` `##`                ` ##`      ```###   ``##        `###` `  ####  `    ``  ``` " << endl;
		cout << "        ```     ` ` ` ```      ```````````````````` ` `##`    `           ` ##`        `### ` ``##        ``##` ` ###`                " << endl;
		cout << "       ``###############       `     `######`` `` ``` `#######`           ` ##`         ###   ``##         `##`  `##``                " << endl;
		cout << "       ###``     `  ` ###`       ``####`   `####   `` `##``````           ` ##```  ````###  ` ``##    ``  `###   ### `     `          " << endl;
		cout << "       `####` ` `  `####`        `###`  ` ````##`   ` `##`                ` ############      ``############`   `### `    ` `#######` " << endl;
		cout << "         ``##########``` `        ####`  ` ` ###`` `` `##`                ` ##` `  ``###``    ``########`````    ### ``    ```````##` " << endl;
		cout << " `                           ` `` ` ##########``    ` `##`                ` ##`     ```###  ` ``##               `###             ##` " << endl;
		cout << " `#############################```         ` ```    ` `##`                ` ##`        `##    ``##                ####`           ##` " << endl;
		cout << "  ` `  `` ```````````````````        `###            ``##`                ` ##`        `###`` ``##              `  `###```      ` ##` " << endl;
		cout << "      ##``                            ###`                                  ##``       `###``  `##                   #######```#####``" << endl;
		cout << "      ##``                            ###`                                 `##`          ###`` ```                  ` ` `########`    " << endl;
		cout << "      ##````````````````````          ###                  ``                                                                         " << endl;
		cout << "      ####################``         `####################                                                                            " << endl;
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
		setcolor(13, 0);
		gotoxy(33, 41);
		cout << "������!";
		setcolor(14, 0);
		MonsterAction();
		return;
	}
	int damageArr[11];
	for (int i = 0; i <= 10; i++) {
		damageArr[i] = m_player->m_attack - 5 + i;
	}
	int idx = rand() % 11;
	int damage = damageArr[idx];
	gotoxy(33, 41);
	int critical = rand() % 10;
	if (critical < 1) {
		setcolor(4, 0);
		cout << "ũ��Ƽ��!!  ";
		damage *= 2;
		setcolor(14, 0);
	}
	damage -= m_field->m_monster->m_defence;
	if (damage <= 0) {
		setcolor(7, 0);
		cout << "������ ���!";
		Sleep(500);
		setcolor(14, 0);
		MonsterAction();
		return;
	}
	m_field->m_monster->m_hp -= damage;
	cout << m_field->m_monster->m_name << "���� " << damage << "������!";
	Sleep(500);
	MonsterAction();
}

void Game::Magic()
{
	gotoxy(33, 41);
	if (m_player->m_mana < m_player->m_skillMana) {
		cout << "������ �����մϴ�!";
		return;
	}
	float miss = rand() % 20;
	if (miss <= 1) {
		setcolor(13, 0);
		gotoxy(33, 41);
		cout << "������!";
		setcolor(14, 0);
		MonsterAction();
		return;
	}
	int damageArr[11];
	for (int i = 0; i <= 10; i++) {
		damageArr[i] = m_player->m_attack - 5 + i;
	}
	int idx = rand() % 11;
	int damage = damageArr[idx];
	//damage - m_field->m_monster->m_defence + m_player->m_magic;
	int idx1 = rand() % 11;
	int idx2 = rand() % 11;
	int skillDamageArr[11];
	for (int i = 0; i <= 10; i++) {
		skillDamageArr[i] = m_player->m_magic - 5 + i;
	}
	int skillIdx = rand() % 11;
	m_player->m_mana -= m_player->m_skillMana;
	gotoxy(33, 41);
	switch (m_player->m_playerType)
	{
	case PT_KNIGHT:
		damage = damage + m_player->m_attack / 2 + m_player->m_magic - m_field->m_monster->m_defence;
		break;
	case PT_ARCHER:
		
		damage = damage + damageArr[idx1] / 2 + damageArr[idx2] / 3 + m_player->m_magic - m_field->m_monster->m_defence;
		break;
	case PT_MAGE:
		damage += skillDamageArr[skillIdx] * 2 - m_field->m_monster->m_defence;
		break;
	default:
		break;
	}
	int critical = rand() % 10;
	if (critical < 1) {
		setcolor(4, 0);
		cout << "ũ��Ƽ��!!  ";
		damage *= 2;
		setcolor(14, 0);
	}
	if (damage <= 0) {
		setcolor(7, 0);
		cout << "������ ���!";
		Sleep(500);
		setcolor(14, 0);
		MonsterAction();
		return;
	}
	m_field->m_monster->m_hp -= damage;
	cout << "��ų! " << m_player->m_skillName << "! " << m_field->m_monster->m_name << "���� " << damage << "������!";
	MonsterAction();
}

void Game::Shield()
{
	setcolor(8, 0);
	gotoxy(33, 41);
	cout << "������ ����մϴ�!";
	int deffence = m_player->m_defence / 4;
	m_player->m_defence += deffence; // 25%���
	setcolor(14, 0);
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
	int action = rand() % 10;
	if (action <= 7) {
		MonsterAttack();
	}
	else {
		MonsterMagic();
	}
}

void Game::MonsterAttack()
{
	float miss = rand() % 20;
	if (miss <= 1) {
		setcolor(13, 0);
		gotoxy(33, 42);
		cout << "������ ������ ������!";
		EndTurn();
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
		setcolor(7, 0);
		cout << "������ ���!";
		EndTurn();
		return;
	}
	m_player->m_hp -= damage;
	cout << "�÷��̾�� " << damage << "������!";
	EndTurn();
}

void Game::MonsterMagic()
{
	if (m_field->m_monster->m_mana < m_field->m_monster->m_skillMana) {
		MonsterAttack();
		return;
	}
	if (m_field->m_monster->isBleeding == true && m_field->m_monster->m_creaturetype == MT_WOLF) {
		MonsterAttack();
		return;
	}
	float miss = rand() % 20;
	if (miss <= 1) {
		setcolor(13, 0);
		gotoxy(33, 42);
		cout << "������ ������ ������!";
		EndTurn();
		return;
	}
	int damageArr[11];
	for (int i = 0; i <= 10; i++) {
		damageArr[i] = m_field->m_monster->m_attack - 5 + i;
	}
	int idx = rand() % 11;
	int damage = damageArr[idx] - m_player->m_defence + m_field->m_monster->m_magic;
	m_field->m_monster->m_mana -= m_field->m_monster->m_skillMana;
	gotoxy(33, 42);
	if (damage <= 0) {
		setcolor(7, 0);
		cout << "������ ���!";
		EndTurn();
		return;
	}
	m_player->m_hp -= damage;
	cout << "��ų! " << m_field->m_monster->m_skillName << "! �÷��̾�� " << damage << "������!";
	int random = rand() % 2;
	gotoxy(33, 43);
	switch (m_field->m_monster->m_monsterType)
	{
	case MT_SLIME:
		m_player->m_hp -= m_player->m_hp / 10;
		cout << "�꼺���� ���� �÷��̾�� " << m_player->m_hp / 10 << "������!";
		break;
	case MT_WOLF:
		m_field->m_monster->isBleeding = true;
		skillTurn = turn;
		break;
	case MT_GOBLIN:
		m_field->m_monster->m_hp += damage / 10;
		if (m_field->m_monster->m_hp >= m_field->m_monster->m_maxHp)
			m_field->m_monster->m_hp = m_field->m_monster->m_maxHp;
		cout << "����� �÷��̾��� ü���� " << m_player->m_hp / 10 << "��ŭ ���Ѿҽ��ϴ�!";
		break;
	case MT_ORC:
		if (random == 0) {
			m_player->m_hp -= damage / 2;
			cout << "�߰����� Ÿ���� ���ɴϴ�! " << damage / 2 << "������!";
		}
		break;
	case MT_DRAGON:
		gotoxy(33, 42);
		m_player->m_hp -= damage;
		cout << "��ų! " << m_field->m_monster->m_skillName << "! �÷��̾�� " << damage * 2 << "������!";
		break;
	default:
		break;
	}
	EndTurn();
}

void Game::EndTurn()
{
	turn++;
	if (m_field->m_monster->isBleeding == true) {
		cout << "������ ���� �÷��̾�� " << m_player->m_hp / 10 << "������!";
		if ((turn - skillTurn) == 3) {
			m_field->m_monster->isBleeding = false;
		}
	}
	if (m_field->m_monster->m_mana < m_field->m_monster->m_maxMana)
		m_field->m_monster->m_mana += 2;
	if (m_player->m_mana < m_player->m_maxMana)
		m_player->m_mana += 2;
}
