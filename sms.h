/***************************************************/
/*********** [Done by Sunrix] *********************/
/*************************************************/


/* Simple [student management system] purely in C. */
/* Used for adding, printing, deleting users etc. */
/* Will implement --> Add command, List command, Print command, Mean command, */
/* Goodstanding command, Search command, Delete command, Quit command. */
/* I may add file transfer later on. */
/* May add more in the future */  

/****************************************************************/

extern int count;

/****************************************************************/

#include "colour.h"

struct STUDENT    			/* written for a max of 100 students */
{
	char first_name[50];
	char last_name[50];

	int stu_id;

	float math_mark;
	float music_mark;
	float pe_mark;
};

// =====================================================================================

void help_info(void)
{
	system("clear");

	int i;

	printf("\t");

	for (i = 1; i <= 110; i++)
	{
		printf("%s=%s", blue, normal);

	}

	printf("\n");
	
	printf("\t=             %s[STUDENT - MANAGEMENT - SYSTEM]%s                       \t\t\t\t\t     =\n", yellow, normal);
	printf("\t=                                                                      \t\t\t\t\t     =\n");
	printf("\t=\t\t\tCommands:                                                      \t\t\t     =\n");
	printf("\t=\t\t\t\t  %s--A%s [firstname][lastname][stu_id][math][music][pe]          \t\t     =\n", green, normal);
	printf("\t=\t\t\t\t  %s--L%s                                                         \t\t     =\n", green, normal);
	printf("\t=\t\t\t\t  %s--P%s [stu_id]                                                \t\t     =\n", green, normal);
	printf("\t=\t\t\t\t  %s--M%s                                                         \t\t     =\n", green, normal);
	printf("\t=\t\t\t\t  %s--G%s                                                         \t\t     =\n", green, normal);
	printf("\t=\t\t\t\t  %s--S%s [QueryString]                                           \t\t     =\n", green, normal);
	printf("\t=\t\t\t\t  %s--D%s [QueryString]                                           \t\t     =\n", green, normal);
	printf("\t=\t\t\t\t  %s--Q%s                                                         \t\t     =\n", green, normal);
	printf("\t=\t\t\t\t  %s--start%s                                                     \t\t     =\n", green, normal);
	
	printf("\t");

	for (i = 1; i <= 110; i++)
	{
		printf("%s=%s", blue, normal);

	}

	printf("\n");

	printf("\t=\t\t\t\t  %s--A%s ---> [Adding users]                                     \t\t     =\n", cyan, normal);
	printf("\t=\t\t\t\t  %s--L%s ---> [List users]                                       \t\t     =\n", cyan, normal);
	printf("\t=\t\t\t\t  %s--P%s ---> [Print Student-Id]                                 \t\t     =\n", cyan, normal);
	printf("\t=\t\t\t\t  %s--M%s ---> [Print each subject mean of total]                 \t\t     =\n", cyan, normal);
	printf("\t=\t\t\t\t  %s--G%s ---> [Print Good-Standing(all marks higher than mean)]  \t\t     =\n", cyan, normal);
	printf("\t=\t\t\t\t  %s--S%s ---> [Search and print user with QueryString]           \t\t     =\n", cyan, normal);
	printf("\t=\t\t\t\t  %s--D%s ---> [Delete users with QueryString]                    \t\t     =\n",cyan, normal);
	printf("\t=\t\t\t\t  %s--Q%s ---> [Quit the program]                                 \t\t     =\n", cyan, normal);
	printf("\t=\t\t\t\t  %s--start%s ---> [Start the program]                            \t\t     =\n", cyan, normal);
	printf("\t=                                                                      \t\t\t\t\t     =\n");
	printf("\t=                                                                      \t\t\t\t\t     =\n");
	printf("\t=                                                                      \t\t\t\t\t     =\n");

	printf("\t");

	for (i = 1; i <= 110; i++)
	{
		printf("%s=%s", blue, normal);

	}

	printf("\n\n");
}

// =============================================================================

void quit(void)
{
	printf("\nProgram Terminated !\n\n");

	exit(0);
}

// ===================================================

void add_users(struct STUDENT st[], char *f_n, char *l_n, int sd, float ma, float mu, float p_e)
{
	memset(st[count].first_name, 0, strlen(st[count].first_name));	
	memset(st[count].last_name, 0, strlen(st[count].last_name));

	strncpy(st[count].first_name, f_n, strlen(f_n));		/* adding firstname */		
	strncpy(st[count].last_name, l_n, strlen(l_n));		/* adding lastname */

	st[count].stu_id = sd;								/* adding student id */

	st[count].math_mark = ma;							/* adding maths mark */
	st[count].music_mark = mu;							/* adding music mark */
	st[count].pe_mark = p_e;							/* adding pe mark */

	count++;

	if (count == 1000)
	{
		printf("[Max Limit of 100 -> students] has been reached !...\n");
		printf("[Program Terminated]...\n");

		exit(0);
	}

}

// =================================================================================

void list_users(struct STUDENT st[])
{
	int i;

	for (i = 0; i < count; i++)
	{
		printf("\n%s %s [%d]:\n", st[i].first_name, st[i].last_name, st[i].stu_id);
		printf("\t Math:  %.2f\n", st[i].math_mark);
		printf("\t Music: %.2f\n", st[i].music_mark);
		printf("\t Pe:    %.2f\n\n", st[i].pe_mark);
	}

	if (count == 0)
	{
		printf("\n------Empty List!-------\n\n");
	}

}


// =================================================================================

void quit_program(void)
{
	system("clear");

	printf("Program terminated!...\n\n");
	exit(0);
}	


// ==================================================================================

void print_sid(struct STUDENT stu[], int sid)
{
	int i, j;

	j = 0;

	for (i = 0; i < count; i++)
	{
		if (stu[i].stu_id == sid)
		{
			printf("\n%s %s [%d]:\n", stu[i].first_name, stu[i].last_name, stu[i].stu_id);
			printf("\t Math:  %.2f\n", stu[i].math_mark);
			printf("\t Music: %.2f\n", stu[i].music_mark);
			printf("\t Pe:    %.2f\n\n", stu[i].pe_mark);

			j++;
		}

	}

	if (j == 0)
	{
		printf("\nNo such student exists...\n\n");
	}

}

// ==================================================================================

void print_total_mean(struct STUDENT stu[])
{
	float math_mean, music_mean, pe_mean;
	float total_math, total_music, total_pe;
	int i;

	total_math = total_music = total_pe = 0.0;

	/* Finding the mean */

	for (i = 0; i < count; i++)
	{
		total_math = total_math + stu[i].math_mark;
		total_music = total_music + stu[i].music_mark;
		total_pe = total_pe + stu[i].pe_mark;
	}

	math_mean = total_math / count;
	music_mean = total_music / count;
	pe_mean = total_pe / count;

	printf("\n\t Math:  %.2f\n", math_mean);
	printf("\t MUSIC: %.2f\n", music_mean);
	printf("\t PE:    %.2f\n\n", pe_mean);

}

// =================================================================================

void search_and_print(struct STUDENT stu[], char *string)
{	
	int i;
	int j = 0;

	for (i = 0; i < count; i++)
	{
		if ((strstr(stu[i].first_name, string) != NULL) || (strstr(stu[i].last_name, string) != NULL))
		{
			printf("\n%s %s [%d]:\n", stu[i].first_name, stu[i].last_name, stu[i].stu_id);
			printf("\t Math:  %.2f\n", stu[i].math_mark);
			printf("\t Music: %.2f\n", stu[i].music_mark);
			printf("\t Pe:    %.2f\n\n", stu[i].pe_mark);

			j++;
		}
	}

	if (j == 0)
	{
		printf("\nSearch Failed...\n\n");
	}

}

// =================================================================================

void good_standing(struct STUDENT stu[])
{	
	int i;
	int j = 0;

	float t_math, t_music, t_pe;
	float math_mean, music_mean, pe_mean;

	t_math = t_music = t_pe = 0.0;

	/* only good standing if each of the marks is higher than average marks of total */

	for (i = 0; i < count; i++)
	{
		t_math = t_math + stu[i].math_mark;
		t_music = t_music + stu[i].music_mark;
		t_pe = t_pe + stu[i].pe_mark;
	}

	/* find the immediate average first */

	math_mean = t_math / count;
	music_mean = t_music / count;
	pe_mean = t_pe / count;

	/* to be good-standing, a student needs to get higher marks than the mean marks for each subject */

	for (i = 0; i < count; i++)
	{
		if ((stu[i].math_mark > math_mean) && (stu[i].music_mark > music_mean) && (stu[i].pe_mark > pe_mean))
		{
			printf("\n%s %s [%d]:\n", stu[i].first_name, stu[i].last_name, stu[i].stu_id);
			printf("\t Math:  %.2f\n", stu[i].math_mark);
			printf("\t Music: %.2f\n", stu[i].music_mark);
			printf("\t Pe:    %.2f\n\n", stu[i].pe_mark);

			j++;
		}

	}

	if (j == 0)
	{
		printf("\nNo Good-Standing student...\n\n");
	}

}

// ==================================================================================

void delete_user(struct STUDENT stu[], char *d)
{
	int i, j, k;

	k = 0;

	for (i = 0; i < count; i++)
	{
		if ((strstr(stu[i].first_name, d) != NULL) || (strstr(stu[i].last_name, d) != NULL))
		{
			/* if we manage to find the student we must now delete it */

			for (j = i; j < count; j++)
			{
				if (j == count - 1)
				{
					count--;
						
					delete_user(stu, d);
				}

				strncpy(stu[j].first_name, stu[j + 1].first_name, strlen(stu[j + 1].first_name));
				strncpy(stu[j].last_name, stu[j + 1].last_name, strlen(stu[j + 1].last_name));

				stu[j].math_mark = stu[j + 1].math_mark;
				stu[j].music_mark = stu[j + 1].music_mark;
				stu[j].pe_mark = stu[j + 1].pe_mark;
			}

		}

	}

}

// ==================================================================================


// ==================================================================================


// ==================================================================================

void stu_man_sys(struct STUDENT stu[])		/* this is where all the main stff happens */
{
	system("clear");

	char command[4], fn[30], ln[30], search[30], del[30];
	int s_id, i, ans;
	float maths, music, pe;

	while (1)
	{
		printf("[%d Students] Command: ", count);
		scanf("%s", command);

		if (strlen(command) > 4)
		{
			system("clear");

			printf("\nCommands are only 4 characters long!...\n\n");

			exit(0);
		}

		if (strncmp(command, "--A", 4) == 0)
		{	
			printf("Input: ");
			scanf("%s %s %d %f %f %f", fn, ln, &s_id, &maths, &music, &pe);

			/* doing necessary checks */

			if (strlen(fn) > 30 || strlen(ln) > 30)		/* check if strings are more than string length */
			{
				break;
			}	

			printf("\n");

			add_users(stu, fn, ln, s_id, maths, music, pe); 	/* Too add users... [--A] */
		}

		else if (strncmp(command, "--L", 4) == 0)
		{
			list_users(stu);									/* Too list users... [--L] */
		}

		else if (strncmp(command, "--Q", 4) == 0)
		{
			quit_program();										/* to quit program [--Q] */
		}

		else if (strncmp(command, "--P", 4) == 0)
		{
			printf("Input: ");
			scanf("%d", &s_id);

			print_sid(stu, s_id);								/* to print student based on ID [--P] */
		}

		else if (strncmp(command, "--M", 4) == 0)
		{
			print_total_mean(stu);								/* print total mean [--M] */
		}

		else if (strncmp(command, "--S", 4) == 0)
		{
			printf("Input: ");
			scanf("%s", search);

			search_and_print(stu, search);				/* print out search query [--S] */
		}

		else if (strncmp(command, "--G", 4) == 0)
		{
			good_standing(stu);								/* print the good standing student [--G] */
		}

		else if (strncmp(command, "--D", 4) == 0)
		{
			printf("Input: ");
			scanf("%s", del);

			delete_user(stu, del);							/* to delete a student [--D] */
		}

	}

	system("clear");			/* if there was a break if fn > 30 || ln > 30 */

	printf("\nError!...\n");

	exit(0);

}
