class Student
{	
	char student_name[30];
	float math, english, history;

	public:
		void Set_Name(char *x);
		char* Get_Name();
		void Set_Math_Grade(float x);
		float Get_Math_Grade();
		void Set_English_Grade(float x);
		float Get_English_Grade();
		void Set_History_Grade(float x);
		float Get_History_Grade();
		float Avg_Grade();
};