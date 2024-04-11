#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <class T>
class Array {
	private :

	T				*_array;
	unsigned int	_size;

	public :

	Array() {
		_array = new T[1];
		_size = 1;
	};

	Array(unsigned int size){
		_array = new T[size];
		_size = size;
	};

	~Array() {
		delete[] _array;
	}

	Array(const Array &copy) {
		this->_array = new T[copy._size];
		for(unsigned int i = 0; i < copy._size; i++)
			this->_array[i] = copy._array[i];
		this->_size = copy._size;
	};

	Array &operator=(const Array &copy) {
		for(unsigned int i = 0; i < copy._size; i++)
			this->_array[i] = copy._array[i];
		this->_size = copy->_size;
		return (*this);
	};

	T	&operator[](unsigned int num) {
		if (num >= _size)
			throw std::exception();
		return _array[num];
	};
};

#endif