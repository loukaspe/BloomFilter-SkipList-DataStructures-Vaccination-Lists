#include "Virus.h"

Virus::Virus(
    char *virusName,
    VaccinatedSkipList *vaccinatedPeopleList,
    NotVaccinatedSkipList *notVaccinatedPeopleList,
    BloomFilter *notVaccinatedPeopleBloomFilter
) : virusName(virusName),
    vaccinatedPeopleList(vaccinatedPeopleList),
    notVaccinatedPeopleList(notVaccinatedPeopleList),
    vaccinatedPeopleBloomFilter(notVaccinatedPeopleBloomFilter) {}

char *Virus::getVirusName() const {
    return virusName;
}

VaccinatedSkipList *Virus::getVaccinatedPeopleList() const {
    return vaccinatedPeopleList;
}

NotVaccinatedSkipList *Virus::getNotVaccinatedPeopleList() const {
    return notVaccinatedPeopleList;
}

BloomFilter *Virus::getVaccinatedPeopleBloomFilter() const {
    return vaccinatedPeopleBloomFilter;
}
