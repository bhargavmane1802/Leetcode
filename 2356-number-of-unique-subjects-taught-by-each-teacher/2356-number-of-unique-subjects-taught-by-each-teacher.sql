# Write your MySQL query statement below
with drank as (
    select t.teacher_id,(dense_rank() over (partition by t.teacher_id order by t.subject_id)) as a from Teacher t)
select x.teacher_id,max(x.a) as cnt from drank x group by x.teacher_id;
