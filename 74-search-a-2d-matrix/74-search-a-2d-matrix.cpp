class Solution {
public:
    int lower(vector<int>& a, int t,int n){
        int beg=0,end=n-1;
        while(beg<=end){
            int mid=(beg+end)/2;
            if(a[mid]>=t){
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return beg;
    }
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int n=m.size();
        vector<int>a;
        for(int i=0;i<n;i++){
            a.push_back(m[i][0]);
        }
        int lo=lower(a,target,n);
        if(lo==0)
        if(m[lo][0]==target){
            return true;
        }
        if(lo!=0){
            if(lo<n && m[lo][0]==target){
                return true;
            }
            lo--;
            a.clear();
            int m1=m[lo].size();
            for(int i=0;i<m1;i++){
                a.push_back(m[lo][i]);
            }
            if(binary_search(a.begin(),a.end(),target)){
                return true;
            }
        }
        
        return false;
    }
};