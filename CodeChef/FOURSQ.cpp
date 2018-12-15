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
#define MAX 1000000+5
#define MAXSZ 100000+5
#define SQRTMAX 1000+5
using namespace std;

vector< pair< ii , ii > > four(MAX+5);
vector< pair < int,ii > > three(MAX+5);
ll p,base[MAXSZ];
vector< pair< pll,pll > > tree(4*MAXSZ);

bitset<MAX+5> possible;

void pre(int maxval)
{

	possible.reset();
	int a,b,c,d;
	for(int i=0 ; i*i<=maxval ; i++)
	{
		a=i*i;
		for(int j=i ; a+j*j<=maxval ; j++)
		{
			b=i*i+j*j;
			for(int k=j ; b+k*k<=maxval ; k++)
			{
				three[b+k*k]=mp(i,mp(j,k));
				possible[b+k*k]=true;
			}
		}
	}

	rep(i,1,maxval+1)
	{
		a=three[i].F;
		b=three[i].S.F;
		c=three[i].S.S;
		d=0;
		while(1)
		{
			if(possible[i-d*d])
			{
				four[i]=mp(mp(d,three[i-d*d].F),mp(three[i-d*d].S.F,three[i-d*d].S.S));
				break;
			}
			d++;
		}


		//printf("%d = (%d %d %d %d)",i,four[i].F.F,four[i].F.S,four[i].S.F,four[i].S.S);

	}

	/*rep(i,0,100)
	printf("%d = (%d %d %d %d)\n",i,four[i].F.F,four[i].F.S,four[i].S.F,four[i].S.S);*/

}

ll multi(ll x,ll y)
{
	ll w=x*y-p*((ll)(double(x)*y/p+1e-3));
	while(w<0)
		w+=p;
	while(w>=p)
		w-=p;
	return w;
}

pair< pll,pll > get(pair< pll,pll > x , pair< pll,pll > y)
{
	ll x1=x.F.F , x2=x.F.S , x3 = x.S.F , x4 = x.S.S;
	ll y1=y.F.F , y2=y.F.S , y3 = y.S.F , y4 = y.S.S;

	pair< pll,pll > ret;
	
	ret.F.F=multi(x1,y1)-multi(x2,y2)-multi(x3,y3)-multi(x4,y4);
	if(ret.F.F<0)
		ret.F.F*=-1;
	ret.F.F%=p;

	ret.F.S=multi(x1,y2)+multi(x2,y1)+multi(x3,y4)-multi(x4,y3);
	if(ret.F.S<0)
		ret.F.S*=-1;
	ret.F.S%=p;


	ret.S.F=multi(x1,y3)+multi(x3,y1)+multi(x4,y2)-multi(x2,y4);
	if(ret.S.F<0)
		ret.S.F*=-1;
	ret.S.F%=p;


	ret.S.S=multi(x1,y4)+multi(x4,y1)+multi(x2,y3)-multi(x3,y2);
	if(ret.S.S<0)
		ret.S.S*=-1;
	ret.S.S%=p;
	

	return ret;
}

pair< pll,pll > query(int idx,int start,int end,int qs,int qe)
{
	if(start>end || qs>qe || start>qe || end<qs)
		return mp(mp(0ll,0ll),mp(0ll,1ll));
	if(start>=qs && end<=qe)
		return tree[idx];
	int mid=(start+end)>>1;
	return get(query(2*idx+1,start,mid,qs,qe),query(2*idx+2,mid+1,end,qs,qe));
}

void update(int idx,int start,int end,int id,int val)
{
	if(start>id || end<id)
		return;
	if(start==end)
	{
		//CHECK
		base[id]=val;
		tree[idx]=four[val];
		return;
	}
	int mid=(start+end)/2;
	update(2*idx+1,start,mid,id,val);
	update(2*idx+2,mid+1,end,id,val);
	tree[idx]=get(tree[2*idx+1],tree[2*idx+2]);
}

void build(int idx,int start,int end)
{
	if(start==end)
	{
		//CHECK
		tree[idx]=four[base[start]];
		return;
	}
	int mid=(start+end)>>1;
	build(2*idx+1,start,mid);
	build(2*idx+2,mid+1,end);
	tree[idx]=get(tree[2*idx+1],tree[2*idx+2]);
}

void print(pair< pll,pll > ans)
{
	printf("%lld %lld %lld %lld\n",ans.F.F,ans.F.S,ans.S.F,ans.S.S);
}

int main()
{
	pre(MAX);
	int t,type,n,q;
	ll x,y;
	si(t);
	pair< pll,pll > ans;
	while(t--)
	{

		rep(i,0,4*MAXSZ)
		tree[i]=mp(mp(0,0),mp(0,1));
		
		si(n); si(q); sl(p);
		rep(i,0,n)
		sl(base[i]);
		build(0,0,n-1);
		
		while(q--)
		{
			si(type); sl(x); sl(y);
			if(type==1)
			update(0,0,n-1,x-1,y);
			else
			{
				x--; y--;
				ans=query(0,0,n-1,x,y);
				printf("%lld %lld %lld %lld\n",ans.F.F,ans.F.S,ans.S.F,ans.S.S);
			}
		}
	}
	return 0;
}