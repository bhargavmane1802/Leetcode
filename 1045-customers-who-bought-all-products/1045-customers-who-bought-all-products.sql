# Write your MySQL query statement below
with p as (select count(*) as c from Product )
select customer_id 
from Customer 
group by customer_id having count(distinct product_key )=(SELECT c FROM p);