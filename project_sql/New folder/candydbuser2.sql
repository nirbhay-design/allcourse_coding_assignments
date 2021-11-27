use confectionery;

start transaction;
SET SQL_SAFE_UPDATES=0;
set autocommit = 0;

update candies
set quantity = quantity - 300
where candie_id = "3";

update candies
set quantity = quantity - 5
where candie_id = "2";

commit;
rollback;
