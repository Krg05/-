#include <stdio.h>
#define SIZE 7

int main(void) {
	int number[SIZE] = { 0 };
	int temp = 0;
    int select;
	char cont;
    int pocket;
    printf("���� %d���� ���� �Է��Ͻÿ�\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        while (1) {
            printf("���ڸ� �Է��Ͻÿ�: ");
            pocket = scanf("%d", &number[i]);
            if (pocket == 1) {
                break;
            }
            else {
                printf("�߸��� �Է��Դϴ�. ���ڸ� �ٽ� �Է��Ͻÿ�.\n");
                while (getchar() != '\n');
            }
        }
    }
    //���� ����
    printf("1----��������\n2----��������\n");
    scanf("%d", &select);
    switch (select) {
    case 1: //����
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
    case 2: //����
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
    } //�˻� ����
    while (1) {
        printf("�˻�?(Y/N): ");
        scanf(" %c", &cont);
        if (cont == 'n' || cont == 'N') {
            break;
        }
        else if (cont == 'y' || cont == 'Y') {
            int search;
            printf("�˻��� ����: ");
            scanf("%d", &search);

            int count = 0;
            for (int i = 0; i < SIZE; i++) {
                if (number[i] == search) {
                    printf("%d��° ���Դϴ�.\n", i + 1);
                    count++;
                    break;
                }
            }
            if (!count) {
                printf("%d�� �迭�� �������� �ʽ��ϴ�.\n", search);
            }
        }
        else {
            printf("Y(y) �Ǵ� N(n)�� �Է����ּ���.\n");
        }
    }
	return 0;
}