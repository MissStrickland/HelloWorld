#include<iostream>
using namespace std;
//直接插入排序 数据元素从 [0]开始存储
//升序

//王晓云书 P78
void insertSort(int a[],int n)
{
	cout << "王晓云版" << endl;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (a[j]>a[i])
			{
				int temp = a[i];
				for (int k = i; k>j; --k)
					a[k] = a[k - 1];
				a[j] = temp;
			}
		}
	}
}

//网上 for for版 与 网上 for while版 的插入思想是一样的 只是将内循环 用两种不同的循环体表现了而已
//来自于网上的一种方法，已理解
void insertSort1(int a[], int n)
{
	cout << "网上 for while版 思想较好" << endl;
	for (int i = 1; i < n; ++i)
	{
		int temp = a[i];
		int j = i - 1;
		while (a[j]>temp)//a[j]（从左到右 递增）
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;//跟随 向左跟随到最后一个大于temp的a[j]之后，由于跟随到之后，j先减了1，故此时，就跟随到了第一个小于temp的数，从该位置向右看，所有的a[j]都大于temp，从此位置(包括此位置)向左看，所有数字都小于temp，故将temp 赋给此位置的下一位置[j+1],即将temp插入到a[j]之后，a[j+1]=temp;
	}
}
// a[j + 1] = temp;
// 跟随 向左跟随到最后一个大于temp的a[j]之后，
// 由于跟随到之前，while循环中 j先减了1，故此时，就跟随到了第一个小于temp的数，
// 从该位置向右看，所有的a[j]都大于temp，从此位置(包括此位置)向左看，所有数字都小于temp，
// 故将temp 赋给此位置的下一位置[j+1],即将temp插入到a[j]之后，a[j+1]=temp;


//ok--从后往前比，比一个a[j]>temp;数据就后移一位：比较的同时，顺便实现数据是否后移
//https://www.2cto.com/kf/201706/644226.html
void insertSort2(int *a, int n)
{
	cout << "网上 for for版 从第一个数据开始就一直往前看，和前面元素比" << endl;
	for (int i = 1; i < n; ++i)
	{
		int temp = a[i];
		int j;
		for (j = i - 1; j >= 0 && a[j]>temp; --j)// 从i-1位置开始 查找比i位置小的数，如果一直都是 a[j]>temp,的话，就一直将j位置的数据后移，当遇到第一个a[j]<=temp时，就结束该循环，结束将第j个位置的数据后移
			a[j + 1] = a[j];
		a[j + 1] = temp;//将比较的元素插入
	}
}

void test()
{
	cout << "-----------------test--------------------" << endl;

	int a1[] = { 5, 3, 6, 2, 4, 8, 2, 1 };
	int n = sizeof(a1) / sizeof(a1[0]);

	for (auto c : a1)
		cout << c << "\t";
	cout << endl;

	cout << "after sort" << endl;
	insertSort(a1, n);

	for (auto c : a1)
		cout << c << "\t";
	cout << endl;
}

void test1()
{
	cout << "-----------------test1-------------------" << endl;

	int a1[] = { 5, 3, 6, 2, 4, 8, 2, 1 };
	int n = sizeof(a1) / sizeof(a1[0]);

	for (auto c : a1)
		cout << c << "\t";
	cout << endl;

	cout << "after sort" << endl;
	insertSort1(a1, n);

	for (auto c : a1)
		cout << c << "\t";
	cout << endl;
}
void test2()
{
	cout << "-----------------test2-------------------" << endl;

	int a1[] = { 5, 3, 6, 2, 4, 8, 2, 1 };
	int n = sizeof(a1) / sizeof(a1[0]);

	for (auto c : a1)
		cout << c << "\t";
	cout << endl;

	cout << "after sort" << endl;
	insertSort2(a1, n);

	for (auto c : a1)
		cout << c << "\t";
	cout << endl;
}

int main()
{
	test();
	test1();
	test2();
	cout << "网上 for for版 与 网上 for while版 的插入思想是一样的 只是将内循环 用两种不同的循环体表现了而已" << endl;
	return 0;
}