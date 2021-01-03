#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define N 5 		//���� 
using namespace std;
//�û��ṹ�� 
typedef struct User
{
	char* name;
	int victory;	
	int	fail;
	int draw;
}User; 
//�����û����� 
User* create_user(char* str,int victory,int fail,int draw)
{
	User* user=(User*)malloc(sizeof(User));
	user->name=(char*)malloc(sizeof(str));
	strcpy(user->name,str);
	user->draw=draw;
	user->fail=fail;
	user->victory=victory;
	return user;
}
//�ڵ�ṹ�� 
typedef struct Node
{
	User* data;
	struct Node* next;
	struct Node* prev;
}Node; 
//�����ڵ㺯�� 
Node* create_node(User* user)
{
	Node *node=(Node*)malloc(sizeof(Node));
	node->data=user;
	node->next=node;
	node->prev=node;
	return node;
}
//����ṹ�� 
typedef struct List
{
	Node* head;
	int sum;
}List;
//���������� 
List* create_list(void)
{
	List* list=(List*)malloc(sizeof(Node));
	list->head=create_node(NULL);
	list->sum=0 ; 
	return list;
}
//ͷ��� 
void add_head_list(List* list,User* user)
{
	Node* node=create_node(user);

	node->next=list->head->next;
	node->prev=list->head;
	list->head->next->prev=node;	
	list->head->next=node;
	
	list->sum++;
}

//��ʾ ǰ10����ȫ�� 
void show_list(List* list,int x) 
{
	int i=0;
	for(Node* n=list->head->next;n!=list->head;n=n->next)
	{
		if(++i>10&&x!=0) 
			return ; 
		printf("���� :%d ���: %s  ʤ: %d  ��: %d  ƽ: %d\n",
		i,n->data->name,n->data->victory,n->data->fail,n->data->draw);
	}
}

//�ļ���ȡ 
void r_user(List* list)
{
	FILE* fp=fopen("user.txt","r");
	if(fp==NULL)
	{
		fp=fopen("user.txt","w");
		fclose(fp);
		return ;
	}
	char name[100];
	int a,b,c;

	while( (fgetc(fp)!=EOF) )
	{
		fseek(fp,-1,SEEK_CUR);
		fscanf(fp,"%s %d %d %d ",name,&a,&b,&c);
		 
		User* user=create_user(name,a,b,c);				
		add_head_list(list,user);
		/*
		printf("---%s--- %d --%d-- %d---\n",list->head->next->data->name,
		list->head->next->data->victory,
		list->head->next->data->fail,
		list->head->next->data->draw);
		*/
	}
	fclose(fp);
	return;
}
//�ļ�д�� 
void w_user(List* list)
{
	FILE* fp=fopen("user.txt","w");
	if(fp==NULL)
	{
		puts("Ȩ�޲���");
		fclose(fp);
		sleep(1); 
		return ;
	}
	for(Node* n=list->head->next;n!=list->head;n=n->next)
	{
		fprintf(fp,"%s %d %d %d\n",
		n->data->name,n->data->victory,n->data->fail,n->data->draw);		
	}
	fclose(fp);
}

//---------------------------------------------------------------------------- 
void key_over(void)
{
	puts("������˳�");
	getch();
}
//�򵥵��� 
void pve_simple(List* list)
{
	int draw=0,victory=0,fail=0; 
	char x;
	while(1)
	{	
		system("cls");
		if(draw+victory+fail==N)
		{
			char name[21];
			//��ʾս�� 
			printf("*��ǰս��*\nʤ: %d  ��: %d  ƽ: %d\n",victory,fail,draw); 
			//�������� 
			printf("����������� :");
			scanf("%20s",name); 
			//����ս�� 
			User* user=create_user(name,victory,fail,draw);					
			//��ӵ����� 
			add_head_list(list,user);		
			//����
			//��ʾ
			show_list(list,1);
			//�������� 
			//д���ļ�
			w_user(list); 
			//������˳� 
			key_over();
			return ;
		}
		puts("**��������Vs���˻�**");
		printf("  ��ǰս��\nʤ: %d  ��: %d  ƽ: %d\n",victory,fail,draw);
		printf("%d�ֺ����\n",N-draw-victory-fail);
		puts("---------------");
		puts("A:����");
		puts("B:ʯͷ");
		puts("C:��");
		puts("D:������,��������");
		puts("---------------"); 
		printf("��ѡ����ǣ�");
		char ch;
		ch=getch();
		int ran=rand()%3;
		switch(ch)
		{
			case 'A':;
			case 'a': 
				printf("ʯͷ\n���Գ����� :"); 
				if(0==ran)
				{
					draw++;
					puts("ʯͷ");
					puts("---------------");
					puts("ƽ��~��"); 
				} 
				else if(1==ran)
				{
					victory++;
					puts("����");
					puts("---------------");
					puts("��Ӯ����");
				}	
				else
				{
					fail++;
					puts("��");
					puts("---------------");
					puts("��ϧ��,������");
				}
				sleep(1);
				break; 
			case 'B':;
			case 'b':
				printf("����\n���Գ����� :"); 
				if(0==ran)
				{
					fail++;
					puts("ʯͷ");
					puts("---------------");
					puts("��ϧ��,������");
				}	
				else if(1==ran)
				{
					draw++;
					puts("����");
					puts("---------------");
					puts("ƽ��~��"); 
				}	
				else
				{
					victory++;
					puts("��");
					puts("---------------");
					puts("��Ӯ����"); 
				}	
				sleep(1);
				break; 
			case 'C':;
			case 'c':
				printf("����\n���Գ����� :");
				if(0==ran)
				{
					victory++;
					puts("ʯͷ");
					puts("---------------");
					puts("��Ӯ����"); 
				}	
				else if(1==ran)
				{
					fail++;
					puts("����");
					puts("---------------");
					puts("��ϧ��,������");
				}	
				else
				{
					draw++;
					puts("��");
					puts("---------------");
					puts("ƽ��~��"); 
				}	
				sleep(1);
				break;
			case 'D':;
			case 'd': 
				printf("����%d�֣����ɱ���ս��!�Ƿ����(y/n)\n",N-draw-victory-fail);
				ch=getch(); 
				if(ch=='y'||ch=='Y')
				{
				
					puts("��Ϸ����");
					sleep(1);
					system("cls");
					break;	
				}
				else
				{
					puts("��;�˳���������ս��");
					sleep(1);
					system("cls");
					return ; 
				}
		}
	}
}
//���ѵ��� 
void pve_maddening(void)
{
	system("cls");
	puts("**��δ����**");
	puts("�������� :1824860xxxx");
	key_over();
	system("cls");
}
//pve���� 
void pve_show(List* list)
{
	while(1)
	{
		system("cls");
		puts("1.��ͨ�����˻�");
		puts("2.���˷����˻�"); 
		puts("0.��������");
		cout<<"��ת :"; 
		char x=getch();
		switch(x)
		{
			case '1':
				pve_simple(list);
				break;
			case '2':
				pve_maddening(); 
				break;
			case '0':		
				return;
				break;
		}
	}
}
//���� 
void user_charts(List* list)
{
	system("cls");
	if(list->sum==0)
	{
		puts("�����û� ������ȡ��һ����");	
		key_over();
	}
	else 
	{
		show_list(list,0);
		key_over();
	}
/*
	puts("**��δ����**");
	puts("�������� :18248609615");
*/	
	system("cls");
}
//��ҳ�� 
void show_main(List* list)
{
	
	while(1)
	{
		system("cls");
		puts("+-------------+");
		puts("| 1.�˻���ս  |");
		puts("| 2.������    |");
		puts("| 0.�˳���Ϸ  |");
		puts("+-------------+");
		cout<<"��ת :"; 
		char x=getch();
		switch(x)
		{
			case '1':
				pve_show(list);
				break;
			case '2':
				user_charts(list);
				break;
			case '0':		
				return;
		}
	}
}

int main()
{
	List* list=create_list();
	r_user(list);
	/*
	while(1)
	{	
		
		show_list(list,0);
		getch();
	}
	*/
	//���������	
	srand(time(0));	
	//����	 
	show_main(list);
}
