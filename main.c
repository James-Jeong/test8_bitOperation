#include <stdio.h>

///////////////////////////////////////////////////////////////////////////////////////
/// Macros
///////////////////////////////////////////////////////////////////////////////////////

// 2진수 변환에 사용될 정수의 비트 수
#define BIT_NUM 32
// 함수 실행 결과 열거형
enum STATUS
{
	FAIL	= 0,	// 실패
	SUCCESS	= 1,	// 성공
};

/////////////////////////////////////////////////////////////////////////////////////
/// Predefinitions of Local functions
///////////////////////////////////////////////////////////////////////////////////////

void printSigned32bitsNumberToBinary(const int inputValue);
void printUnsigned32bitsNumberToBinary(unsigned const int inputValue);
void input32bitsNumbers(int *signedNumber, unsigned int *unsignedNumber);

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
	int signedInputValue = 0;
	unsigned int unsignedInputValue = 0;

	input32bitsNumbers(&signedInputValue, &unsignedInputValue);

	printSigned32bitsNumberToBinary(signedInputValue);
	printUnsigned32bitsNumberToBinary(unsignedInputValue);

	return SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////////////
/// Local functions
///////////////////////////////////////////////////////////////////////////////////////

/**
 * @fn void printSigned32bitsNumberToBinary(const int inputValue)
 * @brief 부호 있는 32 bits 정수를 이진수로 출력하는 함수
 * @param number 이진수로 출력될 부호 있는 정수(입력)
 * @return 반환값 없음
 */
void printSigned32bitsNumberToBinary(const int inputValue)
{
 	int mask = (signed)0x80000000;
	int loopIndex = 1;
	
	printf("\n입력 받은 정수(signed) : %d\n", inputValue);
	printf("2진수 : ");
	for( ; loopIndex <= BIT_NUM; loopIndex++)
	{
		printf("%c", (inputValue & mask) == 0 ? '0' : '1');
		if(loopIndex % 4 == 0) printf(" ");
		mask >>= 1;
	}
	printf("\n");
}

/**
 * @fn void printUnsigned32bitsNumberToBinary(unsigned const int inputValue)
 * @brief 부호 없는 32 bits 정수를 이진수로 출력하는 함수
 * @param number 이진수로 출력될 부호 없는 정수(입력)
 * @return 반환값 없음
 */
void printUnsigned32bitsNumberToBinary(unsigned const int inputValue)
{
	unsigned int mask = 0x80000000;
	int loopIndex = 1;
	
	printf("\n입력 받은 정수(unsigned) : %d\n", inputValue);
	printf("2진수 : ");
	for( ; loopIndex <= BIT_NUM; loopIndex++)
	{
		printf("%c", (inputValue & mask) == 0 ? '0' : '1');
		if(loopIndex % 4 == 0) printf(" ");
		mask >>= 1;
	}
	printf("\n");
}

/**
 * @fn void input32bitsNumbers(int *signedNumber, unsigned int *unsignedNumber)
 * @brief 부호 있는 32 bits 정수와 부호 없는 32 bits 정수를 입력받는 함수
 * @param signedNumber 입력받을 부호 있는 정수를 저장하는 변수(출력)
 * @param unsignedNumber 입력받을 부호 없는 정수를 저장하는 변수(출력)
 * @return 반환값 없음
 */
void input32bitsNumbers(int *signedNumber, unsigned int *unsignedNumber)
{
	if(signedNumber == NULL || unsignedNumber == NULL)
	{
		printf("잘못된 정수 변수 참조. NULL. (signedNumber:%p, unsignedNumber:%p)\n", signedNumber, unsignedNumber);
		return;
	}

	int inputResult = FAIL;
	do
	{
		printf("부호 있는 32 bit 정수 입력 : ");
		inputResult = scanf(" %d", signedNumber);
		if( inputResult == FAIL)
		{
			printf("입력 오류, 문자열 입력\n");
			while( getchar() != '\n');
		}
	} while(inputResult != SUCCESS);

	do
	{
		printf("부호 없는 32 bit 정수 입력 (양수) : ");
		inputResult = scanf(" %d", unsignedNumber);
		if( inputResult == FAIL)
		{
			printf("입력 오류, 문자열 입력\n");
			while( getchar() != '\n');
		}
	} while(inputResult != SUCCESS);
}

