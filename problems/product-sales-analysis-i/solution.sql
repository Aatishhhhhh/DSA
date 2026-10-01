# Write your MySQL query statement below
select p.product_name, Sales.year, Sales.price from Product p right join Sales on p.product_id = Sales.product_id;