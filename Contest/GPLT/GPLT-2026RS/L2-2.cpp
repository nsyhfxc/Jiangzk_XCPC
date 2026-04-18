#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
using u32 = unsigned long long;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    map<string, char>mp;
    for(int i = 1; i <= n; i++) {
        string str;
        char ch;
        cin >> str >> ch;
        mp[str] = ch;
    }
    int m;
    queue<int>ans;
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        int cnt = 0;
        for(int j = 1; j <= k; j++) {
            string temp;
            cin >> temp;
            if(mp[temp] == 'i') {
                cnt++;
            }
        }
        if(cnt == k) {
            ans.push(i);
        }
    }
    bool first = false;
    if(ans.empty()){
    	cout << "None" << endl;
    	return;
	}
    while(!ans.empty()) {
        cout << (first ? " " : "") << ans.front();
        ans.pop();
        first = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
