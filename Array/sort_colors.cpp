//Problem : https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_red = 0, count_white = 0, count_blue = 0;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count_red++;
            }
            else if(nums[i]==1){
                count_white++;
            }
            else{
                count_blue++;
            }
        }
        
        int index=0;
        while(count_red--){
            nums[index++] = 0;
        }
        
        while(count_white--){
            nums[index++] = 1;
        }
        
        while(count_blue--){
            nums[index++] = 2;
        }
    }
};

//Time Complexity : O(n)
//Space Complexity : O(1)