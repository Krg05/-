#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

typedef int Element;

typedef struct LinkedNode {
    Element data; // 데이터 영역
    struct LinkedNode* link; // 다음 노드를 가리키는 포인터 변수
} Node;

Node* top = NULL; // 연결 리스트의 헤드 포인터

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
        error("스택 공백 에러");
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
    Node* p = (Node*)malloc(sizeof(Node)); // 노드 동적 할당
    if (p == NULL) {
        error("메모리 할당 에러");
    }
    p->data = e;
    if (top == NULL) {
        p->link = NULL;
    }
    else {
        p->link = top;
    }
    top = p;

    printf("입력받은 수: %d\n", e);
}

Element pop()
{
    Node* p;
    Element e;
    if (is_empty())
        error("스택 공백 에러");

    p = top;
    e = p->data;
    top = p->link;

    printf("삭제된 값: %d\n", e);

    free(p); // 노드 동적 해제
    return e; // 복사한 항목 데이터를 반환
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
        printf("1: 입력  2: 삭제  3: 출력  4: 종료\n");
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            printf("입력 받을 수\n");
            scanf("%d", &value);
            if (value < 1 || value > 9)
            {
                printf("1-9 사이의 수를 입력해주세요.\n");
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
            print_stack("스택에 남아있는 값들: ");
            break;
        case 4:
            destroy_stack();
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
            break;
        }
    }

    return 0;
}
