//
//  longest_common_subsequence.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/07.
//  acmicpc.net/problem/9251

#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1, s2;
    
    cin>>s1;
    cin>>s2;
    
    int size_1=(int)s1.size();
    int size_2=(int)s2.size();
    
    int memo[size_2+1][size_1+1];
    
    for(int i=0;i<size_2+1;i++) memo[i][0]=0;
    for(int i=0;i<size_1+1;i++) memo[0][i]=0;
    
    int max_num=0;
    for(int i=1;i<size_2+1;i++){
        for(int j=1;j<size_1+1;j++){
            if(s2[i-1]==s1[j-1]) memo[i][j]=memo[i-1][j-1]+1;
            
            else{
                memo[i][j]=max(memo[i-1][j], memo[i][j-1]);
            }
            max_num=max(max_num, memo[i][j]);
        }
    }
    cout<<max_num<<"\n";
}
