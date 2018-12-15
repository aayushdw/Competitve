#include<bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
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
#define priority_queue pq;
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
#define MAX 1024+5
using namespace std;

int t[4*MAX][4*MAX],n;

/*
void updateY(int vy, int ly, int ry, int vx, int lx, int rx, int x, int y, int val)
{
	if(ly == ry)
		if(lx == rx)
			tree[vx][vy] = val;
		else
			tree[vx][vy] = tree[vx<<1][vy] + tree[(vx<<1)|1][vy];
	else
	{
		int my = (ly+ry)>>1;
		if(y<=my)
			updateY(vy<<1,ly,my,vx,lx,rx,x,y,val);
		else
			updateY((vy<<1)|1,my+1,ry,vx,lx,rx,x,y,val);
	}
}

void updateX(int vx, int lx, int rx, int x, int y, int val)
{
	if(lx!=rx)
	{
		int mx = (lx+rx)>>1;
		if(x <= mx)
			updateX(vx<<1,lx,mx,x,y,val);
		else
			updateX((vx<<1)|1,mx+1,rx,x,y,val);
	}
	updateY(1,0,n-1,vx,lx,rx,x,y,val);
}

int sumY(int vx, int vy, int tly, int try_, int ly, int ry)
{
	if(ly>ry)
		return 0;
	else if(ly == tly && ry == try_)
		return tree[vx][vy];
	int tmy = (tly + try_)>>1;
	return sumY(vx,vy<<1,tly,tmy,ly,min(ry,tmy)) + sumY(vx,(vy<<1)|1,tmy+1,try_,max(ly,tmy+1),ry);
}

int sumX(int vx, int tlx, int trx,int lx, int rx, int ly,int ry)
{
	if(rx<lx)
		return 0;
	else if(lx == tlx && rx == trx)
		return sumY(vx,1,0,n-1,ly,ry);
	int tmx = (trx + tlx)>>1;
	return sumX(vx<<1,tlx,tmx,lx,min(rx,tmx),ly,ry) + sumX((vx<<1)|1,tmx+1,trx,max(lx,tmx+1),rx,ly,ry);
}
*/


/*
int sum_y (int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return 0;
	if (ly == tly && try_ == ry)
		return t[vx][vy];
	int tmy = (tly + try_) / 2;
	return sum_y (vx, vy*2, tly, tmy, ly, min(ry,tmy))
		+ sum_y (vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry);
}
 
int sum_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if (lx > rx)
		return 0;
	if (lx == tlx && trx == rx)
		return sum_y (vx, 1, 0, n-1, ly, ry);
	int tmx = (tlx + trx) / 2;
	return sum_x (vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry)
		+ sum_x (vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry);
}

void update_y (int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
	if (ly == ry) {
		if (lx == rx)
			t[vx][vy] = new_val;
		else
			t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
	}
	else {
		int my = (ly + ry) / 2;
		if (y <= my)
			update_y (vx, lx, rx, vy*2, ly, my, x, y, new_val);
		else
			update_y (vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
		t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
	}
}
 
void update_x (int vx, int lx, int rx, int x, int y, int new_val) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		if (x <= mx)
			update_x (vx*2, lx, mx, x, y, new_val);
		else
			update_x (vx*2+1, mx+1, rx, x, y, new_val);
	}
	update_y (vx, lx, rx, 1, 0, n-1, x, y, new_val);
}
*/



void update(int x , int y , int val){
    int y1;
    while (x <= max_x){
        y1 = y;
        while (y1 <= max_y){
            tree[x][y1] += val;
            y1 += (y1 & -y1); 
        }
        x += (x & -x); 
    }
}

int main()
{
	int T;
	si(T);
	while(T--)
	{
		clr(t);
		//clr(a);
		si(n);
		string s;
		while(1)
		{
			cin>>s;
			if(s=="SET")
			{
				int x,y,val;
				si(x); si(y);
				si(val);
				update_x(1,0,n-1,x,y,val);
			}
			else if(s=="SUM")
			{
				int x1,y1,x2,y2;
				si(x1); si(y1);
				si(x2); si(y2);
				pr(sum_x(1,0,n-1,x1,x2,y1,y2));
			}
			else
				break;
		}
	}
	return 0;
}