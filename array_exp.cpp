//
//  array_exp.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/26.
//  acmicpc.net/problem/10830

//  30번째 줄에서 계속 시간초과
//  원인 : 1<<exp를 하여 제곱하는 횟수 B와 비교할 때 1은 기본 자료형이므로 그 범위를 넘어가면 음수의 비트마스크가 된다. 따라서 무한루프를 돌게 되고 시간초과가 발생했다.
//  해결 : 30번째 줄의 1<<exp와 31번째 줄의 B&(1<<exp)에서 1을 64bit 자료형으로 바꿔줘야한다. --> int64_t (1) << exp, B&(int64_t (1)<<exp)
#include <iostream>
using namespace std;

int main(){
    int N;
    int64_t B;
    cin>>N>>B;
    int arr[N][N],ans[N][N], temp[N][N];
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
            if(i==j)
                ans[i][j]=1;
            else
                ans[i][j]=0;
            temp[i][j]=0;
        }
    }
    for(int64_t exp=0;(int64_t (1)<<exp)<=B;exp++){
        if((B&(int64_t (1)<<exp))!=0){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    for(int k=0;k<N;k++){
                        temp[i][j]+=(arr[i][k]%1000)*(ans[k][j]%1000);
                    }
                }
            }
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    ans[i][j]=temp[i][j]%1000;
                    temp[i][j]=0;
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<N;k++){
                    temp[i][j]+=(arr[i][k]%1000)*(arr[k][j]%1000);
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                arr[i][j]=temp[i][j]%1000;
                temp[i][j]=0;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
