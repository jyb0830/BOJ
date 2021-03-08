//
//  bitonic.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/08.
//  acmicpc.net/problem/11054

#include <iostream>

using namespace std;

int n;
int arr[1000];
int memo[1000][2];

int bitonic(int idx, int up_down){
    int answer[n-idx-1];
    int up_cnt=0, down_cnt=0;
    for(int i=idx+1;i<n;i++){
        if(arr[idx]>arr[i]) down_cnt++;
        
        if(arr[idx]<arr[i]) up_cnt++;
    }
    if(up_down==1) {
        if(memo[idx][1]!=-1) return memo[idx][1];
        
        if(down_cnt==0){
            memo[idx][1]=1;
            return 1;
        }
    }
    else if(up_down==0){
        if(memo[idx][0]!=-1) return memo[idx][0];
        
        if(up_cnt==0){
            memo[idx][0]=1;
            return bitonic(idx, 1);
        }
    }
    
    for(int i=idx+1;i<n;i++){
        answer[i-idx-1]=0;
        if(up_down==0){
            if(arr[idx]>arr[i]) {
                answer[i-idx-1]=1 + bitonic(i, 1);
            }
            
            else if(arr[idx]<arr[i]) answer[i-idx-1]=1 + bitonic(i, 0);
        }
        else{
            if(arr[idx]>arr[i]) answer[i-idx-1]=1 + bitonic(i, 1);
        }
    }
    int max_num=0;
    for(int i=0;i<n-idx-1;i++){
        max_num=max(max_num, answer[i]);
    }
    memo[idx][up_down]=max_num;
    return max_num;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        memo[i][0]=-1;
        memo[i][1]=-1;
    }
    int max_num=0;
    for(int i=0;i<n;i++){
        max_num=max(max_num, bitonic(i, 0));
    }
    cout<<max_num;
    return 0;
}
