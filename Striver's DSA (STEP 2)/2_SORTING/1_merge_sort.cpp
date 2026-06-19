/// MERGE SORT
/// Time Complexity: O(N logN)
/// Space Complexity: O(N) Since we need an arbitrary array as well.
/// ARRAY INPUT KRAKR MERGE SORT KR RE

#include<bits/stdc++.h>
using namespace std;zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz

void merge(int ary[] , int low , int mid , int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left<=mid  &&  right<=high){
        if(ary[left]<=ary[right]){
            temp.push_back(ary[left]);
            left++;
        }
        else{
            temp.push_back(ary[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(ary[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(ary[right]);
        right++;
    }
    for(int i=low; i<=high; i++){
        ary[i] = temp[i-low];
    }
}


void merge_sort(int ary[], int low, int high){
    if(low >= high){return;}
    
    int mid = (low+high)/2;
    merge_sort(ary,low,mid);
    merge_sort(ary,mid+1,high);
    merge(ary,low,mid,high);
}



///////////////////////////////////// 

int main(){

    int n ;
    cout << "ENTER THE NUMBER OF ELEMENTS IN THE ARRAY " ;
    cin >> n ;

    int ary[n];
    int low=0;
    int high = n-1;

    cout << "WRITE THE ELEMENTS ONE BY ONE "<< endl ;

    for(int i =0 ; i < n ;i++ )
    {
        cin>>ary[i];
    }
    
    merge_sort(ary ,  low ,  high);

    cout << "THE SORTED ARY CONTAINS " << endl;

    for(int i =0 ; i < n ;i++ )
    {
        cout<< ary[i] << " " ;
    }

    return 0;
}




