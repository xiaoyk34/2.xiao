#include <iostream>
#include <stdlib.h>		 
using namespace std;
int q=1;				//��������  q=1Ϊ@ ��q=0Ϊ# 
int s=0;				//�������� 
char board[15][15]={ }; //�������� 
char role ='@';			//��ɫ1 @��ɫ2 # 
int key_x=7,key_y=7; 		//����λ��	
void init_board(void)	//��ʼ������ 
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			board[i][j]='*';	//���̿մ�Ϊ * 
		}
	}
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
	cout<<endl;				//ÿ15�����д�ӡ 
	}
}
 
void get_key(void)			//����
{
	cout<<"��ǰ��ɫ "<<role<<"  ������(x,y):";	//��ʾ�� 
	cin>>key_x>>key_y;							//����xy 
	// ���λ���Ƿ�Ϸ�
	if(key_x<15&&key_x>=0&&key_y<15&&key_y>=0)	// ����xy��������ʱ 
	{
		if(board[key_x][key_y]=='*')				//��������ǿ�*ʱ 
		{
			board[key_x][key_y] = role;				//�޸Ķ���� �����ӳɹ� 
			if(role=='@')							// ��ǰ��ɫΪ@���ӳɹ�ʱ 
			q=0;									// ��תq 
			else									//��ǰ��ɫΪ#���ӳɹ�ʱ
			q=1;									//��תq 
			
		}
		else  										//���������Ϊ��*ʱ �����Ѿ�����#��@ ������ʧ�� ��Ҫ�������� 
		{
			if(role=='@')							//��ǰ����Ϊ@��ɫʱ 
			q=1;									//q���� ���ּ���@��ɫ���� 
			else									//��#��ɫ����ʱ 
			q=0; 									//qҲ����  ���ּ���#��ɫ���� 
		}	
		
	}	
	else										//��������������ʱ ����Ϊ����ʧ�� ��Ҫ�������� 
	{
		if(role=='@')								//��ǰ����Ϊ@��ɫʱ 
		q=1;										//q���� ���ּ���@��ɫ���� 
		else										//��#��ɫ����ʱ 
		q=0;										//qҲ����  ���ּ���#��ɫ���� 
	}
} 

//����Ƿ����Ӳ���
int check_key()
{
	//���� 	���� 
	for(int i=1;i<5;i++) 										//���ӵ����ѭ��4�� 
	if(board[key_x][key_y-i]==role&&(key_y-i)>=0)  s++;			//��˳����������������ͬ�Ҳ����� s��++ 
	else break;													//����һ�β����� ��ǰ���� 
	for(int j=1;j<5;j++) 										//���ӵ��ұ�ѭ��4�� 
	if(board[key_x][key_y+j]==role&&(key_y+j)<15)  s++;			//��Ѹ���ҷ�������������ͬ�Ҳ����� s��++ 
	else break;													//����һ�β����� ��ǰ����
	if(s<4)														//sС��4������ �����s �ж���һ����� 
		s=0;														
	else														//����4�򷵻�s ��ζ����Ϸʤ�� 
		return s;	
	//���¡��� 
	for(int i=1;i<5;i++) 										// ���ӵ��ϱ�ѭ��4��
	if(board[key_x-i][key_y]==role&&(key_x-i)>=0)  s++;			// ��˳����������������ͬ�Ҳ����� s��++ 
	else break;													// ����һ�β����� ��ǰ���� 
	for(int j=1;j<5;j++) 										// ���ӵ��±�ѭ��4�� 
	if(board[key_x+j][key_y]==role&&(key_x+j)<15)  s++;			// ��˳���·�������������ͬ�Ҳ����� s��++ 
	else break;													// ����һ�β����� ��ǰ���� 
	if(s<4)														//sС��4������ �����s�ж���һ����� 
		s=0;
	else														//����4�򷵻�s ��ζ����Ϸʤ�� 
		return s;												 
	//�������¨I�K 
	for(int i=1;i<5;i++) 													//���ӵ����ϱ�ѭ��4�� 				
	if(board[key_x-i][key_y-i]==role&&(key_y-i)>=0&&(key_x-i)>=0)  s++;		// ˳�����Ϸ�������������ͬ�Ҳ����� s��++
	else break;																// ����һ�β����� ��ǰ���� 
	for(int j=1;j<5;j++) 													// ���ӵ����±�ѭ��4�� 
	if(board[key_x+j][key_y+j]==role&&(key_y+j)<15&&(key_x+j)<15)  s++;		// ��˳�����·�������������ͬ�Ҳ����� s��++ 
	else break;																// ��һ�β����� ��ǰ���� 
	if(s<4)																	//sС��4������ �����s�ж���һ����� 	
		s=0;
	else																	//����4�򷵻�s ��ζ����Ϸʤ�� 
		return s;															 
	//�������¨L�J 
	for(int i=1;i<5;i++) 													// ���ӵ����ϱ�ѭ��4��
	if(board[key_x-i][key_y+i]==role&&(key_y+i)<15&&(key_x-i)>=0)  s++;		// ��˳�����Ϸ�������������ͬ�Ҳ����� s��++ 
	else break;																// ��һ�β����� ��ǰ���� 
	for(int j=1;j<5;j++) 													// ���ӵ����±�ѭ��4��
	if(board[key_x+j][key_y-j]==role&&(key_y-j)>=0&&(key_x+j)<15)  s++;		// ��˳�����·�������������ͬ�Ҳ����� s��++ 
	else break;																// ��һ�β����� ��ǰ���� 
	return s;														     	// ����s 
}
//�л���ɫ
void change_role(void)
{
	if(q==1)					//��ǰq=1ʱ  
	{
		role ='@';				//��ɫΪ@ 
		q=0;					//���ӳɹ���ת 
	}
	else						//��ǰq=0ʱ 
	{
		role ='#';				//��ɫΪ# 
		q=1;					//���ӳɹ���ת 
	}	
}

int main()
{
	//��ʼ������
	init_board();
	//��ѭ��
	while(1)
	{  
        // �л���ɫ
        change_role();
        
		//��ʾ����
		show_broad();
		//����
		get_key();
		
		if(4 <=check_key())		//����Ƿ������Ӳ���
		{
			
			show_broad();		//��ʾ���� ���ʤ��һĻ 
			cout<<role<<" ʤ��!"<<endl;	//���ʤ���� 
			return 0;
		}
		s=0;					//�������� ��շ���ֵs 

	} 
	return 0;
	
	
}
