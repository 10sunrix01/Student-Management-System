#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "sms.h"

int count = 0;

int main(int argc, char *argv[])
{
	struct STUDENT stud[1000]; 		/* a max of 1000 students */

	switch(argc)
	{
		case 1:

			system("clear");

			printf("\nPlease use the [-h] or [-help] option.\n\n");

			break;


		case 2:

			if ((strncmp(argv[1], "-h", 3) == 0) || (strncmp(argv[1], "-help", 6) == 0))
			{
				help_info();	/* how to use the commands later on */
			}

			else if (strncmp(argv[1], "--start", 8) == 0)
			{

				stu_man_sys(stud);		/* this is where the main function happens */
			}

			else
			{
				system("clear");
				
				printf("\nPlease use the [-h] or [-help] option.\n\n");
			}

			break;

		default:

			system("clear");

			printf("\nOption does not exist...\n\n");

			break;

	}	


	return 0;
}
