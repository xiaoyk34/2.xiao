#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <getch.h>
char board[15][15];
char keyx=7,keyy=7;
char role='@';
void init_board(void)
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			board[i][j]='*';
		}
	}
}
void show_board(void)
{
	system("clear");
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			printf(" %c",board[i][j]);
		}
		printf("\n");
	}
	
}
void get_key(void)
{
	printf("Çë%cÏÂÆå\n",role);
	for(;;)
	{
		printf("\33[%hhd;%hhdH",keyx+1,(keyy+1)*2);
		switch(getch())
		{
			case 183:keyx>0&&keyx--;break;
			case 184:keyx<14&&keyx++;break;
			case 185:keyy<14&&keyy++;break;
			case 186:keyy>0&&keyy--;break;
			case 10:
				if(board[keyx][keyy]=='*')
				{
					board[keyx][keyy]=role;
					return;
				}

		}
	}
}
int check_board(int gox,int goy)
{
	int count=0;
	for(int x=keyx+gox,y=keyy+goy;x<15&&x>=0&&y>=0&&y<15;x+=gox,y+=goy)
	{
		if(board[x][y]==role)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}
bool check_count(void)
{
	if(check_board(-1,-1)+check_board(1,1)>=4)
		return true;
	if(check_board(-1,0)+check_board(1,0)>=4)
		return true;
	if(check_board(0,-1)+check_board(0,1)>=4)
		return true;
	if(check_board(-1,1)+check_board(1,-1)>=4)
		return true;
	else 
		return false;
}
int main(int argc,const char* argv[])
{
	init_board();
	for(;;)
	{
		show_board();
		get_key();
		if(check_count())
		{
			show_board();
			printf("%cÊ¤Àû£¡£¡£¡£¡\n",role);
			return 0;
		}
		role=role=='@'?'$':'@';
	}
}
