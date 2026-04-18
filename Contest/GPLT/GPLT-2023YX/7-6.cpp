#include<bits/stdc++.h>
using namespace std;
using i32 = long long;
#define endl '\n'

struct Person {
    string name;
    int age;
    int score;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Person> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].name >> arr[i].age;
        arr[i].score = 0;
    }
    while (m--) {
        int x;
        cin >> x;
        arr[x].score++;
    }
    sort(arr.begin() + 1, arr.end(), [&](const Person &a, const Person &b) {
        if (a.score != b.score) {
            return a.score > b.score;
        }
        if (a.name != b.name) {
            return a.name < b.name;
        }
        return a.age < b.age;
    });
    for (int i = 1; i <= n; i++) {
        cout << arr[i].score << " " << arr[i].name << " " << arr[i].age << endl;
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
}
