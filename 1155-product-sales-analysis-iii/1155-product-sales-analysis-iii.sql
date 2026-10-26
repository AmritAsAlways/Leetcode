# Write your MySQL query statement below
with temp as (select product_id , min(year) as first_year from sales group by product_id)
select s.product_id , s.year as first_year , s.quantity , s.price  from sales as s join temp as t on t.product_id=s.product_id and s.year=t.first_year