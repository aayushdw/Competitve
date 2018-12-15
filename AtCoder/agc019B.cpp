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
#define MAX 100000+5
using namespace std;

ll findLongestPalindromicString(string text)
{
    int N = text.length();
    if(N == 0)
        return 0;
    N = 2*N + 1; //Position count
    vi L(N); //LPS Length Array
    L[0] = 0;
    L[1] = 1;
    int C = 1; //centerPosition 
    int R = 2; //centerRightPosition
    int i = 0; //currentRightPosition
    int iMirror; //currentLeftPosition
    int expand = -1;
    int diff = -1;
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;
     
    //Uncomment it to print LPS Length array
    //printf("%d %d ", L[0], L[1]);
    for (i = 2; i < N; i++) 
    {
        //get currentLeftPosition iMirror for currentRightPosition i
        iMirror  = 2*C-i;
        //Reset expand - means no expansion required
        expand = 0;
        diff = R - i;
        //If currentRightPosition i is within centerRightPosition R
        if(diff > 0) 
        {
            if(L[iMirror] < diff) // Case 1
                L[i] = L[iMirror];
            else if(L[iMirror] == diff && i == N-1) // Case 2
                L[i] = L[iMirror];
            else if(L[iMirror] == diff && i < N-1)  // Case 3
            {
                    L[i] = L[iMirror];
                    expand = 1;  // expansion required
            }
            else if(L[iMirror] > diff)  // Case 4
            {
                L[i] = diff;
                expand = 1;  // expansion required
            }
        }
        else
        {
            L[i] = 0;
            expand = 1;  // expansion required
        }
         
        if (expand == 1)
        {
            //Attempt to expand palindrome centered at currentRightPosition i
            //Here for odd positions, we compare characters and 
            //if match then increment LPS Length by ONE
            //If even position, we just increment LPS by ONE without 
            //any character comparison
            while (((i + L[i]) < N && (i - L[i]) > 0) && 
                ( ((i + L[i] + 1) % 2 == 0) || 
                (text[(i + L[i] + 1)/2] == text[(i-L[i]-1)/2] )))
            {
                L[i]++;
            }
        }
 
        if(L[i] > maxLPSLength)  // Track maxLPSLength
        {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }
 
        // If palindrome centered at currentRightPosition i 
        // expand beyond centerRightPosition R,
        // adjust centerPosition C based on expanded palindrome.
        if (i + L[i] > R) 
        {
            C = i;
            R = i + L[i];
        }
        //Uncomment it to print LPS Length array
        //printf("%d ", L[i]);
    }
    ll ans=0;
    rep(i,0,N)
    {
    	printf("%d ", (L[i]+1)/2);
    	ans+=(L[i]+1)/2;
    }
    	cout<<endl;
    return ans;
}

int main()
{
	string T,s;
	cin>>s;
	ll n = s.size();
	/*ll t =findLongestPalindromicString(s);
	ll tot = n*(n+1)/2;
	ll ans=tot-t+1;
	prll(ans);*/
	ll a[26]={0};
	rep(i,0,n)
		a[s[i]-'a']++;
	ll ans = n*(n-1)/2+1;
	rep(i,0,26)
		ans-=((a[i]-1)*a[i])/2;
	prll(ans);
	return 0;
}