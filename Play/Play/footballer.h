#pragma once
#include<utility>
#include<iostream>
class footballer
{
protected:
	int power,
		energy,
		backup = 0;//���������� ����� ������� �� ��������� 
	std::pair<int, int>x_y;//���������� 
	bool player=1,
		 ball=0;
public:
	footballer();
	footballer(int x, int y){//��� ������� ���������, ����������� 
		this->power = rand() % 101 + 1;
		this->energy = rand() % 101 + 1;
		this->x_y = std::make_pair(x,y);
	}
	footballer(const footballer & T) :power(T.power), energy(T.energy), x_y(T.x_y), player(T.player), ball(T.ball) {}//����������� ����������� 
	void set_backup(int N);	//������� ��� �������� �� N ����� 
	void set_player(bool z) { this->player = z; }// �������� ������ �� ����� 
	void set_ball(bool z) { this->ball = z; }// �������� ������� �� ����� 
	void set_XY(int X, int Y);//�������� ���������� 
	void set_energy(int N);// �������� �������
	bool react_ball();// ������� �� ����� 
	bool react_player();//������ �� 
	int get_backup() { return this->backup; }//������� ����� ��������� 
	int get_energy() { return this->energy; }//����� ������ ������� 
	int get_power() { return this->power; }//����� ������ ���� 
	int get_X() { return x_y.first; }//���������� ���������� �
	int get_Y() { return x_y.second; }//���������� ���������� �
	std::pair<int, int> get_XY();//��������� ���������� 
		~footballer();

};
class Ac : public footballer {
public:
	Ac() :footballer() {//������ �����������  
		this->power = rand() % 101 + 1;
		this->energy = rand() % 101 + 1;
		this->x_y = std::make_pair(rand() % 25+1 , rand()%15+1);
	}
	Ac(int x, int y) :footballer(x, y) {}
};
class Bc : public footballer {
public:
	Bc() :footballer()	 {//������ ����������� 
		this->power = rand() % 101 + 1;
		this->energy = rand() % 101 + 1;
		this->x_y = std::make_pair(rand() % 25 + 26, rand() % 15 + 1);
	  }
	Bc(int x, int y) :footballer(x, y) {}
};
