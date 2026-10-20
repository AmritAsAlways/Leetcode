# Write your MySQL query statement below
select x.class from (select class , count(class) as student_in_class from Courses group by class) as x where x.student_in_class>=5