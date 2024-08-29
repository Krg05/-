#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

typedef int Element;

typedef struct LinkedNode {
    Element data; // ������ ����
    struct LinkedNode* link; // ���� ��带 ����Ű�� ������ ����
} Node;

Node* top = NULL; // ���� ����Ʈ�� ��� ������

void error(char* str)
{
    fprintf(stderr, "%s\n", str);
    exit(1);
};

int is_empty() { return top == NULL; }

void init_stack() { top = NULL; }

Element peek()
{
    if (is_empty())
        error("���� ���� ����");
    return top->data;
}

void destroy_stack()
{
    while (!is_empty())
        pop();
}

int size()
{
    Node* p;
    int count = 0;
    for (p = top; p != NULL; p = p->link) count++;
    return count;
}

void push(Element e)
{
    Node* p = (Node*)malloc(sizeof(Node)); // ��� ���� �Ҵ�
    if (p == NULL) {
        error("�޸� �Ҵ� ����");
    }
    p->data = e;
    if (top == NULL) {
        p->link = NULL;
    }
    else {
        p->link = top;
    }
    top = p;

    printf("�Է¹��� ��: %d\n", e);
}

Element pop()
{
    Node* p;
    Element e;
    if (is_empty())
        error("���� ���� ����");

    p = top;
    e = p->data;
    top = p->link;

    printf("������ ��: %d\n", e);

    free(p); // ��� ���� ����
    return e; // ������ �׸� �����͸� ��ȯ
}

void print_stack(char* msg)
{
    Node* p;
    printf("%s", msg);
    for (p = top; p != NULL; p = p->link)
        printf("%d -> ", p->data);
    printf("NULL\n");
}

int main()
{
    int select, value;

    init_stack();

    while (1)
    {
        printf("1: �Է�  2: ����  3: ���  4: ����\n");
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            printf("�Է� ���� ��\n");
            scanf("%d", &value);
            if (value < 1 || value > 9)
            {
                printf("1-9 ������ ���� �Է����ּ���.\n");
            }
            else
            {
                push(value);
            }
            break;
        case 2:
            pop();
            break;
        case 3:
            print_stack("���ÿ� �����ִ� ����: ");
            break;
        case 4:
            destroy_stack();
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
            break;
        }
    }

    return 0;
}
