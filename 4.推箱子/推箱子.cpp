#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h> 
using namespace std;
int main()
{
	//空格0=' '  墙1='#'  目标3='O' 箱子4='M'  箱子到目标7='M'  小人到目标8='@' 小人5='@' 
	int arr[8][8]={
		{0,0,1,1,1,1,0,0},
		{0,0,1,3,3,1,0,0},
		{0,1,1,0,3,1,1,0},
		{0,1,0,0,4,3,1,0},
		{1,1,0,4,0,0,1,1} ,
		{1,0,0,1,4,4,0,1} ,
		{1,0,0,5,0,0,0,1} ,
		{1,1,1,1,1,1,1,1} , 
	};
	//记录时间
		int t=time(0); 
	//记录步数 
		int q=0;
	//小人坐标 
	int work_x=6, work_y=3;
	while(1)
	{

		// 记录完成数量 
		int cnt=0;
		//清理屏幕 
		system("cls");
		//显示地图 
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				switch(arr[i][j])
				{
					case  0:cout<<" ";break;
					case  1:cout<<"#";break;
					case  3:cout<<"O";break;
					case  4:cout<<"M"; break;
					case  5:cout<<"@";break;
					case  8:cout<<"@";break;
					case  7:cout<<"M";cnt++; break;
				}
			}
			cout<<endl; 
		}
		//判断是否过关
		if(4==cnt)
		{
			cout<<"通关！"<<endl<<"步数 ： "<<q<<"步"<<endl<<"通关时间 ： "<<time(0)-t<<"秒"; 
			//return 0;
		} 
		
		//按键获取 
		switch(getch())
		{
			case 'w' :	
			{
				if(arr[work_x-1][work_y]==0||arr[work_x-1][work_y]==3)
				{
					arr[work_x][work_y]-=5;		//1.前方是目标是空或目标 直接走
					arr[work_x-1][work_y]+=5;	//原位置-5 新位置+5 
					work_x-=1;
					q++; 
				}
				else if(arr[work_x-1][work_y]==4||arr[work_x-1][work_y]==7)	//2.前方是箱子或者箱子加目标 
				{
					if(arr[work_x-2][work_y]==0||arr[work_x-2][work_y]==3)	//判断箱子前面是目标或者是空 
					{
						arr[work_x-1][work_y]-=4;			//箱子原位置-4 箱子新位置+4 
						arr[work_x-2][work_y]+=4;
						arr[work_x][work_y]-=5;				//小人原位置-5 新位置+5 
						arr[work_x-1][work_y]+=5;
						work_x-=1;
						q++;
					} 
					
				}
			}
				break;
				
				
				 
			case 's' :
			{
				if(arr[work_x+1][work_y]==0||arr[work_x+1][work_y]==3)
				{
					arr[work_x][work_y]-=5;		//1.前方是目标是空或目标 直接走
					arr[work_x+1][work_y]+=5;	//原位置-5 新位置+5 
					work_x+=1;
					q++;
				}
				else if(arr[work_x+1][work_y]==4||arr[work_x+1][work_y]==7)	//2.前方是箱子或者箱子加目标 
				{
					if(arr[work_x+2][work_y]==0||arr[work_x+2][work_y]==3)	//判断箱子前面是目标或者是空 
					{
						arr[work_x+1][work_y]-=4;			//箱子原位置-4 箱子新位置+4 
						arr[work_x+2][work_y]+=4;
						arr[work_x][work_y]-=5;				//小人原位置-5 新位置+5 
						arr[work_x+1][work_y]+=5;
						q++;
						work_x+=1;
					} 
					
				}
			}
				break;
								
			case 'a' :
			{
				if(arr[work_x][work_y-1]==0||arr[work_x][work_y-1]==3)
				{
					arr[work_x][work_y]-=5;		//1.前方是目标是空或目标 直接走
					arr[work_x][work_y-1]+=5;	//原位置-5 新位置+5 
					work_y-=1;
					q++;
				}
				else if(arr[work_x][work_y-1]==4||arr[work_x][work_y-1]==7)	//2.前方是箱子或者箱子加目标 
				{
					if(arr[work_x][work_y-2]==0||arr[work_x][work_y-2]==3)	// 判断箱子前面是目标或者是空 
					{
						arr[work_x][work_y-1]-=4;			//箱子原位置-4 箱子新位置+4 
						arr[work_x][work_y-2]+=4;
						arr[work_x][work_y]-=5;				//小人原位置-5 新位置+5 
						arr[work_x][work_y-1]+=5;
						work_y-=1;
						q++;
					} 
				}
			}
				break;
			case 'd' :
			{
				if(arr[work_x][work_y+1]==0||arr[work_x][work_y+1]==3)
				{
					arr[work_x][work_y]-=5;		//1.前方是目标是空或目标 直接走
					arr[work_x][work_y+1]+=5;	//原位置-5 新位置+5 
					work_y+=1;
					q++;
				}
				else if(arr[work_x][work_y+1]==4||arr[work_x][work_y+1]==7)	//2.前方是箱子或者箱子加目标 
				{
					if(arr[work_x][work_y+2]==0||arr[work_x][work_y+2]==3)	//判断箱子前面是目标或者是空 
					{
						arr[work_x][work_y+1]-=4;			//箱子原位置-4 箱子新位置+4 
						arr[work_x][work_y+2]+=4;
						arr[work_x][work_y]-=5;				//小人原位置-5 新位置+5 
						arr[work_x][work_y+1]+=5;
						work_y+=1;
						q++;
					} 
				}
			}							
		}
	} 
} 

