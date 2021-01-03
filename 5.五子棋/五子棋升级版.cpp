#include <iostream>
#include <stdlib.h>	
#include <windows.h>	 
#include <conio.h>
#include <time.h> 
using namespace std;
int q=1;				//换人条件  q=1为@ ，q=0为# 
int s=0;				//几子连线 
char board[15][15]={ }; //棋盘数组 
char role ='@';			//角色1 @角色2 # 
int key_x=7,key_y=7; 		//棋子位置	
void init_board(void)	//初始化棋盘 
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			board[i][j]='*';	//棋盘空处为 * 
		}
	}
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
	cout<<endl;				//每15个换行打印 
	}
}
 
void get_key(void)			//落子
{
    for(;;)					//光标下棋  死循环  落子成功则结束死循环 
    {
        // 设置光标的位置
        COORD cp={key_y*2+1,key_x};			// 需要头文件<windows.h> 
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);	

        // 获取方向键
        int key = getch();					//需要头文件 <conio.h>
        if(0 == key) key = getch();			//方向键需要判断两次，且第一次为0  回车只需要一次 
        
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

//检查是否五子产生
int check_key()
{
	//左右 	←→ 
	for(int i=1;i<5;i++) 										//落子点左边循环4次 
	if(board[key_x][key_y-i]==role&&(key_y-i)>=0)  s++;			//按顺序左方依次与落子相同且不过界 s则++ 
	else break;													//若有一次不等则 提前结束 
	for(int j=1;j<5;j++) 										//落子点右边循环4次 
	if(board[key_x][key_y+j]==role&&(key_y+j)<15)  s++;			//按迅速右方依次与落子相同且不过界 s则++ 
	else break;													//若有一次不等则 提前结束
	if(s<4)														//s小于4不成立 ，清空s 判断下一个情况 
		s=0;														
	else														//大于4则返回s 意味着游戏胜利 
		return s;	
	//上下↑↓ 
	for(int i=1;i<5;i++) 										// 落子点上边循环4次
	if(board[key_x-i][key_y]==role&&(key_x-i)>=0)  s++;			// 按顺序左方依次与落子相同且不过界 s则++ 
	else break;													// 若有一次不等则 提前结束 
	for(int j=1;j<5;j++) 										// 落子点下边循环4次 
	if(board[key_x+j][key_y]==role&&(key_x+j)<15)  s++;			// 按顺序下方依次与落子相同且不过界 s则++ 
	else break;													// 若有一次不等则 提前结束 
	if(s<4)														//s小于4不成立 ，清空s判断下一个情况 
		s=0;
	else														//大于4则返回s 意味着游戏胜利 
		return s;												 
	//左上右下↖↘ 
	for(int i=1;i<5;i++) 													//落子点左上边循环4次 				
	if(board[key_x-i][key_y-i]==role&&(key_y-i)>=0&&(key_x-i)>=0)  s++;		// 顺序左上方依次与落子相同且不过界 s则++
	else break;																// 若有一次不等则 提前结束 
	for(int j=1;j<5;j++) 													// 落子点右下边循环4次 
	if(board[key_x+j][key_y+j]==role&&(key_y+j)<15&&(key_x+j)<15)  s++;		// 按顺序右下方依次与落子相同且不过界 s则++ 
	else break;																// 有一次不等则 提前结束 
	if(s<4)																	//s小于4不成立 ，清空s判断下一个情况 	
		s=0;
	else																	//大于4则返回s 意味着游戏胜利 
		return s;															 
	//右上左下↙↗ 
	for(int i=1;i<5;i++) 													// 落子点右上边循环4次
	if(board[key_x-i][key_y+i]==role&&(key_y+i)<15&&(key_x-i)>=0)  s++;		// 按顺序右上方依次与落子相同且不过界 s则++ 
	else break;																// 有一次不等则 提前结束 
	for(int j=1;j<5;j++) 													// 落子点左下边循环4次
	if(board[key_x+j][key_y-j]==role&&(key_y-j)>=0&&(key_x+j)<15)  s++;		// 按顺序左下方依次与落子相同且不过界 s则++ 
	else break;																// 有一次不等则 提前结束 
	if(s<4)																	//s小于4不成立 ，清空s判断下一个情况 	
		s=0;
	else																	//大于4则返回s 意味着游戏胜利 
		return s;			
}
//切换角色
void change_role(void)
{
	if(q==1)					//当前q=1时  
	{
		role ='@';				//角色为@ 
		q=0;					//落子成功后翻转 		
	}
	else						//当前q=0时 
	{
		role ='#';				//角色为# 
		
		q=1;					//落子成功后翻转 
	}	
}

int main()
{
	
	//初始化棋盘
	init_board();
	//死循环
	while(1)
	{  
        // 切换角色
        change_role();
        
		//显示棋盘
		show_broad();
		//落子
		get_key();
		
		if(4 <=check_key())		//检查是否有五子产生
		{			
			show_broad();		//显示棋盘 最后胜利一幕 
			cout<<role<<" 胜利!"<<endl;	//输出胜利着 
			return 0;
		}
	

	} 
	return 0;	
}
