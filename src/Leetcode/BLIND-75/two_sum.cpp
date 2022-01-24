class Solution {
public:
    /*
        1. make a map
        2. check if target-current_num exists in map, then current+map_val == target and we are done.
        3. else insert the current in the map 
        4. repeat
        -- Time complexity - O(n*log(n))
    */
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

