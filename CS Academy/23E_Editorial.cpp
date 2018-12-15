#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

typedef long long int64;

const int kMaxN = 1e4, kMaxVal = 2e5+5;

vector<int> left_nodes, right_nodes;
vector<int> vertex[kMaxN];

bool is_prime[kMaxVal];

void Init() {
    for (int i = 2; i < kMaxVal; i += 1) {
        is_prime[i] = true;
    }

    for (int i = 2; i < kMaxVal; i += 1) {
        if (not is_prime[i]) {
            continue;
        }

        for (int64 j = 1LL * i * i; j < kMaxVal; j += i) {
            is_prime[j] = false;
        }
    }
}

bool visited[kMaxN], matched[kMaxN];
int match_pair[kMaxN];

bool Match(int node) {
    visited[node] = true;

    for (auto itr : vertex[node]) {
        if (not matched[itr]) {
            matched[node] = true;
            matched[itr] = true;

            match_pair[node] = itr;
            match_pair[itr] = node;

            return true;
        }
    }

    for (auto itr : vertex[node]) {
        if (not visited[match_pair[itr]] and Match(match_pair[itr])) {
            matched[node] = true;

            match_pair[node] = itr;
            match_pair[itr] = node;

            return true;
        }
    }

    return false;
}

int main() {
    Init();
    
    int n;
    cin >> n;
    vector<int> elements(n);
    
    for (auto itr : elements) {
        cin >> itr;
        if (itr & 1) {
            left_nodes.push_back(itr);
        } else {
            right_nodes.push_back(itr);
        }
    }

    // add edges between nodes which have a prime sum
    for (int i = 0; i < (int)left_nodes.size(); i += 1) {
        for (int j = 0; j < (int)right_nodes.size(); j += 1) {
            if (not is_prime[left_nodes[i] + right_nodes[j]]) {
                continue;
            }

            int a = i;
            int b = j + left_nodes.size();
            vertex[a].push_back(b);
        }
    }
    
    // get the maximum matching
    bool ok = true;
    while (ok) {
        ok = false;

        for (int i = 0; i < (int)left_nodes.size(); i += 1) {
            visited[i] = false;
        }

        for (int i = 0; i < (int)left_nodes.size(); i += 1) {
            if (visited[i] or matched[i]) {
                continue;
            }

            if (Match(i)) {
                ok = true;
            }
        }
    }

    // the actual elements that should be erased in order to not have
    // a prime sum
    vector<int> unselected_q;
    vector<int> selected(n, 0);
    for (int i = 0; i < (int)left_nodes.size(); i += 1) {
        if (matched[i]) {
            selected[i] = true;
        } else {
            unselected_q.push_back(i);
        }
    }

    while (unselected_q.size()) {
        int node = unselected_q.back();
        unselected_q.pop_back();

        for (auto itr : vertex[node]) {
            if (not selected[itr]) {
                int oth = match_pair[itr];
                if (selected[oth]) {
                    unselected_q.push_back(oth);
                    selected[oth] = false;
                }
                selected[itr] = true;
            }
        }
    }

    // print the solution :)
    int r = 0;
    for (auto itr : selected) {
        r += itr;
    }

    cout << r << '\n';
    vector<int> v;
    for (int i = 0; i < n; i += 1) {
        if (not selected[i]) {
            continue;
        }

        if (i < (int)left_nodes.size()) {
            //cout << left_nodes[i] << ' ';
            v.pb(left_nodes[i]);
        } else {
            //cout << right_nodes[i - (int)left_nodes.size()] << ' ';
            v.pb(right_nodes[i - (int)left_nodes.size()]);
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        cout<< v[i] << ' ';

    cout << '\n';

    return 0;
}
