#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
using namespace std;
map <ll,ll> v;
int main()
{
	ll n,i,j,c=0,p,q;
	scll(n);
	typeof(v.begin()) it;
	for(i=0;i<n;i++)
	{
		scll(p);
		it = v.find(p);
		if(it!=v.end())
		(it->second)++;
		else
		v.insert(mp(p,1));
	}
	i=0; j=0;
	for(it=v.begin();it!=v.end();it++)
	{
		p=it->first;
		q=it->second;
		if(j+q>=p)
		j=p;
		else
		{
			while(it!=v.end())
			{
				q=it->second;
				j+=q;
				it++;
			}
			break;
		}
	}
	prll(j+1);
	return 0;
}
