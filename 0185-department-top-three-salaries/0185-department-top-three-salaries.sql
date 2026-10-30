with tmp AS (
    SELECT * , DENSE_RANK() OVER(partition by departmentId order by salary desc) as rnk from Employee
)
SELECT 
    d.name AS Department,
    e.name AS Employee,
    e.salary
FROM tmp e
LEFT JOIN Department d
On e.departmentId = d.id
WHERE e.rnk <= 3