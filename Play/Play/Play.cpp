// Play.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Match.h"
#include <time.h>
int main(){
	srand(time(0));
	Match E;
	E.players_move();
	E.statistics();
	system("pause");
    return 0;
}

