#include "VaccinationCenter.h"

VaccinationCenter::VaccinationCenter(PersonLinkedList *people, VirusLinkedList *viruses)
        : people(people), viruses(viruses) {}

void VaccinationCenter::vaccineStatusBloom(char *citizenId, char *virusName)
{}

void VaccinationCenter::vaccineStatusForAllViruses(char *citizenId)
{}

void VaccinationCenter::vaccineStatusForSpecificVirus(char *citizenId, char *virusName)
{}

void VaccinationCenter::populationStatusForAllCountries(
        char *virusName,
        Date *date1,
        Date *date2
)
{}

void VaccinationCenter::populationStatusForCountry(
        char *country,
        char *virusName,
        Date *date1,
        Date *date2
) {}

void VaccinationCenter::VaccinationCenter::popStatusByAgeForAllCountries(
        char *virusName,
        Date *date1,
        Date *date2
) {}

void VaccinationCenter::popStatusByAgeForCountry(
        char *country,
        char *virusName,
        Date *date1,
        Date *date2
) {}

void VaccinationCenter::insertVaccinated(
        char *citizenId,
        char *firstName,
        char *lastName,
        char *country,
        int age,
        Date *date1
) {}

void VaccinationCenter::insertNotVaccinated(
        char *citizenId,
        char *firstName,
        char *lastName,
        char *country,
        int age
) {}

void VaccinationCenter::vaccinateNow(
        char *citizenId,
        char *firstName,
        char *lastName,
        char *country,
        int age,
        char *virusName
) {}

void VaccinationCenter::listNotVaccinatedPersonsForVirus(char *virusName)
{}
