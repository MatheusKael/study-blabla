--In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
SELECT name FROM people WHERE id IN (
    SELECT person_id FROM stars WHERE movie_id IN (
        SELECT id FROM movies WHERE id IN (
            SELECT movie_id FROM stars WHERE person_id = (
                SELECT id FROM people where name = 'Kevin Bacon'
            )
        )
    )
) AND id != (
    SELECT id FROM people where name = 'Kevin Bacon'
);