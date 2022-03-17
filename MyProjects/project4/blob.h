#ifndef BLOB_H_
#define BLOB_H_
#include <cstddef>

template<typename T>
struct Blob{
	T* data=nullptr;
	size_t* ref_count;
	Blob(size_t size);
	Blob(const Blob<T>& other);
	Blob<T> operator=(const Blob<T>& other);
	~Blob();
};

#endif