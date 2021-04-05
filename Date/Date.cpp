#include "Date.h"

Date::Date(char *dateAsString) {
    this->dateAsString = Helper::copyString(dateAsString);

    this->dateTimeObject = {0};

    sscanf(
            this->dateAsString,
            "%2d-%2d-%4d",
            &dateTimeObject.tm_mday,
            &dateTimeObject.tm_mon,
            &dateTimeObject.tm_year
    );

    this->year = this->dateTimeObject.tm_year;
    this->month = this->dateTimeObject.tm_mon;
    this->day = this->dateTimeObject.tm_mday;

    this->dateTimeInSeconds = mktime(&dateTimeObject);
}


bool Date::isEqualTo(Date *givenDate) {
    return (this->dateTimeInSeconds == givenDate->dateTimeInSeconds);
}

bool Date::isBiggerOrEqualThan(Date *givenDate) {
    return (this->dateTimeInSeconds >= givenDate->dateTimeInSeconds);
}

bool Date::isSmallerOrEqualThan(Date *givenDate) {
    return (this->dateTimeInSeconds <= givenDate->dateTimeInSeconds);
}

char *Date::toString() const {
    return this->dateAsString;
}
