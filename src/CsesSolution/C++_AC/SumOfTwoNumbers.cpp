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
        long long target;
        in >> n >> target;
        vector<long long> nums;
        for (size_t i = 0; i < n; i++) {
            long long val;
            in >> val;
            nums.push_back(val);
        }
       map<int,int> m;
       vector<int> ans;
       for(int i=0; i<nums.size();i++){
           auto c = m.find(target-nums[i]);
           if(c == m.end()){
               m.insert(make_pair(nums[i], i+1));
           }
           else{
               ans.push_back(c->second);
               ans.push_back(i+1);
               break;
           }
       }
       if (ans.size() == 0)
           out << "IMPOSSIBLE" << endl;
       else
        out << ans[0] << " " << ans[1] << endl;
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
 