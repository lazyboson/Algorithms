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
        map<int, int> cnt;
        int n;
        cin >> n;
        for (size_t i = 0; i < n; i++) {
            int skill;
            cin >> skill;
            cnt[skill]++;
        }
        int maxSize = 0;
        for (auto a : cnt) {
            if (a.second == 1) {
                continue;
            }
            int oneSum = 0;
            for (auto b : cnt) {
                if (b.first != a.first) {
                    oneSum++;
                }
            }
            int currentMax = 0;
            if (oneSum >= a.second)
                currentMax = a.second;
            else if (oneSum == a.second - 1)
                currentMax = a.second - 1;
            else if (oneSum + 1 <= a.second - 1)
                currentMax = oneSum + 1;
            maxSize < currentMax ? maxSize = currentMax : maxSize;
        }

        if (cnt.size() > 1 && maxSize == 0)
            cout << 1 << endl;
        else
            cout << maxSize << endl;
    }

    return 0;
}
