#include <bits/stdc++.h>

//recursive method -- to evaluate the matrix chain maultiplication
int cost_calculator(int arr[], int start_index, int end_index) {
    if (start_index == end_index) {
        return 0;
    }
    int res = INT_MAX;
    int temp;
    for (int k = start_index; k < end_index; k++) {
        temp = cost_calculator(arr, start_index, k) +
               cost_calculator(arr, k+1, end_index) +
               arr[start_index-1] * arr[k] *arr[end_index];
        if(res > temp)
            res = temp;
    }
    return res;
}


int main(int argc, char const *argv[]) {
    int matrix_cnt;
    std::cin >> matrix_cnt;
    int arr[matrix_cnt];
    for (size_t i = 0; i < matrix_cnt; i++) {
        std::cin >> arr[i];
    }
    int res = cost_calculator(arr, 1, matrix_cnt-1);
    std::cout << res << std::endl;
    
    return 0;
}
