# Write your MySQL query statement below
with temp as (select player_id , min(event_date) as firstdate from activity group by player_id)
select round(count(case when datediff(a.event_date,t.firstdate)=1 then 1 end)/(select count(*) from temp),2) as fraction from  activity as a join temp as t on t.player_id=a.player_id 