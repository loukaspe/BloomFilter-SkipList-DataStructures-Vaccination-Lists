cmake_minimum_required(VERSION 3.16)
project(ergasia1)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ergasia1
        main.cpp
        BitArray/BitArray.cpp BitArray/BitArray.h
        BloomFilter/BloomFilter.cpp BloomFilter/BloomFilter.h
        Helper/Helper.cpp Helper/Helper.h
        NotVaccinatedPersonSkipListNode/NotVaccinatedPersonSkipListNode.cpp NotVaccinatedPersonSkipListNode/NotVaccinatedPersonSkipListNode.h
        NotVaccinatedSkipList/NotVaccinatedSkipList.cpp NotVaccinatedSkipList/NotVaccinatedSkipList.h
        VaccinatedPersonSkipListNode/VaccinatedPersonSkipListNode.cpp VaccinatedPersonSkipListNode/VaccinatedPersonSkipListNode.h
        VaccinatedSkipList/VaccinatedSkipList.cpp VaccinatedSkipList/VaccinatedSkipList.h
        Person/Person.cpp Person/Person.h
        Vaccination/Vaccination.cpp Vaccination/Vaccination.h
)