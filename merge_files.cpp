//
//  merge_files.cpp
//  BOJ
//
//  Created by 지영본 on 2021/05/27.
//  acmicpc.net/problem/11066

#include <iostream>

using namespace std;

int T, K;
int chapter[500];
int c_sum[500];
int memo[500][500];
int dp(int a, int b){ //a는 시작 chapter, b는 마지막 chapter
    if(a==b) return chapter[a];
    
    if(memo[a][b]) return memo[a][b];
    
    int sum;
    
    if(a==0) sum = c_sum[b];
    
    else sum = c_sum[b]-c_sum[a-1];
    
    int min_num=1000000000;
    
    for(int i=a;i<b;i++){
        min_num = min(min_num, dp(a,i) + dp(i+1, b) + sum);
    }
    
    memo[a][b]=min_num;
    
    return min_num;
}



int main(){
    cin>>T;
    
    int answer[T];
    
    for(int i=0;i<T;i++){
        cin>>K;
        
        for(int j=0;j<K;j++){
            cin>>chapter[j];
        }
        
        for(int j=0;j<K;j++){
            for(int k=0;k<K;k++){
                memo[j][k]=0;
            }
        }
        
        c_sum[0]=chapter[0];
        
        for(int j=1;j<K;j++){
            c_sum[j]=c_sum[j-1]+chapter[j];
        }
        
        int min_num=1000000000;
        
        for(int j=0;j<K-1;j++){
            min_num=min(min_num, dp(0,j)+dp(j+1, K-1));
        }
        answer[i]=min_num;
    }
    
    for(int i=0;i<T;i++) cout<<answer[i]<<"\n";
    
    
    return 0;
}
