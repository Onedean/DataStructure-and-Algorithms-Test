// 堆栈的定义与操作-顺序存储

#include<stdio.h>
#include<stdbool.h>
#define ERROR -1

typedef int ElementType;
typedef int Position;
typedef struct Snode *Stack;

struct Snode{
    ElementType *data;  // 顺序存储元素的数组
    Position top;  // 栈顶指针
    int maxSize;  // 堆栈最大容量
};

// 建栈：创建一个最大容量为maxSize的堆栈
Stack creatStack(int maxSize){
    Stack s = (Stack)malloc(sizeof(struct Snode));  // 申请一个空的堆栈内存空间
    s->data = (ElementType *)malloc(maxSize * sizeof(ElementType));  // 申请循序存储数组的内存空间
    s->top = -1;  // 标记为空栈
    s->maxSize = maxSize;
    return s;
}

// 判断栈满：判断栈s是否满
bool isFull(Stack s){
    return (s->top == s->maxSize-1);
}

// 判断栈空：判断栈s是否空
bool isEmpty(Stack s){
    return (s->top == -1);
}

// 入栈：栈s压入元素x
bool push(Stack s,ElementType x){
    if(isFull(s)){
        printf("堆栈已满\n");
        return false;
    }else{
        s->data[++(s->top)] = x;
        return true;
    }
}

// 出栈：栈s弹出元素x
bool pop(Stack s){
    if(isEmpty(s)){
        printf("堆栈已无元素\n");
        return ERROR;  // ERROR代表错误标志
    }else{
        return s->data[(s->top)--];
    }
}