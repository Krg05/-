#include <stdio.h>
#pragma warning(disable: 4996)

int main(void) {
    int num = 0;
    char cont;
    int count = 0;
    while (count == 0) {
       
        printf("3���� 23 ������ ���� ���ÿ�: ");
        scanf("%d", &num);
        if (num > 2 && num < 24) {
            for (int j = 0; j < num; j++) {
                printf("*");
            }
            printf("\n");
            for (int i = 0; i < num - 2; i++) {
                printf("*");
                for (int j = num; j > num - i; j--) {
                    printf(" ");
                }
                printf("@");
                for (int j = 0; j < num - i - 3; j++) {
                    printf(" ");
                }
                printf("*\n");
            }
            for (int j = 0; j < num; j++) {
                printf("*");
            }
            printf("\n�ٽ�? (Y / N) : ");

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
                    printf("\nY(y) �Ǵ� N(n)�� �Է����ּ���.\n");
                    continue;
                }
            }
        }
        else {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
        }
    }
    return 0;
}