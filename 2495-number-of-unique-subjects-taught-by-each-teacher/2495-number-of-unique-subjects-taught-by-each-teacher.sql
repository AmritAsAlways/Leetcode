# Write your MySQL query statement below
select x.teacher_id , count(x.teacher_id) as cnt from (select distinct teacher_id , subject_id from Teacher ) as x group by teacher_id