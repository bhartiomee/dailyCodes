#include<bits/stdc++.h>
using namespace std;
int main(){
  int i,j,sum=0;
  int k=24;
  for(i=3;i>0;i--){
    for(j=0;j<4;j++){
      if((j%2)!=0){
        sum+=k*i;
      }
      else{
        sum-=k;
      }
      k++;
    }
    sum=sum%7;
    cout<<sum;
  }
}