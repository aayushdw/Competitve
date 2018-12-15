#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

const int maxn = 10000 + 1;

int N;
double R;
double X[maxn];
vector<pair<double, int> > pushed;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> N >> R;

    for (int i = 0; i < N; i++) cin >> X[i];

    for (int i = 0; i < N; i++)
    {
        double CX = X[i], CY = R;

        for (int j = pushed.size() - 1; j >= 0; j--)
        {
            if (fabs(CX - X[pushed[j].s]) <= 2 * R)
            {
                CY = pushed[j].f + sqrt(4 * R * R - fabs(CX - X[pushed[j].s]) * fabs(CX - X[pushed[j].s]));
                break;
            }
        }

        pushed.pb(mp(CY, i));
    }

    cout << fixed << setprecision(17);

    for (int i = 0; i < pushed.size(); i++) cout << pushed[i].f << " ";

    cout << endl;
    cout.flush();

    return 0;
}