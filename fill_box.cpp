//
//  fill_box.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/28.
//  acmicpc.net/problem/1493

#include <iostream>
using namespace std;
int A[20],B[20], n;
int ans=0;
bool possible=true;
void fill_box(int l, int w, int h){
    cout<<"l : "<<l<<",  w : "<<w<<",   h : "<<h<<"\n";
    int cube=0, idx=0;
    if(possible==false)
        return;
    
    if(l==0||w==0||h==0)
        return;
    
    for(int i=n-1;i>=0;i--){    //박스에 들어갈 수 있는 큐브중 가장 큰 큐브 찾기
        if(1<<A[i]<=l&&1<<A[i]<=w&&1<<A[i]<=h){
            cube=1<<A[i];
            idx=i;
            break;
        }
    }
    if((l/cube)*(w/cube)*(h/cube)>B[idx]){  //남아있는 큐브 갯수가 필요한 갯수보다 모자라면 종료
        cout<<"-1"<<"\n";
        possible=false;
        return;
    }
    ans+=(l/cube)*(w/cube)*(h/cube);
    fill_box(l%cube, cube, cube);
    fill_box(l, cube, h%cube);
    fill_box(l, w%cube, h);
    
}

int main(){
    int l, w, h;
    
    cin>>l>>w>>h;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i]>>B[i];
    }
    
    fill_box(l, w, h);
    cout<<ans<<"\n";
    return 0;
}
