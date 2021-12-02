SELECT name FROM people
WHERE id IN(SELECT person_id FROM directors
            WHERE movie_id IN(SELECT movie_id FROM ratings
                              WHERE rating >= 9.0));

-- This query is not working properly, might check it later final count should be 1887 while its result 1882.
-- SELECT COUNT(name) FROM people
-- JOIN directors ON directors.person_id = people.id 
-- JOIN ratings ON ratings.movie_id = directors.movie_id
-- WHERE ratings.rating >= 9;


