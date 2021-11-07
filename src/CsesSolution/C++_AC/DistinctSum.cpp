#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)
 
 
class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
         int n;
        in >> n;
        set<int> s;
        for (size_t i = 0; i < n; i++) {
            int d;
            in >> d;
            s.insert(d);
        }
        out << s.size() << endl;
    }
};
 
void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}
 
 
#include <fstream>
#include <iostream>
 
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
 
    istream& in = cin;
 
 
    ostream& out = cout;
 
    solve(in, out);
    return 0;
}
 
 