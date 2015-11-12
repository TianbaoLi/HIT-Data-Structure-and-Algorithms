#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
const int maxlen=214748364;
const int maxn=10;
int map[maxn+1][maxn+1];
int n,from,to,len,point;
ifstream fin("map.txt");
bool visited[maxn];
int dis[maxn];
int road[maxn+1];
stack<int> record;
void  Dijkstra(int p)
{
	for(int i=1;i<=n;i++)
		dis[i]=map[point][i];
	for(int i=1;i<=n;i++)
		visited[i]=0;
	for(int i=1;i<=n;i++)
		road[i]=p;
	visited[p]=1;
	for(int i=1;i<n;i++)
	{
		int l=maxlen,t=0;
		for(int j=1;j<=n;j++)
		{
			if(j==p)continue;
			if(visited[j]==0&&dis[j]<=l)
			{
				l=dis[j];
				t=j;
			}
		}
		visited[t]=1;
		for(int j=1;j<=n;j++)
		{
			if(j==p)continue;
			if(visited[j]==0)
				if(dis[j]>dis[t]+map[t][j])
				{
					dis[j]=dis[t]+map[t][j];
					road[j]=t;
				}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==p)continue;
		if(dis[i]==214748364)
		{
			cout<<i<<":No road"<<endl;
			continue;
		}
		cout<<i<<":"<<dis[i]<<endl;
		cout<<"The road is: ";
		int temp=i;
		while(temp!=p)
		{
			record.push(temp);
			temp=road[temp];
		}
		record.push(temp);
		while(record.empty()==0)
		{
			cout<<record.top()<<ends;
			record.pop();
		}
		cout<<endl;
	}
}
int main()
{
	fin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			map[i][j]=maxlen;
	while(fin>>from>>to>>len)
		map[from][to]=len;
	cout<<"Input the start point:";
	cin>>point;
	Dijkstra(point);
	return 0;
}
