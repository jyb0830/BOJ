//
//  Goldbach_conjecture.cpp
//  BOJ
//
//  Created by 지영본 on 2020/12/31.
//

#include <iostream>

using namespace std;

int main(){
    int size=10001;
    bool arr[size];
    for(int i=2;i<size;i++)
        arr[i]=true;
    
    for(int i=2;i*i<=size;i++)
    {
        if(arr[i])
            for(int j=i*i;j<=size;j+=i)
                arr[j]=false;
    }
    
    int T,n;
    cin>>T;
    int ans[T][2];
    for(int i=0;i<T;i++){
        cin>>n;
        int temp=n/2;
        for(int j=0;j<n/2;j++){
            if(arr[temp-j]==true && arr[temp+j]==true){
                ans[i][0]=temp-j;
                ans[i][1]=temp+j;
                break;
            }
        }
    }
    for(int i=0;i<T;i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
    }
    return 0;
}
