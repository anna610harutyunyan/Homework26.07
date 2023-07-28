#include <iostream>
template <typename T>

class Array
{
	int m_size;
	T* ptr = nullptr;
public:
	Array<T>(int size) : m_size(size)
	{
		ptr = new T[size];
		std::cout << "Call parametrized constructor " << std::endl;
	}
	Array(const Array& obj)
	{
		this->m_size = obj.m_size;
		this->ptr = new T[m_size];
		for (int i = 0; i < m_size; ++i)
		{
			ptr[i] = obj.ptr[i];
		}
		std::cout << " Call Copy" << __func__ << std::endl;
	}
	Array& operator=(const Array& other)
	{
		if (this == &other)
		{
			return *this;
		}
		this->m_size = other.m_size;
		delete[] this->ptr;
		this->ptr = new T[m_size];
		for (int i = 0; i < m_size; ++i)
		{
			ptr[i] = other.ptr[i];
		}
		std::cout << "Call " << __func__ << std::endl;

		return *this;

	}
	Array(Array<&& obj)
	{
		this->m_size = obj.m_size;
		this->ptr = obj.ptr;
		obj.m_size = 0;
		obj.ptr = nullptr;
		std::cout << "Call move constructor " << std::endl;

	}
	Array& operator =(Array&& obj)
	{
		if (this != &obj)
		{
			delete[] this->ptr;
			this->m_size = obj.m_size;
			this->ptr = obj.ptr;
			obj.m_size = 0;
			obj.ptr = nullptr;
		}
		std::cout << "Call move operator assignment " << std::endl;
		return *this;

	}
	~Array()
	{
		std::cout << "Call destructor " << std::endl;
		delete[] ptr;
		ptr = nullptr;
	}
public:
	void Push_back(T newValue)
	{
		T* newPtr = new T[m_size + 1];
		for (int i = 0; i < m_size; ++i)
		{
			newPtr[i] = ptr[i];
		}

		newPtr[m_size] = newValue;
		delete[] ptr;
		ptr = newPtr;
		m_size++;
		std::cout << __func__ << std::endl;
	}
	void Pop_back(T extra)
	{
		T* newPtr = new T[m_size - 1];
		for (int i = 0; i < (m_size - 1); ++i)
		{
			newPtr[i] = ptr[i];
		}

		delete[] ptr;
		ptr = newPtr;
		m_size--;
		std::cout << __func__ << std::endl;
	}
};


int main(int argc, char** argv)
{
	Array <int> obj(5);
	Array<char> obj1(7);
	Array<double> obj2(10);
	obj2.Pop_back(5);
	obj.Push_back(1);

	return 0;
}