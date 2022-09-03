class Solution {
public:
    bool check_leap(int y){
        if((y%4==0 && y%100)||(y%400==0)){
            return true;
        }
        return false;
    }
    vector<int>m={31,28,31,30,31,30,31,31,30,31,30,31};
    int fun(int year,int month,int date){
        int ans=0;
        for(int i=1900;i<year;i++){
            if(check_leap(i)){
                ans+=366;
            }else{
                ans+=365;
            }
        }
        for(int i=0;i<month-1;i++){
            if(i==1 && check_leap(year)){
                ans++;
            }
            ans+=m[i];
        }
        ans+=date;
        return ans;
    }
    int daysBetweenDates(string d1, string d2) {
        int a=fun(stoi(d1.substr(0,4)),stoi(d1.substr(5,2)),stoi(d1.substr(8,2)));
        int b=fun(stoi(d2.substr(0,4)),stoi(d2.substr(5,2)),stoi(d2.substr(8,2)));
        return abs(a-b);
    }
};