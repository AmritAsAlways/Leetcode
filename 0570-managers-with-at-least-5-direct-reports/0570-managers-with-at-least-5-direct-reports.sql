# Write your MySQL query statement below
select e.name from employee as e join employee as e1 on e.id=e1.managerId group by e.id having count(e.id)>=5