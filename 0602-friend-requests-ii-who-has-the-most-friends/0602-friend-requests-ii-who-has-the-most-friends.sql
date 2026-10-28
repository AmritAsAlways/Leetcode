with temp as (select accepter_id as id , count(accepter_id) as cnt from requestaccepted group by accepter_id) , temp1 as (select requester_id as id , count(requester_id) as cnt from requestaccepted group by requester_id),
totalone as (
    select * from temp union all select * from temp1
)

select id , sum(cnt) as num from totalone group by id order by num desc limit 1