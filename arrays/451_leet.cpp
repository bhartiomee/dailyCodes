// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/submissions/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int cnt=1;
        int end=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>end){
                cnt++;
                end=points[i][1];
            }
            else
             end=min(points[i][1],end);
        }
        return cnt;
    }
};