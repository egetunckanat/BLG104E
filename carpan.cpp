#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
int N;
struct num 
{
	vector < vector <int> >  myv;
};
num nums[10005];

vector < vector <int> > calc(int m)
{
	vector < vector <int> > temp;
	vector <int> temp1;
	if(nums[m].myv.size()!=0)
	{
		return nums[m].myv;
	}
	int i,j,t,k,cont;
	for(i=1;i<m;i++)
	{
		if(m%i!=0)
			continue;
		temp=calc(i);
		for(j=0;j<temp.size();j++)
		{
			temp1=temp[j];
			temp1.push_back(m/i);
			sort(temp1.begin(),temp1.end());
			cont=0;
			for(k=0;k<nums[m].myv.size();k++)
			{
				if(nums[m].myv[k]==temp1)
				{
					cont=1;
					break;
				}
			}
			if(!cont)
				nums[m].myv.push_back(temp1);			
		}
	}
	return nums[m].myv;
}
int main()
{
	int i,j,t;
	vector < vector <int> > temp;
	vector <int> temp1;
	temp1.push_back(1);
	temp.push_back(temp1);
	nums[1].myv.push_back(temp1);
	cin>>N;
	for(i=1;i<=N;i++)
	{
		cin>>t;
		temp=calc(t);
		cout<<"Case "<<i<<" : "<<nums[t].myv.size()<<endl;
	}
	return 0;
}