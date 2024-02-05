#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
int info;
struct node *next;
}*start;
class single_list
{
public:
node *create_node(int);
void insert_begin();
void insert_last();
void delete_pos();
void display();
single_list()
{
	start=NULL;
}
};
main() 
 {
int choice;
single_list sl,s2;
 start=NULL;
do{
  cout<<"1.Insert node at beginning"<<endl;
  cout<<"2.Insert node at last"<<endl;
  cout<<"3.Insert node at position"<<endl;
  cout<<"4.Delete a particular node"<<endl;
  cout<<"5.display linked list"<<endl;
  cout<<"6.Exit"<<endl;
  cout<<"Enter choice :";
  cin>>choice;
 switch(choice)
 {
 case 1:cout<<"Insert node at beginning"<<endl;
       sl.insert_begin();
	   cout<<endl; 
	   break;
 case 2:cout<<"Insert node at last"<<endl;
      sl.insert_last();
	   cout<<endl; 
	   break;
 case 3:cout<<"Insert node at a given position"<<endl;
        sl.insert_pos();
	   cout<<endl; 
	   break;
 case 4:cout<<"Delete a particular node"<<endl;
       sl.delete_pos();
       break;
 case 5: cout<<"display linked list"<<endl;
      sl.display();
      break;
 case 6:cout<<"Exiting...:"<<endl;
      exit(1);
      break;
 default:cout<<"Wrong choice"<<endl;
      }
}
while(choice !=6);
}
node*single_list::create_node(int value)
{
	struct node*temp,*s;
	temp=new(struct node);
	if(temp==NULL)
	{
		cout<<"Memory not allocated"<<endl;
		return 0;
	}
	else
	{
		temp->info=value;
		temp->next=NULL;
		return temp;
	}
}
void single_list::insert_begin()
{
	int value;
	cout<<"Enter the value to be inserted:";
	cin>>value;
	struct node *temp,*p;
	temp=create_node(value);
	if(start==NULL)
	{
		start=temp;
		start->next=NULL;
	}
	else
	{
		p=start;
		start=temp;
		start->next=p;
	}
	cout<<"Element inserted at begining"<<endl;
}
void single_list::insert_last()
{
	int value;
	cout<<"Enter the value to be inserted:";
	cin>>value;
	struct node *temp,*s;
	temp=create_node(value);
	s=start;
	while(s->next !=NULL)
	{
		s=s->next;
	}
	temp->next=NULL;
	s->next=temp;
cout<<"Element inserted at begining"<<endl;
}
 
 void single_list::insert_pos()
{
	int value,pos,counter=0;
	cout<<"Enter the value to be inserted:";
	cin>>value;
	struct node *temp,*s,*ptr;
	temp=create_node(value);
	cout<<"Enter the position at which node to be inserted:";
	cin>>pos;
	int i;
	s=start;
	while(s !=NULL)
	{
		s=s->next;
		counter++;
	}
	if(pos==1)
	{
		if(start==NULL)
		{
			start=temp;
			start->next=NULL;
		}
		else
		{
			ptr=start;
			start=temp;
			start->next=ptr;
		}
	}
else if(pos>1 && pos<=counter)
{
s=start;
for(i=1;i<pos;i++)
{
	ptr=s;
	s=s->next;
}	
	ptr->next=temp;
	temp->next=s;
}
else
{
cout<<"position out of range"<<endl;
}
}

void single_list::delete_pos()
{
	int pos,i,counter=0;
	if(start==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	cout<<"Enter the position to be deleted:";
	cin>>pos;
	struct node *s,*ptr;
	s=start;
	if(pos==1)
	{
		start=s->next;
	}
	else
	{
		while(s !=NULL)
		{
			s=s->next;
			counter++;
		}
		if(pos>0 && pos<=counter)
		{
			s=start;
			for(i=1;i<pos;i++)
			{
				ptr=s;
				s=s->next;
			}
			ptr->next=s->next;
		}
		else
		{
			cout<<"Position out of range"<<endl;
		}
	free(s);
	cout<<"Element deleted"<<endl;
    }
}
void single_list::display()
{
	struct node *temp;
	if(start==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	temp=start;
	cout<<"Elements of list are:"<<endl;
	while(temp !=NULL)
	{
	cout<<temp->info<<"->";
	temp=temp->next;
}
   cout<<endl;
}
