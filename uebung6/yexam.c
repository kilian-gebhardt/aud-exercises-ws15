#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 32

struct exam_result {
	char exam_name[MAXLEN];
	int exam_grade;
};

struct student {
	char name[MAXLEN];
	struct exam_result * exams[MAXLEN];
};

struct student * new_student(char name[]){
	int i;
	struct student * s; 

	s = malloc(sizeof(*s));

	strncpy( (*s).name, name, MAXLEN);

	for(i = 0; i < MAXLEN; i = i + 1)
		(*s).exams[i] = NULL;

	return s;
}

void add_exam(struct student * s, char name[]
	, int grade){
	int i;
	struct exam_result * r;
	r = malloc(sizeof(*r));
	r->exam_grade = grade;
	strncpy(r->exam_name, name, MAXLEN);

	for(i = 0; i < MAXLEN && s->exams[i] != NULL
		; i = i + 1);

	if (i == MAXLEN){
		free(r);
		return;
	}

	s->exams[i] = r;
	return;
}


void print_student(struct student * s){
	int i;
	printf("-- Student: %s --\n", s->name);
	for (i = 0; s->exams[i] != NULL && i < MAXLEN; i++){
		printf("Prüfung \"%s\": Note %d\n"
			, s->exams[i]->exam_name
			, s->exams[i]->exam_grade
			);
	}
	
	printf("----------\n\n");
}


int main()
{
/*
	struct exam_result e1;
	e1.exam_grade = 1;
	strncpy(e1.exam_name, "AuD", MAXLEN);

	printf("Prüfung \"%s\": Note %d\n"
			, e1.exam_name
			, e1.exam_grade
			);

	printf("size struct student:    %u Bytes\n\
size struct exam_result: %u Bytes\n\n"
		, sizeof(struct student)
		, sizeof(struct exam_result)
	);
*/

	struct student * db[2];
	int i;

	db[0] = new_student("Max Mustermann");
	
	add_exam(db[0], "GTI", 4);
	add_exam(db[0], "SyA", 3);

	db[1] = new_student("Sepp Wurz");
	add_exam(db[1], "GTI", 1);
	add_exam(db[1], "SyA", 1);
	add_exam(db[1], "ThI", 2);

	for(i = 0; i < 2; ++i)
		print_student(db[i]);

	return 0;
}