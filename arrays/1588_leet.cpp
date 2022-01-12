// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/submissions/

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int contri= ceil((i+1)*(n-i)/2.0);
            sum+=arr[i]*contri;
        }
        return sum;
    }
};
