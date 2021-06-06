//Problem : https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> temp_res;
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<int> v;
        int left, right, sum, req_sum;
        for(int i=0;i<n-2;i++){
            req_sum = -nums[i];

            left = i+1;
            right = n-1;
            while(left<right){
                sum = nums[left]+nums[right];
                if( sum == req_sum){
                    v = {nums[i], nums[left], nums[right]};
                    temp_res.insert(v);
                    left++;
                    right--;
                }
                else if(sum<req_sum){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        for(auto it = temp_res.begin(); it!= temp_res.end(); it++){
            res.push_back(*it);
        }
        return res;
    }
};