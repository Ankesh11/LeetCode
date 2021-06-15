//Problem : https://leetcode.com/problems/rotate-array/solution/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        
        int count = 0;
        
        for(int start = 0; count < n; start++){
            int current = start;
            int prev = nums[start];
            do{
                int next = (current+k)%n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            }while(current!=start);
        }
    }
};

//Time Complexity : O(n)
//Space Complexity : O(1)