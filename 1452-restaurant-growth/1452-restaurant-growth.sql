-- with temp as (select *, sum(amount) over (order by visited_on) AS total_sum from customer group by visited_on)
-- select visited_on , total_sum - coalesce(lag(total_sum,6) over (order by visited_on),amount) as totalsum from temp 
with temp as (select visited_on , sum(amount) as amount , count(visited_on) as cnt from customer group by visited_on) , 
temp1  as (select * , sum(amount) over (order by visited_on) as totalsum , sum(cnt) over (order by visited_on) as totalcount  from temp),
temp2 as (select * , coalesce(lag(totalcount,6) over (order by visited_on),0) as prevcount , coalesce(lag(totalsum,7) over (order by visited_on),0) as prevsum from temp1),
temp3 as (select * from temp2 where prevcount!=0)
select visited_on , totalsum-prevsum as amount , round((totalsum-prevsum)/7,2) as average_amount from temp3