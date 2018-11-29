#pragma once
#include "footballer.h"
#include<utility>
#include<vector>
class Match
{
	std::vector<footballer*>A;
	std::vector<footballer*>B;
	std::pair<int, int>score = std::make_pair(0, 0);
	bool N= rand() % 2;//‘лаг кака€ команда владее м€чом
	int Time = 1;//врем€ игры
public:
	Match();
	bool search(footballer *, footballer* );//поиск противников 
	bool fight(footballer *, footballer*);//борьба за м€ч
	bool shoot_for_goal(footballer *, footballer*);//попытка забитьт гол 
	bool goal(footballer *, footballer*);
	void set_score(int, int);//счет игры
	void get_baller();//рандом м€ча
	void players_move();//передвижение игроков 
	void statistics();//статистика 
	~Match();
};

