#pragma once
#include<utility>
#include<iostream>
class footballer
{
protected:
	int power,
		energy,
		backup = 0;//количество ходов сколько он пропустил 
	std::pair<int, int>x_y;//координаты 
	bool player=1,
		 ball=0;
public:
	footballer();
	footballer(int x, int y){//для задание координат, конструктор 
		this->power = rand() % 101 + 1;
		this->energy = rand() % 101 + 1;
		this->x_y = std::make_pair(x,y);
	}
	footballer(const footballer & T) :power(T.power), energy(T.energy), x_y(T.x_y), player(T.player), ball(T.ball) {}//конструктор копирования 
	void set_backup(int N);	//счётчик для пропуска на N ходов 
	void set_player(bool z) { this->player = z; }// изменить играет ли игрок 
	void set_ball(bool z) { this->ball = z; }// изменить владеет ли мячом 
	void set_XY(int X, int Y);//изменить координаты 
	void set_energy(int N);// изменить энергию
	bool react_ball();// владеет ли мячом 
	bool react_player();//играет ли 
	int get_backup() { return this->backup; }//сколько ходов пропустил 
	int get_energy() { return this->energy; }//какая сейчас энергия 
	int get_power() { return this->power; }//какая сейчас сила 
	int get_X() { return x_y.first; }//возвращает координату Х
	int get_Y() { return x_y.second; }//возвращает координату У
	std::pair<int, int> get_XY();//возращает координаты 
		~footballer();

};
class Ac : public footballer {
public:
	Ac() :footballer() {//пустой конструктор  
		this->power = rand() % 101 + 1;
		this->energy = rand() % 101 + 1;
		this->x_y = std::make_pair(rand() % 25+1 , rand()%15+1);
	}
	Ac(int x, int y) :footballer(x, y) {}
};
class Bc : public footballer {
public:
	Bc() :footballer()	 {//пустой конструктор 
		this->power = rand() % 101 + 1;
		this->energy = rand() % 101 + 1;
		this->x_y = std::make_pair(rand() % 25 + 26, rand() % 15 + 1);
	  }
	Bc(int x, int y) :footballer(x, y) {}
};
