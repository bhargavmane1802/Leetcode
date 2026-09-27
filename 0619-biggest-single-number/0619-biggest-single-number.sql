# Write your MySQL query statement below
select max(t.num)as num
from (select a.num,count(a.num) as c from MyNumbers a group by a.num) t
where t.c=1; 