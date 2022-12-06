#include <iostream>
#include <conio.h>
#include "VectorBase.h"
#include "VectorDerived.h"
#include "StringDerived.h"
#pragma warning(disable:4996)

using namespace std;

void testCreate() {
	//构造函数测试
	int arr[4] = { 1,2,3,4 };
	mVector<int> v1;
	mVector<int> v2(4);
	mVector<int> v3(4, arr);
	mVector<int> v4(v3);
	cout << v1 << v2 << v3 << v4 << endl;

}

void testSetGetShow() {
	//getDim,setDim,Show测试
	char arr[4] = { 'a','b','c','d' };
	mVector<char> v1(4, arr);
	cout << "v1:";
	v1.show(cout);
	cout << endl << "v1的维数：" << v1.getDim() << endl;
	v1.setDim(6);
	cout << "v1:" << v1 << endl << "v1的维数：" << v1.getDim() << endl;
	v1.setDim(2);
	cout << "v1:" << v1 << endl << "v1的维数：" << v1.getDim() << endl;
}

void testAddPopVeccpy() {
	//Add,Pop,veccpy测试
	int arr[4] = { 1,2,3,4 };
	mVector<int> v1(2);
	cout << "v1:" << v1 << endl << "v1维数：" << v1.getDim() << endl;;
	v1.copy(arr, arr + 3);
	cout << "v1:" << v1 << endl << "v1维数：" << v1.getDim() << endl;
	v1.Add(50);
	cout << "v1:" << v1 << endl << "v1维数：" << v1.getDim() << endl;
	int tp = v1.Pop();
	cout << tp << "被删除，v1:" << v1 << endl << "v1维数：" << v1.getDim() << endl;
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
	cout << "尝试修改v1[10]的值。" << endl;
	v1[10] = 100;
}

//构造函数/IO测试
void testCreateIO() {
	cout << "构造函数测试：" << endl;
	char str[] = "HelloWorld!!";
	cout << "当前字符串str：" << str << endl;
	mystring test1(str);
	cout << "构造函数：mystring(const char* str = \"\"); 由str构造自定义字符串test1：" << test1 << endl;
	mystring test2(test1, 2, 5);
	cout << "构造函数：mystring(const mystring& str, int pos, int n); 由test1, pos=2, n=5构造自定义字符串test2：" << test2 << endl;
	mystring test2_0(test1, 2, 500);
	cout << "构造函数：mystring(const mystring& str, int pos, int n); 由test1, pos=2, n=500构造自定义字符串test2_0：" << test2_0 << endl;
	mystring test2_1(test1, 200, 500);
	cout << "构造函数：mystring(const mystring& str, int pos, int n); 由test1, pos=200, n=500构造自定义字符串test2_1：" << test2_1 << endl;
	mystring test3(str, 9);
	cout << "构造函数：mystring(const char* s, int n); 由str, n=9构造自定义字符串test3：" << test3 << endl;
	mystring test3_0(str, 900);
	cout << "构造函数：mystring(const char* s, int n); 由str, n=900构造自定义字符串test3_0：" << test3_0 << endl;
	mystring test4(8, 'a');
	cout << "构造函数：mystring(int n, char c); 由n=8, c='a'构造自定义字符串test4：" << test4 << endl;
	cout << endl << "I/O测试：" << endl;
	mystring test5;
	cout << "输入字符串：" << endl;
	cin >> test5;
	cout << "该字符串为：" << test5 << endl;
}

//查找字符串出现位置测试
void testFind() {
	mystring test0("HelloWorld!!");
	cout << "当前自定义字符串test0：" << test0 << endl;
	cout << "测试：int find(const mystring& str) const;" << endl;
	char str1[] = "123";
	cout << "当str为\"123\"，结果为" << test0.find(str1) << endl;
	char str2[] = "llo";
	cout << "当str为\"llo\"，结果为" << test0.find(str2) << endl;
}

//交换两字符串测试
void testSwap() {
	mystring test0("HelloWorld!!");
	cout << "当前自定义字符串test0：" << test0 << endl;
	cout << "测试：void swap(mystring& str);" << endl;
	mystring test1("HelloOOP!!");
	cout << "当前自定义字符串test1：" << test1 << endl;
	test0.swap(test1);
	cout << "执行test0.swap(test1); \n结果：test0：" << test0 << "\ttest1：" << test1 << endl;
}

//字符串长度/C字符串转换测试
void testLenCstr() {
	mystring test0("HelloWorld!!");
	cout << "当前自定义字符串test0：" << test0 << endl;
	cout << "测试：int length() const;" << endl;
	cout << "test0长度：" << test0.length() << endl;
	char p[80]{};
	cout << "测试：const char* c_str() const;" << endl;
	strcpy(p, test0.c_str());
	cout << "将test0.c_str()复制到字符串p：" << p << endl;
}

//插入字符串测试
void testInsert() {
	mystring test0("HelloWorld!!");
	cout << "当前自定义字符串test0：" << test0 << endl;
	cout << "测试：mystring& insert(int p0, const char* s);" << endl;
	test0.insert(3, "0123");
	cout << "在p0=3位置插入字符串str=\"0123\"：" << test0 << endl;
	test0.insert(100, "0123");
	cout << "在p0=100位置插入字符串str=\"0123\"：" << test0 << endl;
}

//取字符串子串测试
void testSubstr() {
	mystring test0("HelloWorld!!");
	cout << "当前自定义字符串test0：" << test0 << endl;
	cout << "测试：mystring substr(int pos, int n) const;" << endl;
	mystring sub0 = test0.substr(2, 5);
	cout << "从p0=2开始取n=5个字符作子串sub0：" << sub0 << endl;
	mystring sub1 = test0.substr(2, 500);
	cout << "从p0=2开始取n=500个字符作子串sub1：" << sub1 << endl;
	mystring sub2 = test0.substr(200, 500);
	cout << "从p0=200开始取n=500个字符作子串sub2：" << sub2 << endl;
}

//运算符重载测试
void testOperator2() {
	mystring test0("HelloWorld!!"), test1("HelloOOP!");
	cout << "当前自定义字符串test0：" << test0 << "test1：" << test1 << endl;
	test0 += test1;
	cout << "测试：test0+=test1（+=运算符），test0：" << test0 << endl;
	mystring test2;
	test2 = test0 + test1;
	cout << "测试：test2=test0+test1（+运算符，=运算符），test2：" << test2 << endl;
	test0[5] = '-';
	cout << "测试：test0[5] = '-'（[]运算符），test0=" << test0 << endl;
	cout << endl << "测试关系运算符：" << endl;
	mystring test3 = "abcd", test4 = "abce";
	cout << "当前自定义字符串test3：" << test3 << "\ttest4：" << test4 << endl;
	if (test3 < test4)cout << "<运算符测试：test3<test4" << endl;
	if (test3 <= test4)cout << "<=运算符测试：test3<=test4" << endl;
	if (test4 > test3)cout << ">运算符测试：test4>test3" << endl;
	if (test4 >= test3)cout << ">=运算符测试：test4>=test3" << endl;
	if (test3 == test3)cout << "==运算符测试：test3==test3" << endl;
	if (test3 != test4)cout << "!=运算符测试：test3!=test4" << endl;
}

//下标越界
void testIndexOutOfRange2() {
	mystring test0("HelloWorld!!");
	cout << "当前自定义字符串test0：" << test0 << endl;
	cout << "测试：test0[1000] = '-'（[]运算符下标越界）" << endl;
	test0[1000] = '-';
}

int main() {
	cout << "?" << endl;
	int c = getch();
	if (c == 1) {
		while (1) {
			cout << endl << endl;
			cout << "------mVector类测试------" << endl;
			cout << "1.构造函数测试" << endl;
			cout << "2.获取维度，修改维度，输出向量测试" << endl;
			cout << "3.维度缩放，veccpy测试" << endl;
			cout << "4.运算符重载测试" << endl;
			cout << "5.下标越界测试" << endl;
			cout << "0.退出" << endl;
			cout << "------------------------" << endl;
			int choice = getch() - '0';
			cout << endl;
			switch (choice) {
			case 1:cout << "1.构造函数测试" << endl; testCreate(); break;
			case 2:cout << "2.获取维度，修改维度，输出向量测试" << endl; testSetGetShow(); break;
			case 3:cout << "3.维度缩放，veccpy测试" << endl; testAddPopVeccpy(); break;
			case 4:cout << "4.运算符重载测试" << endl; testOperator(); break;
			case 5:cout << "5.下标越界测试" << endl; testIndexOutOfRange(); break;
			default:cout << "已退出。" << endl; return 0;
			}
		}
	}
	else {
		while (1) {
			cout << endl << endl;
			cout << "------mystring类测试------" << endl;
			cout << "1.构造函数/IO测试" << endl;
			cout << "2.查找字符串出现位置测试" << endl;
			cout << "3.交换两字符串测试" << endl;
			cout << "4.字符串长度/C字符串转换测试" << endl;
			cout << "5.插入字符串测试" << endl;
			cout << "6.取字符串子串测试" << endl;
			cout << "7.运算符重载测试" << endl;
			cout << "8.下标越界" << endl;
			cout << "0.退出" << endl;
			int choice = getch() - '0';
			cout << endl;
			switch (choice) {
			case 1:cout << "1.构造函数/IO测试" << endl; testCreateIO(); break;
			case 2:cout << "2.查找字符串出现位置测试" << endl; testFind(); break;
			case 3:cout << "3.交换两字符串测试" << endl; testSwap(); break;
			case 4:cout << "4.字符串长度/C字符串转换测试" << endl; testLenCstr(); break;
			case 5:cout << "5.插入字符串测试" << endl; testInsert(); break;
			case 6:cout << "6.取字符串子串测试" << endl; testSubstr(); break;
			case 7:cout << "7.运算符重载测试" << endl; testOperator2(); break;
			case 8:cout << "8.下标越界" << endl; testIndexOutOfRange2(); break;
			default:cout << "已退出。" << endl; return 0;
			}
		}
	}
	
}