use deadlock_db;

select * from student;

start transaction;

begin;

set SQL_SAFE_UPDATES=0;
update student
set salary = salary - 400
where fname = "ramesh";

select * from student;

update student
set salary = salary - 100
where fname = "nirbhay";
commit;
rollback;
