#include <iostream>
#include <conio.h>
#include "VectorBase.h"
#include "VectorDerived.h"
#include "StringDerived.h"
#pragma warning(disable:4996)

using namespace std;

void testCreate() {
	//���캯������
	int arr[4] = { 1,2,3,4 };
	mVector<int> v1;
	mVector<int> v2(4);
	mVector<int> v3(4, arr);
	mVector<int> v4(v3);
	cout << v1 << v2 << v3 << v4 << endl;

}

void testSetGetShow() {
	//getDim,setDim,Show����
	char arr[4] = { 'a','b','c','d' };
	mVector<char> v1(4, arr);
	cout << "v1:";
	v1.show(cout);
	cout << endl << "v1��ά����" << v1.getDim() << endl;
	v1.setDim(6);
	cout << "v1:" << v1 << endl << "v1��ά����" << v1.getDim() << endl;
	v1.setDim(2);
	cout << "v1:" << v1 << endl << "v1��ά����" << v1.getDim() << endl;
}

void testAddPopVeccpy() {
	//Add,Pop,veccpy����
	int arr[4] = { 1,2,3,4 };
	mVector<int> v1(2);
	cout << "v1:" << v1 << endl << "v1ά����" << v1.getDim() << endl;;
	v1.copy(arr, arr + 3);
	cout << "v1:" << v1 << endl << "v1ά����" << v1.getDim() << endl;
	v1.Add(50);
	cout << "v1:" << v1 << endl << "v1ά����" << v1.getDim() << endl;
	int tp = v1.Pop();
	cout << tp << "��ɾ����v1:" << v1 << endl << "v1ά����" << v1.getDim() << endl;
}

void testOperator() {
	//operator
	//=,<<
	int arr[4] = { 1,2,3,4 };
	mVector<int> v1(4, arr);
	mVector<int> v2(1);
	v2 = v1;
	cout << "v2:" << v2 << endl;
	//+,-
	//cout << "v1:" << v1 << endl;
	cout << "v1+v2:" << v1 + v2 << endl;
	cout << "v1-v2:" << v1 - v2 << endl;
	mVector<int> v3(2);
	cout << "v3:" << v3 << endl;
	cout << "v1+v3:" << v1 + v3 << endl;
	cout << "v1-v3:" << v1 - v3 << endl;
	//==,!=
	if (v1 == v2) cout << "v1==v2" << endl;
	if (v1 != v2) cout << "v1!=v2" << endl;
	if (v1 == v3) cout << "v1==v3" << endl;
	if (v1 != v3) cout << "v1!=v3" << endl;
}

void testIndexOutOfRange() {
	int arr[4] = { 1,2,3,4 };
	mVector<int> v1(4, arr);
	cout << "�����޸�v1[10]��ֵ��" << endl;
	v1[10] = 100;
}

//���캯��/IO����
void testCreateIO() {
	cout << "���캯�����ԣ�" << endl;
	char str[] = "HelloWorld!!";
	cout << "��ǰ�ַ���str��" << str << endl;
	mystring test1(str);
	cout << "���캯����mystring(const char* str = \"\"); ��str�����Զ����ַ���test1��" << test1 << endl;
	mystring test2(test1, 2, 5);
	cout << "���캯����mystring(const mystring& str, int pos, int n); ��test1, pos=2, n=5�����Զ����ַ���test2��" << test2 << endl;
	mystring test2_0(test1, 2, 500);
	cout << "���캯����mystring(const mystring& str, int pos, int n); ��test1, pos=2, n=500�����Զ����ַ���test2_0��" << test2_0 << endl;
	mystring test2_1(test1, 200, 500);
	cout << "���캯����mystring(const mystring& str, int pos, int n); ��test1, pos=200, n=500�����Զ����ַ���test2_1��" << test2_1 << endl;
	mystring test3(str, 9);
	cout << "���캯����mystring(const char* s, int n); ��str, n=9�����Զ����ַ���test3��" << test3 << endl;
	mystring test3_0(str, 900);
	cout << "���캯����mystring(const char* s, int n); ��str, n=900�����Զ����ַ���test3_0��" << test3_0 << endl;
	mystring test4(8, 'a');
	cout << "���캯����mystring(int n, char c); ��n=8, c='a'�����Զ����ַ���test4��" << test4 << endl;
	cout << endl << "I/O���ԣ�" << endl;
	mystring test5;
	cout << "�����ַ�����" << endl;
	cin >> test5;
	cout << "���ַ���Ϊ��" << test5 << endl;
}

//�����ַ�������λ�ò���
void testFind() {
	mystring test0("HelloWorld!!");
	cout << "��ǰ�Զ����ַ���test0��" << test0 << endl;
	cout << "���ԣ�int find(const mystring& str) const;" << endl;
	char str1[] = "123";
	cout << "��strΪ\"123\"�����Ϊ" << test0.find(str1) << endl;
	char str2[] = "llo";
	cout << "��strΪ\"llo\"�����Ϊ" << test0.find(str2) << endl;
}

//�������ַ�������
void testSwap() {
	mystring test0("HelloWorld!!");
	cout << "��ǰ�Զ����ַ���test0��" << test0 << endl;
	cout << "���ԣ�void swap(mystring& str);" << endl;
	mystring test1("HelloOOP!!");
	cout << "��ǰ�Զ����ַ���test1��" << test1 << endl;
	test0.swap(test1);
	cout << "ִ��test0.swap(test1); \n�����test0��" << test0 << "\ttest1��" << test1 << endl;
}

//�ַ�������/C�ַ���ת������
void testLenCstr() {
	mystring test0("HelloWorld!!");
	cout << "��ǰ�Զ����ַ���test0��" << test0 << endl;
	cout << "���ԣ�int length() const;" << endl;
	cout << "test0���ȣ�" << test0.length() << endl;
	char p[80]{};
	cout << "���ԣ�const char* c_str() const;" << endl;
	strcpy(p, test0.c_str());
	cout << "��test0.c_str()���Ƶ��ַ���p��" << p << endl;
}

//�����ַ�������
void testInsert() {
	mystring test0("HelloWorld!!");
	cout << "��ǰ�Զ����ַ���test0��" << test0 << endl;
	cout << "���ԣ�mystring& insert(int p0, const char* s);" << endl;
	test0.insert(3, "0123");
	cout << "��p0=3λ�ò����ַ���str=\"0123\"��" << test0 << endl;
	test0.insert(100, "0123");
	cout << "��p0=100λ�ò����ַ���str=\"0123\"��" << test0 << endl;
}

//ȡ�ַ����Ӵ�����
void testSubstr() {
	mystring test0("HelloWorld!!");
	cout << "��ǰ�Զ����ַ���test0��" << test0 << endl;
	cout << "���ԣ�mystring substr(int pos, int n) const;" << endl;
	mystring sub0 = test0.substr(2, 5);
	cout << "��p0=2��ʼȡn=5���ַ����Ӵ�sub0��" << sub0 << endl;
	mystring sub1 = test0.substr(2, 500);
	cout << "��p0=2��ʼȡn=500���ַ����Ӵ�sub1��" << sub1 << endl;
	mystring sub2 = test0.substr(200, 500);
	cout << "��p0=200��ʼȡn=500���ַ����Ӵ�sub2��" << sub2 << endl;
}

//��������ز���
void testOperator2() {
	mystring test0("HelloWorld!!"), test1("HelloOOP!");
	cout << "��ǰ�Զ����ַ���test0��" << test0 << "test1��" << test1 << endl;
	test0 += test1;
	cout << "���ԣ�test0+=test1��+=���������test0��" << test0 << endl;
	mystring test2;
	test2 = test0 + test1;
	cout << "���ԣ�test2=test0+test1��+�������=���������test2��" << test2 << endl;
	test0[5] = '-';
	cout << "���ԣ�test0[5] = '-'��[]���������test0=" << test0 << endl;
	cout << endl << "���Թ�ϵ�������" << endl;
	mystring test3 = "abcd", test4 = "abce";
	cout << "��ǰ�Զ����ַ���test3��" << test3 << "\ttest4��" << test4 << endl;
	if (test3 < test4)cout << "<��������ԣ�test3<test4" << endl;
	if (test3 <= test4)cout << "<=��������ԣ�test3<=test4" << endl;
	if (test4 > test3)cout << ">��������ԣ�test4>test3" << endl;
	if (test4 >= test3)cout << ">=��������ԣ�test4>=test3" << endl;
	if (test3 == test3)cout << "==��������ԣ�test3==test3" << endl;
	if (test3 != test4)cout << "!=��������ԣ�test3!=test4" << endl;
}

//�±�Խ��
void testIndexOutOfRange2() {
	mystring test0("HelloWorld!!");
	cout << "��ǰ�Զ����ַ���test0��" << test0 << endl;
	cout << "���ԣ�test0[1000] = '-'��[]������±�Խ�磩" << endl;
	test0[1000] = '-';
}

int main() {
	cout << "?" << endl;
	int c = getch();
	if (c == 1) {
		while (1) {
			cout << endl << endl;
			cout << "------mVector�����------" << endl;
			cout << "1.���캯������" << endl;
			cout << "2.��ȡά�ȣ��޸�ά�ȣ������������" << endl;
			cout << "3.ά�����ţ�veccpy����" << endl;
			cout << "4.��������ز���" << endl;
			cout << "5.�±�Խ�����" << endl;
			cout << "0.�˳�" << endl;
			cout << "------------------------" << endl;
			int choice = getch() - '0';
			cout << endl;
			switch (choice) {
			case 1:cout << "1.���캯������" << endl; testCreate(); break;
			case 2:cout << "2.��ȡά�ȣ��޸�ά�ȣ������������" << endl; testSetGetShow(); break;
			case 3:cout << "3.ά�����ţ�veccpy����" << endl; testAddPopVeccpy(); break;
			case 4:cout << "4.��������ز���" << endl; testOperator(); break;
			case 5:cout << "5.�±�Խ�����" << endl; testIndexOutOfRange(); break;
			default:cout << "���˳���" << endl; return 0;
			}
		}
	}
	else {
		while (1) {
			cout << endl << endl;
			cout << "------mystring�����------" << endl;
			cout << "1.���캯��/IO����" << endl;
			cout << "2.�����ַ�������λ�ò���" << endl;
			cout << "3.�������ַ�������" << endl;
			cout << "4.�ַ�������/C�ַ���ת������" << endl;
			cout << "5.�����ַ�������" << endl;
			cout << "6.ȡ�ַ����Ӵ�����" << endl;
			cout << "7.��������ز���" << endl;
			cout << "8.�±�Խ��" << endl;
			cout << "0.�˳�" << endl;
			int choice = getch() - '0';
			cout << endl;
			switch (choice) {
			case 1:cout << "1.���캯��/IO����" << endl; testCreateIO(); break;
			case 2:cout << "2.�����ַ�������λ�ò���" << endl; testFind(); break;
			case 3:cout << "3.�������ַ�������" << endl; testSwap(); break;
			case 4:cout << "4.�ַ�������/C�ַ���ת������" << endl; testLenCstr(); break;
			case 5:cout << "5.�����ַ�������" << endl; testInsert(); break;
			case 6:cout << "6.ȡ�ַ����Ӵ�����" << endl; testSubstr(); break;
			case 7:cout << "7.��������ز���" << endl; testOperator2(); break;
			case 8:cout << "8.�±�Խ��" << endl; testIndexOutOfRange2(); break;
			default:cout << "���˳���" << endl; return 0;
			}
		}
	}
	
}