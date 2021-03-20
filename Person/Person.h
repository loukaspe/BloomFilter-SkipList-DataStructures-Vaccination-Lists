#ifndef ERGASIA1_PERSON_H
#define ERGASIA1_PERSON_H

#include <cstring>
#include "../Vaccination/Vaccination.h"

class Person {
private:
    char *citizenId;
    char *firstName;
    char *lastName;
    char *country;
    int age;
public:
    virtual ~Person();

    Person(char *citizenId, char *firstName, char *lastName, char *country, int age);

    char *getCitizenId() const;

    char *getFirstName() const;

    char *getLastName() const;

    char *getCountry() const;

    int getAge() const;
};

#endif //ERGASIA1_PERSON_H
