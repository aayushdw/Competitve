#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prl(x) printf("%ld",x)
#define prll(x) printf("%lld\n",x)
#define ll long long int
#define rep(i,x,y) for(int i=x;i<y;i++)
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
#define MAX 100000+5
#define MOD 1000000007
using namespace std;
vector< pair < int,pair< int,int > > > event;
vector< pair < int,int > > hline;
int line[MAX][3]={0},tree[4*MAX][2]={0},lazy[4*MAX]={0},ans[MAX]={0};
map< ii,int > vp,hp;
typeof(hp.begin()) it;
void pointCheck(int start, int end, int idx, int x, ii p)
{
	if(p.first<hline[start].first || p.first>hline[end].first)
		return;
	if(start==end)
	{
		int l=hline[start].second;
		if(tree[idx][0] && (line[l][1]==x || line[l][2]==x))
		{
 
			lazy[idx]--;
			ans[p.second]--;
 
		}
		return;
	}
	int mid=(start+end)/2;
	if(tree[2*idx+1][1])
		pointCheck(start,mid,2*idx+1,x,p);
	else if(tree[2*idx+2][1])
		pointCheck(mid+1,end,2*idx+2,x,p);
	return;
}
void rangeUpdate(int start, int end, int idx, int qs, int qe,int p)
{
	if(qe<hline[start].first || qs>hline[end].first)
		return;
	if(qs<=hline[start].first && qe>=hline[end].first)	//check
	{
		lazy[idx]+=1;
		ans[p]+=tree[idx][1];
		return;
	}
	int mid=(start+end)/2;
	rangeUpdate(start,mid,2*idx+1,qs,qe,p);
	rangeUpdate(mid+1,end,2*idx+2,qs,qe,p);
}
void activate(int start,int end,int idx,ii p)
{
	if(hline[start]>p || hline[end]<p)
		return;
	tree[idx][1]++;
	if(start==end)
	{
		tree[idx][0]=1;
		lazy[idx]=0;
		return;
	}
	lazy[2*idx+1]+=lazy[idx];
	lazy[2*idx+2]+=lazy[idx];
	lazy[idx]=0;
	int mid=(start+end)/2;
	activate(start,mid,2*idx+1,p);
	activate(mid+1,end,2*idx+2,p);
}
void deactivate(int start,int end, int idx,ii p)
{
	if(hline[start]>p || hline[end]<p)
		return;
	if(start==end)
	{
		ans[p.second]+=lazy[idx];
		tree[idx][1]=0;
		tree[idx][0]=0;
		return;
	}
	tree[idx][1]--;
	lazy[2*idx+1]+=lazy[idx];
	lazy[2*idx+2]+=lazy[idx];
	lazy[idx]=0;
	int mid=(start+end)/2;
	deactivate(start,mid,2*idx+1,p);
	deactivate(mid+1,end,2*idx+2,p);
}
void make_tree(int start, int end, int idx)
{
	if(start>end)
		return;
	tree[idx][0]=tree[idx][1]=lazy[idx]=0;
	if(start==end)
	{
		tree[idx][0]=tree[idx][1]=lazy[idx]=0;
		return;
	}
	int mid=(start+end)/2;
	make_tree(start,mid,2*idx+1);
	make_tree(mid+1,end,2*idx+2);
}
int main()
{
	int n,x1,x2,y1,y2,lineNum;
	sc(n);
	rep(i,0,n)
	{
		sc(x1); sc(y1); sc(x2); sc(y2);
		if(x1==x2)
		{
			line[i][0]=x1, line[i][1]=min(y1,y2), line[i][2]=max(y1,y2);
			event.pb(mp(x1,mp(1,i)));
			//vp.insert(mp(mp(x1,y1),i));
			//vp.insert(mp(mp(x2,y2),i));
		}
		if(y1==y2)
		{
			line[i][0]=y1, line[i][1]=min(x1,x2), line[i][2]=max(x1,x2);
			event.pb(mp(line[i][1],mp(0,i)));
			event.pb(mp(line[i][2],mp(2,i)));
			hline.pb(mp(y1,i));
			hp.insert(mp(mp(x1,y1),i));
			hp.insert(mp(mp(x2,y2),i));
		}
 
	}
	sort(event.begin(),event.end());
	sort(hline.begin(),hline.end());
	int hsize=hline.size()-1;
    /*
	rep(i,0,event.size())
	printf("%d %d %d\n",event[i].first,event[i].second.first,event[i].second.second);
	printf("\n");
    */
	make_tree(0,hsize,0);
	rep(i,0,event.size())
	{
		lineNum=event[i].second.second;
		if(event[i].second.first==0)
			activate(0,hsize,0,mp(line[lineNum][0],lineNum));
		else if(event[i].second.first==1)
		{
			rangeUpdate(0,hsize,0,line[lineNum][1],line[lineNum][2],lineNum);
			pointCheck(0,hsize,0,line[lineNum][0],mp(line[lineNum][1],lineNum));
			pointCheck(0,hsize,0,line[lineNum][0],mp(line[lineNum][2],lineNum));
			/*it=hp.find(mp(line[lineNum][0],line[lineNum][1]));
			if(it!=hp.end())
			{
				ans[it->second]--, ans[lineNum]--;
				//printf("%d %d\n",it->second+1,lineNum+1);
			}
			it=hp.find(mp(line[lineNum][0],line[lineNum][2]));
			if(it!=hp.end())
			{
				ans[it->second]--, ans[lineNum]--;
				//printf("%d %d\t%d %d\n",it->second+1,lineNum+1,ans[it->second],ans[lineNum]);
			}*/
		}
		else
			deactivate(0,hsize,0,mp(line[lineNum][0],lineNum));
		/*rep(i,0,10)
		printf("%2d",i);
		printf("\n");
		rep(i,0,10)
		printf("%2d",tree[i][0]);
		printf("\n");
		rep(i,0,10)
		printf("%2d",tree[i][1]);
		printf("\n");
		rep(i,0,10)
		printf("%2d",lazy[i]);
		printf("\n");
		rep(i,0,10)
		printf("%2d",ans[i]);
		printf("\n\n");*/
	}
	ll total=0;
	rep(i,0,n)
	total+=ans[i];
	total/=2;
	prll(total);
	rep(i,0,n)
	printf("%d ",ans[i]);
}  