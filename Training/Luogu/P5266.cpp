#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    unordered_map<string,int> db;
    while (t--) {
        int n;
        string sname;
        int score;
        cin >> n;
        switch (n) {
            case 1:
                cin >> sname >> score;
                db[sname] = score;
                cout << "OK" << endl;
                break;
            case 2:
                cin >> sname;
                if (db.count(sname)) {
                    cout << db[sname] << endl;
                } else {
                    cout << "Not found" << endl;
                }
                break;
            case 3:
                cin >> sname;
                if (db.count(sname)) {
                    db.erase(sname);
                    cout << "Deleted successfully" << endl;
                } else {
                    cout << "Not found" << endl;
                }
                break;
            case 4:
                cout << db.size() << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
