#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        push_heap(arr.begin(), arr.begin() + i + 1, greater<int>());
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i)
        mp[arr[i]] = i + 1;
    cin.ignore();
    for (int i = 0; i < m; ++i) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<string> input;
        bool flag = true;
        while (ss >> s)
            input.push_back(s);
        if (input.back() == "root") {
            if (const int root = mp[stoi(input[0])]; root != 1)
                flag = false;
        } else if (input.back() == "siblings") {
            const int x = mp[stoi(input[0])];
            const int y = mp[stoi(input[2])];
            if (x / 2 != y / 2)
                flag = false;
        } else {
            const int x = mp[stoi(input[0])];
            const int y = mp[stoi(input.back())];
            if (input[input.size() - 3] == "parent" && x != y / 2)
                flag = false;
            else if (input[input.size() - 3] == "child" && x / 2 != y)
                flag = false;
        }
        if (flag)
            cout << "T\n";
        else
            cout << "F\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
