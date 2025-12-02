SELECT 
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary
FROM Employee e
JOIN Department d 
    ON e.departmentId = d.id
JOIN (
    SELECT departmentId, MAX(salary) AS MaxSalary
    FROM Employee
    GROUP BY departmentId
) AS m
    ON e.departmentId = m.departmentId
   AND e.salary = m.MaxSalary;
