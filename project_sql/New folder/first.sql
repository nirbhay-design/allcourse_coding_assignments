-- show databases; 
-- create database mytestdb;

use mytestdb; 

-- CREATE TABLE book_details (
--   auth_id varchar(40) Not null,
--   book_id varchar(40) NOT NULL,
--   book_name varchar(40) NOT NULL,
--   PRIMARY KEY (book_id)
-- );


-- CREATE table author_details(
--     auth_id VARCHAR(40) not null primary key,
--     auth_name varchar(50) not null
-- );

-- create table purchase_det(
--     book_id varchar(40) not null,
--     pur_dt varchar(40) not null,
--     copies integer not null, 
--     price_dollar integer not null,
--     pur_price integer,
--     book_val integer
-- );

select * from book_details;
select * from author_details;
select * from purchase_det;
-- create view myview as
-- select auth_name,book_name,copies,count(book_name) as book_count
-- from ((book_details inner join author_details on book_details.auth_id = author_details.auth_id) 
-- inner join purchase_det on book_details.book_id = purchase_det.book_id)
-- group by book_name;


-- select * from myview;

-- insert into purchase_det (book_id,pur_dt,copies,price_dollar) values("Da001_Sel", "Sep 1, 2021", 1, 60);

-- create trigger cal_purr
-- before insert
-- on purchase_det
-- for each row
-- set new.pur_price = new.price_dollar - 5, new.book_val = new.pur_price - 10;


select * from purchase_det;

create view myv as
select auth_name,book_name,book_val
from ((book_details inner join author_details on book_details.auth_id = author_details.auth_id) 
inner join purchase_det on book_details.book_id = purchase_det.book_id);

create trigger cal_val
before insert
on purchase_det
for each row
set new.pur_price = new.price_dollar - 5, new.book_val = new.pur_price * new.copies;

insert into purchase_det (book_id,pur_dt,copies,price_dollar) values ("Mi009_Emo","Sep 4, 2021",4,40), ("Mi009_Emo","Sep 10, 2021",14,30), ("Mi009_Emo","Sep 14, 2021",43,40);


select * from myv;

create view myvw as
select auth_name,book_name,book_val
from ((book_details inner join author_details on book_details.auth_id = author_details.auth_id) 
inner join purchase_det on book_details.book_id = purchase_det.book_id) group by book_name;

select * from myvw;

select * from purchase_det;

select book_ids from
(select *,group_concat(book_id) as book_ids, count(pur_dt) as count_pur_dt from purchase_det group by pur_dt) as T
where pur_dt = 'Sep 1, 2021';

create table total_money(
	money integer,
    change_time varchar(50)
);
drop table total_money;
create trigger pur_price_up
after update
on purchase_det
for each row
insert into total_money values ((select sum(pur_price) from purchase_det),"current_date");

create trigger pur_price_ins
after insert
on purchase_det
for each row
insert into total_money values ((select sum(pur_price) from purchase_det),new.pur_dt);

create trigger pur_price_del
after delete
on purchase_det
for each row
insert into total_money values ((select sum(book_val) from purchase_det),getdate());

drop trigger pur_price_del;
drop trigger pur_price_ins;
drop trigger pur_price_up;

insert into purchase_det (book_id,pur_dt,copies,price_dollar) values ("Mi009_Emo","Sep 20, 2021",19,410);

show triggers;

select * from myv;

select * from purchase_det;

select * from total_money;

SET SQL_SAFE_UPDATES=0;

update purchase_det
set pur_price = price_dollar-5
where pur_price is NULL;

update purchase_det
set book_val = pur_price * copies
where book_val is NULL;

select * from purchase_det;

insert into purchase_det (book_id,pur_dt,copies,price_dollar) values ("Mi009_Emo","Sep 20, 2022",19,100);

create table price_per_book(
	book_id varchar(40),
    pur_price_tot integer
);

create trigger pur_price_per_book
after insert
on purchase_det
for each row
insert into price_per_book select * from (select book_id,sum(pur_price) as total_pur_price from purchase_det group by book_id) as T;


drop trigger pur_price_per_book;

select * from price_per_book;

select * from myview;
show triggers;