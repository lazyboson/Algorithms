class Solution {
public:
    
    int all_possible_paths(int last_row, int last_col, int current_down, int current_right){
        //base case of recurssion --
        if(current_down > last_row || current_right > last_col)
            return 0;
        if(current_down == last_row && current_right == last_col)
            return 1;
            return all_possible_paths(last_row, last_col, current_down+1, current_right) + all_possible_paths(last_row, last_col, current_down, current_right+1);
        }
    
    int uniquePaths(int m, int n) {
        return all_possible_paths(m-1, n-1, 0, 0);
    }
};
