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
#define MAX 600000+5
using namespace std;

int a[MAX];

#define INT_SIZE 32

struct TrieNode
{
    TrieNode *arr[2];
};
 

TrieNode *newNode()
{
    TrieNode *temp = new TrieNode;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}
 
void insert(TrieNode *root, int pre_xor)
{
    TrieNode *temp = root;

    for (int i=INT_SIZE-1; i>=0; i--)
    {
        // Find current bit in given prefix
        bool val = pre_xor & (1<<i);
        printf("%d ",val);
        // Create a new node if needed
        if (temp->arr[val] == NULL)
            temp->arr[val] = newNode();
 
        temp = temp->arr[val];
    }
    cout<<endl;
}
int query(TrieNode *root, int p)
{
    TrieNode *temp = root;
    int ret=0;
    //pr(p & (1<<0));
    for (int i=INT_SIZE-1; i>=0; i--)
    {
        // Find current bit in given prefix
        bool val = p & (1<<i);
 		printf("%d ",1-val);
        val = 1-val;
        if (temp->arr[1-val]==NULL)
        {
            if(1-val)
            	ret |= (1<<i);
            return ret;
        }
        else if (temp->arr[1-val] != NULL)
        {
            if(1-val)
            	ret |= (1<<i);
            temp = temp->arr[1-val];
        }
    }
    
}


int main()
{
	int n,m;
	si(n); si(m);
	TrieNode *root = newNode();
	rep(i,0,n)
	{
		si(a[i]);
		insert(root,a[i]);
	}
	int p=0;
	while(m--)
	{
		int x;
		si(x);
		p^=x;
		pr(query(root,p));
	}
	return 0;
}