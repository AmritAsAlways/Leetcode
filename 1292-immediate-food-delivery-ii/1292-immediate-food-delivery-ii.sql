# Write your MySQL query statement below
WITH FirstOrders AS (
    -- Step 1: Har customer ka earliest order_date nikal lo
    SELECT customer_id, MIN(order_date) AS first_order_date
    FROM Delivery
    GROUP BY customer_id
)
-- Step 2: Un first orders par immediate vs scheduled check karke percentage nikal lo
SELECT 
    ROUND(
        SUM(CASE WHEN d.order_date = d.customer_pref_delivery_date THEN 1 ELSE 0 END) * 100.0 / COUNT(*), 
        2
    ) AS immediate_percentage
FROM Delivery AS d
JOIN FirstOrders AS f 
  ON d.customer_id = f.customer_id 
  AND d.order_date = f.first_order_date;