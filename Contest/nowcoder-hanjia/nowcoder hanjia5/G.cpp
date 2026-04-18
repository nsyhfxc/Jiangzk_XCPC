#include<bits/stdc++.h>
using namespace std;

int solve(int status, char op) {
    switch (op) {
        case '0':
            if (status == 0) return 3;
            if (status == 1) return 2;
            if (status == 2) return 1;
            if (status == 3) return 0;
            break;
        case '1':
            if (status == 1) return 3;
            if (status == 3) return 1;
            return status;
        case '2':
            if (status == 0) return 1;
            if (status == 1) return 0;
            if (status == 2) return 3;
            if (status == 3) return 2;
            break;
        case '3':
            if (status == 0) return 2;
            if (status == 2) return 0;
            return status;
        case '4':
            return (status + 1) % 4;
        case '5':
            return (status + 3) % 4;
        default:
            break;
    }
    return status;
}

int main() {
    string str = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";
    int status = 0;
    string res;
    for (const char &op: str) {
        status = solve(status, op);
        res += to_string(status);
    }
    cout << res << endl;
    return 0;
}
