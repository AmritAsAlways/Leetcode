# Write your MySQL query statement below
select e1.name  from employee as e join employee as e1 on e.managerId=e1.id group by e.managerId having count(e.managerId)>=5