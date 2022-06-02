-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Theft took place in July 28, 2021 in Humphrey Street

-- Check crime scene reports

SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';

-- crime happened at 10:15am at the Humphrey Street bakery, littering took place at 16.36

-- check interviews
SELECT name, transcript FROM interviews WHERE month = 7 AND day = 28;
--eugene saw the thief withdrawing money in leggett st
--three people mentions bakery: Ruth, Eugene, Raymond. Emma is excluded since she's the owner

--check withdraws
SELECT amount, account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

--check matching accounts
SELECT atm_transactions.amount, name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
    WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.atm_location = 'Leggett Street' AND atm_transactions.transaction_type = 'withdraw';

--raymond mentioned that he heard the thief on phone talking about flight tickets being bought earliest in 29.07.2021 check airports as it was in the
SELECT abbreviation, full_name, city FROM airports WHERE city = 'Fiftyville';

--check flights and order them to find earliest
SELECT flights.id, full_name, city, flights.hour, flights.minute FROM airports JOIN flights ON airports.id = flights.destination_airport_id
 WHERE flights.origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') AND flights.year = 2021 AND flights.month = 7 AND flights.day = 29 ORDER BY flights.hour, flights.minute;

--check the passenger list in first flight 8.20 at la guardia with flight id 36
SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat FROM people JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id WHERE flights.year = 2021 AND flights.month = 7 AND flights.day = 29 AND flights.hour = 8 AND flights.minute = 20 ORDER BY passengers.passport_number;

--check phone calls from raymond's info
SELECT phone_calls.duration, name FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller WHERE phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration <= 60 ORDER BY phone_calls.duration;

--check possible receiver
SELECT phone_calls.duration, name FROM people JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration <= 60 ORDER BY phone_calls.duration;


SELECT name, bakery_security_logs.hour, bakery_security_logs.minute FROM people JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
 WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28 AND bakery_security_logs.activity = 'exit' AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute >= 15 AND bakery_security_logs.minute <= 25 ORDER BY bakery_security_logs.minute;