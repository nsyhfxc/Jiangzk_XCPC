#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'

struct Test {
    string time;
    int index;
    int score;
};

void solve() {
    int n, m;
    cin >> n >> m;
    cin.ignore();
    vector<Test> arr(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        string str;
        getline(cin, str);
        stringstream ss(str);
        string token;
        vector<string> temp;
        while (getline(ss, token, ' ')) {
            if (!token.empty()) {
                temp.push_back(token);
            }
        }
        arr[i].time = temp[0] + " " + temp[1];
        arr[i].index = stoi(temp[2]);
        arr[i].score = stoi(temp[3]);
        int index = arr[i].index;
        int score = arr[i].score;
        if (mp.count(index)) {
            if (mp[index] < score) {
                mp[index] = score;
            }
        } else mp[index] = score;
    }
    set<int> used;
    for (int i = 1; i <= n; i++) {
        if (mp[arr[i].index] == arr[i].score && !used.count(arr[i].index)) {
            cout << arr[i].time << " " << arr[i].index << " " << arr[i].score << endl;
            used.insert(arr[i].index);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
