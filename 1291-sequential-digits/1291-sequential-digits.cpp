class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int a[8]={11,111,1111,11111,111111,1111111,11111111,111111111};
        string l=to_string(low);
        int n=l.length();
        string h=to_string(high);
        int m=h.length();
        int nl=low/(pow(10,n-1));
        int nh=high/(pow(10,m-1));
        vector<int> ans;
        long long int num=0,num1;
        for(int i=0;i<n;i++){            
            num=num*10 + (i+1);
        }
        num1=num;
        int k=n;
        while(num<=high&&k<=m){
            if(num>=low && num<=high){
                ans.push_back(num);
            }
            if(num%10==9){
                int r=num1%10;
                num1=num1*10 +(r+1);
                num=num1;
                k++;
            }
            else{
                num=num+a[k-2];
            }
            
        }
        return ans;
    }
};