# Write your MySQL query statement below
select s.product_id , t.year as first_year , s.quantity, s.price
from Sales s join (select a.product_id, min(a.year)as year from Sales a group by a.product_id ) t
on s.product_id=t.product_id and s.year=t.year;