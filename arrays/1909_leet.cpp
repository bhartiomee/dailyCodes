// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int cnt=0;
        int prev=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(prev<nums[i])prev=nums[i];
           else{
             if(i==1||nums[i]>nums[i-2])
                 prev=nums[i];
                cnt++;
           }
        }
        return (cnt<2);
    }
};
