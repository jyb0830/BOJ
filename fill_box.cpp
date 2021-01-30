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
void fill_box(int l, int w, int h){
    //cout<<"l : "<<l<<",    w : "<<w<<",    h : "<<h<<",    ans : "<<ans<<"\n";
    if(ans==-1)
        return;
    
    if(l==0||w==0||h==0)
        return;
    
    for(int i=n-1;i>=0;i--){
        if(A[i]<=l && A[i]<=w && A[i]<=h && B[i]>0){
            B[i]--;
            ans++;
            fill_box(l-A[i], A[i], A[i]);
            fill_box(l, A[i], h-A[i]);
            fill_box(l, w-A[i], h);
            return;
        }
    }
    ans=-1;
}

int main(){
    int l, w, h;
    
    cin>>l>>w>>h;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i]>>B[i];
        A[i]=1<<A[i];
    }
    
    fill_box(l, w, h);
    cout<<ans<<"\n";
    return 0;
}
