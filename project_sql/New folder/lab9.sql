show databases;
create database deadlock_db;

use deadlock_db;

create table student(
	fname varchar(50),
    salary integer
);
drop table student;

show tables;

insert into student
values ("nirbhay",5000),("raj",4000),("dhoni",3000);
select * from student;


begin;

SET SQL_SAFE_UPDATES=0;
update student
set salary = salary - 1000
where fname = "nirbhay";

update student
set salary = salary - 500
where fname = "ramesh";

select * from student;

commit;
