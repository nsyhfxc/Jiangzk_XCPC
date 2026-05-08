#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    int rating = 1000;
    int hui = 0, zi = 0, lan = 0, qing = 0, huang = 0, cheng = 0, hong = 0;
    for (int i = 1; i <= n; i++) {
        int score;
        cin >> score;
        rating += score;
        if (rating <= 699) {
            hui++;
        } else if (rating <= 1099) {
            zi++;
        } else if (rating <= 1499) {
            lan++;
        } else if (rating <= 1999) {
            qing++;
        } else if (rating <= 2399) {
            huang++;
        } else if (rating <= 2799) {
            cheng++;
        } else hong++;
    }
    cout << hui << " " << zi << " " << lan << " " << qing << " " << huang << " " << cheng << " " << hong << endl;
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
