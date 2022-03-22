#ifndef BLOB_H_
#define BLOB_H_
#include <cstddef>

template<typename T>
struct Blob{
	T* data;
	size_t* ref_count;
	size_t size;
	Blob(size_t size);
	Blob(const Blob<T>& other);
	Blob<T> operator=(const Blob<T>& other);
	~Blob();
};

#endif