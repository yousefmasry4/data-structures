#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

struct queue{
    int front,rear,size;
    unsigned capacity;
    int* arr;
};
struct queue* creatqueue(unsigned x){
    struct queue* queue=(struct queue*)malloc(sizeof(struct queue));
    queue->front=queue->size=0;
    queue->capacity=x;
    queue->rear=x-1;
    queue->arr=(int*)malloc(x * sizeof(struct queue));
    return queue;
}
int isFull(struct queue* queue)
{return(queue->size == queue->capacity);}
int isEmpty(struct queue* queue)
{return(queue->size == 0);}

void enqueue(struct queue* queue,int item){
    if(isFull(queue))
        return;
    queue->rear=(queue->rear +1)%queue->capacity;
    queue->arr[queue->rear]=item;
    queue->size=queue->size +1;
    printf("%d enqueued to queue\n", item);
}
int dequeue(struct queue* queue){
    if(isEmpty(queue))
        return INT_MIN;
    int item=queue->arr[queue->front];
    queue->front=(queue->front +1)%queue->capacity;
    queue->size=queue->size -1;
    return item;
}
int front(struct queue* queue){
    if(isEmpty(queue)){
        return INT_MIN;
    }
    else{
        return queue->arr[queue->front];
    }
}
int rear(struct queue* queue){
    if(isEmpty(queue)){
        return INT_MIN;
    }
    else{
        return queue->arr[queue->rear];
    }
}
int main(){
    struct queue* que=creatqueue(10);
    for(int i=0;i<10;i++){
        enqueue(que,i);
    }
    printf("%d dequeued from queue\n\n", dequeue(que)); 
	printf("Front item is %d\n", front(que)); 
	printf("Rear item is %d\n", rear(que)); 

}





















