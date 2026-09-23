# Write your MySQL query statement below
with temporarytable as (
    select author_id as id from Views as v where v.author_id=v.viewer_id
)

select distinct id from temporarytable order by id asc