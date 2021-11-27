use deadlock_db;

show tables;

select * from student;
SET SQL_SAFE_UPDATES=0;
set autocommit = 0;
start transaction;


-- insert into student(fname,salary) values ("ravi",5000);
update student
set salary = 5900
where fname="nirbhay";
select * from student;
rollback;
commit;


