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
#define LIM 20
using namespace std;

struct Node
{
	int val;
	int num;
	Node *arr[2];
};

Node* newNode()
{
	Node* t = new Node;
	t->val=0; t->num=1;
	t->arr[0]=NULL; t->arr[1]=NULL;
}

void insert(Node* root,int pre)
{
	Node* t=root;
	for(int i=LIM;i>=0;i--)
	{
		bool v=ison(pre,i);
		if(t->arr[val]==NULL)
			t->arr[val]=newNode();
		else
		{
			t=t->arr[val];
			t->num++;
		}
	}
	t->val=pre;
}

int query(Node* root,int pre,int k)
{
	Node *t=root;
	for(int i=LIM;i>=0;i--)
	{
		bool x=ison(pre,i);
		bool y=ison(k,i);
		if(y)
		{
			if(x)
			{
				
			}
			else
			{

			}
		}
		else
		{
			if(x)
			{

			}
			else
			{
				
			}
		}
	}
}

ll solve(int a[],int n,int k)
{
	ll ans=0;
	Node* root=newNode();
	pre=a[0];
	insert(root,pre);
	rep(i,1,n)
	{
		pre^=a[i];
		ans+=query(root,pre,k);
		insert(root,pre);
	}
	return ans;
}

int main()
{
	si(t);
	while(t--)
	{
		int n,k;
		si(n); si(k);
		rep(i,0,n)
		si(a[i]);
		prll(solve(a,n,k));
	}
	return 0;
}