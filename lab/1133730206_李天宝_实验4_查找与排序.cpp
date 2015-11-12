#include<iostream>
using namespace std;
int n,a[50];
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
int findpivot(int i,int j)
{
	for(int k=i+1;k<=j;k++)
		if(a[k]>a[i])
			return k;
		else if(a[k]<a[i])
			return i;
	return 0;
}
int partion(int i,int j,int p)
{
	int l=i,r=j;
	do
	{
		while(a[l]<p)
			l++;
		while(a[r]>=p)
			r--;
		if(l<r)
		{
			swap(a[l],a[r]);
			for(int i=1;i<=n;i++)
				cout<<a[i]<<ends;
			cout<<endl;
		}
	}while(l<=r);
	return l;
}
void qsort(int i,int j)
{
	int v=findpivot(i,j);
	if(v)
	{
		int k=partion(i,j,a[v]);
		qsort(i,k-1);
		qsort(k,j);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	qsort(1,n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<ends;
	cout<<endl;
	return 0;
}
