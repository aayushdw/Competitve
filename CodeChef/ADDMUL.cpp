#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define prll(x) printf("%lld\n",x)
#define pr(x) printf("%d\n",x)
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid
#define clrgt rgt,mid+1,ed
#define MOD 1000000007
 
vector<int> tree(400005);
vector<int> add_lazy(400005);
vector<int> mul_lazy(400005,1);
vector<bool> clearlazy(400005);
vector<int> vec(100005);
int n,q,l,r,query;
int new_val;
 
inline void lazy_prop(int& idx,int& st,int& ed){
	if(clearlazy[idx]==1){
		tree[idx]=(((ll)add_lazy[idx])*(ed-st+1))%MOD;
		if(st!=ed){
			clearlazy[lft]=clearlazy[rgt]=1;
			add_lazy[lft]=add_lazy[rgt]=add_lazy[idx];
		}
		mul_lazy[idx]=1;
		add_lazy[idx]=0;
		clearlazy[idx]=0;
		return;
	}
	if(mul_lazy[idx]!=1){//multiply
		tree[idx]=(((ll)tree[idx])*mul_lazy[idx])%MOD;
		if(st!=ed){
			mul_lazy[lft]=(((ll)mul_lazy[lft])*mul_lazy[idx])%MOD;
			mul_lazy[rgt]=(((ll)mul_lazy[rgt])*mul_lazy[idx])%MOD;
			add_lazy[lft]=(((ll)add_lazy[lft])*mul_lazy[idx])%MOD;
			add_lazy[rgt]=(((ll)add_lazy[rgt])*mul_lazy[idx])%MOD;
		}
		mul_lazy[idx]=1;
	}
	if(add_lazy[idx]!=0){
		tree[idx]=(tree[idx]+(((ll)add_lazy[idx])*(ed-st+1))%MOD)%MOD;
		if(st!=ed){
			add_lazy[lft]=( add_lazy[lft] + add_lazy[idx])%MOD;
			add_lazy[rgt]=( add_lazy[rgt] + add_lazy[idx])%MOD;
		}
		add_lazy[idx]=0;
	}
}
 
inline void build(int idx,int st,int ed){
	if(st>ed) return;
	if(st==ed){
		tree[idx]=vec[st];
		return;
	}
	int mid=(st+ed)/2;
	build(cllft);
	build(clrgt);
	tree[idx]=(tree[lft]+tree[rgt])%MOD;
}
 
inline int query_tree(int idx,int st,int ed){
	if(st > ed || st > r || ed < l) return 0;
	lazy_prop(idx,st,ed);
	if(st>=l && ed<=r){
		return tree[idx];
	}
	int mid=(st+ed)/2;
	return ( query_tree(cllft) + query_tree(clrgt) )%MOD;
}
 
inline void update_add(int idx, int st, int ed) {
	lazy_prop(idx,st,ed);
	if(st > ed || st > r || ed < l) return;
	if(st>=l && ed<=r){
		tree[idx]=(tree[idx] + (((ll)(ed-st+1))*new_val)%MOD)%MOD;
		if(st!=ed){
			add_lazy[lft]=(add_lazy[lft]+new_val)%MOD;
			add_lazy[rgt]=(add_lazy[rgt]+new_val)%MOD;
		}
		return;
	}
	int mid=(st+ed)/2;
	update_add(cllft);
	update_add(clrgt);
	tree[idx]=(tree[lft]+tree[rgt])%MOD;
}
 
inline void update_mul(int idx, int st, int ed) {
	lazy_prop(idx,st,ed);
	if(st > ed || st > r || ed < l) return;
	if(st>=l && ed<=r){
		tree[idx]=(((ll)tree[idx])*new_val)%MOD;
		if(st!=ed){
			mul_lazy[lft]=(((ll)mul_lazy[lft])*new_val)%MOD;
			add_lazy[lft]=(((ll)add_lazy[lft])*new_val)%MOD;
			mul_lazy[rgt]=(((ll)mul_lazy[rgt])*new_val)%MOD;
			add_lazy[rgt]=(((ll)add_lazy[rgt])*new_val)%MOD;
		}
		return;
	}
	int mid=(st+ed)/2;
	update_mul(cllft);
	update_mul(clrgt);
	tree[idx]=(tree[lft]+tree[rgt])%MOD;
}
 
inline void update_set(int idx, int st, int ed) {
	lazy_prop(idx,st,ed);
	if(st > ed || st > r || ed < l) return;
	if(st>=l && ed<=r){
		tree[idx]=(((ll)(ed-st+1))*new_val)%MOD;
		if(st!=ed){
			clearlazy[lft]=clearlazy[rgt]=1;
			add_lazy[lft]=add_lazy[rgt]=new_val;
		}
		return;
	}
	int mid=(st+ed)/2;
	update_set(cllft);
	update_set(clrgt);
	tree[idx]=(tree[lft]+tree[rgt])%MOD;
}
 
#define gc getchar_unlocked
int rd_int(){
	char c=gc();
	while(c < '0' || c > '9'){
		c=gc();
	}
	int num=0;
	while(c >= '0' && c <= '9'){
		num=10*num+c-48;
		c=gc();
	}
	return num;
}
 
int main(){	
	n=rd_int();q=rd_int();
	for(int i=0;i<n;i++){
		vec[i]=rd_int();
	}
	build(1,0,n-1);
	while(q--){
		query=rd_int();l=rd_int();r=rd_int();
		l--;r--;
		if(query==1){
			new_val=rd_int();
			update_add(1,0,n-1);
		}
		else if(query==2){
			new_val=rd_int();
			update_mul(1,0,n-1);
		}
		else if(query==3){
			new_val=rd_int();
			update_set(1,0,n-1);
		}
		else{
			pr(query_tree(1,0,n-1));
		}
	}
	return 0;
}
