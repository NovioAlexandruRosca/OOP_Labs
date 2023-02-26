#include <stdlib.h>
#include <stdio.h>
#include "Student.h"
#include "Global.h"

int main()
{
	Student elev,elev1;

	char nume[] = "Andrei";
	char nume1[] = "Alex";

	elev.Set_Name(nume);
	elev.Set_Math_Grade(9.5);
	elev.Set_English_Grade(9.6);
	elev.Set_History_Grade(9.2);

	elev1.Set_Name(nume1);
	elev1.Set_Math_Grade(9.6);
	elev1.Set_English_Grade(9.5);
	elev1.Set_History_Grade(9.3);

	//  /\  Setting up the data   //

	printf(" Notele lui %s sunt urmatoarele ", elev.Get_Name());
	printf("\n Matematica : % f \n Engleza : % f \n Istorie : %f", elev.Get_Math_Grade(), elev.Get_English_Grade(), elev.Get_History_Grade());
	printf("\n Media lui este : % f \n\n", (elev.Get_Math_Grade() + elev.Get_English_Grade() + elev.Get_History_Grade()) / 3);

	printf(" Notele lui %s sunt urmatoarele ", elev1.Get_Name());
	printf("\n Matematica : % f \n Engleza : % f \n Istorie : %f", elev1.Get_Math_Grade(), elev1.Get_English_Grade(), elev1.Get_History_Grade());
	printf("\n Media lui este : % f \n\n", (elev1.Get_Math_Grade() + elev1.Get_English_Grade() + elev1.Get_History_Grade()) / 3);

	//  /\  Presenting the data   //

	printf("Comparare nume : %d\n", comp_nume(elev.Get_Name(), elev1.Get_Name()));
	printf("Comparare engleza : %d\n", comp_engleza(elev.Get_English_Grade(), elev1.Get_English_Grade()));
	printf("Comparare istorie : %d\n", comp_istorie(elev.Get_History_Grade(), elev1.Get_History_Grade()));
	printf("Comparare mate : %d\n", comp_mate(elev.Get_Math_Grade(), elev1.Get_Math_Grade()));
	printf("Comparare medie : %d\n", comp_avg((elev.Get_Math_Grade() + elev.Get_English_Grade() + elev.Get_History_Grade()) / 3, (elev1.Get_Math_Grade() + elev1.Get_English_Grade() + elev1.Get_History_Grade()) / 3));

	//  /\  Global Functions in-use  //

}