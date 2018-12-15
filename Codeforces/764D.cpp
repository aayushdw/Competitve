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
#define INF 4000000000000000000
#define MAX 500000+5
using namespace std;

bitset<MAX> t;
bitset<5> col;
int ans[MAX]={0};
int yray[MAX][2]={0};
int xray[MAX][2]={0};
map< int,int > s;

vector< pair< int,ii > > event,yevent;
vi rect[MAX];

int main()
{
	bool f=true;
	typeof(s.begin()) it;
	int x1,y1,x2,y2,xs,xe,ys,ye,j,n,idx;
	si(n);
	rep(i,0,n)
	{
		si(x1); si(y1);
		si(x2); si(y2);
		xs=min(x1,x2);
		xe=max(x1,x2);
		ys=min(y1,y2);
		ye=max(y1,y2);
		event.pb(mp(xs,mp(0,i)));
		event.pb(mp(xe,mp(1,i)));
		yevent.pb(mp(ys,mp(0,i)));
		yevent.pb(mp(ye,mp(1,i)));
		yray[i][0]=ys;
		yray[i][1]=ye;
		xray[i][0]=xs;
		xray[i][1]=xe;
	}
	sort(all(event));
	sort(all(yevent));
	t.reset();
	rep(i,0,yevent.size())
	{
		idx=yevent[i].S.S;
		x1=xray[idx][0];
		x2=xray[idx][1];
		if(t[idx])
		{
			it=s.find(x1);
			if(it->S==idx)
				s.erase(it);

			it=s.find(x2);
			if(it->S==idx)
				s.erase(it);

			t[idx]=false;
		}
		else
		{
			it=s.find(x1);
			if(it==s.end())
				s.insert(mp(x1,idx));
			else
			{
				j=it->S;
				if(yray[j][1]<yray[idx][1])
				{
					s.erase(it);
					s.insert(mp(x1,idx));
				}
				if(yray[idx][0]<yray[j][1])
				{
					rect[idx].pb(j);
					rect[j].pb(idx);
				}
			}


			it=s.find(x2);
			if(it==s.end())
				s.insert(mp(x2,idx));
			else
			{
				j=it->S;
				if(yray[j][1]<=yray[idx][1])
				{
					s.erase(it);
					s.insert(mp(x2,idx));
				}
				if(yray[idx][0]<yray[j][1])
				{
					rect[idx].pb(j);
					rect[j].pb(idx);
				}
			}

			t[idx]=true;
		}
	}

	s.clear();
	t.reset();
	rep(i,0,event.size())
	{
		idx=event[i].S.S;
		y1=yray[idx][0];
		y2=yray[idx][1];
		if(t[idx])
		{
			it=s.find(y1);
			if(it->S==idx)
				s.erase(it);

			it=s.find(y2);
			if(it->S==idx)
				s.erase(it);

			t[idx]=false;
		}
		else
		{
			it=s.find(y1);
			if(it==s.end())
				s.insert(mp(y1,idx));
			else
			{
				j=it->S;
				if(xray[j][1]<xray[idx][1])
				{
					s.erase(it);
					s.insert(mp(y1,idx));
				}
				if(xray[idx][0]<xray[j][1])
				{
					rect[idx].pb(j);
					rect[j].pb(idx);
				}
			}


			it=s.find(y2);
			if(it==s.end())
				s.insert(mp(y2,idx));
			else
			{
				j=it->S;
				if(xray[j][1]<=xray[idx][1])
				{
					s.erase(it);
					s.insert(mp(y2,idx));
				}
				if(xray[idx][0]<xray[j][1])
				{
					rect[idx].pb(j);
					rect[j].pb(idx);
				}
			}

			t[idx]=true;


			col.reset();
			rep(k,0,rect[idx].size())
			col[ans[rect[idx][k]]]=true;

			rep(k,1,5)
			if(!col[k])
			{
				ans[idx]=k;
				break;
			}

			if(ans[idx]==0)
				f=false;

		}
	}
	if(!f)
		printf("NO");
	else
	{
		printf("YES");
		rep(i,0,n)
		printf("\n%d",ans[i]);
	}
	return 0;
}