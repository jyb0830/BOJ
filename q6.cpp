//
//  q6.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/07.
//

#include <iostream>

using namespace std;

int n;
int land[1024];

int development(int g_size, int idx){
    int l_cost, r_cost; //l_cost : 왼쪽을 개발했을 때의 총 이익
    if(g_size==2){
        return (land[idx]>land[idx+1])?land[idx]:land[idx+1];
    }
    
    else{
        int max_l=0, max_r=0;
        for(int i=idx;i<idx+g_size/2;i++){
            max_l=max(max_l, land[i]);
        }
        
        for(int i=idx+g_size/2;i<idx+g_size;i++){
            max_r=max(max_r, land[i]);
        }
        
        l_cost = max_l + development(g_size/2, idx+g_size/2);
        r_cost = max_r + development(g_size/2, idx);
        
        return max(l_cost, r_cost);
    }
}


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>land[i];
    }
    
    cout<<development(n, 0)<<"\n";
    
    return 0;
}
