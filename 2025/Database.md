# Desing
## https://leetcode.com/problem-list/database/

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


###[511. Game Play Analysis I](https://leetcode.com/problems/game-play-analysis-i/description/?envType=problem-list-v2&envId=database)
~~~SQL
select player_id,min(event_date) as first_login
from activity 
group by player_id;
~~~