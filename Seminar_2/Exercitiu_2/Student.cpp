#include "Student.h"
#include <cstring>

void Student::Set_Name(char x[30]) {

	strcpy(this->student_name,x);

}

char* Student::Get_Name() {

	return this->student_name;
}

void Student::Set_Math_Grade(float x) {

	this->math = x;

}

float Student::Get_Math_Grade() {

	return this->math;
	
}

void Student::Set_English_Grade(float x) {

	this->english = x;

}

float Student::Get_English_Grade() {

	return this->english;

}

void Student::Set_History_Grade(float x) {

	this->history = x;

}

float Student::Get_History_Grade() {

	return this->history;

}

float Student::Avg_Grade() {

	return (this->english + this->math + this->history) / 3;

}
