# Write your MySQL query statement below
select tweet_id from Tweets as t where LENGTH(t.content)>15 