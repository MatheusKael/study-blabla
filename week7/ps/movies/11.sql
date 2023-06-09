--In 11.sql, write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
SELECT title FROM movies LEFT JOIN ratings WHERE movies.id = ratings.movie_id AND movies.id IN (
    SELECT movie_id FROM stars WHERE person_id = (
        SELECT id FROM people WHERE name = 'Chadwick Boseman'
    )
) ORDER BY ratings.rating DESC limit 5;