#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        auto lower_index = lower_bound(nums.begin(), nums.end(), target);
        auto upper_index = upper_bound(nums.begin(), nums.end(), target);
        if(lower_index != nums.end())
             ans.push_back(lower_index - nums.begin());
        if(upper_index != nums.end())
             ans.push_back(upper_index - nums.begin()-1);
        if(ans.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};

int main(){
    vector<int> data {5,7,7,8,8,10};
    
    int target = 6;
    Solution sln;
    sln.searchRange(data, target);
}