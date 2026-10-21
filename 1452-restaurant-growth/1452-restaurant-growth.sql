# Write your MySQL query statement below
WITH DailyAmount AS (
    -- Step 1: Har din ka total amount sum karo (kyunki ek din mein multiple customers ho sakte hain)
    SELECT visited_on, SUM(amount) AS total_amount
    FROM Customer
    GROUP BY visited_on
),
RollingWindow AS (
    -- Step 2: 7-day rolling window (6 preceding days + current day) lagao
    SELECT 
        visited_on,
        SUM(total_amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount,
        ROUND(AVG(total_amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW), 2) AS average_amount,
        ROW_NUMBER() OVER (ORDER BY visited_on) AS rn
    FROM DailyAmount
)
-- Step 3: Sirf wahi rows dikhao jahan poora 7 din ka window ban chuka ho (rn >= 7)
SELECT visited_on, amount, average_amount
FROM RollingWindow
WHERE rn >= 7;