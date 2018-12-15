#include <bits/stdc++.h>  
#define MAX 1000000
#define MAXLG 20 // ceil(log2(MAX))
using namespace std;

// suffixRank is table hold the rank of each string on each iteration  
// suffixRank[i][j] denotes rank of jth suffix at ith iteration  

// For a memory efficient code only suffixRank[2][MAX] can be used
int suffixRank[MAXLG][MAX];

struct myTuple {  
    int originalIndex;   // stores original index of suffix  
    int firstHalf;       // store rank for first half of suffix  
    int secondHalf;      // store rank for second half of suffix  
};


// function to compare two suffix in O(1)  
// first it checks whether first half chars of 'a' are equal to first half chars of b  
// if they compare second half  
// else compare decide on rank of first half  

int cmp(myTuple a, myTuple b) {  
    if(a.firstHalf == b.firstHalf) return a.secondHalf < b.secondHalf;  
    else return a.firstHalf < b.firstHalf;  
}

int main() {

    string s; cin >> s;
    int N = s.size();

    // Initialize suffix ranking on the basis of only single character
    for(int i = 0; i < N; ++i)
        suffixRank[0][i] = s[i] - 'a';

    // Create a tuple array for each suffix
    myTuple L[N];


    // Iterate log(n) times i.e. till when all the suffixes are sorted
    // 'stp' keeps the track of number of iteration
    // 'cnt' store length of suffix which is going to be compared

    // On each iteration we initialize tuple for each suffix array
    // with values computed from previous iteration

    for(int cnt = 1, stp = 1; cnt < N; cnt *= 2, ++stp) {

        for(int i = 0; i < N; ++i) {
            L[i].firstHalf = suffixRank[stp - 1][i];
            L[i].secondHalf = i + cnt < N ? suffixRank[stp - 1][i + cnt] : -1;
            L[i].originalIndex = i;
        }


        // On the basis of tuples obtained sort the tuple array

        sort(L, L + N, cmp);


        // Initialize rank for rank 0 suffix after sorting to its original index
        // in suffixRank array

        suffixRank[stp][L[0].originalIndex] = 0;

        for(int i = 1, currRank = 0; i < N; ++i) {

            // compare ith ranked suffix ( after sorting ) to (i - 1)th ranked suffix
            // if they are equal till now assign same rank to ith as that of (i - 1)th
            // else rank for ith will be currRank ( i.e. rank of (i - 1)th ) plus 1, i.e ( currRank + 1 )

            if(L[i - 1].firstHalf != L[i].firstHalf || L[i - 1].secondHalf != L[i].secondHalf)
                ++currRank;

            suffixRank[stp][L[i].originalIndex] = currRank;
        }

    }

    // Print suffix array

    for(int i = 0; i < N; ++i) cout << L[i].originalIndex << endl;

    return 0;
}
