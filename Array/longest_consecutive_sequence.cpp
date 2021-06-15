//Problem : https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums_set.insert(nums[i]);
        }
        
        int max_seq_len = 0;
        
        for(auto it = nums_set.begin(); it!=nums_set.end(); it++){
            if(nums_set.find(*it-1) == nums_set.end()){
                int current_num = *it;
                int seq_len = 1;
                
                while(nums_set.find(current_num+1) != nums_set.end()){
                    seq_len++;
                    current_num++;
                }
                max_seq_len = max(max_seq_len, seq_len);
            }
        }
        return max_seq_len;
    }
};

//Time Complexity : ϴ(n)
//Space Complexity : O(n)