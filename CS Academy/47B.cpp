#include <bits/stdc++.h>
using namespace std;
 
// Print consecutive numbers from
// last to first
void printConsecutive(int last, int first)
{
    cout << first<<" ";
    cout<<last;
}
 
void findConsecutive(int N)
{
    for (int last=1; last<N; last++)
    {
        for (int first=0; first<last; first++)
        {
            if (2*N == (last-first)*(last+first+1))
            {
                printConsecutive(last, first+1);
                return;
            }
        }
    }
    cout << "-1";
}
 
// Driver code
int main()
{
    int n;
    cin>>n;
    findConsecutive(n);
    return 0;
}