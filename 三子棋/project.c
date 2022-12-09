#define _CRT_SECURE_NO_WARNINGS

#include"game.h"


void menu()
{
	printf("��ѡ��:\n");
	printf("*******************************************\n");
	printf("*********         1. Play         *********\n");
	printf("*********         0. Exit         *********\n");
	printf("*******************************************\n");
	printf("������:");
}

void game()
{
	//�洢���� - ��ά����
	char board[ROW][COL];
	//�����ʼ�� - �ո�
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		//��ҿ�ʼ����
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//��������
		ret = IsWin(board, ROW, COL);

		if (ret != 'C')//�ж����Ӯ����
			break;

		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("��Ӯ�ˣ�����\n");
	else if (ret == '#')
		printf("�����ˣ�����\n");
	else printf("ƽ��\n");
	DisplayBoard(board, ROW, COL);
	printf("\n������\n");
}
//���Ӯ�� *
//����Ӯ�� #
//ƽ��     Q
//����     C

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:game();
			break;
		case 0:printf("��Ϸ����");
			return 0;
			break;
		default:printf("��Ȥ��������\n");
			break;
		}
	} while (input);
	return 0;
}