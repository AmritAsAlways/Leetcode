# Write your MySQL query statement below
select name , bonus from (select e.name , b.bonus from Employee as e left join Bonus as b on e.empId=b.empId ) as x where x.bonus<1000 or x.bonus is null