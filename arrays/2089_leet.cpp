// https://leetcode.com/problems/find-target-indices-after-sorting-array/submissions/
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int small=0;
        int cnt=0;
        vector<int>ans;
        for(auto i:nums){
            if(i<target)small++;
            if(i==target)cnt++;
        }
        
        for(int i=small;i<cnt+small;i++){
            ans.push_back(i);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)
                ans.push_back(i);
            
        }
        return ans;
    }
};
