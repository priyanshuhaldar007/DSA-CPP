# include<bits/stdc++.h>
using namespace std;

void waveSort(int arr[], int n){
    for(int i=1;i<n-1;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
        if(arr[i]>arr[+1]){
            swap(arr[i],arr[i+1]);
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[7] ={1,3,4,7,5,6,2};
    waveSort(arr,7);
    
    return 0;
}