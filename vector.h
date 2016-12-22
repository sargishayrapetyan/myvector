#pragma once

template < typename T>
class Vector
{
public:
		  class iterator
		  {
		  public:
			  iterator(T* other)
				  :iter_ptr(other)
			  {
			  }
			  iterator(const iterator& other)
				  : iter_ptr(other.iter_ptr)
			  {
			  }

			  iterator& operator=(const iterator& other)
			  {
				  this->iter_ptr = other.iter_ptr;
				  return *this;
			  }

			  iterator& operator++()
			  {
				  ++iter_ptr;
				  return *this;
			  }

			  iterator operator++(int)
			  {
				  iterator temp(*this);
				  ++(*this);
				  return temp;
			  }

			  iterator& operator--()
			  {
				  --iter_ptr;
				  return *this;
			  }

			  iterator operator--(int)
			  {
				  iterator temp(*this);
				  --(*this);
				  return temp;
			  }

			  iterator& operator+(const int number)
			  { 
				  iterator it(iter_ptr + number);
				  return it;
			  }

			  iterator operator-(const int number)
			  {
				 iterator it(iter_ptr - number);
				 return it;
			  }

			  T& operator*() const
			  {
				  return *iter_ptr;
			  }

			  bool operator==(const iterator& other)
			  {
				  return (this->iter_ptr == other.iter_ptr);
			  }

			  bool operator!=(const iterator& other)
			  {
				  return !(this->iter_ptr == other.iter_ptr);
			  }

		  private:
			  T* iter_ptr;
		  };

public:
	Vector();
	Vector(unsigned size, const T value);
	Vector(std::initializer_list<T>);
	Vector(const Vector&);
	Vector operator=(const Vector&);
	~Vector();

public:
	void push_back(const T&&);
	void pop_back();
	bool isEmpty() const;
	bool isFull() const;

public:
	int get_size() const;

public:
	bool operator==(const Vector&) const;
	bool operator!=(const Vector&) const;
	T& operator[](int);
	const T& operator[](int) const;
	T& at(int);
	const T& at(int) const;
public:
	iterator erase(iterator pos); //unfinished
	iterator begin();
	const iterator begin() const;
	iterator end();
	void insert(int, const T&);

public:
	void clear();
	const T& front() const;
	const T& back() const;
	void reverse();

private:
	int capacity;
	int size;
	T* vectorPtr;
};
//ok
template<typename T>
Vector<T>::Vector()
	: size(0)
	, capacity(0)
	, vectorPtr(nullptr)
{

}
//ok
template<typename T>
Vector<T>::Vector(unsigned s,const T value)
	: capacity(100)
	, size(s)
	, vectorPtr(new T[capacity])
{
	for (int i = 0; i < size; ++i)
		vectorPtr[i] = value;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init_list)
    : vectorPtr(new T[init_list.size()])
	, capacity(100)
{ 
	auto i = init_list.begin();
	for(int index = 0; i != init_list.end(); ++i, ++index)
	{
		vectorPtr[index] = *i;
		++size;
	}
}

//ok
template<typename T>
Vector<T>::Vector(const Vector& other)
	: capacity(other.capacity)
	, size(other.size)
{
	vectorPtr = new T[capacity];
	for (int i = 0; i < size; i++)
		vectorPtr[i] = other.vectorPtr[i];
}
//ok
template<typename T>
Vector<T> Vector<T>::operator=(const Vector& other)
{
	capacity = other.capacity;
	size = other.size;
	delete[] vectorPtr;
	vectorPtr = new T[capacity];
	for (int i = 0; i < size; i++)
		vectorPtr[i] = other.vectorPtr[i];
	return *this;
}
//ok
template<typename T>
Vector<T>::~Vector()
{
	delete vectorPtr;
	vectorPtr = nullptr;
}
//ok
template<typename T>
void Vector<T>::push_back(const T&& pushElement)
{
	if (!isFull()) {
		vectorPtr[size] = pushElement;
		++size;
	}
	else if (isEmpty())
	{
		T* newptr = new T(pushElement);
		vectorPtr = newptr;
		++size;
		++capacity;
	}
	else {
		T *newPtr = new T[(2 * capacity)];
		for (int i = 0; i < size; ++i)
		{
			newPtr[i] = vectorPtr[i];
		}
		newPtr[size] = pushElement;
		++size;

		delete[] vectorPtr;
		vectorPtr = newPtr;
	}
}
//ok
template<typename T>
void Vector<T>::pop_back() 
{
	if (!isEmpty()) {
		T* v = new T[size -1];
		for (int i = 0; i < size - 1; ++i)
		{
			v[i] = vectorPtr[i];
		}
		--size;
		vectorPtr = v;
	}
	
}
//ok
template<typename T>
bool Vector<T>::isEmpty() const
{
	return size == 0;
}

template<typename T>
bool Vector<T>::isFull() const
{
	return size == capacity;
}

template<typename T>
int Vector<T>::get_size() const
{
	return size;
}

template<typename T>
bool Vector<T>::operator==(const Vector& other) const
{
	if (capacity != other.capacity
		|| size != other.size) {
		return false;
	}

	for (int i = 0; i < size; ++i) {
		if (vectorPtr[i] != other.vectorPtr[i]) {
			return false;
		}
	}
}

template<typename T>
bool Vector<T>::operator!=(const Vector& other) const
{
	return !(*this == other);
}

template<typename T>
const T& Vector<T>::operator[](int index) const
{
	return vectorPtr[index];
}
//ok
template <typename T>
T& Vector<T>::operator[](int index)
{
	return vectorPtr[index];
}

template <typename T>
T& Vector<T>::at(int pos)
{
	if (pos < 0 || pos >= size)
		throw std::out_of_range("vector<T>::at() : pos is out of range");
	return vectorPtr[pos];
}

template <typename T>
const T& Vector<T>::at(int pos) const
{
	if (pos < 0 || pos >= size)
		throw std::out_of_range("Vector<T>::at() : pos is out of range");
	return vectorPtr[pos];
}
//ok
template < typename T >
void Vector<T>::insert(int number, const T& other)
{
	unsigned int i = 0;
	T *newptr = new T[capacity];

	if (!isFull()) {
		while (i < capacity)
		{
			if (i == number)
			{
				newptr[i] = other;
				++i;
			}
			newptr[i] = vectorPtr[i];
			++i;

		}
		delete[] vectorPtr;
		vectorPtr = newptr;
	}

	else {
		T *newptr = new T[(2 * capacity)];
		while (i < capacity) {
			if (i = number) {
				newptr[i] = other;
				i++;
			}
			newptr[i] = vectorPtr[i];
		}
		delete[] vectorPtr;
		vectorPtr = newptr;
	}
}

template <typename T>
typename Vector<T>::iterator Vector<T>::erase(typename Vector<T>::iterator pos)
{
	if (!isEmpty())
	{
		T *newptr = new T[capacity];
		typename Vector<T>::iterator it = begin();
		for (int i = 0; i < get_size(); i++)
		{
			if (it == pos)
				continue;
			newptr[i] = vectorPtr[i];
			++it;
		}
	}
	return ++pos;
}

template <typename T>
const T& Vector<T>::front() const
{
	return vectorPtr;
}

template <typename T>
const T& Vector<T>::back() const
{
	return vectorPtr[size - 1];
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
	return vectorPtr;
}

template <typename T>
const typename Vector<T>::iterator Vector<T>::begin() const
{
	return vectorPtr;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end()
{
	return vectorPtr + get_size();
}

template <typename T>
void Vector<T>::clear()
{
	Vector v;
	vectorPtr = v.vectorPtr;
	size = 0;
}

template <typename T>
void Vector<T>::reverse()
{
	Vector other = *this;
	for (int i = 0; i < size; i++) {
		vectorPtr[i] = other[size - 1];
	}
}
