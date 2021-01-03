#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//小球速度 
int velocity_x = 1 ,velocity_y = 1;
//小球初始位置
int x=3,y=1;
//显示棋盘与棋子 
int left = 0,right = 20,top = 0,bottom =10;
void show_board(void)
{
	for(int i=top;i<=bottom+1;i++)
	{
		for(int j=left;j<=right+1;j++)
		{
			if(x==i&&y==j)
				printf("o");
			else
			{
				if(i==0 || i==bottom+1)
				{
					printf("-");
				}
				else if(j==0 || j==right+1)
				{
					printf("|");
				}
				else
				{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
} 
/* 
//显示棋子
void show_ball(void)
{	
	for(int i=0;i<=x;i++)
	{
		printf("\n");
	}
	for(int i=0;i<=y;i++)
	{
		printf(" ");
	}
	printf("o");	
}
*/ 
int main(int argc,const char* argv[])
{
	
	while(1)
	{ 
		x += velocity_x;
		y += velocity_y;
		//显示刷新并显示棋盘 棋子 
		system("cls");
		show_board();
		
		//show_ball();
		
		//休眠50ms 
		Sleep(100);
		
		//到达边界 修改速度方向  并响铃 
		if((x == top+1)||(x == bottom))
		{
			printf("\a"); 
			velocity_x = -velocity_x;
		}
		if((y == left+1)||(y == right))
		{
			printf("\a");
			velocity_y = -velocity_y;
		}
	}
	return 0;
}