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
  printf("\n\n\n\n\n\t\t\t��ӭʹ�÷�װ���۹���ϵͳ\n");
  printf("\t\t\t���س�������......");
  getchar();
  system("cls"); 
 flag: printf("\n\n\n\n\n\t\t\t\t�û���¼��ע�ᴰ��\n");
 printf("\t\t\t\t��ѡ��\n");
  printf("\t\t\t\t1.��¼�˺�\n");
  printf("\t\t\t\t2.ע���˺�\n\t\t\t\t");
  scanf("%d",&k);
  system("cls"); 
  while(k!=1&&k!=2)//������Ч���������룡 
  {
  printf("\n\n\n\n\n\t\t\t\t��Ч���룡");
  sleep(1);
  system("cls");
  goto flag;
  }
  if(k==2)//ע���˺š� 
  {
  	fp=fopen("c:\\pw.txt","rb");
  	if(fp!=NULL)//ע�������˺� 
  	{
  		fp=fopen("c:\\pwg.txt","ab");
  		printf("\n\n\n\n\n\t\t\t\tע�������˺�\n\t\t\t\t");
  		printf("Guest\n\t\t\t\t");
  		fflush(stdin);
  		printf("\n\t\t\t\t�û�����");
  		gets(guest);
  		fprintf(fp,"%s ",guest);
  		printf("\n\t\t\t\t���룺");
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
  		mark:printf("\n\n\n\n\n\t\t\t\t��ѡ��\n");
  		printf("\t\t\t\t1.ע�����Ա�˺�\n");
		printf("\t\t\t\t2.ע�������˺�\n\t\t\t\t");
		scanf("%d",&j);
		while(j!=1&&j!=2)
		{
			printf("\t\t\t\t��Ч����\n");
			sleep(1);
			system("cls");
			goto mark;
		}
		if(j==1)//ע�����Ա�˺š� 
		{
			system("cls");
			fp=fopen("c:\\pw.txt","wb");
			printf("\n\n\n\n\n\t\t\t\tAdministrator\n");
			printf("\t\t\t\t�û�����");
			fflush(stdin);
			gets(administrator);
			fprintf(fp,"%s ",administrator);
			printf("\n\t\t\t\t���룺");
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
  if(k==1)//��¼�˺š� 
  {
  	up:printf("\n\n\n\n\n\t\t\t\t��ѡ��\n");
  	printf("\t\t\t\t1.��¼����Ա�˺�\n");
	printf("\t\t\t\t2.��¼�����˺�\n\t\t\t\t");
	scanf("%d",&m);
	while(m!=1&&m!=2)
	{
		printf("\n\t\t\t\t��Ч���룡");
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
		printf("\n\n\n\n\n\t\t\t\tAdministrator");//��¼����Ա�˺š� 
		printf("\n\t\t\t\t�û�����");
		gets(a);
		printf("\n\t\t\t\t���룺");
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
		      printf("\n\n\t\t\t\t��½�ɹ���");
		      sleep(1);
		      system("cls");
		      n=1;
		      break;
		    }
	    }
	    fclose(fp);
	    if(n==0)
	    {
	      printf("\n\n\t\t\t\t�û������������"); 
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
		printf("\n\n\n\n\n\t\t\t\tGuest");//��¼�����˺š� 
		printf("\n\t\t\t\t�û�����");
		gets(a);
		printf("\n\t\t\t\t���룺");
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
		      printf("\n\n\t\t\t\t��½�ɹ���");
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
	      printf("\n\n\t\t\t\t�û������������"); 
	      sleep(1);
	      system("cls");
	      goto flaga;
        }
    }	
}
fp=fopen("c:\\cloth.txt","rb");
if(fp==NULL||fgetc(fp)==EOF)
{
  printf("��¼���װ��Ϣ��\n");
  h=input();
  save_file(h);
  sleep(1);
  system("cls");
}
  loop:printf("\n\n\n\t\t\t\t��װ���۹���ϵͳ\n");
  printf("\t\t\t\t1.��ӷ�װ��Ϣ\n");
  printf("\t\t\t\t2.ɾ����װ��Ϣ\n");
  printf("\t\t\t\t3.�޸ķ�װ��Ϣ\n");
  printf("\t\t\t\t4.���ҷ�װ��Ϣ\n");
  printf("\t\t\t\t5.��ʾ��װ��Ϣ\n");
  printf("\t\t\t\t6.��ʾͳ����Ϣ\n");
  printf("\t\t\t\t0.�˳�����\n"); 
  printf("\t\t\t��ѡ����Ҫ���еĲ���:"); 
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
	case 1://��ӷ�װ��Ϣ�� 
	   {
	   	   sleep(1);
		   system("cls"); 
		   p=read_file();
		   innode(p);
		   resave_file(p);
		   printf("\n\t\t\t���س���������һ���˵���");
		   getchar();
		   system("cls");
		   goto loop;
	   };break;
	case 2://ɾ����װ��Ϣ�� 
	   {
	   	   sleep(1);
		   system("cls"); 
	   	   p=read_file();
		   denode(p);
		   resave_file(p);
		   printf("\n\t\t\t���س���������һ���˵���");
		   getchar();
		   system("cls");
		   goto loop;
	   };break;
	case 3://�޸ķ�װ��Ϣ
	   {
	   	   sleep(1);
		   system("cls"); 
	   	   p=read_file();
		   modify(p);
		   resave_file(p);
		   printf("\n\t\t\t���س���������һ���˵���");
		   getchar();
		   system("cls");
		   goto loop;
	   };break;
	case 4://���ҷ�װ��Ϣ
	   {
	   	   sleep(1);
		   system("cls"); 
	   	   p=read_file();
		   search(p);
		   printf("\n\t\t\t���س���������һ���˵���");
		   getchar();
		   system("cls");
		   goto loop;
	   };break;
	case 5://��ʾ��װ��Ϣ
	   {
	   	   sleep(1);
		   system("cls"); 
		   p=read_file();
		   sleep(1);
		   system("cls");
		   print(p); 
		   printf("\n\t\t\t���س���������һ���˵���");
		   fflush(stdin);
		   getchar();
		   system("cls");
		   goto loop;
	   };break;
	case 6://��ʾͳ����Ϣ
	   {
	   	   sleep(1);
		   system("cls"); 
		   p=read_file();
		   printf("\n\n\n\t\t\t\t��ѡ��1������2������:");
		   scanf("%d",&i);
		   if(i==1) 
		   q=rorder(p);
		   else if(i==2)
		   q=dorder(p);
		   else
		   printf("\n\t\t\t\t��Ч���룡");
		   sleep(1);
		   system("cls");
		   statis(q);
		   printf("\n\t\t\t���س���������һ���˵���");
		   fflush(stdin);
		   getchar();
		   system("cls");
		   goto loop;
	    };break;
	}
  }
  else 
  {
  	printf("\n\t\t\t\t��Ч���룡");
  	sleep(1);
  	system("cls");
  	goto loop;
  }
}
 flagb: fp=fopen("c:\\cloth.txt","rb");
if(fp==NULL||fgetc(fp)==EOF)
{
  printf("\n\n\n\t\t\t\t�޿ɷ�����Ϣ��");
  return 0;
}
  printf("\n\n\n\t\t\t\t1.���ҷ�װ��Ϣ\n");
  printf("\t\t\t\t2.��ʾ��װ��Ϣ\n");
  printf("\t\t\t\t3.��ʾͳ����Ϣ\n");
  printf("\t\t\t\t0.�˳�����\n"); 
  printf("\t\t\t��ѡ����Ҫ���еĲ���:");  
  scanf("%d",&i);
  while(i)
{
	fflush(stdin);
	if(i==1||i==2||i==3)
	{
    switch(i)
    {
	case 1://���ҷ�װ��Ϣ
	   {
	   	   sleep(1);
		   system("cls"); 
	   	   p=read_file();
		   search(p);
		   printf("\n\t\t\t���س���������һ���˵���");
		   getchar();
		   system("cls");
		   goto flagb;
	   };break;
	case 2://��ʾ��װ��Ϣ
	   {
	   	   sleep(1);
		   system("cls"); 
		   p=read_file();
		   printf("\n\n\n\t\t\t\t��ѡ��1������2������:");
		   scanf("%d",&i);
		   if(i==1) 
		   q=rorder(p);
		   else if(i==2)
		   q=dorder(p);
		   else
		   printf("\n\t\t\t\t��Ч���룡");
		   sleep(1);
		   system("cls");
		   print(q);
		   printf("\n\t\t\t���س���������һ���˵���");
		   fflush(stdin);
		   getchar();
		   system("cls");
		   goto flagb;
	   };break;
	case 3://��ʾͳ����Ϣ
	   {
	   	   sleep(1);
		   system("cls"); 
		   p=read_file();
		   printf("\n\n\n\t\t\t\t��ѡ��1������2������:");
		   scanf("%d",&i);
		   if(i==1) 
		   q=rorder(p);
		   else if(i==2)
		   q=dorder(p);
		   else
		   printf("\n\t\t\t\t��Ч���룡");
		   sleep(1);
		   system("cls");
		   statis(q);
		   printf("\n\t\t\t���س���������һ���˵���");
		   fflush(stdin);
		   getchar();
		   system("cls");
		   goto flagb;
	    };break;
	}
	}
	else 
	{
		printf("\n\t\t\t\t��Ч���룡");
		sleep(1);
		system("cls");
		goto flagb;
	}
  }
}


