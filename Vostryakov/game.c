#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Result(int, int, int, int, int);
int Result(int number,int bet,int Bank, int d,int current_p)
{
                if(number == 0)
                {
                    return 0;
                }
                if(number == d)
                {
                    Bank+=4*bet;
                    printf("игрок №%d угадал число\n",current_p+1);
                }
                else if(number<7 && d<7)
                {
                    Bank+=2*bet;
                    printf("игрок №%d близко твоё число %d\n",current_p+1,number);
                }
                else if(number>7 && d>7)
                {
                    Bank+=2*bet;
                    printf(" игрок №%d близко твоё число %d\n",current_p+1,number);
                }
                else 
                {
                    printf("игрок №%d не угадал и не был близок\n",current_p+1);
                }
                return Bank;
}
int Menu(int);
int Menu(int i)
{
	printf("Опции игры:\n 1-начать игру\n 2-закончить игру\n");
        do
        {
        scanf("%d",&i);
        if(i>2 || i<1)
			{
				printf("неверное значение введите снова\n");
			}
        }
		while(i>2 || i<1);
			return i;
}
int bets(int, int, int);
int bets(int bet, int Bank, int current_p)
{
    do
                    {
                        printf("сделайте ставку, игрок %d, или пойти ва банк (для этого нажмите 0)\n",current_p+1);
                        scanf("%d",&bet);
                        if(bet == 0)
                        {
                            bet=Bank;
                        }
                        if(bet>Bank)
                        {
                            printf("вы не можете сделать такую ставку\n");
                        }
                    }
                    while(bet>Bank);
                    return bet;
}

main()
{
    srand(time(NULL));
    int number[3],dice=0,Bank[3]={100,100,100,100},bet[3]={0,0,0,0},i=0,player,countP;
    do
    {
        i = Menu(i);
        switch(i)
        {
            case 1:
            do
            {
            printf("выберите число игроков 1-4\n");
            scanf("%d",&player);
            countP=player;
            if(player>4 || player<1)
				{
					printf("количество игроков не совпадает с условием\n");
				}
            }
            while(player>4 || player<1);
            for(int round = 0; round < 10; round++)
            {
                if(player>1)
                {
                    if(countP==1)
                    {
                        printf("Игра окончена\n");
                        break;
                    }
                }
                printf("раунд %d\n",round+1);
                dice=(1+rand() % 6)+(1+rand() % 6);
                for(int current_p=0;current_p<player;current_p++)
                {
                    if(Bank[current_p]<=0)
                    {
                        printf("игрок №%d больше не может сделать ставку\n",current_p+1);
                        number[current_p]=0;
                        continue;
                    }
                    bet[current_p]=bets(bet[current_p],Bank[current_p],current_p);
                    Bank[current_p]-=bet[current_p];
                    printf("назовите любое число от 2 до 12\n");
                    scanf("%d",&number[current_p]);
                }
                printf("число %d\n",dice);
                for(int current_p=0;current_p<player;current_p++)
                {
                    Bank[current_p]=Result(number[current_p],bet[current_p],Bank[current_p],dice,current_p);
                    printf("деньги игрока №%d = %d\n",current_p+1,Bank[current_p]);
                    if(Bank[current_p] <= 0)
                    {
                        countP--;
                    }
                }
                printf("____________________\n");
            }
            break;
            case 2:
            break;
        }
    }       
    while(i!=2);
    return 0;
}
