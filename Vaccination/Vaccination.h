#ifndef ERGASIA1_VACCINATION_H
#define ERGASIA1_VACCINATION_H

/* Forward Declaration of class Person */
class Person;

class Vaccination {
private:
    Person* person;
    char* date;
public:
    Vaccination(Person *person, char *date);

    Person *getPerson() const;

    char *getDate() const;
};


#endif //ERGASIA1_VACCINATION_H
