//
//  Square_X_num.cpp
//  BOJ
//
//  Created by 지영본 on 2020/12/31.
//  acmicpc.net/problem/1016
//  배열의 인덱스 참조 부분에서 런타임 에러 발생
#include <iostream>

using namespace std;

int main(){
    long long min_num, max_num, cnt=0;
    
    cin>>min_num>>max_num;
    
    long long size=max_num-min_num+1;
    bool arr[size];
    for(long long i=0;i<size;i++) arr[i]=true;
    
    for(long long i=2;i*i<=max_num;i++){
        long long start;
        start = (min_num%(i*i))?min_num/(i*i)+1:min_num/(i*i);
            for(long long j=i*i*start;j<=max_num;j+=(i*i)){
                long long temp = j-min_num;
                arr[temp]=false;
            }
    }
    for(long long i=0;i<size;i++){
        if(arr[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
