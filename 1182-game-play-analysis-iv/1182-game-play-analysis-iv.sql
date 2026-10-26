# Write your MySQL query statement below
with temp as (select player_id , min(event_date) as first_day from activity group by player_id)
select round(count(*)/(select count(*) from temp),2)  as fraction from activity as a join temp as t on t.player_id=a.player_id and datediff(a.event_date,t.first_day)=1