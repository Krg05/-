#include <stdio.h>
#pragma warning(disable: 4996)

int main() {
    int num;
    char cont;
    int count = 0;
    while (count == 0) {
        printf("높이(정수)를 입력하시오 : ");
        scanf("%d", &num);
        printf("\n");
        if (num > 0) {
            for (int i = 0; i < num; i++) {
                for (int j = 0; j < i; j++) {
                    printf(" ");
                }
                for (int j = num - i; j > 0; j--) {
                    printf("*");
                }
                for (int j = num - i; j > 1; j--) {
                    printf(" ");
                }
                for (int j = 0; j < i + 1; j++) {
                    printf("*");
                }
                printf("\n");
            }
            for (int i = 0; i < num; i++) {
                for (int j = num - i; j > 0; j--) {
                    printf("*");
                }
                for (int j = 0; j < i; j++) {
                    printf(" ");
                }
                for (int j = 0; j < i + 1; j++) {
                    printf("*");
                }
                printf("\n");
            }
            printf("\n다시? (Y / N) : ");

            while (1) {
                
                scanf(" %c", &cont);
                if (cont == 'n' || cont == 'N') {
                    count++;
                    break;
                }
                else if (cont == 'y' || cont == 'Y') {
                    break;
                }
                else {
                    printf("\nY(y) 또는 N(n)을 입력해주세요.\n");
                    continue;
                }
            }
        }
        else {
            printf("잘못된 입력입니다. 다시 입력해주세요.\n");
        }
    }
    return 0;
}