#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct cloth/*��װ��Ϣ�ṹ��*/ 
{
	char kindname[10];
	char purchasedate[10];
	char itemnumber[10];
	char status[5];
	char originalprice[10];
	char salesprice[10];
	char size[10];
	char color[10];
	struct cloth *next,*prev;
}node,*linklist;
typedef struct count/*��װͳ�ƽṹ��*/ 
{
  	    char name[10];
  	    int solded;
  	    int unsolded;
		int data;
		int sumprice;
		struct count *next;
}count;
linklist input()//¼���װ��Ϣ�� 
{
	linklist h;
	node *p,*r;
	char arr[10];
	r=h=(node*)malloc(sizeof(node));
	p=(node*)malloc(sizeof(node));
	printf("�������·���������(��q����):");
	gets(p->kindname);
	while(strcmp(p->kindname,"q")!=0)
	{
		printf("�������·���ţ�");
		gets(p->itemnumber);
	    printf("������������ڣ�");
	    gets(p->purchasedate);
	    printf("���������(Ԫ)��");
	    gets(p->originalprice);
		printf("�������ۼۣ�");
		gets(p->salesprice);
		printf("�������·�״̬������1/δ��0����");
		gets(p->status);
		while(strcmp(p->status,"1")!=0&&strcmp(p->status,"0")!=0)/*������벻������ѡ���������*/ 
		{
			printf("���������룺");
			gets(p->status);
		}
		printf("����������С�����ף���");
		gets(p->size);
		printf("��������ɫ��");
		gets(p->color);
		r->next=p;
		p->prev=r;
		r=p;
		p=(node*)malloc(sizeof(node));
		printf("�������·���������(��q����):");
	    gets(p->kindname);
	    fflush(stdin);
	}
	free(p);
	r->next=NULL;
	return h; 
}
void exchange( node * p, node * min )  /*�����ڵ㺯��*/ 
{  
    node *min_prev;
    node *p_next;
    if(p==min)  
        return;  
    //p��min����Ҫ��6��ָ�룬�����ڸ�8��ָ��  
    if( min!= p->next )  
    {  
        p->next->prev = min;  
        min->prev->next = p;  
    }  
    p->prev->next = min;  
    if( min->next != NULL)  
        min->next->prev= p;  
  
    min_prev = min->prev;  
    p_next = p->next;  
    min->prev = p->prev;  
    p->next = min->next;  
  
    if( min == p_next ) //p��min����  
    {  
        min->next = p;  
        p->prev = min;  
    }  
    else  
    {  
        min->next = p_next;  
        p->prev = min_prev;  
    }  
} 
node *rorder(node *head)  //������ 
{  
     node *p=head->next;
     node *min ;
     node *s;
    //ѡ������ÿһ��ѡ����СԪ�ؽڵ�ĺ�p�ڵ㽻��  
    for(p; p->next!=NULL; p=p->next)  
    {  
        min = p; //��ʼ����С�ڵ�
		s=p->next;  
        for(s; s!=NULL; s=s->next)  
        {  
            //����СԪ�صĽڵ�  
            if( strcmp(min->kindname,s->kindname)>0 )  
                min = s;  
        }  
        exchange( p, min ); //���������ڵ�  
        p=min;//���������ڵ��p�䵽��min��λ�ã�Ϊ�˱������ѽڵ�p�������ƶ����ϴνڵ㴦����p = min;  
    }  
    return head;  
}  
node *dorder(node *head)  //������ 
{  
     node *p=head->next;
     node *min;
     node *s;
    //ѡ������ÿһ��ѡ����СԪ�ؽڵ�ĺ�p�ڵ㽻��  
    for(p; p->next!=NULL; p=p->next)  
    {  
        min = p; //��ʼ����С�ڵ�
		s=p->next;  
        for(s; s!=NULL; s=s->next)  
        {  
            //����СԪ�صĽڵ�  
            if( strcmp(min->kindname,s->kindname)<0 )  
                min = s;  
        }  
        exchange( p, min ); //���������ڵ�  
        p=min;//���������ڵ��p�䵽��min��λ�ã�Ϊ�˱������ѽڵ�p�������ƶ����ϴνڵ㴦����p = min;  
    }  
    return head;  
}  
void search(node *h)/*���Һ���*/ 
{
	node *p;
	int i,m=0;
	char infor[10];
	p=h->next;
	printf("��ѡ����м򵥲�ѯ1��/�ۺϲ�ѯ2����");
	scanf("%d",&i);
	fflush(stdin);
	while(i!=1&&i!=2)
	{
		printf("���������룺");
		scanf("%d",&i);
	 } 
	fflush(stdin);
	if(i==1)
    {
	printf("��������Ҫ��ѯ���·���Ϣ������/���/�������ڣ���");
	gets(infor);
	printf("��ѯ���Ϊ��\n");
	while(p!=NULL)
	  {
		if(strcmp(infor,p->kindname)==0||strcmp(infor,p->itemnumber)==0||strcmp(infor,p->purchasedate)==0)
		{
		   printf("�·��������ƣ�");
		printf("%s\n",p->kindname);
		printf("�·����:"); 
		printf("%s\n",p->itemnumber);
		printf("�������ڣ�");
	    printf("%s\n",p->purchasedate);
	    printf("�·�״̬��");
		if(strcmp(p->status,"0")==0)
		printf("δ�ۣ�");
		else
		printf("���ۣ�");
		printf("����(Ԫ)��");
		printf("%s\n",p->originalprice);
		printf("�ۼۣ�");
		printf("%s\n",p->salesprice);
		printf("�����С�����ף���");
		printf("%s\n",p->size);
		printf("��ɫ��");
	    printf("%s\n",p->color);
	    m=1;
		}
		p=p->next;
	  }
	  if(!m)
	  printf("��ƥ���\n");
    }
    else if(i==2)
    {
       printf("��������Ҫ��ѯ���·������ࡢ��š��������ڣ��Կո����֮����");
	   scanf("%s%s%s",p->kindname,p->itemnumber,p->purchasedate); 
	   printf("��ѯ���Ϊ��");
	   while(p!=NULL)
	  {
		if(strcmp(infor,p->kindname)==0&&strcmp(infor,p->itemnumber)==0&&strcmp(infor,p->purchasedate)==0)
		{
		 printf("�·��������ƣ�");
		 printf("%s\n",p->kindname);
		 printf("�·����:"); 
		 printf("%s\n",p->itemnumber);
		 printf("�������ڣ�");
	     printf("%s\n",p->purchasedate);
	     printf("�·�״̬��");
		 if(strcmp(p->status,"0")==0)
		 printf("δ�ۣ�");
		 else
		 printf("���ۣ�");
		 printf("\n����(Ԫ)��");
		 printf("%s\n",p->originalprice);
		 printf("�ۼۣ�");
		 printf("%c\n",p->salesprice);
		 printf("�����С(����)��");
		 printf("%s\n",p->size);
		 printf("��ɫ��");
	     printf("%s\n",p->color);
		}
		m=1; 
		p=p->next;
	  }
	  if(!m)
	  printf("��ƥ���\n");
	}
	else 
	printf("��Ч���룡");
}
void print(node *h)
{
    node *p,*r;
	p=h->next;
	printf("�·����� ");
	printf("�·���� ");
	printf("�������� ");
	printf("�·�״̬ ");
	printf("����(Ԫ) ");
	printf("�ۼ�(Ԫ) ");
	printf("�����С�����ף� ");
	printf("��ɫ\n");
	while(p!=NULL)
	{
		printf("%s\t  ",p->kindname);
		printf("%s   ",p->itemnumber);
	    printf("  %s  ",p->purchasedate);
		if(strcmp(p->status,"0")==0)
		printf("δ��!\t");
		else
		printf("����!\t");
		printf("%s\t",p->originalprice);
		printf("%s\t   ",p->salesprice);
		printf("%s\t\t",p->size);
	    printf("%s\n",p->color);
		p=p->next;
	}	
}
void innode(linklist q)//��ӷ�װ��Ϣ�����䱣�浽�ļ��С� 
{
	node *p;
	char arr[10];
	int i,flag=0;
	q=q->next;
	p=(node*)malloc(sizeof(node));
	printf("\t\t�������·���������:");
	gets(p->kindname);
	printf("\n\t\t�������·���ţ�");
	gets(p->itemnumber);
	printf("\n\t\t������������ڣ�");
	gets(p->purchasedate);
    printf("\n\t\t���������(Ԫ)��");
	gets(p->originalprice);
	printf("\n\t\t�������ۼۣ�");
	gets(p->salesprice);
	printf("\n\t\t�������·�״̬��δ��0/����1����");
	gets(p->status);
		while(strcmp(p->status,"1")!=0&&strcmp(p->status,"0")!=0)/*������벻������ѡ���������*/ 
		{
			printf("\n\t\t\t\t���������룺");
			gets(p->status);
		}
	printf("\n\t\t����������С�����ף���");
	gets(p->size);
	printf("\n\t\t��������ɫ��");
	gets(p->color);
    printf("��ѡ�����ĳ�·�λ��֮ǰ1����֮��2����");
    scanf("%d",&i);
    fflush(stdin);
    if(i==2)
    {
     printf("\n��������·��ı�ţ�");
     gets(arr);	
     while(q!=NULL)
     {
    	if(strcmp(q->itemnumber,arr)==0)
    	{
    		if(q->next==NULL)
    		{
    			q->next=p;
    			p->prev=q;
    			p->next=NULL;
			}
			else
			{
				p->next=q->next;
				q->next->prev=p;
				p->prev=q;
				q->next=p;
			}
			flag=1;
		}
		q=q->next;
	  }
   }
    else if(i==1)
    {
    	printf("\n��������·��ı�ţ�");
        gets(arr);	
	   while(q!=NULL)
       {
    	 if(strcmp(q->itemnumber,arr)==0)
    	 {
    	 	p->next=q;
    	 	p->prev=q->prev;
    	 	q->prev->next=p;
    	 	q->prev=p;
    	 	flag=1;
		 }
		 q=q->next;
	   }
    }
else
printf("\n\n\n\t\t\t\t��Ч���룡");
if(flag==0)
printf("��ƥ���"); 
}
void denode(node *h)
{
	node *p,*r;
	char number[10];
	p=h->next;
	r=h;
	printf("\n\n\n\n\n\t\t\t\t��������Ҫɾ�����·���ţ�");
	gets(number);
	while(p!=NULL)
	{
		if(strcmp(p->itemnumber,number)==0)
		{
			if(p->next==NULL)
			{
				p->prev->next=NULL;
				free(p);
				break;
			}
		     p->prev->next=p->next;
		     p->next->prev=p->prev;
		     free(p);
	         break;
	    }
	    p=p->next;
	}
	if(p==NULL)
	printf("\t\t\t\t��ƥ���");
}
void modify(node *h)//�޸ķ�װ��Ϣ�� 
{
	node *p;
	int i=0;
	char name[10];
	char number[10]; 
	p=h->next;
	printf("��������Ҫ�޸ĵ��·�����Ϣ���������ơ����,�Կո��������");
	scanf("%s",name);
	scanf("%s",number);
	while(p!=NULL)
	{
		if(strcmp(p->kindname,name)==0&&strcmp(p->itemnumber,number)==0)
		{ 
		  printf("�������޸ĺ����Ϣ��");
		  printf("�������·����ࣺ");
	      scanf("%s",p->kindname);
	      getchar();
	      printf("\n������������ڣ�");
	      gets(p->purchasedate);
	      printf("\n��������������");
	      gets(p->originalprice);
	      printf("\n���������(Ԫ)��");
	      gets(p->originalprice);
	      printf("\n�������ۼۣ�");
	      gets(p->salesprice);
	      printf("\n�������·�״̬������1/δ��0����");
	      gets(p->status);
		while(strcmp(p->status,"1")!=0&&strcmp(p->status,"0")!=0)/*������벻������ѡ���������*/ 
		{
			printf("���������룺");
			gets(p->status);
		}
	      printf("\n����������С�����ף���");
	      gets(p->size);
	      printf("\n��������ɫ��");
	      gets(p->color);
	      i=1;
		  break; 
		}
	    p=p->next;	
	}
	if(i==0)
	printf("���·������ڣ�");
}
linklist read_file()//��ȡ������ļ��� 
{
   FILE *fp;
   linklist p,r,head;
   r=head=(node*)malloc(sizeof(node));
   fp=fopen("c:\\cloth.txt","rb");
   if(fp==NULL)
   {
	   printf("file not exist");
	   return 0;
   }
   while(feof(fp)==0)
   {
	   p=(node*)malloc(sizeof(node));
	   r->next=p;
	   p->prev=r;
	   r=p;
	   fscanf(fp,"%s ",p->kindname);
	   fscanf(fp,"%s ",p->itemnumber);
	   fscanf(fp,"%s ",p->purchasedate);
	   fscanf(fp,"%s ",p->originalprice);
	   fscanf(fp,"%s ",p->salesprice);
	   fscanf(fp,"%s ",p->status);
	   fscanf(fp,"%s ",p->size);
	   fscanf(fp,"%s ",p->color);
   }
   p->next=NULL;
   fclose(fp);
   return head;
}
void save_file(linklist h)//�����ļ��� 
{
	FILE *fp;
	linklist p;
	p=h->next;
	if((fp=fopen("C:\\cloth.txt","ab"))==NULL)
	{
		printf("error");
		return;
	}
	while(p!=NULL)
	{
	   fprintf(fp,"%s ",p->kindname);
	   fprintf(fp,"%s ",p->itemnumber);
	   fprintf(fp,"%s ",p->purchasedate);
	   fprintf(fp,"%s ",p->originalprice);
	   fprintf(fp,"%s ",p->salesprice);
	   fprintf(fp,"%s ",p->status);
	   fprintf(fp,"%s ",p->size);
	   fprintf(fp,"%s ",p->color);
	   p=p->next;
	}
	fclose(fp);
}
void resave_file(linklist h)//���±����ļ� 
{
	FILE *fp;
	linklist p;
	p=h->next;
	if((fp=fopen("C:\\cloth.txt","wb"))==NULL)
	{
		printf("error");
		return;
	}
	while(p!=NULL)
	{
	   fprintf(fp,"%s ",p->kindname);
	   fprintf(fp,"%s ",p->itemnumber);
	   fprintf(fp,"%s ",p->purchasedate);
	   fprintf(fp,"%s ",p->originalprice);
	   fprintf(fp,"%s ",p->salesprice);
	   fprintf(fp,"%s ",p->status);
	   fprintf(fp,"%s ",p->size);
	   fprintf(fp,"%s ",p->color);
	   p=p->next;
	}
	fclose(fp);
}
void statis(linklist p)//�Է�װ��Ϣ��ͳ�ơ� 
{
	count *q,*r,*head;
	int sum=0;
	p=p->next;
	head=r=q=(count*)malloc(sizeof(count));
	q->data=1;
	q->solded=0;
	q->sumprice=0;
	while(p->next!=NULL)
	{
		if(strcmp(p->status,"1")==0)/*ͳ��������*/ 
		{
		 q->solded++;
		 q->sumprice+=atoi(p->salesprice)-atoi(p->originalprice);
	    }
		if(strcmp(p->kindname,p->next->kindname)==0)
		{
			q->data++;
		}
		else 
		{
			strcpy(q->name,p->kindname);
			if(strcmp(p->status,"1")==0)
			q->sumprice+=atoi(p->salesprice)-atoi(p->originalprice);
			q=(count*)malloc(sizeof(count));
			q->solded=0;
			q->data=1;
			q->sumprice=0;
			r->next=q;
			r=q;
		}
		p=p->next;
	}
	//�жϲ�ͳ�����һ���ڵ��״̬
	if(strcmp(p->prev->kindname,p->kindname)!=0)
	{ 
    strcpy(q->name,p->kindname);
    if(strcmp(p->status,"1")==0)
    {
    q->solded++;
    q->sumprice+=atoi(p->salesprice)-atoi(p->originalprice);
    }
    }
    else
    {
    	if(strcmp(p->status,"1")==0)
    	{
    	q->solded++;
    	q->sumprice+=atoi(p->salesprice)-atoi(p->originalprice);
        }
	}
    r->next=NULL;
    q=head;
    printf("�·�����\t");
    printf("������\t");
    printf("�����\t");
	printf("����Ԫ��\n");
    while(q!=NULL)
    {
	  printf("%s\t\t",q->name);
	  printf("%d\t",q->solded);
	  printf("%d\t",q->data-q->solded);
	  printf("%d\n",q->sumprice);
	  q=q->next;
    }
}





