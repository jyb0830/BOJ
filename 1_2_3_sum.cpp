////
////  1_2_3_sum.cpp
////  BOJ
////
////  Created by 지영본 on 2021/02/09.
////  acmicpc.net/problem/9095
//
//#include <iostream>
//
//using namespace std;
//
//int main(){
//    int T, n;
//    int arr[11];
//    cin>>T;
//    int ans[T];
//    arr[1]=1;
//    arr[2]=2;
//    arr[3]=4;
//    
//    for(int i=4;i<11;i++) arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
//    
//    for(int i=0;i<T;i++){
//        cin>>n;
//        ans[i]=arr[n];
//    }
//    for(int i=0;i<T;i++) cout<<ans[i]<<"\n";
//    
//    
//    return 0;
//}
