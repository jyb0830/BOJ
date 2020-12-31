//
//  prime_number.cpp
//  BOJ
//
//  Created by 지영본 on 2020/12/31.
//  acmicpc.net/problem/1929

#include <iostream>
using namespace std;

int main(){
    
    int M,N;
    cin>>M>>N;
    
    bool arr[N+1];
    
    arr[1]=false;
    
    for(int i=2;i<N+1;i++)
        arr[i]=true;
    
    for(int i=2;i*i<=N;i++){
        if(arr[i])
            for(int j=i*i;j<=N;j+=i){
                arr[j]=false;
            }
    }
    for(int i=M;i<=N;i++)
        if(arr[i]==true)
            cout<<i<<"\n";
    
    return 0;
}
