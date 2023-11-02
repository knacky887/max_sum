#ifndef FIND_MAX_OPTIMIZED_H
#define FIND_MAX_OPTIMIZED_H

#include <stdexcept>
#include <vector>

#define MINIMUM_SIZE 4
#define INT_MINIMUM (-1100000000)

namespace utils{
    int find_max(const std::vector<int>& nums) {
        auto n = nums.size();
        if (n < MINIMUM_SIZE){
            throw std::invalid_argument("utils::find_max: std::vector's size must be at least 4");
        }
        std::vector<int> pre_maximum(n, INT_MINIMUM); 
        std::vector<int> post_maximum(n, INT_MINIMUM);
        pre_maximum.shrink_to_fit();
        post_maximum.shrink_to_fit();

        int minimum{nums[0]}; 
        int maximum{nums[n-1]};
        int max_sum=INT_MINIMUM;
        int current_result{};

        size_t k=1, j = n-2;
        for(; j >=1 || k < n-1; k++, j--){
            current_result = nums[k]-minimum;
            pre_maximum[k]=std::max(pre_maximum[k-1], current_result);
            minimum=std::min(minimum,nums[k]);

            current_result = maximum-nums[j];
            post_maximum[j]=std::max(post_maximum[j+1] ,current_result);
            maximum=std::max(maximum,nums[j]);
        }

        for(size_t i=1;i<n-1;i++){
            current_result = pre_maximum[i]+post_maximum[i+1];
            max_sum=std::max(max_sum, pre_maximum[i]+post_maximum[i+1]);    
        }

        return max_sum;
    }
}

#endif //FIND_MAX_OPTIMIZED_H
    