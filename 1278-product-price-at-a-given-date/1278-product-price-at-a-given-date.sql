with temp as (select product_id , max(change_date) as lastdate from products where change_date<='2019-08-16' group by product_id),
x as (select product_id from products group by product_id),
temp2 as (select x.product_id , t.lastdate from x left join temp as t on x.product_id=t.product_id)
select t.product_id , ifnull(p.new_price,10) as price from temp2 as t left join products as p on t.product_id=p.product_id and t.lastdate=p.change_date