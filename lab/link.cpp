#include<iostream>
#include<fstream>
using namespace std;
class node
{
public:
	int num;
	node *next;
	node()
	{
		num=0;
		next=NULL;
	}
};
node *head;
void add(int x)
{
	node *p=head;
	while(p->next!=NULL)
		p=p->next;
	p->next=new node();
	p=p->next;
	p->num=x;
	
}
void show()
{
	node *p=head->next;
	while(p!=NULL)
	{
		cout<<p->num<<ends;
		p=p->next;
	}
	cout<<endl<<endl;
}
void sort()
{
	for(node *p=head->next;p!=NULL;p=p->next)
		for(node *q=p;q!=NULL;q=q->next)
			if(p->num>q->num)
			{
				int temp=p->num;
				p->num=q->num;
				q->num=temp;
			}
}
void build()
{
	ifstream fin("link.txt");
	int x;
	while(fin>>x)
		add(x);
	sort();
}
void search(int x)
{
	node *p=head->next;
	int cou=1;
	while(p!=NULL)
	{
		if(p->num==x)
		{
			cout<<x<<" is No."<<cou<<" Element!"<<endl;
			return;
		}
		p=p->next;
		cou++;
	}
	cout<<"Haven`t Found "<<x<<endl;
}
void insert(int x)
{
	node *p=head;
	while(p->next!=NULL)
	{
		if((p->num)<=x&&(p->next->num)>=x)
		{
			node *temp=new node();
			temp->num=x;
			temp->next=p->next;
			p->next=temp;
			cout<<x<<" is Inserted"<<endl;
			return;
		}
		p=p->next;
	}
	cout<<"Haven`t Found "<<x<<endl;
}
void del(int x)
{
	node *p=head;
	while(p->next!=NULL)
	{
		if(p->next->num==x)
		{
			p->next=p->next->next;
			cout<<x<<" is Deleted"<<endl;
			return;
		}
		p=p->next;
	}
	cout<<"Haven`t Found "<<x<<endl;
}
int length()
{
	node *p=head->next;
	int cou=0;
	while(p!=NULL)
	{
		cou++;
		p=p->next;
	}
	return cou;
}
void reverse()
{
	node *p=head->next,*q=head->next->next,*r;
	while(q!=NULL)
	{
		r=q->next;
		q->next=p;
		p=q;
		q=r;
	}
	head->next->next=NULL;
	head->next=p;
}
int main()
{
	head=new node();
	int order,x;
	cout<<"Input the Number for the Instruction"<<endl;
	cout<<"1.build"<<endl;
	cout<<"2.search"<<endl;
	cout<<"3.insert"<<endl;
	cout<<"4.delete"<<endl;
	cout<<"5.length"<<endl;
	cout<<"6.reverse"<<endl;
	cout<<"7.show"<<endl;
	cout<<"0.exit"<<endl;
	cout<<endl;
	cin>>order;
	while(order!=0)
	{
		switch(order)
		{
			case 1:
				build();
				show();
				break;
			case 2:
				cout<<"Input the Number to be Searched"<<endl;
				cin>>x;
				search(x);
				show();
				break;
			case 3:
				cout<<"Input the Number to be Inserted"<<endl;
				cin>>x;
				insert(x);
				show();
				break;
			case 4:
				cout<<"Input the Number to be Deleted"<<endl;
				cin>>x;
				del(x);
				show();
				break;
			case 5:
				cout<<"the Lenngth is "<<length()<<endl;
				break;
			case 6:
				reverse();
				show();
				break;
			case 7:
				show();
				break;
			case 0:
				return 0;
		}
		cout<<"Input the Number for the Instruction"<<endl;
		cout<<"1.build"<<endl;
		cout<<"2.search"<<endl;
		cout<<"3.insert"<<endl;
		cout<<"4.delete"<<endl;
		cout<<"5.length"<<endl;
		cout<<"6.reverse"<<endl;
		cout<<"7.show"<<endl;
		cout<<"0.exit"<<endl;
		cout<<endl;
		cin>>order;
	}
	return 0;
}
