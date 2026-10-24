# Write your MySQL query statement below
with temp as (select product_id , min(year) as first_year from sales group by product_id)  
select t.product_id , t.first_year , s.quantity , s.price from temp as t join sales as s on s.year=t.first_year and s.product_id=t.product_id