class MyCircularDeque {
private:
    int *Deque;
    int front;
    int rear;
    int k;
public:
    MyCircularDeque(int k):k(k) {
        Deque=new int[k];
        rear=front=-1;
    }
    
    bool insertFront(int value) {
       if(isFull()){
           return false;
       }
       else if(front==-1){
           front=rear=0;
       } 
       else if(front==0){
           front=k-1;
       }
       else{
           front--;
       }
       Deque[front]=value;
       return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
           return false;
       }
       else if(rear==-1){
           front=rear=0;
       } 
       else if(rear==k-1){
           rear=0;;
       }
       else{
           rear++;
       }
       Deque[rear]=value;
       return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        Deque[front]=-1;
        if(rear==front){
            rear=front=-1;
        }
        else if(front==k-1){
            front=0;
        }
        else{
            front++;
        }
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        Deque[rear]=-1;
        if(rear==front){
            rear=front=-1;
        }
        else if(rear==0){
            rear=k-1;
        }
        else{
            rear--;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty())return -1;
        return Deque[front];
    }
    
    int getRear() {
        if(isEmpty())return -1;
        return Deque[rear];
    }
    
    bool isEmpty() {
        if(front==-1){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        if((front==0 && rear==k-1)|| (rear==front-1)){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */