#include <iostream>
#include <conio.h> 			//����ͷ�ļ� 
#include <time.h>			//ʱ��ͷ�ļ� 
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
	};//���ڡ�8��14��  
	int mouse_x =1 ,mouse_y =1;  				//С�������� 
	
	int q=time(0);								//��ʼ��ʱ 
							
	while(1)									//��ѭ�� 
	{	
		
		system("cls"); 							// ������Ļ
		
		for(int i=0;i<10;i++)					//��ʾ�Թ� 
		{
			for(int j=0;j<15;j++)
			{
				cout<<maze[i][j];
			}
		cout<<endl;	
		}
		
		  if(8 == mouse_x && 14 == mouse_y)		// �ж��Ƿ��߳��Թ�
        {
        	int k=time(0);						//ͨ��ʱ�� 
            
			cout<<"over��over!"<<endl<<"ͨ��ʱ�� ��"<<k-q<<"��";	//���ʱ�� 
        	//return 0;
			 
           
        }
		
		switch(getch())							//�жϰ��� 
		{
			case 'w':  							//w 
			if(maze[mouse_x-1][mouse_y]==' ')	//�Ϸ���·��  
			{
			maze[mouse_x][mouse_y]	=' ';		//�ƶ������ԭλ����� 
			maze[mouse_x-1][mouse_y]='@';		//�ƶ�������λ�� 
			mouse_x=mouse_x-1;					//�ı��������� 
			}
			break; 								//������� 
			
            case 's':  							//s 
			if
			(maze[mouse_x+1][mouse_y]==' ')		//�·���·�� 
			{
			maze[mouse_x][mouse_y]=' ';			 
			maze[mouse_x+1][mouse_y]='@';
			mouse_x=mouse_x+1;
			}
			break;
			
            case 'a':  							//a 
			if(maze[mouse_x][mouse_y-1]==' ')	//����·�� 
			{
			maze[mouse_x][mouse_y]=' ';
			maze[mouse_x][mouse_y-1]='@';
			mouse_y=mouse_y-1;
			}
			break;
           
		    case 'd':  							//d 
			if(maze[mouse_x][mouse_y+1]==' ')	//�ҷ���·�� 
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
