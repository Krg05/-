#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

//큐 배열 및 변수 선언
#define MAX_QUEUE_SIZE 5
typedef int Element;
Element data[MAX_QUEUE_SIZE];
int front;
int rear;

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

//큐 초기화
int init_queue() {
	return front = rear = 0;
}

//큐가 비어있는지 확인
int is_empty() {
	return front == rear;
}

//큐가 가득 찼는지 확인
int is_full() {
	return front == (rear + 1) % MAX_QUEUE_SIZE;
}

int size() {
	return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void enqueue(Element e) {
	if (is_full()) {
		error("큐가 가득 찼습니다.\n");
	}
	else {
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		data[rear] = e;
	}
}

Element dequeue() {
	if (is_empty()) {
		error("큐가 이미 비어있습니다.\n");
	}
	else {
		front = (front + 1) % MAX_QUEUE_SIZE;
		return data[front];
	}
}

int peek() {
	if (is_empty()) {
		error("큐가 비어있습니다.\n");
	}
	else {
		//rear를 출력하는 게 아니라 우린 값이 필요하잖아. 그러니까 data[rear]
		return data[rear];
	}
}

void print_queue() {
	if (is_empty()) {
		error("스택이 비어있습니다.\n");
	}
	else {// front + 1 ~ rear rear와 front가 끝에 도달했을 때 다시 시작? 해야함
		for (int i = front + 1; i <= rear; i++) {
			printf("%d번째 방에 숫자 %d가 있습니다.\n", i, data[i]);
		}
	}
}

void main() {
	init_queue();
	int select, value;
	while (1) {
		printf("1--입력  2--삭제  3--출력  4--종료\n");
		int pocket;
		while (1) {
			pocket = scanf("%d", &select);
			while (getchar() != '\n');
			if (pocket >= 1 || pocket <= 4) {
				break;
			}
			else {
				printf("잘못된 입력입니다. 숫자를 다시 입력하시오.\n");
			}
		}
		switch (select) {
		case 1:
			printf("입력 받을 수\n");
			while (1) {
				scanf("%d", &value);
				if (value < 1 || value > 9) {
					printf("1-9 사이의 수를 입력해주세요.\n");
					continue;
				}
				else {
					enqueue(value);
					break;
				}
			}
			break;
		case 2:
			dequeue();
			printf("삭제되었습니다.\n");
			break;
		case 3:
			print_queue();
			break;
		case 4:
			printf("프로그램을 종료합니다.\n");
			exit(0);
		default:
			printf("잘못된 선택입니다. 다시 시도하세요.\n");
			continue;
		}
	}
}