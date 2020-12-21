#include <iostream>

using namespace std;


int main(){
    int N, M, Max=0;
    
    cin>>N>>M;
    int arr[N];
    
    for(int i=0;i<N;i++)
        cin>>arr[i];
        
    
    for(int i=0;i<N-2;i++)
    {
        for(int j=i+1;j<N-1;j++)
        {
            if(arr[i]+arr[j]>=M)
                continue;
            
            for(int k=j+1;k<N;k++)
            {
                int sum = arr[i]+arr[j]+arr[k];
                if(sum<Max||sum>M)
                    continue;
                else if(sum>Max && sum<=M)
                {
                    Max = sum;
                    if(sum==M)
                        break;
                }
                    
            }
        }
    }
    cout<<Max;
    return 0;
}
