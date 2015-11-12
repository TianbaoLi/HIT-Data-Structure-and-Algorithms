#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class node
{
public:
	char ch;
	node *lc;
	node *rc;
	node(char c)
	{
		ch=c;
		lc=NULL;
		rc=NULL;
	}
};
node *tree;
node* search(node *h,char x)
{
	if(h->ch==x)return h;
	if(h->lc!=NULL)
	{
		node *ans=NULL;
		ans=search(h->lc,x);
		if(ans!=NULL)
			return ans;
	}
	if(h->rc!=NULL)
	{
		node *ans=NULL;
		ans=search(h->rc,x);
		if(ans!=NULL)
			return ans;
	}
	return NULL;
}
void build()
{
	ifstream fin("tree.txt");
	char a,b,c;
	fin>>a>>b>>c;
	tree=new node(a);
	while(fin>>a>>b>>c)
	{
		node *p=search(tree,b);
		node *q=new node(a);
		if(c=='L')
			p->lc=q;
		else
			p->rc=q;
	}
}
void preorder(node *p)
{
	if(p==NULL)return;
	cout<<p->ch;
	preorder(p->lc);
	preorder(p->rc);
}
void inorder(node *p)
{
	if(p==NULL)return;
	inorder(p->lc);
	cout<<p->ch;
	inorder(p->rc);
}
void postorder(node *p)
{
	if(p==NULL)return;
	postorder(p->lc);
	postorder(p->rc);
	cout<<p->ch;
}
void levelorder(node *p)
{
	vector<node *>list;
	list.push_back(p);
	while(list.empty()==0)
	{
		node *q=list.front();
		list.erase(list.begin());
		cout<<q->ch;
		if(q->lc!=NULL)
			list.push_back(q->lc);
		if(q->rc!=NULL)
			list.push_back(q->rc);
	}
}
int main()
{
	int order=-1;
	while(order!=0)
	{
		switch(order)
		{
			case 1:
				build();
				break;
			case 2:
				cout<<"Input the char to be Searched"<<endl;
				char x;
				cin>>x;
				node *q=search(tree,x);
				cout<<"char:"<<q->ch;
				if(q->lc!=NULL)
					cout<<"\tleftchild:"<<q->lc->ch;
				if(q->rc!=NULL)
					cout<<"\trightchild:"<<q->rc->ch;
				cout<<endl<<endl;
				break;
			case 3:
				preorder(tree);
				cout<<endl<<endl;
				break;
			case 4:
				inorder(tree);
				cout<<endl<<endl;
				break;
			case 5:
				postorder(tree);
				cout<<endl<<endl;
				break;
			case 6:
				levelorder(tree);
				cout<<endl<<endl;
				break;
			case 0:
				return 0;
		}
		cout<<"Input the Number for the Instruction"<<endl;
		cout<<"1.build"<<endl;
		cout<<"2.search"<<endl;
		cout<<"3.preorder"<<endl;
		cout<<"4.inorder"<<endl;
		cout<<"5.postorder"<<endl;
		cout<<"6.levelorder"<<endl;
		cout<<"0.exit"<<endl;
		cout<<endl;
		cin>>order;
	}
}
