# include<bits/stdc++.h>
using namespace std;

void DNFSort(int arr[], int n){
    int low=0,mid=0,high=n-1;
    while(mid<high){
        if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
        }
        else if(arr[mid]==2){
            swap(arr[high],arr[mid]);
            high--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[10] ={1,1,2,0,0,1,2,2,1,0};
    DNFSort(arr,10);
    
    return 0;
}