create database Emaildatabase;

show databases;
use emaildatabase;

show tables;
create table userinfo(
	emailid varchar(60) not null primary key,
    passwd varchar(60) not null,
    fname varchar(40),
    lname varchar(40),
    country varchar(40),
    age int
);

create table inbox (
	from_eid varchar(60) not null,
    to_eid varchar(60) not null,
    tmstp timestamp not null,
    subj varchar(30),
    mailcontent varchar(1000),
	foreign key (from_eid) references userinfo(emailid),
    foreign key (to_eid) references userinfo(emailid)
);

create table trash (
	from_eid varchar(60) not null,
    to_eid varchar(60) not null,
    tmstp timestamp not null,
    subj varchar(30),
    mailcontent varchar(1000),
	foreign key (from_eid) references userinfo(emailid),
    foreign key (to_eid) references userinfo(emailid)
);

create table allmails(
	from_eid varchar(60) not null,
    to_eid varchar(60) not null,
    tmstp timestamp not null,
    subj varchar(30),
    mailcontent varchar(1000),
	foreign key (from_eid) references userinfo(emailid),
    foreign key (to_eid) references userinfo(emailid)
);


create table archieved(
	from_eid varchar(60) not null,
    to_eid varchar(60) not null,
    tmstp timestamp not null,
    subj varchar(30),
    mailcontent varchar(1000),
	foreign key (from_eid) references userinfo(emailid),
    foreign key (to_eid) references userinfo(emailid)
);
create table sent(
	from_eid varchar(60) not null,
    to_eid varchar(60) not null,
    tmstp timestamp not null,
    subj varchar(30),
    mailcontent varchar(1000),
	foreign key (from_eid) references userinfo(emailid),
    foreign key (to_eid) references userinfo(emailid)
);



