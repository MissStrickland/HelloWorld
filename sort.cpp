#include<iostream>
using namespace std;
//ֱ�Ӳ������� ����Ԫ�ش� [0]��ʼ�洢
//����

//�������� P78
void insertSort(int a[],int n)
{
	cout << "�����ư�" << endl;
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

//���� for for�� �� ���� for while�� �Ĳ���˼����һ���� ֻ�ǽ���ѭ�� �����ֲ�ͬ��ѭ��������˶���
//���������ϵ�һ�ַ����������
void insertSort1(int a[], int n)
{
	cout << "���� for while�� ˼��Ϻ�" << endl;
	for (int i = 1; i < n; ++i)
	{
		int temp = a[i];
		int j = i - 1;
		while (a[j]>temp)//a[j]�������� ������
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;//���� ������浽���һ������temp��a[j]֮�����ڸ��浽֮��j�ȼ���1���ʴ�ʱ���͸��浽�˵�һ��С��temp�������Ӹ�λ�����ҿ������е�a[j]������temp���Ӵ�λ��(������λ��)���󿴣��������ֶ�С��temp���ʽ�temp ������λ�õ���һλ��[j+1],����temp���뵽a[j]֮��a[j+1]=temp;
	}
}
// a[j + 1] = temp;
// ���� ������浽���һ������temp��a[j]֮��
// ���ڸ��浽֮ǰ��whileѭ���� j�ȼ���1���ʴ�ʱ���͸��浽�˵�һ��С��temp������
// �Ӹ�λ�����ҿ������е�a[j]������temp���Ӵ�λ��(������λ��)���󿴣��������ֶ�С��temp��
// �ʽ�temp ������λ�õ���һλ��[j+1],����temp���뵽a[j]֮��a[j+1]=temp;


//ok--�Ӻ���ǰ�ȣ���һ��a[j]>temp;���ݾͺ���һλ���Ƚϵ�ͬʱ��˳��ʵ�������Ƿ����
//https://www.2cto.com/kf/201706/644226.html
void insertSort2(int *a, int n)
{
	cout << "���� for for�� �ӵ�һ�����ݿ�ʼ��һֱ��ǰ������ǰ��Ԫ�ر�" << endl;
	for (int i = 1; i < n; ++i)
	{
		int temp = a[i];
		int j;
		for (j = i - 1; j >= 0 && a[j]>temp; --j)// ��i-1λ�ÿ�ʼ ���ұ�iλ��С���������һֱ���� a[j]>temp,�Ļ�����һֱ��jλ�õ����ݺ��ƣ���������һ��a[j]<=tempʱ���ͽ�����ѭ������������j��λ�õ����ݺ���
			a[j + 1] = a[j];
		a[j + 1] = temp;//���Ƚϵ�Ԫ�ز���
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
	cout << "���� for for�� �� ���� for while�� �Ĳ���˼����һ���� ֻ�ǽ���ѭ�� �����ֲ�ͬ��ѭ��������˶���" << endl;
	return 0;
}