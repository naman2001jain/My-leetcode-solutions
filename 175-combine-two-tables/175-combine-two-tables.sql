# Write your MySQL query statement below
Select FirstName, LastName, City, State from Person left Join Address on Person.personId = Address.personId;