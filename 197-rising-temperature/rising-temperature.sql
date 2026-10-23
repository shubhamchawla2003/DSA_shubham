# Write your MySQL query statement below
select w.id from Weather as w
inner join Weather as w1
ON DATEDIFF(w.recordDate, w1.recordDate) = 1
where w.temperature > w1.temperature;
