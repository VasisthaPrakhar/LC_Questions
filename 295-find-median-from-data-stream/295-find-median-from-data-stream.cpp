class MedianFinder {
private:
    priority_queue<int>pq_max;
    priority_queue<int,vector<int>,greater<int>>pq_min;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(pq_max.empty()){
            pq_max.push(num);
            return;
        }
        if(num>pq_max.top()){
            pq_min.push(num);
        }else{
            pq_max.push(num);
        }
        int a=pq_min.size();
        int b=pq_max.size();
        if((b-a) > 1){
            pq_min.push(pq_max.top());
            pq_max.pop();
        }
        if((a-b) > 1){
            pq_max.push(pq_min.top());
            pq_min.pop();
        }
        
    }
    
    double findMedian() {
        //cout<<pq_min.size()<<" "<<pq_max.size()<<endl;
        if(pq_min.size()>pq_max.size()){
            return (double)pq_min.top();
        }else if(pq_max.size()>pq_min.size()){
            return (double)pq_max.top();
        }else{
            double a=pq_max.top();
            double b=pq_min.top();
            return (a+b)/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */