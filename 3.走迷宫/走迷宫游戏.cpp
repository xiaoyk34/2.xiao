#include <iostream>
#include <conio.h> 			//清屏头文件 
#include <time.h>			//时间头文件 
using namespace std;
int main()
{
	char maze[10][15]={
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
	{'#','@','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#','#'},
	{'#',' ','#','#',' ','#','#',' ','#',' ','#','#',' ','#','#'},
	{'#',' ','#','#',' ','#','#',' ','#',' ','#','#',' ','#','#'},
	{'#',' ','#','#',' ','#','#',' ',' ',' ','#','#',' ','#','#'},
	{'#',' ','#','#',' ','#','#','#','#','#','#','#',' ','#','#'},
	{'#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ','#','#'},
	{'#',' ','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ','#','#','#',' ',' ',' ',' ','#','#','#','#',' ',' '},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
	};//出口【8，14】  
	int mouse_x =1 ,mouse_y =1;  				//小老鼠坐标 
	
	int q=time(0);								//开始记时 
							
	while(1)									//死循环 
	{	
		
		system("cls"); 							// 清理屏幕
		
		for(int i=0;i<10;i++)					//显示迷宫 
		{
			for(int j=0;j<15;j++)
			{
				cout<<maze[i][j];
			}
		cout<<endl;	
		}
		
		  if(8 == mouse_x && 14 == mouse_y)		// 判断是否走出迷宫
        {
        	int k=time(0);						//通关时间 
            
			cout<<"over！over!"<<endl<<"通关时间 ："<<k-q<<"秒";	//输出时间 
        	//return 0;
			 
           
        }
		
		switch(getch())							//判断按键 
		{
			case 'w':  							//w 
			if(maze[mouse_x-1][mouse_y]==' ')	//上方有路则  
			{
			maze[mouse_x][mouse_y]	=' ';		//移动老鼠后原位置清空 
			maze[mouse_x-1][mouse_y]='@';		//移动老鼠到新位置 
			mouse_x=mouse_x-1;					//改变老鼠坐标 
			}
			break; 								//结束这次 
			
            case 's':  							//s 
			if
			(maze[mouse_x+1][mouse_y]==' ')		//下方有路则 
			{
			maze[mouse_x][mouse_y]=' ';			 
			maze[mouse_x+1][mouse_y]='@';
			mouse_x=mouse_x+1;
			}
			break;
			
            case 'a':  							//a 
			if(maze[mouse_x][mouse_y-1]==' ')	//左方有路则 
			{
			maze[mouse_x][mouse_y]=' ';
			maze[mouse_x][mouse_y-1]='@';
			mouse_y=mouse_y-1;
			}
			break;
           
		    case 'd':  							//d 
			if(maze[mouse_x][mouse_y+1]==' ')	//右方有路则 
			{
			maze[mouse_x][mouse_y]=' ';
			maze[mouse_x][mouse_y+1]='@';
			mouse_y=mouse_y+1;
			}
			break;
		}
	}
	
	return 0;
 } 
