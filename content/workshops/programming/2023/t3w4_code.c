#include <stdio.h>

int stack[100005];
int top = 0; // points to the space above the top element.

void push(int data) {
    stack[top] = data;
    top++;
}

int pop() {
    top--;
    return stack[top];
}

int peek() {
    return stack[top - 1];
}

int size() {
    return top;
}

// first, a brute force n^2 solution to the problem:
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
    int* ans = (int*)malloc(sizeof(int) * temperaturesSize);
    *returnSize = temperaturesSize;
    for (int i = temperaturesSize - 1; i >= 0; i--) {
        ans[i] = 0;
        for (int j = i+1; j < temperaturesSize; j++) {
            if (temperatures[j] > temperatures[i]) {
                ans[i] = j - i;
                break;
            }
        }
    }
    return ans;
}


int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
    top = 0;
    int* ans = (int*)malloc(sizeof(int) * temperaturesSize);
    *returnSize = temperaturesSize;
    for (int i = temperaturesSize - 1; i >= 0; i--) {
        while (size() > 0 && temperatures[i] >= temperatures[peek()]) {
            pop();
        }
        if (size() == 0) {
            ans[i] = 0;
        } else {
            ans[i] = peek() - i;
        }
        push(i);

    }
    return ans;
}



int temperatures[100005];
int* ans;

/* Main function */
int main(){
    stack s;
    push(44);
    push(10);
    push(62);
    push(123);
    push(15);

    while(size() > 0) {
        int data = pop();
        printf("%d\n",data);
    }
    printf("Stack full: %s\n" , isfull()?"true":"false");
    printf("Stack empty: %s\n" , isempty()?"true":"false");

    int* returnSize;
    ans = dailyTemperatures(temperatures, 5, returnSize);


    return 0;
}