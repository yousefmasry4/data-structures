#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *array;
    size_t size;
    size_t used;
}arr;
void init(arr *a,int data){
    a->array=(int *)malloc(data * sizeof(int));
    a->size=data;
    a->used=0;
}
void insert(arr *a,int data){
    if(a->size == a->used){
        a->size *=2;
        a->array=(int *)realloc(a->array,a->size * sizeof(int));
    }
    a->array[a->used++]=data;
}
int main(){
    arr a;
    init(&a,5);
    for(int i=0;i<10;i++){
        insert(&a,i);
    }
    printf("%d",a.array[9]);
}