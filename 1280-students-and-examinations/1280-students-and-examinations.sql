# Write your MySQL query statement below
select a.student_id ,a.student_name ,a.subject_name ,COALESCE(b.attended, 0) AS attended_exams

from (select * from Students join Subjects )a 
left join (
    select student_id ,subject_name,count(*) as attended 
    from Examinations 
    group by student_id ,subject_name 
) b 
on a.student_id=b.student_id and a.subject_name=b.subject_name
order by student_id , subject_name asc ;