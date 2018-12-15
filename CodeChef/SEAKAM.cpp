#include<stdio.h>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
#define scll(x) scanf("%lld",&x)
#define sc(x) scanf("%d",&x)
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define ll long long int
#define MAX 100005
#define MOD 1000000007
using namespace std;
set<ll> s;
vector<ll> vec[15];
ll arr[10][2],list[10][2],temp[2];
ll fact[MAX]={1},pow2[30]={1},iep[10]={0};
bool get_bit(ll a,ll n)
{
	return (a>>n-1)&1;
}
bool isCyclicUtil(ll v,bool visited[],ll parent)
{
    ll i;
    visited[v]=true;
    typeof(vec[i].begin()) it;
    for(it=vec[v].begin();it!=vec[v].end();it++)
    {
        if(!visited[*it])
        {   
            if(isCyclicUtil(*it,visited,v))
            return true;
        }
        else if(*it!=parent)
        return true;
    }
    return false;
}
bool isCyclic(ll n)
{
	ll i,j;
	s.clear();
	for(i=0;i<n;i++)
	{
		s.insert(list[i][0]);
		s.insert(list[i][1]);
	}
	vector<ll> v(all(s));
	ll size=sz(v);
	for(i=0;i<size;i++)
	/*
	printf("%lld ",v[i]);
	printf("\n");
	*/
	for(i=0;i<15;i++)
	vec[i].clear();
	
	map<ll,ll> m;
	for(i=0;i<size;i++)
	m.insert(make_pair(v[i],i));
	typeof(m.begin()) it;
	typeof(vec[0].begin()) p;
	for(i=0;i<size;i++)
	{
	    //printf("%lld = ",i);
		for(j=0;j<n;j++)
		if(list[j][0]==v[i])
		{
			it=m.find(list[j][1]);
			vec[i].push_back(it->second);
			//printf("%lld ",it->second);
		}
		for(j=0;j<n;j++)
		if(list[j][1]==v[i])
		{
			it=m.find(list[j][0]);
			vec[i].push_back(it->second);
			//printf("%lld ",it->second);
		}
		/*for(p=vec[i].begin();p!=vec[i].end();p++)
    	printf("%lld ",*p);
    	printf("\n");*/
	}
	ll u;
	bool *visited = new bool[size];
    for(i=0;i<size;i++)
    visited[i]=false;

	for (u=0;u<size;u++)
    if (!visited[u]) // Don't recur for u if it is already visited
    if (isCyclicUtil(u, visited, -1))
    return true;
 
    return false;
}

void get_count(ll n,ll x)
{
	ll i,a[15][2]={0},k=0,p,f,j;
	if(isCyclic(x))
	{
		temp[0]=0;
		temp[1]=0;
		return;
	}
	for(i=0;i<15;i++)
	{
		a[i][0]=-1;
		a[i][1]=0;
	}
	for(i=0;i<x;i++)
	{
		p=list[i][0]; f=0;
		for(j=0;j<k;j++)
		if(a[j][0]==p)
		{
			a[j][1]++;
			f=1;
		}
		if(!f)
		{
			a[k][0]=p;
			a[k][1]++;
			k++;
		}
		p=list[i][1]; f=0;
		for(j=0;j<k;j++)
		if(a[j][0]==p)
		{
			a[j][1]++;
			f=1;
		}
		if(!f)
		{
			a[k][0]=p;
			a[k][1]++;
			k++;
		}
	}
	ll count=0;
	for(i=0;i<k;i++)
	{
		if(a[i][1]>2)
		{
			temp[0]=0;
			temp[1]=0;
			return;
		}
		if(a[i][1]==1)
		count++;
	}
	temp[0]=k;
	temp[1]=count/2;
	return;
}
void pre()
{
	ll i;
	for(i=1;i<MAX;i++)
	fact[i]=(fact[i-1]*i)%MOD;
	for(i=1;i<30;i++)
	pow2[i]=(pow2[i-1]*2)%MOD;
	return;
}
int main()
{
	pre();
	ll i,j,n,t,m,k,ans,p,mul;
	ll a,b;
	scll(t);
	while(t--)
	{
	    for(i=0;i<10;i++)
	    iep[i]=0;
		scll(n); scll(m);
		for(i=0;i<m;i++)
		{
			scll(a); scll(b);
			arr[i][0]=a;
			arr[i][1]=b;
		}
		for(i=1;i<(1<<m);i++)
		{
			k=0;
			for(j=0;j<m;j++)
			{
				if(get_bit(i,j+1))
				{
					list[k][0]=arr[j][0];
					list[k][1]=arr[j][1];
					k++;
				}
			}
			/*
			for(int y=0;y<k;y++)
			printf("edges=%d %d,\t",list[y][0],list[y][1]);
			printf("\n");
			*/
			get_count(n,k);
			//printf("%d %d\n",temp[0],temp[1]);
			if(temp[1])
			{
				p=(fact[n-temp[0]+temp[1]]*pow2[temp[1]])%MOD;
				iep[k]+=p;
				iep[k]%=MOD;
			//	printf("%lld\n",p);
			}
		}
		ans=fact[n]; mul=-1;
		for(i=1;i<=m;i++)
		{
			ans+=mul*iep[i];
			mul*=-1;
			if(ans<0)
			ans+=MOD;
			ans%=MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
