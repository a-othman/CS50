-- Keep a log of any SQL queries you execute as you solve the mystery.

-- What we know: took place on July 28, 2020 and that it took place on Chamberlin Street.

-- crime_scene_reports
-- This query is to find the crime_id = 295
-- crime_descripion: Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today with three 
-- witnesses who were present at the time — each of their interview transcripts mentions the courthouse.
SELECT id, description
FROM crime_scene_reports
WHERE year = 2020 AND month = 7 AND day = 28 AND street = 'Chamberlin Street';


-- interviews
SELECT id, name, transcript FROM interviews
WHERE year = 2020 AND month = 7 AND day = 28;
-- 161|Ruth|Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. If you have security 
-- footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
-- 162|Eugene|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, I was walking by
--  the ATM on Fifer Street and saw the thief there withdrawing some money.
-- 163|Raymond|As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief 
-- say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to
--  purchase the flight ticket.


-- courthouse_security_logs
SELECT license_plate FROM courthouse_security_logs
WHERE activity = 'exit' AND year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;

-- 5P2BI95
-- 94KL13X
-- 6P58WS2
-- 4328GD8
-- G412CB7
-- L93JTIZ
-- 322W7JE
-- 0NTHK55

-- atm_transactions

SELECT account_number, amount FROM atm_transactions
WHERE year= 2020 AND month = 7 AND day = 28 AND transaction_type = 'withdraw' AND atm_location = 'Fifer Street';

-- 28500762|48
-- 28296815|20
-- 76054385|60
-- 49610011|50
-- 16153065|80
-- 25506511|20
-- 81061156|30
-- 26013199|35

-- bank_accounts
SELECT person_id FROM bank_accounts
WHERE account_number IN (SELECT account_number FROM atm_transactions
                        WHERE year= 2020 AND month = 7 AND day = 28 AND transaction_type = 'withdraw' AND atm_location = 'Fifer Street');

-- 686048
-- 514354
-- 458378
-- 395717
-- 396669
-- 467400
-- 449774
-- 438727


-- airports
SELECT id, abbreviation, full_name FROM airports
WHERE city = 'Fiftyville';

-- 8|CSF|Fiftyville Regional Airport


-- flights
SELECT id FROM flights
WHERE origin_airport_id= 8 AND year = 2020 AND month = 7 AND day = 29;

-- 18, 23, 36, 43, 53

-- passengers

SELECT passport_number FROM passengers
WHERE flight_id IN (18, 23, 36, 43, 53);

2835165196,6131360461,3231999695,3592750733,2626335085,6117294637,2996517496,3915621712,4149859587,9183348466,7378796210,7874488539,4195341387,6263461050,3231999695,7951366683,7214083635,1695452385,5773159633,1540955065,8294398571,1988161715,9878712108,8496433585,7597790505,6128131458,6264773605,3642612721,4356447308,7441135547,7894166154,6034823042,4408372428,2312901747,1151340634,8174538026,1050247273,7834357192


-- phone_calls

-- caller
SELECT caller FROM phone_calls
WHERE year= 2020 AND month = 7 AND day = 28 AND duration< 60;
-- (130) 555-0289
-- (499) 555-9472
-- (367) 555-5533
-- (499) 555-9472
-- (286) 555-6063
-- (770) 555-1861
-- (031) 555-6622
-- (826) 555-1652
-- (338) 555-6650

-- receiver
SELECT receiver FROM phone_calls
WHERE year= 2020 AND month = 7 AND day = 28 AND duration< 60;

-- (996) 555-8899
-- (892) 555-8872
-- (375) 555-8161
-- (717) 555-1342
-- (676) 555-6554
-- (725) 555-3243
-- (910) 555-3251
-- (066) 555-9701
-- (704) 555-2131


CREATE TABLE people (
    id INTEGER,
    name TEXT,
    phone_number TEXT,
    passport_number INTEGER,
    license_plate TEXT,
    PRIMARY KEY(id)
);
-- people
SELECT name FROM people
WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year= 2020 AND month = 7 AND day = 28 AND duration< 60)
      AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id IN (18, 23, 36, 43, 53))
      AND license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55')
      AND id IN (686048,514354,458378,395717,396669,467400,449774,438727);

SELECT name FROM people
WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE year= 2020 AND month = 7 AND day = 28 AND duration< 60)
      AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id IN (18, 23, 36, 43, 53))
      AND license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55')
      AND id IN (686048,514354,458378,395717,396669,467400,449774,438727);
