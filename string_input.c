#include <stdio.h>
#define LINE_LENGTH (1024)

int main(void) {
	char line[LINE_LENGTH];
	char word[LINE_LENGTH];

	while (1) {
		if (fgets(line, LINE_LENGTH, stdin) == NULL) { //�Է¹ޱ� ���н�
			clearerr(stdin);
			break;
		}

		if (sscanf(line, "%s", word) == 1) {
			printf("%s\n", word);
		}
	}

}