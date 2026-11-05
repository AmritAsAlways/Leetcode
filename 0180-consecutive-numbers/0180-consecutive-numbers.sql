with temp as (select num , lead(num,1) over (order by id) as num1, lead(num,2) over (order by id) as num2 from logs)
select distinct  num as ConsecutiveNums from temp where num=num1 and num1=num2 