# Write your MySQL query statement below
with temp as (select a.machine_id , a.process_id , (a.timestamp-b.timestamp) as totaltime from activity as a join activity as b on a.machine_id=b.machine_id and b.process_id=a.process_id and a.activity_type='end' and b.activity_type='start')
select machine_id , round(avg(totaltime),3) as processing_time from temp group by machine_id