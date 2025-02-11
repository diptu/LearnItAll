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