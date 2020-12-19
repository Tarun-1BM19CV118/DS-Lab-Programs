#include<stdio.h>
#include<conio.h>
#define qsize 5
int isfull(int r)
  {
   return(r==qsize-1)?1:0;
  }
int isempty(int f,int r)
  {
   return(f>r)?1:0;
  }
void insert_rear(int item,int *r,int q[])
  {
   if(isfull(*r))
	 {
	  printf("queue overflow\n");
	  return;
	 }
   *r=*r+1;
   q[*r]=item;
  }
void delete_front(int *f,int *r,int q[])
  {
   if(isempty(*f,*r))
	 {
	  printf("queue empty\n");
	  return;
	 }
   printf("item deleted is %d\n",q[(*f)++]);
   if(*f>*r)
	 {
	  *f=0;
	  *r=-1;
	 }
  }
void insert_front(int *f,int *r,int q[],int item)
  {
   if(*f!=0)
	 {
	  *f=*f-1;
	  q[*f]=item;
	  return;
	 }
	else if((*f==0)&&(*r==-1))
	 {
	  q[++(*r)]=item;
	  return;
	 }
	else
	  printf("insertion not possible\n");
  }
void delete_rear(int *f,int *r,int q[])
  {
   if(isempty(*f,*r))
	 {
	  printf("queue is empty\n");
	  return;
	 }
   printf("item deleted is %d\n",q[(*r)--]);
   if(*f>*r)
	 {
	  *f=0;
	  *r=-1;
	 }
  }
void display(int f,int r ,int q[])
  {
   int i;
   if(isempty(f,r))
	 {
	  printf("queue empty\n");
	  return;
	 }
   for(i=f;i<=r;i++)
	printf("%d\n",q[i]);
  }
void main()
 {
  int f=0,r=-1,item,q[10],ch;

  for(;;)
   {
	printf("1.insert_rear\n2.insert_front\n3.delete_rear\n4.delete_front\n5.display\n6.exit\n");
	printf("enter choice\n");
	scanf("%d",&ch);
	switch(ch)
	  {
	   case 1:printf("enter the item\n");
			  scanf("%d",&item);
			  insert_rear(item,&r,q);
			  break;
	   case 2:printf("enter the item\n");
			  scanf("%d",&item);
			  insert_front(&f,&r,q,item);
			  break;
	   case 3:delete_rear(&f,&r,q);
			  break;
	   case 4:delete_front(&f,&r,q);
			  break;
	   case 5:display(f,r,q);
			  break;
	   default:exit(0);
	  }
	}
  }

