#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
#define MOD 998244353

void solve() {
    //int n,m;
    //cin >> n >> m;
    vector<vector<int> > arr(3, vector<int>(3));
    set<int> st;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
            st.insert(arr[i][j]);
        }
    }
    set<int> ans;
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += arr[i][j];
        }
        ans.insert(sum);
    }
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += arr[i][i];
    }
    ans.insert(sum);

    cout << ((ans.size() == 1 && st.size() == 9) ? "Yes" : "No") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
