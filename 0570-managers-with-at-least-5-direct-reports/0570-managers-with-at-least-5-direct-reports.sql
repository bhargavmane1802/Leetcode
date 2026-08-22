# Write your MySQL query statement below
select a.name 
from Employee a join ( 
    select managerId from Employee
    group by managerId having count(*)>=5
) b
on a.id=b.managerId ;
 