# Write your MySQL query statement below
with temptable as (select customer_id , min(order_date) as order_date from delivery group by customer_id)
select round(count(case when t.order_date=d.customer_pref_delivery_date then 1 end)/count(*)*100,2) as immediate_percentage from delivery as d inner join temptable as t on t.customer_id=d.customer_id and t.order_date=d.order_date