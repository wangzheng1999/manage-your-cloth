#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct cloth/*服装信息结构体*/ 
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
typedef struct count/*服装统计结构体*/ 
{
  	    char name[10];
  	    int solded;
  	    int unsolded;
		int data;
		int sumprice;
		struct count *next;
}count;
linklist input()//录入服装信息。 
{
	linklist h;
	node *p,*r;
	char arr[10];
	r=h=(node*)malloc(sizeof(node));
	p=(node*)malloc(sizeof(node));
	printf("请输入衣服种类名称(按q结束):");
	gets(p->kindname);
	while(strcmp(p->kindname,"q")!=0)
	{
		printf("请输入衣服编号：");
		gets(p->itemnumber);
	    printf("请输入进货日期：");
	    gets(p->purchasedate);
	    printf("请输入进价(元)：");
	    gets(p->originalprice);
		printf("请输入售价：");
		gets(p->salesprice);
		printf("请输入衣服状态（已售1/未售0）：");
		gets(p->status);
		while(strcmp(p->status,"1")!=0&&strcmp(p->status,"0")!=0)/*如果输入不是所给选项，重新输入*/ 
		{
			printf("请重新输入：");
			gets(p->status);
		}
		printf("请输入尺码大小（厘米）：");
		gets(p->size);
		printf("请输入颜色：");
		gets(p->color);
		r->next=p;
		p->prev=r;
		r=p;
		p=(node*)malloc(sizeof(node));
		printf("请输入衣服种类名称(按q结束):");
	    gets(p->kindname);
	    fflush(stdin);
	}
	free(p);
	r->next=NULL;
	return h; 
}
void exchange( node * p, node * min )  /*交换节点函数*/ 
{  
    node *min_prev;
    node *p_next;
    if(p==min)  
        return;  
    //p和min相邻要改6个指针，不相邻改8个指针  
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
  
    if( min == p_next ) //p和min相邻  
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
node *rorder(node *head)  //排序函数 
{  
     node *p=head->next;
     node *min ;
     node *s;
    //选择排序，每一轮选择最小元素节点的和p节点交换  
    for(p; p->next!=NULL; p=p->next)  
    {  
        min = p; //初始化最小节点
		s=p->next;  
        for(s; s!=NULL; s=s->next)  
        {  
            //找最小元素的节点  
            if( strcmp(min->kindname,s->kindname)>0 )  
                min = s;  
        }  
        exchange( p, min ); //交换两个节点  
        p=min;//交换两个节点后，p变到了min的位置，为了遍历，把节点p重新在移动到上次节点处，即p = min;  
    }  
    return head;  
}  
node *dorder(node *head)  //排序函数 
{  
     node *p=head->next;
     node *min;
     node *s;
    //选择排序，每一轮选择最小元素节点的和p节点交换  
    for(p; p->next!=NULL; p=p->next)  
    {  
        min = p; //初始化最小节点
		s=p->next;  
        for(s; s!=NULL; s=s->next)  
        {  
            //找最小元素的节点  
            if( strcmp(min->kindname,s->kindname)<0 )  
                min = s;  
        }  
        exchange( p, min ); //交换两个节点  
        p=min;//交换两个节点后，p变到了min的位置，为了遍历，把节点p重新在移动到上次节点处，即p = min;  
    }  
    return head;  
}  
void search(node *h)/*查找函数*/ 
{
	node *p;
	int i,m=0;
	char infor[10];
	p=h->next;
	printf("请选择进行简单查询1）/综合查询2）：");
	scanf("%d",&i);
	fflush(stdin);
	while(i!=1&&i!=2)
	{
		printf("请重新输入：");
		scanf("%d",&i);
	 } 
	fflush(stdin);
	if(i==1)
    {
	printf("请输入所要查询的衣服信息（种类/编号/进货日期）：");
	gets(infor);
	printf("查询结果为：\n");
	while(p!=NULL)
	  {
		if(strcmp(infor,p->kindname)==0||strcmp(infor,p->itemnumber)==0||strcmp(infor,p->purchasedate)==0)
		{
		   printf("衣服种类名称：");
		printf("%s\n",p->kindname);
		printf("衣服编号:"); 
		printf("%s\n",p->itemnumber);
		printf("进货日期：");
	    printf("%s\n",p->purchasedate);
	    printf("衣服状态：");
		if(strcmp(p->status,"0")==0)
		printf("未售！");
		else
		printf("已售！");
		printf("进价(元)：");
		printf("%s\n",p->originalprice);
		printf("售价：");
		printf("%s\n",p->salesprice);
		printf("尺码大小（厘米）：");
		printf("%s\n",p->size);
		printf("颜色：");
	    printf("%s\n",p->color);
	    m=1;
		}
		p=p->next;
	  }
	  if(!m)
	  printf("无匹配项！\n");
    }
    else if(i==2)
    {
       printf("请输入所要查询的衣服的种类、编号、进货日期（以空格隔开之）：");
	   scanf("%s%s%s",p->kindname,p->itemnumber,p->purchasedate); 
	   printf("查询结果为：");
	   while(p!=NULL)
	  {
		if(strcmp(infor,p->kindname)==0&&strcmp(infor,p->itemnumber)==0&&strcmp(infor,p->purchasedate)==0)
		{
		 printf("衣服种类名称：");
		 printf("%s\n",p->kindname);
		 printf("衣服编号:"); 
		 printf("%s\n",p->itemnumber);
		 printf("进货日期：");
	     printf("%s\n",p->purchasedate);
	     printf("衣服状态：");
		 if(strcmp(p->status,"0")==0)
		 printf("未售！");
		 else
		 printf("已售！");
		 printf("\n进价(元)：");
		 printf("%s\n",p->originalprice);
		 printf("售价：");
		 printf("%c\n",p->salesprice);
		 printf("尺码大小(厘米)：");
		 printf("%s\n",p->size);
		 printf("颜色：");
	     printf("%s\n",p->color);
		}
		m=1; 
		p=p->next;
	  }
	  if(!m)
	  printf("无匹配项！\n");
	}
	else 
	printf("无效输入！");
}
void print(node *h)
{
    node *p,*r;
	p=h->next;
	printf("衣服种类 ");
	printf("衣服编号 ");
	printf("进货日期 ");
	printf("衣服状态 ");
	printf("进价(元) ");
	printf("售价(元) ");
	printf("尺码大小（厘米） ");
	printf("颜色\n");
	while(p!=NULL)
	{
		printf("%s\t  ",p->kindname);
		printf("%s   ",p->itemnumber);
	    printf("  %s  ",p->purchasedate);
		if(strcmp(p->status,"0")==0)
		printf("未售!\t");
		else
		printf("已售!\t");
		printf("%s\t",p->originalprice);
		printf("%s\t   ",p->salesprice);
		printf("%s\t\t",p->size);
	    printf("%s\n",p->color);
		p=p->next;
	}	
}
void innode(linklist q)//添加服装信息，将其保存到文件中。 
{
	node *p;
	char arr[10];
	int i,flag=0;
	q=q->next;
	p=(node*)malloc(sizeof(node));
	printf("\t\t请输入衣服种类名称:");
	gets(p->kindname);
	printf("\n\t\t请输入衣服编号：");
	gets(p->itemnumber);
	printf("\n\t\t请输入进货日期：");
	gets(p->purchasedate);
    printf("\n\t\t请输入进价(元)：");
	gets(p->originalprice);
	printf("\n\t\t请输入售价：");
	gets(p->salesprice);
	printf("\n\t\t请输入衣服状态（未售0/已售1）：");
	gets(p->status);
		while(strcmp(p->status,"1")!=0&&strcmp(p->status,"0")!=0)/*如果输入不是所给选项，重新输入*/ 
		{
			printf("\n\t\t\t\t请重新输入：");
			gets(p->status);
		}
	printf("\n\t\t请输入尺码大小（厘米）：");
	gets(p->size);
	printf("\n\t\t请输入颜色：");
	gets(p->color);
    printf("请选择插入某衣服位置之前1）或之后2）：");
    scanf("%d",&i);
    fflush(stdin);
    if(i==2)
    {
     printf("\n请输入该衣服的编号：");
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
    	printf("\n请输入该衣服的编号：");
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
printf("\n\n\n\t\t\t\t无效输入！");
if(flag==0)
printf("无匹配项！"); 
}
void denode(node *h)
{
	node *p,*r;
	char number[10];
	p=h->next;
	r=h;
	printf("\n\n\n\n\n\t\t\t\t请输入所要删除的衣服编号：");
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
	printf("\t\t\t\t无匹配项！");
}
void modify(node *h)//修改服装信息。 
{
	node *p;
	int i=0;
	char name[10];
	char number[10]; 
	p=h->next;
	printf("请输入所要修改的衣服的信息（种类名称、编号,以空格隔开）：");
	scanf("%s",name);
	scanf("%s",number);
	while(p!=NULL)
	{
		if(strcmp(p->kindname,name)==0&&strcmp(p->itemnumber,number)==0)
		{ 
		  printf("请输入修改后的信息：");
		  printf("请输入衣服种类：");
	      scanf("%s",p->kindname);
	      getchar();
	      printf("\n请输入进货日期：");
	      gets(p->purchasedate);
	      printf("\n请输入销售量：");
	      gets(p->originalprice);
	      printf("\n请输入进价(元)：");
	      gets(p->originalprice);
	      printf("\n请输入售价：");
	      gets(p->salesprice);
	      printf("\n请输入衣服状态（已售1/未售0）：");
	      gets(p->status);
		while(strcmp(p->status,"1")!=0&&strcmp(p->status,"0")!=0)/*如果输入不是所给选项，重新输入*/ 
		{
			printf("请重新输入：");
			gets(p->status);
		}
	      printf("\n请输入尺码大小（厘米）：");
	      gets(p->size);
	      printf("\n请输入颜色：");
	      gets(p->color);
	      i=1;
		  break; 
		}
	    p=p->next;	
	}
	if(i==0)
	printf("该衣服不存在！");
}
linklist read_file()//获取保存的文件。 
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
void save_file(linklist h)//保存文件。 
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
void resave_file(linklist h)//重新保存文件 
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
void statis(linklist p)//对服装信息的统计。 
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
		if(strcmp(p->status,"1")==0)/*统计销售量*/ 
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
	//判断并统计最后一个节点的状态
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
    printf("衣服种类\t");
    printf("销售量\t");
    printf("库存量\t");
	printf("利润（元）\n");
    while(q!=NULL)
    {
	  printf("%s\t\t",q->name);
	  printf("%d\t",q->solded);
	  printf("%d\t",q->data-q->solded);
	  printf("%d\n",q->sumprice);
	  q=q->next;
    }
}





