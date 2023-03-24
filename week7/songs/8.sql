--In 7.sql, write a SQL query that returns the average energy of songs that are by Drake
SELECT avg(energy) AS average_energy FROM songs WHERE artist_id = (SELECT id FROM );