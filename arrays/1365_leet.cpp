https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        int rep=0;
        vector<int>tmp(n),ans(n);
        for(int i=0;i<n;i++){
            tmp[i]=nums[i];
        }
         sort(tmp.begin(),tmp.end());
        unordered_map<int,pair<int,int>>mp;
        
        for(int i=0;i<n;i++){
            mp[tmp[i]].first=i-mp[tmp[i]].second;
            mp[tmp[i]].second++;
        }
        for(int i=0;i<n;i++){
            ans[i]=mp[nums[i]].first;
        }
        
        return ans;
    }
};
//
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        
        int cnt[102]={0};
        for(int i=0;i<n;i++){
            cnt[nums[i]+1]++;
        }
        for(int i=1;i<102;i++){
            cnt[i]+=cnt[i-1];
        }
        
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=cnt[nums[i]];
        }
        return ans;
    }
};
