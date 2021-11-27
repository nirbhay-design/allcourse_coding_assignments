create database anotherdb;
use anotherdb;

create table tabla(
	id integer,
    name varchar(50)
);

insert into tabla values
(1,"ravi"),
(2,"rav"),
(3,"nirbhay"),
(4,"manveeer"),
(5,"ranveer"),
(6,"tahir");


select * from tabla;

insert into tabla values (4,"nirbhay");

create trigger trigo
after insert
on tabla
for each row
update tabla
set id = id + 5
where name = new.name;

insert into tabla values (6,"nirbhay");
select * from tabla
