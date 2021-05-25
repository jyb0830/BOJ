//
//  longest_bitonic_sequence.cpp
//  BOJ
//
//  Created by 지영본 on 2021/05/25.
//  acmicpc.net/problem/11054

#include <iostream>

using namespace std;

int arr[1001];
int memo[1001][2];      // memo[a][0] : a번째 수를 기준으로 왼쪽으로 감소하는 수의 갯수
                        // memo[a][1] : a번째 수를 기준으로 오른쪽으로 감소하는 수의 갯수



int main(){
    int N;
    
    cin>>N;
    
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        arr[i]=num;
        memo[i][0]=0;
        memo[i][1]=0;
    }
    
    for(int i=1;i<N;i++){ //memo[i][0]을 구하기 위한 dp
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                memo[i][0]=max(memo[j][0]+1, memo[i][0]);
            }
        }
    }
    for(int i=N-2;i>=0;i--){
        for(int j=N-1;j>i;j--){
            if(arr[i]>arr[j]){
                memo[i][1]=max(memo[j][1]+1, memo[i][1]);
            }
        }
    }
    
    int max_num=0;
    
    for(int i=0;i<N;i++){
        max_num=max(max_num, memo[i][0]+memo[i][1]+1);
    }
    
    
    cout<<max_num<<"\n";
    return 0;
}
