create database confectionery;
use confectionery;

create table candies(
	candie_id varchar(30) not null primary key,
    nameofcandy varchar(50) ,
    brand varchar(50),
    cost integer,
    flavour varchar(50),
    quantity integer
);
insert into candies values("1","mazelo","parle",4,"orange",50),
							("2","mazelo","parle",4,"banana",10),
                            ("3","mazelo","parle",4,"mango",500),
                            ("4","mazelo","parle",4,"peach",50),
                            ("5","pulse","passpass",2,"kachcha aam",40);

select * from candies;

start transaction;
SET SQL_SAFE_UPDATES=0;
set autocommit = 0;

update candies
set quantity = quantity - 10
where candie_id = "2";

update candies
set quantity = quantity - 100
where candie_id = "3";

commit;
rollback;
