#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

//ť �迭 �� ���� ����
#define MAX_QUEUE_SIZE 5
typedef int Element;
Element data[MAX_QUEUE_SIZE];
int front;
int rear;

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

//ť �ʱ�ȭ
int init_queue() {
	return front = rear = 0;
}

//ť�� ����ִ��� Ȯ��
int is_empty() {
	return front == rear;
}

//ť�� ���� á���� Ȯ��
int is_full() {
	return front == (rear + 1) % MAX_QUEUE_SIZE;
}

int size() {
	return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void enqueue(Element e) {
	if (is_full()) {
		error("ť�� ���� á���ϴ�.\n");
	}
	else {
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		data[rear] = e;
	}
}

Element dequeue() {
	if (is_empty()) {
		error("ť�� �̹� ����ֽ��ϴ�.\n");
	}
	else {
		front = (front + 1) % MAX_QUEUE_SIZE;
		return data[front];
	}
}

int peek() {
	if (is_empty()) {
		error("ť�� ����ֽ��ϴ�.\n");
	}
	else {
		//rear�� ����ϴ� �� �ƴ϶� �츰 ���� �ʿ����ݾ�. �׷��ϱ� data[rear]
		return data[rear];
	}
}

void print_queue() {
	if (is_empty()) {
		error("������ ����ֽ��ϴ�.\n");
	}
	else {// front + 1 ~ rear rear�� front�� ���� �������� �� �ٽ� ����? �ؾ���
		for (int i = front + 1; i <= rear; i++) {
			printf("%d��° �濡 ���� %d�� �ֽ��ϴ�.\n", i, data[i]);
		}
	}
}

void main() {
	init_queue();
	int select, value;
	while (1) {
		printf("1--�Է�  2--����  3--���  4--����\n");
		int pocket;
		while (1) {
			pocket = scanf("%d", &select);
			while (getchar() != '\n');
			if (pocket >= 1 || pocket <= 4) {
				break;
			}
			else {
				printf("�߸��� �Է��Դϴ�. ���ڸ� �ٽ� �Է��Ͻÿ�.\n");
			}
		}
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
					enqueue(value);
					break;
				}
			}
			break;
		case 2:
			dequeue();
			printf("�����Ǿ����ϴ�.\n");
			break;
		case 3:
			print_queue();
			break;
		case 4:
			printf("���α׷��� �����մϴ�.\n");
			exit(0);
		default:
			printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
			continue;
		}
	}
}