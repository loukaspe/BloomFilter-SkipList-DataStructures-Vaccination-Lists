#include "MenuPromptCreator.h"

const size_t MenuPromptCreator::SIZE_OF_INPUT_BUFFER = 1024;
char *MenuPromptCreator::AVAILABLE_COMMANDS[MenuPromptCreator::COMMANDS_NUMBER] = {
        "/vaccineStatusBloom",
        "/vaccineStatus",
        "/populationStatus",
        "/popStatusByAge",
        "insertCitizenRecord",
        "vaccinateNow",
        "/list-nonVaccinated-Persons",
        "/exit",
        "/help"
};

const char *MenuPromptCreator::INSERT_YOUR_COMMAND_MESSAGE = "Please enter your "
                                                             "command: ";
const char *MenuPromptCreator::NOT_VALID_COMMAND_MESSAGE = "This is not a valid"
                                                           " command. "
                                                           "To see the available command please type '/help'";
const char *MenuPromptCreator::READING_COMMAND_ERROR_MESSAGE = "ERROR: There was"
                                                               " an error reading your command.";

const char *MenuPromptCreator::AVAILABLE_COMMANDS_MESSAGE = "Commands' list: \n"
                                                            "1) /vaccineStatusBloom citizenID virusName\n"
                                                            "2) /vaccineStatus citizenID virusName\n"
                                                            "3) /vaccineStatus citizenID\n"
                                                            "4) /populationStatus [country] virusName date1 date2\n"
                                                            "5) /popStatusByAge [country] virusName date1 date2\n"
                                                            "6) /insertCitizenRecord citizenID firstName lastName country age virusName YES/NO [date]\n"
                                                            "7) /vaccinateNow citizenID firstName lastName country age virusName\n"
                                                            "8) /list-nonVaccinated-Persons virusName\n"
                                                            "9) /exit\n\n";

void MenuPromptCreator::showAllOptions() {
    cout << MenuPromptCreator::AVAILABLE_COMMANDS_MESSAGE << endl;
}

int MenuPromptCreator::executeInputCommand() {
    const int CONTINUE_EXECUTION = 1;
    const int EXIT = 0;
    const char *SPACE_DELIMITER = " ";

    char *command = NULL;
    char *citizenId = NULL;
    char *firstName = NULL;
    char *lastName = NULL;
    char *age = NULL;
    char *country = NULL;
    char *virusName = NULL;
    char *isVaccinated = NULL;
    Date *date1 = NULL;
    Date *date2 = NULL;
    char *possibleExtraArgument = NULL;
    char *argumentOne = NULL;
    char *argumentTwo = NULL;
    char *argumentThree = NULL;
    char *argumentFour = NULL;

    char *input = (char *) malloc(
            MenuPromptCreator::SIZE_OF_INPUT_BUFFER * sizeof(char)
    );

    if (input == NULL) {
        Helper::handleError(MenuPromptCreator::READING_COMMAND_ERROR_MESSAGE);
    }

    cout << MenuPromptCreator::INSERT_YOUR_COMMAND_MESSAGE;

    /* READ WHOLE INPUT */

    if (
            fgets(
                    input,
                    MenuPromptCreator::SIZE_OF_INPUT_BUFFER,
                    stdin
            ) == NULL
            ) {
        Helper::handleError(MenuPromptCreator::READING_COMMAND_ERROR_MESSAGE);
    };

    /* Fgets returns a '\n' character in the end of the input, so if one exists
     * we remove it. */
    input = Helper::removeNewLineCharacterFromString(input);

    /* READ COMMAND */

    command = strtok(input, SPACE_DELIMITER);
    // We check if there is a command and if it is in the available commands' array
    if (
            command == NULL
            || !Helper::inArray(
                    command,
                    MenuPromptCreator::AVAILABLE_COMMANDS,
                    MenuPromptCreator::COMMANDS_NUMBER
            )
            ) {
        cout << MenuPromptCreator::NOT_VALID_COMMAND_MESSAGE << endl;
        free(input);
        return CONTINUE_EXECUTION;
    }

    // /vaccineStatusBloom citizenID virusName
    if (strcmp(command, MenuPromptCreator::AVAILABLE_COMMANDS[0]) == 0) {

        citizenId = strtok(input, SPACE_DELIMITER);
        virusName = strtok(input, SPACE_DELIMITER);
        possibleExtraArgument = strtok(NULL, SPACE_DELIMITER);

        if (
                citizenId == NULL
                || virusName == NULL
                || possibleExtraArgument != NULL
                ) {
            cout << MenuPromptCreator::NOT_VALID_COMMAND_MESSAGE << endl;
            free(input);
            return CONTINUE_EXECUTION;
        }

//        vaccineStatusBloom(citizenId, virusName);

        free(input);
        return CONTINUE_EXECUTION;
    }

    // /vaccineStatus citizenID virusName
    // /vaccineStatus citizenID
        citizenId = strtok(input, SPACE_DELIMITER);
        virusName = strtok(input, SPACE_DELIMITER);
    if (strcmp(command, MenuPromptCreator::AVAILABLE_COMMANDS[1]) == 0) {

        if (
                citizenId == NULL
                ) {
            cout << MenuPromptCreator::NOT_VALID_COMMAND_MESSAGE << endl;
            free(input);
            return CONTINUE_EXECUTION;
        }

        if (virusName == NULL) {
//            vaccineStatusForAllViruses(citizenId);
        } else {
            possibleExtraArgument = strtok(NULL, SPACE_DELIMITER);

            if (
                    possibleExtraArgument != NULL
                    ) {
                cout << MenuPromptCreator::NOT_VALID_COMMAND_MESSAGE << endl;
                free(input);
                return CONTINUE_EXECUTION;
            }

//            vaccineStatusForSpecificVirus(citizenId, virusName);
        }

        free(input);
        return CONTINUE_EXECUTION;
    }

    //TODO: Synexizoyme edww


    // /populationStatus [country] virusName date1 date2
    if (strcmp(command, MenuPromptCreator::AVAILABLE_COMMANDS[2]) == 0) {

        argumentOne = strtok(input, SPACE_DELIMITER);
        argumentTwo = strtok(input, SPACE_DELIMITER);
        argumentThree = strtok(input, SPACE_DELIMITER);

        if (
                argumentOne == NULL
                || argumentTwo == NULL
                || argumentThree == NULL
                ) {
            cout << MenuPromptCreator::NOT_VALID_COMMAND_MESSAGE << endl;
            free(input);
            return CONTINUE_EXECUTION;
        }

        argumentFour = strtok(input, SPACE_DELIMITER);

        if (argumentFour == NULL) {
            virusName = argumentOne;
            date1 = new Date(argumentTwo);
            date2 = new Date(argumentThree);

//            populationStatusForAllCountries(virusName, date1, date2);
        } else {
            country = argumentOne;
            virusName = argumentTwo;
            date1 = new Date(argumentThree);
            date2 = new Date(argumentFour);

//            populationStatusForCountry(country, virusName, date1, date2);
        }

        free(input);
        return CONTINUE_EXECUTION;
    }

    // /popStatusByAge [country] virusName date1 date2
    if (strcmp(command, MenuPromptCreator::AVAILABLE_COMMANDS[3]) == 0) {

        argumentOne = strtok(input, SPACE_DELIMITER);
        argumentTwo = strtok(input, SPACE_DELIMITER);
        argumentThree = strtok(input, SPACE_DELIMITER);

        if (
                argumentOne == NULL
                || argumentTwo == NULL
                || argumentThree == NULL
                ) {
            cout << MenuPromptCreator::NOT_VALID_COMMAND_MESSAGE << endl;
            free(input);
            return CONTINUE_EXECUTION;
        }

        argumentFour = strtok(input, SPACE_DELIMITER);

        if (argumentFour == NULL) {
            virusName = argumentOne;
            date1 = new Date(argumentTwo);
            date2 = new Date(argumentThree);

//            popStatusByAgeForAllCountries(virusName, date1, date2);
        } else {
            country = argumentOne;
            virusName = argumentTwo;
            date1 = new Date(argumentThree);
            date2 = new Date(argumentFour);

//            popStatusByAgeForCountry(country, virusName, date1, date2);
        }

        free(input);
        return CONTINUE_EXECUTION;
    }

    // /insertCitizenRecord citizenID firstName lastName country age virusName YES NO [date]
    if( strcmp( command, MenuPromptCreator::AVAILABLE_COMMANDS[4] ) == 0 ) {
        citizenId = strtok(input, SPACE_DELIMITER);
        firstName = strtok(input, SPACE_DELIMITER);
        lastName = strtok(input, SPACE_DELIMITER);
        country = strtok(input, SPACE_DELIMITER);
        age = strtok(input, SPACE_DELIMITER);
        virusName = strtok(input, SPACE_DELIMITER);
        isVaccinated = strtok(input, SPACE_DELIMITER);

        if (
                citizenId == NULL
                || firstName == NULL
                || lastName == NULL
                || country == NULL
                || age == NULL
                || virusName == NULL
                || isVaccinated == NULL
                ) {
            cout << MenuPromptCreator::NOT_VALID_COMMAND_MESSAGE << endl;
            free(input);
            return CONTINUE_EXECUTION;
        }

        if (isVaccinated == "YES") {
            date1 = new Date(strtok(input, SPACE_DELIMITER));

//            insertVaccinated(
//                citizenId,
//                firstName,
//                lastName,
//                country,
//                age,
//                date1
//            );
        } else if (isVaccinated == "NO") {
//            insertNotVaccinated(
//                citizenId,
//                firstName,
//                lastName,
//                country,
//                age
//            );
        } else {
            cout << MenuPromptCreator::NOT_VALID_COMMAND_MESSAGE << endl;
            free(input);
            return CONTINUE_EXECUTION;
        }

        free(input);
        return CONTINUE_EXECUTION;
    }

    // /vaccinateNow citizenID firstName lastName country age virusName
    if (strcmp(command, MenuPromptCreator::AVAILABLE_COMMANDS[5]) == 0) {

        citizenId = strtok(input, SPACE_DELIMITER);
        firstName = strtok(input, SPACE_DELIMITER);
        lastName = strtok(input, SPACE_DELIMITER);
        country = strtok(input, SPACE_DELIMITER);
        age = strtok(input, SPACE_DELIMITER);
        virusName = strtok(input, SPACE_DELIMITER);

        if (
                citizenId == NULL
                || firstName == NULL
                || lastName == NULL
                || country == NULL
                || age == NULL
                || virusName == NULL
                ) {
            cout << MenuPromptCreator::NOT_VALID_COMMAND_MESSAGE << endl;
            free(input);
            return CONTINUE_EXECUTION;
        }

//        vaccinateNow(citizenId, firstName, lastName, country, age, virusName);

        free(input);
        return CONTINUE_EXECUTION;
    }

    // /list-nonVaccinated-Persons virusName
        virusName = strtok(input, SPACE_DELIMITER);
    if (strcmp(command, MenuPromptCreator::AVAILABLE_COMMANDS[6]) == 0) {

        if (virusName == NULL) {
            cout << MenuPromptCreator::NOT_VALID_COMMAND_MESSAGE << endl;
            free(input);
            return CONTINUE_EXECUTION;
        }

//        listNotVaccinatedPersonsForVirus(virusName);

        free(input);
        return CONTINUE_EXECUTION;
    }

    // exit command
    if (strcmp(command, MenuPromptCreator::AVAILABLE_COMMANDS[7]) == 0) {
        free(input);
        return EXIT;
    }

    // help command
    if (strcmp(command, MenuPromptCreator::AVAILABLE_COMMANDS[8]) == 0) {
        showAllOptions();
        free(input);
        return CONTINUE_EXECUTION;
    }
}

void MenuPromptCreator::createAndExecute() {
    // Continue execution until executeInputCommand() returns 0 (EXIT signal)
    while (executeInputCommand()) {}
}

MenuPromptCreator::MenuPromptCreator(VaccinationCenter *vaccinationCenter) : vaccinationCenter(vaccinationCenter) {}
