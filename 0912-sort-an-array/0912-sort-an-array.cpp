class Solution {
public:

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