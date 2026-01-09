drop database TMS;
create database TMS;
use TMS;


create table User (
user_id int not null,
firstName varchar(25) not null,
lastName varchar(25) not null,
city varchar(15) not null,
country varchar(15) not null,
PIN int not null,
gender char(6) not null,
email varchar(50) unique,
primary key(user_id)
);


create table User_contact_no(
contact_no varchar(12) unique not null,
user_id int,
foreign key(user_id) references User (user_id)
);


create table Taxi(
taxi_id int not null,
user_id int,
registration_no varchar(25) not null ,
make varchar(10) not null,
type varchar(25) not null,
year year not null,
status varchar(10) not null,

primary key(taxi_id)
);
alter table Taxi
add foreign key (user_id) references User (user_id);


create table Driver(
driver_id int not null,
taxi_id int,
firstName  varchar(25) not null,
lastName varchar(25) not null,
gender char(6) not null,
experience int,
city varchar(15) not null,
country varchar(15) not null,
PIN int not null,
salary int not null,
license_status varchar(10) not null,
working_hours int not null,
email varchar(50) unique,
primary key(driver_id)
);
alter table Driver
add foreign key (taxi_id) references Taxi (taxi_id);


create table Driver_contact_no(
contact_no varchar(12)  not null,
driver_id int,
foreign key(driver_id) references Driver(driver_id)
);


create table Owner(
owner_id int not null ,
taxi_id int,
firstName  varchar(25) not null,
lastName varchar(25) not null,
no_of_taxies int not null,
primary key(owner_id)
);
alter table Owner
add foreign key (taxi_id) references Taxi (taxi_id);


create table PaymentMethod(
payment_id int not null ,
user_id int, 
name varchar(15) not null,
code int not null,
description text,
primary key(payment_id)
);
alter table PaymentMethod
add foreign key (user_id) references User (user_id);

create table Bill_detail(
bill_no int not null ,
user_id int,
payment_id int,
discount int default null,
advance int default null,
bill_date date not null,
total_amount int not null,
primary key(bill_no)
);
alter table Bill_detail
add foreign key (user_id) references User (user_id),
add foreign key (payment_id) references PaymentMethod (payment_id);


create table Receipt(
description text,
bill_no int,
foreign key (bill_no) references Bill_detail (bill_no)
);

create table Ride_detail(
ride_id int not null ,
bill_no int,
user_id int,
ride_date date not null,
start_time time not null,
end_time time not null,
pickUp varchar(50) not null,
destination varchar(50) not null,
primary key(ride_id)
);
alter table Ride_detail
add foreign key (bill_no) references Bill_detail (bill_no),
add foreign key (user_id) references User (user_id);


create table Feedback(
feedback_id int not null ,
user_id int,
ride_id int,
value int not null,
comment text default null,
date date not null,
primary key(feedback_id)
);
alter table Feedback
add foreign key (user_id) references User (user_id),
add foreign key (ride_id) references Ride_detail (ride_id);


create table CustomerService(
cService_id int not null ,
user_id int,
feedback_id int,
firstName  varchar(25) not null,
lastName varchar(25) not null,
department varchar(20) not null,
email varchar(50) unique,
primary key(cService_id)
);
alter table CustomerService
add foreign key (user_id) references User (user_id),
add foreign key (feedback_id) references Feedback (feedback_id);


create table CustomerService_contact_no(
contact_no int,
Service_id int,
primary key(contact_no),
foreign key (Service_id) references CustomerService (cService_id)
);

INSERT INTO User (user_id, firstName, lastName, city, country, PIN, gender, email)
VALUES
    (1, 'Muhammad', 'Ali', 'Karachi', 'Pakistan', 75000, 'Male', 'muhammad.ali@gmail.com'),
    (2, 'Fatima', 'Khan', 'Lahore', 'Pakistan', 54000, 'Female', 'fatima.khan@gmail.com'),
    (3, 'Ahmed', 'Hussain', 'Islamabad', 'Pakistan', 44000, 'Male', 'ahmed.hussain@gmail.com'),
    (4, 'Aisha', 'Bibi', 'Multan', 'Pakistan', 60000, 'Female', 'aisha.bibi@gmail.com'),
    (5, 'Hamza', 'Ali', 'Peshawar', 'Pakistan', 90000, 'Male', 'hamza.ali@gmail.com');
    
INSERT INTO User_contact_no (contact_no, user_id)
VALUES
    ('03001234567', 1),
    ('03002345678', 2),
    ('03003456789', 3),
    ('03004567890', 4),
    ('03005678901', 5);

INSERT INTO Taxi (taxi_id, user_id, registration_no, make, type, year, status)
VALUES
    (1, 1, 'PK-1234', 'Toyota', 'Corolla', 2018, 'Available'),
    (2, 2, 'PK-5678', 'Honda', 'Civic', 2019, 'Available'),
    (3, 3, 'PK-9012', 'Suzuki', 'Swift', 2020, 'Available'),
    (4, 4, 'PK-3456', 'Hyundai', 'Elantra', 2017, 'Available'),
    (5, 5, 'PK-7890', 'Kia', 'Picanto', 2018, 'Available');
    
INSERT INTO Driver (driver_id, taxi_id, firstName, lastName, gender, experience, city, country, PIN, salary, license_status, working_hours, email)
VALUES
    (1, 1, 'Muhammad', 'Ali', 'Male', 5, 'Karachi', 'Pakistan', 75000, 20000, 'Valid', 8, 'muhammad.ali@gmail.com'),
    (2, 2, 'Fatima', 'Khan', 'Female', 3, 'Lahore', 'Pakistan', 54000, 18000, 'Valid', 8, 'fatima.khan@gmail.com'),
    (3, 3, 'Ahmed', 'Hussain', 'Male', 7, 'Islamabad', 'Pakistan', 44000, 25000, 'Valid', 8, 'ahmed.hussain@gmail.com'),
    (4, 4, 'Aisha', 'Bibi', 'Female', 2, 'Multan', 'Pakistan', 60000, 15000, 'Valid', 8, 'aisha.bibi@gmail.com'),
    (5, 5, 'Hamza', 'Ali', 'Male', 8, 'Peshawar', 'Pakistan', 90000, 30000, 'Valid', 8, 'hamza.ali@gmail.com');
    
INSERT INTO Driver_contact_no (contact_no, driver_id)
VALUES
    ('03001234567', 1),
    ('03002345678', 2),
    ('03003456789', 3),
    ('03004567890', 4),
    ('03005678901', 5);

INSERT INTO Owner (owner_id, taxi_id, firstName, lastName, no_of_taxies)
VALUES
    (1, 1, 'Muhammad', 'Khan', 5),
    (2, 2, 'Fatima', 'Javed', 3),
    (3, 3, 'Ahmed', 'Ali', 7),
    (4, 4, 'Aisha', 'Bibi', 2),
    (5, 5, 'Hamza', 'Khan', 6);
    
INSERT INTO PaymentMethod (payment_id, user_id, name, code, description)
VALUES
    (1, 1, 'Credit Card', 1234567890, 'Visa'),
    (2, 2, 'Debit Card', 6789012, 'Mastercard'),
    (3, 3, 'Online Banking', 11111111, 'Bank of Punjab'),
    (4, 4, 'Mobile Wallet', 55555555, 'Easypaisa'),
    (5, 5, 'Cash', 0894762, 'Cash on Delivery');
    
INSERT INTO Bill_detail (bill_no, user_id, payment_id, discount, advance, bill_date, total_amount)
VALUES
    (1, 1, 1, 0, 500, '2022-01-01', 1000),
    (2, 2, 2, 100, NULL, '2022-01-02', 2000),
    (3, 3, 3, 0, 1000, '2022-01-03', 3000),
    (4, 4, 4, 50, NULL, '2022-01-04', 1500),
    (5, 5, 5, 0, 2000, '2022-01-05', 4000);
INSERT INTO Receipt (description, bill_no)
VALUES
    ('Payment Received for Bill No. 1', 1),
    ('Payment Received for Bill No. 2', 2),
    ('Payment Received for Bill No. 3', 3),
    ('Payment Received for Bill No. 4', 4),
    ('Payment Received for Bill No. 5', 5);
    
INSERT INTO Ride_detail (ride_id, bill_no, user_id, ride_date, start_time, end_time, pickUp, destination)
VALUES
    (1, 1, 1, '2022-01-01', '08:00:00', '10:00:00', 'Karachi Airport', 'Karachi City'),
    (2, 2, 2, '2022-01-02', '09:00:00', '11:00:00', 'Lahore Airport', 'Lahore City'),
    (3, 3, 3, '2022-01-03', '10:00:00', '12:00:00', 'Islamabad Airport', 'Islamabad City'),
    (4, 4, 4, '2022-01-04', '11:00:00', '13:00:00', 'Multan Airport', 'Multan City'),
    (5, 5, 5, '2022-01-05', '12:00:00', '14:00:00', 'Peshawar Airport', 'Peshawar City');

INSERT INTO Feedback (feedback_id, user_id, ride_id, value, comment, date)
VALUES
    (1, 1, 1, 5, 'Excellent service, will definitely use again!', '2022-01-02'),
    (2, 2, 2, 4, 'Good service, but could improve on timekeeping', '2022-01-03'),
    (3, 3, 3, 5, 'Very satisfied with the ride, thank you!', '2022-01-04'),
    (4, 4, 4, 3, 'Service was okay, but not great', '2022-01-05'),
    (5, 5, 5, 5, 'Fantastic ride, highly recommend!', '2022-01-06');
INSERT INTO CustomerService (cService_id, user_id, feedback_id, firstName, lastName, department, email)
VALUES
    (1, 1, 1, 'Hakeem', 'Danish', 'Customer Service', 'hakeem@example.com'),
    (2, 2, 2, 'ch', 'zain', 'Customer Service', 'zain@example.com'),
    (3, 3, 3, 'Ali', 'Khan', 'Customer Service', 'ali.khan@example.com'),
    (4, 4, 4, 'Mohammad', 'Ali', 'Customer Service', 'mohammad.ali@example.com'),
    (5, 5, 5, 'Asif', 'Ahmed', 'Customer Service', 'asif.ahmed@example.com');
INSERT INTO CustomerService_contact_no (contact_no, Service_id)
VALUES
    (12345678, 1),
    (23456789, 2),
    (34567890, 3),
    (45678901, 4),
    (56789012, 5);