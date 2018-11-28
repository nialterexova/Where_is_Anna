#include "stdafx.h"
#include "footballer.h"
#include<iostream>
footballer::footballer()
{
}
void footballer::set_XY(int X, int Y) {
	this->x_y.first = X;
	this->x_y.second = Y;
}
void footballer::set_backup(int N) {
	if (N == 0)
		this->backup = N;
	this->backup += N;
}
void footballer::set_energy(int N) {
	this->energy -= 1;
	if (N > 1)
		this->energy = N;

}
bool footballer::react_ball() {
	return this->ball;
}

bool footballer::react_player() {
	return this->player;
}

std::pair<int, int> footballer::get_XY() {
	return this->x_y;
}
footballer::~footballer()
{
}
