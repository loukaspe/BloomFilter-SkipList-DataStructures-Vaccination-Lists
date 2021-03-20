#ifndef ERGASIA1_VACCINATION_H
#define ERGASIA1_VACCINATION_H

#include "../Person/Person.h"

class Vaccination {
private:
    Person* person;
    char* date;
public:
    Vaccination(Person *person, char *date);

    Person *getPerson() const;

    char *getDate() const;

    void printInfo();
};


#endif //ERGASIA1_VACCINATION_H
