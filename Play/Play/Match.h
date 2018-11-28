#pragma once
#include "footballer.h"
#include<utility>
#include<vector>
class Match
{
	std::vector<footballer*>A;
	std::vector<footballer*>B;
	std::pair<int, int>score = std::make_pair(0, 0);
	bool N= rand() % 2;//���� ����� ������� ������ �����
	int Time = 1;//����� ����
public:
	Match();
	bool search(footballer *, footballer* );//����� ����������� 
	bool fight(footballer *, footballer*);//������ �� ���
	bool shoot_for_goal(footballer *, footballer*);//������� ������� ��� 
	bool goal(footballer *, footballer*);
	void set_score(int, int);//���� ����
	void get_baller();//������ ����
	void players_move();//������������ ������� 
	void statistics();//���������� 
	~Match();
};

