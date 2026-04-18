#include<bits/stdc++.h>
using namespace std;

int main() {
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    int t = rng() % 100 + 1;
    cout << t << endl;
    for (int i = 1; i <= t; i++) {
        cout << rng() % 100 + 1 << " ";
        cout << rng() % 100 + 1 << " ";
        cout << rng() % 100 + 1 << " ";
        cout << rng() % 100 + 1 << " ";
        cout << endl;
    }
    return 0;
}
