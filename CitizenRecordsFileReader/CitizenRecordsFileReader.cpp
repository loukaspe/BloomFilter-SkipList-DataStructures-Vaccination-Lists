#include "CitizenRecordsFileReader.h"

const char *CitizenRecordsFileReader::NO_INPUT_FILE_ERROR = "ERROR: No Input File was found.\n";
const char *CitizenRecordsFileReader::OPEN_FILE_ERROR = "ERROR: Could not open file ";
const char *CitizenRecordsFileReader::OPEN_FILE_READ_MODE = "r";
const char *CitizenRecordsFileReader::SPACE_DELIMITER = " ";
const char *CitizenRecordsFileReader::ERROR_IN_READING_FILE = "ERROR: Cannot read file\n";

CitizenRecordsFileReader::CitizenRecordsFileReader(
        char *fileName,
        PersonLinkedList *people,
        VirusLinkedList *viruses
) : fileName(fileName), people(people), viruses(viruses) {}

// 889 John Papadopoulos Greece 52 COVID-19 YES 27-12-2020
// 889 John Papadopoulos Greece 52 Η1Ν1 ΝΟ

void CitizenRecordsFileReader::readAndUpdateStructures() {
    if (fileName == NULL) {
        Helper::handleError(NO_INPUT_FILE_ERROR);
    }

    FILE *inputFile;
    char *line = NULL;
    size_t length = 0;
    char *temp;
    char *citizenId;
    char *firstName;
    char *lastName;
    char *country;
    int age;
    char *virusName;
    bool isVaccinated;
    Date *date;
    Virus *tempVirus;

    inputFile = fopen(fileName, OPEN_FILE_READ_MODE);
    if(inputFile == NULL) {
        Helper::handleError(OPEN_FILE_ERROR);
    }

    // I consider that the inputFile is correctly formatted as per the way the
    // data is given
    while (getline(&line, &length, inputFile) != -1) {
        temp = strtok(line, SPACE_DELIMITER);
        citizenId = Helper::copyString(temp);

        temp = strtok(NULL, SPACE_DELIMITER);
        firstName = Helper::copyString(temp);

        temp = strtok(NULL, SPACE_DELIMITER);
        lastName = Helper::copyString(temp);

        temp = strtok(NULL, SPACE_DELIMITER);
        country = Helper::copyString(temp);

        temp = strtok(NULL, SPACE_DELIMITER);
        age = atoi(temp);

        temp = strtok(NULL, SPACE_DELIMITER);
        virusName = Helper::copyString(temp);

        temp = strtok(NULL, SPACE_DELIMITER);
        temp = Helper::removeNewLineCharacterFromString(temp);
        isVaccinated = setBooleanIsVaccinatedFromStringValue(temp);

        // ADD NEW PERSON

        if (this->people->findByCitizenId(citizenId) == NULL) {
            Person *newPerson = new Person(
                    citizenId,
                    firstName,
                    lastName,
                    country,
                    age
            );

            this->people->addAtStart(newPerson);
        }

        // ADD NEW VIRUS: new, check, add

        if (this->viruses->findByName(virusName) == NULL) {
            BloomFilter *newBloomFilter = new BloomFilter();
            VaccinatedSkipList *newVaccinatedSkipList = new VaccinatedSkipList();
            NotVaccinatedSkipList *newNotVaccinatedSkipList = new NotVaccinatedSkipList();

            Virus *newVirus = new Virus(
                    virusName,
                    newVaccinatedSkipList,
                    newNotVaccinatedSkipList,
                    newBloomFilter
            );

            this->viruses->addAtStart(newVirus);
        }

        if (isVaccinated) {
            temp = strtok(NULL, SPACE_DELIMITER);
            temp = Helper::removeNewLineCharacterFromString(temp);
            date = new Date(temp);

            Vaccination *newVaccination = new Vaccination(
                    this->people->findByCitizenId(citizenId)->person,
                    date
            );

            tempVirus = this->viruses->findByName(virusName)->getVirus();
            tempVirus->getVaccinatedPeopleList()->insert(
                    atoi(citizenId),
                    newVaccination
            );
            tempVirus->getVaccinatedPeopleBloomFilter()->add(citizenId);
        } else {
            tempVirus = this->viruses->findByName(virusName)->getVirus();
            tempVirus->getNotVaccinatedPeopleList()->insert(
                atoi(citizenId),
                this->people->findByCitizenId(citizenId)->person
            );
        }
    }

// TESTS GIA INSERT/SEARCH
//    Virus* rabies = this->viruses->findByName("Rabies")->getVirus();
//    Virus* cholera = this->viruses->findByName("Cholera")->getVirus();
//    Virus* hepatitisA = this->viruses->findByName("HepatitisA")->getVirus();
//    Virus* ebola = this->viruses->findByName("Ebola")->getVirus();
//
//    Vaccination* tempv;
//    Person* tempp;
//    bool a = ebola->getVaccinatedPeopleBloomFilter()->check("98");                  // YES
//    tempv = ebola->getVaccinatedPeopleList()->search(atoi("98"));       // YES
//    a = ebola->getVaccinatedPeopleBloomFilter()->check("527");                      // NO
//    tempp = ebola->getNotVaccinatedPeopleList()->search(atoi("527")); // Briskei
//    a = ebola->getVaccinatedPeopleBloomFilter()->check("6515");                         // NO
//    tempp = ebola->getNotVaccinatedPeopleList()->search(atoi("6515")); // Briskei
//    a = ebola->getVaccinatedPeopleList()->search(atoi("1706"));         // Den kseroyme - logika no
//    tempp = ebola->getNotVaccinatedPeopleList()->search(atoi("1706"));  // NULL
//
//    a = rabies->getVaccinatedPeopleBloomFilter()->check("5473");                    // YES
//    tempv = rabies->getVaccinatedPeopleList()->search(atoi("5473")); // YES
//    a = rabies->getVaccinatedPeopleBloomFilter()->check("3764");                    // NO
//    tempp = rabies->getNotVaccinatedPeopleList()->search(atoi("3764")); // Briskei
//    a = rabies->getVaccinatedPeopleBloomFilter()->check("7320");                        // NO
//    tempp = rabies->getNotVaccinatedPeopleList()->search(atoi("7320")); // Briskei
//    a = rabies->getVaccinatedPeopleList()->search(atoi("1706"));        // Den kseroyme - logika no
//    tempp = rabies->getNotVaccinatedPeopleList()->search(atoi("1706")); // NULL
//
//    a = cholera->getVaccinatedPeopleBloomFilter()->check("7804");                       // YES
//    tempv = cholera->getVaccinatedPeopleList()->search(atoi("7804"));   // YES
//    a = cholera->getVaccinatedPeopleBloomFilter()->check("6325");                       // NO
//    tempp = cholera->getNotVaccinatedPeopleList()->search(atoi("6325")); // Briskei
//    a = cholera->getVaccinatedPeopleBloomFilter()->check("4602");                       // NO
//    tempp = cholera->getNotVaccinatedPeopleList()->search(atoi("4602")); // Briskei
//    a = cholera->getVaccinatedPeopleList()->search(atoi("1706"));           // Den kseroyme - logika no
//    tempp = cholera->getNotVaccinatedPeopleList()->search(atoi("1706")); // NULL
//
//    a = hepatitisA->getVaccinatedPeopleBloomFilter()->check("8372");                    // YES
//    tempv = hepatitisA->getVaccinatedPeopleList()->search(atoi("8372")); // YES
//    a = hepatitisA->getVaccinatedPeopleBloomFilter()->check("6254");                    // NO
//    tempp = hepatitisA->getNotVaccinatedPeopleList()->search(atoi("6254")); // Briskei
//    a = hepatitisA->getVaccinatedPeopleBloomFilter()->check("4333");                        // NO
//    tempp = hepatitisA->getNotVaccinatedPeopleList()->search(atoi("4333")); // Briskei
//    a = hepatitisA->getVaccinatedPeopleList()->search(atoi("1706")); // Den kseroyme - logika no
//    tempp = hepatitisA->getNotVaccinatedPeopleList()->search(atoi("1706")); // NULL

    if( ferror(inputFile) ) {
        Helper::handleError(ERROR_IN_READING_FILE);
    }

    free(line);
    fflush(inputFile);
    fclose(inputFile);
}

bool CitizenRecordsFileReader::setBooleanIsVaccinatedFromStringValue(char *isVaccinatedAsString) {
    if (strcmp(isVaccinatedAsString, "YES") == 0) {
        return true;
    }

    if (strcmp(isVaccinatedAsString, "NO") == 0) {
        return false;
    }

    // TODO: throw exception
    return false;
}
