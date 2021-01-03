#include <iostream>
#include <stdlib.h>	
#include <windows.h>	 
#include <conio.h>
#include <time.h> 
using namespace std;

char board[15][15]={ }; //棋盘数组 
char role ='@';			//角色1 @角色2 # 
int key_x=7,key_y=7; 		//光标始位置	
void init_board(void)	//初始化棋盘 
{
	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
			board[i][j]='*';	//棋盘空处为 * 	
} 
void show_broad(void)		//显示棋盘
{
	system("cls");			//清空屏幕 
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			cout<<" "<<board[i][j];	//整齐输出棋盘 
		}
	cout<<endl;						//每15个换行打印 
	}
}
void get_key(void)				//落子
{
    while(1)					//光标下棋  死循环  落子成功则结束死循环 
    {
        
        COORD cp={key_y*2+1,key_x};			// // 设置光标的位置,需要头文件<windows.h> 
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp); //显示光标	
        int key = getch();					//getch（）需要头文件 <conio.h> 获取光标位置 
        if(0 == key) key = getch();			//方向键需要获取两次，且第一次为0  回车只需要一次         
        switch(key)	
        {
            case 72: key_x>0 && key_x--; break; // 上  
            case 80: key_x<14 && key_x++; break; // 下
            case 75: key_y>0 && key_y--; break; // 左
            case 77: key_y<14 && key_y++; break; // 右
            case 13: if('*' == board[key_x][key_y])	//当敲入回车时，目标区域为空* 贼落子成功 
            {        
                board[key_x][key_y] = role;			//修改目标区域 
                return;
            }
        }
    }
}
//辅助函数 
int count_key(int off_x,int off_y)					//偏移值off_x off_y 
{
    int cnt = 0;
    for(int x=key_x+off_x,y=key_y+off_y;			//初始化第一次偏移后的位置 x y； 
	x>=0 && x<15 && y>=0 && y<15 && board[x][y]==board[key_x][key_y];	//当偏移后x y满足在棋盘范围内 且偏移后位置的符号等于落子位置的符号 时 
	x+=off_x,y+=off_y)													//继续往下一个方向偏移 
    {
        cnt++;															//每循环一次则计数器++ 
    }
    return cnt;															//返回cnt的值 
}
int check_key(void)									// 检查是否有五子产生
{
    if(count_key(-1,-1)+count_key(1,1) >= 4) return 1;				//左上右下 
    if(count_key(-1,1)+count_key(1,-1) >= 4) return 1;				// 右上左下 
    if(count_key(-1,0)+count_key(1,0) >= 4) return 1;				//上下 
    if(count_key(0,-1)+count_key(0,1) >= 4) return 1;				// 左右 
    return 0;														//都不成立则返回0 
}
int main()
{
	init_board();			//初始化棋盘	
	while(1)				//死循环
	{  			
		show_broad();		//显示棋盘		
		get_key();			//落子	
		if(check_key())		//检查是否有五子产生
		{			
			show_broad();		//显示棋盘 最后胜利一幕 
			cout<<role<<" 胜利!"<<endl;	//输出胜利着 
			return 0;
		}		
        role=role=='@'?'#':'@';	//切换角色 
	} 
	return 0;	
}
