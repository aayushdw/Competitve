#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define sc(x) scanf("%d",&x)
#define MAX 1000005
using namespace std;
vector<int> row[MAX],col[MAX];
vector<pair<int,vector<int> > > rows(MAX),cols(MAX);
int main()
{
	int t,n,m,p,i,j,k,q,count,ma,max_el,f;
	sc(t);
	while(t--)
	{
		sc(n); sc(m); ma=0; max_el=0;
		int arr[n][m];
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			sc(arr[i][j]);
			if(arr[i][j]>max_el)
			max_el=arr[i][j];
			row[i].push_back(arr[i][j]);
			col[j].push_back(arr[i][j]);
		}
		for(i=0;i<n;i++)
		{
			sort(row[i].begin(),row[i].end());
			j=0;
			while(j<m)
			{
				count=1;
				while(j+1<m && row[i][j]==row[i][j+1])
				{
					j++;
					count++;
				}
				if(rows[row[i][j]].first<count)
				{
					rows[row[i][j]].first=count;
					rows[row[i][j]].second.clear();
					rows[row[i][j]].second.push_back(i);
				}
				else if(rows[row[i][j]].first==count)
				rows[row[i][j]].second.push_back(i);
				j++;
			}
			/*for(j=0;j<rows[i].size();j++)
			printf("%d-%d ",rows[i][j].first,rows[i][j].second);
			printf("\n");*/
		}
		for(j=0;j<m;j++)
		{
			sort(col[j].begin(),col[j].end());
			i=0;
			while(i<n)
			{
				count=1;
				while(i+1<n && col[j][i]==col[j][i+1])
				{
					i++;
					count++;
				}
				if(cols[col[j][i]].first<count)
				{
					cols[col[j][i]].first=count;
					cols[col[j][i]].second.clear();
					cols[col[j][i]].second.push_back(j);
				}
				else if(cols[col[j][i]].first==count)
				cols[col[j][i]].second.push_back(j);
				i++;
			}
			/*for(i=0;i<cols[j].size();i++)
			printf("%d-%d ",cols[j][i].first,cols[j][i].second);
			printf("\n");*/
		}
		ma=0;
		for(i=0;i<=max_el;i++)
		{
			f=0;
			for(j=0;j<rows[i].second.size();j++)
			for(k=0;k<cols[i].second.size();k++)
			if(i!=arr[rows[i].second[j]][cols[i].second[k]])
			f=1;
			q=rows[i].first+cols[i].first;
			if(!f)
			q--;
			if(q>ma)
			ma=q;
		}
		printf("%d\n",ma);
		for(i=0;i<=max_el;i++)
		{
			rows[i].first=0;
			rows[i].second.clear();
			cols[i].first=0;
			cols[i].second.clear();
		}
		for(i=0;i<n;i++)
		{
			row[i].clear();
		}
		for(j=0;j<m;j++)
		{
			col[j].clear();
		}
	}
	return 0;
}
