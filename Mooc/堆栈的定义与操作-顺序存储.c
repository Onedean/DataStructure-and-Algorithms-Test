// ��ջ�Ķ��������-˳��洢

#include<stdio.h>
#include<stdbool.h>
#define ERROR -1

typedef int ElementType;
typedef int Position;
typedef struct Snode *Stack;

struct Snode{
    ElementType *data;  // ˳��洢Ԫ�ص�����
    Position top;  // ջ��ָ��
    int maxSize;  // ��ջ�������
};

// ��ջ������һ���������ΪmaxSize�Ķ�ջ
Stack creatStack(int maxSize){
    Stack s = (Stack)malloc(sizeof(struct Snode));  // ����һ���յĶ�ջ�ڴ�ռ�
    s->data = (ElementType *)malloc(maxSize * sizeof(ElementType));  // ����ѭ��洢������ڴ�ռ�
    s->top = -1;  // ���Ϊ��ջ
    s->maxSize = maxSize;
    return s;
}

// �ж�ջ�����ж�ջs�Ƿ���
bool isFull(Stack s){
    return (s->top == s->maxSize-1);
}

// �ж�ջ�գ��ж�ջs�Ƿ��
bool isEmpty(Stack s){
    return (s->top == -1);
}

// ��ջ��ջsѹ��Ԫ��x
bool push(Stack s,ElementType x){
    if(isFull(s)){
        printf("��ջ����\n");
        return false;
    }else{
        s->data[++(s->top)] = x;
        return true;
    }
}

// ��ջ��ջs����Ԫ��x
bool pop(Stack s){
    if(isEmpty(s)){
        printf("��ջ����Ԫ��\n");
        return ERROR;  // ERROR��������־
    }else{
        return s->data[(s->top)--];
    }
}