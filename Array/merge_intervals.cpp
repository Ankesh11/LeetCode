//Problem : https://leetcode.com/problems/merge-intervals/

bool compare(vector<int> &a, vector<int> &b){
    if(a[0]<b[0]){
        return true;
    }
    else if(a[0]==b[0]){
        return (a[1]<=b[1])?true:false;
    }
    return false;
}
class Solution {
public:
    
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        int n = intervals.size();
        vector<vector<int> > res;

        sort(intervals.begin(), intervals.end(), compare);

        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=0;i<n;i++){
            if(intervals[i][0] > end){
                res.push_back(vector<int> {start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else{
                end = intervals[i][1];
            }
        }
        res.push_back(vector<int> {start, end});
        for(int i=0;i<res.size();i++){
            cout<<res[i][0]<<" "<<res[i][1]<<endl;
        }
        return res;
    }
};

//Time Complexity : O(n*logn)
//Space Complexity : O(1)  not considering the result vector