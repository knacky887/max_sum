#ifndef FIND_MAX_TWO_POINTERS_H
#define FIND_MAX_TWO_POINTERS_H
#include <stdexcept>
#include <vector>

#define MINIMUM_SIZE 4

namespace utils{
    int find_max(const std::vector<int>& nums){
        int n = nums.size();
        if (n < MINIMUM_SIZE){
            throw std::invalid_argument("utils::find_max: std::vector's size must be at least 4");
        }
        int j{n - 2};
        int k{1};

        int right_maximum{nums[n-1]}, left_minimum{nums[0]};
        int left{0}, right{n-1};

        int pre_result = nums[k] - nums[0]; 
        int post_result = nums[n-1] - nums[j];
       
        while(right > 1 && left < n - 1){
            right--, left++;
            if(right_maximum < nums[right]){
                right_maximum = nums[right];
            }
            else if(post_result < right_maximum - nums[right] && right > k){
                j = right;
                post_result = right_maximum - nums[right];
                left--;
                continue;
            }
            if(left_minimum > nums[left]){
                left_minimum = nums[left];
            }
            else if (pre_result < nums[left] - left_minimum && j > left){
                k = left;
                pre_result = nums[left] - left_minimum;
                right++; 
            }
        }
        return pre_result + post_result;
    }
}

#endif //FIND_MAX_TWO_POINTERS_H