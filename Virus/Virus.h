/* Class that represents a Virus. It has a virusName, a SkipList of Vaccinated
 * people, a SkipList of NOT Vaccinated people and a BloomFilter for NOT Vaccinated
 * people*/

#ifndef ERGASIA1_VIRUS_H
#define ERGASIA1_VIRUS_H

#include "../NotVaccinatedSkipList/NotVaccinatedSkipList.h"
#include "../VaccinatedSkipList/VaccinatedSkipList.h"
#include "../BloomFilter/BloomFilter.h"


class Virus {
public:
    char *getVirusName() const;

    VaccinatedSkipList *getVaccinatedPeopleList() const;

    NotVaccinatedSkipList *getNotVaccinatedPeopleList() const;

    BloomFilter *getNotVaccinatedPeopleBloomFilter() const;

    Virus(char *virusName, VaccinatedSkipList *vaccinatedPeopleList, NotVaccinatedSkipList *notVaccinatedPeopleList,
          BloomFilter *notVaccinatedPeopleBloomFilter);

private:
    char *virusName;
    VaccinatedSkipList *vaccinatedPeopleList;
    NotVaccinatedSkipList *notVaccinatedPeopleList;
    BloomFilter *notVaccinatedPeopleBloomFilter;
};


#endif //ERGASIA1_VIRUS_H
