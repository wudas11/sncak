#include<stdio.h>
#include<string.h>
int number = 0;
char user[20];
char password[20];

void test2()
{
	getchar();
	printf("��������Ҫע����˻�\n");
	gets_s(user, 20);
	printf("��������Ҫʹ�õ�����\n");
	gets_s(password,20);
	number++;
}
int test1()
{
	char user1[20];
	char password1[20];
	int i = 0;
	if (number == 0) {
		printf("����ע��\n");
		return 0;
	}
	getchar();
	printf("�����˺�");
	gets_s(user1, 20);
	printf("��������");
	gets_s(password1, 20);
	i=strcmp(user1, user);
	i+=strcmp(password1, password);
	if (i == 0) {
		printf("��¼�ɹ����ø�������\n");
	}
	return 0;
}
int test()
{
	int i=0;
		printf("* * * * * * * * * *\n");
		printf("     1.��¼\n");
		printf("     2.ע��\n");
		printf("     0.�˳�\n");
		printf("     ��ѡ��\n");
		printf("* * * * * * * * * *\n");
		scanf_s("%d", &i);
		if (i > 2 ||i < 0) {
			test();
		}
	return i;
}
int main()
{
	printf("��ӭ��������������\n");
	int a=test();
	while (a) {
		if (a == 1) {
			test1(number);
		}
		else test2();
		a = test();
	}
}