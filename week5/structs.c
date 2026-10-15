#include <stdio.h>

typedef struct {
  char* name;
  unsigned int age;
  char grade;
} Student;

void printStudent(Student);
void printStdudentWithPointer(Student*);


int main(int argc, char *argv[])
{
  int EXIT_SUCCESS = 0;

    Student s1 = {
    s1.name = "Kem",
    s1.age = 23,
    s1.grade = 'A'
  };

  Student s2 = {
    s2.name = "Shania",
    s2.age = 21,
    s2.grade = 'A'
  };

  Student* student_p = &s2;

  printStudent(s1);
  printStdudentWithPointer(student_p);

  return EXIT_SUCCESS;
}


void printStudent(Student st) {
  printf("Name: %s\n", st.name);
  printf("Age: %d\n", st.age);
  printf("Grade: %c\n", st.grade);
}

void printStdudentWithPointer(Student* stp){
  printf("Name: %s\n", stp->name);
  printf("Age: %d\n", stp->age);
  printf("Grade: %c\n", stp->grade);
}
