#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> ans;
       for(int i=0; i<nums.size();i++){
           auto c = m.find(target-nums[i]);
           if(c == m.end()){
               m.insert(make_pair(nums[i], i));
           }
           else{
               ans.push_back(c->second);
               ans.push_back(i);
               return ans;
           }
       }
        return ans;
    }
};


int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //build ur data structure to call the function here --
    return 0;
}
