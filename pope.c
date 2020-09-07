#include <stdio.h>
#include <string.h>

#define BUFFER_LENGTH (32)

static size_t buffer_idx = 0;
static char buffer[BUFFER_LENGTH];

int string_comp(const char* s1, const char* s2) {
	char* p1 = s1;
	char* p2 = s2;

	while (*p1 != '\0' && *p1 == *p2) { //널 빼고 서로 같은 문자들은 전부 건너뜀
		p1++; p2++;
	}

	if (*p1 == *p2) return 0; //맨 마지막에 널이 남았을 경우
	return *p1 > *p2 ? 1 : -1;

}

void string_copy(const char* str, char* dest) { //str문자열을 dest 배열로 복사한다.
	while (*str != '\0') {
		*dest++ = *str++; //한글자씩 복사해준다.
	}
	*dest = '\0';
}

void buffered_print(const char* src) {
	size_t num_left;
	const char* p = src;

	num_left = strlen(src); //버퍼에 복사해야 할 문자 길이

	while (num_left > 0) { //아직 복사할 문자가 남아 있으면
		//버퍼가 꽉 차면 출력하고 다시 복사함
		size_t copy_count = BUFFER_LENGTH - 1 - buffer_idx; //버퍼에 남아 있는 공간
		const int buffer_empty = (buffer_idx == 0);

		if (num_left < copy_count) { //버퍼에 복사해야 할 문자열 길이 < 버퍼에 남은 공간
			copy_count = num_left;
		}

		buffer_idx += copy_count; //버퍼의 현재 인덱스 이동시켜줌
		num_left -= copy_count; //버퍼에 남은 공간 수 줄여줌

		if (buffer_empty) {
			strncpy(buffer, p, copy_count); //인수로 받은 문자열을 버퍼에 복사.
			//정확히 복사해야 할 만큼을 계산해 뒀기에 그만큼 복사
			buffer[buffer_idx] = '\0';
		}
		else {
			strncpy(buffer, p, copy_count);
		}

		p += copy_count;

		if (buffer_idx == BUFFER_LENGTH) {
			printf("%s\n", buffer);
			buffer_idx = 0;
		}

	}


}

int main(void) {
	char str1[] = "ABCD";
	char str2[5];
	string_copy(str1, str2);
	printf("%s\n", str2);
}
