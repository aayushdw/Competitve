#include <stdio.h>
#include<math.h>
int main(void) {
	int t;
	double d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&d);
		printf("%0.6lf\n",1-1/(3*sqrt(d/2)));
	}
	return 0;
}
