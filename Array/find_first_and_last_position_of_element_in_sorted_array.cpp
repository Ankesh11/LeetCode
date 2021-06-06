//Problem : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    int find_first(vector<int> &nums, int target){
        int pos = -1;
        int beg = 0;
        int end = nums.size()-1;
        int mid;
        while(beg<=end){
            mid = (beg+end)>>1;
            if(nums[mid]==target){
                pos = mid;
                end = mid-1;
            }
            else if(nums[mid]<target){
                beg = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return pos;
    }
    
    int find_last(vector<int> &nums, int target){
        int pos = -1;
        int beg = 0;
        int end = nums.size()-1;
        int mid;
        while(beg<=end){
            mid = (beg+end)>>1;
            if(nums[mid]==target){
                pos = mid;
                beg = mid+1;
            }
            else if(nums[mid]<target){
                beg = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return pos;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = find_first(nums, target);
        int last = find_last(nums, target);
        vector<int> res = {first, last};
        return res;
    }
};