#include <stdio.h>
 
#define MAX 1000000007
 
int id[100000], sz[100000];
int getint()
{
	int p;
	scanf("%d",&p);
	return p;
}
int main()
{
	int testCases, p, q, n, m, rootCount, i;
	long long ans;
	
	//scanf("%d", &testCases);
 
	testCases = getint();
 
	while (testCases--)
	{
		ans = 1;
		//scanf("%d", &n);
		//scanf("%d", &m);
 
		n = getint();
		m = getint();
 
		rootCount = n;
 
		for (i = 0; i < n; i++)
		{
			id[i] = i;
			sz[i] = 1;
		}
 
		while(m--)
		{
			//scanf("%d", &p);
			//scanf("%d", &q);
 
			p = getint();
			q = getint();
 
			p--;
			q--;
 
			while (p != id[p])
			{
				id[p] = id[id[p]];
				p = id[p];
				printf("%d\n",p);
			}
 
			while (q != id[q])
			{
				id[q] = id[id[q]];
				q = id[q];
			}
			
 
			if (p != q)
			{
				if (sz[p] >= sz[q])
				{
					id[q] = p;
					sz[p] += sz[q];
					sz[q] = -1;
				}
 
				else
				{
					id[p] = q;
					sz[q] += sz[p];
					sz[p] = -1;
				}
 
				rootCount--;
			}
		}
 
		for (i = 0; i < n; i++)
			{
				if (sz[i] != -1)
				{
					ans = ( (ans % MAX) * 	(sz[i] % MAX) ) % MAX;
				}
			}
 
			printf("%d %lld\n", rootCount, ans % MAX);
	}
 
	return 0;
} 
