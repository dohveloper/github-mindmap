#ifndef _ARRAY_H
#define _ARRAY_H

typedef signed long int Long;
template <typename T>
class Array
{
public:
	Array(Long capacity = 256);
	Array(const Array& source);
	~Array();

	Long Store(Long index, T object);
	Long Insert(Long index, T object);
	Long AppendFromFront(T object);
	Long AppendFromRear(T object);
	Long Delete(Long index);
	Long DeleteFromFront();
	Long DeleteFromRear();
	void Clear();
	Long Modify(Long index, T object);
	Long LinearSearchUnique(void *key, int(*compare)(void*, void*));
	void LinearSearchDuplicate(void *key, Long *(*indexes), Long *count, int(*compare)(void*, void*));
	Long BinarySearchUnique(void *key, int(*compare)(void*, void*));
	void BinarySearchDuplicate(void *key, Long *(*indexes), Long *count, int(*compare)(void*, void*));
	void BubbleSort(int(*compare)(void*, void*));
	void InsertionSort(int(*compare)(void*, void*));
	void SelectionSort(int(*compare)(void*, void*));
	void MergeSort(const Array &ont, const Array &other, int(*compare)(void*, void*));
	T& GetAt(Long index);

	Long GetCapacity() const;
	Long GetLength() const;

	Array& operator = (const Array& source);
	T& operator[](Long index);
	T* operator+(Long index);

private:
	T(*front);
	Long capacity;
	Long length;
};

template <typename T>
inline Long Array<T>::GetCapacity() const
{
	return this->capacity;
}

template <typename T>
inline Long Array<T>::GetLength() const
{
	return this->length;
}

//Create
template <typename T>
Array<T>::Array(Long capacity)
{
	this->front = new T[capacity];
	this->capacity = capacity;
	this->length = 0;
}

//복사생성자
template <typename T>
Array<T>::Array(const Array& source)
{
	Long i = 0;

	this->front = new T[source.capacity];

	while (i < source.length)
	{
		this->front[i] = source.front[i];
		i++;
	}

	this->capacity = source.capacity;
	this->length = source.length;
}

//소멸자
template <typename T>
Array<T>::~Array()
{
	if (this->front != 0)
	{
		delete[] this->front;
		this->front = 0;
	}
}

//Store
template <typename T>
Long Array<T>::Store(Long index, T object)
{
	this->front[index] = object;
	this->length++;

	return index;
}

//Insert
template <typename T>
Long Array<T>::Insert(Long index, T object)
{
	T(*temp);
	Long i = 0;
	Long j = 0;

	temp = new T[this->capacity + 1];

	while (i < index)
	{
		temp[j] = this->front[i];
		j++;
		i++;
	}
	j++;
	while (i < this->length)
	{
		temp[j] = this->front[i];
		j++;
		i++;
	}

	if (this->front != 0)
	{
		delete[] this->front;
		this->front = 0;
	}

	this->front = temp;
	this->capacity++;
	this->front[index] = object;
	this->length++;

	return index;
}

//AppendFromFront
template <typename T>
Long Array<T>::AppendFromFront(T object)
{
	T(*temp);
	Long i = 0;
	Long j = 1;
	Long index = 0;

	temp = new T[this->capacity + 1];

	while (i < this->length)
	{
		temp[j] = this->front[i];
		j++;
		i++;
	}

	if (this->front != 0)
	{
		delete[] this->front;
		this->front = 0;
	}

	this->front = temp;
	this->capacity++;
	this->front[index] = object;
	this->length++;

	return index;
}

//AppendFromRear
template <typename T>
Long Array<T>::AppendFromRear(T object)
{
	T(*temp);
	Long index;
	Long i = 0;

	temp = new T[this->capacity + 1];

	while (i < this->length)
	{
		temp[i] = this->front[i];
		i++;
	}

	if (this->front != 0)
	{
		delete[] this->front;
		this->front = 0;
	}

	this->front = temp;
	this->capacity++;
	index = this->capacity - 1;
	this->front[index] = object;
	this->length++;

	return index;
}

//Delete
template <typename T>
Long Array<T>::Delete(Long index)
{
	T(*temp) = 0;
	Long i = 0;
	Long j = 0;

	if (this->capacity > 1)
	{
		temp = new T[this->capacity - 1];
	}

	while (i < index)
	{
		temp[j] = this->front[i];
		i++;
		j++;
	}
	i++;
	while (i < this->length)
	{
		temp[j] = this->front[i];
		i++;
		j++;
	}

	if (this->front != 0)
	{
		delete[] this->front;
		this->front = 0;
	}

	if (this->capacity > 1)
	{
		this->front = temp;
	}

	this->capacity--;
	this->length--;
	index = -1;

	return index;
}

//DeleteFromFront
template <typename T>
Long Array<T>::DeleteFromFront()
{
	T(*temp) = 0;
	Long index;
	Long i = 0;
	Long j = 1;

	if (this->capacity > 1)
	{
		temp = new T[this->capacity - 1];
	}

	while (j < this->length)
	{
		i++;
		j++;
	}

	if (this->front != 0)
	{
		delete[] this->front;
		this->front = 0;
	}

	if (this->capacity > 1)
	{
		this->front = temp;
	}

	this->capacity--;
	this->length--;
	index = -1;

	return index;
}

//DeleteFromRear
template <typename T>
Long Array<T>::DeleteFromRear()
{
	T(*temp) = 0;
	Long i = 0;
	Long j = 0;
	Long index;

	if (this->capacity > 1)
	{
		temp = new T[this->capacity - 1];
	}

	while (j < this->capacity - 1)
	{
		temp[i] = this->front[j];
		i++;
		j++;
	}

	if (this->front != 0)
	{
		delete[] this->front;
		this->front = 0;
	}

	if (this->capacity > 1)
	{
		this->front = temp;
	}

	this->capacity--;
	this->length--;
	index = -1;

	return index;
}

template <typename T>
Long Array<T> ::Modify(Long index, T object)
{
	this->front[index] = object;
	return index;
}

template <typename T>
void Array<T> ::Clear()
{
	if (this->front != 0)
	{
		delete[]this->front;
		this->front = 0;
	}

	this->capacity = 0;
	this->length = 0;
}

template <typename T>
Long Array<T> ::LinearSearchUnique(void *key, int(*compare)(void*, void*))
{
	Long index = -1;
	Long i = 0;

	while (i < this->length && compare(this->front + i, key) != 0)
	{
		i++;
	}

	if (i < this->length)
	{
		index = i;
	}

	return index;
}

template <typename T>
void Array<T> ::LinearSearchDuplicate(void *key, Long *(*indexes), Long *count, int(*compare)(void*, void*))
{
	Long i = 0;
	Long j = 0;
	*count = 0;
	*indexes = new Long[this->length];

	while (i < this->length)
	{
		if (compare(this->front + i, key) == 0)
		{
			(*indexes)[j] = i;
			(*count)++;
			j++;
		}
		i++;
	}
}

template <typename T>
Long Array<T> ::BinarySearchUnique(void *key, int(*compare)(void*, void*))
{
	Long index = -1;
	Long start = 0;
	Long end;
	Long mid;
	end = this->length - 1;
	mid = (start + end) / 2;

	while (start <= end && compare(this->front + mid, key) != 0)
	{
		if (compare(this->front + mid, key) < 0)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
		mid = (start + end) / 2;
	}

	if (start <= end)
	{
		index = mid;
	}
	return index;
}

template <typename T>
void Array<T> ::BinarySearchDuplicate(void *key, Long*(*indexes), Long *count, int(*compare)(void*, void*))
{
	Long start = 0;
	Long end;
	Long mid;
	Long i;
	Long j = 0;
	*count = 0;

	*indexes = new Long[this->length];
	end = this->length - 1;
	mid = (start + end) / 2;

	while (start <= end && compare(this->front + mid, key) != 0)
	{
		if (compare(this->front + mid, key) < 0)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
		mid = (start + end) / 2;
	}
	start = mid - 1;
	while (start >= 0 && compare(this->front + start, key) == 0)
	{
		start--;
	}
	i = start + 1;
	while (i < this->length && compare(this->front + start, key) == 0)
	{
		(*indexes)[j] = i;
		j++;
		i++;
	}
}

template <typename T>
T& Array<T> ::operator[](Long index)
{
	return this->front[index];
}

template <typename T>
T* Array<T> ::operator+(Long index)
{
	return this->front + index;
}

template <typename T>
Array<T>& Array<T> ::operator=(const Array& source)
{
	Long i = 0;

	if (this->front != 0)
	{
		delete[]this->front;
	}
	this->front = new T[source.capacity];

	while (i < source.length)
	{
		this->front[i] = source.front[i];
		i++;
	}
	this->capacity = source.capacity;
	this->length = source.length;

	return *this;
}

template <typename T>
T& Array<T>::GetAt(Long index)
{
	return this->front[index];
}

//BubbleSort

template <typename T>

void Array<T>::BubbleSort(int(*compare)(void*, void*))
{
	T temp;
	Long i = 0;
	Long j;

	while (i < this->length - 1)
	{
		j = 0;
		while (j < this->length - i - 1)
		{
			if (compare(this->front + j, this->front + (j + i)) > 0)
			{
				temp = this->front[j];
				this->front[j] = this->front[j + 1];
				this->front[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

//InsertionSort

template <typename T>

void Array<T>::InsertionSort(int(*compare)(void*, void*))
{
	T temp;
	Long i = 1;
	Long j;

	while (i < this->length)
	{
		j = i - 1;
		temp = this->front[i];
		while (j >= 0 && compare(this->front + j, &temp) > 0)
		{
			this->front[j + 1] = this->front[j];
			j--;
		}
		this->front[j + 1] = temp;
		i++;
	}
}

//SelectionSort

template <typename T>

void Array<T>::SelectionSort(int(*compare)(void*, void*))
{
	T temp;
	Long i = 0;
	Long j;
	Long min;

	while (i < this->length - 1)
	{
		min = i;
		j = i + 1;
		while (j < this->length)
		{
			if (compare(this->front + j, this->front + min) > 0)
			{
				min = j;
			}
			j++;
		}
		temp = this->front[min];
		this->front[min] = this->front[i];
		this->front[i] = temp;
		i++;
	}
}

//MergeSort

template <typename T>

void Array<T>::MergeSort(const Array&one, const Array&other, int(*compare)(void*, void*))
{
	Long i = 0;
	Long j = 0;
	Long k = 0;

	if (this->front != 0)
	{
		delete[] this->front;
	}
	this->front = new T[one.length + other.length];
	this->capacity = one.length + other.length;
	this->length = 0;

	while (i < one.length && j < other.length)
	{
		if (compare(one.front + i, other.front + j) <= 0)
		{
			this->front[k] = one.front[i];
			i++;
		}
		else
		{
			this->front[k] = other.front[j];
			j++;
		}
		k++;
		this->length++;
	}
	while (i < one.length)
	{
		this->front[k] = one.front[i];
		this->length++;
		k++;
		i++;
	}
	while (j < other.length)
	{
		this->front[k] = other.front[j];
		this->length++;
		k++;
		j++;
	}
}

#endif //_ARRAY_H