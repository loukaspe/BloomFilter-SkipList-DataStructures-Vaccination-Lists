#include "Person.h"

Person::Person(
        char *citizenId,
        char *firstName,
        char *lastName,
        char *country,
        int age
) : citizenId(citizenId),
    firstName(firstName),
    lastName(lastName),
    country(country), age(age) {}

Person::~Person() {

}

char *Person::getCitizenId() const {
    return citizenId;
}

char *Person::getFirstName() const {
    return firstName;
}

char *Person::getLastName() const {
    return lastName;
}

char *Person::getCountry() const {
    return country;
}

int Person::getAge() const {
    return age;
}
