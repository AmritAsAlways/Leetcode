with temp as (select distinct * from customer)
select customer_id from temp group by customer_id having count(customer_id)=(select count(*) from product)