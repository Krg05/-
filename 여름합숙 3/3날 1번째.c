#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5 // 스택 요소 저장을 위한 배열의 크기
#pragma warning(disable: 4996)

typedef int Element; // 스택 요소의 자료형 정의
Element data[MAX_STACK_SIZE]; // 실제 스택 요소의 배열
int top; // 실제 스택의 top

void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}

void init_stack() { top = -1; } // 초기화
int is_empty() { return top == -1; } // 스택이 비어있는 지 검사
int is_full() { return top == MAX_STACK_SIZE - 1; }
int size() { return top + 1; }

void push(Element e) // 입력 연산
{
	if (is_full()) {
		error("스택이 가득 찼습니다.\n");
	}
	else {
		data[++top] = e;
	}
}

Element pop() // 삭제 연산
{
	if (is_empty()) {
		error("스택이 이미 비어있습니다.\n");
	}
	else {
		return data[top--];
	}
}

void print_stack() // 스택 출력
{
	if (is_empty()) {
		error("스택이 비어있습니다.\n");
	}
	else {
		for(int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%d번째 방에 있는 숫자 %d\n", i, data[i]);
	}
}

void main()
{
	init_stack();
	int select, value = 0;
	while (1) {
		printf("1.입력\t2.삭제\t3.출력\t4.종료\n");
		scanf("%d", &select);
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
					push(value);
					break;
				}
			}
			break;
		case 2:
			pop();
			break;
		case 3:
			print_stack();
			break;
		case 4:
			printf("프로그램을 종료합니다.\n");
			exit(1);
			break;
		default:
			printf("잘못된 입력입니다. 다시 입력해주세요.\n");
			continue;
		}
	}
}