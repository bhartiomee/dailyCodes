https://leetcode.com/problems/add-binary/
class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1;
        int j=b.length()-1;
        
        string ans;
        int carry=0;
        while(i>=0 || j>=0){
          if(i>=0){
              carry+=a[i]-'0';
              i--;
          }
            if(j>=0){
                carry+=b[j]-'0';
                j--;
            }
           ans+=(carry%2 +'0');
            carry/=2;
        }
        if(carry==1)ans+=(carry+'0');
         reverse(ans.begin(),ans.end());
        return ans;
    }
};
