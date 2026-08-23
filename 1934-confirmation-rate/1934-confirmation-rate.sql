-- # Write your MySQL query statement below
-- select a.user_id,round(coalesce((coalesce(b.con,0)/coalesce(d.total,0)),0),2) as confirmation_rate 
-- from (Signups a left join (
--     select user_id ,coalesce(count(*),0) as con 
--     from Confirmations 
--     where action ='confirmed'
--     group by user_id ,action
-- ) b on a.user_id=b.user_id ) 
-- left join (
--     select user_id ,coalesce(count(*),0) as total 
--     from Confirmations 
--     group by user_id 
-- )d on b.user_id =d.user_id;

SELECT 
    s.user_id,
    ROUND(COALESCE
    (SUM(c.action = 'confirmed') / COUNT(c.action),0),2) 
    AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c
    ON s.user_id = c.user_id
GROUP BY s.user_id;
