#include <bits/stdc++.h>
#define fr freopen("input.in","r",stdin)
#define fw freopen("output.out","w",stdout)
#define iOs ios_base::sync_with_stdio(false);
#define INF 111313131 
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int id[1000001],sz[1000001];
int quickunion(int n)
{
	for(int i=1;i<=n;i++)
		id[i]=i;
	fill_n(sz,1000001,1);
	return 0;
}
int root(int i)
{
	while(id[i]!=i)
		{ id[i]=id[id[i]]; i=id[i]; }
	return i;
}
bool connected(int p,int q)
{
	if(root(p)==root(q)) return true;
	else return false;
}
int unione(int p,int q)
{
	int i=root(p);
	int j=root(q);
	if(i==j) return 0;
	if(sz[i]<sz[j]) {id[i]=j; sz[j]+=sz[i]; sz[i]=0;}
	else {id[j]=i; sz[i]+=sz[j]; sz[j]=0;}
	return 0;
}
int main()
{
	fw;fr;
	iOs;
	int n,count=0; cin>>n;
	quickunion(n);
	char c;
	while(c!='-')
	{
		cin>>c;
		if(c==45) break;
		else if(c=='C')
		{
			int x,y; cin>>x>>y;
			if(connected(x,y)==true)
				continue;
			else
			{
				unione(x,y);
				//cout<<sz[x]<<" "<<sz[y]<<"        in union"<<endl;
			}
		}
		else
		{
			int x,y;
			cin>>x>>y;
			for(int i=1;i<=n;i++)
			{
				//cout<<sz[i]<<endl;
				if(sz[i]%2==0 && sz[i]>0)
					count++;
			}
			cout<<count<<endl;
			count=0;
		}
	}
return 0;
}
