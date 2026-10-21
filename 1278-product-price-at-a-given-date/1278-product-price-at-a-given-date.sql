# Write your MySQL query statement below
-- Part 1: Jin products ka price 2019-08-16 tak change hua hai (latest price uthana hai)
SELECT product_id, new_price AS price
FROM Products
WHERE (product_id, change_date) IN (
    SELECT product_id, MAX(change_date)
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
)

UNION

-- Part 2: Jin products ka koi bhi price change 2019-08-16 ke baad hua hai (unka default price 10 hoga)
SELECT DISTINCT product_id, 10 AS price
FROM Products
WHERE product_id NOT IN (
    SELECT DISTINCT product_id
    FROM Products
    WHERE change_date <= '2019-08-16'
);