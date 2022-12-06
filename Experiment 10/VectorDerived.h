//VECTORDERIVED_H
#ifndef VECTORDERIVED_H
#define VECTORDERIVED_H
#include "VectorBase.h"
#include <iostream>
using namespace std;

template<class T>
class mVector:public VectorBase<T> {
public:
	mVector(int dimension = 0, T* arr = NULL);
	mVector(mVector<T>& v);
	virtual ~mVector();
	int getDim() const;
	void setDim(int newDim);
	void copy(const T* start, const T* end);
	mVector<T>& operator=(const mVector<T>& v);
	virtual void show(ostream& out) const ;
	template<class T>
	friend ostream& operator<<(ostream& out, const mVector<T>& v);
	template<class T>
	friend mVector<T> operator+(const mVector<T>& v1, const mVector<T>& v2);
	template<class T>
	friend mVector<T> operator-(const mVector<T>& v1, const mVector<T>& v2);
	mVector<T>& operator+=(const mVector<T>& v);
	bool operator==(const mVector<T>& v);
	bool operator!=(const mVector<T>& v);
};

//template<class T>
//T& mVector<T>::get(int index) {
//	if (index >= this->size)
//	{
//		cout << "下标越界" << endl;
//		exit(1);
//	}
//	else return this->data[index];
//}
//
//template<class T>
//T& mVector<T>::operator[](int index)
//{
//	return get(index);
//}

template<class T>
bool mVector<T>::operator==(const mVector<T>& v) {
	if (this->size != v.getDim())return false;
	else {
		for (int i = 0; i < getDim(); ++i) {
			if (this->data[i] != v.data[i]) {
				return false;
			}
		}
		return true;
	}
}

template<class T>
bool mVector<T>::operator!=(const mVector<T>& v) {
	if (!(*this == v)) return true;
	else return false;
}

template<class T>
mVector<T>::mVector(int dimension, T* arr) {
	if (dimension <= 0) {
		this->size = 0;
		this->data = NULL;
		return;
	}
	this->size = dimension;
	this->data = new T[this->size]{};
	if (arr != NULL) {
		for (int i = 0; i < this->size; i++) {
			this->data[i] = arr[i];
		}
	}
}

template<class T>
mVector<T>::mVector(mVector<T>& v) {
	this->data = NULL;
	if (this->size = v.getDim() != 0) {
		this->data = new T[this->size]{};
		for (int i = 0; i < this->size; i++) {
			this->data[i] = v[i];
		}
	}
}

template<class T>
mVector<T>::~mVector() {
	if (this->data != NULL) delete[] this->data;
}

template<class T>
int mVector<T>::getDim() const {
	return this->size;
}

template<class T>
void mVector<T>::setDim(int dimension) {
	if (this->size == dimension) return;
	T* tp = new T[dimension]{};
	if (this->size < dimension) {
		for (int i = 0; i < this->size; i++) {
			tp[i] = this->data[i];
		}
		for (int j = this->size; j < dimension; j++) {
			tp[j] = (T)0;
		}
	}
	else if (this->size > dimension) {
		for (int i = 0; i < dimension; i++) {
			tp[i] = this->data[i];
		}
	}
	this->size = dimension;
	this->data = tp;
}

template<class T>
void mVector<T>::copy(const T* start, const T* end) {
	int dimension = end - start + 1;
	if (this->data != NULL) {
		this->size = 0;
		delete[] this->data;
		this->data = NULL;
	}
	this->data = new T[dimension]{};
	for (int i = 0; i < dimension; i++) {
		this->data[i] = *(start + i);
	}
	this->size = dimension;
}

template<class T>
mVector<T>& mVector<T>::operator=(const mVector<T>& v)
{
	if (&v == this) return *this;
	if (this->data != NULL) delete[] this->data;				// 主动释放原有资源
	this->data = NULL;
	if (this->size = v.getDim() != 0)
	{
		this->data = new T[v.getDim()];
		for (int i = 0; i < this->size; i++)
			this->data[i] = v.data[i];
	}
	return *this;
}

template<class T>
mVector<T> operator+(const mVector<T>& v1, const mVector<T>& v2)
{
	if (v1.getDim() != v2.getDim())
	{
		cout << "无法相加" << endl;
		return NULL;
	}
	int dimension = v1.size;
	mVector<T> V(dimension);
	for (int i = 0; i < dimension; i++)
	{
		V[i] = v1.data[i] + v2.data[i];
	}
	return V;
}

template<class T>
mVector<T> operator-(const mVector<T>& v1, const mVector<T>& v2) {
	if (v1.getDim() != v2.getDim())
	{
		cout << "无法相减" << endl;
		return NULL;
	}
	int dimension = v1.getDim();
	mVector<T> V(v1.getDim());
	for (int i = 0; i < dimension; i++) {
		V[i] = v1.data[i] - v2.data[i];
	}
	return V;
}

template<class T>
ostream& operator<< (ostream& out, const mVector<T>& v)
{
	v.show(out);
	return out;
}

template<class T>
void mVector<T>::show(ostream& out) const {
	if (this->size == 0) {
		out << "()";
		return;
	}
	out << "(" << this->data[0];
	for (int i = 1; i < this->size; i++)
		out << ", " << this->data[i];
	out << ")";
}



template<class T>
mVector<T>& mVector<T>::operator+=(const mVector<T>& v) {
	if (this->size != v.getDim()) {
		cout << "无法相加" << endl;
		return *this;
	}
	mVector<T> V(v.getDim());
	for (int i = 0; i < v.getDim(); i++) {
		this->data[i] += v[i];
	}
	return *this;
}



#endif