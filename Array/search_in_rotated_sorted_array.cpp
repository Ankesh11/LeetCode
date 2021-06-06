//Problem : https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search_util(vector<int> &nums, int &target, int beg, int end){
        if(beg>end || beg >= nums.size() || end < 0){
            return -1;
        }
        int mid = (beg+end)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(mid-1 >=beg && nums[beg] <= nums[mid-1]){
            if(target >= nums[beg] && target <= nums[mid-1]){
                return search_util(nums, target, beg, mid-1);
            }
            else{
                return search_util(nums, target, mid+1, end);
            }
        }
        if(mid+1 <= end){
            if(target >= nums[mid+1] && target <= nums[end]){
                return search_util(nums, target, mid+1, end);
            }
            else{
                return search_util(nums, target, beg, mid-1);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return search_util(nums, target, 0, nums.size()-1);
    }
};