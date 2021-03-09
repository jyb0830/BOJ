//
//  increasing_subsequence.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/09.
//  acmicpc.net/problem/11053

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n], dp[n];
    
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        dp[i]=1;
    }
    
    int max_num=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
        max_num=max(max_num, dp[i]);
    }
    
    cout<<max_num<<"\n";
    
    return 0;
}
