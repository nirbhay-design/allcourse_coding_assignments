show databases;
set session transaction isolation level repeatable read;
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

SET SQL_SAFE_UPDATES=0;
set autocommit = 0;
use mytestdb;
select * from book_details;
start transaction;

update book_details set book_name = "nirbhay1";
select * from book_details;

update author_details set auth_name="mayank";
select * from author_details;

commit;
rollback;
show session variables like "%transaction_isolation";



SET SQL_SAFE_UPDATES=0;
set autocommit = 0;

start transaction;

update book_details
set book_name = "self comes to your mind"
where book_id = "Da001_Sel";

update book_details
set book_name = "Emotion mcne"
where book_id = "Mi009_Emo";

select * from author_details;
commit;
rollback;

use mytestdb;
start transaction;

SET SQL_SAFE_UPDATES=0;
set autocommit = 0;

update book_details
set book_name = "self comes to your mind"
where book_id = "Da001_Sel";
select * from book_details;

update book_details
set book_name = "Emotion mcne"
where book_id = "Mi009_Emo";
select * from book_details;

select * from author_details;
commit;
rollback;


