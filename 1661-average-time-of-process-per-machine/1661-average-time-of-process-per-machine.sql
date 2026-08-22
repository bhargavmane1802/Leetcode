SELECT s.machine_id,
       ROUND(e.avg_end - s.avg_start, 3) AS processing_time
FROM
(
    SELECT machine_id, AVG(timestamp) AS avg_start
    FROM Activity
    WHERE activity_type = 'start'
    GROUP BY machine_id
) s
JOIN
(
    SELECT machine_id, AVG(timestamp) AS avg_end
    FROM Activity
    WHERE activity_type = 'end'
    GROUP BY machine_id
) e
ON s.machine_id = e.machine_id;