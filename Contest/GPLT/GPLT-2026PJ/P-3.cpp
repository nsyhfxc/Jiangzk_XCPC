#include<bits/stdc++.h>
using namespace std;
//10 pts
int main() {
    int h, h1, h2;
    cin >> h >> h1 >> h2;
    cout << h << endl;
    if (h < h1) {
        cout << "Bu Kan" << endl;
    } else if (h >= h1 && h < h2) {
        cout << "Zhe Gua Bao Shu Ma" << endl;
    } else cout << "Chi Gua" << endl;
    return 0;
}
