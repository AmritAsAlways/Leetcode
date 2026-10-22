# Write your MySQL query statement below
select w.id from weather as w join weather as w1 on datediff(w.recordDate,w1.recordDate)=1 and w.temperature>w1.temperature