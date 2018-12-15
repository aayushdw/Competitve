#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld",x)
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
#define MAX 200000+5
using namespace std;
struct tn
{
    int o,c,b ; 
};
char X[500] ; 
tn tree[4000] ;

void build_tree(int start , int end , int node)
{
    if(start==end)
    {
        tree[node].o = 0 ; 
        tree[node].c = 0 ; 
        tree[node].b = 0 ;
        if(X[start]=='(')
            tree[node].o = 1 ; 
        else
            tree[node].c = 1 ; 
        return  ; 
    }
    int mid = (start+end)/2 ; 
    build_tree(start,mid,2*node+1) ; 
    build_tree(mid+1,end,2*node+2) ;
    
    int temp = min(tree[2*node+1].o , tree[2*node+2].c) ; 
    
    tree[node].o = tree[2*node+1].o + tree[2*node+2].o - temp ; 
    tree[node].c = tree[2*node+1].c + tree[2*node+2].c - temp ; 
    tree[node].b = tree[2*node+1].b + tree[2*node+2].b + temp ; 
    
}    

int main() {
    int t; 
    sc(t);  
    while(t--)
    {
        scanf("%s",X) ;
        int l = strlen(X) ; 
        build_tree(0,l-1,0) ; 
        printf("%d\n",tree[0].b * 2) ; 
    }
    return 0;
}