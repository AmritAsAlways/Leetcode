with temp as (select requester_id as id , count(requester_id) as cnt from requestaccepted group by requester_id ),
temp1 as (select accepter_id as id , count(accepter_id) as cnt from requestaccepted group by accepter_id)
select id , sum(cnt) as num from (select * from temp union all select * from temp1) as x group by id order by num desc limit 1