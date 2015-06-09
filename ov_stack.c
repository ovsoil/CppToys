#ifndef _OV_STACK_H
#define _OV_STACK_H
#include <stdlib.h>
#include <stdio.h>


typedef struct MinStackElement{
    int value;
    int min;
} MinStackElement;

typedef struct MinStack{
    MinStackElement *data;
    int size;
    int top;
} MinStack;


MinStack* initialStack(int maxSize){
    MinStack* s = (MinStack*) malloc(sizeof(MinStack));
    s->data = (MinStackElement*)malloc(sizeof(MinStackElement) * maxSize);
    s->size = maxSize;
    s->top = 0;
    return s;
}

void push(MinStack* s, int value){
    if(s->top >= s->size){
        printf("The Stack is full!\n");
        return;
    }
    MinStackElement elem;
    elem.value = value;
    if(s->top == 0){
        elem.min = elem.value;
    }
    else{
        if(elem.value > s->data[s->top - 1].min){
            elem.min = s->data[s->top - 1].min;
        }
        else{
            elem.min = elem.value;
        }
    }
    s->data[s->top] = elem;
    s->top++;
}

int pop(MinStack *s){
    if(s->top == 0){
        printf("The Stack is Empty!\n");
        return -1;
    }
    s->top--;
    return s->data[s->top].value;
}

int min(MinStack *s){
    if(s->top == 0){
        printf("The Stack is Empty!\n");
        return -1;
    }
    return s->data[s->top-1].min;
}


void display(MinStack *s){
    printf("MinStack(size, top, min:%d, %d, %d):", s->size, s->top, min(s));
    for(int i = 0; i < s->top; ++i){
        printf("%d  ", s->data[i].value);
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    MinStack *s = initialStack(10);
    push(s, 10);
    push(s, 2);
    push(s, 1);
    push(s, 6);
    push(s, -1);
    
    display(s);

    pop(s);
    display(s);
    pop(s);
    display(s);
    pop(s);
    display(s);
    return 0;
}

#endif /* OV_STACK_H */
