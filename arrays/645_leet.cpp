// https://leetcode.com/problems/set-mismatch/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans(2);
       int n=nums.size();
        for(int i=0;i<n;i++){
          int idx=abs(nums[i])-1;
          if(nums[idx]<0)ans[0]=abs(nums[i]);
          else{
              nums[idx]=-1*nums[idx];
          }  
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0)ans[1]=(i+1);
        }
     return ans;
    }
};
