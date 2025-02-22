# Desing
## https://leetcode.com/problem-list/database/
<!-- advance SQL : https://www.youtube.com/watch?v=ch520NKjHOg&list=PLGAnLqlBhx1H2ttudV4JeHotbvpbR7HQQ -->
#### [175. Combine Two Tables](https://leetcode.com/problems/combine-two-tables/description/?envType=problem-list-v2&envId=database)
~~~SQL
select firstName, lastName, city, state from Person 
left outer join Address on 
Person.personId = Address.personId;
~~~

### [620. Not Boring Movies](https://leetcode.com/problems/not-boring-movies/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT * 
FROM Cinema 
WHERE mod(id,2) = 1
and description <> 'boring'
order by rating desc;
~~~

### [183. Customers Who Never Order](https://leetcode.com/problems/customers-who-never-order/?envType=problem-list-v2&envId=database)
~~~SQL
select name as 'Customers' from Customers
left outer join Orders on
Customers.id = Orders.customerId
where Orders.id is NULL;
~~~

### [1527. Patients With a Condition](https://leetcode.com/problems/patients-with-a-condition/description/?envType=problem-list-v2&envId=database)
~~~SQL
select p.patient_id , p.patient_name ,p.conditions
 from Patients p
 where p.conditions like "DIAB1%" or p.conditions like "% DIAB1%";
~~~

### [182. Duplicate Emails](https://leetcode.com/problems/delete-duplicate-emails/description/?envType=problem-list-v2&envId=database)

~~~SQL
select Email from Person
Group by Email
Having Count(email) > 1 ;
~~~
### [196. Delete Duplicate Emails](https://leetcode.com/problems/delete-duplicate-emails/description/?envType=problem-list-v2&envId=database)

~~~SQL
delete from person 
where id not in (select t.minid from (select min(id) as minid from person group by email) t)
~~~


### [511. Game Play Analysis I](https://leetcode.com/problems/game-play-analysis-i/description/?envType=problem-list-v2&envId=database)
~~~SQL
select player_id,min(event_date) as first_login
from activity 
group by player_id;
~~~

### [577. Employee Bonus](https://leetcode.com/problems/employee-bonus/description/?envType=problem-list-v2&envId=database)
~~~SQL
select Employee.name, Bonus.bonus
from Employee
left Join bonus on employee.empId = bonus.empId
where Bonus.bonus is null OR Bonus.bonus<1000 
~~~

### [595. Big Countries](https://leetcode.com/problems/big-countries/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT name, population, area 
FROM World
WHERE area >= 3000000 or population >= 25000000;
~~~

### [596. Classes More Than 5 Students](https://leetcode.com/problems/classes-more-than-5-students/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT
    class
FROM Courses
GROUP BY class
HAVING COUNT(class) >= 5
~~~

### [607. Sales Person](https://leetcode.com/problems/sales-person/?envType=problem-list-v2&envId=database)
~~~SQL
select name from salesperson 
where sales_id not in (select o.sales_id from orders o where o.com_id in (select c.com_id from company c where c.name='RED'))
~~~

### [1075. Project Employees I](https://leetcode.com/problems/project-employees-i/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT  P.PROJECT_ID, ROUND(AVG(E.EXPERIENCE_YEARS),2) AS AVERAGE_YEARS
FROM PROJECT AS P
LEFT JOIN EMPLOYEE AS E
ON P.EMPLOYEE_ID= E.EMPLOYEE_ID
GROUP BY P.PROJECT_ID;  
~~~

### [1211. Queries Quality and Percentage](https://leetcode.com/problems/queries-quality-and-percentage/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT query_name,round(avg(rating/position),2) as quality, 
round(sum(rating<3)/count(*)*100,2) as  poor_query_percentage 
from Queries 
group by query_name
~~~

### [1251. Average Selling Price](https://leetcode.com/problems/average-selling-price/description/?envType=problem-list-v2&envId=database)

# coalesce simply returns the value of the 1st non-NULL argument in its parameter list.
~~~SQL
select p.product_id ,ROUND(COALESCE(SUM(u.units * p.price), 0)  / COALESCE(SUM(u.units), 1), 2) AS average_price
from Prices p 
left join UnitsSold u on 
p.product_id = u.product_id
AND u.purchase_date BETWEEN p.start_date AND p.end_date
group by p.product_id
~~~

### [1633. Percentage of Users Attended a Contest](https://leetcode.com/problems/percentage-of-users-attended-a-contest/description/?envType=problem-list-v2&envId=database)

~~~SQL
SELECT 
    r.contest_id,
    ROUND(COUNT(DISTINCT r.user_id) * 100.0 / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM 
    Register r
GROUP BY 
    r.contest_id
ORDER BY 
    percentage DESC, r.contest_id ASC;
~~~

### [1407. Top Travellers](https://leetcode.com/problems/top-travellers/?envType=problem-list-v2&envId=database)
~~~SQL

select name, 
sum(
    case when u.id = r.user_id 
        then distance
        else 0 
    end) as travelled_distance
from users u
left join rides r
on u.id = r.user_id
group by u.id
order by travelled_distance desc, name asc

# Alternnative solution
SELECT 
    u.name, 
    COALESCE(SUM(r.distance), 0) AS travelled_distance
FROM 
    Users u
LEFT JOIN 
    Rides r ON u.id = r.user_id
GROUP BY 
    u.id, u.name
ORDER BY 
    travelled_distance DESC, 
    u.name ASC;
~~~

### [1327. List the Products Ordered in a Period](https://leetcode.com/problems/list-the-products-ordered-in-a-period/description/?envType=problem-list-v2&envId=database)
~~~SQL
select p.product_name, sum(o.unit) as unit
from Orders o
join Products p
on o.product_id=p.product_id
where o.order_date>='2020-02-01' and o.order_date<='2020-02-29'
group by p.product_name
having sum(o.unit)>=100
~~~
### [1587. Bank Account Summary II](https://leetcode.com/problems/bank-account-summary-ii/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT name, SUM(amount) AS balance
FROM Users AS u
LEFT JOIN Transactions AS t
ON u.account = t.account
GROUP BY 1
HAVING balance > 10000;
# Alternnative solution
WITH cte
as (
select u.name as NAME,sum(t.amount) as BALANCE
from Transactions as t
inner join Users as u on
t.account = u.account
group by NAME
having sum(t.amount)> 10000
)
select * from cte;
~~~
### [1484. Group Sold Products By The Date](https://leetcode.com/problems/group-sold-products-by-the-date/description/?envType=problem-list-v2&envId=database)
~~~SQL 
SELECT 
    sell_date,
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(DISTINCT product ORDER BY product ASC SEPARATOR ',') AS products
FROM 
    Activities
GROUP BY 
    sell_date
ORDER BY 
    sell_date;
~~~

### [1581. Customer Who Visited but Did Not Make Any Transactions](https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT v.customer_id,
    count(v.visit_id) count_no_trans
FROM Visits v
LEFT JOIN Transactions t ON v.visit_id = t.visit_id
WHERE t.transaction_id IS NULL
GROUP BY 1
ORDER BY 2

# Alternnative solution
select customer_id, count(visit_id) as count_no_trans
from Visits 
where visit_id not in (select visit_id from Transactions)
group by customer_id;
~~~
### [181. Employees Earning More Than Their Managers](https://leetcode.com/problems/employees-earning-more-than-their-managers/description/?envType=problem-list-v2&envId=database)

~~~SQL
SELECT e1.NAME AS Employee
FROM Employee e1
INNER JOIN Employee e2 ON e1.managerId = e2.id
WHERE e1.salary > e2.salary;
~~~
### [197. Rising Temperature](https://leetcode.com/problems/rising-temperature/description/)
~~~SQL
SELECT w1.id
FROM Weather w1
INNER JOIN Weather w2 
ON w1.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 DAY)
WHERE w1.temperature > w2.temperature;
~~~

### [84. Find Customer Referee](https://leetcode.com/problems/find-customer-referee/description/?envType=problem-list-v2&envId=database)
~~~SQL
select name 
from customer 
where referee_id !=2 or referee_id is null;
~~~
### [586. Customer Placing the Largest Number of Orders](https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY count(customer_number) DESC LIMIT 1;
~~~
### [610. Triangle Judgement](https://leetcode.com/problems/triangle-judgement/description/?envType=problem-list-v2&envId=database)
~~~SQL
select x,y,z, 
case 
    when x+y>z and y+z>x and z+x>y 
    then 'Yes' 
    else 'No' 
end as triangle from triangle;
~~~
### [1050. Actors and Directors Who Cooperated At Least Three Times](https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/description/?envType=problem-list-v2&envId=database)
~~~SQL 
SELECT actor_id, director_id 
FROM ActorDirector
GROUP BY actor_id, director_id
HAVING COUNT(*) > 2
~~~
### [619. Biggest Single Number](https://leetcode.com/problems/biggest-single-number/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT max(num) AS num
FROM (
	SELECT num
	FROM MyNumbers
	GROUP BY num
	HAVING count(*) = 1
	) t
~~~
### [627. Swap Salary](https://leetcode.com/problems/swap-salary/description/?envType=problem-list-v2&envId=database)
~~~SQL
Update salary
SET
    sex = CASE sex
    WHEN 'm' THEN 'f'
    ELSE 'm'
END;
~~~
### [176. Second Highest Salary](https://leetcode.com/problems/second-highest-salary/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT max(salary) AS SecondHighestSalary
FROM employee
WHERE salary < (
		SELECT max(salary)
		FROM employee
		);

~~~

### [177. Nth Highest Salary](https://leetcode.com/problems/nth-highest-salary/description/?envType=problem-list-v2&envId=database)
~~~SQL
CREATE FUNCTION getNthHighestSalary (N INT)
RETURNS INT

BEGIN
	SET N = N - 1;

	RETURN (
			SELECT DISTINCT salary
			FROM Employee
			ORDER BY salary DESC LIMIT 1 OFFSET N
			);
END

~~~
### [178. Rank Scores](https://leetcode.com/problems/rank-scores/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT score
	,DENSE_RANK() OVER (
		ORDER BY score DESC
		) AS rank
FROM Scores
ORDER BY score DESC;

~~~
### [1068. Product Sales Analysis I](https://leetcode.com/problems/product-sales-analysis-i/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT 
    p.product_name,
    s.year,
    s.price
FROM sales AS s
LEFT JOIN product AS b 
ON s.product_id = p.product_id

~~~

### [1179. Reformat Department Table](https://leetcode.com/problems/reformat-department-table/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT id,
SUM(IF(month='Jan', revenue, NULL)) AS Jan_Revenue,
SUM(IF(month='Feb', revenue, NULL)) AS Feb_Revenue,
SUM(IF(month='Mar', revenue, NULL)) AS Mar_Revenue,
SUM(IF(month='Apr', revenue, NULL)) AS Apr_Revenue,
SUM(IF(month='May', revenue, NULL)) AS May_Revenue,
SUM(IF(month='Jun', revenue, NULL)) AS Jun_Revenue,
SUM(IF(month='Jul', revenue, NULL)) AS Jul_Revenue,
SUM(IF(month='Aug', revenue, NULL)) AS Aug_Revenue,
SUM(IF(month='Sep', revenue, NULL)) AS Sep_Revenue,
SUM(IF(month='Oct', revenue, NULL)) AS Oct_Revenue,
SUM(IF(month='Nov', revenue, NULL)) AS Nov_Revenue,
SUM(IF(month='Dec', revenue, NULL)) AS Dec_Revenue
FROM Department
Group BY id;
~~~
### [1148. Article Views I](https://leetcode.com/problems/article-views-i/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT DISTINCT author_id AS id
FROM VIEWS
WHERE author_id = viewer_id
ORDER BY id ASC;
~~~
### [184. Department Highest Salary](https://leetcode.com/problems/department-highest-salary/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT d.Name AS Department, e.Name As Employee, e.Salary AS Salary
FROM Employee AS e
LEFT JOIN Department AS d
ON e.DepartmentId = d.Id
WHERE (d.Id, e.Salary) in (SELECT DepartmentId, max(Salary)
FROM Employee
GROUP BY DepartmentId)


#Alternnative solution

SELECT Department
	,NAME AS "Employee"
	,salary AS "Salary"
FROM (
	SELECT d.NAME AS "Department"
		,e.salary
		,e.NAME
		,dense_rank() OVER (
			PARTITION BY e.departmentid ORDER BY e.salary DESC
			) AS salary_rank
	FROM employee e
	INNER JOIN department d ON e.departmentid = d.id
	) AS TEMP
WHERE salary_rank = 1

~~~

### [1084. Sales Analysis III](https://leetcode.com/problems/sales-analysis-iii/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT p.product_id, p.product_name
FROM Product AS p
JOIN Sales AS s 
ON p.product_id = s.product_id
GROUP BY p.product_id
HAVING 
    MIN(s.sale_date) >= '2019-01-01' 
    AND MAX(s.sale_date) <= '2019-03-31';
~~~

### [1280. Students and Examinations](https://leetcode.com/problems/students-and-examinations/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT 
    students.student_id,
    students.student_name,
    s.subject_name,
    count(e.subject_name) AS attended_exams
FROM students
INNER JOIN subjects s
LEFT JOIN examinations e ON e.student_id = students.student_id
	AND s.subject_name = e.subject_name
GROUP BY 1
	,3
ORDER BY 1 ASC
~~~
### [1693. Daily Leads and Partners](https://leetcode.com/problems/daily-leads-and-partners/description/?envType=problem-list-v2&envId=database)
~~~SQL
select date_id, make_name, 
        count(distinct lead_id) unique_leads, 
        count(distinct partner_id) unique_partners
from DailySales
group by date_id, make_name
~~~
### [1729. Find Followers Count](https://leetcode.com/problems/find-followers-count/description/?envType=problem-list-v2&envId=database)

~~~SQL
SELECT user_id,COUNT(user_id) AS followers_count
FROM followers
GROUP BY user_id
ORDER BY user_id
~~~
## [1741. Find Total Time Spent by Each Employee](https://leetcode.com/problems/find-total-time-spent-by-each-employee/description/?envType=problem-list-v2&envId=database)
~~~SQL
select 
    event_day as day,
    emp_id, 
    sum(out_time - in_time) as total_time 
from Employees 
group by emp_id,event_day
~~~
### [1789. Primary Department for Each Employee](https://leetcode.com/problems/primary-department-for-each-employee/description/?envType=problem-list-v2&envId=database)
~~~SQL
select employee_id, department_id 
from Employee
where primary_flag = 'Y' or employee_id in (
    select employee_id 
    from Employee
    group by employee_id
    having count(employee_id) = 1
)
~~~
### [1757. Recyclable and Low Fat Products](https://leetcode.com/problems/recyclable-and-low-fat-products/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT product_id FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y' ;
~~~
### [1141. User Activity for the Past 30 Days I](https://leetcode.com/problems/user-activity-for-the-past-30-days-i/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE (activity_date > "2019-06-27" AND activity_date <= "2019-07-27")
GROUP BY activity_date;
~~~
### [1795. Rearrange Products Table](https://leetcode.com/problems/rearrange-products-table/description/?envType=problem-list-v2&envId=database)
~~~SQL
select product_id, 'store1' as store,store1 as price
from products
where store1 is not null
union
select product_id, 'store2' as store,store2 as price
from products
where store2 is not null
union
select product_id,'store3' as store, store3 as price
from products
where store3 is not null
~~~
### [1731. The Number of Employees Which Report to Each Employee](https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee/description/?envType=problem-list-v2&envId=database)
~~~SQL
SELECT e1.employee_id, e1.name, COUNT(e1.employee_id) AS reports_count, ROUND(AVG(e2.age)) AS average_age
FROM Employees e1, Employees e2
WHERE e1.employee_id = e2.reports_to
GROUP BY e1.employee_id
ORDER BY employee_id
~~~

### [1873. Calculate Special Bonus](https://leetcode.com/problems/calculate-special-bonus/description/?envType=problem-list-v2&envId=database)
~~~SQL
Select employee_id, 
Case when employee_id % 2 <> 0 and
    substring(name,1,1) <> 'M' then salary
else 0
END as bonus
from employees
order by employee_id
~~~
### [1890. The Latest Login in 2020](https://leetcode.com/problems/the-latest-login-in-2020/description/?envType=problem-list-v2&envId=database)
~~~SQL

select 
    user_id, 
    max(time_stamp) as last_stamp
from Logins l
where year(time_stamp) = 2020
group by user_id;
~~~