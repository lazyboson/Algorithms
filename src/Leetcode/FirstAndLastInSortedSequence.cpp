#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> ans;
        if (nums.size() == 0) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int first = 0;
        int last = nums.size() - 1;
        int first_instance = -1;
        while (first <= last) {
            int middle = (first + last) / 2;
            if (nums[middle] == target) {
                first_instance = middle;
            }
            if (nums[middle] > target) {
                last = middle - 1;
            } else
                first = middle + 1;
        }
        // if no such key exists in the array -- just returning -1
        if (first_instance == -1) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        // first pos of lower element
        bool hasProgressed = false;
        for (size_t i = first_instance - 1; i >= 0; i--) {
            hasProgressed = true;
            if (nums[i] == target && i == 0) {
                ans.push_back(i);
                break;
            } else if (nums[i] == target) {
                continue;
            } else {
                ans.push_back(i + 1);
                break;
            }
        }
        if (!hasProgressed)
            ans.push_back(first_instance);

        // last pos of target
        bool hasProgressedNext = false;
        for (size_t i = first_instance + 1; i < nums.size(); i++) {
            hasProgressedNext = true;
            if (nums[i] == target && i == nums.size() - 1) {
                ans.push_back(i);
                break;
            } else if (nums[i] == target) {
                continue;
            } else {
                ans.push_back(i - 1);
                break;
            }
        }
        if (!hasProgressedNext)
            ans.push_back(first_instance);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums;
    int size, target;
    cin >> size >> target;
    for (size_t i = 0; i < size; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    Solution sln;
    auto ans = sln.searchRange(nums, target);
    for (auto const &a : ans) {
        cout << a << endl;
    }
    return 0;
}
