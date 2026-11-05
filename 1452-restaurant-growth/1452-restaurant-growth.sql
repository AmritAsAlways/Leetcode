with temp as (select visited_on , sum(amount) as amount from customer group by visited_on),
temp1 as (select visited_on , sum(amount) over (order by visited_on) as totalamount , lag(visited_on,6) over (order by visited_on) as prevdate from temp group by visited_on),
temp2 as (select visited_on , totalamount , prevdate, coalesce(lag(totalamount,7) over (order by visited_on),0) as prevtotal from temp1),
temp3 as (select visited_on, totalamount-prevtotal as amount from temp2 where prevdate is not null)
select *  ,  round(amount/7,2) as average_amount from temp3