#ifndef ERGASIA1_CITIZENRECORDSFILEREADER_H
#define ERGASIA1_CITIZENRECORDSFILEREADER_H


#include "../PersonLinkedList/PersonLinkedList.h"
#include "../VirusLinkedList/VirusLinkedList.h"

class CitizenRecordsFileReader {
public:
    CitizenRecordsFileReader(char *fileName, PersonLinkedList *people, VirusLinkedList *viruses);

    void readAndUpdateStructures();

private:
    char *fileName;
    PersonLinkedList *people;
    VirusLinkedList *viruses;
    static const char *NO_INPUT_FILE_ERROR;
    static const char *OPEN_FILE_ERROR;
    static const char *OPEN_FILE_READ_MODE;
    static const char *SPACE_DELIMITER;
    static const char *ERROR_IN_READING_FILE;

    bool setBooleanIsVaccinatedFromStringValue(char *);

    bool isPersonAlreadyInsertedAsVaccinated(Virus *, char *);

    bool isPersonAlreadyInsertedAsNotVaccinated(Virus *, char *);
};

#endif //ERGASIA1_CITIZENRECORDSFILEREADER_H
