#include <iostream>
#include <vector>
using namespace std;
int adj[30][30],visited[30],rcount,best=1000000;
char last;
vector<char> dizi,road;
void read()
{
	cin>>last;
	char a,b;
	while(1)
	{
		cin>>a>>b;
		if(a=='A' && b=='A')
			break;
		adj[a-70][b-70]=1;
		adj[b-70][a-70]=1;
	}
}
void dfs(int a,int count)
{
	dizi.push_back(a+70);
	int i;
	if(a+70==last)
	{
		rcount++;
		if(best>count)
		{
			best=count;
			road=dizi;
		}
		return;
	}
	for(i=0;i<30;i++)
	{
		if(adj[a][i]==1 && visited[i]==0)
		{
			visited[i]=1;
			dfs(i,count+1);
			dizi.pop_back();
			visited[i]=0;
		}
	}
	
}
int main()
{
	read();
	visited[0]=1;
	dfs(0,1);
	if(rcount==0)
		cout<<"No Route Available from F to "<<last<<endl;
	else
	{
		cout<<"Total Routes: "<<rcount<<endl;
		cout<<"Shortest Route Length: "<<best<<endl;
		cout<<"Shortest Route after Sorting of Routes of length "<<best<<":";
		for(int i=0; i<road.size(); i++)
			cout<<" "<<road[i];
		cout<<endl;
	}
}