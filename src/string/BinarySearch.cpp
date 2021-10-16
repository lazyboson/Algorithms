#include <iostream>
#include <vector>
#include<iostream>


class Solution {
public:
    int searchIndex(std::vector<int>& nums, int target) {
        int start = 0; 
        int end = nums.size()-1;
        int medium = (start + end)/2;
        while(start <= end ) {
            if(target == nums[start])
                return start;
            if(target == nums[end])
                return end;
            if(target == nums[medium])
                return medium;
            if(target > nums[medium]){
                start = medium + 1;
                medium = (start + end)/2;
            }
            else{
                end = medium -1;
                medium = (start + end)/2;
            }
        }
       return -1;
    }

    int searchInsert(std::vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() -1;
        int middle = (start+end)/2;
        while(start <= end) {
             if(target == nums[start])
                return start;
            if(target == nums[end])
                return end;
            if(target == nums[middle])
                return middle;
            //reached a position where no longer search is required--we just return
            if(end-start <= 1){
                if(target > nums[start] && target < nums[end])
                    return start + 1;
                else if(target > nums[end])
                    return end + 1;
                else
                    return start;
            }
            if(target > nums[middle]){
                start = middle + 1;
                middle = (start + end)/2;
            }
            else{
                end = middle -1;
                middle = (start + end)/2;
            }
        }
        return -1;
    }
};

int main(){
    std::vector<int> nums;
    int num;
    int v_len;
    std::cin >> v_len;
    while(v_len--){
        //input must be in assecding order 
        std::cin >> num;
        nums.push_back(num);
    }
    int key;
    std::cin >> key;
    Solution sln;
    std::cout << sln.searchIndex(nums, key) << std::endl;
}