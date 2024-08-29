#include <stdio.h>
#pragma warning(disable: 4996)

int main(void) {
	int num = 0;
	char cont;
	int count = 0;
	while (count == 0) {
		printf("높이 입력(3이상 홀수): ");
		scanf("%d", &num);
		if (num > 2 && num % 2 != 0) {
			//위 삼각형
			for (int i = 0; i < num - 3; i++) {
				for (int j = 0; j < num - i - 4.5; j++) {
					printf(" ");  
				}
				for (int j = 0; j < i *	2 + 1; j++) {
					printf("*");
				}
				printf("\n");
			}
			//v 부분
			for (int i = 0; i < num / 2 - 1; ++i) {
				for (int j = 0; j < i + 1; ++j) {
					printf(" ");
				}
				printf("*");
				for (int j = 0; j < num - 2 * i - 4; ++j) {
					printf(" ");
				}
				printf("*\n");
			}

			for (int i = 0; i < num / 2 ; ++i) {
				printf(" ");
			}
			printf("*\n");
			//사각형
			for (int j = 0; j < num; j++) {
				printf("*");
			}
			printf("\n");
			for (int i = 0; i < num - 2; i++) {
				printf("*");
				for (int j = 0; j < num - 2; j++) {
					printf(" ");
				}
				printf("*\n");
			}
			for (int j = 0; j < num; j++) {
				printf("*");
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