#include <iostream>

class Number
{
	int base;
	char* value;
	int val(char c);
	char charval(int n);

public:

	Number(const char* value, int base);
	Number(int n);
	Number(const Number& d)
	{
		this->base = d.base;
		this->value = new char[strlen(d.value) + 2];

		for (int i = 0; i < strlen(d.value); i++)
			value[i] = d.value[i];

		this->value[strlen(d.value)] = NULL;
	}
	Number(Number&& d)
	{
		std::swap(base, d.base);
		std::swap(value, d.value);
	}
	~Number();

	friend Number& operator+(Number &i,Number& j);
	friend void operator+=(Number& i, Number& j);
	friend Number& operator-(Number& i, Number& j);
	Number& operator = (int val);
	Number& operator = (const char* val);
	Number& operator = (Number &i);
	bool operator>(Number& i);
	bool operator>=(Number& i);
	bool operator<(Number& i);
	bool operator<=(Number& i);
	bool operator==(Number& i);
	char operator[](int n);
	void operator--();
	void operator--(int val);

	void SwitchBase(int newBase);
	int GetDigitsCount();
	void Print();
	int GetBase();


};