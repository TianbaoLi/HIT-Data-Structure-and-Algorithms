#include<iostream>
#include<fstream>
using namespace std;
class node
{
public:
	int coef;
	int exp;
	node *next;
	node()
	{
		coef=0;
		exp=2147483647;
		next=NULL;
	}
};
node *head1,*head2;
void add(node *head,int x,int y)
{
	node *p=head;
	while(p->next!=NULL)
		p=p->next;
	p->next=new node();
	p=p->next;
	p->coef=x;
	p->exp=y;
}
void show(node *head)
{
	node *p=head->next;
	while(p!=NULL)
	{
		if(p->coef<0)cout<<'\b';
		cout<<p->coef<<"x^"<<p->exp<<'+';
		p=p->next;
	}
	cout<<"\b\b\b\b"<<"    "<<endl;
}
void build()
{
	ifstream fin1("link1.txt");
	ifstream fin2("link2.txt");
	int x,y;
	while(fin1>>x>>y)
		add(head1,x,y);
	while(fin2>>x>>y)
		add(head2,x,y);
}
void insert(node *head,int x,int y)
{
	node *p=head;
	while(p!=NULL)
	{
		if(p->exp==y)
		{
			p->coef+=x;
			return;
		}
		else if((p->exp)>y&&(p->next->exp)<y)
		{
			node *temp=new node();
			temp->coef=x;
			temp->exp=y;
			temp->next=p->next;
			p->next=temp;
			return;
		}
		p=p->next;
	}
}
void fun()
{
	node *p=head2->next;
	while(p!=NULL)
	{
		insert(head1,p->coef,p->exp);
		p=p->next;
	}
}
int main()
{
	head1=new node();
	head2=new node();
	build();
	show(head1);
	show(head2);
	fun();
	show(head1);
	return 0;
}
