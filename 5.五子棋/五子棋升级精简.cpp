#include <iostream>
#include <stdlib.h>	
#include <windows.h>	 
#include <conio.h>
#include <time.h> 
using namespace std;

char board[15][15]={ }; //�������� 
char role ='@';			//��ɫ1 @��ɫ2 # 
int key_x=7,key_y=7; 		//���ʼλ��	
void init_board(void)	//��ʼ������ 
{
	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
			board[i][j]='*';	//���̿մ�Ϊ * 	
} 
void show_broad(void)		//��ʾ����
{
	system("cls");			//�����Ļ 
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			cout<<" "<<board[i][j];	//����������� 
		}
	cout<<endl;						//ÿ15�����д�ӡ 
	}
}
void get_key(void)				//����
{
    while(1)					//�������  ��ѭ��  ���ӳɹ��������ѭ�� 
    {
        
        COORD cp={key_y*2+1,key_x};			// // ���ù���λ��,��Ҫͷ�ļ�<windows.h> 
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp); //��ʾ���	
        int key = getch();					//getch������Ҫͷ�ļ� <conio.h> ��ȡ���λ�� 
        if(0 == key) key = getch();			//�������Ҫ��ȡ���Σ��ҵ�һ��Ϊ0  �س�ֻ��Ҫһ��         
        switch(key)	
        {
            case 72: key_x>0 && key_x--; break; // ��  
            case 80: key_x<14 && key_x++; break; // ��
            case 75: key_y>0 && key_y--; break; // ��
            case 77: key_y<14 && key_y++; break; // ��
            case 13: if('*' == board[key_x][key_y])	//������س�ʱ��Ŀ������Ϊ��* �����ӳɹ� 
            {        
                board[key_x][key_y] = role;			//�޸�Ŀ������ 
                return;
            }
        }
    }
}
//�������� 
int count_key(int off_x,int off_y)					//ƫ��ֵoff_x off_y 
{
    int cnt = 0;
    for(int x=key_x+off_x,y=key_y+off_y;			//��ʼ����һ��ƫ�ƺ��λ�� x y�� 
	x>=0 && x<15 && y>=0 && y<15 && board[x][y]==board[key_x][key_y];	//��ƫ�ƺ�x y���������̷�Χ�� ��ƫ�ƺ�λ�õķ��ŵ�������λ�õķ��� ʱ 
	x+=off_x,y+=off_y)													//��������һ������ƫ�� 
    {
        cnt++;															//ÿѭ��һ���������++ 
    }
    return cnt;															//����cnt��ֵ 
}
int check_key(void)									// ����Ƿ������Ӳ���
{
    if(count_key(-1,-1)+count_key(1,1) >= 4) return 1;				//�������� 
    if(count_key(-1,1)+count_key(1,-1) >= 4) return 1;				// �������� 
    if(count_key(-1,0)+count_key(1,0) >= 4) return 1;				//���� 
    if(count_key(0,-1)+count_key(0,1) >= 4) return 1;				// ���� 
    return 0;														//���������򷵻�0 
}
int main()
{
	init_board();			//��ʼ������	
	while(1)				//��ѭ��
	{  			
		show_broad();		//��ʾ����		
		get_key();			//����	
		if(check_key())		//����Ƿ������Ӳ���
		{			
			show_broad();		//��ʾ���� ���ʤ��һĻ 
			cout<<role<<" ʤ��!"<<endl;	//���ʤ���� 
			return 0;
		}		
        role=role=='@'?'#':'@';	//�л���ɫ 
	} 
	return 0;	
}
