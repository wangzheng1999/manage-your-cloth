#include"cloth.h"
#include<windows.h>
#include<conio.h>
int main()
{
  linklist h,p,q;
  int i,k,j,m,n=0;
  FILE *fp;
  char ch;
  char a[20],b[20];
  char administrator[20];
  char code[20];
  char guest[20];
  char codes[20];
  printf("\n\n\n\n\n\t\t\t欢迎使用服装销售管理系统\n");
  printf("\t\t\t按回车键继续......");
  getchar();
  system("cls"); 
 flag: printf("\n\n\n\n\n\t\t\t\t用户登录及注册窗口\n");
 printf("\t\t\t\t请选择\n");
  printf("\t\t\t\t1.登录账号\n");
  printf("\t\t\t\t2.注册账号\n\t\t\t\t");
  scanf("%d",&k);
  system("cls"); 
  while(k!=1&&k!=2)//输入无效，重新输入！ 
  {
  printf("\n\n\n\n\n\t\t\t\t无效输入！");
  sleep(1);
  system("cls");
  goto flag;
  }
  if(k==2)//注册账号。 
  {
  	fp=fopen("c:\\pw.txt","rb");
  	if(fp!=NULL)//注册来宾账号 
  	{
  		fp=fopen("c:\\pwg.txt","ab");
  		printf("\n\n\n\n\n\t\t\t\t注册来宾账号\n\t\t\t\t");
  		printf("Guest\n\t\t\t\t");
  		fflush(stdin);
  		printf("\n\t\t\t\t用户名：");
  		gets(guest);
  		fprintf(fp,"%s ",guest);
  		printf("\n\t\t\t\t密码：");
  		i=0;
  		while((ch=getch())!='\r')
		{
			printf("*");
			codes[i]=ch;
			i++;
		}
  		fprintf(fp,"%s ",codes);
  		fclose(fp);
  		sleep(1);
  		system("cls");
  		goto up;
	  }
  	if(fp==NULL)
  	{
  		mark:printf("\n\n\n\n\n\t\t\t\t请选择\n");
  		printf("\t\t\t\t1.注册管理员账号\n");
		printf("\t\t\t\t2.注册来宾账号\n\t\t\t\t");
		scanf("%d",&j);
		while(j!=1&&j!=2)
		{
			printf("\t\t\t\t无效输入\n");
			sleep(1);
			system("cls");
			goto mark;
		}
		if(j==1)//注册管理员账号。 
		{
			system("cls");
			fp=fopen("c:\\pw.txt","wb");
			printf("\n\n\n\n\n\t\t\t\tAdministrator\n");
			printf("\t\t\t\t用户名：");
			fflush(stdin);
			gets(administrator);
			fprintf(fp,"%s ",administrator);
			printf("\n\t\t\t\t密码：");
			i=0;
			while((ch=getch())!='\r')
		   {
			printf("*");
			code[i]=ch;
			i++;
		   }
			fprintf(fp,"%s ",code);
			fclose(fp);
			sleep(1);
			system("cls");
			goto up;
		}
	}
  }
  if(k==1)//登录账号。 
  {
  	up:printf("\n\n\n\n\n\t\t\t\t请选择\n");
  	printf("\t\t\t\t1.登录管理员账号\n");
	printf("\t\t\t\t2.登录来宾账号\n\t\t\t\t");
	scanf("%d",&m);
	while(m!=1&&m!=2)
	{
		printf("\n\t\t\t\t无效输入！");
		sleep(1);
		system("cls");
		goto up;
	}
	if(m==1)
	{
		flag1:fp=fopen("c:\\pw.txt","rb");
		system("cls");
		if(fp==NULL)
		{
			printf("\n\n\n\n\n\t\t\t\terror!");
			sleep(1);
			system("cls");
		    goto flag;
		}
		fflush(stdin);
		printf("\n\n\n\n\n\t\t\t\tAdministrator");//登录管理员账号。 
		printf("\n\t\t\t\t用户名：");
		gets(a);
		printf("\n\t\t\t\t密码：");
		i=0;
		fflush(stdin);
		while((ch=getch())!='\r')
		{
			printf("*");
			b[i]=ch;
			i++;
		}
		while(feof(fp)==0)
		{
			fscanf(fp,"%s ",administrator);
			fscanf(fp,"%s ",code);
			if(strcmp(administrator,a)==0&&strcmp(code,b)==0)
			{
		      printf("\n\n\t\t\t\t登陆成功！");
		      sleep(1);
		      system("cls");
		      n=1;
		      break;
		    }
	    }
	    fclose(fp);
	    if(n==0)
	    {
	      printf("\n\n\t\t\t\t用户名或密码错误！"); 
	      sleep(1);
	      system("cls");
	      goto flag1;
        }
    }
    if(m==2)
    {
		flaga:fp=fopen("c:\\pwg.txt","rb");
		if(fp==NULL)
		{
			printf("\n\n\n\n\n\t\t\t\terror!");
			sleep(1);
			system("cls");
		    goto flag;
		}
		system("cls");
		fflush(stdin);
		printf("\n\n\n\n\n\t\t\t\tGuest");//登录来宾账号。 
		printf("\n\t\t\t\t用户名：");
		gets(a);
		printf("\n\t\t\t\t密码：");
		i=0;
		while((ch=getch())!='\r')
		{
			printf("*");
			b[i]=ch;
			i++;
		}
		while(feof(fp)==0)
		{
			fscanf(fp,"%s ",guest);
			fscanf(fp,"%s ",codes);
			if(strcmp(guest,a)==0&&strcmp(codes,b)==0)
			{
		      printf("\n\n\t\t\t\t登陆成功！");
		      sleep(1);
		      system("cls");
		      n=1;
		      sleep(1);
		      system("cls");
		      goto flagb;
		      break;
		    }
	    }
	    fclose(fp);
	    if(n==0)
	    {
	      printf("\n\n\t\t\t\t用户名或密码错误！"); 
	      sleep(1);
	      system("cls");
	      goto flaga;
        }
    }	
}
fp=fopen("c:\\cloth.txt","rb");
if(fp==NULL||fgetc(fp)==EOF)
{
  printf("请录入服装信息：\n");
  h=input();
  save_file(h);
  sleep(1);
  system("cls");
}
  loop:printf("\n\n\n\t\t\t\t服装销售管理系统\n");
  printf("\t\t\t\t1.添加服装信息\n");
  printf("\t\t\t\t2.删除服装信息\n");
  printf("\t\t\t\t3.修改服装信息\n");
  printf("\t\t\t\t4.查找服装信息\n");
  printf("\t\t\t\t5.显示服装信息\n");
  printf("\t\t\t\t6.显示统计信息\n");
  printf("\t\t\t\t0.退出程序\n"); 
  printf("\t\t\t请选择所要进行的操作:"); 
  scanf("%d",&i);
  fflush(stdin);
  if(i==0)
  return 0;
  while(i)
  {
    if(i==0||i==1||i==2||i==3||i==4||i==5||i==6)
    {
    switch(i)
    { 
	case 1://添加服装信息。 
	   {
	   	   sleep(1);
		   system("cls"); 
		   p=read_file();
		   innode(p);
		   resave_file(p);
		   printf("\n\t\t\t按回车键返回上一级菜单！");
		   getchar();
		   system("cls");
		   goto loop;
	   };break;
	case 2://删除服装信息。 
	   {
	   	   sleep(1);
		   system("cls"); 
	   	   p=read_file();
		   denode(p);
		   resave_file(p);
		   printf("\n\t\t\t按回车键返回上一级菜单！");
		   getchar();
		   system("cls");
		   goto loop;
	   };break;
	case 3://修改服装信息
	   {
	   	   sleep(1);
		   system("cls"); 
	   	   p=read_file();
		   modify(p);
		   resave_file(p);
		   printf("\n\t\t\t按回车键返回上一级菜单！");
		   getchar();
		   system("cls");
		   goto loop;
	   };break;
	case 4://查找服装信息
	   {
	   	   sleep(1);
		   system("cls"); 
	   	   p=read_file();
		   search(p);
		   printf("\n\t\t\t按回车键返回上一级菜单！");
		   getchar();
		   system("cls");
		   goto loop;
	   };break;
	case 5://显示服装信息
	   {
	   	   sleep(1);
		   system("cls"); 
		   p=read_file();
		   sleep(1);
		   system("cls");
		   print(p); 
		   printf("\n\t\t\t按回车键返回上一级菜单！");
		   fflush(stdin);
		   getchar();
		   system("cls");
		   goto loop;
	   };break;
	case 6://显示统计信息
	   {
	   	   sleep(1);
		   system("cls"); 
		   p=read_file();
		   printf("\n\n\n\t\t\t\t请选择1）升序2）降序:");
		   scanf("%d",&i);
		   if(i==1) 
		   q=rorder(p);
		   else if(i==2)
		   q=dorder(p);
		   else
		   printf("\n\t\t\t\t无效输入！");
		   sleep(1);
		   system("cls");
		   statis(q);
		   printf("\n\t\t\t按回车键返回上一级菜单！");
		   fflush(stdin);
		   getchar();
		   system("cls");
		   goto loop;
	    };break;
	}
  }
  else 
  {
  	printf("\n\t\t\t\t无效输入！");
  	sleep(1);
  	system("cls");
  	goto loop;
  }
}
 flagb: fp=fopen("c:\\cloth.txt","rb");
if(fp==NULL||fgetc(fp)==EOF)
{
  printf("\n\n\n\t\t\t\t无可访问信息！");
  return 0;
}
  printf("\n\n\n\t\t\t\t1.查找服装信息\n");
  printf("\t\t\t\t2.显示服装信息\n");
  printf("\t\t\t\t3.显示统计信息\n");
  printf("\t\t\t\t0.退出程序\n"); 
  printf("\t\t\t请选择所要进行的操作:");  
  scanf("%d",&i);
  while(i)
{
	fflush(stdin);
	if(i==1||i==2||i==3)
	{
    switch(i)
    {
	case 1://查找服装信息
	   {
	   	   sleep(1);
		   system("cls"); 
	   	   p=read_file();
		   search(p);
		   printf("\n\t\t\t按回车键返回上一级菜单！");
		   getchar();
		   system("cls");
		   goto flagb;
	   };break;
	case 2://显示服装信息
	   {
	   	   sleep(1);
		   system("cls"); 
		   p=read_file();
		   printf("\n\n\n\t\t\t\t请选择1）升序2）降序:");
		   scanf("%d",&i);
		   if(i==1) 
		   q=rorder(p);
		   else if(i==2)
		   q=dorder(p);
		   else
		   printf("\n\t\t\t\t无效输入！");
		   sleep(1);
		   system("cls");
		   print(q);
		   printf("\n\t\t\t按回车键返回上一级菜单！");
		   fflush(stdin);
		   getchar();
		   system("cls");
		   goto flagb;
	   };break;
	case 3://显示统计信息
	   {
	   	   sleep(1);
		   system("cls"); 
		   p=read_file();
		   printf("\n\n\n\t\t\t\t请选择1）升序2）降序:");
		   scanf("%d",&i);
		   if(i==1) 
		   q=rorder(p);
		   else if(i==2)
		   q=dorder(p);
		   else
		   printf("\n\t\t\t\t无效输入！");
		   sleep(1);
		   system("cls");
		   statis(q);
		   printf("\n\t\t\t按回车键返回上一级菜单！");
		   fflush(stdin);
		   getchar();
		   system("cls");
		   goto flagb;
	    };break;
	}
	}
	else 
	{
		printf("\n\t\t\t\t无效输入！");
		sleep(1);
		system("cls");
		goto flagb;
	}
  }
}


