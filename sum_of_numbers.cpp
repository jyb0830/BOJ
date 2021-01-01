//
//  sum_of_numbers.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/01.
//  acmicpc.net/problem/1644

#include <iostream>

using namespace std;

int main(){
    int N,M,cnt=0, idx=0, sum=0;
    
    cin>>N>>M;
    
    int A[N];
    for(int i=0; i<N;i++){
        cin>>A[i];
        sum+=A[i];
        while(sum>M) sum-=A[idx++];
        
        cnt+=(sum==M);
    }
    cout<<cnt<<"\n";
    
    return 0;
}
