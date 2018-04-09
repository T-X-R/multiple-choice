#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX_LINE 1024


struct answer
{
char Ans;
char mark[10];
char explain[1000];
}A[15];

/*typedef struct The_users
{
    char id[10];
    char pwd[20];
}users;

void Create_File()
{
    FILE *fp;
    if ((fp = fopen("users.txt","rb"))==NULL)
    {
        if ((fp = fopen("users.txt","wb+"))==NULL)
        {
            printf("无法建立文件!");
        }
    }
}

void registers()  //按结构体的大小，一次写入或者读入1个结构体大小
{
    users a,b;//结构体 The_users 重命名定义
    FILE *fp;
    fp = fopen("users.txt","r");
    fread(&b, sizeof(struct The_users),1,fp); //读入一个结构体字符块 到b

    printf("\t\t--------------------------------------\n");
 printf("\t\t|      请输入用户名(<=10个字符)      |\n");
 printf("\t\t--------------------------------------\n");
 printf("\t\t                  ");
    char c;
 for(int x=0;;x++)
 {
  fprintf(fp,"%s",a.id[x]);
  if(c=='\n')
   break;
    }

    while (1)
    {
        if (strcmp(a.id, b.id)!=0)
        {
            if (!feof(fp))
            {
                fread(&b, sizeof(struct The_users), 1, fp);
            }
            else break;
        }
        else
  {
   printf("\t\t                  ");
            printf("此用户名已存在!");
            fclose(fp);
   break;
        }
    }

 printf("\t\t--------------------------------------\n");
 printf("\t\t|       请输入密码(<=20个字符)       |\n");
 printf("\t\t--------------------------------------\n");
 fprintf(fp,"%s",a.pwd);

    fp = fopen("users.txt","a");
    fwrite(&a, sizeof(struct The_users),1,fp);

    printf("\t\t--------------------------------------\n");
 printf("\t\t|             注册成功！             |\n");
 printf("\t\t--------------------------------------\n");

    fclose(fp);
}

void  Input_login()
{
    users a,b;//定义结构体The_users别名
    FILE *fp;
    fp = fopen("users.txt","r");
    fread(&b, sizeof(struct The_users),1,fp); //读入一个结构体字符块 写入b

    printf("\t\t--------------------------------------\n");
 printf("\t\t|            请输入用户名            |\n");
 printf("\t\t--------------------------------------\n");
    fprintf(fp,"%s",a.id);
    while (1)
    {
     if(strcmp(a.id, b.id)==0)         //如果有此用户名
      break;
        else
        {
            if (!feof(fp))  //如果文件没有读完
            {
                fread(&b, sizeof(struct The_users), 1, fp);
            }
            else
            {
                printf("\t\t                  ");
       printf("此用户名不存在!");
                fclose(fp);
        }
        }
    }

    printf("\t\t--------------------------------------\n");
 printf("\t\t|             请输入密码             |\n");
 printf("\t\t--------------------------------------\n");
    fprintf(fp,"%s",a.pwd);
    if (strcmp(a.pwd, b.pwd)==0)
    {
        fclose(fp);
   printf("\t\t--------------------------------------\n");
     printf("\t\t|         登录成功,欢迎使用!         |\n");
     printf("\t\t--------------------------------------\n");
    }
    else
    {
     printf("\t\t                  ");
  printf("密码不正确!");
    }
}*/

void Menu()
{
 printf("\n\n\n\n\n");
  printf("\t\t--------------------------------------\n");
 printf("\t\t|           选择试题类型：           |\n");
  printf("\t\t|                                    |\n");
  printf("\t\t|            1.数据结构              |\n");
  printf("\t\t|                                    |\n");
  printf("\t\t|            2.c/c++                 |\n");
  printf("\t\t|                                    |\n");
  printf("\t\t|            3.退出考试              |\n");
  printf("\t\t|                                    |\n");
  printf("\t\t--------------------------------------\n");
}


int main()
{
 /*while(1)
 {
  printf("\n\n\n\n\n");
  printf("\t\t--------------------------------------\n");
  printf("\t\t|       欢迎来到单选题考试系统       |\n");
  printf("\t\t|                                    |\n");
  printf("\t\t|            1.注册账号              |\n");
  printf("\t\t|                                    |\n");
  printf("\t\t|            2.登录                  |\n");
  printf("\t\t|                                    |\n");
  printf("\t\t--------------------------------------\n");

  int k;
  printf("\t\t                  ");
  scanf("%d",&k);

  if(k==1)
  {
   registers();
  }
  if(k==2)
  {
   Input_login();
   break;
  }
 }*/

 while(1)
 {
  Menu();
  printf("\t\t--------------------------------------\n");
  printf("\t\t|           请输入您的选项           |\n");
  printf("\t\t--------------------------------------\n");
  int op;
  printf("\t\t--------------------------------------\n");
  printf("\t\t                  ");
  scanf("%d",&op);
  printf("\n");

  if(op==1)
  {
   char buf1[MAX_LINE];
   char *p;
   char buf2[MAX_LINE];
   int len1;
   int len2;
   FILE *fp1=fopen("question.txt","r");
   FILE *fp2=fopen("answer.txt","r");
   if(fp1==NULL||fp2==NULL)
   {
    printf("文件打开失败！");
   }

   printf("单项选择题（每道题5分，多选错选均不得分，共有15道题，8道简单题，4道普通题，3道难题）:\n\n");

   while(1)
   {
    p=fgets(buf1,MAX_LINE,fp1);
    if(!p) break;
    printf("%s",buf1);
   }

   /*for(int j=0;j<k;j++)
   {
   printf("%s\n",timu[j]);
   }*/

   int i=0;
   while(fgets(buf2,MAX_LINE,fp2)!=NULL)
   {
    len2=strlen(buf2);
    buf2[len2-1]='\0';
    fscanf(fp2,"%c%s%s",&A[i].Ans,A[i].mark,A[i].explain);
    i++;
   }

   /*for(int j=0;j<15;j++)
   printf("%s\n",A[j].mark);*/

   fclose(fp1);
   fclose(fp2);

   char choose[15];

   printf("请输入您的选项：\n\n");

   for(int j=0;j<15;j++)
   {
    scanf("%c",&choose[j]);
   }

   /*for(int j=0;j<15;j++)
   {
    printf("%c ",choose[j]);
   }*/

   int easy=0;
   int normal=0;
   int hard=0;
   int score=0;

   for(int j=0;j<15;j++)
   {
    if(choose[j]==A[j].Ans)
    {
     score=score+5;
     if(strcmp(A[j].mark,"easy")) easy++;
     else if(strcmp(A[j].mark,"normal")) normal++;
     else if(strcmp(A[j].mark,"hard")) hard++;
    }
    else if(choose[j]!=A[j].Ans)
    {
     printf("\n第%d题、您的选项为：%c 正确选项为：%c\n解析：%s\n",j+1,choose[j],A[j].Ans,A[j].explain);
    }
   }
   printf("\n");
   printf("您的成绩是：%d分\n",score);
   printf("您的正确率为：%.2lf%%\n",score/75.0*100);
   printf("您的简单题正确率为：%.2lf%%\n",double(easy)/8.0*100);
   printf("您的普通题正确率为：%.2lf%%\n",double(normal)/4*100);
   printf("您的难题正确率为：%.2lf%%\n",double(hard)/3*100);
   break;
  }

  /*if(op==2)
  {

  }*/

  if(op==3)
  {
   printf("\t\t--------------------------------------\n");
   printf("\t\t|             已退出考试             |\n");
   printf("\t\t--------------------------------------\n");
   break;
  }

  if(op<=0||op>3)
  {
   printf("\t\t--------------------------------------\n");
   printf("\t\t|       输入错误！请重新输入！       |\n");
   printf("\t\t--------------------------------------\n");
  }
 }
}
