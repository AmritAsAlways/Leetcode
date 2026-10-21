# Write your MySQL query statement below
(
    -- Part 1: Sabse zyada movies rate karne wala user
    SELECT u.name AS results
    FROM Users AS u
    JOIN MovieRating AS mr ON u.user_id = mr.user_id
    GROUP BY u.user_id, u.name
    ORDER BY COUNT(mr.movie_id) DESC, u.name ASC
    LIMIT 1
)
UNION ALL
(
    -- Part 2: February 2020 mein sabse high average rating wali movie
    SELECT m.title AS results
    FROM Movies AS m
    JOIN MovieRating AS mr ON m.movie_id = mr.movie_id
    WHERE DATE_FORMAT(mr.created_at, '%Y-%m') = '2020-02'
    GROUP BY m.movie_id, m.title
    ORDER BY AVG(mr.rating) DESC, m.title ASC
    LIMIT 1
);