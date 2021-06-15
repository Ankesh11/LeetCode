//Problem : https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        int zero_count = 0;
        int product = 1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero_count++;
            }
            else{
                product *= nums[i];
            }
        }
        
        vector<int> res(n);
        
        for(int i=0;i<n;i++){
            if(zero_count >=2){
                res[i] = 0;
            }
            else if(zero_count==1){
                if(nums[i]==0){
                    res[i] = product;
                }
                else{
                    res[i] = 0;
                }
            }
            else{
                res[i] = product/nums[i];
            }
        }
        return res;
    }
};

//Time Complexity : O(n)
//Space Complexity : O(1);