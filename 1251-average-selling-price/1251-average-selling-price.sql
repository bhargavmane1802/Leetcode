# Write your MySQL query statement below
-- select p.product_id , as average_price
select a.product_id, round(coalesce(sum(a.price*a.units)/sum(a.units),0),2) as average_price
from (select p.product_id,p.price ,coalesce(u.units,0) as units from Prices p left join UnitsSold u on p.product_id =u.product_id and  u.purchase_date Between p.start_date and p.end_date  ) a 
group by a.product_id ;
