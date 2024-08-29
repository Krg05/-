#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3
#pragma warning(disable: 4996)

int number[SIZE] = { 0 };

//���� ����
void CreateNum() {
	srand(time(NULL));
	int random_number;
	int used[10] = { 0 };
	for (int i = 0; i < SIZE; i++) {
		do {
			random_number = (rand() % 9) + 1;
		} while (used[random_number]);
			number[i] = random_number;
			used[random_number] = 1;
		
	}
}

int main() {
	char cont;
	int count = 0;
	int num;
	int guess[SIZE] = { 0 };

	int strikes, balls;
	while (count == 0) {
		int attempt = 0;
		CreateNum();
		while (1) {
			strikes = 0;
			balls = 0;
			printf("���� 3���� �Է��ϼ���: ");
			scanf(" %d", &num);
			if (num > 100 && num < 1000) {
				guess[2] = num % 10;
				guess[1] = (num % 100) / 10;
				guess[0] = (num / 10) / 10;
			}
			else {
				printf("\n3�ڸ� ������ �Է����ּ���.\n");
			}
			
			//��Ʈ����ũ, ��
			for (int i = 0; i < SIZE; ++i) {
				if (guess[i] == number[i]) {
					strikes++;
				}
				else {
					for (int j = 0; j < SIZE; ++j) {
						if (guess[i] == number[j]) {
							balls++;
							break;
						}
					}
				}
			}
			attempt++;
			if (strikes == SIZE) {
				printf("Ȩ��!! �����Դϴ�!\n%d�� �õ�\n", attempt);
				break;
			}
			else {
				printf("%d ��Ʈ����ũ\n%d ��\n", strikes, balls);
			}
		}
		//�ٽ��ϱ�
		printf("\n�ٽ� �Ͻðڽ��ϱ�?[Y/N] : ");
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
	return 0;
}