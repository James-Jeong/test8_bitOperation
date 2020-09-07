#include <stdio.h>

///////////////////////////////////////////////////////////////////////////////////////
/// Macros
///////////////////////////////////////////////////////////////////////////////////////

// 2진수 변환에 사용될 정수의 비트 수
#define NUM_OF_BIT 32
// 함수 실행 결과 열거형
enum STATUS
{
	FAIL	= 0,	// 실패
	SUCCESS	= 1,	// 성공
};

/////////////////////////////////////////////////////////////////////////////////////
/// Predefinitions of Local functions
///////////////////////////////////////////////////////////////////////////////////////

void printUnsigned32bitsNumberToBinary(unsigned int inputValue);
void input32bitsNumber(unsigned int *number);

///////////////////////////////////////////////////////////////////////////////////////
/// Main function
///////////////////////////////////////////////////////////////////////////////////////

/**
 * @fn int main(int argc, char **argv)
 * @brief 32 비트 정수값을 이진수로 출력하는 프로그램
 * @return SUCCESS 반환
 */
int main()
{
	unsigned int unsignedInputValue = 0;
	input32bitsNumber(&unsignedInputValue);
	printUnsigned32bitsNumberToBinary(unsignedInputValue);

	return SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////////////
/// Local functions
///////////////////////////////////////////////////////////////////////////////////////

/**
 * @fn void printUnsigned32bitsNumberToBinary(unsigned int inputValue)
 * @brief 부호 없는 32 bits 정수를 이진수로 출력하는 함수
 * @param number 이진수로 출력될 부호 없는 정수(입력)
 * @return 반환값 없음
 */
void printUnsigned32bitsNumberToBinary(unsigned int inputValue)
{
	unsigned int mask = 0x80000000;
	int bitPosition = 1;
	
	printf("\n입력 받은 정수(unsigned) : %d\n", inputValue);
	printf("2진수 : ");
	for( ; bitPosition <= NUM_OF_BIT; bitPosition++)
	{
		printf("%c", (inputValue & mask) == 0 ? '0' : '1');
		if(bitPosition % 4 == 0) printf(" ");
		mask >>= 1;
	}
	printf("\n");
}

/**
 * @fn void input32bitsNumbers(unsigned int *number)
 * @brief 부호 없는 32 bits 정수를 입력받는 함수
 * @param number 입력받을 부호 없는 정수를 저장하는 변수(출력)
 * @return 반환값 없음
 */
void input32bitsNumber(unsigned int *number)
{
	if(number == NULL)
	{
		printf("잘못된 정수 변수 참조. NULL. (number:%p)\n", number);
		return;
	}

	int inputResult = FAIL;
	do
	{
		printf("부호 없는 32 bit 정수 입력 : ");
		inputResult = scanf(" %d", number);
		if( inputResult == FAIL)
		{
			printf("입력 오류, 문자열 입력\n");
			while( getchar() != '\n');
		}
	} while(inputResult != SUCCESS);
}

