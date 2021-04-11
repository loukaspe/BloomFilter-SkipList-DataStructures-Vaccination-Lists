PETEINARIS LOUKAS sdi1600134

IMPORTANT DISCLAIMERS:

1. My classes BloomFilter and BitArray are copied from another university project, and
specifically from Operating Systems with A.Delis.
Only change made was about the size that you give in the Description of the Exercise (100KBytes).
No other change made since their use was exactly what I needed for here too.

2. For virusesFile and countriesFile, I assume for reasons of simplicity that each
country and each virus has an one-word name ex 'France' and NOT 'Northern Ireland'

3. Wherever date1 and date2 I assume that date1 < date2 for simplicity.

4. According to https://piazza.com/class/kkx2o2gvper2nj?cid=41 & https://piazza.com/class/kkx2o2gvper2nj?cid=23
    vaccineStatus() should only check vaccinated skip list and if this search does not find
    a vaccinated citizen, then the citizen is considered NOT vaccinated, regardless if he
    exists or not in the not vaccinated skip list

5. According to https://piazza.com/class/kkx2o2gvper2nj?cid=54, citizenId may be string or integer

6. In insertCitizenRecord() if the Virus and the Country do not exist, then I treat them as
    new cases and insert them too in the appropriate structures