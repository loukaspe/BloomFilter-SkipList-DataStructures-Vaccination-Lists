#include "CitizenRecordsFileReader/CitizenRecordsFileReader.h"
#include "MenuPromptCreator/MenuPromptCreator.h"
#include <getopt.h>

const char *PROGRAM_OPTIONS = "c:b:";
const char *WRONG_PROGRAM_USAGE_ERROR = "Usage %s -c [citizenRecordsFile] -b [bloom size]\n";

int main(int argc, char *argv[]) {
    int opt;

    char *citizenRecordsFile;
    int bloomSizeInKiloBytes;

    while ((opt = getopt(argc, argv, PROGRAM_OPTIONS)) != -1) {
        switch (opt) {
            case 'c':
                citizenRecordsFile = Helper::copyString(optarg);
                break;
            case 'b':
                bloomSizeInKiloBytes = atoi(optarg);
                break;
            default:
                Helper::handleError(WRONG_PROGRAM_USAGE_ERROR);
        }
    }

    PersonLinkedList *people = new PersonLinkedList();
    VirusLinkedList *viruses = new VirusLinkedList();

    CitizenRecordsFileReader *fileReader = new CitizenRecordsFileReader(
            citizenRecordsFile,
            people,
            viruses
    );

    fileReader->readAndUpdateStructures();

    VaccinationCenter *vaccinationCenter = new VaccinationCenter(
            people,
            viruses
    );

    MenuPromptCreator *menuPromptCreator = new MenuPromptCreator(
            vaccinationCenter
    );

    menuPromptCreator->createAndExecute();

    return 0;
}
