#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    map<int, int>mp;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        mp[x] += y;
    }
    vector<int>arr;
    for(const auto &[x,y] : mp){
    	if(y == 0){
    		arr.push_back(x);
		}
	}
	if(arr.empty()){
		cout << "NONE" << endl;
		return;
	}
	sort(arr.begin(),arr.end());
	bool flag = false;
	for(const auto &x : arr){
		cout << (flag ? " " : "") << x;
		flag = true; 
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
