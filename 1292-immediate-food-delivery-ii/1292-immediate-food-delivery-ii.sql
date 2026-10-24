# Write your MySQL query statement below
with temp as (select customer_id , min(order_date) as order_date from Delivery group by customer_id) 
select round(count(case when d.order_date=d.customer_pref_delivery_date then 1 end)*100/count(*),2) as immediate_percentage from temp as t join delivery as d on d.customer_id=t.customer_id and d.order_date=t.order_date