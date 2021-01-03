#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define N 5 		//次数 
using namespace std;
//用户结构体 
typedef struct User
{
	char* name;
	int victory;	
	int	fail;
	int draw;
}User; 
//创建用户函数 
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
//节点结构体 
typedef struct Node
{
	User* data;
	struct Node* next;
	struct Node* prev;
}Node; 
//创建节点函数 
Node* create_node(User* user)
{
	Node *node=(Node*)malloc(sizeof(Node));
	node->data=user;
	node->next=node;
	node->prev=node;
	return node;
}
//链表结构体 
typedef struct List
{
	Node* head;
	int sum;
}List;
//创建链表函数 
List* create_list(void)
{
	List* list=(List*)malloc(sizeof(Node));
	list->head=create_node(NULL);
	list->sum=0 ; 
	return list;
}
//头添加 
void add_head_list(List* list,User* user)
{
	Node* node=create_node(user);

	node->next=list->head->next;
	node->prev=list->head;
	list->head->next->prev=node;	
	list->head->next=node;
	
	list->sum++;
}

//显示 前10个或全部 
void show_list(List* list,int x) 
{
	int i=0;
	for(Node* n=list->head->next;n!=list->head;n=n->next)
	{
		if(++i>10&&x!=0) 
			return ; 
		printf("名次 :%d 玩家: %s  胜: %d  负: %d  平: %d\n",
		i,n->data->name,n->data->victory,n->data->fail,n->data->draw);
	}
}

//文件读取 
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
//文件写入 
void w_user(List* list)
{
	FILE* fp=fopen("user.txt","w");
	if(fp==NULL)
	{
		puts("权限不足");
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
	puts("任意键退出");
	getch();
}
//简单电脑 
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
			//显示战绩 
			printf("*当前战绩*\n胜: %d  负: %d  平: %d\n",victory,fail,draw); 
			//输入名字 
			printf("输入你的名字 :");
			scanf("%20s",name); 
			//保存战绩 
			User* user=create_user(name,victory,fail,draw);					
			//添加到链表 
			add_head_list(list,user);		
			//排序
			//显示
			show_list(list,1);
			//给出结论 
			//写入文件
			w_user(list); 
			//任意键退出 
			key_over();
			return ;
		}
		puts("**聪明的你Vs简单人机**");
		printf("  当前战绩\n胜: %d  负: %d  平: %d\n",victory,fail,draw);
		printf("%d局后结束\n",N-draw-victory-fail);
		puts("---------------");
		puts("A:剪刀");
		puts("B:石头");
		puts("C:布");
		puts("D:不玩了,溜了溜了");
		puts("---------------"); 
		printf("你选择的是：");
		char ch;
		ch=getch();
		int ran=rand()%3;
		switch(ch)
		{
			case 'A':;
			case 'a': 
				printf("石头\n电脑出的是 :"); 
				if(0==ran)
				{
					draw++;
					puts("石头");
					puts("---------------");
					puts("平局~！"); 
				} 
				else if(1==ran)
				{
					victory++;
					puts("剪刀");
					puts("---------------");
					puts("你赢啦！");
				}	
				else
				{
					fail++;
					puts("布");
					puts("---------------");
					puts("可惜了,你输了");
				}
				sleep(1);
				break; 
			case 'B':;
			case 'b':
				printf("剪刀\n电脑出的是 :"); 
				if(0==ran)
				{
					fail++;
					puts("石头");
					puts("---------------");
					puts("可惜了,你输了");
				}	
				else if(1==ran)
				{
					draw++;
					puts("剪刀");
					puts("---------------");
					puts("平局~！"); 
				}	
				else
				{
					victory++;
					puts("布");
					puts("---------------");
					puts("你赢啦！"); 
				}	
				sleep(1);
				break; 
			case 'C':;
			case 'c':
				printf("剪刀\n电脑出的是 :");
				if(0==ran)
				{
					victory++;
					puts("石头");
					puts("---------------");
					puts("你赢啦！"); 
				}	
				else if(1==ran)
				{
					fail++;
					puts("剪刀");
					puts("---------------");
					puts("可惜了,你输了");
				}	
				else
				{
					draw++;
					puts("布");
					puts("---------------");
					puts("平局~！"); 
				}	
				sleep(1);
				break;
			case 'D':;
			case 'd': 
				printf("还有%d局，即可保存战绩!是否继续(y/n)\n",N-draw-victory-fail);
				ch=getch(); 
				if(ch=='y'||ch=='Y')
				{
				
					puts("游戏继续");
					sleep(1);
					system("cls");
					break;	
				}
				else
				{
					puts("中途退出，不保存战绩");
					sleep(1);
					system("cls");
					return ; 
				}
		}
	}
}
//困难电脑 
void pve_maddening(void)
{
	system("cls");
	puts("**暂未开放**");
	puts("赞助号码 :1824860xxxx");
	key_over();
	system("cls");
}
//pve界面 
void pve_show(List* list)
{
	while(1)
	{
		system("cls");
		puts("1.普通入门人机");
		puts("2.令人发狂人机"); 
		puts("0.溜了溜了");
		cout<<"跳转 :"; 
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
//排名 
void user_charts(List* list)
{
	system("cls");
	if(list->sum==0)
	{
		puts("暂无用户 快来夺取第一名把");	
		key_over();
	}
	else 
	{
		show_list(list,0);
		key_over();
	}
/*
	puts("**暂未开放**");
	puts("赞助号码 :18248609615");
*/	
	system("cls");
}
//主页面 
void show_main(List* list)
{
	
	while(1)
	{
		system("cls");
		puts("+-------------+");
		puts("| 1.人机对战  |");
		puts("| 2.名人堂    |");
		puts("| 0.退出游戏  |");
		puts("+-------------+");
		cout<<"跳转 :"; 
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
	//随机数种子	
	srand(time(0));	
	//界面	 
	show_main(list);
}
