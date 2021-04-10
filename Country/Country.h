#ifndef ERGASIA1_COUNTRY_H
#define ERGASIA1_COUNTRY_H

#include "../VaccinatedSkipList/VaccinatedSkipList.h"
#include "../VirusLinkedList/VirusLinkedList.h"

class Country {
public:
    Country(char *, VirusLinkedList *);

    void addCitizen(int);

    VirusLinkedList *getViruses() const;

    char *getName() const;

    int getNumberOfCitizens() const;

    void printCountryStatisticsForDates(char *, Date *, Date *);

    void printCountryStatisticsPerAgeForDates(char *, Date *, Date *);

private:
    char *name;
    int numberOfCitizens;
    int numberOfVaccinatedCitizensUnder20yearsOld;
    int numberOfVaccinatedCitizensFrom20To40yearsOld;
    int numberOfVaccinatedCitizensFrom40To60yearsOld;
    int numberOfVaccinatedCitizensOver60yearsOld;
    VirusLinkedList *viruses;
};


#endif //ERGASIA1_COUNTRY_H


