# Write your MySQL query statement below
with temp as (select product_id , min(year) as first_year from sales group by product_id)
select t.product_id , t.first_year , s.quantity , s.price from sales as s join temp as t on t.first_year=s.year and s.product_id=t.product_id