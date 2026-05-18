#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
private:
	T* _array;
	unsigned int _size;

public:
	Array() : _array(NULL), _size(0)
	{
	}

	Array(unsigned int n) : _array(new T[n]()), _size(n)
	{
	}

	Array(const Array& other) : _array(NULL), _size(0)
	{
		if (other._size > 0)
		{
			_array = new T[other._size]();
			for (unsigned int i = 0; i < other._size; ++i)
			{
				_array[i] = other._array[i];
			}
		}
		_size = other._size;
	}

	~Array()
	{
		delete[] _array;
	}

	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			delete[] _array;
			_array = NULL;
			_size = 0;
			if (other._size > 0)
			{
				_array = new T[other._size]();
				for (unsigned int i = 0; i < other._size; ++i)
				{
					_array[i] = other._array[i];
				}
			}
			_size = other._size;
		}
		return *this;
	}

	T& operator[](unsigned int index)
	{
		if (index >= _size)
		{
			throw std::exception();
		}
		return _array[index];
	}

	const T& operator[](unsigned int index) const
	{
		if (index >= _size)
		{
			throw std::exception();
		}
		return _array[index];
	}

	unsigned int size() const
	{
		return _size;
	}
};

#endif