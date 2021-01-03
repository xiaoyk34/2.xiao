#include <stdio.h>
#include <time.h>		//随机数种子time(0)头文件 
#include <stdlib.h>	  
#include <windows.h>	//system头文件 刷屏 
#include <conio.h>  //getch()头文件 
int a[4][4]; //棋盘 
int s;//计分器 
int x=1;//判断是否有效移动标记 
//显示棋盘 与 实时得分 
void xianshi()
{
	for(int i=0;i<4;i++)
	{
		printf("---------------------\n");
		for(int j=0;j<4;j++)
		{
			if(a[i][j]==0) 			 
				printf("|    ");	//为则输出空格 
			else 
				printf("|%4d",a[i][j]);//不为零则输出占4位右对齐得该数字 
		}
		printf("|\n");					
	}
	printf("---------------------\n");
	printf("得分：%d\n",s); 	//分数 
}
//统计还有几个空格 
int count()
{
	int k=0;
	for(int i=0;i<4;i++)//遍历 
	{
		for(int j=0;j<4;j++)
		{
			if(a[i][j]==0) //当有空位时 k++ 
				k++;	
		}
	} 
	return k; //返回空位数k 
} 
//生成一个随机数 百分之30几率出现4 百分之70出现2 
void suijishu()
{
	srand(time(NULL));	//随机数种子  
	if(x==0||count()==0) return; //当没有空位 或者 无效移动则不长生新得睡觉数 
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
//是否游戏结束 结束则返回1 进入结束 否则返回0不进入 
int over()	
{
	for(int i=0;i<4;i++)//遍历 
	{
		for(int j=0;j<4;j++)
		{
			if(a[i][j]==0)		// 当前为0则还可以移动 
			return 0;
			if( (j<3&&a[i][j]==a[i][j+1]) ||  
			(j>0&&a[i][j]==a[i][j-1]) ||
			(i>0&&a[i][j]==a[i-1][j]) || 
			(i<3&&a[i][j]==a[i+1][j])  )
			return 0;//当前上下左右 有相同的数则说明 还可以移动 
		}
	}
	return 1;//其他情况说明进入结束 
}
//上 
void up()
{
	for(int i=0;i<4;i++)	//分列看 
	{
		for(int j=1;j<4;j++)	//每列从第2个数开始 
		{
			if(a[j][i])	//当前数为0则下一个 不为零则进入下面判断 
			{
				int t=-1;	//标记位t至 -1（0 1 2 以外的数都可以） 
				for(int k=j-1;k>=0&& ( a[j][i]==a[k][i] || a[k][i]==0 );k-- )
				//k为当前位的前一位  不能出界且 遇到0 或者相同数 就记录 k值 
				{
					t=k;
				}
				if(t!=-1)	//k被修改则说明可以叠加 
				{
					if(a[t][i]!=0)	//如果不是加0上面 则分数增加 
						s+=a[t][i]*2;
					a[t][i]+=a[j][i];//把后面数加到前面 
					a[j][i]=0;//后面数置0 
					x=1;	//标记位x至1 证明有效移动 可以产生新的随机数 
				}
			}		
		}	
	} 
}
//下 
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
//左 
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
//右 
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
		//刷新屏幕 
		system("cls"); 
		//生成随机数
		suijishu(); 
		//显示棋盘 
		xianshi();
		// 判断是否结束
		if(over())	//游戏失败 则进入结束 
		{
			printf("游戏结束 得分：%d\n",s); 
			while(1); //return 0;  若写return 0点太快会直接关闭   
		} 
		x=0;	//修改x置0 
		//移动 
		switch(getch()+getch()) //Windows下上下左右要获取两次 
		{
			case 296:up();break;	
			case 304:down();break;
			case 299:left();break;
			case 301:right();break;
		}
	}
}
