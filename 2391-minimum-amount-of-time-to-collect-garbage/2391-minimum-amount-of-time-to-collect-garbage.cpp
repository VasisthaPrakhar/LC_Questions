class Solution {
public:
    int garbageCollection(vector<string>& arr, vector<int>& t) {
        int n=arr.size();
        int a=-1,b=-1,c=-1;
        vector<map<char,int>>v(n);
        for(int i=0;i<n;i++){
            map<char,int>temp;
            for(auto x:arr[i]){
                if(x=='G'){
                    a=i;
                }
                if(x=='M'){
                    b=i;
                }
                if(x=='P'){
                    c=i;
                }
                temp[x]++;
            }
            v[i]=temp;
        }
        int s1=0,s2=0,s3=0;
        for(int i=0;i<n;i++){
            int temp=0;
            if(i!=0){
                temp=t[i-1];
            }
            if(a>=i){
                s1+=v[i]['G']+temp;
            }
            if(b>=i){
                s2+=v[i]['M']+temp;
            }
            if(c>=i){
                s3+=v[i]['P']+temp;
            }
        }
        return s1+s2+s3;
    }
};