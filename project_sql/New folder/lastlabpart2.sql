use deadlock_db;

SET SQL_SAFE_UPDATES=0;
set autocommit = 0;
start transaction;
update student
set salary = 4900
where fname="nirbhay";
-- insert into student(fname,salary) values ("ravi bhandari",50);
select * from student;
rollback;
commit;