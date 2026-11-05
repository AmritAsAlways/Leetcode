with temp as (select employee_id , department_id from employee where primary_flag='Y'),
temp1 as (select employee_id , department_id from employee group by employee_id having count(employee_id)=1)
select * from temp union all select * from temp1