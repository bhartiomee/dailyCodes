//https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n=nums.size();
     
        for(int i=1;i<n;i++){
            nums[i]=nums[i]+nums[i-1];
        }
        int ans=nums[L+M-1];
        int maxL=nums[L-1];
        int maxM=nums[M-1];
        
        for(int i=L+M;i<n;i++){
            maxL=max(maxL,nums[i-M]-nums[i-M-L]);
            maxM=max(maxM,nums[i-L]-nums[i-M-L]);
            
            ans=max(ans,max(maxL+nums[i]-nums[i-M],maxM+nums[i]-nums[i-L]));
        }
        return ans;
    }
};
