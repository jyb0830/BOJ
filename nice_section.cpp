//
//  nice_section.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/04.
//

#include <iostream>

using namespace std;

int main(){
    int L,n,cnt=0, min_num=0, max_num=0;
    cin>>L;
    
    int arr[L];
    for(int i=0;i<L;i++){
        cin>>arr[i];
    }
    cin>>n;
    for(int i=0;i<L-1;i++){
        for(int j=i+1;j<L;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<L;i++){
        if(n==arr[i]) break;
        if(n<arr[i]){
            min_num=(i==0)?1:arr[i-1]+1;
            max_num=arr[i]-1;
            break;
        }
    }
    if(max_num==0||min_num==0) cnt=0;
    
    else cnt+=(n-min_num)*(max_num-n+1)+(max_num-n);
    
    cout<<cnt<<"\n";
    
    return 0;
}
