-- Keep a log of any SQL queries you execute as you solve the mystery.
--All you know is that the theft took place on July 28, 2021 and that it took place on Humphrey Street.

SELECT * FROM crime_scene_reports WHERE day = 28 AND street = 'Humphrey Street';


SELECT * FROM interviews WHERE transcript LIKE '%bakery%' AND day = 28;
--Select every flight out of town at July 29, 2021
SELECT * FROM flights WHERE id IN (SELECT id FROM flights WHERE origin_airport_id =
    (SELECT id FROM airports WHERE city = "Fiftyville")) AND day = 29;

-- All people from the earliest flight at date 29
SELECT * FROM people WHERE passport_number IN (
    SELECT passport_number FROM passengers WHERE flight_id = 36);


SELECT * FROM phone_calls  WHERE caller IN (
    SELECT phone_number FROM people WHERE passport_number IN (
        SELECT passport_number FROM passengers WHERE flight_id = 36)
    ) AND day = 28 AND duration < 60;

SELECT * FROM people WHERE phone_number IN (
    SELECT caller FROM phone_calls  WHERE caller IN (
        SELECT phone_number FROM people WHERE passport_number IN (
            SELECT passport_number FROM passengers WHERE flight_id = 36)
    ) AND day = 28 AND duration < 60
);

SELECT people.name, * FROM bakery_security_logs LEFT JOIN people WHERE people.license_plate = bakery_security_logs.license_plate
AND people.license_plate IN (
    SELECT license_plate FROM people WHERE phone_number IN (
        SELECT caller FROM phone_calls  WHERE caller IN (
            SELECT phone_number FROM people WHERE passport_number IN (
                SELECT passport_number FROM passengers WHERE flight_id = 36)
        ) AND day = 28 AND duration < 60
    )
) AND day = 28 AND hour = 10;

-- Who withdray money at ATM Leggett Street at that day's morning

SELECT * FROM atm_transactions WHERE atm_location = 'Leggett Street'
            AND day = 28;

SELECT * FROM bank_accounts WHERE account_number IN (
    SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street'
                AND day = 28 AND transaction_type = 'withdraw'
);


SELECT * FROM people WHERE id IN (
    SELECT person_id FROM bank_accounts WHERE account_number IN (
        SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street'
                    AND day = 28 AND transaction_type = 'withdraw'
    )
) AND name IN (
SELECT people.name FROM bakery_security_logs LEFT JOIN people WHERE people.license_plate = bakery_security_logs.license_plate
    AND people.license_plate IN (
        SELECT license_plate FROM people WHERE phone_number IN (
            SELECT caller FROM phone_calls  WHERE caller IN (
                SELECT phone_number FROM people WHERE passport_number IN (
                    SELECT passport_number FROM passengers WHERE flight_id = 36)
            ) AND day = 29 AND duration < 60
        )
    ) AND day = 28 AND hour = 10
);