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
        int n, a, b;
        cin >> n >> a >> b;
        for (int i = 0; i < n; ++i) {
            cout << char('a' + i % b);
        }
        cout << endl;
    }

    return 0;
}
