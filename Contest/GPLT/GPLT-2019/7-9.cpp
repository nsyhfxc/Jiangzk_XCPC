#include<bits/stdc++.h>
using namespace std;
int dependent[10001] = {};

int main() {
    int a, b;
    cin >> a >> b;
    auto isprime = [&](int n)-> bool {
        if (n < 2) return false;
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0) return false;
        return true;
    };
    auto next_n = [&](int n)-> int {
        int res = 0;
        while (n) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    };
    vector<pair<int, int> > results;
    for (int i = a; i <= b; i++) {
        set<int> path;
        int curr = i, steps = 0;
        while (curr != 1 && !path.count(curr)) {
            path.insert(curr);
            curr = next_n(curr);
            if (curr <= b && curr >= a) dependent[curr] = 1;
            steps++;
            if (curr == 4) break;
        }
        if (curr == 1) results.emplace_back(i, steps);
    }

    bool found = false;
    for (const auto &[x,y]: results) {
        if (!dependent[x]) {
            const int score = y * (isprime(x) ? 2 : 1);
            cout << x << " " << score << endl;
            found = true;
        }
    }

    if (!found) cout << "SAD" << endl;
    return 0;
}
