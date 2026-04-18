#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i32 = long long;
using u32 = unsigned long long;
bool cmp(const pair<int, int>&a, const pair<int, int>&b) {
    if(a.first != b.first) {
        return a.first < b.first;
    }
    return a.second < b.second;
}
void solve() {
    vector<pair<int, int>>arr;
    arr.push_back({95, 7});
    arr.push_back({94, 3});
    arr.push_back({95, 4});
    arr.push_back({95, 6});
	sort(arr.begin(),arr.end(),cmp);
	for(const auto &[x,y] : arr){
		cout << x << " " << y << endl;
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
