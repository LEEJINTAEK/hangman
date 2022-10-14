
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
	printf("���� ����\n");
	printf("---------\n\n\n");
	printf("������ ������");
	printf("1(��),2(��),3(��)\n");
	scanf_s("%d", &n);
	char replay;   //�ٽ��ϱ� üũ

	if (n == 1) {
		easy_hangman();
		while (1) {
			printf("����Ͻðڽ��ϱ�? (y/n)");
			scanf_s(" %c", &replay);

			if (replay == 'y') {
				easy_hangman();
			}
			else if (replay == 'n') {
				printf("������ �����մϴ�.\n");
				break;
			}
			else {
				printf("�߸� �Է��ϼ̽��ϴ�.\n");
			}
		}
		return 0;

		}
		else if (n==2) {
			normal_hangman();
			while (1) {
				printf("����Ͻðڽ��ϱ�? (y/n)");
				scanf_s(" %c", &replay);

				if (replay == 'y') {
					normal_hangman();
				}
				else if (replay == 'n') {
					printf("������ �����մϴ�.\n");
					break;
				}
				else {
					printf("�߸� �Է��ϼ̽��ϴ�.\n");
				}
			}
			return 0;
	

		}

		else if (n == 3) {
		hard_hangman();
		while (1) {
			printf("����Ͻðڽ��ϱ�? (y/n)");
			scanf_s(" %c", &replay);

			if (replay == 'y') {
				hard_hangman();
			}
			else if (replay == 'n') {
				printf("������ �����մϴ�.\n");
				break;
			}
			else {
				printf("�߸� �Է��ϼ̽��ϴ�.\n");
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
	s = rand() % n;     //������


	char problem[30] = { 0, };
	char answer[30] = { 0, };   //���ĺ�����
	char char_answer;        //���ĺ��� �Է�
	int len_answer;        //�ܾ� ���� ����
	int count = 0;        //����Ƚ�� 
	int input_count = 0;  //�Էº� üũ


	len_answer = strlen(word[s]);   //���ڿ�����
	strcpy_s(problem, 20, word[s]);         //problem�� �ܾ� ���� 

	for (int i = 0; i < len_answer; i++) {
		answer[i] = '_';                          //���� ���ڿ� ���� ��ŭ ���� 
		printf("%c", answer[i]);
	}


	while (1) {
		scanf_s("%c", &char_answer);         //�� �Է�
		int right = 0;

		if (char_answer == '\n') {
			printf("\n�Է��ϼ���: ");
			continue;
		} // ���� char_answer�� 0 �̸� �ٽ� ó������

		for (int i = 0; i < len_answer; i++)  //���ڿ� ���� �ݺ�
		{
			if (problem[i] == char_answer)   //����� i��° �ܾ�� ���� �¾Ҵ�
			{
				answer[i] = problem[i];       //answer�� ����
				right = 1;                    //right�� 1�� �ٲ�
				boy(count);
			}

		}
		if (right == 0)
		{
			printf("\nƲ�Ƚ��ϴ�\n");
			count++;
			boy(count);    //Ʋ���� ��

		}


		for (int i = 0; i < len_answer; i++)
		{
			printf("%c", answer[i]);

		}
		printf("\n");
		if (strcmp(answer, problem) == 0)
		{
			printf("�¸�\n");
			break;
		}

		if (count == 10)
		{
			printf("�й�\n");
			printf("����: \"%s\"\n", problem);
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
		s = rand() % n;     //������


		char problem[30] = { 0, };
		char answer[30] = { 0, };   //���ĺ�����
		char char_answer;        //���ĺ��� �Է�
		int len_answer;        //�ܾ� ���� ����
		int count = 0;        //����Ƚ�� 
		int input_count = 0;  //�Էº� üũ


		len_answer = strlen(word[s]);   //���ڿ�����
		strcpy_s(problem, 20, word[s]);         //problem�� �ܾ� ���� 

		for (int i = 0; i < len_answer; i++) {
			answer[i] = '_';                          //���� ���ڿ� ���� ��ŭ ���� 
			printf("%c", answer[i]);
		}
	

		while (1) {
			scanf_s("%c", &char_answer);         //�� �Է�
			int right = 0;

			if (char_answer == '\n') {
				printf("\n�Է��ϼ���: ");
				continue;
			} // ���� char_answer�� 0 �̸� �ٽ� ó������

			for (int i = 0; i < len_answer; i++)  //���ڿ� ���� �ݺ�
			{
				if (problem[i] == char_answer)   //����� i��° �ܾ�� ���� �¾Ҵ�
				{
					answer[i] = problem[i];       //answer�� ����
					right = 1;                    //right�� 1�� �ٲ�
					man(count);
				}

			}
			if (right == 0)
			{
				printf("\nƲ�Ƚ��ϴ�\n");
				count++;
				man(count);    //Ʋ���� ��

			}


			for (int i = 0; i < len_answer; i++)
			{
				printf("%c", answer[i]);

			}
			printf("\n");
			if (strcmp(answer, problem) == 0)
			{
				printf("�¸�\n");
				break;
			}

			if (count == 8)
			{
				printf("�й�\n");
				printf("����: \"%s\"\n", problem);
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
	s = rand() % n;     //������


	char problem[30] = { 0, };
	char answer[30] = { 0, };   //���ĺ�����
	char char_answer;        //���ĺ��� �Է�
	int len_answer;        //�ܾ� ���� ����
	int count = 0;        //����Ƚ�� 
	int input_count = 0;  //�Էº� üũ


	len_answer = strlen(word[s]);   //���ڿ�����
	strcpy_s(problem, 20, word[s]);         //problem�� �ܾ� ���� 

	for (int i = 0; i < len_answer; i++) {
		answer[i] = '_';                          //���� ���ڿ� ���� ��ŭ ���� 
		printf("%c", answer[i]);
	}
	

	while (1) {
		scanf_s("%c", &char_answer);         //�� �Է�
		int right = 0;

		if (char_answer == '\n') {
			printf("\n�Է��ϼ���: ");
			continue;
		} // ���� char_answer�� 0 �̸� �ٽ� ó������

		for (int i = 0; i < len_answer; i++)  //���ڿ� ���� �ݺ�
		{
			if (problem[i] == char_answer)   //����� i��° �ܾ�� ���� �¾Ҵ�
			{
				answer[i] = problem[i];       //answer�� ����
				right = 1;                    //right�� 1�� �ٲ�
				girl(count);
			}

		}
		if (right == 0)
		{
			printf("\nƲ�Ƚ��ϴ�\n");
			count++;
			girl(count);    //Ʋ���� ��

		}


		for (int i = 0; i < len_answer; i++)
		{
			printf("%c", answer[i]);

		}
		printf("\n");
		if (strcmp(answer, problem) == 0)
		{
			printf("�¸�\n");
			break;
		}

		if (count == 5)
		{
			printf("�й�\n");
			printf("����: \"%s\"\n", problem);
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
		printf("��     |\n");

	}

	else if (c == 4) {


		printf("   ____ \n");
		printf("  |    |\n");
		printf("  O    |\n");
		printf(" <|>   |\n");
		printf(" ((    |\n");
		printf("����   |\n");
	}

	else if (c == 5) {
		printf("   ____ \n");
		printf("  |    |\n");
		printf("  O    |\n");
		printf(" <|>   |\n");
		printf(" ((    |\n");
		printf("����!~ |\n");

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
			printf("��~    |\n");
		}

		else if (c == 8) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" /|>   |\n");
			printf(" / L   |\n");
			printf("��~��  |\n");
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
			printf("��     |\n");
		}

		else if (c == 8) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" <|>   |\n");
			printf(" < >   |\n");
			printf("����   |\n");
		}
		else if (c == 9) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" <|>   |\n");
			printf(" < >   |\n");
			printf("���֤� |\n");
		}
		else if (c == 10) {

			printf("   ____ \n");
			printf("  |    |\n");
			printf("  O    |\n");
			printf(" <|>   |\n");
			printf(" < >   |\n");
			printf("���֤Ф�|\n");
		}
	}