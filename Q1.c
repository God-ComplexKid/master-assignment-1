/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
  int id;
  int score;
};

struct student* allocate() {
  /* Allocate memory for ten students */
     struct student *los = (struct student *) malloc(10);
  /* return the pointer */
  return los;
}


void generate(struct student* students) {
	int i;
  /*
   * Generate random ID and scores for 10 students, ID being between
   * 0 and 9, scores equal to (id * 10) % 50.
   */
   for(i = 0; i < 10; i++)
   {
	   students[i].id = i;
   }
   for(i = 0; i < 10; i++)
   {
	   students[i].score = (students[i].id * 10) % 50;
   }
}

void output(struct student* students) {
	int i;
  /*
   * Output information about the ten students in the format:
   *
   *   ID0 Score0
   *   ID1 score1
   *   ID2 score2
   *   ...
   *   ID9 score9
   */
   for(i = 0; i < 10; i++)
   {
	   printf("ID: %d, Score: %d \n", students[i].id, students[i].score);
   }
}

int min(struct student* students) {
  /* return the minimum score */
  int i = 0; int min = 999999;
  for(i = 0; i < 10; i++)
  {
	  if(min > students[i].score)
	  {
		  min = students[i].score;
	  }
  }
  return min;
}

float avg(struct student* students) {
  /* return the average score */  
  int i; float avg;
  avg = 0;
  for(i = 0; i < 10; i++)
  {
	  avg += students[i].score;
  }
  avg = avg/10;
  return avg;
}

void sort(struct student* students){ 
  /* sorts highest at top
 */
	int i,k, sub; 
	for(i = 0; i<10; i++)
	{
		for(k = i; k < 10; k++)
		{
			if(students[k].score >= students[i].score)
			{
				sub = students[i].score;
				students[i].score = students[k].score;
				students[k].score = sub;
				sub = students[i].id;
				students[i].id = students[k].id;
				students[k].id = sub;				
			}
		}
	}
	
	//free(hold);
}

void deallocate(struct student* stud) {
  /* Deallocate memory from stud */
  if(stud != NULL)
  {
	  free(stud);
  }
}

int main(){
  struct student* stud = allocate();
  generate(stud);
  output(stud);
  sort(stud);
  for (int i=0; i<10; i++) {
    printf("%d %d\n", stud[i].id, stud[i].score);
  }
  printf("Avg: %f \n", avg(stud));
  printf("Min: %d \n", min(stud));
  return 0;
}
