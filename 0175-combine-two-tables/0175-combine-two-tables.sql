# Write your MySQL query statement below
SELECT Person.firstName,Person.lastname,Address.city,Address.state 
from Person LEFT JOIN Address
on Person.personId = Address.personId