class Solution {
public:
    int getLastMoment(int n, vector<int>& l, vector<int>& r) {
        vector<int>right=r,left=l;
        if(right.size()==0){
                right.push_back(n);
        }
        if(left.size()==0){
            left.push_back(0);
        }
        int mi=*min_element(right.begin(),right.end());
        int ma=*max_element(left.begin(),left.end());
       
        if(ma>(n-mi)){
            return ma;
        }
        else{
            return (n-mi);
        }
    }
};