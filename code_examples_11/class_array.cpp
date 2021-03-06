// class_array.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <exception>
#include <stdexcept>
#define FIRST_SIZE 20
#define ADD_MEM 10

class BaseArray
{
public:
	BaseArray() {};
	virtual ~BaseArray() {};
};

template <typename T>
class Array : public BaseArray
{
private:
	T * * array;
	int capacity;
	int length;

public:
	Array();
	Array(int);
	Array(const Array<T> &);

	void add(const T&);
	void del(int);
	void show() const;

	int len() const;
	int search() const;

	T& operator [](int) const;
	T** resize(int);

	~Array();
};

template <typename T>
Array<T>::Array()
{
	if ((array = (T**)calloc(FIRST_SIZE, sizeof(T*))) == NULL)
		throw "Exception: Memmory_except";
	capacity = FIRST_SIZE;
	length = 0;
}

template <typename T>
Array<T>::Array(int size)
{
	if ((array = (T**)calloc(size, sizeof(T*))) == NULL)
		throw "Exception: Memmory_except";
	capacity = size;
	length = 0;
}

template <typename T>
Array<T>::Array(const Array<T>& elem_arr)
{
	if ((array = (T**)calloc(elem_arr.capacity, sizeof(T*))) == NULL)
		throw "Exception: Memmory_except";
	capacity = elem_arr.capacity;
	length = elem_arr.len();

	for (int i = 0; i < length; i++)
		array[i] = new T(elem_arr[i]);
}

template <typename T>
int Array<T>::len() const
{
	return length;
}

template <typename T>
Array<T>::~Array()
{
	for (int i = 0; i < length; i++)
		free(array[i]);
	free(array);
}

template <typename T>
void Array<T>::add(const T& elem)
{
	if (length == capacity)
		array = resize(capacity + ADD_MEM);

	array[length++] = new T(elem);
}

template <typename T>
void Array<T>::del(int Pos) // Корявое удаление, но реализуется легко ?!
{
	if (Pos < 0 || Pos >= length)
		throw "Range Except";

	length--;
	T temp = array[Pos];
	array[Pos] = array[length];
	delete temp;
}

template <typename T>
void Array<T>::show() const
{
	for (int i = 0; i < length; i++)
	{
		cout << *array[i] << "  ";
	}
	cout << endl;
}

template <typename T>
T** Array<T>::resize(int size)
{
	if ((array = (T**)realloc(array, sizeof(T*)*size)) == NULL)
		throw "Exception: Memmory_except";

	capacity = size;
	return array;
}


int main()
{
	Array<int> A;
    return 0;
}

