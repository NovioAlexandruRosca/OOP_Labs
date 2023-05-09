#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

class MyCompare : public Compare {
public:
	int CompareElements(void* e1, void* e2) override {

		int* el1 = static_cast<int*>(e1);
		int* el2 = static_cast<int*>(e2);

		if (*el1 > *el2)
			return 1;
		else if (*el1 < *el2)
			return -1;
		else
			return 0;
	}
};


template<class T>

class ArrayIterator

{

private:

	T* ptr;
	int Current;

public:

	ArrayIterator()
	{
		Current = 0;
		ptr = nullptr;
	}

	ArrayIterator(const int index) : Current(index), ptr(nullptr) {}

	ArrayIterator& operator++ ()
	{
		++Current;
		return *this;
	}

	ArrayIterator& operator-- ()
	{
		--Current;
		return *this;
	}

	bool operator= (ArrayIterator<T>& other)
	{
		return Current == other.Current;
	}

	bool operator!=(ArrayIterator<T>& other)
	{
		return Current != other.Current;
	}

	T& operator*() {
		return *ptr[Current];
	}
};

template<class T>

class Array
{

private:

	T** List;
	int Capacity;
	int Size;

public:

	Array()
	{
		Capacity = 0;
		Size = 0;
	}

	~Array()
	{
		delete[] List;
	}

	Array(int capacity)
	{
		Capacity = capacity;
		Size = 0;
		List = new T *[Capacity];
	}

	Array(const Array<T>& otherArray) // constructor de copiere
	{
		List = otherArray.List;
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
	}


	T& operator[] (int index) // arunca exceptie daca index este out of range
	{

		try
		{

			if (index < 0 || index >= Size)
				throw out_of_range("Index out of range");

			return *List[index];
		}
		catch(out_of_range& e)
		{
			cout << "Exceptie: " << e.what() << endl;
			static T defaultV;
			return defaultV;
		}

	}

	const Array<T>& operator+=(const T& newElem)
	{
		if (Size == Capacity)
		{
			T** auxiliar = new T* [Capacity + 1];

			for (int i = 0; i < Capacity; i++)
				auxiliar[i] = List[i];

			delete[] List;

			List = auxiliar;
			Capacity++;

		}

		List[Size] = const_cast<T*>(&newElem);
		Size++;
		return *this;
	}

	const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		try
		{
			if (index < 0 || index > Size)
				throw out_of_range("Invalid index");

			if (index == Size)
			{
				if (Size == Capacity)
				{
					T** auxiliar = new T * [Capacity + 1];

					for (int i = 0; i < Capacity; i++)
						auxiliar[i] = List[i];

					delete[] List;

					List = auxiliar;
					Capacity++;
				}
				Size++;
			}

			List[index] = const_cast<T*>(&newElem);

		}
		catch (out_of_range& e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}

		return *this;
	}

	const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		try
		{
			if (index < 0 || index > Size)
				throw out_of_range("Invalid index");


			for(int i = 0 ; i < otherArray.Size; i++)
			{
				if (index + i == Size)
				{
					if (Size == Capacity)
					{
						T** auxiliar = new T * [Capacity + 1];

						for (int i = 0; i < Capacity; i++)
							auxiliar[i] = List[i];

						delete[] List;

						List = auxiliar;
						Capacity++;
					}
					Size++;
				}

				List[index + i] = otherArray.List[i];
			}

		}
		catch (out_of_range& e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}

		return *this;
	}

	const Array<T>& Delete(int index) 
	{
		try
		{
			if (index < 0 || index >= Size)
				throw out_of_range("Invalid index");


			for (int i = index; i < Size - 1; i++)
				List[i] = List[i + 1];

			Size--;

			Array<T> otherArray(this);

			delete[] List;

			List = otherArray.List;
			Capacity = otherArray.Capacity;
			Size = otherArray.Size;

		}
		catch (out_of_range& e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}

		return *this;
	}

	bool operator==(const Array<T>& otherArray)
	{

		if (Size != otherArray.Size)
			return false;

		for (int i = 0; i < Size ; i++)
		{
			if (List[i] != otherArray.List[i])
				return false;
		}
		return true;
	}

	void Sort()
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i; j < Size; j++)
				if (List[i] > List[j])
				{
					T* aux = List[i];
					List[i] = List[j];
					List[j] = aux;
				}

	}

	void Sort(int(*compare)(const T&, const T&))
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i; j < Size; j++)
				if(compare(List[i],List[j]))
				{
					T* aux = List[i];
					List[i] = List[j];
					List[j] = aux;
				}
	}

	void Sort(Compare* comparator)
	{
		int size = List.Size;

		for (int i = 0; i < size - 1; ++i)
		{
			for (int j = 0; j < size - i - 1; ++j)
			{
				if (comparator->CompareElements(&data[j], &data[j + 1]))
				{
					T* aux = List[i];
					List[i] = List[j];
					List[j] = aux;
				}
			}
		}
	}


	int BinarySearch(const T& elem)
	{

		int left = 0;
		int right = List.Size - 1;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;

			if (*List[mid] == elem)
				return mid;
			else if (*List[mid] < elem)
				left = mid + 1;
			else
				right = mid - 1;
		}

		return -1;
	}

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
	{
		int left = 0;
		int right = List.Size - 1;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			int comparison = compare(*List[mid], elem);

			if (comparison == 0)
				return mid;
			else if (comparison < 0)
				left = mid + 1;
			else
				right = mid - 1;
		}

		return -1;
	}

	int BinarySearch(const T& elem, Compare* comparator)
	{
		int left = 0;
		int right = List.Size - 1;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			int comparison = comparator->CompareElements(*List[mid], elem);

			if (comparison == 0)
				return mid;
			else if (comparison < 0)
				left = mid + 1;
			else
				right = mid - 1;
		}

		return -1;

	}

	int Find(const T& elem)
	{
		for (int i = 0; i < Size; i++)
			if (*List[i] == elem)
				return i;

		return -1;
	}

	int Find(const T& elem, int(*compare)(const T&, const T&))
	{
		int size = List.Size;

		for (int i = 0; i < size; ++i)
		{
			if (compare(*List[i], elem) == 0)
			{
				return i;
			}
		}
		return -1;
	}

	int Find(const T& elem, Compare* comparator)
	{
		int size = List.Size;

		for (int i = 0; i < size; ++i)
		{
			if (comparator->CompareElements(*List[i], &elem) == 0)
			{
				return i;
			}
		}
		return -1;
	}

	int GetSize()
	{
		return Size;
	}
	int GetCapacity()
	{
		return Capacity;
	}

	ArrayIterator<T> GetBeginIterator()
	{
		return ArrayIterator<T>(0);
	}
	ArrayIterator<T> GetEndIterator()
	{
		return ArrayIterator<T>(Size);
	}

};
