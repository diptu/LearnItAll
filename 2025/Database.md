# Desing
## https://leetcode.com/problem-list/database/

#### [175. Combine Two Tables](https://leetcode.com/problems/combine-two-tables/description/?envType=problem-list-v2&envId=database)
~~~SQL
select firstName, lastName, city, state from Person 
left outer join Address on 
Person.personId = Address.personId;
~~~