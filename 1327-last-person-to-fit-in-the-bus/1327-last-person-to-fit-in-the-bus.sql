with temp as (select person_name , weight , sum(weight) over (order by turn) as totalweight , turn from queue)
select person_name from temp where totalweight<=1000 order by turn desc limit 1