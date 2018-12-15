#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
 
#define ll long long int
#define ull unsigned long long int
#define F first
#define S second
 
#define rep(i,x,y) for(int i=x;i<y;i++)
#define ii pair<int,int> 
#define pll pair<ll,ll> 
#define vi vector<int> 
#define vvi vector< vi > 
#define vl vector<long long int>
#define vvl vector< vl >
#define vii vector< ii >
#define vvii vector< vii >
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 10000000000000000
#define MAX 32
using namespace std;
int num[MAX][MAX][MAX][MAX][2],comp[MAX][MAX][MAX][MAX];
bitset<MAX> t[MAX][MAX];
int n,c;
 
int LOG(int p)
{
	int c=0;
	while(p!=2)
		p/=2, c+=7;
	return c+7;
}

pair< vii,vii > foo(int sz,int x,int y,int z)
{
	pair< vii,vii > ret;
	ret.F.clear();
	ret.S.clear();
	//BASE CASE
	//return pair of vector of pairs (cost,value)
	if(sz==2)
	{
		int a=0;
		rep(i,0,sz)
		rep(j,0,sz)
		rep(k,0,sz)
		a+=t[x+i][y+j][z+k];
		num[x][y][z][sz][1]=a;
		num[x][y][z][sz][0]=8-a;
		if(min(a,8-a))
		{
			if(min(a,8-a)<=c)
			ret.S.pb(mp(min(a,8-a),7));
		}
		else
		{
			if(1<=c)
			ret.F.pb(mp(1,7));
		}
		if(a==0 || a==8)
			comp[x][y][z][sz]=1;
		else
			comp[x][y][z][sz]=8;
		return ret;
	}
	vector< pair< vii,vii > > v(8);
	rep(i,0,2)
	rep(j,0,2)
	rep(k,0,2)
	{
		v[4*i+2*j+k]=foo(sz/2,x+i*sz/2,y+j*sz/2,z+k*sz/2);
		comp[x][y][z][sz]+=comp[x+i*sz/2][y+j*sz/2][z+k*sz/2][sz/2];
		num[x][y][z][sz][0]+=num[x+i*sz/2][y+j*sz/2][z+k*sz/2][sz/2][0];
		num[x][y][z][sz][1]+=num[x+i*sz/2][y+j*sz/2][z+k*sz/2][sz/2][1];
	}
 
	if(num[x][y][z][sz][0]==0 || num[x][y][z][sz][1]==0)
		comp[x][y][z][sz]=1;
 
	// Optimization possible here?
	int cost,val,prev;
	int arr[8][c+1];
	clr(arr);
	rep(i,0,v[0].F.size())
		arr[0][v[0].F[i].F]=v[0].F[i].S;
	rep(i,1,8)
	{
		prev=0;
		rep(j,0,c+1)
		if(prev<arr[i-1][j])
			prev=arr[i-1][j];
		else
			arr[i][j]=prev;
		rep(j,0,c+1)
		arr[i][j]=arr[i-1][j];
		rep(j,0,v[i].F.size())
		{
			cost=v[i].F[j].F;
			val=v[i].F[j].S;
			rep(k,0,c-cost+1)
			arr[i][k+cost]=max(arr[i][k+cost],arr[i-1][k]+val);
		}
	}
	if(comp[x][y][z][sz]==1)
	{
		rep(i,1,c+1)
		arr[7][i]+=7;
		arr[7][1]=LOG(sz);
	}
	prev=0;
	rep(i,1,c+1)
	if(arr[7][i]>prev)
	{
		ret.F.pb(mp(i,arr[7][i]));
		prev=arr[7][i];
	}
 
 
 
	clr(arr);
	rep(i,0,v[0].S.size())
		arr[0][v[0].S[i].F]=v[0].S[i].S;
	rep(i,1,8)
	{
		prev=0;
		rep(j,0,c+1)
		if(prev<arr[i-1][j])
			prev=arr[i-1][j];
		else
			arr[i][j]=prev;
		rep(j,0,c+1)
		arr[i][j]=arr[i-1][j];
		rep(j,0,v[i].S.size())
		{
			cost=v[i].S[j].F;
			val=v[i].S[j].S;
			rep(k,0,c-cost+1)
			arr[i][k+cost]=max(arr[i][k+cost],arr[i-1][k]+val);
		}
	}
	// Total Cell MAnipulation
	if(num[x][y][z][sz][0]<=c && num[x][y][z][sz][0] && num[x][y][z][sz][1])
	arr[7][num[x][y][z][sz][0]]=max(arr[7][num[x][y][z][sz][0]],comp[x][y][z][sz]-1);
	if(num[x][y][z][sz][1]<=c && num[x][y][z][sz][1] && num[x][y][z][sz][0])
	arr[7][num[x][y][z][sz][1]]=max(arr[7][num[x][y][z][sz][1]],comp[x][y][z][sz]-1);
	
	prev=0;
	rep(i,1,c+1)
	if(arr[7][i]>prev)
	{
		ret.S.pb(mp(i,arr[7][i]));
		prev=arr[7][i];
	}
	
	return ret;
 
}
 
ii solve()
{
	clr(num); clr(comp);
	pair< vii,vii > v=foo(n,0,0,0);
	int compression=comp[0][0][0][n];
	int mx=0,mn=0;
	rep(i,0,v.F.size())
	mx=max(mx,v.F[i].S);
	rep(i,0,v.S.size())
	mn=max(mn,v.S[i].S);
	//printf("c=%d mn=%d mx=%d\n",compression,mn,mx);
	return mp(compression-mn,compression+mx);
}
 
int main()
{
	int p;
	si(n); si(c);
	rep(i,0,n)
	rep(j,0,n)
	{
		t[i][j].reset();
		rep(k,0,n)
		{
			si(p);
			if(p)
				t[i][j][k]=true;
		}
	}
	if(n==1)
	{
		printf("1 1");
		return 0;
	}
	else if(c==n*n*n)
	{
		printf("1 %d",c);
		return 0;
	}
	ii ans=solve();
	printf("%d %d",ans.F,ans.S);
	return 0;
} 