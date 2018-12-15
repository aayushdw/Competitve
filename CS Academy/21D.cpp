#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int kNotFound = -1;

string Solve(int n, int d) {
    vector<int> father(n, kNotFound);
    vector<int> letter(n, kNotFound);

    father[d % n] = 0;
    letter[d % n] = d;

    queue<int> current_bfs_level;
    current_bfs_level.push(d % n);

    while (father[0] == kNotFound) {
        int itr = current_bfs_level.front();
        current_bfs_level.pop();

        for (auto digit : {0, d}) {
            int next = (itr * 10 + digit) % n;
            if (father[next] == kNotFound) {
                letter[next] = digit;
                father[next] = itr;
                current_bfs_level.push(next);
            }
        }
    }

    string number = "";
    int l = 0;
    
    do {
        number += '0' + letter[l];
        l = father[l];
    } while (l != 0);

    reverse(number.begin(), number.end());
    return number;
}

int main() {
    int n, d;
    cin >> n >> d;

    cout << Solve(n, d) << '\n';
    return 0;
}
