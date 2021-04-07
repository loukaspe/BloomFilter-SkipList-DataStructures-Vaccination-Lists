#!/bin/bash

# ./testFile.sh virusesFile countriesFile numLines duplicatesAllowed
# I assume that each country and each virus has an one-word name ex 'France' and NOT 'Northern Ireland'

## Functions
generateRandomAgeUpTo120() {
  RANGE=120

  echo

  age=$RANDOM
  age=$(($RANDOM % $RANGE))

  echo $age
}

printRandomLineFromFile() {
  fileName=$1
  #shuf -n 1 $fileName
  sort < $fileName -R | head -n 1
}

generateRandomCountry() {
  printRandomLineFromFile $inputCountries
}

generateRandomVirus() {
  printRandomLineFromFile $inputViruses
}

generateRandomIdWithoutRepetition() {
  # Range is set to create up to 4-digits numbers
  RANGE=9999

  echo

  randomId=$RANDOM
  randomId=$(($RANDOM % $RANGE))

  while [[ "${citizenIdsArray[@]}" =~ "${randomId}" ]]; do
    randomId=$RANDOM
    randomId=$(($RANDOM % $RANGE))
  done

  citizenIdsArray+=$randomId
  echo $randomId
}

generateRandomIdWithRepetition() {
  # Range is set to create up to 4-digits numbers
  RANGE=9999

  echo

  randomId=$RANDOM
  randomId=$(($RANDOM % $RANGE))

  echo $randomId
}

generateRandomId() {
  if [ "$duplicatesAllowed" = true ]; then
    generateRandomIdWithRepetition
  else
    generateRandomIdWithoutRepetition
  fi
}

generateRandomNameFrom3UpTo12Chars() {
  RANGE=9

  echo
  numOfCharacters=$((($RANDOM % $RANGE) + 3))

  tr -dc A-Za-z </dev/urandom | head -c $numOfCharacters
  echo ''
}

generateRandomVaccinationStatus() {
  FLIP=$(($(($RANDOM % 10)) % 2))
  if [ $FLIP -eq 1 ]; then
    age=$1
    yearOfBirth=$((2021-$age))

    RANGE=365
    echo
    randomDaysNumber=$(($RANDOM % $RANGE))

    echo "YES $(date -d "$yearOfBirth-01-01 + $randomDaysNumber days" +'%d/%m/%Y')"
  else
    echo "NO"
  fi
}

#Input variables
inputViruses=$1
inputCountries=$2
numLines=$3
duplicatesAllowed=$4
# Array to keep generated citizenIds to avoid repetition
citizenIdsArray=()


for i in $( eval echo {1..$numLines} )
do
  citizenId=$(generateRandomId | tr -d '\n')
  firstName=$(generateRandomNameFrom3UpTo12Chars  | tr -d '\n')
  lastName=$(generateRandomNameFrom3UpTo12Chars  | tr -d '\n')
  country=$(generateRandomCountry  | tr -d '\n')
  age=$(generateRandomAgeUpTo120  | tr -d '\n')
  virus=$(generateRandomVirus  | tr -d '\n')
  vaccinationStatus=$(generateRandomVaccinationStatus "${age}"  | tr -d '\n')

  echo  "${citizenId} ${firstName} ${lastName} ${country} ${age} ${virus} ${vaccinationStatus}" >> ./inputFile.txt
done
