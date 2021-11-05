#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        if (n < 3) {
            cout << 0 << endl;
        } else {
            if (n % 2 == 0)
                cout << (n / 2) - 1 << endl;
            else
                cout << n / 2 << endl;
        }
    }

    return 0;
}
