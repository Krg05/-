#include <stdio.h>
#define SIZE 7

int main(void) {
	int number[SIZE] = { 0 };
	int temp = 0;
    int select;
	char cont;
    int pocket;
    printf("숫자 %d개를 각각 입력하시오\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        while (1) {
            printf("숫자를 입력하시오: ");
            pocket = scanf("%d", &number[i]);
            if (pocket == 1) {
                break;
            }
            else {
                printf("잘못된 입력입니다. 숫자를 다시 입력하시오.\n");
                while (getchar() != '\n');
            }
        }
    }
    //정렬 선택
    printf("1----버블정렬\n2----선택정렬\n");
    scanf("%d", &select);
    switch (select) {
    case 1: //버블
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - i - 1; j++) {
                if (number[j] < number[j + 1]) {
                    temp = number[j];
                    number[j] = number[j + 1];
                    number[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", number[i]);
        }
        printf("\n");
        break;
    case 2: //선택
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = i + 1; j < SIZE; j++) {
                if (number[i] < number[j]) {
                    temp = number[i];
                    number[i] = number[j];
                    number[j] = temp;
                }
            }
        }

        for (int i = 0; i < SIZE; i++) {
            printf("%d ", number[i]);
        }
        printf("\n");
        break;
    } //검색 순서
    while (1) {
        printf("검색?(Y/N): ");
        scanf(" %c", &cont);
        if (cont == 'n' || cont == 'N') {
            break;
        }
        else if (cont == 'y' || cont == 'Y') {
            int search;
            printf("검색할 숫자: ");
            scanf("%d", &search);

            int count = 0;
            for (int i = 0; i < SIZE; i++) {
                if (number[i] == search) {
                    printf("%d번째 수입니다.\n", i + 1);
                    count++;
                    break;
                }
            }
            if (!count) {
                printf("%d는 배열에 존재하지 않습니다.\n", search);
            }
        }
        else {
            printf("Y(y) 또는 N(n)을 입력해주세요.\n");
        }
    }
	return 0;
}