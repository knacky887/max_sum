#ifndef FIND_MAX_H
#define FIND_MAX_H
#include <stdexcept>
#include <vector>

#define INT_MINIMUM (-1100000000)
#define MINIMUM_SIZE 4

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

        for(size_t k=1;k<n-1;k++){
            current_result = nums[k]-minimum;
            pre_maximum[k]=std::max(pre_maximum[k-1], current_result);
            minimum=std::min(minimum,nums[k]);
        }
        
        for(size_t j=n-2;j>=1;j--){
            current_result = maximum-nums[j];
            post_maximum[j]=std::max(post_maximum[j+1], current_result);
            maximum=std::max(maximum,nums[j]);
        }

        for(size_t i=1;i<n-1;i++){
            current_result = pre_maximum[i]+post_maximum[i+1];
            max_sum=std::max(max_sum, pre_maximum[i]+post_maximum[i+1]);    
        }

        return max_sum;
    }
}

#endif //FIND_MAX_H
    