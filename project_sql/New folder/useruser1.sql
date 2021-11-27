use lock_data;

start transaction;

SET SQL_SAFE_UPDATES=0;
set autocommit = 0;

update variable
set val = val + 200
where id = 'Z';
select * from variable;
update variable
set val = val*10
where id = 'Y';

commit;
rollback;
