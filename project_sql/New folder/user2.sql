show databases;
set session transaction isolation level repeatable read;
use mytestdb;
show tables;
SET SQL_SAFE_UPDATES=0;
set autocommit = 0;

start transaction;


update author_details set auth_name="nirbhay";
select * from author_details;

update book_details set book_name = "mayank" where book_id = "Da001_Sel";
select * from book_details;
commit;
rollback;



SET SQL_SAFE_UPDATES=0;
set autocommit = 0;

start transaction;

update book_details
set book_name = "Emoticon mcney"
where book_id = "Mi009_Emo";

update book_details
set book_name = "self comes to your minds"
where book_id = "Da001_Sel";

commit;
rollback;


use mytestdb;
start transaction;

SET SQL_SAFE_UPDATES=0;
set autocommit = 0;

update book_details
set book_name = "Fan is useful in summers"
where book_id = "Ro015_Fan";

select * from book_details;

update book_details
set book_name = "Emotion mcne"
where book_id = "Mi009_Emo";
select * from book_details;

select * from author_details;
commit;
rollback;