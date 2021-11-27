create database lock_data;
show tables;

create table Variable(
	id varchar(20) not null primary key,
    val integer not null
);
insert into Variable values ('Y',10),('Z',20),('X',45);
select * from variable;

use lock_data;

start transaction;

SET SQL_SAFE_UPDATES=0;
set autocommit = 0;

update variable
set val = val -10
where id = 'Y';

update variable
set val = val + 20
where id = 'Z';

commit;
rollback;
