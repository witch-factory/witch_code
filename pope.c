#include <stdio.h>

int string_comp(const char* s1, const char* s2) {
	char* p1 = s1;
	char* p2 = s2;

	while (*p1 != '\0' && *p1 == *p2) { //�� ���� ���� ���� ���ڵ��� ���� �ǳʶ�
		p1++; p2++;
	}

	if (*p1 == *p2) return 0; //�� �������� ���� ������ ���
	return *p1 > *p2 ? 1 : -1;

}

void string_copy(const char* str, char* dest) {
	while (*str != '\0') {
		*dest++ = *str++; //�ѱ��ھ� �������ش�.
	}
	*dest = '\0';
}

int main(void) {
	char str1[] = "ABCD";
	char str2[5];
	string_copy(str1, str2);
	printf("%s\n", str2);
}