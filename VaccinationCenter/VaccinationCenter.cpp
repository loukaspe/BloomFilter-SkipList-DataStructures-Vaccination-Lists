#include "VaccinationCenter.h"

VaccinationCenter::VaccinationCenter(PersonLinkedList *people, VirusLinkedList *viruses)
        : people(people), viruses(viruses) {}

void VaccinationCenter::vaccineStatusBloom(char *citizenId, char *virusName)
{
    VirusLinkedListNode* node = this->viruses->findByName(virusName);

    if(node == NULL) {
        cout << "No Virus with name " << virusName << endl;
        return;
    }

    Virus* virus = node->getVirus();

    if(virus == NULL) {
        cout << "No Virus with name " << virusName << endl;
        return;
    }

    bool isVaccinated = virus->getVaccinatedPeopleBloomFilter()->check(citizenId);

    if(isVaccinated) {
        cout << "MAYBE" << endl;
        return;
    }

    cout << "NOT VACCINATED" << endl;
}

void VaccinationCenter::vaccineStatusForAllViruses(char *citizenId)
{
    this->viruses->checkIfVaccinatedForAllViruses(citizenId);
}

void VaccinationCenter::vaccineStatusForSpecificVirus(char *citizenId, char *virusName)
{
    VirusLinkedListNode* tempNode = this->viruses->findByName(virusName);
    if (tempNode == NULL) {
        cout << "There is no Virus with name " << "'virusName'." << endl;
        return;
    }

    Virus* tempVirus = tempNode->getVirus();
    if (tempVirus == NULL) {
        cout << "There is no Virus with name " << virusName << endl;
        return;
    }

    bool shouldPrintVirusName = false;
    tempVirus->printIfPersonIsVaccinated(citizenId, shouldPrintVirusName);
}

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
