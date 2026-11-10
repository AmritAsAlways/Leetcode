with temp as (select visited_on , sum(amount) as amount from customer group by visited_on),
temp1 as (select * , sum(amount) over (order by visited_on) as totalamount , lag(visited_on,6) over (order by visited_on) as prevdate from temp),
temp2 as (select * , coalesce(lag(totalamount,7) over (order by visited_on),0) as prevtotal from temp1)
select visited_on , totalamount-prevtotal as amount , round((totalamount-prevtotal)/7,2) as average_amount from temp2 where prevdate is not null