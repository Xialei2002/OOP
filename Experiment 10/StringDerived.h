//STRINGDERIVED_H
#ifndef STRINGDERIVED_H
#define STRINGDERIVED_H
#include "VectorBase.h"
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class mystring: public VectorBase<char> {
public:
	mystring(const char* str = "");
	virtual ~mystring();
	mystring(const mystring& str);
	mystring(const mystring& str, int pos, int n);
	mystring(const char* s, int n);
	mystring(int n, char c);
	mystring& insert(int p0, const char* s);		// 将s所指向的字符串插入在本串位置p0之前
	mystring substr(int pos, int n) const;			// 取子串，取本串位置pos开始的n个字符，构成新对象
	int find(const mystring& str) const;
	void swap(mystring& str);
	int length() const;
	const char* c_str() const;
	friend istream& operator>> (istream& in, mystring& str);
	friend ostream& operator<<(ostream& out, mystring& str);
	mystring& operator=(const mystring& str);
	friend mystring operator+(const mystring& str1, const mystring& str2);
	mystring& operator+=(const mystring& str);
	bool operator<(const mystring& str) const;
	bool operator<=(const mystring& str) const;
	bool operator>(const mystring& str) const;
	bool operator>=(const mystring& str) const;
	char& operator[](int index);
	virtual void show(ostream& out);
	bool operator==(const mystring& str) const;
	bool operator!=(const mystring& str) const;
};

mystring::mystring(const char* str) {
	size = strlen(str);
	data = new char[size + 1]{};
	strcpy(data, str);
}

mystring::~mystring() {
	if (data != nullptr) {
		delete[] data;
		data = nullptr;
		size = 0;
	}
}

mystring::mystring(const mystring& str) {
	this->size = str.size;
	data = new char[this->size + 1]{};
	strcpy(data, str.data);
}

mystring& mystring::operator=(const mystring& str) {
	if (this->data != nullptr) {
		delete[] this->data;
		this->data = nullptr;
		this->size = 0;
	}
	this->size = str.size;
	data = new char[this->size + 1]{};
	strcpy(data, str.data);
	return *this;
}

mystring::mystring(const mystring& str, int pos, int n) {
	if (pos > str.length())pos = str.length();
	if (pos + n > str.size) {
		n = str.size - pos;
	}
	this->size = n;
	this->data = new char[n + 1]{};
	for (int i = 0, j = pos; i < n; ++i, ++j) {
		this->data[i] = str.data[j];
	}
}

mystring::mystring(const char* s, int n) {
	int slen = strlen(s);
	if (n > slen)n = slen;
	this->size = n;
	this->data = new char[n + 1]{};
	for (int i = 0; i < n; ++i) {
		this->data[i] = s[i];
	}
}

mystring::mystring(int n, char c) {
	this->size = n;
	this->data = new char[n + 1]{};
	for (int i = 0; i < n; ++i) {
		this->data[i] = c;
	}
}

mystring& mystring::insert(int p0, const char* s) {
	int slen = strlen(s);
	if (p0 > this->size) {
		p0 = this->size;
	}
	char* tp = new char[this->size + slen + 1]{};
	for (int i = 0; i < p0; ++i) {
		tp[i] = this->data[i];
	}
	for (int i = p0, j = 0; j < slen; ++i, ++j) {
		tp[i] = s[j];
	}
	for (int i = p0 + slen, j = p0; j < this->size + slen; ++i, ++j) {
		tp[i] = this->data[j];
	}
	this->size = this->size + slen;
	this->data = tp;
	return *this;
}

mystring mystring::substr(int pos, int n) const {
	mystring tp(*this, pos, n);
	return tp;
}

int mystring::find(const mystring& str) const {
	if (this->size < str.size) return -1;
	for (int i = 0; i < this->size; i++) {
		if (this->data[i] == str.data[0]) {
			int p = i, q = 0;
			while (p < this->size && q < str.size) {
				if (this->data[p] == str.data[q]) {
					p++;
					q++;
				}
				else {
					break;
				}
			}
			if (q == str.size) return i;
		}
	}
	return -1;
}

void mystring::swap(mystring& str) {
	char* temp = this->data;
	this->data = str.data;
	str.data = temp;
	int length = this->size;
	this->size = str.size;
	str.size = length;
}


const char* mystring::c_str() const {
	char* str = new char[this->size + 1]{};
	strcpy(str, this->data);
	return str;
}

mystring operator+(const mystring& str1, const mystring& str2) {
	char* temp = new char[str1.size + str2.size + 1]{};
	strcpy(temp, str1.data);
	strcat(temp, str2.data);
	mystring ret;
	ret.size = str1.size + str2.size;
	ret.data = temp;
	return ret;
}

mystring& mystring::operator+=(const mystring& str) {
	char* temp = new char[this->size + str.size + 1]{};
	strcpy(temp, this->data);
	strcat(temp, str.data);
	this->data = temp;
	this->size = this->size + str.size;
	return *this;
}

char& mystring::operator[](int index) {
	try {
		if (index >= this->size) {
			throw index;
		}
		return this->data[index];
	}
	catch (int) {
		cerr << "下标越界！" << endl;
		exit(1);
	}
}

int mystring::length() const {
	return this->size;
}

istream& operator>>(istream& in, mystring& str) {
	if (str.data != nullptr) {
		delete[] str.data;
		str.data = nullptr;
		str.size = 0;
	}
	char* tp = new char[1000]{};
	in >> tp;
	str.size = strlen(tp);
	str.data = new char[str.size + 1]{};
	strcpy(str.data, tp);
	delete[] tp;
	return in;
}

void mystring::show(ostream& out) {
	out << data;
}

ostream& operator<<(ostream& out, mystring& str) {
	out << str.data;
	return out;
}

bool mystring::operator<(const mystring& str) const {
	return strcmp(this->data, str.data) < 0 ? true : false;
}

bool mystring::operator<=(const mystring& str) const {
	return strcmp(this->data, str.data) <= 0 ? true : false;
}

bool mystring::operator>(const mystring& str) const {
	return strcmp(this->data, str.data) > 0 ? true : false;
}

bool mystring::operator>=(const mystring& str) const {
	return strcmp(this->data, str.data) >= 0 ? true : false;
}

bool mystring::operator==(const mystring& str) const {
	return strcmp(this->data, str.data) == 0 ? true : false;
}

bool mystring::operator!=(const mystring& str) const {
	return strcmp(this->data, str.data) != 0 ? true : false;
}

#endif