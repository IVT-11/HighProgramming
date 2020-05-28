#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h> 
#include<conio.h>
#include <iostream>
#include <limits>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

typedef unsigned short u_short;
typedef unsigned int u_int;
typedef enum Direction { upArrow, downArrow, rightArrow, leftArrow } Direction;

using namespace std;
u_short Field[4][4];
u_short CurX, CurY;

//Создание игровой площадки 
void CreateField() {
	u_short arr[16], n, i, buf, k = 0;
	bool flag = false;
	srand(time(NULL));
	for (n = 0; n < 16; ) {
		flag = false;
		buf = rand() % 16 + 1;
		for (i = 0; i < n; i++) {
			if (arr[i] == buf) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			arr[n] = buf;
			n++;
		}
	}
	for (n = 0; n < 4; n++)
		for (i = 0; i < 4; i++) {
			Field[n][i] = arr[k];
			k++;
		}
	Field[3][3] = 0;
	CurX = 3; CurY = 3;
	return;
}

// Организация перемещений
void Move(Direction dir) {
	switch (dir) {
	case upArrow:
		if (CurY > 0)
		{
			Field[CurY][CurX] = Field[CurY - 1][CurX];
			Field[CurY - 1][CurX] = 0;
			CurY--;
		}
		else
			printf("ВЫХОД ЗА ПРЕДЕЛЫ ПОЛЯ \n\n");
		break;
	case downArrow:
		if (CurY < 3)
		{
			Field[CurY][CurX] = Field[CurY + 1][CurX];
			Field[CurY + 1][CurX] = 0;
			CurY++;
		}
		else
			printf("ВЫХОД ЗА ПРЕДЕЛЫ ПОЛЯ \n\n");
		break;
	case rightArrow:
		if (CurX < 3)
		{
			Field[CurY][CurX] = Field[CurY][CurX + 1];
			Field[CurY][CurX + 1] = 0;
			CurX++;
		}
		else
			printf("ВЫХОД ЗА ПРЕДЕЛЫ ПОЛЯ \n\n");
		break;
	case leftArrow:
		if (CurX > 0)
		{
			Field[CurY][CurX] = Field[CurY][CurX - 1];
			Field[CurY][CurX - 1] = 0;
			CurX--;
		}
		else
			printf("ВЫХОД ЗА ПРЕДЕЛЫ ПОЛЯ \n\n");
		break;
	}
}

//ВЫВОД ПОЛЯ
void coutArr() {
	system("cls");
	printf("\n");
	for (u_int i = 0; i < 4; i++) {
		for (u_int j = 0; j < 4; j++) {
			printf("\t%d ", Field[i][j]);
		}
		printf("\n\n");
	}
	return;
}

//Проверка на выигрыш 
bool total() {
	u_short k = 1;
	bool flag = true;
	for (u_short i = 0; i < 4; i++) {
		for (u_short j = 0; j < 4; i++) {
			if (Field[i][j] != k % 16)
				flag = true;
			else {
				flag = false;
				break;
			}
			k++;
		}
	}
	return flag;
}

int main() {
	setlocale(LC_ALL, "Russian");
	printf("\n     @@@@@@@@      @@@@@@    @@@@@@@@    @@    @@       @@@@       @@   @@   @@     @@   @@     @@    @@ \n");
	printf("     @@    @@     @@   @@       @@       @@@@@@@@      @@  @@      @@   @@   @@     @@@@        @@  @@@@ \n");
	printf("     @@    @@      @@  @@       @@       @@    @@     @@@@@@@      @@   @@   @@     @@  @@      @@@@  @@ \n");
	printf("     @@    @@     @@   @@       @@       @@    @@    @@@    @@     @@@@@@@@@@@@     @@   @@     @@    @@ \n\n");
	printf("Добро пожаловать в игру пятнашки!\n");
	printf("Имеется поле 4х4 для набора из 15 элементов(чисел),\n");
	printf("соответственно на поле остаётся незаполненным один элемент.\n");
	printf("Цель игры — перемещая числа по полю, добиться упорядочивания их по номерам, \n");
	printf("желательно сделав как можно меньше перемещений.\n");
	cout << "Нажмите 'Ввод' чтобы начать игру!";
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	CreateField();
	coutArr();
	printf("Выберите направление  - стрелочки 'вверх, вниз, влево, вправо'\n");
	int c = 0;
	while (!total()) {
		c = 0;
		switch ((c = getch())) {
		case KEY_UP:
			Move(upArrow);
			break;
		case KEY_DOWN:
			Move(downArrow);
			break;
		case KEY_LEFT:
			Move(leftArrow);
			break;
		case KEY_RIGHT:
			Move(rightArrow);
			break;
		case 27:
			printf("ХОРОШАЯ ПОПЫТКА! \n");
			return 0;
			break;
		default:
			break;
		}
		coutArr();
	}
	printf(" ====Поздравляем! Нажмите Esc для выхода====  ");
	return 0;
}
