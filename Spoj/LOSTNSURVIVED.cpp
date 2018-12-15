#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int>; 
#define vvi vector<vi>; 
#define ii pair<int,int>; 
#define pll pair<ll,ll>; 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define INF 10000000000000000
#define MAX 100000+5
using namespace std;

//COPY FROM HERE


ll siz=MAX,numset;
vector<ll> pset(siz), rank(siz), setSize(siz)/*size of each set*/;
set<pair<ll,ll> > s;// contains roots
void initSet(ll _size)
{ 
	pset.resize(_size); numset=_size;
	rep (i,0,_size) 
	{
		pset[i] = i, rank[i]=1;
		setSize[i]=1;	//for size of set
		s.insert(mp(1,i));	//contains roots
	}
}
ll findSet(ll i) 
{ 
	return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); 
}
void unionSet(ll i,ll j)
{
	ll x=findSet(i), y=findSet(j);
	if(x==y)
		return;
	if(rank[x]<rank[y])
	{
		pset[x]=y;
		s.erase(mp(setSize[x],x));
		s.erase(mp(setSize[y],y));
		s.insert(mp(setSize[y]+setSize[x],y));
		setSize[y]+=setSize[x];
	}
	else if(rank[x]>rank[y])
	{
		pset[y]=x;
		s.erase(mp(setSize[x],x));
		s.erase(mp(setSize[y],y));
		s.insert(mp(setSize[y]+setSize[x],x));
		setSize[x]+=setSize[y];
	}
	else
	{
		pset[x]=y, rank[y]++;
		s.erase(mp(setSize[x],x));
		s.erase(mp(setSize[y],y));
		s.insert(mp(setSize[y]+setSize[x],y));
		setSize[y]+=setSize[x];
	}
}

//TO HERE

int main()
{
	ll n,q,x,y;
	scll(n); scll(q);
	initSet(n);
	while(q--)
	{
		scll(x); scll(y); x--; y--;
		unionSet(x,y);
		printf("%lld\n",(s.rbegin()->first)-(s.begin()->first));
	}
	return 0;
}