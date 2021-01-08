//
//  high_rise_building.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/09.
//  acmicpc.net/problem/1027

#include <iostream>
using namespace std;

int main(){
    int N;
    
    cin>>N;
    int height[N],max=0;
    int visible_num[N];
    for(int i=0;i<N;i++){
        cin>>height[i];
        visible_num[i]=0;
    }
    for(int i=0;i<N;i++){
        double L_slope=0, R_slope=0;
        if(i>0){
            L_slope=height[i]-height[i-1];
            visible_num[i]++;
        }
        if(i<N-1){
            R_slope=height[i+1]-height[i];
            visible_num[i]++;
        }
        for(int j=i-2;j>=0;j--){        //j번째 빌딩 기준 왼쪽에서 보이는 빌딩 탐색
            double temp=(double)(height[i]-height[j])/(i-j);
            if(temp>=L_slope)
                continue;
            else{
                L_slope=temp;
                visible_num[i]++;
            }
        }
        for(int j=i+2;j<N;j++){         //j번째 빌딩 기준 오른쪽에서 보이는 빌딩 탐색
            double temp=(double)(height[j]-height[i])/(j-i);
            if(temp<=R_slope)
                continue;
            else{
                R_slope=temp;
                visible_num[i]++;
            }
        }
        if(visible_num[i]>max)
            max=visible_num[i];
    }
    cout<<max;
    
    return 0;
}
