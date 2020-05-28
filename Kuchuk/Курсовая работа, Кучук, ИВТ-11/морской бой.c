#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#define SIZE 10

typedef void (*u)(char fm[][SIZE]); // указатель на функцию printMaps printMaps

int menu();
void printMaps(char [][SIZE]);
void game(int );
void initialization(char [][10]);
void verticalShip(char [][SIZE], int);
void horizontalShip(char [][SIZE], int);
void maskMaps(char [][SIZE], char [][SIZE], char [][SIZE], char [][SIZE]);
void battleuc(char [][SIZE], char [][SIZE], char [][SIZE], char [][SIZE]) ;
int battcc(char [][SIZE], char [][SIZE], int, int, u );
void battleUu(char [][SIZE], char [][SIZE], char [][SIZE] ,char [][SIZE]);
void battlecc(int);
bool shot(char [][SIZE], char [][SIZE], bool , int ,int );
void manualPlacement(char [][SIZE]);
void rVerticalShip(char [][SIZE], int);
void rHorizontalShip(char [][SIZE], int);


int main(int argc, char const *argv[])
{
	int menu;
    int menu2;
    
    srand( time(NULL) );
    
    printf( "Игра 'Морской бой'\nВыберите вариант:\n"
			" 1. Начать игру\n 2. Выход\n");
    while(1)
    {
    scanf("%d",&menu);
    // system("clear");
    switch (menu)
      {
        case 1: printf( " Меню игры:\n 1. Два игрока\n 2. Игрок и компьютер\n 3. Два компьютера\n 4. Выход\n");
                scanf("%d",&menu2);
                game(menu2);
                return menu2;
        case 2 : printf(" BB");
			return 0;
		default:
			printf(" ERROR\n");
			continue;
        }
    }
	return 0;
}

void printMaps(char field[][SIZE]) // реализация ффункции после заполнения компуктера
{
	printf("%3c", ' ');
	for (int i = 0; i < 10; i++)
		printf("%3d", i + 1);
	printf("\n");
	for(int j = 0; j < 10; j++)
	{
		printf("%3d", j + 1);
		for (int i = 0; i < 10; i++)
			printf("%3c", field[i][j]);
		printf("\n");
	}
}

void maskMaps(char field[][SIZE], char field2[][SIZE], char field_m[][SIZE], char field_m2[][SIZE]) // функция отображения карты и маски на нее
{	    
	for (int j = 0; j < 10; j++)
	 	for (int i = 0; i < 10; i++)
	 	{
	 		field[i][j] = '~';
	 		field2[i][j] = '~';
        }
	for (int j = 0; j < 10; j++)
		for (int i = 0; i < 10; i++)
		{
			field_m[i][j] = '~';
			field_m2[i][j] = '~';
		}
}

void game(int menu)	
{
	char f1[SIZE][SIZE];
	char f2[SIZE][SIZE];
	char fm1[SIZE][SIZE];
	char fm2[SIZE][SIZE];
	int x,y, count = 0;
	int quantsh=4;
	bool check;

	int size; // размерность корабля
	int r;
	int menu2;
	
	// system("clear"); 
    maskMaps(f1,f2,fm1,fm2); 

	if (menu == 1)
	{
        // system("clear");
        printf( " Меню игры:\n 1. Автоматическая расстановка\n 2. Ручная расстановка\n 3. Выход\n");
		scanf("%d",&menu2);
	
        // system("clear");
        if (menu2==1)
        {
		    initialization(f2);
		    initialization(f1);
		    
			battleUu(f2, fm2, f1, fm1);
	    }
        if (menu2 == 2)
	    {
	    	manualPlacement(f2);
	    	manualPlacement(f1);
			battleUu(f2, fm2, f1, fm1);		
	    }
	    if (menu2 == 3)
	    {
	        printf(" Вы вышли!");
		    exit(0);
	    }
	}
 
    if (menu == 2)
	{
        printf( " Меню игры:\n 1. Автоматическая расстановка\n 2. Ручная расстановка\n 3. Выход\n");
		scanf("%d",&menu2);
        // system("clear");
        if (menu2==1)
        {
		    initialization(f2);
		    initialization(f1);
	    }
        if (menu2 == 2)
	    {
	        printMaps(f2);
	    	manualPlacement(f2);
	    }
	    else
	        printf(" Вы вышли!\n");
			exit(0);
    
        // system("clear");
	    check = true;
        
        battleuc(f2,fm2, f1, fm1);
	}
	if (menu == 3)
	{
		initialization(f2);
		initialization(f1);
		
		int count1=20;
		int count2=20;
	
		do {
		    count1 = battcc(f1,fm1, 1,count1, printMaps);
		    count2 = battcc(f2,fm2, 2, count2, printMaps);
		} while (count1!=0 && count2!=0);
		battlecc(count2);
	}
	else
	{
		printf("Вы вышли!");
		exit(0);
	}
}

void battleuc(char field2[][SIZE],char field_m2[][SIZE], char field[][SIZE] ,char field_m1[][SIZE]) 
{
	int x, y, menu2;
	int usr_count = 20, cmp_count = 20;
	bool step;
	printMaps(field2);
	do {
		step = true;
		while (step && usr_count) 
		{
			printf( "\nВаш ход!:\n Определите цель: х="); scanf("%d", &x);
			printf( "y= "); scanf("%d", &y);
            
			    if(x<1 || x>10 || y<1 || y>10)
			    {
			    	printf( "\nВЫХОД ЗА ПРЕДЕЛЫ\n");
			    	continue;
			    }
			    
		        if (field[y-1][x-1] == 'X' || field_m1[y-1][x-1] == 'X' || field[y-1][x-1] == 'O' || field_m1[y-1][x-1] == 'O')
		        {
			    	printf( "\nБЫЛО\n");
			    	continue;
			    }

		        x--;y--;

			while (step) 
			{
				step = shot(field_m1,  field, step,  x, y);
				
				if (step) 
				{
					printf("\nПОПАДАНИЕ\n");
					
					usr_count--;
					printf("\n");
					printf("\n");
                    printMaps(field_m1);

					if ( (field[x][y] == '#' || field[x - 1][y] == '#' || field[x - 1][y + 1] == '#' || field[x][y + 1] == '#' || field[x + 1][y + 1] == '#' || 
					field[x + 1][y] 	== '#' || field[x + 1][y - 1] == '#' || field[x][y - 1] == '#' || field[x - 1][y - 1] == '#') || (x<1 || x>10 || y<1 || y>10) )
						break;

					else 
						printf("\nУБИТ\n");
					break;
				}
				else
				{
					printf("\nПРОМАХ\n");
                    printMaps(field_m1);
					break;
				}
			}
		}
		
		if (!usr_count) 
		{
			printf( "\nпоздравляем вы победили\n");
			break;
		}
		
		step = true;
		while (step) 
		{
		    int xc = 1 + rand() % 11;
		    int yc = 1 + rand() % 11;
		    
			xc--; yc--;
		    
		    while(1)
		    {
		    	if (field2[yc][xc] == 'X' || field_m2[yc][xc] == 'X' || field2[yc][xc] == 'O' || field_m2[yc][xc] == 'O')
		    	{
		    	    printf("БЫЛО");
		    	    xc =1 + rand() % 11;
		    	    yc =1 + rand() % 11;

					xc--; yc--;
		    	}
		    	else
		    		break;
		    }
		    
			step=shot(field_m2,  field2, step, xc, yc);
            
			if (step) 
			{
				printf( "\nКомпьютер попал!\n");
                
                cmp_count--;
				
				bool f = !step;
				printMaps(field_m2);
			} 
			else
				printf( "\nКомпьютер не попал!\n");
		}
	} while (usr_count || cmp_count);
	
	int reset;
	printf( "Хотите повторить?\n");
	printf( "Да - 1\nНет - 0\n => ");
	scanf("%d", &reset);

	if (!reset) 
	{
	 	printf( "Вы вышли!");
		exit(0);
	} 
	else 
	{
		reset = !reset;//??

		maskMaps(field, field2, field_m1, field_m2);
		game(menu2);
	}
}
 
bool shot(char fiedl_m[][SIZE], char field[][SIZE], bool step, int x, int y) 
{
	if (field[y][x] == '#') 
	{
		field[y][x] = 'X';
		fiedl_m[y][x] = 'X';
	} else {
		field[y][x] = 'O';
		fiedl_m[y][x] = 'O';
		step = false;
	}
	return step;
}

void initialization(char field[][10])
{
	int quentsh[4]={1, 2, 3, 4};
	int ship_size[4]={4, 3, 2, 1};
	
	for (int i = 0; i < 4; i++)
		while (quentsh[i])
		{	
			if (rand() % 2)
				verticalShip(field, ship_size[i]);
			else
				horizontalShip(field, ship_size[i]);
			quentsh[i]--;
		}
}

void verticalShip(char arr[][SIZE], int ship_size)
{
	while (1)
	{
		if (ship_size == 4)
		{
			int x = rand() % 7;
 			int y = rand() % 10;
			
			for (int i = x; i < x + 4; i++)
				arr[i][y] = '#';
			break;
		}
		
		if (ship_size == 3)
		{
			int x = rand() % 8;
 			int y = rand() % 10;

			if ( arr[x][y] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || arr[x][y + 1] == '#' || arr[x + 1][y + 1] == '#' || 
			arr[x + 2][y + 1] == '#' || arr[x + 3][y + 1] == '#' || arr[x + 3][y] == '#' || arr[x + 3][y - 1] == '#' || arr[x + 2][y - 1] == '#' || 
			arr[x + 1][y - 1] == '#' || arr[x][y - 1] == '#' || arr[x - 1][y - 1] == '#' )
				continue;
			else
				for (int i = x; i < x + 3; i++)
					arr[i][y] = '#';
			break;
		}
		
		if (ship_size == 2)
		{
			int x = rand() % 9;
 			int y = rand() % 10;

			if ( arr[x][y] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || arr[x][y + 1] == '#' || arr[x + 1][y + 1] == '#' || 
			arr[x + 2][y + 1] == '#' || arr[x + 2][y] == '#' || arr[x + 2][y - 1] == '#' || arr[x + 1][y - 1] == '#' || arr[x][y - 1] == '#' || 
			arr[x - 1][y - 1] == '#' )
				continue;
			else
				for (int i = x; i < x + 2; i++)
					arr[i][y] = '#';
			break;
		}
		
		if (ship_size == 1)
		{
			int x = rand() % 10;
 			int y = rand() % 10;

			if (arr[x][y] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || arr[x][y + 1] == '#' || arr[x + 1][y + 1] == '#' || 
			arr[x + 1][y] == '#' || arr[x + 1][y - 1] == '#' || arr[x][y - 1] == '#' || arr[x - 1][y - 1] == '#')
				continue;
			else
				arr[x][y] = '#';
			break;
		}
	}
}

void horizontalShip(char arr[][SIZE], int ship_size)
{
	while (1)
	{
		if (ship_size == 4)
		{
			int x = rand() % 10;
 			int y = rand() % 7;

			for (int i = y; i < y + 4; i++)
				arr[x][i] = '#';
			break;
		}
		
		if (ship_size == 3)
		{
			int x = rand() % 10;
 			int y = rand() % 8;

			if (arr[x][y] == '#' || arr[x][y - 1] == '#' || arr[x - 1][y - 1] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || 
			arr[x - 1][y + 2] == '#' || arr[x - 1][y + 3] == '#' || arr[x][y + 3] == '#' || arr[x + 1][y + 3] == '#' || arr[x + 1][y + 2] == '#' || 
			arr[x + 1][y + 1] == '#' || arr[x + 1][y] == '#' || arr[x + 1][y + 1] == '#' )
				continue;
			else
				for (int i = y; i < y + 3; i++)
					arr[x][i] = '#';
			break;
		}

		if (ship_size == 2)
		{
			int x = rand() % 10;
 			int y = rand() % 9;

			if (arr[x][y] == '#' || arr[x][y - 1] == '#' || arr[x - 1][y - 1] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || 
			arr[x - 1][y + 2] == '#' || arr[x][y + 2] == '#' || arr[x + 1][y + 2] == '#' || arr[x + 1][y + 1] == '#' || arr[x + 1][y] == '#' || 
			arr[x + 1][y - 1] == '#' )
				continue;
			else
				for (int i = y; i < y + 2; i++)
					arr[x][i] = '#';
			break;
		}

		if (ship_size == 1)
		{
			int x = rand() % 10;
 			int y = rand() % 10;

			if (arr[x][y] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || arr[x][y + 1] == '#' || arr[x + 1][y + 1] == '#' || 
			arr[x + 1][y] == '#' || arr[x + 1][y - 1] == '#' || arr[x][y - 1] == '#' || arr[x - 1][y - 1] == '#')
				continue;
			else
				arr[x][y] = '#';
			break;
		}
	}
}

int battcc(char field[][SIZE],char field_m[][SIZE], int cmp, int count, u out)
{
    int x, y;
	
	bool step;

	step = true;
		while (step) 
		{
		    int x = 1 + rand() % 11;
		    int y = 1 + rand() % 11;
		   
		    x--;  y--;
		    
		    while(1)
		    {
		    	if (field[y][x] == 'X' || field_m[y][x] == 'X' || field[y][x] == 'O' || field_m[y][x] == 'O')
		    	{
		    	    printf("БЫЛО ");
		    	    x = 1 + rand() % 11;
		    	    y = 1 + rand() % 11;
		    	    
					x--; y--;
		    	}
		    	else
		    		break;
		    }
		    
			step=shot(field_m,  field,  step, x, y);
            
			if (step) 
			{
				printf("\nПОПАДАНИЕ КОМПЬЮТЕР %d\n", cmp);
                
                count--;
				bool f = !step;
				out(field_m);
			} 
			else
				printf("\nПРОМАХ КОМПЬЮТЕР %d\n", cmp);
		}
	return count;
}

void battlecc(int count) 
 {
	int menu2=3;
	
	if (!count)
			printf( "\nПОБЕДА КОМПЬЮТЕР 1\n");
	else
	    printf( "\nПОБЕДА КОМПЬЮТЕР 2\n");
		
	printf( "Хотите повторить?\n");
	printf( "Да - 1\nНет - 0\n => ");

	int var;
	scanf("%d", &var);

	if (!var) 
	{
	 	printf( "Вы вышли!");
		exit(0);
	} 
	else 
	{
		var = !var;

		game(menu2);
	}
}

void manualPlacement(char field[][SIZE])
{
	int n[4] = {1, 2, 3, 4};
	int k[4] = {4, 3, 2, 1};
	int orient;
	for (int i = 0; i < 4; i++)
		while (n[i])
		{	
			printf( "Выберите ориентацию:\n 0. Горизонтальная\n1. Вертикальная\n");
			scanf("%d", &orient);
			if (!orient)
				rVerticalShip(field, k[i]);
			else
				rHorizontalShip(field, k[i]);
			n[i]--;
			
			printMaps(field);
			
			getchar();
		}
}

void rVerticalShip(char arr[][SIZE], int ship_size)
{
	int x, y;
	while (1)
	{
		printf("Размер корабля: %d", ship_size);
		printf("\nВведите координаты:\n");
		if (ship_size == 4)
		{
			printf("x (x <= 6) = "); scanf("%d", &x);
 			printf("y = "); scanf("%d", &y);
			if (x < 1 || x > 6 || y < 1 || y > 10) 
			{
				printf("\nВы ввели неверную координату x > 6 или вышли за пределы поля, повторите ввод!\n");
				continue;
			}

			x--; y--;

			for (int i = x; i < x + 4; i++)
				arr[i][y] = '#';
			break;
		}
		
		if (ship_size == 3)
		{
			printf("x (x <= 7) = "); scanf("%d", &x);
 			printf("y = "); scanf("%d", &y);
			if (x < 1 || x > 7 || y < 1 || y > 10) 
			{
				printf("\nВы ввели неверную координату x > 7 или вышли за пределы поля, повторите ввод!\n");
				continue;
			}

			x--; y--;

			if ( arr[x][y] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || arr[x][y + 1] == '#' || arr[x + 1][y + 1] == '#' || 
			arr[x + 2][y + 1] == '#' || arr[x + 3][y + 1] == '#' || arr[x + 3][y] == '#' || arr[x + 3][y - 1] == '#' || arr[x + 2][y - 1] == '#' || 
			arr[x + 1][y - 1] == '#' || arr[x][y - 1] == '#' || arr[x - 1][y - 1] == '#' )
			{
				printf("\nКорабль перекрывает/расположен рядом с другим кораблем, повторите ввод\n");
				continue;
			}
			else
				for (int i = x; i < x + 3; i++)
					arr[i][y] = '#';
			break;
		}
		
		if (ship_size == 2)
		{
			printf("x (x <= 8) = "); scanf("%d", &x);
 			printf("y = "); scanf("%d", &y);
			if (x < 1 || x > 8 || y < 1 || y > 10) 
			{
				printf("\nВы ввели неверную координату x > 8 или вышли за пределы поля, повторите ввод!\n");
				continue;
			}
			
			x--; y--;

			if ( arr[x][y] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || arr[x][y + 1] == '#' || arr[x + 1][y + 1] == '#' || 
			arr[x + 2][y + 1] == '#' || arr[x + 2][y] == '#' || arr[x + 2][y - 1] == '#' || arr[x + 1][y - 1] == '#' || arr[x][y - 1] == '#' || 
			arr[x - 1][y - 1] == '#' )
			{
				printf("\nКорабль перекрывает/расположен рядом с другим кораблем, повторите ввод\n");
				continue;
			}
			else
				for (int i = x; i < x + 2; i++)
					arr[i][y] = '#';
			break;
		}
		
		if (ship_size == 1)
		{
			printf("x = "); scanf("%d", &x);
 			printf("y = "); scanf("%d", &y);
			if (x < 1 || x > 10 || y < 1 || y > 10) 
			{
				printf("\nВы вышли за пределы поля, повторите ввод!\n");
				continue;
			}
			
			x--; y--;

			if (arr[x][y] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || arr[x][y + 1] == '#' || arr[x + 1][y + 1] == '#' || 
			arr[x + 1][y] == '#' || arr[x + 1][y - 1] == '#' || arr[x][y - 1] == '#' || arr[x - 1][y - 1] == '#')
			{
				printf("\nКорабль перекрывает/расположен рядом с другим кораблем, повторите ввод\n");
				continue;
			}
			else
				arr[x][y] = '#';
			break;
		}
	}
}

void rHorizontalShip(char arr[][SIZE], int ship_size)
{
	int x, y;
	while (1)
	{
		printf("Размер корабля: %d", ship_size);
		printf("\nВведите координаты:\n");
		if (ship_size == 4)
		{
			printf("x = "); scanf("%d", &x);
			printf("y (y <= 6) = "); scanf("%d", &y);
			
			if (x < 1 || x > 10 || y < 1 || y > 6) 
			{
				printf("\nВы ввели неверную координату y > 6 или вышли за пределы поля, повторите ввод!\n");
				continue;
			}

			x--; y--;

			for (int i = y; i < y + 4; i++)
				arr[x][i] = '#';
			break;
		}
		
		if (ship_size == 3)
		{
			printf("x = "); scanf("%d", &x);
			printf("y (y <= 7) = "); scanf("%d", &y);
			
			if (x < 1 || x > 10 || y < 1 || y > 7) 
			{
				printf("\nВы ввели неверную координату y > 7 или вышли за пределы поля, повторите ввод!\n");
				continue;
			}

			x--; y--;

			if (arr[x][y] == '#' || arr[x][y - 1] == '#' || arr[x - 1][y - 1] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || 
			arr[x - 1][y + 2] == '#' || arr[x - 1][y + 3] == '#' || arr[x][y + 3] == '#' || arr[x + 1][y + 3] == '#' || arr[x + 1][y + 2] == '#' || 
			arr[x + 1][y + 1] == '#' || arr[x + 1][y] == '#' || arr[x + 1][y + 1] == '#' )
			{
				printf("\nКорабль перекрывает/расположен рядом с другим кораблем, повторите ввод\n");
				continue;
			}
			else
				for (int i = y; i < y + 3; i++)
					arr[x][i] = '#';
			break;
		}

		if (ship_size == 2)
		{
			printf("x = "); scanf("%d", &x);
			printf("y (y <= 8) = "); scanf("%d", &y);
			
			if (x < 1 || x > 10 || y < 1 || y > 8) 
			{
				printf("\nВы ввели неверную координату y > 8 или вышли за пределы поля, повторите ввод!\n");
				continue;
			}

			x--; y--;

			if (arr[x][y] == '#' || arr[x][y - 1] == '#' || arr[x - 1][y - 1] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || 
			arr[x - 1][y + 2] == '#' || arr[x][y + 2] == '#' || arr[x + 1][y + 2] == '#' || arr[x + 1][y + 1] == '#' || arr[x + 1][y] == '#' || 
			arr[x + 1][y - 1] == '#' )
			{
				printf("\nКорабль перекрывает/расположен рядом с другим кораблем, повторите ввод\n");
				continue;
			}
			else
				for (int i = y; i < y + 2; i++)
					arr[x][i] = '#';
			break;
		}

		if (ship_size == 1)
		{
			printf("x = "); scanf("%d", &x);
			printf("y = "); scanf("%d", &y);
			
			if (x < 1 || x > 10 || y < 1 || y > 10) 
			{
				printf("\nВы вышли за пределы поля, повторите ввод!\n");
				continue;
			}

			x--; y--;

			if (arr[x][y] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || arr[x][y + 1] == '#' || arr[x + 1][y + 1] == '#' || 
			arr[x + 1][y] == '#' || arr[x + 1][y - 1] == '#' || arr[x][y - 1] == '#' || arr[x - 1][y - 1] == '#')
			{
				printf("\nКорабль перекрывает/расположен рядом с другим кораблем, повторите ввод\n");
				continue;
			}
			else
				arr[x][y] = '#';
			break;
		}
	}
}

void battleUu(char field2[][SIZE], char field_m2[][SIZE], char field[][SIZE] ,char field_m[][SIZE])
{
	int x, y;
	int menu2;
	
	bool step;
	int usr_count_1 = 20;
	int usr_count_2 = 20;
	do {
		
		step = true;
		while (step && usr_count_1) 
		{
			printf( "\nИгрок 1 ходит:\n Определите цель: х=");
			scanf("%d", &x);
			printf( "y= ");
			scanf("%d", &y);		 	
            
			    if(x<1 || x>10 || y<1 || y>10)
			    {
			    	printf( "\nВЫХОД ЗА ПРЕДЕЛЫ\n");
			    	continue;
			    }
			    
		     
		        if (field[y-1][x-1] == 'X' || field_m[y-1][x-1] == 'X' || field[y-1][x-1] == 'O' || field_m[y-1][x-1] == 'O')
		        {
			    	printf( "\nБЫЛО\n");
			    	continue;
			    }

		        x--;
		        y--;

			while (step) 
			{
				step = shot(field_m,  field, step,  x, y);
				
				if (step) 
				{
					printf("\nИгрок 1 попал!\n");
					
					usr_count_1--;
					printf("\n");
					printf("\n");
                    printMaps(field_m);

					if ( (field[x][y] == '#' || field[x - 1][y] == '#' || field[x - 1][y + 1] == '#' || field[x][y + 1] == '#' || field[x + 1][y + 1] == '#' || field[x + 1][y] 	== '#' || field[x + 1][y - 1] == '#' || field[x][y - 1] == '#' || field[x - 1][y - 1] == '#') || (x<1 || x>10 || y<1 || y>10) )
						break;

					else 
						printf("\nУБИТ\n");
					break;
				}
				
				else{
					printf("\nИгрок 1 не попал \n");
					break;
				}
			}
		}
		
		if (!usr_count_1) 
		{
			printf( "\nИгрок 1 победил!\n");
			break;
		}
		
		step = true;
		while (step && usr_count_2) 
		{
			printf( "\nИгрок 2 ходит:\n Определите цель: х=");
			scanf("%d", &x);
			printf( "y= ");
			scanf("%d", &y);		 	
            
			    if(x<1 || x>10 || y<1 || y>10)
			    {
			    printf( "\nВЫХОД ЗА ПРЕДЕЛЫ\n");
			    continue;
			    }
			    
		     
		        if (field2[y-1][x-1] == 'X' || field_m2[y-1][x-1] == 'X' || field2[y-1][x-1] == 'O' || field_m2[y-1][x-1] == 'O')
		        {
			    printf( "\nБЫЛО\n");
			    continue;
			    }

		        x--;
		        y--;

			while (step) 
			{
				step = shot(field_m2,  field2, step,  x, y);
				
				if (step) 
				{
					printf("\nИгрок 2 попал!\n");
					
					usr_count_2--;
					printf("\n");
					printf("\n");
					printMaps(field_m2);

					if ( (field2[x][y] == '#' || field2[x - 1][y] == '#' || field2[x - 1][y + 1] == '#' || field2[x][y + 1] == '#' || field2[x + 1][y + 1] == '#' || field2[x + 1][y] 	== '#' || field2[x + 1][y - 1] == '#' || field2[x][y - 1] == '#' || field2[x - 1][y - 1] == '#') || (x<1 || x>10 || y<1 || y>10) )
						break;

					else 
						printf("\nУБИТ\n");
					break;
				}
				
				else{
					printf("\nИгрок 2 не попал \n");
					break;
				}
			}
		}
	} while (usr_count_1 || usr_count_2);
	
	printf( "Хотите повторить?\n");
	printf( "Да - 1\nНет - 0\n => ");

	int var;
	scanf("%d", &var);

	if (!var) 
	{
	 	printf( "Вы вышли!");
		exit(0);
	} 
	else 
	{
		var = !var;

		maskMaps(field, field2, field_m, field_m2);
		game(menu2);
	}
}