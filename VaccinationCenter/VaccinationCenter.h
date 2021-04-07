/*
 * Class for operating on people and viruses and performing the functions of the
 * Exercise. It will be injected on the MenuPromptCreator
 * */

#ifndef ERGASIA1_VACCINATIONCENTER_H
#define ERGASIA1_VACCINATIONCENTER_H


#include "../Date/Date.h"
#include "../PersonLinkedList/PersonLinkedList.h"
#include "../VirusLinkedList/VirusLinkedList.h"

class VaccinationCenter {
public:
    VaccinationCenter(PersonLinkedList *people, VirusLinkedList *viruses);

    void vaccineStatusBloom(char *citizenId, char *virusName);

    void vaccineStatusForAllViruses(char *citizenId);

    void vaccineStatusForSpecificVirus(char *citizenId, char *virusName);

    void populationStatusForAllCountries(char *virusName, Date *date1, Date *date2);

    void populationStatusForCountry(
            char *country,
            char *virusName,
            Date *date1,
            Date *date2
    );

    void popStatusByAgeForAllCountries(char *virusName, Date *date1, Date *date2);

    void popStatusByAgeForCountry(char *country, char *virusName, Date *date1, Date *date2);

    void insertVaccinated(
            char *citizenId,
            char *firstName,
            char *lastName,
            char *country,
            int age,
            Date *date1
    );

    void insertNotVaccinated(
            char *citizenId,
            char *firstName,
            char *lastName,
            char *country,
            int age
    );

    void vaccinateNow(
            char *citizenId,
            char *firstName,
            char *lastName,
            char *country,
            int age,
            char *virusName
    );

    void listNotVaccinatedPersonsForVirus(char *virusName);

private:
    PersonLinkedList *people;
    VirusLinkedList *viruses;
};


#endif //ERGASIA1_VACCINATIONCENTER_H
