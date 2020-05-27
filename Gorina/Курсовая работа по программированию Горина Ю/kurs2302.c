// заголовочные файлы стандартной библиотеки языка С
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define SIZE 10 // директива препроцессора, определяет размерность при ее вызове

typedef void (*u)(char f[][SIZE]); // указатель на функцию output output2 (fm)
typedef void (*uu)(char fm[][SIZE]); // указатель на функцию output output2 (f)
typedef bool (*sh)(char [][SIZE], char [][SIZE], int , bool , int ,int ); // указатель на функцию shotc shotu

void output(char [][SIZE]); // функция реализация после заполнения
void output2(char [][SIZE]);
void mapsdis(char [][SIZE], char [][SIZE], char [][SIZE], char [][SIZE]);  // функция отображения карты и маски на нее
void ship(char [][SIZE],int , int ); // функция выбора ориентации построения кораблей
int game(int ); // функция обеспечивающая выбор и порядок игрового процесса 
void battleuc(char [][SIZE], char [][SIZE], char [][SIZE], char [][SIZE]) ; // функция алгоритма игры человек и компьютера
int battuu(char [][SIZE], char [][SIZE], char [][SIZE], int, u , uu, sh, int) ; // функция алгоритма игры двух человек
bool shotu(char [][SIZE], char [][SIZE], int , bool , int ,int ); // функция воспроизведения выстрела
bool shotc(char [][SIZE], char [][SIZE], int , bool , int ,int );
void initial(char [][10]); // функция выбора и реализации автоматической растановки кораблей
void vertarr(char [][SIZE], int); // функция автоматической расстановки кораблей
void horizarr(char [][SIZE], int);
int battcc(char [][SIZE], char [][SIZE], int, u , sh, int); // функция алгоритма игры двух компьютеров
void battleuu(int ); // по окончании игры, функция предлагает повторить или же выйти
void battlecc(int );
void hardarr(char [][SIZE]); // функция выбора и реализации ручной растановки кораблей
void vhardarr(char [][SIZE], int); // функция ручной расстановки кораблей
void hhardarr(char [][SIZE], int);

int main(int argc, char const *argv[]) // глобальная функция, начало программы которой положено со входа в меню
{
	int menu,menu2; // переменнные целого типа, определяющие через оператор дальнейшие действия
    
    srand( time(NULL) ); // генератор случайных чисел
    
    printf( " Добро пожаловать в игру 'Морской бой'\n Выберите вариант:\n" // вывод на экран приветственного меню
			" 1. Начать игру\n 2. Выход\n");
    while(1)
    {
    scanf("%d",&menu);
    system("clear");
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
}

void output(char fm1[][SIZE])  
{
	printf("%3c", ' '); // исключает первый символ строки для сохранения равности поля 10х10
	for(int i = 1; i <= 10; i++) 
		printf("%3d", i); // выводит на экран строку переменных от 1 до 10
	printf("\n");
	for(int j = 0; j < 10; j++) // вывод поля
	{
		printf("%3d", j+1);
		for (int i = 0; i < 10; i++)
			printf("%3c", fm1[i][j]);
		printf("\n");
	}
}

void output2(char fm2[][SIZE])
{
	printf("%3c", ' ');
	for(int i = 1; i <= 10; i++)
		printf("%3d", i);
	printf("\n");
	for(int j = 0; j < 10; j++)
	{
		printf("%3d", j+1);
		for (int i = 0; i < 10; i++)
			printf("%3c", fm2[i][j]);
		printf("\n");
	}
}

void mapsdis(char f1[][SIZE], char f2[][SIZE], char fm1[][SIZE], char fm2[][SIZE]) // функция отображения карты и маски на нее
{
    for (int j = 0; j < 10; j++)
	 	for (int i = 0; i < 10; i++)
	 	{
	 		f1[i][j] = ' ';
	 		f2[i][j] = ' ';
        }
	for (int j = 0; j < 10; j++)
		for (int i = 0; i < 10; i++)
		{
			fm1[i][j] = ' ';
			fm2[i][j] = ' ';
		}
}
 
void ship(char f2[][SIZE],int sizesh, int orient) 
{
    if (!orient)
		vhardarr(f2, sizesh);
	else
		hhardarr(f2, sizesh);
}

int game(int menu2)	
{
    // объявление массивов
	char f1[SIZE][SIZE];
	char f2[SIZE][SIZE];
	char fm1[SIZE][SIZE];
	char fm2[SIZE][SIZE];
	int menu3;
	
	system("clear"); // производит очистку меню с экрана	
    mapsdis(f1,f2,fm1,fm2); 

    // условие выполняется в соответствии с выбором перемнной
	if (menu2 == 1)  // реализуется игра двух человек
	{
        do {
            system("clear");
            printf( " Меню игры:\n 1. Автоматическая расстановка\n 2. Ручная расстановка\n 3. Выход\n");
		    scanf("%d",&menu3);
		
            system("clear");
            if (menu3==1)
            {
		        initial(f2);
		        printf(" ПОЛЕ 1ГО ИГРОКА: \n");
	            output2(f2);
	            getchar();
	            getchar();
	            system("clear");
	            
		        initial(f1);
		        printf(" ПОЛЕ 2ГО ИГРОКА: \n");
	            output(f1);
	            getchar();
	            system("clear");
		        
		        output2(f2);
		        
	        	int count1=20;
	        	int count2=20;
	        	
		        do {
		            count1=battuu(f1,fm1,f2,count1,output2,output,shotu,1);
		            count2=battuu(f2,fm2,f1,count2,output,output2,shotc,2);
	        	} while (count1!=0 || count2!=0);
	            	battleuu(count2);
	            	
	        }
            if (menu3 == 2)
	        {
	            output2(f2);
	        	hardarr(f2);
	        	system("clear");
	        	printf(" ПОЛЕ 1ГО ИГРОКА: \n");
	            output2(f2);
	            getchar();
	            system("clear");
	            
	        	output(f1);
	        	hardarr(f1);
	        	system("clear");
	        	printf(" ПОЛЕ 2ГО ИГРОКА: \n");
	            output(f1);
	            getchar();
	            system("clear");
	            
		        output2(f2);
		        
	        	int count1=20;
	        	int count2=20;
	        	
	            do {
	                count1=battuu(f1,fm1,f2,count1,output2,output,shotu,1);
		            count2=battuu(f2,fm2,f1,count2,output,output2,shotc,2);
	        	} while (count1!=0 || count2!=0);
	            	battleuu(count2);
		
	        }
	        if (menu3 == 3)
	        {
	            printf(" BB");
			    return 0;
	        }
            } while(!menu3);
	}
    if (menu2 == 2) // реализуется игра человека с компьютером
	{
        printf( " Меню игры:\n 1. Автоматическая расстановка\n 2. Ручная расстановка\n 3. Выход\n");
		scanf("%d",&menu3);
		do {
            system("clear");
            if (menu3==1)
            {
		        initial(f2);
		        initial(f1);
	        }
            if (menu3 == 2)
	        {
	            output2(f2);
	        	hardarr(f2);
	        }
	        else
	            printf(" ERROR\n");
			    continue;
            } while(!menu3);
        
        system("clear");
        battleuc(f2,fm2, f1, fm1);
	}
	else // реализуется игра двух компьютеров
	{
	    initial(f2);
		initial(f1);
		
		int count1=20;
		int count2=20;
		
		do {
		    count1=battcc(f1,fm1,count1,output2,shotu,1);
		    count2=battcc(f2,fm2,count2,output,shotc,2);
		} while (count1!=0 || count2!=0);
		battlecc(count2);
	}
}

void battleuc(char f2[][SIZE],char fm2[][SIZE], char f1[][SIZE] ,char fm1[][SIZE]) 
{
	int x,y,menu2=2;
	
	bool step;
	int usr_count = 20;
	int cmp_count = 20;

	do {
		
		step = true;
		while (step && usr_count) 
		{
		    system("clear");
		    printf(" ВАШЕ ПОЛЕ: \n");
		    output2(f2);
			output(fm1);
			printf( "\n ВАШ ХОД\n Х ");
			scanf("%d", &x);
			printf( " У ");
			scanf("%d", &y);
            
			if(x<1 || x>10 || y<1 || y>10)
			{
			    printf( " ВЫХОД ЗА ПРЕДЕЛЫ\n");
			    system("sleep 1");
			    continue;
			}
			    
		    if (f1[x-1][y-1] == 'X' || fm1[x-1][y-1] == 'X' || f1[x-1][y-1] == 'O' || fm1[x-1][y-1] == 'O')
		    {
			    printf( " БЫЛО\n");
			    system("sleep 1");
			    continue;
			}

		    x--;
		    y--;
		    
			while (step) 
			{
				step=shotu(fm1, f1, usr_count, step, x, y);
				
				if (step) 
				{
					printf(" ПОПАДАНИЕ\n");
					system("sleep 1");
					usr_count--;
					printf(" ВАШЕ ПОЛЕ: \n");
					output2(f2);
					output(fm1);
					
					// проверка на потопление корабля
					if ( (f1[x][y] == '#' || f1[x - 1][y] == '#' || f1[x - 1][y + 1] == '#' || f1[x][y + 1] == '#' || f1[x + 1][y + 1] == '#' || 
					f1[x + 1][y] 	== '#' || f1[x + 1][y - 1] == '#' || f1[x][y - 1] == '#' || f1[x - 1][y - 1] == '#') || (x<1 || x>10 || y<1 || y>10) )
						break;

					else {
						printf(" УБИТ\n");
						system("sleep 1");
						printf(" ВАШЕ ПОЛЕ: \n");
					    output2(f2);
					    output(fm1);
				    	break;
					} // конец проверки
				}
				else{
					printf(" ПРОМАХ\n");
					system("sleep 1");
					system("clear");
					break;
				}
			}
		}
		
		if (!usr_count) // условие победы, при обнулении наличия кораблей
		{
			printf( "\n ВЫ ПОБЕДИЛИ\n");
			break;
		}
		
		step = true;
		while (step) 
		{
		    system("clear");
			printf(" ВАШЕ ПОЛЕ: \n");
			output2(f2);
				
		    int xc =1 + rand()%10;
		    int yc =1 + rand()%10;
		    xc--;
		    yc--;
		    
		    while(1)
		    {
		        if (f2[xc][yc] == 'X' || fm2[xc][yc] == 'X' || f2[xc][yc] == 'O' || fm2[xc][yc] == 'O')
		        {
		            printf(" БЫЛО");
		            system("sleep 1");
		            xc =1 + rand()%10;
		            yc =1 + rand()%10;
		            xc--;
		            yc--;
		        }
		        else
		        break;
    		}
		    
		    step=shotc(fm2, f2, cmp_count, step, xc, yc);
            
		    if(step) 
		    {
			    printf( "\n БОТ ПОПАЛ\n");
			    system("sleep 2");
                cmp_count--;
                system("clear");
		        printf(" ВАШЕ ПОЛЕ: \n");
			    output2(f2);
		    } 
		    else 
		    {
		    	printf( "\n БОТ НЕ ПОПАЛ\n");
			    system("sleep 2");
			    system("clear");
			    break;
		    }
	    }
	} while (usr_count || cmp_count);
	
	printf( " ПОВТОРИТЬ?\n");
	printf( " 1. ДА\n 0. НЕТ\n");

	int var;
	scanf("%d", &var);
	if (!var) 
	{
	 	printf( " ВВ");
		exit(0);
	} 
	else 
	{
		var = !var;
		mapsdis(f1, f2,fm1, fm2);
		game(menu2);
	}
}

int battuu(char f[][SIZE],char fm[][SIZE], char m[][SIZE], int count, u out, uu outt, sh shot, int numb)
{
    int x,y;
	bool step;

    step = true;
	while (step) 
	{
		system("clear");
		printf(" ПОЛЕ %dГО ИГРОКА: \n", numb);
		out(m);
		outt(fm);
			    	
		printf( "\n ВАШ ХОД\n х=");
		scanf("%d", &x);
		printf( " y=");
		scanf("%d", &y);
			
		if(x<1 || x>10 || y<1 || y>10)
		{
		    printf( " ВЫХОД ЗА ПРЕДЕЛЫ\n");
			continue;
		}
			    
		if (f[x-1][y-1] == 'X' || fm[x-1][y-1] == 'X' || f[x-1][y-1] == 'O' || fm[x-1][y-1] == 'O')
		{
		    printf( " БЫЛО\n");
			continue;
		}

		x--;
		y--;
		    
		while (step) 
		{
			step=shot(fm,  f,  count, step,  x, y);
            
			if (step) 
			{
			    printf(" ПОПАДАНИЕ\n");
				count--;
			    system("clear");
			    printf(" ПОЛЕ %dГО ИГРОКА: \n", numb);
			    out(m);
		        outt(fm);

				if ( (f[x][y] == '#' || f[x - 1][y] == '#' || f[x - 1][y + 1] == '#' || f[x][y + 1] == '#' || f[x + 1][y + 1] == '#' || 
				    f[x + 1][y] 	== '#' || f[x + 1][y - 1] == '#' || f[x][y - 1] == '#' || f[x - 1][y - 1] == '#') || (x<1 || x>10 || y<1 || y>10) )
					break;

				else 
				{
					printf(" УБИТ\n");
					break;
				}
		    }
		    else
		    {
				printf(" ПРОМАХ\n");
				system("sleep 1");
				system("clear");
				break;
			}
		}
	}
	system("sleep 0.5");
	return count;
}

bool shotu(char fm1[][SIZE], char f1[][SIZE], int usr_count, bool usr_step, int xx,int yy) 
{
	if (f1[xx][yy] == '#')
	{
		f1[xx][yy] = 'X';
		fm1[xx][yy] = 'X';
	}
	else
	{
		f1[xx][yy] = 'O';
		fm1[xx][yy] = 'O';
		usr_step = false;
	}
	return usr_step;
}

bool shotc(char fm2[][SIZE], char f2[][SIZE], int cmp_count, bool usr_step, int xx,int yy) 
{
 	if (f2[xx][yy] == '#') 
	{
	 	
		f2[xx][yy] = 'X';
		fm2[xx][yy] = 'X';
	}
	else 
	{
	 	f2[xx][yy] = 'O';
		fm2[xx][yy] = 'O';
		usr_step = false;
	}
 	return usr_step;
}

void initial(char field[][10])
{
	int quentsh[4]={1, 2, 3, 4};
	int sizesh[4]={4, 3, 2, 1};
	
	for (int i = 0; i < 4; i++)
		while (quentsh[i])
		{	
			if (rand() % 2)
				vertarr(field, sizesh[i]);
			else
				horizarr(field, sizesh[i]);
			quentsh[i]--;
		}
}

void vertarr(char arr[][SIZE], int sizesh)
{
	while (1)
	{
		if (sizesh == 4)
		{
			int x = rand() % 7;
 			int y = rand() % 10;
			
			for (int i = x; i < x + 4; i++)
				arr[i][y] = '#';
			break;
		}
		
		if (sizesh == 3)
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
		
		if (sizesh == 2)
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
		
		if (sizesh == 1)
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

void horizarr(char arr[][SIZE], int sizesh)
{
	while (1)
	{
		if (sizesh == 4)
		{
			int x = rand() % 10;
 			int y = rand() % 7;

			for (int i = y; i < y + 4; i++)
				arr[x][i] = '#';
			break;
		}
		
		if (sizesh == 3)
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

		if (sizesh == 2)
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

		if (sizesh == 1)
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

int battcc(char f[][SIZE],char fm[][SIZE], int count, u out, sh shot, int numb)
{
    int x,y;
	bool step;

    step = true;
	while (step) 
	{
				
		    int x =1 +rand()%10;
		    int y =1 +rand()%10;
		    x--;
		    y--;
		    
		    while(1)
		    {
		        if (f[x][y] == 'X' || fm[x][y] == 'X' || f[x][y] == 'O' || fm[x][y] == 'O')
		        {
		            printf(" БЫЛО\n");
		            x =1 +rand()%10;
    		        y =1 +rand()%10;
		            x--;
		            y--;
		        }
		        else
		            break;
		    }
		    
			step=shot(fm, f, count, step, x, y);
            
			if (step) 
			{
			    printf(" Х %d У %d\n", ++x,++y);
				printf(" ПОПАДАНИЕ\n");
				system("sleep 1");
                count--;
				system("clear");
				printf(" ПОЛЕ %dГО ИГРОКА: \n", numb);
				out(fm);
			} 
			else 
			{
				printf(" ПРОМАХ\n");
				break;
			}
		        
	}
	system("sleep 0.5");
	return count;
}

void battlecc(int count) 
 {
	int menu2=3;
	
	if (!count)
		printf( "\n ПОБЕДА ИГРОК 1\n");
	else
	    printf( "\n ПОБЕДА ИГРОК 2\n");
		
	printf( " ПОВТОРИТЬ?\n");
	printf( " 1. ДА\n 0. НЕТ\n");

	int var;
	scanf("%d", &var);

	if (!var) 
	{
	 	printf( " ВВ");
		exit(0);
	} 
	else 
	{
		var=!var;
		game(menu2);
	}
}

void battleuu(int count) 
 {
	int menu2=1;
	
	if (!count)
		printf( "\n ПОБЕДА ИГРОК 1\n");
	else
	    printf( "\n ПОБЕДА ИГРОК 2\n");
		
	printf( " ПОВТОРИТЬ?\n");
	printf( " 1. ДА\n 0. НЕТ\n");

	int var;
	scanf(" %d", &var);

	if (!var) 
	{
	 	printf( " ВВ");
		exit(0);
	} 
	else 
	{
		var=!var;
		game(menu2);
	}
}

void hardarr(char f2[][SIZE])
{
	int k=1,x,y,size,orient;
	
	for(int i = 1; i < 5; i++) 
	{
		size=5-i;
		for(int j = 1; j <= i; j++) 
		{
			printf( " Выберите ориентацию:\n"
					" 0. Горизонтальная\n 1. Вертикальная\n");
			scanf(" %d", &orient);

			ship(f2, size, orient);
            system("clear");
			output2(f2);
			getchar();
		}
	}
}

void vhardarr(char arr[][SIZE], int sizesh)
{
	int x,y;
	
	while (1)
	{
		printf(" КОЛ-ВО ПАЛУБ: %d", sizesh);
		printf("\n Введите координаты: \n");
		if (sizesh == 4)
		{
			printf(" УСЛОВИЕ (x <= 6)\n Х "); 
			scanf("%d", &x);
 			printf(" У "); scanf("%d", &y);
			if (x < 1 || x > 6 || y < 1 || y > 10) 
			{
				printf("\n Вы ввели неверную координату x > 6 или вышли за пределы поля. Повторите ввод\n");
				continue;
			}

			x--; y--;

			for (int i = x; i < x + 4; i++)
				arr[i][y] = '#';
			break;
		}
		
		if (sizesh == 3)
		{
			printf(" УСЛОВИЕ (x <= 7) Х "); 
			scanf("%d", &x);
 			printf(" У "); scanf("%d", &y);
			if (x < 1 || x > 7 || y < 1 || y > 10) 
			{
				printf("\n Вы ввели неверную координату x > 7 или вышли за пределы поля. Повторите ввод\n");
				continue;
			}

			x--; y--;

			if ( arr[x][y] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || arr[x][y + 1] == '#' || arr[x + 1][y + 1] == '#' || 
			arr[x + 2][y + 1] == '#' || arr[x + 3][y + 1] == '#' || arr[x + 3][y] == '#' || arr[x + 3][y - 1] == '#' || arr[x + 2][y - 1] == '#' || 
			arr[x + 1][y - 1] == '#' || arr[x][y - 1] == '#' || arr[x - 1][y - 1] == '#' )
			{
				printf("\n Корабль перекрывает/расположен рядом с другим кораблем. Повторите ввод\n");
				continue;
			}
			else
				for (int i = x; i < x + 3; i++)
					arr[i][y] = '#';
			break;
		}
		
		if (sizesh == 2)
		{
			printf(" УСЛОВИЕ (x <= 8) Х "); 
			scanf("%d", &x);
 			printf(" У "); scanf("%d", &y);
			if (x < 1 || x > 8 || y < 1 || y > 10) 
			{
				printf("\n Вы ввели неверную координату x > 8 или вышли за пределы поля. Повторите ввод\n");
				continue;
			}
			
			x--; y--;

			if ( arr[x][y] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || arr[x][y + 1] == '#' || arr[x + 1][y + 1] == '#' || 
			arr[x + 2][y + 1] == '#' || arr[x + 2][y] == '#' || arr[x + 2][y - 1] == '#' || arr[x + 1][y - 1] == '#' || arr[x][y - 1] == '#' || 
			arr[x - 1][y - 1] == '#' )
			{
				printf("\n Корабль перекрывает/расположен рядом с другим кораблем. Повторите ввод\n");
				continue;
			}
			else
				for (int i = x; i < x + 2; i++)
					arr[i][y] = '#';
			break;
		}
		
		if (sizesh == 1)
		{
			printf(" Х "); scanf("%d", &x);
 			printf(" У "); scanf("%d", &y);
			if (x < 1 || x > 10 || y < 1 || y > 10) 
			{
				printf("\n Вы вышли за пределы поля. Повторите ввод\n");
				continue;
			}
			
			x--; y--;

			if (arr[x][y] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || arr[x][y + 1] == '#' || arr[x + 1][y + 1] == '#' || 
			arr[x + 1][y] == '#' || arr[x + 1][y - 1] == '#' || arr[x][y - 1] == '#' || arr[x - 1][y - 1] == '#')
			{
				printf("\n Корабль перекрывает/расположен рядом с другим кораблем. Повторите ввод\n");
				continue;
			}
			else
				arr[x][y] = '#';
			break;
		}
	}
}

void hhardarr(char arr[][SIZE], int sizesh)
{
	int x,y;
	
	while (1)
	{
		printf(" КОЛ-ВО ПАЛУБ: %d", sizesh);
		printf("\n Введите координаты:\n");
		if (sizesh == 4)
		{
			printf(" Х "); scanf("%d", &x);
			printf(" УСЛОВИЕ (y <= 6) У "); 
			scanf("%d", &y);
			
			if (x < 1 || x > 10 || y < 1 || y > 6) 
			{
				printf("\n Вы ввели неверную координату y > 6 или вышли за пределы поля. Повторите ввод\n");
				continue;
			}

			x--; y--;

			for (int i = y; i < y + 4; i++)
				arr[x][i] = '#';
			break;
		}
		
		if (sizesh == 3)
		{
			printf(" Х "); scanf("%d", &x);
			printf(" УСЛОВИЕ (y <= 7) У "); 
			scanf("%d", &y);
			
			if (x < 1 || x > 10 || y < 1 || y > 7) 
			{
				printf("\n Вы ввели неверную координату y > 7 или вышли за пределы поля. Повторите ввод\n");
				continue;
			}

			x--; y--;

			if (arr[x][y] == '#' || arr[x][y - 1] == '#' || arr[x - 1][y - 1] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || 
			arr[x - 1][y + 2] == '#' || arr[x - 1][y + 3] == '#' || arr[x][y + 3] == '#' || arr[x + 1][y + 3] == '#' || arr[x + 1][y + 2] == '#' || 
			arr[x + 1][y + 1] == '#' || arr[x + 1][y] == '#' || arr[x + 1][y + 1] == '#' )
			{
				printf("\n Корабль перекрывает/расположен рядом с другим кораблем. Повторите ввод\n");
				continue;
			}
			else
				for (int i = y; i < y + 3; i++)
					arr[x][i] = '#';
			break;
		}

		if (sizesh == 2)
		{
			printf(" Х "); scanf("%d", &x);
			printf(" УСЛОВИЕ (y <= 8) У "); 
			scanf("%d", &y);
			
			if (x < 1 || x > 10 || y < 1 || y > 8) 
			{
				printf("\n Вы ввели неверную координату y > 8 или вышли за пределы поля. Повторите ввод\n");
				continue;
			}

			x--; y--;

			if (arr[x][y] == '#' || arr[x][y - 1] == '#' || arr[x - 1][y - 1] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || 
			arr[x - 1][y + 2] == '#' || arr[x][y + 2] == '#' || arr[x + 1][y + 2] == '#' || arr[x + 1][y + 1] == '#' || arr[x + 1][y] == '#' || 
			arr[x + 1][y - 1] == '#' )
			{
				printf("\n Корабль перекрывает/расположен рядом с другим кораблем. Повторите ввод\n");
				continue;
			}
			else
				for (int i = y; i < y + 2; i++)
					arr[x][i] = '#';
			break;
		}

		if (sizesh == 1)
		{
			printf(" Х "); scanf("%d", &x);
			printf(" У "); scanf("%d", &y);
			
			if (x < 1 || x > 10 || y < 1 || y > 10) 
			{
				printf("\n Вы вышли за пределы поля. Повторите ввод\n");
				continue;
			}

			x--; y--;

			if (arr[x][y] == '#' || arr[x - 1][y] == '#' || arr[x - 1][y + 1] == '#' || arr[x][y + 1] == '#' || arr[x + 1][y + 1] == '#' || 
			arr[x + 1][y] == '#' || arr[x + 1][y - 1] == '#' || arr[x][y - 1] == '#' || arr[x - 1][y - 1] == '#')
			{
				printf("\n Корабль перекрывает/расположен рядом с другим кораблем. Повторите ввод\n");
				continue;
			}
			else
				arr[x][y] = '#';
			break;
		}
	}
}