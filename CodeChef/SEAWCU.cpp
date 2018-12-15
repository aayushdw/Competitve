#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld\n",x)
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define vi vector<int> 
#define vvi vector<vi> 
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define INF 10000000000000000
#define MAX 50+5
#define MOD 1000000007
using namespace std;
//memset(arr, 0, sizeof(arr)); // useful to clear array of integers and put 0 and -1 in them
bitset<MAX> isActive[MAX][MAX];
ll num,a[50][50][50];
vector<pair<ll,pair<ll,ll> > > ans,temp;
vector<pair<ll,pair<ll,pair<ll,ll> > > > v;
pair<ll,pair<ll,ll> > prev,next;
void modified_dijkstra(ll n)
{
	ans.clear();
	num=0;
	ll cost,x,y,z,m,s,idx;
	bool f;
	rep(j,0,n)
	rep(k,0,n)
	{
	    rep(p,0,n)
	    rep(q,0,n)
	    isActive[p][q].set();
		temp.clear();
		cost=a[0][j][k];
		prev=mp(0,mp(j,k));
		temp.pb(prev);
		isActive[0][j][k]=false;
		while(1)
		{
			f=false; m=1;
			x=prev.first; y=prev.second.first; z=prev.second.second;
			v.clear();
			if(x>0)
			{
				if(isActive[x-1][y][z] && a[x-1][y][z]>=m)
				v.pb(mp(a[x-1][y][z],mp(x-1,mp(y,z)))), f=true;
				isActive[x-1][y][z]=false;
			}
			if(x<n-1)
			{
				if(isActive[x+1][y][z] && a[x+1][y][z]>=m)
				v.pb(mp(a[x+1][y][z],mp(x+1,mp(y,z)))), f=true;
				//m=a[x+1][y][z], next=mp(x+1,mp(y,z)), f=true;
				isActive[x+1][y][z]=false;
			}
			if(y>0)
			{
				if(isActive[x][y-1][z] && a[x][y-1][z]>=m)
				v.pb(mp(a[x][y-1][z],mp(x,mp(y-1,z)))), f=true;
				//m=a[x][y-1][z], next=mp(x,mp(y-1,z)), f=true;
				isActive[x][y-1][z]=false;
			}
			if(y<n-1)
			{
				if(isActive[x][y+1][z] && a[x][y+1][z]>=m)
				v.pb(mp(a[x][y+1][z],mp(x,mp(y+1,z)))), f=true;
				//m=a[x][y+1][z], next=mp(x,mp(y+1,z)), f=true;
				isActive[x][y+1][z]=false;
			}
			if(z>0)
			{
				if(isActive[x][y][z-1] && a[x][y][z-1]>=m)
				v.pb(mp(a[x][y][z-1],mp(x,mp(y,z-1)))), f=true;
				//m=a[x][y][z-1], next=mp(x,mp(y,z-1)), f=true;
				isActive[x][y][z-1]=false;
			}
			if(z<n-1)
			{
				if(isActive[x][y][z+1] && a[x][y][z+1]>=m)
				v.pb(mp(a[x][y][z+1],mp(x,mp(y,z+1)))), f=true;
				//m=a[x][y][z], next=mp(x,mp(y,z+1)), f=true;
				isActive[x][y][z+1]=false;
			}
			if(!f)
				break;
			sort(v.begin(),v.end());
			ll qwe=rand()%(v.size());
			m=v[qwe].first, next=v[qwe].second;
			cost+=m;
			temp.pb(next);
			prev=next;
		}
		m=0; s=0; idx=-1;
		rep(i,0,temp.size())
		{
			s+=a[temp[i].first][temp[i].second.first][temp[i].second.second];
			if(s>cost)
				cost=s, idx=i;
		}
		if(idx>=0)
			temp.erase(temp.begin()+idx+1,temp.end());

		if(cost>num)
			num=cost, ans=temp;
		//printf("%lld %d\n",cost,(int)(ans.size()));
	}
}
int main()
{
	ll t,n,p;
	scll(t);
	srand(time(NULL));
	while(t--)
	{
		scll(n);
		rep(k,0,n)
		rep(j,0,n)
		{
			isActive[j][k].set();
			rep(i,0,n)
			scll(a[i][j][k]);
		}
		modified_dijkstra(n);
		p=ans.size();
		prll(p);
		rep(i,0,p)
		printf("%lld %lld %lld\n",ans[i].first+1,ans[i].second.first+1,ans[i].second.second+1);
	}
	return 0;
} 