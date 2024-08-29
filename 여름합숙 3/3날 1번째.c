#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5 // ���� ��� ������ ���� �迭�� ũ��
#pragma warning(disable: 4996)

typedef int Element; // ���� ����� �ڷ��� ����
Element data[MAX_STACK_SIZE]; // ���� ���� ����� �迭
int top; // ���� ������ top

void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}

void init_stack() { top = -1; } // �ʱ�ȭ
int is_empty() { return top == -1; } // ������ ����ִ� �� �˻�
int is_full() { return top == MAX_STACK_SIZE - 1; }
int size() { return top + 1; }

void push(Element e) // �Է� ����
{
	if (is_full()) {
		error("������ ���� á���ϴ�.\n");
	}
	else {
		data[++top] = e;
	}
}

Element pop() // ���� ����
{
	if (is_empty()) {
		error("������ �̹� ����ֽ��ϴ�.\n");
	}
	else {
		return data[top--];
	}
}

void print_stack() // ���� ���
{
	if (is_empty()) {
		error("������ ����ֽ��ϴ�.\n");
	}
	else {
		for(int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%d��° �濡 �ִ� ���� %d\n", i, data[i]);
	}
}

void main()
{
	init_stack();
	int select, value = 0;
	while (1) {
		printf("1.�Է�\t2.����\t3.���\t4.����\n");
		scanf("%d", &select);
		switch (select) {
		case 1:
			printf("�Է� ���� ��\n");
			while (1) {
				scanf("%d", &value);
				if (value < 1 || value > 9) {
					printf("1-9 ������ ���� �Է����ּ���.\n");	
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
			printf("���α׷��� �����մϴ�.\n");
			exit(1);
			break;
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
			continue;
		}
	}
}