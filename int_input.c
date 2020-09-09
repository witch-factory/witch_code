#include <stdio.h>
#define LINE_LENGTH (1024)

int main(void) {
	int sum = 0;
	int num;

	char line[LINE_LENGTH];

	while (1) {
		if (fgets(line, LINE_LENGTH, stdin) == NULL) { //입력받기 실패시
			clearerr(stdin);
			break;
		}

		if (sscanf(line, "%d", &num) == 1) {
			sum += num;
			
		}
	}
	printf("%d", sum);

}