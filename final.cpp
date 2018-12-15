#include <bits/stdc++.h>
 
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%lf",&x)
#define sl(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
 
#define ll long long int
#define ull unsigned long long int
#define F first
#define S second
 
#define rep(i,x,y) for(ll i=x;i<y;i++)
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
#define lb lower_bound
#define ub upper_bound
 
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define SET(a,b) memset(a,b,sizeof(a))
#define all(c) (c).begin(),(c).end() 
#define tr(i,c) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ison(x,i) (((x) >> (i)) & 1)	//checks if ith bit is on
#define set0(x,i) (x & ~(1 << i))		//set ith bit in x to be zero
#define clr(a) memset(a,0,sizeof(a))
 
#define MOD 1000000007
#define INF 4000000000000000000
#define MAX 63
using namespace std;

vl S[10],SS[10];
vl A,cumLen,cumSum;
ll dp[10][MAX][10], dpSum[10][MAX], dpCnt[10][MAX];
ll n,m,q;
ll height;

ll binarySearch( vl &a, ll key )
{
	if(a[0] > key) return -1;
	ll l = 0, r = a.size()-1;
	while(l+1<r)
	{
		ll mid = (l+r)/2;
		if(a[mid] > key )
			r = mid-1;
		else
			l = mid;
	}
	if( a[r] <= key )
		return r;
	else
		return l;
}

vl strToVec( string &s )
{
	vl v;
	rep(i,0,s.size())
		v.pb(s[i]-'0');
	return v;
}

ll findSum( ll idx, ll h, ll d = -1 )
{
	if(!idx) return 0ll;
	if(h == -1)
	{
		ll i = binarySearch(cumLen,idx);
		// prll(i);
		if( i == cumLen.size()-1 )
			return cumSum[i];
		else if( i == -1 )
			return findSum( idx, height, A[0] );
		return cumSum[i] + findSum( idx - cumLen[i], height, A[i+1] );
	}
	ll curLen = 0, i = 0, curSum = 0;
	while( i < S[d].size() )
	{
		if( curLen + dpCnt[S[d][i]][h-1] > idx )
			break;
		curLen += dpCnt[S[d][i]][h-1];
		curSum += dpSum[S[d][i]][h-1];
		i++;
	}
	// prll(h);
	// prll(i);
	// prll(curLen);
	if(i == S[d].size())
		return curSum;
	else
		return curSum + findSum( idx - curLen, h-1, S[d][i] );
}

void preCompute()
{
	clr(dp); clr(dpSum);
	rep(d,0,10)
	{
		dp[d][0][d] = 1;
		dpSum[d][0] = d;
		dpCnt[d][0] = 1;
	}
	rep(d,0,10)
		rep(h,1,MAX)
		{
			rep(i,0,10)
				rep(j,0,10)
					dp[d][h][j] += dp[d][h-1][i]*SS[i][j];
			rep(i,0,10)
			{
				dpSum[d][h] += i*dp[d][h][i];
				dpCnt[d][h] += dp[d][h][i];
			}
		}

	vl cnt(10,0);
	rep(i,0,A.size())
		cnt[A[i]]++;

	rep(h,0,MAX)
	{
		ll len = 0;
		rep(d,0,10)
			len += dpCnt[d][h]*cnt[d];
		if(len >= m)
		{
			height = h;
			break;
		}
	}

	cumLen.resize( A.size() );
	cumSum.resize( A.size() );
	cumLen[0] = dpCnt[A[0]][height];
	cumSum[0] = dpSum[A[0]][height];
	rep(i,1,n)
	{
		cumLen[i] = cumLen[i-1] + dpCnt[A[i]][height];
		cumSum[i] = cumSum[i-1] + dpSum[A[i]][height];
	}

}

int main()
{
	sl(n); sl(m); sl(q);
	string AA; cin >> AA;
	A = strToVec(AA);

	rep(i,0,10)
	{
		string t;
		cin >> t;
		S[i] = strToVec( t );
		SS[i].resize(10);
		rep(j,0,S[i].size())
			SS[i][S[i][j]]++;
	}

	preCompute();
	
	// rep(i,0,10)
	// {
	// 	printf("%lld - ",i);
	// 	rep(j,0,4)
	// 		printf("%lld ",dpSum[i][j]);
	// 	printf("\n");
	// }

	// prll( findSum( 4, -1 ) );

	while(q--)
	{
		ll l,r;
		sl(l); sl(r);
		prll( findSum(r,-1) - findSum(l-1,-1) );
	}

	return 0;
}