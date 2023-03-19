#include "Number.h"
#include <string.h>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

Number::Number(const char* valuee, int basee)         // CONSTRUCTOR
{
	this->value = new char[strlen(valuee) + 1];
	strcpy(this->value,valuee);
	this->base = basee;
}

Number::Number(int n)
{
    this->base = 10;

    string temp_str = to_string(n);
    char const* number_array = temp_str.c_str();

    this->value = new char[strlen(number_array) + 1];
    strcpy(this->value, number_array);

}
 
Number::~Number()                  // DESTERUCTOR
{
	delete[] this->value;
	this->base = 0;
}

void Number::Print()
{
	cout << "Valoarea numarului este = " << this->value << endl;
}

int Number::GetDigitsCount()
{
	return strlen(this -> value);	
}

int Number::GetBase()
{
	return this->base;
}
///    SWITCH BASE    ///
int Number::val(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

char Number::charval(int num)
{

    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

void Number::SwitchBase(int newBase)
{   
    int new_number = 0;
    int old_number;
    int rest = 0;

    for (int i = Number::GetDigitsCount() - 1; i >= 0; i--)
    {
        new_number += val(this->value[i]) * pow(this->base, Number::GetDigitsCount() - i - 1);
    }

    old_number = new_number;
    int dimensiune = 0;
    this->base = newBase;
    delete[] this->value;
    this->value = new char[1];

    do {
        rest = old_number % newBase;

            char* copie = new char[dimensiune + 2];

            for (int i = 0; i < dimensiune; i++)
                copie[i] = this->value[i];

                copie[dimensiune] = charval(rest);
                dimensiune++;

            delete[] this->value;

            this->value = copie;
        
        old_number /= newBase;

    } while (old_number > 0);

      this->value[dimensiune] = NULL;
      strrev(this->value);

}

///    SWITCH BASE    ///
Number& operator+ (Number& i, Number& j)
{
    int base1 = i.base;
    int base2 = j.base;

    i.SwitchBase(10);
    j.SwitchBase(10);

    int x = atoi(i.value);
    int y = atoi(j.value);

    string temp_str = to_string(x + y);
    char const* number_array = temp_str.c_str();

    Number* Digital = new Number(number_array, 10);
    Digital->SwitchBase(max(base1, base2));

    i.SwitchBase(base1);
    j.SwitchBase(base2);

    return *Digital;
}

void operator+=(Number& i, Number& j)
{
    int base1 = i.base;
    int base2 = j.base;

    i.SwitchBase(10);
    j.SwitchBase(10);

    int x = atoi(i.value);
    int y = atoi(j.value);

    string temp_str = to_string(x + y);
    char const* number_array = temp_str.c_str();

    delete[] i.value;
    i.value = new char[strlen(number_array) + 1];
    strcpy(i.value, number_array);

    i.SwitchBase(max(base1, base2));
    j.SwitchBase(base2);
}

Number& operator- (Number& i, Number& j)
{
    int base1 = i.base;
    int base2 = j.base;

    i.SwitchBase(10);
    j.SwitchBase(10);

    int x = atoi(i.value);
    int y = atoi(j.value);

    string temp_str = to_string(abs(x - y));
    char const* number_array = temp_str.c_str();

    Number* Digital = new Number(number_array, 10);
    Digital->SwitchBase(max(base1, base2));

    i.SwitchBase(base1);
    j.SwitchBase(base2);

    return *Digital;
}

bool Number::operator<(Number& i)                          // < //
{
    int base1 = base;
    int base2 = i.base;

    SwitchBase(10);
    i.SwitchBase(10);

    int x = atoi(value);
    int y = atoi(i.value);

    SwitchBase(base1);
    i.SwitchBase(base2);

    if (x < y)
        return true;
    else
        return false;

}

bool Number::operator<=(Number& i)                          // <= //
{
    int base1 = base;
    int base2 = i.base;

    SwitchBase(10);
    i.SwitchBase(10);

    int x = atoi(value);
    int y = atoi(i.value);

    SwitchBase(base1);
    i.SwitchBase(base2);

    if (x <= y)
        return true;
    else
        return false;

}

bool Number::operator>(Number& i)                                     // > //
{
    int base1 = base;
    int base2 = i.base;

    SwitchBase(10);
    i.SwitchBase(10);

    int x = atoi(value);
    int y = atoi(i.value);

    SwitchBase(base1);
    i.SwitchBase(base2);

    if (x > y)
        return true;
    else
        return false;

}

bool Number::operator>=(Number& i)                                // >= //
{
    int base1 = base;
    int base2 = i.base;

    SwitchBase(10);
    i.SwitchBase(10);

    int x = atoi(value);
    int y = atoi(i.value);

    SwitchBase(base1);
    i.SwitchBase(base2);

    if (x >= y)
        return true;
    else
        return false;

}

bool Number::operator==(Number& i)                               // == //
{
    int base1 = base;
    int base2 = i.base;

    SwitchBase(10);
    i.SwitchBase(10);

    int x = atoi(value);
    int y = atoi(i.value);

    SwitchBase(base1);
    i.SwitchBase(base2);

    if (x == y)
        return true;
    else
        return false;

}

char Number::operator[](int n)
{
    if (n < GetDigitsCount())
        return this->value[n];
    else
        cout << "ERROR ELEMENT NOT IN ARRAY";
    char a = ' ';
    return a;
}

Number& Number::operator=(const char* val)
{
    delete[] this->value;
    this->value = new char[strlen(val) + 1];
    int based = this->base;
    this->base = 10;

    strcpy(this->value, val);

    SwitchBase(based);

    return (*this);
}

Number& Number::operator=(Number & i)
{
    delete[] this->value;
    this->value = new char[strlen(i.value) + 1];

    strcpy(this->value, i.value);
    this->base = i.base;

    return (*this);
}

Number& Number::operator=(int val)
{
    delete[] this->value;
    int based = this->base;
    this->base = 10;

    string temp_str = to_string(val);
    char const* number_array = temp_str.c_str();

    this->value = new char[strlen(number_array) + 1];

    strcpy(this->value, number_array);

    SwitchBase(based);

    return (*this);
}

void Number::operator--(int val)
{
   this->value[Number::GetDigitsCount() - 1] = '\0';
}

void Number::operator--()
{
    for (int i = 1; i <= Number::GetDigitsCount(); i++)
        this->value[i - 1] = this->value[i];
}