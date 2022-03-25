#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100; i++) {
//		printf("%d\t", i);
//	}
//}
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <10; i++) {
//		printf("wuhu\n");
//		arr[i] = 0;
//	}
//
//}
void test2()
{
	printf("hehe");
}
void test1()
{
	test2();
}
void test() 
{
	test1();
}
int main()
{
	test();
	return 0;
}