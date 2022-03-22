#include "blob.h"

template <typename T> 
Blob<T>::Blob(size_t size):size(size)
{
	data = new T[size];
	ref_count = new size_t(1);
}

template <typename T>
Blob<T>::~Blob()
{
	--(*ref_count);
	if((*ref_count)==0)
	{
		delete[] data;
		data = nullptr;
		delete ref_count;
		ref_count = nullptr;
	}
}

template <typename T>
Blob<T>::Blob(const Blob<T>& other)
{
	data = other.data;
	ref_count = other.ref_count;
	++(*ref_count);
}

template <typename T>
Blob<T> Blob<T>::operator=(const Blob<T>& other)
{
	if(this!=&other)
	{
		--(*ref_count);
		if((*ref_count)==0)
		{
			delete[] data;
			data = nullptr;
			delete ref_count;
			ref_count = nullptr;

		}
		data = other.data;
		ref_count = other.ref_count;
		++(*ref_count);
	}
	return *this;
}

template class Blob<unsigned char>;
template class Blob<short>;
template class Blob<int>;
template class Blob<float>;
template class Blob<double>;