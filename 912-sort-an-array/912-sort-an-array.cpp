class Solution {
public:
//     int fun(vector<int>&a,int s,int e){
//         int k=a[e];
//         int j=s-1;
//         for(int i=s;i<e;i++){
//             if(a[i]<k){
//                 j++;
//                 swap(a[i],a[j]);
//             }
//         }
//         swap(a[j+1],a[e]);
//         return j+1;
//     }
//     void quicksort(vector<int>&a,int s,int e){
//         if(s>=e){
//             return;
//         }
//         int pos=fun(a,s,e);
//         quicksort(a,s,pos-1);
//         quicksort(a,pos+1,e);
//     }
    void merge(vector<int>&a,int s,int e){
    int mid=(s+e)/2;
    int i=s,j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=e){
        if(a[i]<a[j]){
            temp.push_back(a[i++]);
        }else{
            temp.push_back(a[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(a[i++]);
    }
    while(j<=e){
        temp.push_back(a[j++]);
    }
    int h=0;
    for(int i=s;i<=e;i++){
        a[i]=temp[h++];
    }
}
void mergesort(vector<int>&a,int s,int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);
    merge(a,s,e);
}
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return nums;
    }
};