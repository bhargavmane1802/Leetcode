-- # Write your MySQL query statement below
-- select q.query_name ,round(avg((q.rating/q.position)),2)as quality ,poor_query_percentage from Queries q join 
-- (select t.query_name , round(avg(rating)) as poor_query_percentage from Queries t where t.rating<3 group by t.query_name) a
-- on a.query_name=q.query_name
-- group by q.query_name;

SELECT 
    query_name,
    ROUND(AVG(rating / position), 2) AS quality,
    ROUND(
        SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) 
        / COUNT(*) * 100,
        2
    ) AS poor_query_percentage
FROM Queries
GROUP BY query_name;