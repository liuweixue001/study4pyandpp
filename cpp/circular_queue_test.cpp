#include <stdio.h>  
#include <stdlib.h>  
  
#define MAXSIZE 10 // 定义队列的最大容量  
  
typedef struct {  
    int data[MAXSIZE]; // 存储数据的数组  
    int front; // 队头指针  
    int rear; // 队尾指针  
} CircularQueue;  
  
// 初始化队列  
void InitQueue(CircularQueue *Q) {  
    Q->front = Q->rear = 0; // 初始化队头和队尾指针  
}  
  
// 判断队列是否为空  
int IsEmpty(CircularQueue *Q) {  
    return Q->front == Q->rear; // 如果队头和队尾指针相等，则队列为空  
}  
  
// 判断队列是否已满  
int IsFull(CircularQueue *Q) {  
    return (Q->rear + 1) % MAXSIZE == Q->front; // 如果队尾指针的下一个位置是队头指针，则队列已满  
}  
  
// 入队操作  
int EnQueue(CircularQueue *Q, int x) {  
    if (IsFull(Q)) { // 如果队列已满，则无法进行入队操作  
        return 0; // 入队失败，返回0  
    } else {  
        Q->data[Q->rear] = x; // 将新元素添加到队尾指针指向的位置  
        Q->rear = (Q->rear + 1) % MAXSIZE; // 队尾指针向后移动一位  
        return 1; // 入队成功，返回1  
    }  
}  
  
// 出队操作  
int DeQueue(CircularQueue *Q, int *x) {  
    if (IsEmpty(Q)) { // 如果队列为空，则无法进行出队操作  
        return 0; // 出队失败，返回0  
    } else {  
        *x = Q->data[Q->front]; // 获取队头元素的值  
        Q->front = (Q->front + 1) % MAXSIZE; // 队头指针向后移动一位  
        return 1; // 出队成功，返回1  
    }  
}  
  
// 获取队头元素  
int GetFront(CircularQueue *Q, int *x) {  
    if (IsEmpty(Q)) { // 如果队列为空，则无法获取队头元素  
        return 0; // 获取失败，返回0  
    } else {  
        *x = Q->data[Q->front]; // 获取队头元素的值  
        return 1; // 获取成功，返回1  
    }  
}
  
int main() {  
    CircularQueue Q; // 创建一个循环队列实例  
    int x, y; // 用于存储临时数据  
  
    // 初始化队列  
    InitQueue(&Q);  
  
    // 测试入队操作  
    for (int i = 1; i <= 5; i++) {  
        printf("入队元素 %d\n", i);  
        EnQueue(&Q, i);  
    }  
  
    // 测试获取队头元素操作  
    if (GetFront(&Q, &x)) {  
        printf("队头元素是 %d\n", x);  
    } else {  
        printf("队列为空，无法获取队头元素\n");  
    }  
  
    // 测试出队操作  
    while (!IsEmpty(&Q)) {  
        if (DeQueue(&Q, &y)) {  
            printf("出队元素是 %d\n", y);  
        } else {  
            printf("队列为空，无法进行出队操作\n");  
        }  
    }  
  
    // 测试队列是否为空  
    if (IsEmpty(&Q)) {  
        printf("队列为空\n");  
    } else {  
        printf("队列不为空\n");  
    }  
  
    return 0;  
}