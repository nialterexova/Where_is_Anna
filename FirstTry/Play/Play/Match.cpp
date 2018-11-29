#include "stdafx.h"
#include "Match.h"
#include "footballer.h"
#include<vector>
#include<iostream>
using namespace std;
Match::Match()
{
	for (int i = 0; i < 11; i++) {
		if (i==0) {//расстановка вратарей с координатами 
			A.push_back(new Ac(1, 15));
			B.push_back(new Bc(50, 15));
			i++;
		}
		A.push_back(new Ac);//растановка других игроков 
		B.push_back(new Bc);
	}
	get_baller();//распределение мяча ;

}
void Match::set_score(int A, int B) {//Счет игры
	this->score.first += A;
	this->score.second += B;
}

void Match::get_baller() {// поднимается флаг если игрок владеет мячом  
	int i = rand() % 10 + 1;
	switch (N) {
	case 0:
		if (A[i]->react_player() == true) {
			cout << " time: " << this->Time << " ";
			A[i]->set_ball(true);
			cout << "Player A" << i << " possess the ball" << endl;
		}
		else get_baller();
		break;
	case 1:
		if (B[i]->react_player() == true) {
			cout << " time: " << this->Time << " ";
			B[i]->set_ball(true);
			cout << "Player B" << i << " possess the ball" << endl;
		}
		else get_baller();
		break;
	}
}


void Match::players_move() {//перемещение игроков
	int temp = 1;
	std::pair<int, int>Va(6,15);
	std::pair<int, int>Vb(45, 15);
	
	do {
		for (int i = 1; i <11; i++) {
			if (temp % 5 == 0) {
				A[i]->set_energy(1); B[i]->set_energy(1);// каждый 5 ход отнимается энергия 
			}
			if( (A[i]->get_energy() == 0)&&(A[i]->get_backup()==0)) 
				A[i]->set_player(false); 
				
		
			if ((B[i]->get_energy() == 0) && (B[i]->get_backup() == 0)) 
				B[i]->set_player(false);
			
			try {//исключение 
			  if(A[i]->react_player() == false) throw 1;
			  if (B[i]->react_player() == false) throw 2;
			}
			catch(int a){//уход игрока с поля на 10 ходов....
				if (a == 1) {
					A[i]->set_XY(-100, -100);
					A[i]->set_backup(1);
					if (A[i]->react_ball() == true) {//смена мяча при выбывание игрока 
						A[i]->set_ball(false);
						cout << "  delete A" << i;
						this->N= rand() % 2;
						get_baller();
					}
					if (A[i]->get_backup() == 10) {
						A[i]->set_backup(0);
						A[i]->set_energy(20);
						A[i]->set_player(true);
						A[i]->set_XY(rand() % 50 + 1, rand() % 15 + 1);
				    }
				   
				}
				if (a == 2) {
					B[i]->set_XY(-100, -100);
					B[i]->set_backup(1);
					if (B[i]->react_ball() == true) {//смена мяча при выбывание игрока 
						B[i]->set_ball(false);
						cout << "  delete B" << i;
						this->N = rand() % 2;
						get_baller();
					}
					if (B[i]->get_backup() == 10) {
						B[i]->set_backup(0);
						B[i]->set_energy(20);
						B[i]->set_player(true);
						B[i]->set_XY(rand() % 50 + 1, rand() % 15 + 1);
					}
				}
			}
			if (A[i]->react_player() == true)/// можно ли объединить условие 78 и 80
		     A[i]->set_XY(rand() % 50 + 1, rand() % 15 + 1);//перемещение игроков каманд которые в игре
			if (B[i]->react_player() == true)
		     B[i]->set_XY(rand() % 50 + 1, rand() % 15 + 1);
			if ((A[i]->react_ball() == 1) || (B[i]->react_ball() == 1)) {
				if (search(A[i], B[i]) == false) {//если не отобрали 
					if ((A[i]->get_XY() == Vb) || (B[i]->get_XY() == Va))//находится ли игрок с мячом напротив вратаря 
					{

						shoot_for_goal(A[i], B[i]);//удар по воротам 
					}
				}
			}
       
		}
		temp++;
		this->Time = temp;
	} while ((temp != 10000)&&(this->score.first!=5)&&(this->score.second!=5));

}

bool Match::shoot_for_goal(footballer *K, footballer*M) {//удар в ворота 
	cout <<"Time: "<<this->Time<< " shoot_for_goal ....";
	int temp = this->N;
	switch (temp) {
	case 0:
		if (K->react_player() == true) {
			if (goal(K, B[0]) == true)//забит гол рандомится мяч среди своей команды 
			{
				set_score(1, 0);//изменяется счет
				cout<<"goal to the team A "<<" Set score "<< score.first << "/" << score.second << std::endl;
				return 1;
			}
			else {
				cout << " A->B " << endl;
				this->N = true;//промах, мяч передается другой команде B
				get_baller();
				return 0;
			}
			return 0;
		}
	case 1:
		if (M->react_player() == true) {
			if (goal(M, A[0]) == true)//забит гол рандомится мяч среди своей команды 
			{
				set_score(0, 1);//изменяется счет
				cout << "goal to the team B " << " Set score " << score.first << "/" << score.second << std::endl;
				return 1;
			}
			else {
				cout << " B->A" << endl;
				this->N = false;//промах, мяч передается другой команде A
				get_baller();
				return 0;
			}
		}
		return 0;
	}
}

bool Match::goal(footballer *K, footballer* M) {//гол или не гол, команда К забивает команде М
	int temp = 50 + (K->get_power() - M->get_power()) / 2;
	int i = rand() % 100 + 1;
	if ((i <= temp) && (temp > 0)) {//гол!!!
		cout << "Choal!!! " << endl;
		K->set_ball(false);//мяч перешел к другому игроку 
		get_baller();//мяч остается в команде 
		return 1;//возращает 1 если гол 
	}
	else {
		cout << "Out ";
		K->set_ball(false);//мяч уходит от игрока 
		return 0;
	}
}

bool Match::search(footballer*Axy, footballer*Bxy){//есть ли рядом противник 
	int temp = this->N;
	switch (temp) {
	case 0:// флаг опущен, мяч у команды А	
			for (int j = 1; j < 11; j++) {
				if (B[j]->react_player() == true) {//проверяет только если игрок в игре 
					if ((abs(B[j]->get_X() - Axy->get_X()) <= 1) || (abs(B[j]->get_Y() - Axy->get_Y()) <= 1)) {//проверка есть ли кто рядорм 
						if (fight(Axy, B[j]) == 1) {//если мяч отобрали 
							cout << "-> B" << j <<" time: "<<this->Time<<endl;
							this->N = 1;//флаг поднят, мяч у каманды В
							return 1;//возвращает true если мяч сменил команду 
						}
					}
				}

			}
		return 0;//возвращает false если мяч остался в своей команде 
	case 1: // флаг поднят, мяч у команды В
			for (int j = 1; j < 11; j++) {
				if (A[j]->react_player() == true) {//проверяет только если игрок в игре 
					if ((abs(A[j]->get_X() - Bxy->get_X()) == 1) || (abs(A[j]->get_X() - Bxy->get_X()) == 1)) {//проверка есть ли кто рядорм 
						if (fight(Bxy, A[j]) == 1) {//если мяч отобрали 
							cout << "-> A" << j  << " time: " << this->Time << endl;
							this->N = 0;// флаг опущен, мяч у команды А
							return 1;//возвращает true если мяч сменил команду 
						}
					}
				}
			}
		return 0;//возвращает false если мяч остался в своей команде 
	}
}

bool Match::fight(footballer*A, footballer*B) {//борьба за мяч
	int temp = 50 + (B->get_power() - A->get_power())/2;
	int i = rand() % 100 + 1;
	if ((i <= temp)&&(temp>0)) {//игрок отобрал мяч 
		B->set_ball(true);
		A->set_ball(false);
		return 1;
	}
	return 0;
}


void Match::statistics() {//статистика игры//
	//std::cout << this->N<<" "<<std::endl;
	std::cout << score.first << "/" << score.second<<std::endl;
}

Match::~Match()
{
	A.clear();
	B.clear();
}
