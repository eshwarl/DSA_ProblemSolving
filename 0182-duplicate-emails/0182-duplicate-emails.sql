# Write your MySQL query statement below
-- select email from person  group by email
-- where count>1

SELECT email
FROM person
GROUP BY email
HAVING COUNT(email) > 1;
