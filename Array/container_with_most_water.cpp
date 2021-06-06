//Problem : https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0, area=0;
        int left_index = 0;
        int right_index = height.size()-1;
        while(left_index<right_index){
            area = (right_index-left_index)*min(height[left_index], height[right_index]);
            max_area = max(area, max_area);
            
            if(height[left_index] < height[right_index]){
                left_index++;
            }
            else{
                right_index--;
            }
            
        }
        return max_area;
    }
};