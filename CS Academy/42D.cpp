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


void mergeToCountSmallerOnRight(vi &A, vi &rank, int p, int q, int r, vi &count){
	int n = r-p+1;
	int i = p;
	int j = q+1;
	int mid = q;
	int k=0;
	vi mergedRank(n);
	int smallerCount = 0;
	while(i <= mid && j <= r){
		//satisfies i<j, A[i]<A[j] -- so this is the end of smaller counts so far for A[i]. update smaller count. 
		if(A[rank[i]] < A[rank[j]]){
			count[rank[i]] += smallerCount;
			mergedRank[k++] = rank[i++];
		}
		//i<j, A[i]>=A[j] -- smaller element found for A[i], incr count
		else{
			smallerCount++;
			mergedRank[k++] = rank[j++];
		}
	}
	
	//copy leftovers from the two partitions into merge
	while(i <= mid){
		count[rank[i]] += r-q; 
		mergedRank[k++] = rank[i++];
	}
	while(j <= r){
		mergedRank[k++] = rank[j++];
	}
	
	//update rank
	//System.arraycopy(mergedRank, 0, rank, p, n);
	rep(i,0,n)
	rank[p+i] = mergedRank[i];
}

void countSmallerOnRightWithMerge(vi &A, vi &rank, int p, int r, vi &count){
	if(A.size() == 1){
		return;
	}
	
	if(p < r){
		int q = (p+r)/2;
		//sort left side and count ic
		countSmallerOnRightWithMerge(A, rank, p, q, count);
		//sort right side and count ic
		countSmallerOnRightWithMerge(A, rank, q+1, r, count);
		//merge left and right and count cross ic
		mergeToCountSmallerOnRight(A, rank, p, q, r, count);
	}
}

vector<int> countSmallerOnRightWithMerge(vi &A){
	int n = A.size();
	vi rank(n);
	vi count(n);
	
	for(int i = 0; i < n; i++){
		rank[i] = i;
	}
	
	countSmallerOnRightWithMerge(A, rank, 0, n-1, count);
	
	return count;
}

int a[MAX],l[MAX];
 
int main()
{
  int n,p;
  vi v;
  scanf("%d",&n);
  for(int i=0; i<n; i++)
  {
  	si(p);
  	v.pb(p);
  }
  reverse(v.begin(),v.end());
  vi x = countSmallerOnRightWithMerge(v);
  int ans = 0;
  rep(i,0,n)
  ans = max(ans,n-i-x[i]);
  pr(ans);
  //printf("%d ",x[i]);
  return 0;
}