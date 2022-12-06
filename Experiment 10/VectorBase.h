//VECTORBASE_H
#ifndef VECTORBASE_H
#define VECTORBASE_H
#include<iostream>
using namespace std;

template <class T>
class VectorBase {
protected:
	T* data;
	int size;
public:
	virtual ~VectorBase() = 0;
	virtual void show(ostream& out) const;
	virtual void Add(T t);
	virtual T Pop();
	virtual T& operator[](int index);
	virtual bool isEmpty();
	virtual T& getIndex(int index);
};

template <class T>
VectorBase<T>::~VectorBase() {

}

template <class T>
void VectorBase<T>::show(ostream& out) const {

}

template<class T>
T& VectorBase<T>::getIndex(int index) {
	if (index >= this->size)
	{
		cout << "下标越界" << endl;
		exit(1);
	}
	else return data[index];
}

template <class T>
void VectorBase<T>::Add(T t) {
	T* tp = new T[size + 1]{};
	for (int i = 0; i < size; ++i) {
		tp[i] = this->data[i];
	}
	if (this->data != NULL) delete[] this->data;
	data = tp;
	data[size++] = t;
}

template<class T>
T& VectorBase<T>::operator[](int index)
{
	return getIndex(index);
}

template<class T>
T VectorBase<T>::Pop()
{
	if (size == 0) return 0;
	T* tp = new T[size - 1]{};
	for (int i = 0; i < size - 1; ++i) {
		tp[i] = this->data[i];
	}
	T ret = this->data[size - 1];
	if (this->data != NULL) delete[] this->data;
	data = tp;
	size -= 1;
	return ret;
}

template <class T>
bool VectorBase<T>::isEmpty() {
	return size == 0;
}


#endif