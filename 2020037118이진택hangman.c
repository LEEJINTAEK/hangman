
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int easy_hangman();
int normal_hangman();
int hard_hangman();
void man(int);
void boy(int);
void girl(int);


void main() {
	int n;
	printf("게임 시작\n");
	printf("---------\n\n\n");
	printf("게임을 고르세요");
	printf("1(하),2(중),3(상)\n");
	scanf_s("%d", &n);
	char replay;   //다시하기 체크

	if (n == 1) {
		easy_hangman();
		while (1) {
			printf("계속하시겠습니까? (y/n)");
			scanf_s(" %c", &replay);

			if (replay == 'y') {
				easy_hangman();
			}
			else if (replay == 'n') {
				printf("게임을 종료합니다.\n");
				break;
			}
			else {
				printf("잘못 입력하셨습니다.\n");
			}
		}
		return 0;

		}
		else if (n==2) {
			normal_hangman();
			while (1) {
				printf("계속하시겠습니까? (y/n)");
				scanf_s(" %c", &replay);

				if (replay == 'y') {
					normal_hangman();
				}
				else if (replay == 'n') {
					printf("게임을 종료합니다.\n");
					break;
				}
				else {
					printf("잘못 입력하셨습니다.\n");
				}
			}
			return 0;
	

		}

		else if (n == 3) {
		hard_hangman();
		while (1) {
			printf("계속하시겠습니까? (y/n)");
			scanf_s(" %c", &replay);

			if (replay == 'y') {
				hard_hangman();
			}
			else if (replay == 'n') {
				printf("게임을 종료합니다.\n");
				break;
			}
			else {
				printf("잘못 입력하셨습니다.\n");
			}
		}
		return 0;

	}
}
int easy_hangman() {
	int s;
	int n = 19;
	char word[19][20] = {
	   {"sophisticated"},{"lax"},{"combine" }, { "accomplish"},{"volunteer"},
	   {"assme"},{"employee"},{"assist"},{"satisfy"},{"manner"},{"responsibility"},
	   {"carry"},{"conduct"},{"adjust"},{"personnel"},{"agree"},
	   {"supervise"},{"coworker"},{"direct"}
	};
	srand(time(NULL));
	s = rand() % n;     //무작위


	char problem[30] = { 0, };
	char answer[30] = { 0, };   //알파벳저장
	char char_answer;        //알파벳을 입력
	int len_answer;        //단어 길이 저장
	int count = 0;        //오답횟수 
	int input_count = 0;  //입력비교 체크


	len_answer = strlen(word[s]);   //문자열길이
	strcpy_s(problem, 20, word[s]);         //problem에 단어 복사 

	for (int i = 0; i < len_answer; i++) {
		answer[i] = '_';                          //뽑힌 문자열 길이 만큼 밑줄 
		printf("%c", answer[i]);
	}


	while (1) {
		scanf_s("%c", &char_answer);         //답 입력
		int right = 0;

		if (char_answer == '\n') {
			printf("\n입력하세요: ");
			continue;
		} // 만약 char_answer가 0 이면 다시 처음부터

		for (int i = 0; i < len_answer; i++)  //문자열 길이 반복
		{
			if (problem[i] == char_answer)   //저장된 i번째 단어와 답이 맞았다
			{
				answer[i] = problem[i];       //answer에 대입
				right = 1;                    //right를 1로 바꾸
				boy(count);
			}

		}
		if (right == 0)
		{
			printf("\n틀렸습니다\n");
			count++;
			boy(count);    //틀렸을 때

		}


		for (int i = 0; i < len_answer; i++)
		{
			printf("%c", answer[i]);

		}
		printf("\n");
		if (strcmp(answer, problem) == 0)
		{
			printf("승리\n");
			break;
		}

		if (count == 10)
		{
			printf("패배\n");
			printf("정답: \"%s\"\n", problem);
			break;
		}
	}
	return 0;
}

int normal_hangman() {

		int s;
		int n = 19;
		char word[19][20] = {
		   {"abate"},{"claim"},{"complain" }, { "conserve"},{"debate"},
		   {"declare"},{"eliminate"},{"encounter"},{"imply"},{"impose"},{"offend"},
		   {"praise"},{"refer"},{"refuse"},{"split"},{"suspect"},
		   {"state"},{"reference"},{"recommend"}
		};
		srand(time(NULL));
		s = rand() % n;     //무작위


		char problem[30] = { 0, };
		char answer[30] = { 0, };   //알파벳저장
		char char_answer;        //알파벳을 입력
		int len_answer;        //단어 길이 저장
		int count = 0;        //오답횟수 
		int input_count = 0;  //입력비교 체크


		len_answer = strlen(word[s]);   //문자열길이
		strcpy_s(problem, 20, word[s]);         //problem에 단어 복사 

		for (int i = 0; i < len_answer; i++) {
			answer[i] = '_';                          //뽑힌 문자열 길이 만큼 밑줄 
			printf("%c", answer[i]);
		}
	

		while (1) {
			scanf_s("%c", &char_answer);         //답 입력
			int right = 0;

			if (char_answer == '\n') {
				printf("\n입력하세요: ");
				continue;
			} // 만약 char_answer가 0 이면 다시 처음부터

			for (int i = 0; i < len_answer; i++)  //문자열 길이 반복
			{
				if (problem[i] == char_answer)   //저장된 i번째 단어와 답이 맞았다
				{
					answer[i] = problem[i];       //answer에 대입
					right = 1;                    //right를 1로 바꾸
					man(count);
				}

			}
			if (right == 0)
			{
				printf("\n틀렸습니다\n");
				count++;
				man(count);    //틀렸을 때

			}


			for (int i = 0; i < len_answer; i++)
			{
				printf("%c", answer[i]);

			}
			printf("\n");
			if (strcmp(answer, problem) == 0)
			{
				printf("승리\n");
				break;
			}

			if (count == 8)
			{
				printf("패배\n");
				printf("정답: \"%s\"\n", problem);
				break;
			}
		}
		return 0;
	}

int hard_hangman(){
	int s;
	int n = 19;
	char word[19][20] = {
		{"usher"},{"moderate"},{"conceit" }, {"capable"},{"durable"},
	   {"fabricate"},{"comprehensible"},{"accidently"},{"satisfy"},{"revenue"},{"sovereignty"},
	   {"prosperous"},{"nominate"},{"verify"},{"further"},{"authentic"},
	   {"antibiotic"},{"commemorate"},{"persist"}
	};
	srand(time(NULL));
	s = rand() % n;     //무작위


	char problem[30] = { 0, };
	char answer[30] = { 0, };   //알파벳저장
	char char_answer;        //알파벳을 입력
	int len_answer;        //단어 길이 저장
	int count = 0;        //오답횟수 
	int input_count = 0;  //입력비교 체크


	len_answer = strlen(word[s]);   //문자열길이
	strcpy_s(problem, 20, word[s]);         //problem에 단어 복사 

	for (int i = 0; i < len_answer; i++) {
		answer[i] = '_';                          //뽑힌 문자열 길이 만큼 밑줄 
		printf("%c", answer[i]);
	}
	

	while (1) {
		scanf_s("%c", &char_answer);         //답 입력
		int right = 0;

		if (char_answer == '\n') {
			printf("\n입력하세요: ");
			continue;
		} // 만약 char_answer가 0 이면 다시 처음부터

		for (int i = 0; i < len_answer; i++)  //문자열 길이 반복
		{
			if (problem[i] == char_answer)   //저장된 i번째 단어와 답이 맞았다
			{
				answer[i] = problem[i];       //answer에 대입
				right = 1;                    //right를 1로 바꾸
				girl(count);
			}

		}
		if (right == 0)
		{
			printf("\n틀렸습니다\n");
			count++;
			girl(count);    //틀렸을 때

		}


		for (int i = 0; i < len_answer; i++)
		{
			printf("%c", answer[i]);

		}
		printf("\n");
		if (strcmp(answer, problem) == 0)
		{
			printf("승리\n");
			break;
		}

		if (count == 5)
		{
			printf("패배\n");
			printf("정답: \"%s\"\n", problem);
			break;
		}
	}
	return 0;
}



void girl(int c) {
	if (c == 0)
	{
		printf("   ____ \n");
		printf("  |    |\n");
		printf("       |\n");
		printf("       |\n");
		printf("       |\n");
		printf("       |\n");
	}
	else if (c == 1) {

		printf("   ____ \n");
		printf("  |    |\n");
		printf("  O    |\n");
		printf(" <|>   |\n");
		printf("       |\n");
		printf("       |\n");

	}
	else if (c == 2) {

		printf("   ____ \n");
		printf("  |    |\n");
		printf("  O    |\n");
		printf(" <|>   | \n");
		printf(" ((     |\n");
		printf("       |\n");
	}

	else if (c == 3) {
		printf("   ____ \n");
		printf("  |    |\n");
		printf("  O    |\n");
		printf(" <|>   |\n");
		printf(" ((    |\n");
		printf("끼     |\n");

	}

	else if (c == 4) {


		printf("   ____ \n");
		printf("  |    |\n");
		printf("  O    |\n");
		printf(" <|>   |\n");
		printf(" ((    |\n");
		printf("끼약   |\n");
	}

	else if (c == 5) {
		printf("   ____ \n");
		printf("  |    |\n");
		printf("  O    |\n");
		printf(" <|>   |\n");
		printf(" ((    |\n");
		printf("끼약!~ |\n");

	}

}



	void man(int c) {
		if (c == 0)
		{
			printf("   ____ \n");
			printf("  |    |\n");
			printf("       |\n");
			printf("       |\n");
			printf("       |\n");
			printf("       |\n");
		}
		else if (c == 1) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf("       |\n");
			printf("       |\n");
			printf("       |\n");

		}
		else if (c == 2) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" /     |\n");
			printf("       |\n");
			printf("       |\n");
		}

		else if (c == 3) {
			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" /|    |\n");
			printf("       |\n");
			printf("       |\n");

		}

		else if (c == 4) {


			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" /|>   |\n");
			printf("       |\n");
			printf("       |\n");

		}

		else if (c == 5) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" /|>   |\n");
			printf(" /     |\n");
			printf("       |\n");
		}
		else if (c == 6) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" /|>   |\n");
			printf(" / L   |\n");
			printf("       |\n");
		}

		else if (c == 7) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" /|>   |\n");
			printf(" / L   |\n");
			printf("으~    |\n");
		}

		else if (c == 8) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" /|>   |\n");
			printf(" / L   |\n");
			printf("으~악  |\n");
		}
	}


	void boy(int c) {
		if (c == 0)
		{
			printf("   ____ \n");
			printf("  |    |\n");
			printf("       |\n");
			printf("       |\n");
			printf("       |\n");
			printf("       |\n");
		}
		else if (c == 1) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf("       |\n");
			printf("       |\n");
			printf("       |\n");

		}
		else if (c == 2) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" <     |\n");
			printf("       |\n");
			printf("       |\n");
		}

		else if (c == 3) {
			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" <|    |\n");
			printf("       |\n");
			printf("       |\n");

		}

		else if (c == 4) {


			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" <|>   |\n");
			printf("       |\n");
			printf("       |\n");

		}

		else if (c == 5) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" <|>   |\n");
			printf(" <     |\n");
			printf("       |\n");
		}
		else if (c == 6) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" <|>   |\n");
			printf(" < >   |\n");
			printf("       |\n");
		}

		else if (c == 7) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" <|>   |\n");
			printf(" < >   |\n");
			printf("응     |\n");
		}

		else if (c == 8) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" <|>   |\n");
			printf(" < >   |\n");
			printf("응애   |\n");
		}
		else if (c == 9) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" <|>   |\n");
			printf(" < >   |\n");
			printf("응애ㅠ |\n");
		}
		else if (c == 10) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" <|>   |\n");
			printf(" < >   |\n");
			printf("응애ㅠㅠ|\n");
		}
	}