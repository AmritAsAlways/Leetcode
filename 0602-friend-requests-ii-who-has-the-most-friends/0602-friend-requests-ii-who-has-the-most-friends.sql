# Write your MySQL query statement below
with temp as (select requester_id as id , count(requester_id) as num from requestaccepted group by requester_id),
temp1 as (select accepter_id as id , count(accepter_id) as num from requestaccepted group by accepter_id)
select id , sum(num) as num from (select * from temp union all select * from temp1) as t group by id order by num desc limit 1
