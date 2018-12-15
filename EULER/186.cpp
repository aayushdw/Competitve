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
#define MAX 1000000
using namespace std;

//COPY FROM HERE


ll siz=MAX,numset;
vector<ll> pset(siz), rnk(siz), setSize(siz)/*size of each set*/;
void initSet(ll _size)
{ 
	pset.resize(_size); numset=_size;
	rep (i,0,_size) 
	{
		pset[i] = i, rnk[i]=1;
		setSize[i]=1;	//for size of set
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
	numset--;
	if(rnk[x]<rnk[y])
	{
		pset[x]=y;
		setSize[y]+=setSize[x];
	}
	else if(rnk[x]>rnk[y])
	{
		pset[y]=x;
		setSize[x]+=setSize[y];
	}
	else
	{
		pset[x]=y, rnk[y]++;
		setSize[y]+=setSize[x];
	}
}

//TO HERE

int main()
{
	initSet(MAX);
	vector<ll> f(57);
	ll p,x,y=0;
	rep(i,1,56)
	{
		f[i]=(100003-200003*i+300007*i*i*i)%MAX;
		//printf("%2lld %2lld\n",i,f[i]);
	}
	f[56]=(f[32]+f[1])%MAX;
	rep(i,1,29)
	{
		unionSet(f[2*i-1],f[2*i]);
		//printf("call %lld: %lld to %lld\n",i,f[2*i-1],f[2*i]);
	}
	p=57;
	//printf("%lld\n",f[56]);
	cout<< f.size()<< '\n';
	//return 0;
	while(1)
	{
		f.pb((f[p-24]+f[p-55])%MAX);
		p++;
		f.pb((f[p-24]+f[p-55])%MAX);
		p++;
		unionSet(f[p-1],f[p-2]);
		if(f[p-1]==f[p-2])
			y++;
		x=findSet(524287);
		if(setSize[x]>=990000)
		{
			printf("calls=%lld misdials=%lld\n",p/2,y);
			return 0;
		}
	}
}