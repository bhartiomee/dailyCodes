
    int minInsertions(string s) {
        string a=s;
        string b=s;
        reverse(b.begin(),b.end());
        
        int len=lps(a,b);
        return s.length()-len;
    }
    
    int lps(string a,string b){
        int n=a.length();
        int dp[n+1][n+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0)dp[i][j]=0;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }