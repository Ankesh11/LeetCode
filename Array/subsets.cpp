//Problem : https://leetcode.com/problems/subsets/

class Solution {
public:
    void generate_subsets(vector<int>& nums, int n, int index, vector<vector<int>>& res, vector<int>& curr_res){
        if(index>=n){
            res.push_back(curr_res);
            return;
        }
        
        generate_subsets(nums, n, index+1, res, curr_res);
        curr_res.push_back(nums[index]);
        generate_subsets(nums, n, index+1, res, curr_res);
        curr_res.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr_set;
        
        generate_subsets(nums, nums.size(), 0, res, curr_set);
        return res;
    }
};

//Time Complexity : O(2^n)
//Space Complexity : O(n) - recursion call stack