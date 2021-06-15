//Problem : https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_val = nums[0];
        int max_val = nums[0];
        int max_product = nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(min_val, max_val);
            }
            
            min_val = min(nums[i], nums[i]*min_val);
            max_val = max(nums[i], nums[i]*max_val);
            
            max_product = max(max_product, max_val);
        }
        
        return max_product;
    }
};

//Time Complexity : O(n)
//Space Complexity : O(1)