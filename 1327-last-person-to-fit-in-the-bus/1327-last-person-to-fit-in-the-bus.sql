with temp as (select * , sum(weight) over (order by turn) as totalweight from queue),
temp1 as (select * from temp where totalweight<=1000 order by totalweight desc)
select person_name from temp1 limit 1