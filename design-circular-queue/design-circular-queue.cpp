class MyCircularQueue {
    vector<int>q;
    int front,rear,n;
public:
    MyCircularQueue(int k) {
        q.resize(k);
        n=k;
        rear=-1,front=-1;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }else if(front==-1){
            rear=front=0;
            q[rear]=value;
            return true;
        }else if(rear==n-1){
            rear=0;
            q[rear]=value;
            return true;
        }else{
            rear++;
            q[rear]=value;
            return true;
        }
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        else if(front==rear){
            front=rear=-1;
            return true;
        }else if(front==n-1){
            front=0;
            return true;
        }else{
            front++;
            return true;
        }
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return q[rear];
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return rear+1==front || (front==0 && rear==n-1); 
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */