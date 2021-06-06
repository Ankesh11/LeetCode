//Problem : https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return true;
        }
        int max_reachable = 0;
        for(int i=0;i<n;i++){
            if(i<=max_reachable){
                max_reachable = max(max_reachable, i+nums[i]);
            }
        }
        if(max_reachable>=n-1){
            return true;
        }
        else{
            return false;
        }
    }
};

//Time Complexity : O(n)
//Space Complexity : O(1)