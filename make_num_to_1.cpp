//
//  make_num_to_1.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/15.
//  acmicpc.net/problem/1463

#include <iostream>
using namespace std;

int main(){
    int X;
    
    int arr[1000001]={};
    
    cin>>X;
    
    for(int i=2;i<=X;i++){
        arr[i]=arr[i-1]+1;
        if(i%2==0)
            arr[i]=min(arr[i/2]+1,arr[i]);
        if(i%3==0)
            arr[i]=min(arr[i/3]+1,arr[i]);
    }
    cout<<arr[X];
    
    return 0;
}
