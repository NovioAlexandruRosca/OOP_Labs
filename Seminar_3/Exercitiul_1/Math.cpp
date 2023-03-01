#include "Math.h"
#include <cstdarg>
#include <string.h>


int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y,int z)
{
	return x + y + z;
}

int Math::Add(double x,double y)
{
	return x + y;
}

int Math::Add(double x,double y,double z)
{
	return x + y + z;
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

int Math::Mul(double x, double y)
{
	return x * y;
}

int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}

int Math::Add(int count, ...)
{

    int suma = 0;

	va_list ap;
		
	int i;

	va_start(ap, count);

	suma += count;

		for (i = 0; i < count; i++)
		{
			suma += va_arg(ap, int);
		}

		va_end(ap);

		return suma;
	
}

char* Math::Add(const char* num1, const char* num2) {
    
    if (num1 == nullptr && num2 == nullptr)return nullptr;

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int max_len;
    if (len1 > len2)
        max_len = len1;
    else
        max_len = len2;

    char* sum = new char[max_len + 2];  

    int carry = 0; 
    int digit_sum = 0;  
    int i = 0;
    int j = 0;
    int digit1;
    int digit2;

    for (int k = 0; k <= max_len; k++) { 
      
        if (i < len1)
            digit1 = num1[len1 - 1 - i] - '0';
        else digit1 = 0;
      
        if (j < len2)
            digit2 = num2[len2 - 1 - j] - '0';
        else
            digit2 = 0;

        digit_sum = digit1 + digit2 + carry; 
        carry = digit_sum / 10;  
        sum[k] = (digit_sum % 10) + '0';  
        i++;
        j++; 
    }

    if (sum[max_len] == '0') {  
        max_len--;
    }

    for (int k = 0; k <= max_len / 2; k++) {  
        char temp = sum[k];
        sum[k] = sum[max_len - k];
        sum[max_len - k] = temp;
    }

    sum[max_len + 1] = '\0';  

    return sum;  
}
