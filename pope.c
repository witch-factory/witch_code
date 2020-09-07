#include <stdio.h>

int string_comp(const char* s1, const char* s2) {
	char* p1 = s1;
	char* p2 = s2;

	while (*p1 != '\0' && *p1 == *p2) { //널 빼고 서로 같은 문자들은 전부 건너뜀
		p1++; p2++;
	}

	if (*p1 == *p2) return 0; //맨 마지막에 널이 남았을 경우
	return *p1 > *p2 ? 1 : -1;

}

void string_copy(const char* str, char* dest) {
	while (*str != '\0') {
		*dest++ = *str++; //한글자씩 복사해준다.
	}
	*dest = '\0';
}

int main(void) {
	char str1[] = "ABCD";
	char str2[5];
	string_copy(str1, str2);
	printf("%s\n", str2);
}