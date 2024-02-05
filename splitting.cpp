#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node*link;
};
struct node*create_list(struct node*start);
void display(struct node*start);
struct node*insertatbeg(struct node*start,int data);
struct node*insertatend(struct node*start,int data);
void split(struct node*start,int value,struct node**start1);
int main()
{
	struct node*start=NULL,*start1=NULL;
	int value;
	
	start=create_list(start);
	display(start);
	
	printf("Enter node after which u want to split:");
	scanf("%d",&value);
	split(start,value,&start1);
	display(start);
	display(start1);
	return 0;
}
void split(struct node*start,int value,struct node**start1)
{
	struct node*p=start;
	while(p != NULL)
	{ 
	if(p->info==value)
	break;
	p=p->link;
	}
	if(p==NULL)
	{
	printf("\nValue does not exist\n");
	return;
	}
	*start1=p->link;
	p->link=NULL;
}
struct node*create_list(struct node*start)
{
	int i,n,data;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
	return start;
	
	printf("\nEnter the element to be insertde:");
	scanf("%d",&data);
	start=insertatbeg(start,data);
	
	for(i=2;i<=n;i++)
	{
	printf("\nEnter the element to be insertde:");
	scanf("%d",&data);
	start=insertatbeg(start,data);	
	}
	return start;
}
void display(struct node*start)
{
	struct node*p;
	if(start==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	p=start;
	printf("\nList is:\n");
	while(p !=NULL)
	{
		printf("%d",p->info);
		p=p->link;
	}
	printf("\n\n");
}
struct node*insertatbeg(struct node*start,int data)
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=start;
	start=temp;
	return start;
}
struct node*insertatend(struct node*start,int data)
{
	struct node *p,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	p=start;
	while(p->link!=NULL)
	p=p->link;
	p->link=temp;
	temp->link=NULL;
	return start;
}
