#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h> 
using namespace std;
int main()
{
	//�ո�0=' '  ǽ1='#'  Ŀ��3='O' ����4='M'  ���ӵ�Ŀ��7='M'  С�˵�Ŀ��8='@' С��5='@' 
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
	//��¼ʱ��
		int t=time(0); 
	//��¼���� 
		int q=0;
	//С������ 
	int work_x=6, work_y=3;
	while(1)
	{

		// ��¼������� 
		int cnt=0;
		//������Ļ 
		system("cls");
		//��ʾ��ͼ 
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
		//�ж��Ƿ����
		if(4==cnt)
		{
			cout<<"ͨ�أ�"<<endl<<"���� �� "<<q<<"��"<<endl<<"ͨ��ʱ�� �� "<<time(0)-t<<"��"; 
			//return 0;
		} 
		
		//������ȡ 
		switch(getch())
		{
			case 'w' :	
			{
				if(arr[work_x-1][work_y]==0||arr[work_x-1][work_y]==3)
				{
					arr[work_x][work_y]-=5;		//1.ǰ����Ŀ���ǿջ�Ŀ�� ֱ����
					arr[work_x-1][work_y]+=5;	//ԭλ��-5 ��λ��+5 
					work_x-=1;
					q++; 
				}
				else if(arr[work_x-1][work_y]==4||arr[work_x-1][work_y]==7)	//2.ǰ�������ӻ������Ӽ�Ŀ�� 
				{
					if(arr[work_x-2][work_y]==0||arr[work_x-2][work_y]==3)	//�ж�����ǰ����Ŀ������ǿ� 
					{
						arr[work_x-1][work_y]-=4;			//����ԭλ��-4 ������λ��+4 
						arr[work_x-2][work_y]+=4;
						arr[work_x][work_y]-=5;				//С��ԭλ��-5 ��λ��+5 
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
					arr[work_x][work_y]-=5;		//1.ǰ����Ŀ���ǿջ�Ŀ�� ֱ����
					arr[work_x+1][work_y]+=5;	//ԭλ��-5 ��λ��+5 
					work_x+=1;
					q++;
				}
				else if(arr[work_x+1][work_y]==4||arr[work_x+1][work_y]==7)	//2.ǰ�������ӻ������Ӽ�Ŀ�� 
				{
					if(arr[work_x+2][work_y]==0||arr[work_x+2][work_y]==3)	//�ж�����ǰ����Ŀ������ǿ� 
					{
						arr[work_x+1][work_y]-=4;			//����ԭλ��-4 ������λ��+4 
						arr[work_x+2][work_y]+=4;
						arr[work_x][work_y]-=5;				//С��ԭλ��-5 ��λ��+5 
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
					arr[work_x][work_y]-=5;		//1.ǰ����Ŀ���ǿջ�Ŀ�� ֱ����
					arr[work_x][work_y-1]+=5;	//ԭλ��-5 ��λ��+5 
					work_y-=1;
					q++;
				}
				else if(arr[work_x][work_y-1]==4||arr[work_x][work_y-1]==7)	//2.ǰ�������ӻ������Ӽ�Ŀ�� 
				{
					if(arr[work_x][work_y-2]==0||arr[work_x][work_y-2]==3)	// �ж�����ǰ����Ŀ������ǿ� 
					{
						arr[work_x][work_y-1]-=4;			//����ԭλ��-4 ������λ��+4 
						arr[work_x][work_y-2]+=4;
						arr[work_x][work_y]-=5;				//С��ԭλ��-5 ��λ��+5 
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
					arr[work_x][work_y]-=5;		//1.ǰ����Ŀ���ǿջ�Ŀ�� ֱ����
					arr[work_x][work_y+1]+=5;	//ԭλ��-5 ��λ��+5 
					work_y+=1;
					q++;
				}
				else if(arr[work_x][work_y+1]==4||arr[work_x][work_y+1]==7)	//2.ǰ�������ӻ������Ӽ�Ŀ�� 
				{
					if(arr[work_x][work_y+2]==0||arr[work_x][work_y+2]==3)	//�ж�����ǰ����Ŀ������ǿ� 
					{
						arr[work_x][work_y+1]-=4;			//����ԭλ��-4 ������λ��+4 
						arr[work_x][work_y+2]+=4;
						arr[work_x][work_y]-=5;				//С��ԭλ��-5 ��λ��+5 
						arr[work_x][work_y+1]+=5;
						work_y+=1;
						q++;
					} 
				}
			}							
		}
	} 
} 

