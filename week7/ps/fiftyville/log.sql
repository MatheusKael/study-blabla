-- Keep a log of any SQL queries you execute as you solve the mystery.
--All you know is that the theft took place on July 28, 2021 and that it took place on Humphrey Street.
-- Select every flighst comming and going to town at ^ this date
SELECT id, day FROM flights WHERE id IN (SELECT id FROM flights WHERE origin_airport_id =
    (SELECT id FROM airports WHERE city = "Fiftyville")
    OR destination_airport_id =
    (SELECT id FROM airports WHERE city = "Fiftyville")) AND day = 28;
