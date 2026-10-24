# Write your MySQL query statement below
with temp as (select p.product_id, p.price*u.units as totalprice , u.units from prices as p left join unitssold as u on u.purchase_date>=p.start_date and u.purchase_date<=p.end_date and u.product_id=p.product_id )
select product_id , ifnull(round(sum(totalprice)/sum(units),2),0) as average_price from temp group by product_id