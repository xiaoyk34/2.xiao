#include <stdio.h>
#include <time.h>		//���������time(0)ͷ�ļ� 
#include <stdlib.h>	  
#include <windows.h>	//systemͷ�ļ� ˢ�� 
#include <conio.h>  //getch()ͷ�ļ� 
int a[4][4]; //���� 
int s;//�Ʒ��� 
int x=1;//�ж��Ƿ���Ч�ƶ���� 
//��ʾ���� �� ʵʱ�÷� 
void xianshi()
{
	for(int i=0;i<4;i++)
	{
		printf("---------------------\n");
		for(int j=0;j<4;j++)
		{
			if(a[i][j]==0) 			 
				printf("|    ");	//Ϊ������ո� 
			else 
				printf("|%4d",a[i][j]);//��Ϊ�������ռ4λ�Ҷ���ø����� 
		}
		printf("|\n");					
	}
	printf("---------------------\n");
	printf("�÷֣�%d\n",s); 	//���� 
}
//ͳ�ƻ��м����ո� 
int count()
{
	int k=0;
	for(int i=0;i<4;i++)//���� 
	{
		for(int j=0;j<4;j++)
		{
			if(a[i][j]==0) //���п�λʱ k++ 
				k++;	
		}
	} 
	return k; //���ؿ�λ��k 
} 
//����һ������� �ٷ�֮30���ʳ���4 �ٷ�֮70����2 
void suijishu()
{
	srand(time(NULL));	//���������  
	if(x==0||count()==0) return; //��û�п�λ ���� ��Ч�ƶ��򲻳����µ�˯���� 
	while(1)
	{
		int x=rand()%4;
		int y=rand()%4;
		int t=rand()%10;
		if(a[x][y]==0)
		{
			if(t<3)
			{
				a[x][y]=4;
				return ;
			}
			else 
			{
				a[x][y]=2;
				return ;
			}
		}
	}
}
//�Ƿ���Ϸ���� �����򷵻�1 ������� ���򷵻�0������ 
int over()	
{
	for(int i=0;i<4;i++)//���� 
	{
		for(int j=0;j<4;j++)
		{
			if(a[i][j]==0)		// ��ǰΪ0�򻹿����ƶ� 
			return 0;
			if( (j<3&&a[i][j]==a[i][j+1]) ||  
			(j>0&&a[i][j]==a[i][j-1]) ||
			(i>0&&a[i][j]==a[i-1][j]) || 
			(i<3&&a[i][j]==a[i+1][j])  )
			return 0;//��ǰ�������� ����ͬ������˵�� �������ƶ� 
		}
	}
	return 1;//�������˵��������� 
}
//�� 
void up()
{
	for(int i=0;i<4;i++)	//���п� 
	{
		for(int j=1;j<4;j++)	//ÿ�дӵ�2������ʼ 
		{
			if(a[j][i])	//��ǰ��Ϊ0����һ�� ��Ϊ������������ж� 
			{
				int t=-1;	//���λt�� -1��0 1 2 ������������ԣ� 
				for(int k=j-1;k>=0&& ( a[j][i]==a[k][i] || a[k][i]==0 );k-- )
				//kΪ��ǰλ��ǰһλ  ���ܳ����� ����0 ������ͬ�� �ͼ�¼ kֵ 
				{
					t=k;
				}
				if(t!=-1)	//k���޸���˵�����Ե��� 
				{
					if(a[t][i]!=0)	//������Ǽ�0���� ��������� 
						s+=a[t][i]*2;
					a[t][i]+=a[j][i];//�Ѻ������ӵ�ǰ�� 
					a[j][i]=0;//��������0 
					x=1;	//���λx��1 ֤����Ч�ƶ� ���Բ����µ������ 
				}
			}		
		}	
	} 
}
//�� 
void down()
{
	for(int i=0;i<4;i++)
	{
		for(int j=2;j>=0;j--)
		{
			if(a[j][i])
			{
				int t=-1;
				for(int k=j+1;k<=3&&(a[j][i]==a[k][i] || a[k][i]==0 );k++ )
				{
					t=k;
				}
				if(t!=-1)
				{
					if(a[t][i]!=0)
						s+=a[t][i]*2;
					a[t][i]+=a[j][i];
					a[j][i]=0;
					x=1;
				}
			}		
		}	
	} 
}
//�� 
void right()
{
	for(int i=0;i<4;i++)
	{
		for(int j=2;j>=0;j--)
		{
			if(a[i][j])
            {
                int t = -1;
                for(int k=j+1; k<=3 && (0==a[i][k]||a[i][k]==a[i][j]); k++)
                {
                    t = k;
                }
                if(-1 != t)
                {
                    if(a[i][t]!=0)
						s+=a[i][t]*2;
                    a[i][t] += a[i][j];
                    a[i][j] = 0;
                    x=1;
                    
                }
            }
			
		}
	}

}
//�� 
void left()
{
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<4;j++)
		{
			if(a[i][j])
            {
                int t = -1;
                for(int k=j-1; k>=0 && (0==a[i][k]||a[i][k]==a[i][j]); k--)
                {
                    t = k;
                }
                if(-1 != t)
                {
                	if(a[i][t]!=0)
						s+=a[i][t]*2;
                    a[i][t] += a[i][j];                   
                    a[i][j] = 0;
                    x=1;
                }
            }
			
		}	
	}
}

int main()
{
	while(1)
	{
		//ˢ����Ļ 
		system("cls"); 
		//���������
		suijishu(); 
		//��ʾ���� 
		xianshi();
		// �ж��Ƿ����
		if(over())	//��Ϸʧ�� �������� 
		{
			printf("��Ϸ���� �÷֣�%d\n",s); 
			while(1); //return 0;  ��дreturn 0��̫���ֱ�ӹر�   
		} 
		x=0;	//�޸�x��0 
		//�ƶ� 
		switch(getch()+getch()) //Windows����������Ҫ��ȡ���� 
		{
			case 296:up();break;	
			case 304:down();break;
			case 299:left();break;
			case 301:right();break;
		}
	}
}
