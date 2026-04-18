#include<bits/stdc++.h>
using namespace std;
using int32 = long long;

int solve(int N, int M, int K) {
    if (K == 1) {
        return N * M;
    }

    long long count = 0;
    for (int i = 0; i < N; ++i) {
        int target_rem = (K - 1 - (i % K) + K) % K;
        if (target_rem < M) {
            count += (M - 1 - target_rem) / K + 1;
        }
    }

    return count;
}
