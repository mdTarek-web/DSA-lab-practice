#include<bits/stdc++.h>
using namespace std;

int linear_search(int a[],int n,int item){
    for(int i=0;i<n;i++){
        if(a[i]==item)
            return i;
    }
    return -1;
}
int main(){
    int n, arr[10],item,res;
    cout<<"Enter an integer:";
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the searched item:";
    cin>>item;

    res = linear_search(arr,n,item);
    if(res<0){
        cout<<"Item not found\n";
    }
    else{
        cout<<"Item is found at index "<<res;
    }

    return 0;
}
