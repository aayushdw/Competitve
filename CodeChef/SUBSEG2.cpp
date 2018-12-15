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
#define MAX 1000000+5
using namespace std;
vector<pair<ll,ll> > v;
vector<ll> s;
ll a[MAX],b[MAX],c[MAX],d[100000+5];
int main()
{
	ll n,q,i,j,start,end,num=0,prev=-1,t,f,ans,curr,next,st;
	scll(n); scll(q);
	for(i=0;i<MAX;i++)
	{
		a[i]=-1;
		b[i]=-1;
		c[i]=0;
	}
	for(i=0;i<100000+5;i++)
	d[i]=-1;
	for(i=0;i<n;i++)
	{
		scll(start); scll(end);
		if(a[end]<start)
		{
			v.pb(mp(end,start));
			a[end]=start;
		}
	}
	sort(v.begin(),v.end());
	start=0; end=0; t=0; i=0;
	while(i<v.size())
	{
		end=v[i].first; f=-1;
		while(i<v.size() && v[i].first==end)
		{
			if(v[i].second>start)
			{
				f=i;
				start=v[i].second;
			}
			i++;
		}
		if(f>=0)
		{
			s.pb(f);
			for(i=v[f].second;i<v[f].first;i++)
			{
				b[i]=f;
				c[i]=num;
			}
			b[i]=f;
			c[i]=num+1;
			if(prev>=0)
			{
				d[prev]=f;
				prev=f;
			}
			else
			prev=f;
		}
	}
	while(q--)
	{
		scll(start); scll(end);
		ans=c[end]-c[start-1];
		if(start==1 || b[start]==-1 || b[start]!=b[start-1])
		printf("%lld\n",ans);
		else
		{
			curr=b[start];
			next=d[curr];
			if(next==-1)
			{
				printf("%lld\n",ans);
				continue;
			}
			st=v[next].second;
			j=curr+1;
			while(v[j].first<st)
			{
				if(v[j].second>=start)
				{
					ans+=1;
					break;
				}
				j++;
			}
			printf("%lld\n",ans);
		}
	}
	
	return 0;
}
