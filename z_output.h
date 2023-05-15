#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H
// OUTPUT (test of CTORS, insert & selects):
/*



================================
t1:
       [Last|       [Smith|6]
[Oliver|5]
       [Olajuwon|2 3]
[Horry|0]
       [Fisher|1]
       [Durden|4]

]
[First|       [Tyler|4]
       [Rick|6]
[John|5]
       [Hakeem|2]
[Derek|1]
       [Bob|0]
       [Abdul|3]

]
       [Dept|       [Natural Sciences|6]
       [Math|2 4 5]
[English|3]
       [CS|0 1]

]


============================================================
t2:
       [Last|       [Smith|6]
[Oliver|5]
       [Olajuwon|2 3]
[Horry|0]
       [Fisher|1]
       [Durden|4]

]
[First|       [Tyler|4]
       [Rick|6]
[John|5]
       [Hakeem|2]
[Derek|1]
       [Bob|0]
       [Abdul|3]

]
       [Dept|       [Natural Sciences|6]
       [Math|2 4 5]
[English|3]
       [CS|0 1]

]


============================================================
t2:
       [Last|       [Smith|6]
[Oliver|5]
       [Olajuwon|2 3]
       [Jackman|7]
[Horry|0]
       [Fisher|1]
       [Durden|4]

]
[First|       [Tyler|4]
       [Rick|6]
[John|5]
       [Hugh|7]
       [Hakeem|2]
[Derek|1]
       [Bob|0]
       [Abdul|3]

]
       [Dept|       [Payroll|7]
[Natural Sciences|6]
       [Math|2 4 5]
[English|3]
       [CS|0 1]

]


============================================================
t3:
       [Last|       [Smith|6]
[Oliver|5]
       [Olajuwon|2 3]
       [Jackman|7]
[Horry|0]
       [Fisher|1]
       [Durden|4]

]
[First|       [Tyler|4]
       [Rick|6]
[John|5]
       [Hugh|7]
       [Hakeem|2]
[Derek|1]
       [Bob|0]
       [Abdul|3]

]
       [Dept|       [Payroll|7]
[Natural Sciences|6]
       [Math|2 4 5]
[English|3]
       [CS|0 1]

]


============================================================
t1:
       [Last|       [Smith|6]
[Oliver|5]
       [Olajuwon|2 3]
[Horry|0]
       [Fisher|1]
       [Durden|4]

]
[First|       [Tyler|4]
       [Rick|6]
[John|5]
       [Hakeem|2]
[Derek|1]
       [Bob|0]
       [Abdul|3]

]
       [Dept|       [Natural Sciences|6]
       [Math|2 4 5]
[English|3]
       [CS|0 1]

]

t2:
       [Last|       [Smith|6]
[Oliver|5]
       [Olajuwon|2 3]
       [Jackman|7]
[Horry|0]
       [Fisher|1]
       [Durden|4]

]
[First|       [Tyler|4]
       [Rick|6]
[John|5]
       [Hugh|7]
       [Hakeem|2]
[Derek|1]
       [Bob|0]
       [Abdul|3]

]
       [Dept|       [Payroll|7]
[Natural Sciences|6]
       [Math|2 4 5]
[English|3]
       [CS|0 1]

]

t3:
       [Last|               [Smith|6]
       [Oliver|5]
               [Olajuwon|2 3]
               [Jackman|7]
[Horry|0]
               [Fisher|1]
       [Durden|4]
               [Bowman|8]

]
[First|               [Tyler|4]
       [Rick|6]
               [Ky|8]
[John|5]
               [Hugh|7]
               [Hakeem|2]
       [Derek|1]
               [Bob|0]
               [Abdul|3]

]
       [Dept|       [Payroll|7]
[Natural Sciences|6]
       [Math|2 4 5]
       [Languages|8]
[English|3]
       [CS|0 1]

]


============================================================
t4:
       [Last|       [Oliver|2]
[Olajuwon|0]
       [Durden|1]

]
[First|       [Tyler|1]
[John|2]
       [Hakeem|0]

]
       [Dept|[Math|0 1 2]

]

t5:
[Last|[Horry|0]
[Fisher|1]

]

t6:
[Last|       [Oliver|2]
[Olajuwon|0]
       [Durden|1]

]
[First|       [Tyler|1]
[John|2]
       [Hakeem|0]

]


========================= END TEST =========================



================================
Press <RETURN> to close this window...

 */


// OUTPUT II (parser progress):
/*



================================
Input the command: select Last from school where Dept = Math
Last
Olajuwon
Durden
Oliver

Input the command: quit



================================
Press <RETURN> to close this window...



 */


// OUTPUT III (multiple complex conditions):
/*

> select * from school
==========================================================================================================
|Last                |First               |Dept                |Age                 |State               |
==========================================================================================================
|Horry               |Bob                 |CS                  |22                  |California          |
|Fisher              |Derek               |CS                  |18                  |California          |
|Olajuwon            |Hakeem              |Math                |32                  |Michigan            |
|Olajuwon            |Abdul               |English             |44                  |Louisiana           |
|Durden              |Tyler               |Math                |18                  |New York            |
|Oliver              |John                |Math                |22                  |North Dakota        |
|Smith               |Rick                |Natural Sciences    |52                  |Ohio                |
|Smith               |Steve               |Math                |23                  |Ohio                |
|Smith               |Josh                |Math                |42                  |Michigan            |
|Durden              |Elliot              |CS                  |37                  |Ohio                |
|Kidd                |Josh                |English             |22                  |California          |
==========================================================================================================

> select Age, First, Dept from school where Dept = Math || (Dept = CS && Age = 22)
================================================================
|Age                 |First               |Dept                |
================================================================
|22                  |Bob                 |CS                  |
|32                  |Hakeem              |Math                |
|18                  |Tyler               |Math                |
|22                  |John                |Math                |
|23                  |Steve               |Math                |
|42                  |Josh                |Math                |
================================================================

> Select First, Last from school where Dept = "Natural Sciences"

Command 'Select First, Last from school where Dept = "Natural Sciences"' not found
         ^
> select First, Last from school where Dept = "Natural Sciences"
===========================================
|First               |Last                |
===========================================
|Rick                |Smith               |
===========================================

> select Age, First, Dept from school where Dept = Math && (Dept = CS && Age = 22)
================================================================
|Age                 |First               |Dept                |
================================================================
|                           EMPTY                              |
================================================================

> select Age, First, Dept from school where ((State = Ohio) || Dept = CS && Age = 22) || State = "North Dakota"
================================================================
|Age                 |First               |Dept                |
================================================================
|22                  |Bob                 |CS                  |
|22                  |John                |Math                |
================================================================

> slect

Command 'slect ' not found
         ^
> select * frmmm

Command 'select * frmmm' not found
                  ^
> select * from school where Age = 22
==========================================================================================================
|Last                |First               |Dept                |Age                 |State               |
==========================================================================================================
|Horry               |Bob                 |CS                  |22                  |California          |
|Oliver              |John                |Math                |22                  |North Dakota        |
|Kidd                |Josh                |English             |22                  |California          |
==========================================================================================================

> quit
Press <RETURN> to close this window...
 */


// OUTPUT IV (SQL SAMPLE RUN):
/*

------ Currently Managed SQL Tables: ------
-------------------------------------------
> batch "_!sampl3"
[0]: batch "_!sampl3"
//****************************************************************************
//              CREATE AND INSERT
//****************************************************************************
//---- employee table ----------
[1]: make table employee fields  last,          first,                  dep

------ Currently Managed SQL Tables: ------
employee
-------------------------------------------

[2]: insert into employee values Blow,          Joe,                    CS
[3]: insert into employee values Johnson,       "Jimmy",                Chemistry
[4]: insert into employee values Yang,          Bo,                     CS
[5]: insert into employee values "Jackson",     Billy,                  Math
[6]: insert into employee values Johnson,       Billy,                  "Phys Ed"
[7]: insert into employee values "Van Gogh",    "Jim Bob",              "Phys Ed"
[8]: select * from employee
======================================================================
| #   |last                |first               |dep                 |
======================================================================
| 0   |Blow                |Joe                 |CS                  |
| 1   |Johnson             |Jimmy               |Chemistry           |
| 2   |Yang                |Bo                  |CS                  |
| 3   |Jackson             |Billy               |Math                |
| 4   |Johnson             |Billy               |Phys Ed             |
| 5   |Van Gogh            |Jim Bob             |Phys Ed             |
======================================================================

//----- student table ----------
[9]: make table student fields  fname,                  lname,          major,                          age

------ Currently Managed SQL Tables: ------
employee
student
-------------------------------------------

[10]: insert into student values        Flo,                    Yao,            CS,                             20
[11]: insert into student values        "Flo",                  "Jackson",      Math,                           21
[12]: insert into student values        Calvin,                 Woo,            Physics,                        22
[13]: insert into student values        "Anna Grace",   "Del Rio",      CS,                                     22
[14]: select * from student
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |
| 1   |Flo                 |Jackson             |Math                |21                  |
| 2   |Calvin              |Woo                 |Physics             |22                  |
| 3   |Anna Grace          |Del Rio             |CS                  |22                  |
===========================================================================================

//****************************************************************************
//              SIMPLE SELECT
//****************************************************************************
[15]: select * from student
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |
| 1   |Flo                 |Jackson             |Math                |21                  |
| 2   |Calvin              |Woo                 |Physics             |22                  |
| 3   |Anna Grace          |Del Rio             |CS                  |22                  |
===========================================================================================

//------- simple strings -------------------
[16]: select * from student where lname = Jackson
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
| 0   |Flo                 |Jackson             |Math                |21                  |
===========================================================================================

//----- quoted strings ---------------------
[17]: select * from student where lname = "Del Rio"
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
| 0   |Anna Grace          |Del Rio             |CS                  |22                  |
===========================================================================================

//-------- non-existing string ------------------
[18]: select * from student where lname = "Does Not Exist"
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
|                                        EMPTY                                            |
===========================================================================================

//****************************************************************************
//              RELATIONAL OPERATORS:
//****************************************************************************
//.................
//:Greater Than   :
//.................
[19]: select * from student where lname > Yang
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |
===========================================================================================

//. . . . . . . . . . . . . (Greater Than: Non-existing) . . . . . . . . . . . . . . . . . . . . .
[20]: select * from student where age > 50
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
|                                        EMPTY                                            |
===========================================================================================

//. . . . . . . . . . . . . (Greater than: last item) . . . . . . . . . . . . . . . . . .
[21]: select * from student where age  > 53
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
|                                        EMPTY                                            |
===========================================================================================

//. . . . . . . . . . . . . (Greater Than: Passed last item) . . . . . . . . . . . . . . . . . . . . .
[22]: select * from student where age > 54
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
|                                        EMPTY                                            |
===========================================================================================

//.................
//:Greater Equal  :
//.................
[23]: select * from student where lname >= Yang
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |
===========================================================================================

//. . . . . .  (Greater Equal non-existing: ) . . . . . . . . . . .
[24]: select * from employee where last >= Jack
======================================================================
| #   |last                |first               |dep                 |
======================================================================
| 0   |Jackson             |Billy               |Math                |
| 1   |Johnson             |Jimmy               |Chemistry           |
| 2   |Johnson             |Billy               |Phys Ed             |
| 3   |Van Gogh            |Jim Bob             |Phys Ed             |
| 4   |Yang                |Bo                  |CS                  |
======================================================================

//.................
//:Less Than      :
//.................
//. . . . . . . . . . . . . (Less Than: Non-existing) . . . . . . . . . . . . . . . . . . . . .
[25]: select * from student where lname < Jackson
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
| 0   |Anna Grace          |Del Rio             |CS                  |22                  |
===========================================================================================

//. . . . . . . . . . . . . (Less than: first item) . . . . . . . . . . . . . . . . . .
[26]: select * from student where age  < 20
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
|                                        EMPTY                                            |
===========================================================================================

//. . . . . . . . . . . . . (Less Than: before first item) . . . . . . . . . . . . . . . . . . . . .
[27]: select * from student where age  < 19
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
|                                        EMPTY                                            |
===========================================================================================

//.................
//:Less Equal     :
//.................
[28]: select * from student where lname <= Smith
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
| 0   |Anna Grace          |Del Rio             |CS                  |22                  |
| 1   |Flo                 |Jackson             |Math                |21                  |
===========================================================================================

//. . . . . .  (Less Equal non-existing: ) . . . . . . . . . . .
[29]: select * from employee where last <= Peach
======================================================================
| #   |last                |first               |dep                 |
======================================================================
| 0   |Blow                |Joe                 |CS                  |
| 1   |Jackson             |Billy               |Math                |
| 2   |Johnson             |Jimmy               |Chemistry           |
| 3   |Johnson             |Billy               |Phys Ed             |
======================================================================

//****************************************************************************
//              LOGICAL OPERATORS
//****************************************************************************
//.................
//:AND            :
//.................
[30]: select * from student where fname = "Flo" and lname = "Yao"
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |
===========================================================================================

//.................
//:OR            :
//.................
[31]: select * from student where fname = Flo or lname = Jackson
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |
| 1   |Flo                 |Jackson             |Math                |21                  |
===========================================================================================

//.................
//:OR AND         :
//.................
[32]: select * from student where fname = Flo or major = CS and age <= 23
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |
| 1   |Flo                 |Jackson             |Math                |21                  |
| 2   |Anna Grace          |Del Rio             |CS                  |22                  |
===========================================================================================

//.................
//:AND OR AND     :
//.................
[33]: select * from student where age <30 and major=CS or major = Physics and lname = Jackson
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |
| 1   |Anna Grace          |Del Rio             |CS                  |22                  |
===========================================================================================

//.................
//:OR AND OR      :
//.................
[34]: select * from student where lname = Yang or major = CS and age < 23 or lname = Jackson
===========================================================================================
| #   |fname               |lname               |major               |age                 |
===========================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |
| 1   |Flo                 |Jackson             |Math                |21                  |
| 2   |Anna Grace          |Del Rio             |CS                  |22                  |
===========================================================================================

> quit
Press <RETURN> to close this window...

 */


// OUTPUT V (Final SQL BATCH RUN):
/*

------ Currently Managed SQL Tables: ------
-------------------------------------------
> batch "_!select"
[0]: batch "_!select"
//****************************************************************************
//              CREATE TABLES AND INSERT RECORDS
//****************************************************************************
[1]: make table employee fields  last,          first,                  dep,            salary,         year

------ Currently Managed SQL Tables: ------
employee
-------------------------------------------

[2]: insert into employee values Blow,          Joe,                    CS,                     100000,         2018
[3]: insert into employee values Blow,          JoAnn,                  Physics,        200000,         2016
[4]: insert into employee values Johnson,       Jack,                   HR,             150000,         2014
[5]: insert into employee values Johnson,       "Jimmy",                Chemistry,      140000,         2018
[6]: insert into employee values Yao,           Jimmy,                  Math,           145000,         2014
[7]: insert into employee values "Yao",                 Flo,                    CS,                     147000,         2012
[8]: insert into employee values Yang,          Bo,                     CS,                     160000,         2013
[9]: insert into employee values Jackson,       "Flo",                  Math,           165000,         2017
[10]: insert into employee values Jackson,      Bo,                             Chemistry,      130000,         2011
[11]: insert into employee values "Jackson",    Billy,                  Math,           170000,         2017
[12]: insert into employee values Johnson,      "Mary Ann",     Math,           165000,         2014
[13]: insert into employee values Johnson,      "Billy Bob",    Physics,        142000,         2014
[14]: insert into employee values Johnson,      Billy,                  "Phys Ed",      102000,         2014
[15]: insert into employee values "Van Gogh",   Vincent,                Art,            240000,         2015
[16]: insert into employee values "Van Gogh",   Vincent,                CS,                     245000,         2015
[17]: insert into employee values "Van Gogh",   "Jim Bob",              "Phys Ed",      230000,         2010
[18]: select * from employee
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Blow                |Joe                 |CS                  |100000              |2018                |
| 1   |Blow                |JoAnn               |Physics             |200000              |2016                |
| 2   |Johnson             |Jack                |HR                  |150000              |2014                |
| 3   |Johnson             |Jimmy               |Chemistry           |140000              |2018                |
| 4   |Yao                 |Jimmy               |Math                |145000              |2014                |
| 5   |Yao                 |Flo                 |CS                  |147000              |2012                |
| 6   |Yang                |Bo                  |CS                  |160000              |2013                |
| 7   |Jackson             |Flo                 |Math                |165000              |2017                |
| 8   |Jackson             |Bo                  |Chemistry           |130000              |2011                |
| 9   |Jackson             |Billy               |Math                |170000              |2017                |
| 10  |Johnson             |Mary Ann            |Math                |165000              |2014                |
| 11  |Johnson             |Billy Bob           |Physics             |142000              |2014                |
| 12  |Johnson             |Billy               |Phys Ed             |102000              |2014                |
| 13  |Van Gogh            |Vincent             |Art                 |240000              |2015                |
| 14  |Van Gogh            |Vincent             |CS                  |245000              |2015                |
| 15  |Van Gogh            |Jim Bob             |Phys Ed             |230000              |2010                |
================================================================================================================

[19]: make table student fields fname, lname, major, age, company

------ Currently Managed SQL Tables: ------
employee
student
-------------------------------------------

[20]: insert into student values Flo,                   Yao,            CS,                             20,     Google
[21]: insert into student values Bo,                            Yang,           CS,                             28,             Microsoft
[22]: insert into student values "Sammuel L.",  Jackson,        CS,                             40,             Uber
[23]: insert into student values "Flo",                         "Jackson",      Math,                           21,             Google
[24]: insert into student values "Greg",                        "Pearson",      Physics,                        20,             Amazon
[25]: insert into student values "Jim Bob",             Smith,          Math,                           23,             Verizon
[26]: insert into student values Calvin,                        Woo,            Physics,                        22,             Uber
[27]: insert into student values "Anna Grace",  "Del Rio",      CS,                                     22,             USAF
[28]: insert into student values "Teresa Mae",  Gowers,         Chemistry,                      22,             Verizon
[29]: insert into student values Alex,                  Smith,          "Gender Studies",       53,             Amazon
[30]: select * from student
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |Google              |
| 1   |Bo                  |Yang                |CS                  |28                  |Microsoft           |
| 2   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 3   |Flo                 |Jackson             |Math                |21                  |Google              |
| 4   |Greg                |Pearson             |Physics             |20                  |Amazon              |
| 5   |Jim Bob             |Smith               |Math                |23                  |Verizon             |
| 6   |Calvin              |Woo                 |Physics             |22                  |Uber                |
| 7   |Anna Grace          |Del Rio             |CS                  |22                  |USAF                |
| 8   |Teresa Mae          |Gowers              |Chemistry           |22                  |Verizon             |
| 9   |Alex                |Smith               |Gender Studies      |53                  |Amazon              |
================================================================================================================

//****************************************************************************
//              SIMPLE SELECT:
//****************************************************************************
[31]: select * from student
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |Google              |
| 1   |Bo                  |Yang                |CS                  |28                  |Microsoft           |
| 2   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 3   |Flo                 |Jackson             |Math                |21                  |Google              |
| 4   |Greg                |Pearson             |Physics             |20                  |Amazon              |
| 5   |Jim Bob             |Smith               |Math                |23                  |Verizon             |
| 6   |Calvin              |Woo                 |Physics             |22                  |Uber                |
| 7   |Anna Grace          |Del Rio             |CS                  |22                  |USAF                |
| 8   |Teresa Mae          |Gowers              |Chemistry           |22                  |Verizon             |
| 9   |Alex                |Smith               |Gender Studies      |53                  |Amazon              |
================================================================================================================

//------- simple strings -------------------
[32]: select * from student where lname = Jackson
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 1   |Flo                 |Jackson             |Math                |21                  |Google              |
================================================================================================================

[33]: select * from student where major = CS
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |Google              |
| 1   |Bo                  |Yang                |CS                  |28                  |Microsoft           |
| 2   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 3   |Anna Grace          |Del Rio             |CS                  |22                  |USAF                |
================================================================================================================

[34]: select * from student where company = Uber
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 1   |Calvin              |Woo                 |Physics             |22                  |Uber                |
================================================================================================================

//----- quoted strings ---------------------
[35]: select * from student where lname = "Del Rio"
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Anna Grace          |Del Rio             |CS                  |22                  |USAF                |
================================================================================================================

[36]: select * from student where fname = "Jim Bob"
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Jim Bob             |Smith               |Math                |23                  |Verizon             |
================================================================================================================

[37]: select * from student where fname = "Anna Grace"
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Anna Grace          |Del Rio             |CS                  |22                  |USAF                |
================================================================================================================

[38]: select * from student where fname = "Teresa Mae"
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Teresa Mae          |Gowers              |Chemistry           |22                  |Verizon             |
================================================================================================================

//-------- non-existing string ------------------
[39]: select * from student where lname = "Does Not Exist"
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

//****************************************************************************
//              RELATIONAL OPERATORS:
//****************************************************************************
//.................
//:Greater Than   :
//.................
[40]: select * from student where lname > Yang
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |Google              |
================================================================================================================

[41]: select * from student where major > Math
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Greg                |Pearson             |Physics             |20                  |Amazon              |
| 1   |Calvin              |Woo                 |Physics             |22                  |Uber                |
================================================================================================================

[42]: select * from student where fname > "Sammuel L."
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Teresa Mae          |Gowers              |Chemistry           |22                  |Verizon             |
================================================================================================================

[43]: select * from employee where salary > 200000
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Van Gogh            |Jim Bob             |Phys Ed             |230000              |2010                |
| 1   |Van Gogh            |Vincent             |Art                 |240000              |2015                |
| 2   |Van Gogh            |Vincent             |CS                  |245000              |2015                |
================================================================================================================

[44]: select * from employee where dep > Chemistry
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Johnson             |Jack                |HR                  |150000              |2014                |
| 1   |Yao                 |Jimmy               |Math                |145000              |2014                |
| 2   |Jackson             |Flo                 |Math                |165000              |2017                |
| 3   |Jackson             |Billy               |Math                |170000              |2017                |
| 4   |Johnson             |Mary Ann            |Math                |165000              |2014                |
| 5   |Johnson             |Billy               |Phys Ed             |102000              |2014                |
| 6   |Van Gogh            |Jim Bob             |Phys Ed             |230000              |2010                |
| 7   |Blow                |JoAnn               |Physics             |200000              |2016                |
| 8   |Johnson             |Billy Bob           |Physics             |142000              |2014                |
================================================================================================================

[45]: select * from employee where last > Jackson
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Johnson             |Jack                |HR                  |150000              |2014                |
| 1   |Johnson             |Jimmy               |Chemistry           |140000              |2018                |
| 2   |Johnson             |Mary Ann            |Math                |165000              |2014                |
| 3   |Johnson             |Billy Bob           |Physics             |142000              |2014                |
| 4   |Johnson             |Billy               |Phys Ed             |102000              |2014                |
| 5   |Van Gogh            |Vincent             |Art                 |240000              |2015                |
| 6   |Van Gogh            |Vincent             |CS                  |245000              |2015                |
| 7   |Van Gogh            |Jim Bob             |Phys Ed             |230000              |2010                |
| 8   |Yang                |Bo                  |CS                  |160000              |2013                |
| 9   |Yao                 |Jimmy               |Math                |145000              |2014                |
| 10  |Yao                 |Flo                 |CS                  |147000              |2012                |
================================================================================================================

[46]: select * from employee where first > "Billy Bob"
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Yang                |Bo                  |CS                  |160000              |2013                |
| 1   |Jackson             |Bo                  |Chemistry           |130000              |2011                |
| 2   |Yao                 |Flo                 |CS                  |147000              |2012                |
| 3   |Jackson             |Flo                 |Math                |165000              |2017                |
| 4   |Johnson             |Jack                |HR                  |150000              |2014                |
| 5   |Van Gogh            |Jim Bob             |Phys Ed             |230000              |2010                |
| 6   |Johnson             |Jimmy               |Chemistry           |140000              |2018                |
| 7   |Yao                 |Jimmy               |Math                |145000              |2014                |
| 8   |Blow                |JoAnn               |Physics             |200000              |2016                |
| 9   |Blow                |Joe                 |CS                  |100000              |2018                |
| 10  |Johnson             |Mary Ann            |Math                |165000              |2014                |
| 11  |Van Gogh            |Vincent             |Art                 |240000              |2015                |
| 12  |Van Gogh            |Vincent             |CS                  |245000              |2015                |
================================================================================================================

//. . . . . . . . . . . . . (Greater Than: Non-existing) . . . . . . . . . . . . . . . . . . . . .
[47]: select * from student where age > 50
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Alex                |Smith               |Gender Studies      |53                  |Amazon              |
================================================================================================================

[48]: select * from student where age > 35
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 1   |Alex                |Smith               |Gender Studies      |53                  |Amazon              |
================================================================================================================

[49]: select * from student where fname > T
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Teresa Mae          |Gowers              |Chemistry           |22                  |Verizon             |
================================================================================================================

[50]: select * from employee where salary > 130000
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Johnson             |Jimmy               |Chemistry           |140000              |2018                |
| 1   |Johnson             |Billy Bob           |Physics             |142000              |2014                |
| 2   |Yao                 |Jimmy               |Math                |145000              |2014                |
| 3   |Yao                 |Flo                 |CS                  |147000              |2012                |
| 4   |Johnson             |Jack                |HR                  |150000              |2014                |
| 5   |Yang                |Bo                  |CS                  |160000              |2013                |
| 6   |Jackson             |Flo                 |Math                |165000              |2017                |
| 7   |Johnson             |Mary Ann            |Math                |165000              |2014                |
| 8   |Jackson             |Billy               |Math                |170000              |2017                |
| 9   |Blow                |JoAnn               |Physics             |200000              |2016                |
| 10  |Van Gogh            |Jim Bob             |Phys Ed             |230000              |2010                |
| 11  |Van Gogh            |Vincent             |Art                 |240000              |2015                |
| 12  |Van Gogh            |Vincent             |CS                  |245000              |2015                |
================================================================================================================

[51]: select * from employee where  year > 2009
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Van Gogh            |Jim Bob             |Phys Ed             |230000              |2010                |
| 1   |Jackson             |Bo                  |Chemistry           |130000              |2011                |
| 2   |Yao                 |Flo                 |CS                  |147000              |2012                |
| 3   |Yang                |Bo                  |CS                  |160000              |2013                |
| 4   |Johnson             |Jack                |HR                  |150000              |2014                |
| 5   |Yao                 |Jimmy               |Math                |145000              |2014                |
| 6   |Johnson             |Mary Ann            |Math                |165000              |2014                |
| 7   |Johnson             |Billy Bob           |Physics             |142000              |2014                |
| 8   |Johnson             |Billy               |Phys Ed             |102000              |2014                |
| 9   |Van Gogh            |Vincent             |Art                 |240000              |2015                |
| 10  |Van Gogh            |Vincent             |CS                  |245000              |2015                |
| 11  |Blow                |JoAnn               |Physics             |200000              |2016                |
| 12  |Jackson             |Flo                 |Math                |165000              |2017                |
| 13  |Jackson             |Billy               |Math                |170000              |2017                |
| 14  |Blow                |Joe                 |CS                  |100000              |2018                |
| 15  |Johnson             |Jimmy               |Chemistry           |140000              |2018                |
================================================================================================================

//. . . . . . . . . . . . . (Greater than: last item) . . . . . . . . . . . . . . . . . .
[52]: select * from student where age  > 53
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[53]: select * from student where lname > Yao
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[54]: select * from student where fname > "Teresa Mae"
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[55]: select * from employee where last > "Van Gogh"
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Yang                |Bo                  |CS                  |160000              |2013                |
| 1   |Yao                 |Jimmy               |Math                |145000              |2014                |
| 2   |Yao                 |Flo                 |CS                  |147000              |2012                |
================================================================================================================

[56]: select * from employee where first > Vincent
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[57]: select * from employee where salary > 260000
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

//. . . . . . . . . . . . . (Greater Than: Passed last item) . . . . . . . . . . . . . . . . . . . . .
[58]: select * from student where age > 54
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[59]: select * from student where lname > Zoolander
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[60]: select * from employee where last > Zoolaner
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[61]: select * from employee where first > Xu
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

//.................
//:Greater Equal  :
//.................
[62]: select * from student where lname >= Yang
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Bo                  |Yang                |CS                  |28                  |Microsoft           |
| 1   |Flo                 |Yao                 |CS                  |20                  |Google              |
================================================================================================================

[63]: select * from student where fname >= "Sammuel L."
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 1   |Teresa Mae          |Gowers              |Chemistry           |22                  |Verizon             |
================================================================================================================

[64]: select * from student where age >= 40
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 1   |Alex                |Smith               |Gender Studies      |53                  |Amazon              |
================================================================================================================

//. . . . . .  (Greater Equal non-existing: ) . . . . . . . . . . .
[65]: select * from employee where last >= Jack
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Jackson             |Flo                 |Math                |165000              |2017                |
| 1   |Jackson             |Bo                  |Chemistry           |130000              |2011                |
| 2   |Jackson             |Billy               |Math                |170000              |2017                |
| 3   |Johnson             |Jack                |HR                  |150000              |2014                |
| 4   |Johnson             |Jimmy               |Chemistry           |140000              |2018                |
| 5   |Johnson             |Mary Ann            |Math                |165000              |2014                |
| 6   |Johnson             |Billy Bob           |Physics             |142000              |2014                |
| 7   |Johnson             |Billy               |Phys Ed             |102000              |2014                |
| 8   |Van Gogh            |Vincent             |Art                 |240000              |2015                |
| 9   |Van Gogh            |Vincent             |CS                  |245000              |2015                |
| 10  |Van Gogh            |Jim Bob             |Phys Ed             |230000              |2010                |
| 11  |Yang                |Bo                  |CS                  |160000              |2013                |
| 12  |Yao                 |Jimmy               |Math                |145000              |2014                |
| 13  |Yao                 |Flo                 |CS                  |147000              |2012                |
================================================================================================================

[66]: select * from employee where first >= Bill
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Jackson             |Billy               |Math                |170000              |2017                |
| 1   |Johnson             |Billy               |Phys Ed             |102000              |2014                |
| 2   |Johnson             |Billy Bob           |Physics             |142000              |2014                |
| 3   |Yang                |Bo                  |CS                  |160000              |2013                |
| 4   |Jackson             |Bo                  |Chemistry           |130000              |2011                |
| 5   |Yao                 |Flo                 |CS                  |147000              |2012                |
| 6   |Jackson             |Flo                 |Math                |165000              |2017                |
| 7   |Johnson             |Jack                |HR                  |150000              |2014                |
| 8   |Van Gogh            |Jim Bob             |Phys Ed             |230000              |2010                |
| 9   |Johnson             |Jimmy               |Chemistry           |140000              |2018                |
| 10  |Yao                 |Jimmy               |Math                |145000              |2014                |
| 11  |Blow                |JoAnn               |Physics             |200000              |2016                |
| 12  |Blow                |Joe                 |CS                  |100000              |2018                |
| 13  |Johnson             |Mary Ann            |Math                |165000              |2014                |
| 14  |Van Gogh            |Vincent             |Art                 |240000              |2015                |
| 15  |Van Gogh            |Vincent             |CS                  |245000              |2015                |
================================================================================================================

[67]: select * from employee where salary >= 235000
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Van Gogh            |Vincent             |Art                 |240000              |2015                |
| 1   |Van Gogh            |Vincent             |CS                  |245000              |2015                |
================================================================================================================

//.................
//:Less Than      :
//.................
//. . . . . . . . . . . . . (Less Than: Non-existing) . . . . . . . . . . . . . . . . . . . . .
[68]: select * from student where lname < Jackson
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Anna Grace          |Del Rio             |CS                  |22                  |USAF                |
| 1   |Teresa Mae          |Gowers              |Chemistry           |22                  |Verizon             |
================================================================================================================

[69]: select * from student where major < Math
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |Google              |
| 1   |Bo                  |Yang                |CS                  |28                  |Microsoft           |
| 2   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 3   |Anna Grace          |Del Rio             |CS                  |22                  |USAF                |
| 4   |Teresa Mae          |Gowers              |Chemistry           |22                  |Verizon             |
| 5   |Alex                |Smith               |Gender Studies      |53                  |Amazon              |
================================================================================================================

[70]: select * from student where fname < "Jim Bob"
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Alex                |Smith               |Gender Studies      |53                  |Amazon              |
| 1   |Anna Grace          |Del Rio             |CS                  |22                  |USAF                |
| 2   |Bo                  |Yang                |CS                  |28                  |Microsoft           |
| 3   |Calvin              |Woo                 |Physics             |22                  |Uber                |
| 4   |Flo                 |Yao                 |CS                  |20                  |Google              |
| 5   |Flo                 |Jackson             |Math                |21                  |Google              |
| 6   |Greg                |Pearson             |Physics             |20                  |Amazon              |
================================================================================================================

[71]: select * from employee where salary < 200000
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Blow                |Joe                 |CS                  |100000              |2018                |
| 1   |Johnson             |Billy               |Phys Ed             |102000              |2014                |
| 2   |Jackson             |Bo                  |Chemistry           |130000              |2011                |
| 3   |Johnson             |Jimmy               |Chemistry           |140000              |2018                |
| 4   |Johnson             |Billy Bob           |Physics             |142000              |2014                |
| 5   |Yao                 |Jimmy               |Math                |145000              |2014                |
| 6   |Yao                 |Flo                 |CS                  |147000              |2012                |
| 7   |Johnson             |Jack                |HR                  |150000              |2014                |
| 8   |Yang                |Bo                  |CS                  |160000              |2013                |
| 9   |Jackson             |Flo                 |Math                |165000              |2017                |
| 10  |Johnson             |Mary Ann            |Math                |165000              |2014                |
| 11  |Jackson             |Billy               |Math                |170000              |2017                |
================================================================================================================

[72]: select * from employee where dep < CS
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Van Gogh            |Vincent             |Art                 |240000              |2015                |
================================================================================================================

[73]: select * from employee where last < Jackson
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Blow                |Joe                 |CS                  |100000              |2018                |
| 1   |Blow                |JoAnn               |Physics             |200000              |2016                |
================================================================================================================

[74]: select * from employee where first < "Billy Bob"
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Jackson             |Billy               |Math                |170000              |2017                |
| 1   |Johnson             |Billy               |Phys Ed             |102000              |2014                |
================================================================================================================

//. . . . . . . . . . . . . (Less than: first item) . . . . . . . . . . . . . . . . . .
[75]: select * from student where age  < 20
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[76]: select * from student where lname < "Del Rio"
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[77]: select * from student where fname < Alex
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[78]: select * from employee where last < Blow
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[79]: select * from employee where first < Billy
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[80]: select * from employee where salary < 100000
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

//. . . . . . . . . . . . . (Less Than: before first item) . . . . . . . . . . . . . . . . . . . . .
[81]: select * from student where age  < 19
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[82]: select * from student where lname < Adams
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[83]: select * from student where fname < Adam
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[84]: select * from employee where last < Alex
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[85]: select * from employee where first < Avory
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

[86]: select * from employee where dep < Alchemy
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
|                                                   EMPTY                                                      |
================================================================================================================

//.................
//:Less Equal     :
//.................
[87]: select * from student where lname <= Smith
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Anna Grace          |Del Rio             |CS                  |22                  |USAF                |
| 1   |Teresa Mae          |Gowers              |Chemistry           |22                  |Verizon             |
| 2   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 3   |Flo                 |Jackson             |Math                |21                  |Google              |
| 4   |Greg                |Pearson             |Physics             |20                  |Amazon              |
| 5   |Jim Bob             |Smith               |Math                |23                  |Verizon             |
| 6   |Alex                |Smith               |Gender Studies      |53                  |Amazon              |
================================================================================================================

[88]: select * from student where fname <= Greg
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Alex                |Smith               |Gender Studies      |53                  |Amazon              |
| 1   |Anna Grace          |Del Rio             |CS                  |22                  |USAF                |
| 2   |Bo                  |Yang                |CS                  |28                  |Microsoft           |
| 3   |Calvin              |Woo                 |Physics             |22                  |Uber                |
| 4   |Flo                 |Yao                 |CS                  |20                  |Google              |
| 5   |Flo                 |Jackson             |Math                |21                  |Google              |
| 6   |Greg                |Pearson             |Physics             |20                  |Amazon              |
================================================================================================================

[89]: select * from student where age <= 40
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |Google              |
| 1   |Greg                |Pearson             |Physics             |20                  |Amazon              |
| 2   |Flo                 |Jackson             |Math                |21                  |Google              |
| 3   |Calvin              |Woo                 |Physics             |22                  |Uber                |
| 4   |Anna Grace          |Del Rio             |CS                  |22                  |USAF                |
| 5   |Teresa Mae          |Gowers              |Chemistry           |22                  |Verizon             |
| 6   |Jim Bob             |Smith               |Math                |23                  |Verizon             |
| 7   |Bo                  |Yang                |CS                  |28                  |Microsoft           |
| 8   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
================================================================================================================

//. . . . . .  (Less Equal non-existing: ) . . . . . . . . . . .
[90]: select * from employee where last <= Peach
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Blow                |Joe                 |CS                  |100000              |2018                |
| 1   |Blow                |JoAnn               |Physics             |200000              |2016                |
| 2   |Jackson             |Flo                 |Math                |165000              |2017                |
| 3   |Jackson             |Bo                  |Chemistry           |130000              |2011                |
| 4   |Jackson             |Billy               |Math                |170000              |2017                |
| 5   |Johnson             |Jack                |HR                  |150000              |2014                |
| 6   |Johnson             |Jimmy               |Chemistry           |140000              |2018                |
| 7   |Johnson             |Mary Ann            |Math                |165000              |2014                |
| 8   |Johnson             |Billy Bob           |Physics             |142000              |2014                |
| 9   |Johnson             |Billy               |Phys Ed             |102000              |2014                |
================================================================================================================

[91]: select * from employee where first <= Gary
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Jackson             |Billy               |Math                |170000              |2017                |
| 1   |Johnson             |Billy               |Phys Ed             |102000              |2014                |
| 2   |Johnson             |Billy Bob           |Physics             |142000              |2014                |
| 3   |Yang                |Bo                  |CS                  |160000              |2013                |
| 4   |Jackson             |Bo                  |Chemistry           |130000              |2011                |
| 5   |Yao                 |Flo                 |CS                  |147000              |2012                |
| 6   |Jackson             |Flo                 |Math                |165000              |2017                |
================================================================================================================

[92]: select * from employee where salary <= 23500
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Blow                |Joe                 |CS                  |100000              |2018                |
| 1   |Johnson             |Billy               |Phys Ed             |102000              |2014                |
| 2   |Jackson             |Bo                  |Chemistry           |130000              |2011                |
| 3   |Johnson             |Jimmy               |Chemistry           |140000              |2018                |
| 4   |Johnson             |Billy Bob           |Physics             |142000              |2014                |
| 5   |Yao                 |Jimmy               |Math                |145000              |2014                |
| 6   |Yao                 |Flo                 |CS                  |147000              |2012                |
| 7   |Johnson             |Jack                |HR                  |150000              |2014                |
| 8   |Yang                |Bo                  |CS                  |160000              |2013                |
| 9   |Jackson             |Flo                 |Math                |165000              |2017                |
| 10  |Johnson             |Mary Ann            |Math                |165000              |2014                |
| 11  |Jackson             |Billy               |Math                |170000              |2017                |
| 12  |Blow                |JoAnn               |Physics             |200000              |2016                |
| 13  |Van Gogh            |Jim Bob             |Phys Ed             |230000              |2010                |
================================================================================================================

//****************************************************************************
//              LOGICAL OPERATORS
//****************************************************************************
//.................
//:AND            :
//.................
[93]: select * from student where fname = "Flo" and lname = "Yao"
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |Google              |
================================================================================================================

[94]: select * from student where major = "CS" and age < 25
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |Google              |
| 1   |Anna Grace          |Del Rio             |CS                  |22                  |USAF                |
================================================================================================================

[95]: select * from student where major < Math and age > 25
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Bo                  |Yang                |CS                  |28                  |Microsoft           |
| 1   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 2   |Alex                |Smith               |Gender Studies      |53                  |Amazon              |
================================================================================================================

[96]: select * from employee where dep = CS and salary > 150000
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Yang                |Bo                  |CS                  |160000              |2013                |
| 1   |Van Gogh            |Vincent             |CS                  |245000              |2015                |
================================================================================================================

[97]: select * from employee where last = Jackson and year < 2015
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Jackson             |Bo                  |Chemistry           |130000              |2011                |
================================================================================================================

[98]: select * from employee where last = Johnson and year >=2014
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Johnson             |Jack                |HR                  |150000              |2014                |
| 1   |Johnson             |Jimmy               |Chemistry           |140000              |2018                |
| 2   |Johnson             |Mary Ann            |Math                |165000              |2014                |
| 3   |Johnson             |Billy Bob           |Physics             |142000              |2014                |
| 4   |Johnson             |Billy               |Phys Ed             |102000              |2014                |
================================================================================================================

//.................
//:OR            :
//.................
[99]: select * from student where fname = Flo or lname = Jackson
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |Google              |
| 1   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 2   |Flo                 |Jackson             |Math                |21                  |Google              |
================================================================================================================

[100]: select * from student where age >=40  or company = Verizon
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 1   |Jim Bob             |Smith               |Math                |23                  |Verizon             |
| 2   |Teresa Mae          |Gowers              |Chemistry           |22                  |Verizon             |
| 3   |Alex                |Smith               |Gender Studies      |53                  |Amazon              |
================================================================================================================

[101]: select * from employee where first = Bo or last = Johnson
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Johnson             |Jack                |HR                  |150000              |2014                |
| 1   |Johnson             |Jimmy               |Chemistry           |140000              |2018                |
| 2   |Yang                |Bo                  |CS                  |160000              |2013                |
| 3   |Jackson             |Bo                  |Chemistry           |130000              |2011                |
| 4   |Johnson             |Mary Ann            |Math                |165000              |2014                |
| 5   |Johnson             |Billy Bob           |Physics             |142000              |2014                |
| 6   |Johnson             |Billy               |Phys Ed             |102000              |2014                |
================================================================================================================

[102]: select * from employee where year >= 2015 or dep = CS
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Blow                |Joe                 |CS                  |100000              |2018                |
| 1   |Yao                 |Flo                 |CS                  |147000              |2012                |
| 2   |Yang                |Bo                  |CS                  |160000              |2013                |
| 3   |Van Gogh            |Vincent             |Art                 |240000              |2015                |
| 4   |Van Gogh            |Vincent             |CS                  |245000              |2015                |
| 5   |Blow                |JoAnn               |Physics             |200000              |2016                |
| 6   |Jackson             |Flo                 |Math                |165000              |2017                |
| 7   |Jackson             |Billy               |Math                |170000              |2017                |
| 8   |Blow                |Joe                 |CS                  |100000              |2018                |
| 9   |Johnson             |Jimmy               |Chemistry           |140000              |2018                |
================================================================================================================

//.................
//:OR AND         :
//.................
[103]: select * from student where fname = Flo or major = CS and age <= 23
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |Google              |
| 1   |Flo                 |Jackson             |Math                |21                  |Google              |
| 2   |Anna Grace          |Del Rio             |CS                  |22                  |USAF                |
================================================================================================================

[104]: select * from student where lname = Jackson or age < 23 and company > Uber
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 1   |Flo                 |Jackson             |Math                |21                  |Google              |
| 2   |Teresa Mae          |Gowers              |Chemistry           |22                  |Verizon             |
================================================================================================================

[105]: select * from employee where last = "Van Gogh" or last = Jackson and salary >= 165000
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Jackson             |Flo                 |Math                |165000              |2017                |
| 1   |Jackson             |Billy               |Math                |170000              |2017                |
| 2   |Van Gogh            |Vincent             |Art                 |240000              |2015                |
| 3   |Van Gogh            |Vincent             |CS                  |245000              |2015                |
| 4   |Van Gogh            |Jim Bob             |Phys Ed             |230000              |2010                |
================================================================================================================

//.................
//:AND OR AND     :
//.................
[106]: select * from student where age <30 and major=CS or major = Physics and company = Amazon
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |Google              |
| 1   |Bo                  |Yang                |CS                  |28                  |Microsoft           |
| 2   |Greg                |Pearson             |Physics             |20                  |Amazon              |
| 3   |Anna Grace          |Del Rio             |CS                  |22                  |USAF                |
================================================================================================================

[107]: select * from student where age <=40 and company=Uber or major = CS and company = Google
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |Google              |
| 1   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 2   |Calvin              |Woo                 |Physics             |22                  |Uber                |
================================================================================================================

[108]: select * from employee where dep = CS and salary >= 160000 or year > 2014 and last = "Van Gogh"
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Yang                |Bo                  |CS                  |160000              |2013                |
| 1   |Van Gogh            |Vincent             |Art                 |240000              |2015                |
| 2   |Van Gogh            |Vincent             |CS                  |245000              |2015                |
================================================================================================================

//.................
//:OR AND OR      :
//.................
[109]: select * from student where lname = Yang or major = CS and age < 23 or company = Google
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Flo                 |Yao                 |CS                  |20                  |Google              |
| 1   |Bo                  |Yang                |CS                  |28                  |Microsoft           |
| 2   |Flo                 |Jackson             |Math                |21                  |Google              |
| 3   |Anna Grace          |Del Rio             |CS                  |22                  |USAF                |
================================================================================================================

[110]: select * from student where major = Physics or major = Math and company = Google or lname = Jackson
================================================================================================================
| #   |fname               |lname               |major               |age                 |company             |
================================================================================================================
| 0   |Sammuel L.          |Jackson             |CS                  |40                  |Uber                |
| 1   |Flo                 |Jackson             |Math                |21                  |Google              |
| 2   |Greg                |Pearson             |Physics             |20                  |Amazon              |
| 3   |Calvin              |Woo                 |Physics             |22                  |Uber                |
================================================================================================================

[111]: select * from employee where dep = CS or year >2014 and year < 2018 or salary >= 265000
================================================================================================================
| #   |last                |first               |dep                 |salary              |year                |
================================================================================================================
| 0   |Blow                |Joe                 |CS                  |100000              |2018                |
| 1   |Blow                |JoAnn               |Physics             |200000              |2016                |
| 2   |Yao                 |Flo                 |CS                  |147000              |2012                |
| 3   |Yang                |Bo                  |CS                  |160000              |2013                |
| 4   |Jackson             |Flo                 |Math                |165000              |2017                |
| 5   |Jackson             |Billy               |Math                |170000              |2017                |
| 6   |Van Gogh            |Vincent             |Art                 |240000              |2015                |
| 7   |Van Gogh            |Vincent             |CS                  |245000              |2015                |
================================================================================================================

> quit
Press <RETURN> to close this window...

 */


// OUTPUT VI (BTree remove runs):

// REMOVING ALWAYS THE SMALLEST ITEM:
/*

50 100 0 13 22 3 72 108 45 33 17 4 58 69 70 24 -999
bt1:
                     108
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 16
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
[0 3 4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
Insert number: Remove number: 0
bpt1:
                     108
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
               4
                       3


SIZE: 15
Iterated list of items int bpt1: [3 4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
Remove number: 3
bpt1:
                     108
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4


SIZE: 14
Iterated list of items int bpt1: [4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
Remove number: 4
bpt1:
                     108
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      17
              17
                      13


SIZE: 13
Iterated list of items int bpt1: [13 17 22 24 33 45 50 58 69 70 72 100 108 ]
Remove number: 13
bpt1:
             108
             100
     100
              72
72
              70
              69
      69
              58
      58
              50
50
              45
              33
      33
              24
              22
      22
              17


SIZE: 12
Iterated list of items int bpt1: [17 22 24 33 45 50 58 69 70 72 100 108 ]
Remove number: 17
bpt1:
             108
             100
     100
              72
72
              70
              69
      69
              58
      58
              50
50
              45
              33
      33
              24
      24
              22


SIZE: 11
Iterated list of items int bpt1: [22 24 33 45 50 58 69 70 72 100 108 ]
Remove number: 22
bpt1:
             108
             100
     100
              72
72
              70
              69
      69
              58
      58
              50
50
              45
              33
      33
              24


SIZE: 10
Iterated list of items int bpt1: [24 33 45 50 58 69 70 72 100 108 ]
Remove number: 24
bpt1:
             108
             100
     100
              72
72
              70
              69
      69
              58
      58
              50
50
              45
      45
              33


SIZE: 9
Iterated list of items int bpt1: [33 45 50 58 69 70 72 100 108 ]
Remove number: 33
bpt1:
             108
             100
     100
              72
72
              70
              69
      69
              58
58
              50
      50
              45


SIZE: 8
Iterated list of items int bpt1: [45 50 58 69 70 72 100 108 ]
Remove number: 45
bpt1:
             108
             100
     100
              72
72
              70
              69
      69
              58
      58
              50


SIZE: 7
Iterated list of items int bpt1: [50 58 69 70 72 100 108 ]
Remove number: 50
bpt1:
             108
             100
     100
              72
72
              70
              69
      69
              58


SIZE: 6
Iterated list of items int bpt1: [58 69 70 72 100 108 ]
Remove number: 58
bpt1:
             108
             100
     100
              72
72
              70
      70
              69


SIZE: 5
Iterated list of items int bpt1: [69 70 72 100 108 ]
Remove number: 69
bpt1:
     108
     100
100
      72
72
      70


SIZE: 4
Iterated list of items int bpt1: [70 72 100 108 ]
Remove number: 70
bpt1:
     108
     100
100
      72


SIZE: 3
Iterated list of items int bpt1: [72 100 108 ]
Remove number: 72
bpt1:
     108
108
     100


SIZE: 2
Iterated list of items int bpt1: [100 108 ]
Remove number: 100
bpt1:
108


SIZE: 1
Iterated list of items int bpt1: [108 ]
Remove number: 108
bpt1:


SIZE: 0
Iterated list of items int bpt1: []
Remove number: -999
Press <RETURN> to close this window...
*/

// REMOVING ALWAYS THE LARGEST ITEM
/*

50 100 0 13 22 3 72 108 45 33 17 4 58 69 70 24 -999
bpt1:
                     108
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 16
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
[0 3 4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
Remove number: 108
bpt1:
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 15
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 50 58 69 70 72 100 ]
Remove number: 100
bpt1:
                      72
              72
                      70
                      69
      69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 14
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 50 58 69 70 72 ]
Remove number: 72
bpt1:
                      70
              70
                      69
      69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 13
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 50 58 69 70 ]
Remove number: 70
bpt1:
              69
      69
              58
      58
              50
50
              45
              33
      33
              24
              22
22
              17
              13
      13
               4
               3
       3
               0


SIZE: 12
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 50 58 69 ]
Remove number: 69
bpt1:
              58
      58
              50
50
              45
              33
      33
              24
              22
22
              17
              13
      13
               4
               3
       3
               0


SIZE: 11
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 50 58 ]
Remove number: 58
bpt1:
              50
      50
              45
              33
      33
              24
              22
22
              17
              13
      13
               4
               3
       3
               0


SIZE: 10
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 50 ]
Remove number: 50
bpt1:
              45
      45
              33
      33
              24
              22
22
              17
              13
      13
               4
               3
       3
               0


SIZE: 9
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 ]
Remove number: 45
bpt1:
              33
      33
              24
              22
22
              17
              13
      13
               4
               3
       3
               0


SIZE: 8
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 ]
Remove number: 33
bpt1:
              24
      24
              22
22
              17
              13
      13
               4
               3
       3
               0


SIZE: 7
Iterated list of items int bpt1: [0 3 4 13 17 22 24 ]
Remove number: 24
bpt1:
              22
      22
              17
              13
13
               4
               3
       3
               0


SIZE: 6
Iterated list of items int bpt1: [0 3 4 13 17 22 ]
Remove number: 22
bpt1:
              17
      17
              13
13
               4
               3
       3
               0


SIZE: 5
Iterated list of items int bpt1: [0 3 4 13 17 ]
Remove number: 17
bpt1:
      13
13
       4
       3
3
       0


SIZE: 4
Iterated list of items int bpt1: [0 3 4 13 ]
Remove number: 13
bpt1:
       4
4
       3
3
       0


SIZE: 3
Iterated list of items int bpt1: [0 3 4 ]
Remove number: 4
bpt1:
       3
3
       0


SIZE: 2
Iterated list of items int bpt1: [0 3 ]
Remove number: 3
bpt1:
0


SIZE: 1
Iterated list of items int bpt1: [0 ]
Remove number: 0
bpt1:


SIZE: 0
Iterated list of items int bpt1: []
Remove number: -999
Press <RETURN> to close this window...
*/

// REMOVING ALWAYS THE LARGEST ROOT
/*

50 100 0 13 22 3 72 108 45 33 17 4 58 69 70 24 -999
bpt1:
                     108
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 16
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
[0 3 4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
Remove number: 50
bpt1:
                     108
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
58
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 15
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 58 69 70 72 100 108 ]
Remove number: 58
bpt1:
                     108
                     100
             100
                      72
      72
                      70
              70
                      69
69
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 14
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 69 70 72 100 108 ]
Remove number: 69
bpt1:
             108
             100
     100
              72
      72
              70
70
              45
              33
      33
              24
              22
22
              17
              13
      13
               4
               3
       3
               0


SIZE: 13
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 70 72 100 108 ]
Remove number: 70
bpt1:
             108
             100
     100
              72
72
              45
              33
      33
              24
              22
22
              17
              13
      13
               4
               3
       3
               0


SIZE: 12
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 72 100 108 ]
Remove number: 72
bpt1:
             108
     108
             100
100
              45
              33
      33
              24
              22
22
              17
              13
      13
               4
               3
       3
               0


SIZE: 11
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 100 108 ]
Remove number: 100
bpt1:
             108
     108
              45
              33
      33
              24
              22
22
              17
              13
      13
               4
               3
       3
               0


SIZE: 10
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 108 ]
Remove number: 22
bpt1:
             108
     108
              45
              33
      33
              24
24
              17
              13
      13
               4
               3
       3
               0


SIZE: 9
Iterated list of items int bpt1: [0 3 4 13 17 24 33 45 108 ]
Remove number: 24
bpt1:
             108
     108
              45
      45
              33
33
              17
              13
      13
               4
               3
       3
               0


SIZE: 8
Iterated list of items int bpt1: [0 3 4 13 17 33 45 108 ]
Remove number: 33
bpt1:
             108
     108
              45
45
              17
              13
      13
               4
               3
       3
               0


SIZE: 7
Iterated list of items int bpt1: [0 3 4 13 17 45 108 ]
Remove number: 45
bpt1:
             108
     108
              17
              13
13
               4
               3
       3
               0


SIZE: 6
Iterated list of items int bpt1: [0 3 4 13 17 108 ]
Remove number: 13
bpt1:
             108
     108
              17
17
               4
               3
       3
               0


SIZE: 5
Iterated list of items int bpt1: [0 3 4 17 108 ]
Remove number: 17
bpt1:
     108
108
       4
       3
3
       0


SIZE: 4
Iterated list of items int bpt1: [0 3 4 108 ]
Remove number: 108
bpt1:
       4
4
       3
3
       0


SIZE: 3
Iterated list of items int bpt1: [0 3 4 ]
Remove number: 3
bpt1:
       4
4
       0


SIZE: 2
Iterated list of items int bpt1: [0 4 ]
Remove number: 4
bpt1:
0


SIZE: 1
Iterated list of items int bpt1: [0 ]
Remove number: 0
bpt1:


SIZE: 0
Iterated list of items int bpt1: []
Remove number: -999
Press <RETURN> to close this window...

*/

// REMOVING ALWAYS THE SMALLEST ROOT
/*

50 100 0 13 22 3 72 108 45 33 17 4 58 69 70 24 -999
bpt1:
                     108
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 16
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
[0 3 4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
Remove number: 50
bpt1:
                     108
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
58
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 15
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 58 69 70 72 100 108 ]
Remove number: 58
bpt1:
                     108
                     100
             100
                      72
      72
                      70
              70
                      69
69
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 14
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 69 70 72 100 108 ]
Remove number: 69
bpt1:
             108
             100
     100
              72
      72
              70
70
              45
              33
      33
              24
              22
22
              17
              13
      13
               4
               3
       3
               0


SIZE: 13
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 70 72 100 108 ]
Remove number: 22
bpt1:
             108
             100
     100
              72
      72
              70
70
              45
              33
      33
              24
24
              17
              13
      13
               4
               3
       3
               0


SIZE: 12
Iterated list of items int bpt1: [0 3 4 13 17 24 33 45 70 72 100 108 ]
Remove number: 24
bpt1:
             108
             100
     100
              72
      72
              70
70
              45
      45
              33
33
              17
              13
      13
               4
               3
       3
               0


SIZE: 11
Iterated list of items int bpt1: [0 3 4 13 17 33 45 70 72 100 108 ]
Remove number: 33
bpt1:
             108
             100
     100
              72
      72
              70
70
              45
      45
              17
              13
13
               4
               3
       3
               0


SIZE: 10
Iterated list of items int bpt1: [0 3 4 13 17 45 70 72 100 108 ]
Remove number: 13
bpt1:
             108
             100
     100
              72
      72
              70
70
              45
      45
              17
17
               4
               3
       3
               0


SIZE: 9
Iterated list of items int bpt1: [0 3 4 17 45 70 72 100 108 ]
Remove number: 17
bpt1:
             108
             100
     100
              72
72
              70
      70
              45
45
               4
               3
       3
               0


SIZE: 8
Iterated list of items int bpt1: [0 3 4 45 70 72 100 108 ]
Remove number: 45
bpt1:
             108
             100
     100
              72
72
              70
      70
               4
               3
       3
               0


SIZE: 7
Iterated list of items int bpt1: [0 3 4 70 72 100 108 ]
Remove number: 72
bpt1:
             108
     108
             100
100
              70
      70
               4
               3
       3
               0


SIZE: 6
Iterated list of items int bpt1: [0 3 4 70 100 108 ]
Remove number: 100
bpt1:
             108
     108
              70
70
               4
               3
       3
               0


SIZE: 5
Iterated list of items int bpt1: [0 3 4 70 108 ]
Remove number: 70
bpt1:
     108
108
       4
       3
3
       0


SIZE: 4
Iterated list of items int bpt1: [0 3 4 108 ]
Remove number: 3
bpt1:
     108
108
       4
4
       0


SIZE: 3
Iterated list of items int bpt1: [0 4 108 ]
Remove number: 4
bpt1:
     108
108
       0


SIZE: 2
Iterated list of items int bpt1: [0 108 ]
Remove number: 108
bpt1:
0


SIZE: 1
Iterated list of items int bpt1: [0 ]
Remove number: 0
bpt1:


SIZE: 0
Iterated list of items int bpt1: []
Remove number: -999
Press <RETURN> to close this window...

*/

// REMOVING RANDOM ROOT
/*

50 100 0 13 22 3 72 108 45 33 17 4 58 69 70 24 -999
bpt1:
                     108
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 16
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
[0 3 4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
Remove number: 50
bpt1:
                     108
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
58
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 15
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 58 69 70 72 100 108 ]
Remove number: 58
bpt1:
                     108
                     100
             100
                      72
      72
                      70
              70
                      69
69
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 14
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 69 70 72 100 108 ]
Remove number: 69
bpt1:
             108
             100
     100
              72
      72
              70
70
              45
              33
      33
              24
              22
22
              17
              13
      13
               4
               3
       3
               0


SIZE: 13
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 70 72 100 108 ]
Remove number: 70
bpt1:
             108
             100
     100
              72
72
              45
              33
      33
              24
              22
22
              17
              13
      13
               4
               3
       3
               0


SIZE: 12
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 72 100 108 ]
Remove number: 22
bpt1:
             108
             100
     100
              72
72
              45
              33
      33
              24
24
              17
              13
      13
               4
               3
       3
               0


SIZE: 11
Iterated list of items int bpt1: [0 3 4 13 17 24 33 45 72 100 108 ]
Remove number: 72
bpt1:
             108
     108
             100
100
              45
              33
      33
              24
24
              17
              13
      13
               4
               3
       3
               0


SIZE: 10
Iterated list of items int bpt1: [0 3 4 13 17 24 33 45 100 108 ]
Remove number: 100
bpt1:
             108
     108
              45
              33
      33
              24
24
              17
              13
      13
               4
               3
       3
               0


SIZE: 9
Iterated list of items int bpt1: [0 3 4 13 17 24 33 45 108 ]
Remove number: 24
bpt1:
             108
     108
              45
      45
              33
33
              17
              13
      13
               4
               3
       3
               0


SIZE: 8
Iterated list of items int bpt1: [0 3 4 13 17 33 45 108 ]
Remove number: 33
bpt1:
             108
     108
              45
45
              17
              13
      13
               4
               3
       3
               0


SIZE: 7
Iterated list of items int bpt1: [0 3 4 13 17 45 108 ]
Remove number: 45
bpt1:
             108
     108
              17
              13
13
               4
               3
       3
               0


SIZE: 6
Iterated list of items int bpt1: [0 3 4 13 17 108 ]
Remove number: 13
bpt1:
             108
     108
              17
17
               4
               3
       3
               0


SIZE: 5
Iterated list of items int bpt1: [0 3 4 17 108 ]
Remove number: 17
bpt1:
     108
108
       4
       3
3
       0


SIZE: 4
Iterated list of items int bpt1: [0 3 4 108 ]
Remove number: 3
bpt1:
     108
108
       4
4
       0


SIZE: 3
Iterated list of items int bpt1: [0 4 108 ]
Remove number: 108
bpt1:
       4
4
       0


SIZE: 2
Iterated list of items int bpt1: [0 4 ]
Remove number: 3
bpt1:
       4
4
       0


SIZE: 2
Iterated list of items int bpt1: [0 4 ]
Remove number: 4
bpt1:
0


SIZE: 1
Iterated list of items int bpt1: [0 ]
Remove number: 0
bpt1:


SIZE: 0
Iterated list of items int bpt1: []
Remove number: -999
Press <RETURN> to close this window...
 */

// REMOVING RANDOM
/*

50 100 0 13 22 3 72 108 45 33 17 4 58 69 70 24 -999
bpt1:
                     108
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 16
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
[0 3 4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
Remove number: 69
bpt1:
                     108
                     100
             100
                      72
      72
                      70
              70
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 15
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 50 58 70 72 100 108 ]
Remove number: 17
bpt1:
                     108
                     100
             100
                      72
      72
                      70
              70
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      13
              13
                       4
                       3
               3
                       0


SIZE: 14
Iterated list of items int bpt1: [0 3 4 13 22 24 33 45 50 58 70 72 100 108 ]
Remove number: 72
bpt1:
                     108
             108
                     100
     100
                      70
              70
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      13
              13
                       4
                       3
               3
                       0


SIZE: 13
Iterated list of items int bpt1: [0 3 4 13 22 24 33 45 50 58 70 100 108 ]
Remove number: 0
bpt1:
                     108
             108
                     100
     100
                      70
              70
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      13
              13
                       4
               4
                       3


SIZE: 12
Iterated list of items int bpt1: [3 4 13 22 24 33 45 50 58 70 100 108 ]
Remove number: 100
bpt1:
                     108
             108
                      70
      70
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      13
              13
                       4
               4
                       3


SIZE: 11
Iterated list of items int bpt1: [3 4 13 22 24 33 45 50 58 70 108 ]
Remove number: 22
bpt1:
                     108
             108
                      70
      70
                      58
              58
                      50
50
                      45
                      33
              33
                      24
      24
                      13
              13
                       4
               4
                       3


SIZE: 10
Iterated list of items int bpt1: [3 4 13 24 33 45 50 58 70 108 ]
Remove number: 50
bpt1:
             108
     108
              70
      70
              58
58
              45
              33
      33
              24
24
              13
      13
               4
       4
               3


SIZE: 9
Iterated list of items int bpt1: [3 4 13 24 33 45 58 70 108 ]
Remove number: 33
bpt1:
             108
     108
              70
      70
              58
58
              45
      45
              24
24
              13
      13
               4
       4
               3


SIZE: 8
Iterated list of items int bpt1: [3 4 13 24 45 58 70 108 ]
Remove number: 3
bpt1:
             108
     108
              70
      70
              58
58
              45
      45
              24
24
              13
      13
               4


SIZE: 7
Iterated list of items int bpt1: [4 13 24 45 58 70 108 ]
Remove number: 45
bpt1:
             108
     108
              70
70
              58
      58
              24
24
              13
      13
               4


SIZE: 6
Iterated list of items int bpt1: [4 13 24 58 70 108 ]
Remove number: 70
bpt1:
             108
     108
              58
      58
              24
24
              13
      13
               4


SIZE: 5
Iterated list of items int bpt1: [4 13 24 58 108 ]
Remove number: 108
bpt1:
              58
      58
              24
24
              13
      13
               4


SIZE: 4
Iterated list of items int bpt1: [4 13 24 58 ]
Remove number: 4
bpt1:
      58
58
      24
24
      13


SIZE: 3
Iterated list of items int bpt1: [13 24 58 ]
Remove number: 24
bpt1:
      58
58
      13


SIZE: 2
Iterated list of items int bpt1: [13 58 ]
Remove number: 13
bpt1:
58


SIZE: 1
Iterated list of items int bpt1: [58 ]
Remove number: 58
bpt1:


SIZE: 0
Iterated list of items int bpt1: []
Remove number: -999
Press <RETURN> to close this window...

*/

// REMOVING RANDOM II
/*

50 100 0 13 22 3 72 108 45 33 17 4 58 69 70 24 -999
bpt1:
                     108
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
                      22
      22
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 16
Iterated list of items int bpt1: [0 3 4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
[0 3 4 13 17 22 24 33 45 50 58 69 70 72 100 108 ]
Remove number: 22
bpt1:
                     108
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
      24
                      17
                      13
              13
                       4
                       3
               3
                       0


SIZE: 15
Iterated list of items int bpt1: [0 3 4 13 17 24 33 45 50 58 69 70 72 100 108 ]
Remove number: 13
bpt1:
                     108
                     100
             100
                      72
      72
                      70
                      69
              69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
      24
                      17
              17
                       4
                       3
               3
                       0


SIZE: 14
Iterated list of items int bpt1: [0 3 4 17 24 33 45 50 58 69 70 72 100 108 ]
Remove number: 70
bpt1:
                     108
                     100
             100
                      72
      72
                      69
              69
                      58
              58
                      50
50
                      45
                      33
              33
                      24
      24
                      17
              17
                       4
                       3
               3
                       0


SIZE: 13
Iterated list of items int bpt1: [0 3 4 17 24 33 45 50 58 69 72 100 108 ]
Remove number: 45
bpt1:
                     108
                     100
             100
                      72
      72
                      69
              69
                      58
              58
                      50
50
                      33
              33
                      24
      24
                      17
              17
                       4
                       3
               3
                       0


SIZE: 12
Iterated list of items int bpt1: [0 3 4 17 24 33 50 58 69 72 100 108 ]
Remove number: 72
bpt1:
                     108
             108
                     100
     100
                      69
              69
                      58
              58
                      50
50
                      33
              33
                      24
      24
                      17
              17
                       4
                       3
               3
                       0


SIZE: 11
Iterated list of items int bpt1: [0 3 4 17 24 33 50 58 69 100 108 ]
Remove number: 4
bpt1:
                     108
             108
                     100
     100
                      69
              69
                      58
              58
                      50
50
                      33
              33
                      24
      24
                      17
              17
                       3
               3
                       0


SIZE: 10
Iterated list of items int bpt1: [0 3 17 24 33 50 58 69 100 108 ]
Remove number: 108
bpt1:
                     100
             100
                      69
      69
                      58
              58
                      50
50
                      33
              33
                      24
      24
                      17
              17
                       3
               3
                       0


SIZE: 9
Iterated list of items int bpt1: [0 3 17 24 33 50 58 69 100 ]
Remove number: 100
bpt1:
              69
      69
              58
      58
              50
50
              33
      33
              24
24
              17
      17
               3
       3
               0


SIZE: 8
Iterated list of items int bpt1: [0 3 17 24 33 50 58 69 ]
Remove number: 3
bpt1:
              69
      69
              58
      58
              50
50
              33
      33
              24
24
              17
      17
               0


SIZE: 7
Iterated list of items int bpt1: [0 17 24 33 50 58 69 ]
Remove number: 58
bpt1:
              69
      69
              50
50
              33
      33
              24
24
              17
      17
               0


SIZE: 6
Iterated list of items int bpt1: [0 17 24 33 50 69 ]
Remove number: 50
bpt1:
              69
      69
              33
      33
              24
24
              17
      17
               0


SIZE: 5
Iterated list of items int bpt1: [0 17 24 33 69 ]
Remove number: 0
bpt1:
              69
      69
              33
33
              24
      24
              17


SIZE: 4
Iterated list of items int bpt1: [17 24 33 69 ]
Remove number: 69
bpt1:
      33
33
      24
24
      17


SIZE: 3
Iterated list of items int bpt1: [17 24 33 ]
Remove number: 24
bpt1:
      33
33
      17


SIZE: 2
Iterated list of items int bpt1: [17 33 ]
Remove number: 33
bpt1:
17


SIZE: 1
Iterated list of items int bpt1: [17 ]
Remove number: 17
bpt1:


SIZE: 0
Iterated list of items int bpt1: []
Remove number: -999
Press <RETURN> to close this window...

 */


// OUTPUT VII (BTree is_valid auto test with truncated output):
/*

*********************************************************
 T E S T:    96
*********************************************************
========================================================

========================================================
                                                             999
                                                             998
                                                     998
                                                             997
                                                     997
                                                             996
                                                             995
                                             995
                                                             994
                                                             993
                                                     993
                                                             992
                                                             991
                                             991
                                                             990
                                                             989
                                                     989
                                                             988
                                                     988
                                                             987
                                                             986
                                     986
                                                             985
                                                     985
                                                             984
                                                             983
                                                     983
                                                             982
                                             982
                                                             981
                                                     981
                                                             980
                                                             979
                             979
                                                             978
                                                             977
                                                     977
                                                             976
                                             976
                                                             975
                                                             974
                                                     974
                                                             973
                                     973
                                                             972
                                                             971
                                                     971
                                                             970
                                                             969
                                             969
                                                             968
                                                             967
                                                     967
                                                             966
                                                             965
                             965
                                                             964
                                                     964
                                                             963
                                                             962
                                             962
                                                             961
                                                     961
                                                             960
                                     960
                                                             959
                                                             958
                                                     958
                                                             957
                                                     957
                                                             956
                                             956
                                                             955
                                                             954
                                                     954
                                                             953
                                     953
                                                             952
                                                             951
                                                     951
                                                             950
                                                     950
                                                             949
                                                             948
                                             948
                                                             947
                                                             946
                                                     946
                                                             945
                                                     945
                                                             944
                                             944
                                                             943
                                                             942
                                                     942
                                                             941
                     941
                                                             940
                                                             939
                                                     939
                                                             938
                                                             937
                                                     937
                                                             936
                                             936
                                                             935
                                                             934
                                                     934
                                                             933
                                                             932
                                     932
                                                             931
                                                             930
                                                     930
                                                             929
                                             929
                                                             928
                                                             927
                                                     927
                                                             926
                                             926
                                                             925
                                                             924
                                                     924
                                                             923
                             923
                                                             922
                                                             921
                                                     921
                                                             920
                                             920
                                                             919
                                                             918
                                                     918
                                                             917
                                                     917
                                                             916
                                     916
                                                             915
                                                     915
                                                             914
                                                             913
                                             913
                                                             912
                                                             911
                                                     911
                                                             910
                                     910
                                                             909
                                                             908
                                                     908
                                                             907
                                                     907
                                                             906
                                             906
                                                             905
                                                             904
                                                     904
                                                             903
                                                             902
                             902
                                                             901
                                                             900
                                                     900
                                                             899
                                             899
                                                             898
                                                             897
                                                     897
                                                             896
                                     896
                                                             895
                                                             894
                                                     894
                                                             893
                                                             892
                                             892
                                                             891
                                                     891
                                                             890
                                                             889
                                                     889
                                                             888
                                                             887
                                     887
                                                             886
                                                     886
                                                             885
                                                             884
                                                     884
                                                             883
                                                             882
                                             882
                                                             881
                                                             880
                                                     880
                                                             879
                                                     879
                                                             878
                                             878
                                                             877
                                                     877
                                                             876
                                                             875
             875
                                                             874
                                                             873
                                                     873
                                                             872
                                                     872
                                                             871
                                             871
                                                             870
                                                     870
                                                             869
                                                             868
                                                     868
                                                             867
                                             867
                                                             866
                                                             865
                                                     865
                                                             864
                                     864
                                                             863
                                                             862
                                                     862
                                                             861
                                             861
                                                             860
                                                             859
                                                     859
                                                             858
                                                             857
                                                     857
                                                             856
                                             856
                                                             855
                                                     855
                                                             854
                                                             853
                             853
                                                             852
                                                             851
                                                     851
                                                             850
                                                             849
                                             849
                                                             848
                                                             847
                                                     847
                                                             846
                                             846
                                                             845
                                                             844
                                                     844
                                                             843
                                                             842
                                                     842
                                                             841
                                     841
                                                             840
                                                             839
                                                     839
                                                             838
                                                             837
                                             837
                                                             836
                                                     836
                                                             835
                             835
                                                             834
                                                             833
                                                     833
                                                             832
                                             832
                                                             831
                                                     831
                                                             830
                                                             829
                                             829
                                                             828
                                                             827
                                                     827
                                                             826
                                     826
                                                             825
                                                     825
                                                             824
                                                             823
                                             823
                                                             822
                                                     822
                                                             821
                     821
                                                             820
                                                             819
                                                     819
                                                             818
                                                             817
                                             817
                                                             816
                                                             815
                                                     815
                                                             814
                                                             813
                                             813
                                                             812
                                                     812
                                                             811
                                     811
                                                             810
                                                             809
                                                     809
                                                             808
                                                             807
                                                     807
                                                             806
                                             806
                                                             805
                                                     805
                                                             804
                                     804
                                                             803
                                                             802
                                                     802
                                                             801
                                             801
                                                             800
                                                     800
                                                             799
                                             799
                                                             798
                                                             797
                                                     797
                                                             796
                             796
                                                             795
                                                             794
                                                     794
                                                             793
                                             793
                                                             792
                                                     792
                                                             791
                                                             790
                                             790
                                                             789
                                                     789
                                                             788
                                     788
                                                             787
                                                             786
                                                     786
                                                             785
                                                     785
                                                             784
                                                             783
                                             783
                                                             782
                                                             781
                                                     781
                                                             780
     780
                                                             779
                                                             778
                                                     778
                                                             777
                                                     777
                                                             776
                                             776
                                                             775
                                                             774
                                                     774
                                                             773
                                             773
                                                             772
                                                             771
                                                     771
                                                             770
                                     770
                                                             769
                                                             768
                                                     768
                                                             767
                                                     767
                                                             766
                                                             765
                                             765
                                                             764
                                                     764
                                                             763
                                                             762
                                     762
                                                             761
                                                             760
                                                     760
                                                             759
                                             759
                                                             758
                                                     758
                                                             757
                                                             756
                             756
                                                             755
                                                             754
                                                     754
                                                             753
                                                             752
                                                     752
                                                             751
                                             751
                                                             750
                                                             749
                                                     749
                                                             748
                                             748
                                                             747
                                                     747
                                                             746
                                                             745
                                                     745
                                                             744
                                     744
                                                             743
                                                             742
                                                     742
                                                             741
                                                             740
                                                     740
                                                             739
                                             739
                                                             738
                                                             737
                                                     737
                                                             736
                                                     736
                                                             735
                             735
                                                             734
                                                             733
                                                     733
                                                             732
                                                             731
                                             731
                                                             730
                                                     730
                                                             729
                                     729
                                                             728
                                                     728
                                                             727
                                                             726
                                             726
                                                             725
                                                     725
                                                             724
                     724
                                                             723
                                                             722
                                                     722
                                                             721
                                             721
                                                             720
                                                             719
                                                     719
                                                             718
                                     718
                                                             717
                                                             716
                                                     716
                                                             715
                                             715
                                                             714
                                                             713
                                                     713
                                                             712
                                     712
                                                             711
                                                             710
                                                     710
                                                             709
                                                             708
                                             708
                                                             707
                                                     707
                                                             706
                                                             705
                                             705
                                                             704
                                                             703
                                                     703
                                                             702
                             702
                                                             701
                                                             700
                                                     700
                                                             699
                                             699
                                                             698
                                                             697
                                                     697
                                                             696
                                     696
                                                             695
                                                             694
                                                     694
                                                             693
                                                             692
                                             692
                                                             691
                                                             690
                                                     690
                                                             689
                                                     689
                                                             688
                                     688
                                                             687
                                                             686
                                                     686
                                                             685
                                                             684
                                             684
                                                             683
                                                             682
                                                     682
                                                             681
                                                             680
                                                     680
                                                             679
                                             679
                                                             678
                                                     678
                                                             677
                     677
                                                             676
                                                             675
                                                     675
                                                             674
                                                     674
                                                             673
                                             673
                                                             672
                                                             671
                                                     671
                                                             670
                                             670
                                                             669
                                                     669
                                                             668
                                                             667
                                                     667
                                                             666
                                     666
                                                             665
                                                             664
                                                     664
                                                             663
                                             663
                                                             662
                                                             661
                                                     661
                                                             660
                                     660
                                                             659
                                                             658
                                                     658
                                                             657
                                             657
                                                             656
                                                             655
                                                     655
                                                             654
                                                             653
                                                     653
                                                             652
                             652
                                                             651
                                                             650
                                                     650
                                                             649
                                             649
                                                             648
                                                             647
                                                     647
                                                             646
                                                             645
                                             645
                                                             644
                                                     644
                                                             643
                                     643
                                                             642
                                                             641
                                                     641
                                                             640
                                                             639
                                             639
                                                             638
                                                     638
                                                             637
                                     637
                                                             636
                                                     636
                                                             635
                                                             634
                                             634
                                                             633
                                                             632
                                                     632
                                                             631
                                                     631
                                                             630
                                                             629
                                             629
                                                             628
                                                     628
                                                             627
                                                             626
             626
                                                             625
                                                             624
                                                     624
                                                             623
                                                     623
                                                             622
                                             622
                                                             621
                                                     621
                                                             620
                                                             619
                                             619
                                                             618
                                                     618
                                                             617
                                                             616
                                     616
                                                             615
                                                             614
                                                     614
                                                             613
                                             613
                                                             612
                                                             611
                                                     611
                                                             610
                                     610
                                                             609
                                                             608
                                                     608
                                                             607
                                             607
                                                             606
                                                             605
                                                     605
                                                             604
                             604
                                                             603
                                                             602
                                                     602
                                                             601
                                             601
                                                             600
                                                             599
                                                     599
                                                             598
                                             598
                                                             597
                                                             596
                                                     596
                                                             595
                                     595
                                                             594
                                                             593
                                                     593
                                                             592
                                             592
                                                             591
                                                             590
                                                     590
                                                             589
                                                             588
                                                     588
                                                             587
                             587
                                                             586
                                                             585
                                                     585
                                                             584
                                             584
                                                             583
                                                             582
                                                     582
                                                             581
                                             581
                                                             580
                                                             579
                                                     579
                                                             578
                                                             577
                                     577
                                                             576
                                                             575
                                                     575
                                                             574
                                             574
                                                             573
                                                             572
                                                     572
                                                             571
                                             571
                                                             570
                                                             569
                                                     569
                                                             568
                                                             567
                                                     567
                                                             566
                     566
                                                             565
                                                     565
                                                             564
                                             564
                                                             563
                                                             562
                                                     562
                                                             561
                                                     561
                                                             560
                                                             559
                                             559
                                                             558
                                                     558
                                                             557
                                     557
                                                             556
                                                             555
                                                     555
                                                             554
                                                             553
                                             553
                                                             552
                                                             551
                                                     551
                                                             550
                                                             549
                                     549
                                                             548
                                                     548
                                                             547
                                             547
                                                             546
                                                             545
                                                     545
                                                             544
                                                             543
                                                     543
                                                             542
                             542
                                                             541
                                                             540
                                                     540
                                                             539
                                                             538
                                             538
                                                             537
                                                     537
                                                             536
                                                             535
                                             535
                                                             534
                                                             533
                                                     533
                                                             532
                                                     532
                                                             531
                                                             530
                                     530
                                                             529
                                                             528
                                                     528
                                                             527
                                                     527
                                                             526
                                             526
                                                             525
                                                             524
                                                     524
                                                             523
                                     523
                                                             522
                                                             521
                                                     521
                                                             520
                                             520
                                                             519
                                                             518
                                                     518
                                                             517
                                                     517
                                                             516
                                                             515
515
                                                             514
                                                             513
                                                     513
                                                             512
                                                             511
                                             511
                                                             510
                                                             509
                                                     509
                                                             508
                                                             507
                                     507
                                                             506
                                                             505
                                                     505
                                                             504
                                                     504
                                                             503
                                             503
                                                             502
                                                             501
                                                     501
                                                             500
                                             500
                                                             499
                                                             498
                                                     498
                                                             497
                             497
                                                             496
                                                             495
                                                     495
                                                             494
                                                             493
                                             493
                                                             492
                                                             491
                                                     491
                                                             490
                                             490
                                                             489
                                                     489
                                                             488
                                                             487
                                                     487
                                                             486
                                                             485
                                     485
                                                             484
                                                     484
                                                             483
                                             483
                                                             482
                                                             481
                                                     481
                                                             480
                                                     480
                                                             479
                                                             478
                                             478
                                                             477
                                                     477
                                                             476
                                                             475
                     475
                                                             474
                                                             473
                                                     473
                                                             472
                                             472
                                                             471
                                                             470
                                                     470
                                                             469
                                     469
                                                             468
                                                             467
                                                     467
                                                             466
                                                     466
                                                             465
                                             465
                                                             464
                                                             463
                                                     463
                                                             462
                             462
                                                             461
                                                             460
                                                     460
                                                             459
                                             459
                                                             458
                                                     458
                                                             457
                                             457
                                                             456
                                                     456
                                                             455
                                                             454
                                     454
                                                             453
                                                             452
                                                     452
                                                             451
                                                     451
                                                             450
                                                             449
                                             449
                                                             448
                                                             447
                                                     447
                                                             446
                             446
                                                             445
                                                             444
                                                     444
                                                             443
                                                             442
                                             442
                                                             441
                                                     441
                                                             440
                                     440
                                                             439
                                                             438
                                                     438
                                                             437
                                                     437
                                                             436
                                             436
                                                             435
                                                     435
                                                             434
                     434
                                                             433
                                                             432
                                                     432
                                                             431
                                             431
                                                             430
                                                             429
                                                     429
                                                             428
                                             428
                                                             427
                                                             426
                                                     426
                                                             425
                                     425
                                                             424
                                                     424
                                                             423
                                             423
                                                             422
                                                     422
                                                             421
                             421
                                                             420
                                                             419
                                                     419
                                                             418
                                                             417
                                             417
                                                             416
                                                     416
                                                             415
                                             415
                                                             414
                                                             413
                                                     413
                                                             412
                                                     412
                                                             411
                                     411
                                                             410
                                                             409
                                                     409
                                                             408
                                                     408
                                                             407
                                                             406
                                             406
                                                             405
                                                     405
                                                             404
                                                             403
                                                     403
                                                             402
                             402
                                                             401
                                                             400
                                                     400
                                                             399
                                             399
                                                             398
                                                     398
                                                             397
                                     397
                                                             396
                                                     396
                                                             395
                                                             394
                                             394
                                                             393
                                                             392
                                                     392
                                                             391
                                                     391
                                                             390
                                     390
                                                             389
                                                             388
                                                     388
                                                             387
                                                             386
                                             386
                                                             385
                                                     385
                                                             384
                                             384
                                                             383
                                                     383
                                                             382
             382
                                                             381
                                                             380
                                                     380
                                                             379
                                                     379
                                                             378
                                                             377
                                             377
                                                             376
                                                             375
                                                     375
                                                             374
                                                             373
                                                     373
                                                             372
                                     372
                                                             371
                                                             370
                                                     370
                                                             369
                                                             368
                                             368
                                                             367
                                                     367
                                                             366
                             366
                                                             365
                                                             364
                                                     364
                                                             363
                                                             362
                                             362
                                                             361
                                                     361
                                                             360
                                     360
                                                             359
                                                             358
                                                     358
                                                             357
                                                     357
                                                             356
                                                             355
                                             355
                                                             354
                                                             353
                                                     353
                                                             352
                                                             351
                     351
                                                             350
                                                             349
                                                     349
                                                             348
                                                             347
                                                     347
                                                             346
                                                             345
                                             345
                                                             344
                                                             343
                                                     343
                                                             342
                                     342
                                                             341
                                                             340
                                                     340
                                                             339
                                             339
                                                             338
                                                     338
                                                             337
                                                             336
                                             336
                                                             335
                                                     335
                                                             334
                             334
                                                             333
                                                             332
                                                     332
                                                             331
                                                             330
                                             330
                                                             329
                                                             328
                                                     328
                                                             327
                                     327
                                                             326
                                                             325
                                                     325
                                                             324
                                                     324
                                                             323
                                             323
                                                             322
                                                     322
                                                             321
                                             321
                                                             320
                                                             319
                                                     319
                                                             318
                                                             317
                                                     317
                                                             316
             316
                                                             315
                                                             314
                                                     314
                                                             313
                                             313
                                                             312
                                                             311
                                                     311
                                                             310
                                                             309
                                     309
                                                             308
                                                     308
                                                             307
                                             307
                                                             306
                                                     306
                                                             305
                             305
                                                             304
                                                             303
                                                     303
                                                             302
                                             302
                                                             301
                                                     301
                                                             300
                                     300
                                                             299
                                                     299
                                                             298
                                                             297
                                                     297
                                                             296
                                             296
                                                             295
                                                     295
                                                             294
                     294
                                                             293
                                                             292
                                                     292
                                                             291
                                                             290
                                             290
                                                             289
                                                             288
                                                     288
                                                             287
                                             287
                                                             286
                                                     286
                                                             285
                                     285
                                                             284
                                                             283
                                                     283
                                                             282
                                             282
                                                             281
                                                             280
                                                     280
                                                             279
                                                     279
                                                             278
                                                             277
                             277
                                                             276
                                                             275
                                                     275
                                                             274
                                                     274
                                                             273
                                                             272
                                             272
                                                             271
                                                     271
                                                             270
                                                             269
                                     269
                                                             268
                                                             267
                                                     267
                                                             266
                                             266
                                                             265
                                                     265
                                                             264
                                                             263
                                     263
                                                             262
                                                             261
                                                     261
                                                             260
                                             260
                                                             259
                                                             258
                                                     258
                                                             257
                                                             256
                                                     256
                                                             255
     255
                                                             254
                                                             253
                                                     253
                                                             252
                                                             251
                                             251
                                                             250
                                                     250
                                                             249
                                                             248
                                                     248
                                                             247
                                             247
                                                             246
                                                             245
                                                     245
                                                             244
                                     244
                                                             243
                                                     243
                                                             242
                                                             241
                                                     241
                                                             240
                                             240
                                                             239
                                                     239
                                                             238
                                             238
                                                             237
                                                             236
                                                     236
                                                             235
                                                             234
                             234
                                                             233
                                                             232
                                                     232
                                                             231
                                             231
                                                             230
                                                             229
                                                     229
                                                             228
                                     228
                                                             227
                                                             226
                                                     226
                                                             225
                                             225
                                                             224
                                                     224
                                                             223
                                             223
                                                             222
                                                     222
                                                             221
                                                             220
                                                     220
                                                             219
                                                             218
                     218
                                                             217
                                                             216
                                                     216
                                                             215
                                                     215
                                                             214
                                             214
                                                             213
                                                             212
                                                     212
                                                             211
                                     211
                                                             210
                                                     210
                                                             209
                                                             208
                                             208
                                                             207
                                                     207
                                                             206
                                                             205
                             205
                                                             204
                                                             203
                                                     203
                                                             202
                                                             201
                                                     201
                                                             200
                                             200
                                                             199
                                                     199
                                                             198
                                                             197
                                     197
                                                             196
                                                             195
                                                     195
                                                             194
                                                     194
                                                             193
                                             193
                                                             192
                                                     192
                                                             191
                                             191
                                                             190
                                                             189
                                                     189
                                                             188
                                                     188
                                                             187
                                                             186
                                     186
                                                             185
                                                             184
                                                     184
                                                             183
                                             183
                                                             182
                                                     182
                                                             181
                                                             180
                                             180
                                                             179
                                                             178
                                                     178
                                                             177
                                                     177
                                                             176
                     176
                                                             175
                                                             174
                                                     174
                                                             173
                                                             172
                                             172
                                                             171
                                                     171
                                                             170
                                     170
                                                             169
                                                             168
                                                     168
                                                             167
                                                     167
                                                             166
                                             166
                                                             165
                                                             164
                                                     164
                                                             163
                                             163
                                                             162
                                                             161
                                                     161
                                                             160
                                                     160
                                                             159
                             159
                                                             158
                                                             157
                                                     157
                                                             156
                                                     156
                                                             155
                                                             154
                                             154
                                                             153
                                                             152
                                                     152
                                                             151
                                     151
                                                             150
                                                             149
                                                     149
                                                             148
                                             148
                                                             147
                                                             146
                                                     146
                                                             145
                                     145
                                                             144
                                                             143
                                                     143
                                                             142
                                                             141
                                             141
                                                             140
                                                             139
                                                     139
                                                             138
                                                     138
                                                             137
                                                             136
                                             136
                                                             135
                                                     135
                                                             134
                             134
                                                             133
                                                             132
                                                     132
                                                             131
                                                     131
                                                             130
                                                             129
                                             129
                                                             128
                                                             127
                                                     127
                                                             126
                                                     126
                                                             125
                                                             124
                                     124
                                                             123
                                                             122
                                                     122
                                                             121
                                             121
                                                             120
                                                     120
                                                             119
             119
                                                             118
                                                             117
                                                     117
                                                             116
                                                     116
                                                             115
                                             115
                                                             114
                                                             113
                                                     113
                                                             112
                                     112
                                                             111
                                                             110
                                                     110
                                                             109
                                                     109
                                                             108
                                             108
                                                             107
                                                             106
                                                     106
                                                             105
                                                     105
                                                             104
                             104
                                                             103
                                                             102
                                                     102
                                                             101
                                             101
                                                             100
                                                              99
                                                      99
                                                              98
                                                              97
                                      97
                                                              96
                                                              95
                                                      95
                                                              94
                                              94
                                                              93
                                                      93
                                                              92
                                                              91
                                                      91
                                                              90
                      90
                                                              89
                                                              88
                                                      88
                                                              87
                                              87
                                                              86
                                                      86
                                                              85
                                      85
                                                              84
                                                              83
                                                      83
                                                              82
                                              82
                                                              81
                                                              80
                                                      80
                                                              79
                                                              78
                              78
                                                              77
                                                              76
                                                      76
                                                              75
                                                              74
                                              74
                                                              73
                                                      73
                                                              72
                                      72
                                                              71
                                                      71
                                                              70
                                                              69
                                              69
                                                              68
                                                      68
                                                              67
                              67
                                                              66
                                                              65
                                                      65
                                                              64
                                              64
                                                              63
                                                              62
                                                      62
                                                              61
                                                      61
                                                              60
                                                              59
                                      59
                                                              58
                                                              57
                                                      57
                                                              56
                                              56
                                                              55
                                                      55
                                                              54
                      54
                                                              53
                                                              52
                                                      52
                                                              51
                                              51
                                                              50
                                                      50
                                                              49
                                                              48
                                              48
                                                              47
                                                              46
                                                      46
                                                              45
                                      45
                                                              44
                                                              43
                                                      43
                                                              42
                                              42
                                                              41
                                                              40
                                                      40
                                                              39
                              39
                                                              38
                                                              37
                                                      37
                                                              36
                                              36
                                                              35
                                                              34
                                                      34
                                                              33
                                      33
                                                              32
                                                              31
                                                      31
                                                              30
                                                              29
                                                      29
                                                              28
                                              28
                                                              27
                                                              26
                                                      26
                                                              25
                                                      25
                                                              24
                              24
                                                              23
                                                              22
                                                      22
                                                              21
                                                              20
                                              20
                                                              19
                                                      19
                                                              18
                                                              17
                                      17
                                                              16
                                                              15
                                                      15
                                                              14
                                                      14
                                                              13
                                              13
                                                              12
                                                              11
                                                      11
                                                              10
                                                               9
                                       9
                                                               8
                                                       8
                                                               7
                                                               6
                                               6
                                                               5
                                                       5
                                                               4
                                               4
                                                               3
                                                               2
                                                       2
                                                               1
                                                               0


========================================================
             732
     732
             569
569
             248
     248
             137

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 460 809 606 247 448 465 961 883 491 327 938 925 930 321 382 167 558 642 210 567 72 215 942 796 960 771 625 674 371 372 146 759 991 697 886 451 259 737 533 845 42 31 292 922 416 671 598 141 132 825 875 59 831 964 885 823 591 80 926 179 783 320 532 830 83 20 785 492 452 646 305 331 361 575 705 133 362 525 703 813 234 861 795 411 230 476 350 871 582 530 839 314 593 713 978 53 367 551 868 127 945 564 821 457 979 657 422 311 893 640 220 410 262 70 252 291 355 69 682 297 588 949 99 815 149 89 470 85 917 904 242 194 607 383 458 237 734 878 645 728 613 621 631 701 493 336 554 709 81 322 560 951 619 656 211 969 501 286 294 957 856 447 903 435 568 626 725 300 32 274 187 542 761 498 365 995 218 84 87 811 802 296 177 984 934 3 724 858 440 222 503 848 867 700 994 932 986 183 425 246 348 946 691 855 392 755 143 496 202 853 652 797 970 779 306 207 57 710 356 467 550 332 766 690 913 829 689 390 307 747 963 765 225 846 229 851 216 123 612 836 397 98 407 281 576 157 338 219 333 424 536 981 676 546 191 324 353 997 37 104 940 622 38 972 529 975 736 330 66 751 140 843 647 414 464 996 438 453 249 513 789 325 403 507 166 586 954 463 90 111 417 549 614 129 188 808 75 517 284 952 387 740 15 514 708 617 238 916 516 923 471 504 757 206 343 706 406 784 381 524 664 891 884 35 335 555 180 18 402 990 154 309 547 692 351 510 909 833 579 744 900 7 872 572 62 897 301 841 869 650 86 543 475 47 446 276 895 269 380 828 721 172 919 722 461 489 41 989 873 144 553 378 966 800 116 456 880 535 596 244 76 439 643 627 781 595 200 373 349 717 312 239 52 29 850 175 928 313 318 521 11 931 389 518 24 419 912 399 820 165 570 14 847 221 68 482 26 890 131 171 742 160 933 662 254 341 763 918 723 430 806 125 113 750 181 767 608 620 609 124 186 712 508 97 488 282 413 155 727 818 908 659 616 581 13 233 184 862 540 279 876 64 587 103 0 681 590 679 261 849 628 604 644 347 256 19 444 393 694 466 102 601 449 473 684 118 835 337 6 921 888 958 688 805 260 696 360 561 729 308 894 293 874 245 539 810 285 474 153 824 28 161 142 342 573 807 48 881 860 450 396 512 738 982 509 780 827 122 27 687 77 192 977 814 486 445 599 959 505 288 130 212 714 374 557 236 71 896 733 51 401 385 762 865 107 228 915 454 168 106 837 773 60 441 563 61 962 195 271 427 968 892 624 54 844 786 223 395 632 92 859 803 950 74 583 199 428 801 295 658 16 756 437 398 541 899 240 924 715 902 478 578 653 746 472 379 39 739 680 442 988 571 943 660 594 487 775 980 574 364 898 96 741 270 672 108 480 870 799 409 101 273 772 819 506 290 753 665 226 667 749 316 384 633 566 278 4 201 468 266 182 939 937 126 418 998 605 562 277 499 559 822 45 287 334 328 43 375 887 253 173 637 326 973 115 842 128 790 534 760 359 597 100 584 726 935 94 699 368 30 854 565 315 770 774 745 67 388 163 936 635 663 528 9 198 267 603 340 670 477 944 677 817 485 431 344 1 914 44 953 65 299 695 196 602 412 840 974 91 462 639 793 114 329 955 987 920 258 405 426 82 992 145 545 95 434 404 280 971 283 243 391 134 354 651 22 135 648 638 522 386 358 421 678 366 758 209 63 673 49 666 711 791 544 864 121 317 213 812 523 304 408 302 776 158 630 156 552 693 611 636 34 151 208 777 910 985 369 241 548 88 2 580 484 185 731 73 310 189 511 661 863 272 788 983 502 804 352 906 190 147 718 298 754 500 882 589 176 436 429 152 911 363 834 50 17 877 592 346 495 265 735 36 879 600 150 120 976 377 339 78 227 250 112 204 217 164 420 46 323 792 93 527 432 669 905 538 947 459 105 889 515 433 520 58 531 303 866 668 12 415 469 967 148 193 965 55 370 929 455 927 345 481 720 629 497 289 138 610 707 704 816 376 852 159 136 641 764 255 585 224 231 948 8 251 263 743 119 748 162 40 768 752 10 832 798 941 782 702 56 649 999 169 178 685 205 769 109 719 519 716 21 5 232 490 117 730 275 993 268 901 264 787 423 400 174 23 479 838 394 577 654 907 686 675 494 537 357 319 25 634 235 170 623 778 214 203 826 698 683 197 526 556 794 33 110 443 655 257 618 956 139 483 857 79 615   from: 515 702 33 626 4 258 677 780 8 9 255 357 176 979 604 182 564 277 311 19 316 542 652 119 24 104 434 788 28 129 23 382 210 108 993 99 36 875 134 170 944 97 553 334 530 45 440 941 48 31 218 610 186 571 54 55 260 785 101 631 902 923 156 446 428 985 342 565 682 853 724 520 618 394 783 475 435 67 78 462 480 366 770 742 703 383 514 347 203 234 960 463 744 384 670 32 886 159 98 566 454 269 587 577 174 887 497 27 396 112 285 969 964 503 215 115 116 294 804 243 402 319 321 263 166 647 126 821 388 160 864 721 756 535 660 151 697 822 981 643 43 360 180 17 819 253 364 171 85 751 71 421 498 154 957 712 317 236 835 307 961 666 483 839 5 375 377 305 149 669 636 851 172 540 595 175 359 177 696 934 412 472 584 72 459 185 304 148 188 607 222 747 133 102 575 899 673 197 569 877 796 437 758 904 800 205 94 207 199 547 271 211 793 233 214 114 581 192 678 433 926 896 332 942 200 293 579 718 228 447 444 915 997 861 820 592 351 841 1 327 913 855 948 322 244 245 380 13 356 789 867 524 558 947 490 965 932 973 266 976 408 523 262 484 201 651 601 191 120 64 343 895 47 11 390 655 240 121 779 279 764 616 282 865 485 776 286 594 811 719 157 762 299 2 314 570 296 284 920 274 300 301 715 501 181 911 306 621 411 309 346 143 885 313 118 591 135 272 318 187 894 555 275 323 545 809 76 658 971 596 423 937 315 671 663 335 190 777 613 842 3 526 759 950 325 345 513 292 585 349 350 692 308 353 456 355 771 90 358 489 141 361 598 634 846 733 586 379 728 541 84 729 521 415 688 707 992 891 874 512 477 86 900 422 93 247 386 799 51 754 574 407 392 80 295 395 339 588 280 977 163 391 465 110 628 405 410 882 227 892 705 859 735 986 131 373 773 929 925 419 82 803 844 931 424 805 216 436 916 202 328 893 862 605 290 704 593 644 438 250 338 474 849 128 988 445 953 532 92 42 83 352 452 324 552 557 65 457 458 778 504 283 333 385 956 686 297 790 103 933 29 917 649 528 439 249 831 624 478 169 7 615 537 162 399 397 991 441 367 39 837 491 77 493 968 469 496 674 66 246 132 567 561 451 276 583 668 507 921 509 505 511 59 193 376 632 884 517 471 519 238 372 522 924 96 25 883 687 798 495 546 167 602 533 534 466 609 717 538 464 736 312 510 638 374 261 906 500 548 488 220 943 958 767 398 270 730 723 740 400 701 251 508 922 124 543 936 755 348 212 852 479 231 18 208 600 259 568 840 73 972 387 223 939 265 918 22 727 792 952 291 455 573 61 487 710 224 590 665 41 637 152 833 254 46 12 278 189 146 467 289 611 109 551 791 654 817 165 122 619 620 183 622 62 6 494 978 745 404 58 630 685 641 336 95 807 563 774 267 639 935 37 642 998 629 527 213 225 330 812 650 823 431 847 414 818 406 657 105 967 35 974 662 232 664 945 863 667 30 442 782 164 672 580 963 675 79 765 50 711 56 393 989 230 684 0 145 990 659 310 179 173 91 901 468 331 689 760 75 914 709 239 449 578 970 125 706 739 337 599 951 982 940 221 147 302 138 113 996 26 720 694 810 603 825 725 726 734 14 371 743 955 136 365 443 984 907 161 910 870 645 150 429 623 344 806 89 217 748 749 750 506 752 470 635 363 897 690 680 492 928 60 219 763 909 273 298 930 656 769 420 633 127 461 646 775 808 326 155 425 695 781 903 617 69 560 786 229 341 741 482 123 525 866 368 795 362 797 683 912 908 801 802 761 287 860 737 248 708 370 829 868 784 813 481 815 816 140 556 486 409 845 983 226 256 814 826 827 378 63 830 196 832 536 74 450 836 57 838 340 87 281 499 44 757 430 194 460 329 559 597 264 53 40 854 824 856 531 772 828 10 49 544 88 834 699 995 38 608 987 142 871 872 873 975 653 876 679 878 879 691 676 178 15 529 34 848 389 582 100 890 889 700 257 320 354 713 539 898 130 473 20 549 476 401 550 369 16 716 954 68 413 905 417 268 572 999 453 426 919 766 843 237 448 416 418 722 153 980 117 107 612 427 627 303 768 681 562 106 858 518 738 242 381 606 693 946 70 753 949 209 576 589 403 206 432 640 888 252 959 938 857 962 746 787 794 966 184 502 111 554 731 614 235 661 881 994 198 625 288 927 714 850 137 648 732 158 869 241 168 139 144 698 516 880 21 204 52 195 81
  REMOVING [569]
========================================================
996 of 1000
========================================================
     732
732
     248
248
     137

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 460 809 606 247 448 465 961 883 491 327 938 925 930 321 382 167 558 642 210 567 72 215 942 796 960 771 625 674 371 372 146 759 991 697 886 451 259 737 533 845 42 31 292 922 416 671 598 141 132 825 875 59 831 964 885 823 591 80 926 179 783 320 532 830 83 20 785 492 452 646 305 331 361 575 705 133 362 525 703 813 234 861 795 411 230 476 350 871 582 530 839 314 593 713 978 53 367 551 868 127 945 564 821 457 979 657 422 311 893 640 220 410 262 70 252 291 355 69 682 297 588 949 99 815 149 89 470 85 917 904 242 194 607 383 458 237 734 878 645 728 613 621 631 701 493 336 554 709 81 322 560 951 619 656 211 969 501 286 294 957 856 447 903 435 568 626 725 300 32 274 187 542 761 498 365 995 218 84 87 811 802 296 177 984 934 3 724 858 440 222 503 848 867 700 994 932 986 183 425 246 348 946 691 855 392 755 143 496 202 853 652 797 970 779 306 207 57 710 356 467 550 332 766 690 913 829 689 390 307 747 963 765 225 846 229 851 216 123 612 836 397 98 407 281 576 157 338 219 333 424 536 981 676 546 191 324 353 997 37 104 940 622 38 972 529 975 736 330 66 751 140 843 647 414 464 996 438 453 249 513 789 325 403 507 166 586 954 463 90 111 417 549 614 129 188 808 75 517 284 952 387 740 15 514 708 617 238 916 516 923 471 504 757 206 343 706 406 784 381 524 664 891 884 35 335 555 180 18 402 990 154 309 547 692 351 510 909 833 579 744 900 7 872 572 62 897 301 841 869 650 86 543 475 47 446 276 895 269 380 828 721 172 919 722 461 489 41 989 873 144 553 378 966 800 116 456 880 535 596 244 76 439 643 627 781 595 200 373 349 717 312 239 52 29 850 175 928 313 318 521 11 931 389 518 24 419 912 399 820 165 570 14 847 221 68 482 26 890 131 171 742 160 933 662 254 341 763 918 723 430 806 125 113 750 181 767 608 620 609 124 186 712 508 97 488 282 413 155 727 818 908 659 616 581 13 233 184 862 540 279 876 64 587 103 0 681 590 679 261 849 628 604 644 347 256 19 444 393 694 466 102 601 449 473 684 118 835 337 6 921 888 958 688 805 260 696 360 561 729 308 894 293 874 245 539 810 285 474 153 824 28 161 142 342 573 807 48 881 860 450 396 512 738 982 509 780 827 122 27 687 77 192 977 814 486 445 599 959 505 288 130 212 714 374 557 236 71 896 733 51 401 385 762 865 107 228 915 454 168 106 837 773 60 441 563 61 962 195 271 427 968 892 624 54 844 786 223 395 632 92 859 803 950 74 583 199 428 801 295 658 16 756 437 398 541 899 240 924 715 902 478 578 653 746 472 379 39 739 680 442 988 571 943 660 594 487 775 980 574 364 898 96 741 270 672 108 480 870 799 409 101 273 772 819 506 290 753 665 226 667 749 316 384 633 566 278 4 201 468 266 182 939 937 126 418 998 605 562 277 499 559 822 45 287 334 328 43 375 887 253 173 637 326 973 115 842 128 790 534 760 359 597 100 584 726 935 94 699 368 30 854 565 315 770 774 745 67 388 163 936 635 663 528 9 198 267 603 340 670 477 944 677 817 485 431 344 1 914 44 953 65 299 695 196 602 412 840 974 91 462 639 793 114 329 955 987 920 258 405 426 82 992 145 545 95 434 404 280 971 283 243 391 134 354 651 22 135 648 638 522 386 358 421 678 366 758 209 63 673 49 666 711 791 544 864 121 317 213 812 523 304 408 302 776 158 630 156 552 693 611 636 34 151 208 777 910 985 369 241 548 88 2 580 484 185 731 73 310 189 511 661 863 272 788 983 502 804 352 906 190 147 718 298 754 500 882 589 176 436 429 152 911 363 834 50 17 877 592 346 495 265 735 36 879 600 150 120 976 377 339 78 227 250 112 204 217 164 420 46 323 792 93 527 432 669 905 538 947 459 105 889 515 433 520 58 531 303 866 668 12 415 469 967 148 193 965 55 370 929 455 927 345 481 720 629 497 289 138 610 707 704 816 376 852 159 136 641 764 255 585 224 231 948 8 251 263 743 119 748 162 40 768 752 10 832 798 941 782 702 56 649 999 169 178 685 205 769 109 719 519 716 21 5 232 490 117 730 275 993 268 901 264 787 423 400 174 23 479 838 394 577 654 907 686 675 494 537 357 319 25 634 235 170 623 778 214 203 826 698 683 197 526 556 794 33 110 443 655 257 618 956 139 483 857 79 615 569   from: 515 702 33 626 4 258 677 780 8 9 255 357 176 979 604 182 564 277 311 19 316 542 652 119 24 104 434 788 28 129 23 382 210 108 993 99 36 875 134 170 944 97 553 334 530 45 440 941 48 31 218 610 186 571 54 55 260 785 101 631 902 923 156 446 428 985 342 565 682 853 724 520 618 394 783 475 435 67 78 462 480 366 770 742 703 383 514 347 203 234 960 463 744 384 670 32 886 159 98 566 454 269 587 577 174 887 497 27 396 112 285 969 964 503 215 115 116 294 804 243 402 319 321 263 166 647 126 821 388 160 864 721 756 535 660 151 697 822 981 643 43 360 180 17 819 253 364 171 85 751 71 421 498 154 957 712 317 236 835 307 961 666 483 839 5 375 377 305 149 669 636 851 172 540 595 175 359 177 696 934 412 472 584 72 459 185 304 148 188 607 222 747 133 102 575 899 673 197 569 877 796 437 758 904 800 205 94 207 199 547 271 211 793 233 214 114 581 192 678 433 926 896 332 942 200 293 579 718 228 447 444 915 997 861 820 592 351 841 1 327 913 855 948 322 244 245 380 13 356 789 867 524 558 947 490 965 932 973 266 976 408 523 262 484 201 651 601 191 120 64 343 895 47 11 390 655 240 121 779 279 764 616 282 865 485 776 286 594 811 719 157 762 299 2 314 570 296 284 920 274 300 301 715 501 181 911 306 621 411 309 346 143 885 313 118 591 135 272 318 187 894 555 275 323 545 809 76 658 971 596 423 937 315 671 663 335 190 777 613 842 3 526 759 950 325 345 513 292 585 349 350 692 308 353 456 355 771 90 358 489 141 361 598 634 846 733 586 379 728 541 84 729 521 415 688 707 992 891 874 512 477 86 900 422 93 247 386 799 51 754 574 407 392 80 295 395 339 588 280 977 163 391 465 110 628 405 410 882 227 892 705 859 735 986 131 373 773 929 925 419 82 803 844 931 424 805 216 436 916 202 328 893 862 605 290 704 593 644 438 250 338 474 849 128 988 445 953 532 92 42 83 352 452 324 552 557 65 457 458 778 504 283 333 385 956 686 297 790 103 933 29 917 649 528 439 249 831 624 478 169 7 615 537 162 399 397 991 441 367 39 837 491 77 493 968 469 496 674 66 246 132 567 561 451 276 583 668 507 921 509 505 511 59 193 376 632 884 517 471 519 238 372 522 924 96 25 883 687 798 495 546 167 602 533 534 466 609 717 538 464 736 312 510 638 374 261 906 500 548 488 220 943 958 767 398 270 730 723 740 400 701 251 508 922 124 543 936 755 348 212 852 479 231 18 208 600 259 568 840 73 972 387 223 939 265 918 22 727 792 952 291 455 573 61 487 710 224 590 665 41 637 152 833 254 46 12 278 189 146 467 289 611 109 551 791 654 817 165 122 619 620 183 622 62 6 494 978 745 404 58 630 685 641 336 95 807 563 774 267 639 935 37 642 998 629 527 213 225 330 812 650 823 431 847 414 818 406 657 105 967 35 974 662 232 664 945 863 667 30 442 782 164 672 580 963 675 79 765 50 711 56 393 989 230 684 0 145 990 659 310 179 173 91 901 468 331 689 760 75 914 709 239 449 578 970 125 706 739 337 599 951 982 940 221 147 302 138 113 996 26 720 694 810 603 825 725 726 734 14 371 743 955 136 365 443 984 907 161 910 870 645 150 429 623 344 806 89 217 748 749 750 506 752 470 635 363 897 690 680 492 928 60 219 763 909 273 298 930 656 769 420 633 127 461 646 775 808 326 155 425 695 781 903 617 69 560 786 229 341 741 482 123 525 866 368 795 362 797 683 912 908 801 802 761 287 860 737 248 708 370 829 868 784 813 481 815 816 140 556 486 409 845 983 226 256 814 826 827 378 63 830 196 832 536 74 450 836 57 838 340 87 281 499 44 757 430 194 460 329 559 597 264 53 40 854 824 856 531 772 828 10 49 544 88 834 699 995 38 608 987 142 871 872 873 975 653 876 679 878 879 691 676 178 15 529 34 848 389 582 100 890 889 700 257 320 354 713 539 898 130 473 20 549 476 401 550 369 16 716 954 68 413 905 417 268 572 999 453 426 919 766 843 237 448 416 418 722 153 980 117 107 612 427 627 303 768 681 562 106 858 518 738 242 381 606 693 946 70 753 949 209 576 589 403 206 432 640 888 252 959 938 857 962 746 787 794 966 184 502 111 554 731 614 235 661 881 994 198 625 288 927 714 850 137 648 732 158 869 241 168 139 144 698 516 880 21 204 52 195 81
  REMOVING [137]
========================================================
997 of 1000
========================================================
     732
732
     248

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 460 809 606 247 448 465 961 883 491 327 938 925 930 321 382 167 558 642 210 567 72 215 942 796 960 771 625 674 371 372 146 759 991 697 886 451 259 737 533 845 42 31 292 922 416 671 598 141 132 825 875 59 831 964 885 823 591 80 926 179 783 320 532 830 83 20 785 492 452 646 305 331 361 575 705 133 362 525 703 813 234 861 795 411 230 476 350 871 582 530 839 314 593 713 978 53 367 551 868 127 945 564 821 457 979 657 422 311 893 640 220 410 262 70 252 291 355 69 682 297 588 949 99 815 149 89 470 85 917 904 242 194 607 383 458 237 734 878 645 728 613 621 631 701 493 336 554 709 81 322 560 951 619 656 211 969 501 286 294 957 856 447 903 435 568 626 725 300 32 274 187 542 761 498 365 995 218 84 87 811 802 296 177 984 934 3 724 858 440 222 503 848 867 700 994 932 986 183 425 246 348 946 691 855 392 755 143 496 202 853 652 797 970 779 306 207 57 710 356 467 550 332 766 690 913 829 689 390 307 747 963 765 225 846 229 851 216 123 612 836 397 98 407 281 576 157 338 219 333 424 536 981 676 546 191 324 353 997 37 104 940 622 38 972 529 975 736 330 66 751 140 843 647 414 464 996 438 453 249 513 789 325 403 507 166 586 954 463 90 111 417 549 614 129 188 808 75 517 284 952 387 740 15 514 708 617 238 916 516 923 471 504 757 206 343 706 406 784 381 524 664 891 884 35 335 555 180 18 402 990 154 309 547 692 351 510 909 833 579 744 900 7 872 572 62 897 301 841 869 650 86 543 475 47 446 276 895 269 380 828 721 172 919 722 461 489 41 989 873 144 553 378 966 800 116 456 880 535 596 244 76 439 643 627 781 595 200 373 349 717 312 239 52 29 850 175 928 313 318 521 11 931 389 518 24 419 912 399 820 165 570 14 847 221 68 482 26 890 131 171 742 160 933 662 254 341 763 918 723 430 806 125 113 750 181 767 608 620 609 124 186 712 508 97 488 282 413 155 727 818 908 659 616 581 13 233 184 862 540 279 876 64 587 103 0 681 590 679 261 849 628 604 644 347 256 19 444 393 694 466 102 601 449 473 684 118 835 337 6 921 888 958 688 805 260 696 360 561 729 308 894 293 874 245 539 810 285 474 153 824 28 161 142 342 573 807 48 881 860 450 396 512 738 982 509 780 827 122 27 687 77 192 977 814 486 445 599 959 505 288 130 212 714 374 557 236 71 896 733 51 401 385 762 865 107 228 915 454 168 106 837 773 60 441 563 61 962 195 271 427 968 892 624 54 844 786 223 395 632 92 859 803 950 74 583 199 428 801 295 658 16 756 437 398 541 899 240 924 715 902 478 578 653 746 472 379 39 739 680 442 988 571 943 660 594 487 775 980 574 364 898 96 741 270 672 108 480 870 799 409 101 273 772 819 506 290 753 665 226 667 749 316 384 633 566 278 4 201 468 266 182 939 937 126 418 998 605 562 277 499 559 822 45 287 334 328 43 375 887 253 173 637 326 973 115 842 128 790 534 760 359 597 100 584 726 935 94 699 368 30 854 565 315 770 774 745 67 388 163 936 635 663 528 9 198 267 603 340 670 477 944 677 817 485 431 344 1 914 44 953 65 299 695 196 602 412 840 974 91 462 639 793 114 329 955 987 920 258 405 426 82 992 145 545 95 434 404 280 971 283 243 391 134 354 651 22 135 648 638 522 386 358 421 678 366 758 209 63 673 49 666 711 791 544 864 121 317 213 812 523 304 408 302 776 158 630 156 552 693 611 636 34 151 208 777 910 985 369 241 548 88 2 580 484 185 731 73 310 189 511 661 863 272 788 983 502 804 352 906 190 147 718 298 754 500 882 589 176 436 429 152 911 363 834 50 17 877 592 346 495 265 735 36 879 600 150 120 976 377 339 78 227 250 112 204 217 164 420 46 323 792 93 527 432 669 905 538 947 459 105 889 515 433 520 58 531 303 866 668 12 415 469 967 148 193 965 55 370 929 455 927 345 481 720 629 497 289 138 610 707 704 816 376 852 159 136 641 764 255 585 224 231 948 8 251 263 743 119 748 162 40 768 752 10 832 798 941 782 702 56 649 999 169 178 685 205 769 109 719 519 716 21 5 232 490 117 730 275 993 268 901 264 787 423 400 174 23 479 838 394 577 654 907 686 675 494 537 357 319 25 634 235 170 623 778 214 203 826 698 683 197 526 556 794 33 110 443 655 257 618 956 139 483 857 79 615 569 137   from: 515 702 33 626 4 258 677 780 8 9 255 357 176 979 604 182 564 277 311 19 316 542 652 119 24 104 434 788 28 129 23 382 210 108 993 99 36 875 134 170 944 97 553 334 530 45 440 941 48 31 218 610 186 571 54 55 260 785 101 631 902 923 156 446 428 985 342 565 682 853 724 520 618 394 783 475 435 67 78 462 480 366 770 742 703 383 514 347 203 234 960 463 744 384 670 32 886 159 98 566 454 269 587 577 174 887 497 27 396 112 285 969 964 503 215 115 116 294 804 243 402 319 321 263 166 647 126 821 388 160 864 721 756 535 660 151 697 822 981 643 43 360 180 17 819 253 364 171 85 751 71 421 498 154 957 712 317 236 835 307 961 666 483 839 5 375 377 305 149 669 636 851 172 540 595 175 359 177 696 934 412 472 584 72 459 185 304 148 188 607 222 747 133 102 575 899 673 197 569 877 796 437 758 904 800 205 94 207 199 547 271 211 793 233 214 114 581 192 678 433 926 896 332 942 200 293 579 718 228 447 444 915 997 861 820 592 351 841 1 327 913 855 948 322 244 245 380 13 356 789 867 524 558 947 490 965 932 973 266 976 408 523 262 484 201 651 601 191 120 64 343 895 47 11 390 655 240 121 779 279 764 616 282 865 485 776 286 594 811 719 157 762 299 2 314 570 296 284 920 274 300 301 715 501 181 911 306 621 411 309 346 143 885 313 118 591 135 272 318 187 894 555 275 323 545 809 76 658 971 596 423 937 315 671 663 335 190 777 613 842 3 526 759 950 325 345 513 292 585 349 350 692 308 353 456 355 771 90 358 489 141 361 598 634 846 733 586 379 728 541 84 729 521 415 688 707 992 891 874 512 477 86 900 422 93 247 386 799 51 754 574 407 392 80 295 395 339 588 280 977 163 391 465 110 628 405 410 882 227 892 705 859 735 986 131 373 773 929 925 419 82 803 844 931 424 805 216 436 916 202 328 893 862 605 290 704 593 644 438 250 338 474 849 128 988 445 953 532 92 42 83 352 452 324 552 557 65 457 458 778 504 283 333 385 956 686 297 790 103 933 29 917 649 528 439 249 831 624 478 169 7 615 537 162 399 397 991 441 367 39 837 491 77 493 968 469 496 674 66 246 132 567 561 451 276 583 668 507 921 509 505 511 59 193 376 632 884 517 471 519 238 372 522 924 96 25 883 687 798 495 546 167 602 533 534 466 609 717 538 464 736 312 510 638 374 261 906 500 548 488 220 943 958 767 398 270 730 723 740 400 701 251 508 922 124 543 936 755 348 212 852 479 231 18 208 600 259 568 840 73 972 387 223 939 265 918 22 727 792 952 291 455 573 61 487 710 224 590 665 41 637 152 833 254 46 12 278 189 146 467 289 611 109 551 791 654 817 165 122 619 620 183 622 62 6 494 978 745 404 58 630 685 641 336 95 807 563 774 267 639 935 37 642 998 629 527 213 225 330 812 650 823 431 847 414 818 406 657 105 967 35 974 662 232 664 945 863 667 30 442 782 164 672 580 963 675 79 765 50 711 56 393 989 230 684 0 145 990 659 310 179 173 91 901 468 331 689 760 75 914 709 239 449 578 970 125 706 739 337 599 951 982 940 221 147 302 138 113 996 26 720 694 810 603 825 725 726 734 14 371 743 955 136 365 443 984 907 161 910 870 645 150 429 623 344 806 89 217 748 749 750 506 752 470 635 363 897 690 680 492 928 60 219 763 909 273 298 930 656 769 420 633 127 461 646 775 808 326 155 425 695 781 903 617 69 560 786 229 341 741 482 123 525 866 368 795 362 797 683 912 908 801 802 761 287 860 737 248 708 370 829 868 784 813 481 815 816 140 556 486 409 845 983 226 256 814 826 827 378 63 830 196 832 536 74 450 836 57 838 340 87 281 499 44 757 430 194 460 329 559 597 264 53 40 854 824 856 531 772 828 10 49 544 88 834 699 995 38 608 987 142 871 872 873 975 653 876 679 878 879 691 676 178 15 529 34 848 389 582 100 890 889 700 257 320 354 713 539 898 130 473 20 549 476 401 550 369 16 716 954 68 413 905 417 268 572 999 453 426 919 766 843 237 448 416 418 722 153 980 117 107 612 427 627 303 768 681 562 106 858 518 738 242 381 606 693 946 70 753 949 209 576 589 403 206 432 640 888 252 959 938 857 962 746 787 794 966 184 502 111 554 731 614 235 661 881 994 198 625 288 927 714 850 137 648 732 158 869 241 168 139 144 698 516 880 21 204 52 195 81
  REMOVING [732]
========================================================
998 of 1000
========================================================
248

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 460 809 606 247 448 465 961 883 491 327 938 925 930 321 382 167 558 642 210 567 72 215 942 796 960 771 625 674 371 372 146 759 991 697 886 451 259 737 533 845 42 31 292 922 416 671 598 141 132 825 875 59 831 964 885 823 591 80 926 179 783 320 532 830 83 20 785 492 452 646 305 331 361 575 705 133 362 525 703 813 234 861 795 411 230 476 350 871 582 530 839 314 593 713 978 53 367 551 868 127 945 564 821 457 979 657 422 311 893 640 220 410 262 70 252 291 355 69 682 297 588 949 99 815 149 89 470 85 917 904 242 194 607 383 458 237 734 878 645 728 613 621 631 701 493 336 554 709 81 322 560 951 619 656 211 969 501 286 294 957 856 447 903 435 568 626 725 300 32 274 187 542 761 498 365 995 218 84 87 811 802 296 177 984 934 3 724 858 440 222 503 848 867 700 994 932 986 183 425 246 348 946 691 855 392 755 143 496 202 853 652 797 970 779 306 207 57 710 356 467 550 332 766 690 913 829 689 390 307 747 963 765 225 846 229 851 216 123 612 836 397 98 407 281 576 157 338 219 333 424 536 981 676 546 191 324 353 997 37 104 940 622 38 972 529 975 736 330 66 751 140 843 647 414 464 996 438 453 249 513 789 325 403 507 166 586 954 463 90 111 417 549 614 129 188 808 75 517 284 952 387 740 15 514 708 617 238 916 516 923 471 504 757 206 343 706 406 784 381 524 664 891 884 35 335 555 180 18 402 990 154 309 547 692 351 510 909 833 579 744 900 7 872 572 62 897 301 841 869 650 86 543 475 47 446 276 895 269 380 828 721 172 919 722 461 489 41 989 873 144 553 378 966 800 116 456 880 535 596 244 76 439 643 627 781 595 200 373 349 717 312 239 52 29 850 175 928 313 318 521 11 931 389 518 24 419 912 399 820 165 570 14 847 221 68 482 26 890 131 171 742 160 933 662 254 341 763 918 723 430 806 125 113 750 181 767 608 620 609 124 186 712 508 97 488 282 413 155 727 818 908 659 616 581 13 233 184 862 540 279 876 64 587 103 0 681 590 679 261 849 628 604 644 347 256 19 444 393 694 466 102 601 449 473 684 118 835 337 6 921 888 958 688 805 260 696 360 561 729 308 894 293 874 245 539 810 285 474 153 824 28 161 142 342 573 807 48 881 860 450 396 512 738 982 509 780 827 122 27 687 77 192 977 814 486 445 599 959 505 288 130 212 714 374 557 236 71 896 733 51 401 385 762 865 107 228 915 454 168 106 837 773 60 441 563 61 962 195 271 427 968 892 624 54 844 786 223 395 632 92 859 803 950 74 583 199 428 801 295 658 16 756 437 398 541 899 240 924 715 902 478 578 653 746 472 379 39 739 680 442 988 571 943 660 594 487 775 980 574 364 898 96 741 270 672 108 480 870 799 409 101 273 772 819 506 290 753 665 226 667 749 316 384 633 566 278 4 201 468 266 182 939 937 126 418 998 605 562 277 499 559 822 45 287 334 328 43 375 887 253 173 637 326 973 115 842 128 790 534 760 359 597 100 584 726 935 94 699 368 30 854 565 315 770 774 745 67 388 163 936 635 663 528 9 198 267 603 340 670 477 944 677 817 485 431 344 1 914 44 953 65 299 695 196 602 412 840 974 91 462 639 793 114 329 955 987 920 258 405 426 82 992 145 545 95 434 404 280 971 283 243 391 134 354 651 22 135 648 638 522 386 358 421 678 366 758 209 63 673 49 666 711 791 544 864 121 317 213 812 523 304 408 302 776 158 630 156 552 693 611 636 34 151 208 777 910 985 369 241 548 88 2 580 484 185 731 73 310 189 511 661 863 272 788 983 502 804 352 906 190 147 718 298 754 500 882 589 176 436 429 152 911 363 834 50 17 877 592 346 495 265 735 36 879 600 150 120 976 377 339 78 227 250 112 204 217 164 420 46 323 792 93 527 432 669 905 538 947 459 105 889 515 433 520 58 531 303 866 668 12 415 469 967 148 193 965 55 370 929 455 927 345 481 720 629 497 289 138 610 707 704 816 376 852 159 136 641 764 255 585 224 231 948 8 251 263 743 119 748 162 40 768 752 10 832 798 941 782 702 56 649 999 169 178 685 205 769 109 719 519 716 21 5 232 490 117 730 275 993 268 901 264 787 423 400 174 23 479 838 394 577 654 907 686 675 494 537 357 319 25 634 235 170 623 778 214 203 826 698 683 197 526 556 794 33 110 443 655 257 618 956 139 483 857 79 615 569 137 732   from: 515 702 33 626 4 258 677 780 8 9 255 357 176 979 604 182 564 277 311 19 316 542 652 119 24 104 434 788 28 129 23 382 210 108 993 99 36 875 134 170 944 97 553 334 530 45 440 941 48 31 218 610 186 571 54 55 260 785 101 631 902 923 156 446 428 985 342 565 682 853 724 520 618 394 783 475 435 67 78 462 480 366 770 742 703 383 514 347 203 234 960 463 744 384 670 32 886 159 98 566 454 269 587 577 174 887 497 27 396 112 285 969 964 503 215 115 116 294 804 243 402 319 321 263 166 647 126 821 388 160 864 721 756 535 660 151 697 822 981 643 43 360 180 17 819 253 364 171 85 751 71 421 498 154 957 712 317 236 835 307 961 666 483 839 5 375 377 305 149 669 636 851 172 540 595 175 359 177 696 934 412 472 584 72 459 185 304 148 188 607 222 747 133 102 575 899 673 197 569 877 796 437 758 904 800 205 94 207 199 547 271 211 793 233 214 114 581 192 678 433 926 896 332 942 200 293 579 718 228 447 444 915 997 861 820 592 351 841 1 327 913 855 948 322 244 245 380 13 356 789 867 524 558 947 490 965 932 973 266 976 408 523 262 484 201 651 601 191 120 64 343 895 47 11 390 655 240 121 779 279 764 616 282 865 485 776 286 594 811 719 157 762 299 2 314 570 296 284 920 274 300 301 715 501 181 911 306 621 411 309 346 143 885 313 118 591 135 272 318 187 894 555 275 323 545 809 76 658 971 596 423 937 315 671 663 335 190 777 613 842 3 526 759 950 325 345 513 292 585 349 350 692 308 353 456 355 771 90 358 489 141 361 598 634 846 733 586 379 728 541 84 729 521 415 688 707 992 891 874 512 477 86 900 422 93 247 386 799 51 754 574 407 392 80 295 395 339 588 280 977 163 391 465 110 628 405 410 882 227 892 705 859 735 986 131 373 773 929 925 419 82 803 844 931 424 805 216 436 916 202 328 893 862 605 290 704 593 644 438 250 338 474 849 128 988 445 953 532 92 42 83 352 452 324 552 557 65 457 458 778 504 283 333 385 956 686 297 790 103 933 29 917 649 528 439 249 831 624 478 169 7 615 537 162 399 397 991 441 367 39 837 491 77 493 968 469 496 674 66 246 132 567 561 451 276 583 668 507 921 509 505 511 59 193 376 632 884 517 471 519 238 372 522 924 96 25 883 687 798 495 546 167 602 533 534 466 609 717 538 464 736 312 510 638 374 261 906 500 548 488 220 943 958 767 398 270 730 723 740 400 701 251 508 922 124 543 936 755 348 212 852 479 231 18 208 600 259 568 840 73 972 387 223 939 265 918 22 727 792 952 291 455 573 61 487 710 224 590 665 41 637 152 833 254 46 12 278 189 146 467 289 611 109 551 791 654 817 165 122 619 620 183 622 62 6 494 978 745 404 58 630 685 641 336 95 807 563 774 267 639 935 37 642 998 629 527 213 225 330 812 650 823 431 847 414 818 406 657 105 967 35 974 662 232 664 945 863 667 30 442 782 164 672 580 963 675 79 765 50 711 56 393 989 230 684 0 145 990 659 310 179 173 91 901 468 331 689 760 75 914 709 239 449 578 970 125 706 739 337 599 951 982 940 221 147 302 138 113 996 26 720 694 810 603 825 725 726 734 14 371 743 955 136 365 443 984 907 161 910 870 645 150 429 623 344 806 89 217 748 749 750 506 752 470 635 363 897 690 680 492 928 60 219 763 909 273 298 930 656 769 420 633 127 461 646 775 808 326 155 425 695 781 903 617 69 560 786 229 341 741 482 123 525 866 368 795 362 797 683 912 908 801 802 761 287 860 737 248 708 370 829 868 784 813 481 815 816 140 556 486 409 845 983 226 256 814 826 827 378 63 830 196 832 536 74 450 836 57 838 340 87 281 499 44 757 430 194 460 329 559 597 264 53 40 854 824 856 531 772 828 10 49 544 88 834 699 995 38 608 987 142 871 872 873 975 653 876 679 878 879 691 676 178 15 529 34 848 389 582 100 890 889 700 257 320 354 713 539 898 130 473 20 549 476 401 550 369 16 716 954 68 413 905 417 268 572 999 453 426 919 766 843 237 448 416 418 722 153 980 117 107 612 427 627 303 768 681 562 106 858 518 738 242 381 606 693 946 70 753 949 209 576 589 403 206 432 640 888 252 959 938 857 962 746 787 794 966 184 502 111 554 731 614 235 661 881 994 198 625 288 927 714 850 137 648 732 158 869 241 168 139 144 698 516 880 21 204 52 195 81
  REMOVING [248]
========================================================
999 of 1000
 V A L I D    T R E E
*********************************************************
 T E S T:    97
*********************************************************
========================================================

========================================================
                                                             999
                                                             998
                                                     998
                                                             997
                                                     997
                                                             996
                                                             995
                                             995
                                                             994
                                                             993
                                                     993
                                                             992
                                                             991
                                             991
                                                             990
                                                             989
                                                     989
                                                             988
                                                     988
                                                             987
                                     987
                                                             986
                                                             985
                                                     985
                                                             984
                                             984
                                                             983
                                                     983
                                                             982
                                                             981
                                     981
                                                             980
                                                     980
                                                             979
                                                             978
                                                     978
                                                             977
                                             977
                                                             976
                                                     976
                                                             975
                             975
                                                             974
                                                             973
                                                     973
                                                             972
                                                             971
                                             971
                                                             970
                                                             969
                                                     969
                                                             968
                                     968
                                                             967
                                                     967
                                                             966
                                             966
                                                             965
                                                             964
                                                     964
                                                             963
                                                     963
                                                             962
                             962
                                                             961
                                                             960
                                                     960
                                                             959
                                                             958
                                                     958
                                                             957
                                             957
                                                             956
                                                             955
                                                     955
                                                             954
                                                     954
                                                             953
                                             953
                                                             952
                                                     952
                                                             951
                                     951
                                                             950
                                                             949
                                                     949
                                                             948
                                             948
                                                             947
                                                     947
                                                             946
                                                             945
                                             945
                                                             944
                                                             943
                                                     943
                                                             942
                                                     942
                                                             941
                                                             940
                     940
                                                             939
                                                             938
                                                     938
                                                             937
                                                             936
                                                     936
                                                             935
                                                             934
                                             934
                                                             933
                                                             932
                                                     932
                                                             931
                                             931
                                                             930
                                                             929
                                                     929
                                                             928
                                     928
                                                             927
                                                             926
                                                     926
                                                             925
                                             925
                                                             924
                                                             923
                                                     923
                                                             922
                                                     922
                                                             921
                                                             920
                             920
                                                             919
                                                             918
                                                     918
                                                             917
                                                     917
                                                             916
                                             916
                                                             915
                                                     915
                                                             914
                                     914
                                                             913
                                                             912
                                                     912
                                                             911
                                             911
                                                             910
                                                             909
                                                     909
                                                             908
                                             908
                                                             907
                                                             906
                                                     906
                                                             905
                                                             904
                                                     904
                                                             903
                     903
                                                             902
                                                             901
                                                     901
                                                             900
                                                     900
                                                             899
                                             899
                                                             898
                                                     898
                                                             897
                                                             896
                                                     896
                                                             895
                                             895
                                                             894
                                                     894
                                                             893
                                     893
                                                             892
                                                             891
                                                     891
                                                             890
                                                     890
                                                             889
                                                             888
                                             888
                                                             887
                                                             886
                                                     886
                                                             885
                                                             884
                             884
                                                             883
                                                             882
                                                     882
                                                             881
                                             881
                                                             880
                                                             879
                                                     879
                                                             878
                                                             877
                                     877
                                                             876
                                                             875
                                                     875
                                                             874
                                             874
                                                             873
                                                     873
                                                             872
             872
                                                             871
                                                             870
                                                     870
                                                             869
                                                             868
                                             868
                                                             867
                                                             866
                                                     866
                                                             865
                                             865
                                                             864
                                                             863
                                                     863
                                                             862
                                     862
                                                             861
                                                     861
                                                             860
                                                             859
                                             859
                                                             858
                                                             857
                                                     857
                                                             856
                                                             855
                             855
                                                             854
                                                             853
                                                     853
                                                             852
                                                             851
                                             851
                                                             850
                                                     850
                                                             849
                                     849
                                                             848
                                                             847
                                                     847
                                                             846
                                                             845
                                                     845
                                                             844
                                             844
                                                             843
                                                     843
                                                             842
                             842
                                                             841
                                                             840
                                                     840
                                                             839
                                             839
                                                             838
                                                             837
                                                     837
                                                             836
                                             836
                                                             835
                                                             834
                                                     834
                                                             833
                                                             832
                                     832
                                                             831
                                                             830
                                                     830
                                                             829
                                             829
                                                             828
                                                             827
                                                     827
                                                             826
                                                             825
                                     825
                                                             824
                                                             823
                                                     823
                                                             822
                                             822
                                                             821
                                                             820
                                                     820
                                                             819
                                                             818
                     818
                                                             817
                                                             816
                                                     816
                                                             815
                                             815
                                                             814
                                                             813
                                                     813
                                                             812
                                             812
                                                             811
                                                             810
                                                     810
                                                             809
                                     809
                                                             808
                                                             807
                                                     807
                                                             806
                                                     806
                                                             805
                                             805
                                                             804
                                                             803
                                                     803
                                                             802
                                                             801
                                                     801
                                                             800
                             800
                                                             799
                                                             798
                                                     798
                                                             797
                                             797
                                                             796
                                                             795
                                                     795
                                                             794
                                     794
                                                             793
                                                     793
                                                             792
                                                             791
                                             791
                                                             790
                                                     790
                                                             789
                                                             788
                                                     788
                                                             787
                             787
                                                             786
                                                             785
                                                     785
                                                             784
                                             784
                                                             783
                                                     783
                                                             782
                                                             781
                                     781
                                                             780
                                                             779
                                                     779
                                                             778
                                                             777
                                                     777
                                                             776
                                             776
                                                             775
                                                     775
                                                             774
                                     774
                                                             773
                                                             772
                                                     772
                                                             771
                                             771
                                                             770
                                                             769
                                                     769
                                                             768
                     768
                                                             767
                                                             766
                                                     766
                                                             765
                                                             764
                                             764
                                                             763
                                                     763
                                                             762
                                     762
                                                             761
                                                             760
                                                     760
                                                             759
                                                             758
                                             758
                                                             757
                                                             756
                                                     756
                                                             755
                                             755
                                                             754
                                                             753
                                                     753
                                                             752
                                     752
                                                             751
                                                             750
                                                     750
                                                             749
                                                     749
                                                             748
                                             748
                                                             747
                                                             746
                                                     746
                                                             745
                                                     745
                                                             744
                             744
                                                             743
                                                             742
                                                     742
                                                             741
                                             741
                                                             740
                                                     740
                                                             739
                                             739
                                                             738
                                                     738
                                                             737
                                     737
                                                             736
                                                             735
                                                     735
                                                             734
                                                     734
                                                             733
                                                             732
                                             732
                                                             731
                                                             730
                                                     730
                                                             729
                                                     729
                                                             728
             728
                                                             727
                                                             726
                                                     726
                                                             725
                                             725
                                                             724
                                                             723
                                                     723
                                                             722
                                             722
                                                             721
                                                             720
                                                     720
                                                             719
                                     719
                                                             718
                                                     718
                                                             717
                                             717
                                                             716
                                                     716
                                                             715
                                     715
                                                             714
                                                             713
                                                     713
                                                             712
                                                     712
                                                             711
                                             711
                                                             710
                                                     710
                                                             709
                                             709
                                                             708
                                                             707
                                                     707
                                                             706
                                                     706
                                                             705
                                                             704
                             704
                                                             703
                                                             702
                                                     702
                                                             701
                                                     701
                                                             700
                                             700
                                                             699
                                                             698
                                                     698
                                                             697
                                                     697
                                                             696
                                             696
                                                             695
                                                     695
                                                             694
                                     694
                                                             693
                                                             692
                                                     692
                                                             691
                                             691
                                                             690
                                                     690
                                                             689
                                                             688
                                                     688
                                                             687
                             687
                                                             686
                                                             685
                                                     685
                                                             684
                                                             683
                                             683
                                                             682
                                                             681
                                                     681
                                                             680
                                                             679
                                     679
                                                             678
                                                     678
                                                             677
                                                             676
                                             676
                                                             675
                                                     675
                                                             674
                     674
                                                             673
                                                             672
                                                     672
                                                             671
                                             671
                                                             670
                                                     670
                                                             669
                                                             668
                                             668
                                                             667
                                                             666
                                                     666
                                                             665
                                                             664
                                     664
                                                             663
                                                             662
                                                     662
                                                             661
                                                     661
                                                             660
                                             660
                                                             659
                                                             658
                                                     658
                                                             657
                                                             656
                                                     656
                                                             655
                             655
                                                             654
                                                             653
                                                     653
                                                             652
                                                     652
                                                             651
                                             651
                                                             650
                                                     650
                                                             649
                                                             648
                                                     648
                                                             647
                                     647
                                                             646
                                                             645
                                                     645
                                                             644
                                             644
                                                             643
                                                             642
                                                     642
                                                             641
                                                             640
                                             640
                                                             639
                                                             638
                                                     638
                                                             637
                                                             636
                                     636
                                                             635
                                                     635
                                                             634
                                             634
                                                             633
                                                             632
                                                     632
                                                             631
                             631
                                                             630
                                                             629
                                                     629
                                                             628
                                                     628
                                                             627
                                             627
                                                             626
                                                     626
                                                             625
                                                             624
                                             624
                                                             623
                                                     623
                                                             622
                                                             621
                                     621
                                                             620
                                                             619
                                                     619
                                                             618
                                                             617
                                                     617
                                                             616
                                                             615
                                             615
                                                             614
                                                             613
                                                     613
                                                             612
                                                     612
                                                             611
                                             611
                                                             610
                                                     610
                                                             609
                                                             608
                                     608
                                                             607
                                                             606
                                                     606
                                                             605
                                                             604
                                                     604
                                                             603
                                             603
                                                             602
                                                     602
                                                             601
                                                             600
     600
                                                             599
                                                             598
                                                     598
                                                             597
                                             597
                                                             596
                                                     596
                                                             595
                                             595
                                                             594
                                                     594
                                                             593
                                                             592
                                     592
                                                             591
                                                     591
                                                             590
                                             590
                                                             589
                                                             588
                                                     588
                                                             587
                                                             586
                             586
                                                             585
                                                     585
                                                             584
                                                             583
                                             583
                                                             582
                                                     582
                                                             581
                                     581
                                                             580
                                                             579
                                                     579
                                                             578
                                             578
                                                             577
                                                     577
                                                             576
                                                             575
                     575
                                                             574
                                                             573
                                                     573
                                                             572
                                                             571
                                                     571
                                                             570
                                                             569
                                             569
                                                             568
                                                             567
                                                     567
                                                             566
                                     566
                                                             565
                                                             564
                                                     564
                                                             563
                                                     563
                                                             562
                                             562
                                                             561
                                                     561
                                                             560
                                                             559
                                             559
                                                             558
                                                     558
                                                             557
                                                             556
                             556
                                                             555
                                                             554
                                                     554
                                                             553
                                                     553
                                                             552
                                             552
                                                             551
                                                             550
                                                     550
                                                             549
                                             549
                                                             548
                                                             547
                                                     547
                                                             546
                                                             545
                                                     545
                                                             544
                                     544
                                                             543
                                                             542
                                                     542
                                                             541
                                                             540
                                             540
                                                             539
                                                             538
                                                     538
                                                             537
                                             537
                                                             536
                                                             535
                                                     535
                                                             534
                                                             533
                     533
                                                             532
                                                             531
                                                     531
                                                             530
                                                     530
                                                             529
                                             529
                                                             528
                                                             527
                                                     527
                                                             526
                                                     526
                                                             525
                                     525
                                                             524
                                                             523
                                                     523
                                                             522
                                                     522
                                                             521
                                                             520
                                             520
                                                             519
                                                             518
                                                     518
                                                             517
                             517
                                                             516
                                                             515
                                                     515
                                                             514
                                                     514
                                                             513
                                                             512
                                             512
                                                             511
                                                             510
                                                     510
                                                             509
                                     509
                                                             508
                                                             507
                                                     507
                                                             506
                                                             505
                                                     505
                                                             504
                                             504
                                                             503
                                                             502
                                                     502
                                                             501
                             501
                                                             500
                                                     500
                                                             499
                                                             498
                                             498
                                                             497
                                                     497
                                                             496
                                                             495
                                     495
                                                             494
                                                             493
                                                     493
                                                             492
                                             492
                                                             491
                                                             490
                                                     490
                                                             489
                                                     489
                                                             488
                                     488
                                                             487
                                                     487
                                                             486
                                                             485
                                                     485
                                                             484
                                             484
                                                             483
                                                             482
                                                     482
                                                             481
                                                     481
                                                             480
             480
                                                             479
                                                             478
                                                     478
                                                             477
                                                     477
                                                             476
                                             476
                                                             475
                                                     475
                                                             474
                                                             473
                                                     473
                                                             472
                                     472
                                                             471
                                                     471
                                                             470
                                                             469
                                             469
                                                             468
                                                     468
                                                             467
                                             467
                                                             466
                                                             465
                                                     465
                                                             464
                                                             463
                                                     463
                                                             462
                             462
                                                             461
                                                             460
                                                     460
                                                             459
                                             459
                                                             458
                                                             457
                                                     457
                                                             456
                                     456
                                                             455
                                                     455
                                                             454
                                             454
                                                             453
                                                     453
                                                             452
                                                             451
                                     451
                                                             450
                                                             449
                                                     449
                                                             448
                                                     448
                                                             447
                                             447
                                                             446
                                                             445
                                                     445
                                                             444
                                                             443
                                             443
                                                             442
                                                     442
                                                             441
                                                             440
                                                     440
                                                             439
                             439
                                                             438
                                                             437
                                                     437
                                                             436
                                             436
                                                             435
                                                     435
                                                             434
                                     434
                                                             433
                                                     433
                                                             432
                                             432
                                                             431
                                                     431
                                                             430
                                                             429
                                                     429
                                                             428
                                     428
                                                             427
                                                             426
                                                     426
                                                             425
                                                             424
                                             424
                                                             423
                                                             422
                                                     422
                                                             421
                                             421
                                                             420
                                                     420
                                                             419
                     419
                                                             418
                                                             417
                                                     417
                                                             416
                                                             415
                                                     415
                                                             414
                                                             413
                                             413
                                                             412
                                                             411
                                                     411
                                                             410
                                                             409
                                     409
                                                             408
                                                             407
                                                     407
                                                             406
                                                             405
                                                     405
                                                             404
                                             404
                                                             403
                                                     403
                                                             402
                             402
                                                             401
                                                             400
                                                     400
                                                             399
                                                             398
                                             398
                                                             397
                                                     397
                                                             396
                                     396
                                                             395
                                                             394
                                                     394
                                                             393
                                                             392
                                             392
                                                             391
                                                             390
                                                     390
                                                             389
                             389
                                                             388
                                                             387
                                                     387
                                                             386
                                                             385
                                                     385
                                                             384
                                                             383
                                             383
                                                             382
                                                             381
                                                     381
                                                             380
                                     380
                                                             379
                                                             378
                                                     378
                                                             377
                                                     377
                                                             376
                                             376
                                                             375
                                                             374
                                                     374
                                                             373
                                     373
                                                             372
                                                     372
                                                             371
                                                             370
                                             370
                                                             369
                                                             368
                                                     368
                                                             367
                                                             366
                                                     366
                                                             365
365
                                                             364
                                                             363
                                                     363
                                                             362
                                                             361
                                                     361
                                                             360
                                                             359
                                             359
                                                             358
                                                             357
                                                     357
                                                             356
                                                     356
                                                             355
                                                             354
                                     354
                                                             353
                                                             352
                                                     352
                                                             351
                                                             350
                                                     350
                                                             349
                                             349
                                                             348
                                                     348
                                                             347
                             347
                                                             346
                                                             345
                                                     345
                                                             344
                                             344
                                                             343
                                                             342
                                                     342
                                                             341
                                     341
                                                             340
                                                             339
                                                     339
                                                             338
                                                     338
                                                             337
                                             337
                                                             336
                                                     336
                                                             335
                     335
                                                             334
                                                             333
                                                     333
                                                             332
                                             332
                                                             331
                                                             330
                                                     330
                                                             329
                                             329
                                                             328
                                                     328
                                                             327
                                     327
                                                             326
                                                             325
                                                     325
                                                             324
                                             324
                                                             323
                                                     323
                                                             322
                                             322
                                                             321
                                                             320
                                                     320
                                                             319
                                                     319
                                                             318
                             318
                                                             317
                                                             316
                                                     316
                                                             315
                                             315
                                                             314
                                                             313
                                                     313
                                                             312
                                             312
                                                             311
                                                             310
                                                     310
                                                             309
                                                             308
                                                     308
                                                             307
                                                             306
                                     306
                                                             305
                                                             304
                                                     304
                                                             303
                                                             302
                                             302
                                                             301
                                                     301
                                                             300
                                                             299
             299
                                                             298
                                                             297
                                                     297
                                                             296
                                             296
                                                             295
                                                             294
                                                     294
                                                             293
                                                     293
                                                             292
                                     292
                                                             291
                                                     291
                                                             290
                                                             289
                                                     289
                                                             288
                                             288
                                                             287
                                                             286
                                                     286
                                                             285
                                                     285
                                                             284
                                                             283
                             283
                                                             282
                                                             281
                                                     281
                                                             280
                                                             279
                                                     279
                                                             278
                                             278
                                                             277
                                                             276
                                                     276
                                                             275
                                                     275
                                                             274
                                                             273
                                     273
                                                             272
                                                             271
                                                     271
                                                             270
                                             270
                                                             269
                                                             268
                                                     268
                                                             267
                                             267
                                                             266
                                                             265
                                                     265
                                                             264
                                                     264
                                                             263
                                                             262
                     262
                                                             261
                                                             260
                                                     260
                                                             259
                                                     259
                                                             258
                                             258
                                                             257
                                                             256
                                                     256
                                                             255
                                                     255
                                                             254
                                             254
                                                             253
                                                             252
                                                     252
                                                             251
                                                     251
                                                             250
                                     250
                                                             249
                                                             248
                                                     248
                                                             247
                                                     247
                                                             246
                                             246
                                                             245
                                                     245
                                                             244
                             244
                                                             243
                                                     243
                                                             242
                                             242
                                                             241
                                                             240
                                                     240
                                                             239
                                     239
                                                             238
                                                             237
                                                     237
                                                             236
                                             236
                                                             235
                                                             234
                                                     234
                                                             233
             233
                                                             232
                                                             231
                                                     231
                                                             230
                                             230
                                                             229
                                                     229
                                                             228
                                                             227
                                     227
                                                             226
                                                             225
                                                     225
                                                             224
                                             224
                                                             223
                                                     223
                                                             222
                             222
                                                             221
                                                             220
                                                     220
                                                             219
                                                             218
                                             218
                                                             217
                                                     217
                                                             216
                                                             215
                                     215
                                                             214
                                                             213
                                                     213
                                                             212
                                             212
                                                             211
                                                     211
                                                             210
                                                             209
                                             209
                                                             208
                                                             207
                                                     207
                                                             206
                                                     206
                                                             205
                                     205
                                                             204
                                                             203
                                                     203
                                                             202
                                                             201
                                             201
                                                             200
                                                             199
                                                     199
                                                             198
                                                             197
                                                     197
                                                             196
                     196
                                                             195
                                                             194
                                                     194
                                                             193
                                                     193
                                                             192
                                                             191
                                             191
                                                             190
                                                             189
                                                     189
                                                             188
                                     188
                                                             187
                                                             186
                                                     186
                                                             185
                                             185
                                                             184
                                                             183
                                                     183
                                                             182
                                                             181
                                     181
                                                             180
                                                     180
                                                             179
                                                             178
                                                     178
                                                             177
                                             177
                                                             176
                                                     176
                                                             175
                                                             174
                                                     174
                                                             173
                             173
                                                             172
                                                             171
                                                     171
                                                             170
                                                     170
                                                             169
                                             169
                                                             168
                                                     168
                                                             167
                                     167
                                                             166
                                                             165
                                                     165
                                                             164
                                             164
                                                             163
                                                     163
                                                             162
                                                             161
                                     161
                                                             160
                                                     160
                                                             159
                                                             158
                                                     158
                                                             157
                                             157
                                                             156
                                                             155
                                                     155
                                                             154
                                                             153
     153
                                                             152
                                                             151
                                                     151
                                                             150
                                                             149
                                             149
                                                             148
                                                     148
                                                             147
                                                             146
                                             146
                                                             145
                                                     145
                                                             144
                                     144
                                                             143
                                                     143
                                                             142
                                             142
                                                             141
                                                     141
                                                             140
                                                             139
                                                     139
                                                             138
                             138
                                                             137
                                                             136
                                                     136
                                                             135
                                                             134
                                             134
                                                             133
                                                     133
                                                             132
                                     132
                                                             131
                                                             130
                                                     130
                                                             129
                                                             128
                                                     128
                                                             127
                                             127
                                                             126
                                                             125
                                                     125
                                                             124
                                                     124
                                                             123
                                                             122
                     122
                                                             121
                                                             120
                                                     120
                                                             119
                                             119
                                                             118
                                                     118
                                                             117
                                     117
                                                             116
                                                             115
                                                     115
                                                             114
                                                             113
                                                     113
                                                             112
                                             112
                                                             111
                                                     111
                                                             110
                                                             109
                             109
                                                             108
                                                             107
                                                     107
                                                             106
                                             106
                                                             105
                                                             104
                                                     104
                                                             103
                                                             102
                                             102
                                                             101
                                                     101
                                                             100
                                                              99
                                                      99
                                                              98
                                      98
                                                              97
                                                      97
                                                              96
                                                              95
                                              95
                                                              94
                                                      94
                                                              93
                                                              92
              92
                                                              91
                                                              90
                                                      90
                                                              89
                                                              88
                                              88
                                                              87
                                                      87
                                                              86
                                                              85
                                              85
                                                              84
                                                              83
                                                      83
                                                              82
                                                              81
                                                      81
                                                              80
                                      80
                                                              79
                                                              78
                                                      78
                                                              77
                                                      77
                                                              76
                                                              75
                                              75
                                                              74
                                                              73
                                                      73
                                                              72
                                      72
                                                              71
                                                              70
                                                      70
                                                              69
                                                              68
                                              68
                                                              67
                                                              66
                                                      66
                                                              65
                                                      65
                                                              64
                                                              63
                              63
                                                              62
                                                      62
                                                              61
                                                              60
                                              60
                                                              59
                                                      59
                                                              58
                                                              57
                                      57
                                                              56
                                                              55
                                                      55
                                                              54
                                                              53
                                              53
                                                              52
                                                      52
                                                              51
                                              51
                                                              50
                                                      50
                                                              49
                                                              48
                                                      48
                                                              47
                                      47
                                                              46
                                                              45
                                                      45
                                                              44
                                                      44
                                                              43
                                              43
                                                              42
                                                      42
                                                              41
                                                              40
                      40
                                                              39
                                                              38
                                                      38
                                                              37
                                              37
                                                              36
                                                              35
                                                      35
                                                              34
                                      34
                                                              33
                                                      33
                                                              32
                                                              31
                                                      31
                                                              30
                                              30
                                                              29
                                                      29
                                                              28
                                                              27
                                      27
                                                              26
                                                      26
                                                              25
                                                              24
                                                      24
                                                              23
                                              23
                                                              22
                                                              21
                                                      21
                                                              20
                                              20
                                                              19
                                                              18
                                                      18
                                                              17
                                                              16
                                                      16
                                                              15
                              15
                                                              14
                                                              13
                                                      13
                                                              12
                                                              11
                                                      11
                                                              10
                                                               9
                                               9
                                                               8
                                                               7
                                                       7
                                                               6
                                       6
                                                               5
                                                       5
                                                               4
                                               4
                                                               3
                                                               2
                                                       2
                                                               1
                                                               0


========================================================
             631
     631
             432
432
              27
      27
               6

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 483 876 985 141 338 622 105 548 626 214 605 565 832 984 144 228 12 329 752 809 528 164 609 53 507 604 82 774 230 243 297 111 592 250 575 852 356 621 312 708 793 5 541 115 758 773 954 118 122 966 912 828 786 978 264 384 31 642 464 373 595 764 430 513 878 324 505 829 616 781 516 98 986 630 410 154 354 197 226 383 843 222 0 412 847 436 461 288 441 924 179 589 168 342 784 510 155 646 902 123 406 172 999 887 601 429 551 748 799 654 705 639 187 454 403 707 177 18 519 960 139 128 845 711 182 37 785 805 142 636 334 425 862 475 185 602 424 315 921 821 495 741 474 853 153 881 292 276 663 981 660 74 872 244 277 344 620 628 736 246 309 8 949 19 665 64 79 88 395 830 108 571 460 130 836 131 958 619 127 215 335 963 33 451 696 990 674 870 729 327 462 206 859 401 407 929 744 28 97 927 864 540 385 211 683 858 125 790 520 678 961 435 267 767 900 438 86 60 922 263 80 150 484 361 195 555 352 391 274 778 800 987 653 508 613 911 580 930 840 120 447 304 96 576 32 573 899 445 719 386 486 269 357 235 450 618 481 23 433 808 943 599 603 374 506 379 727 112 715 56 40 747 265 680 717 600 448 974 972 83 763 559 650 21 437 39 907 638 350 746 229 690 90 380 465 962 279 976 811 908 294 713 249 792 151 375 905 668 813 162 608 13 709 659 26 345 617 7 779 556 283 290 129 863 964 14 685 364 186 388 699 734 874 584 738 733 93 114 797 313 501 868 337 54 749 755 284 689 695 877 210 367 915 577 254 188 446 846 323 880 633 823 590 788 353 458 882 770 469 124 499 567 310 509 209 459 712 856 449 992 242 349 648 180 136 545 48 587 926 34 308 743 193 358 301 789 896 355 472 894 824 563 583 378 25 366 988 478 664 570 751 553 219 701 416 611 890 44 289 270 531 694 956 760 562 684 753 591 596 419 282 159 725 634 526 41 318 569 918 399 421 568 947 224 181 849 320 117 245 346 78 135 971 979 55 946 822 718 745 750 57 156 16 273 305 867 29 402 854 71 914 598 937 261 266 256 299 883 657 252 204 101 94 675 163 756 534 389 387 440 208 933 231 191 452 76 970 931 466 632 428 955 923 827 489 722 43 658 714 730 720 192 904 45 558 801 369 950 331 547 524 623 782 913 255 704 776 343 10 703 227 17 686 24 574 951 418 812 119 833 835 287 302 723 65 530 457 62 514 126 409 87 166 697 682 463 757 296 63 839 731 965 480 92 196 332 200 844 917 77 527 919 396 691 275 644 59 30 133 4 491 178 382 542 220 726 945 61 149 762 100 895 607 716 73 525 498 543 38 995 326 173 234 681 841 706 935 586 649 754 610 365 676 110 479 529 807 167 898 614 772 487 582 666 871 983 953 624 780 106 967 511 916 488 46 775 218 994 103 3 482 414 408 392 281 549 496 869 803 278 560 669 625 169 434 81 311 492 831 237 50 865 295 909 253 941 688 325 735 673 143 798 998 857 936 49 969 232 537 468 477 579 891 702 404 377 306 330 944 873 47 319 285 322 768 476 427 213 886 146 550 413 993 199 655 348 303 942 661 134 455 280 260 236 503 640 11 293 585 148 739 207 906 239 910 765 160 314 687 247 258 99 671 920 814 221 470 417 138 546 176 561 879 35 991 901 203 233 158 405 259 518 815 394 184 201 742 819 766 202 240 471 390 662 515 262 925 651 698 381 91 578 973 20 493 431 504 248 189 467 170 948 532 121 903 70 198 740 606 850 848 645 679 521 588 52 85 670 190 271 456 564 107 109 629 693 268 272 721 656 566 58 1 453 161 75 817 928 362 512 212 371 539 68 363 997 980 612 307 861 316 737 517 804 732 423 95 795 89 875 932 838 572 393 104 769 341 132 536 837 647 535 538 36 820 777 9 672 860 485 710 497 641 502 298 351 291 818 700 360 439 257 977 810 317 759 855 934 42 724 500 183 442 594 490 825 175 761 251 241 557 884 238 728 194 523 842 157 152 333 473 420 286 834 643 2 783 336 851 321 223 22 938 372 885 225 893 791 422 370 968 411 552 51 897 888 593 982 952 368 137 794 522 165 84 637 72 957 376 692 217 205 959 826 615 889 494 67 892 667 300 140 581 996 69 940 174 147 802 597 66 116 989 15 171 113 400 787 533 652 975 415 102 340 359 677 339 347 866 145 771 806 443 397 554 444 328 939 544 816 426 216 635 398 627 796   from: 467 1 2 365 122 728 451 903 201 9 818 11 615 5 600 15 475 383 459 173 37 480 631 936 809 299 975 163 200 29 30 402 153 409 439 442 460 62 768 640 40 431 42 101 998 842 980 47 873 861 335 354 585 951 787 55 318 575 704 626 176 196 404 63 577 839 273 370 940 507 766 359 109 39 987 75 111 533 945 120 80 974 535 800 767 136 529 87 403 57 94 188 92 222 167 674 722 160 262 99 95 215 199 798 117 341 981 769 447 836 906 914 920 261 984 115 715 250 118 687 509 428 872 694 124 983 829 127 797 552 130 23 132 133 134 617 514 695 781 288 520 141 971 748 18 877 696 185 660 209 934 602 102 737 744 221 138 0 664 292 131 608 86 27 725 322 364 712 168 169 993 171 229 177 180 175 394 581 4 286 389 181 344 183 184 85 65 862 91 935 396 513 644 193 191 487 815 629 198 81 162 893 890 203 400 500 957 556 586 517 874 597 551 239 323 976 456 217 258 481 881 440 718 125 174 928 271 760 228 537 155 44 706 233 419 908 189 916 251 213 678 218 242 243 244 60 966 142 248 758 143 349 783 621 140 301 259 771 645 745 240 953 870 820 264 26 194 525 161 904 270 703 236 22 152 275 799 523 588 709 158 334 107 245 291 739 450 931 139 289 518 932 912 884 774 610 327 6 234 267 43 590 302 426 304 283 306 321 752 285 56 962 312 445 434 319 287 317 765 732 738 519 170 679 407 716 915 995 759 812 432 947 692 573 424 50 336 411 338 726 938 53 512 757 119 126 495 347 348 28 755 907 569 382 311 756 729 25 489 911 48 466 886 624 448 16 345 453 368 369 342 230 372 151 478 269 666 963 172 816 986 274 353 925 104 825 308 847 388 20 880 578 392 544 554 254 476 397 501 685 68 948 373 942 195 227 876 449 454 982 594 223 505 413 997 574 522 417 418 416 363 805 791 72 462 35 265 623 421 278 211 257 315 433 420 246 960 970 625 636 38 472 226 106 992 316 446 465 83 762 515 740 45 668 526 710 813 485 253 562 337 398 991 642 790 374 116 655 538 784 298 144 817 978 656 611 780 477 582 824 658 362 21 882 484 380 952 284 488 97 461 46 492 493 913 803 863 497 735 499 282 482 879 41 438 412 627 260 393 773 510 683 690 296 542 508 717 786 634 332 93 521 720 79 524 553 90 281 205 443 530 531 532 367 59 415 381 455 705 944 528 922 775 266 98 545 612 917 628 749 603 377 272 788 682 494 894 827 927 875 13 561 179 371 719 238 549 220 772 721 563 548 572 471 356 633 576 463 405 339 580 70 865 727 128 810 540 587 498 157 543 591 502 811 77 595 596 579 939 599 868 650 89 247 604 822 606 328 571 754 464 895 178 61 613 750 164 135 840 619 620 973 819 232 550 607 663 866 999 534 630 823 855 632 457 635 878 423 638 889 24 422 314 643 686 708 73 224 401 148 734 385 652 909 216 255 33 34 307 570 670 661 504 954 182 390 511 667 496 486 593 165 672 190 149 294 648 835 479 112 560 547 566 51 684 994 899 395 961 736 950 691 506 693 212 231 567 697 871 834 700 711 605 832 305 357 713 8 444 898 558 946 225 888 76 770 19 698 859 527 689 14 96 967 129 941 516 968 7 601 929 618 641 733 430 539 491 435 436 841 622 741 58 743 414 910 746 333 557 241 647 303 330 358 958 470 67 52 36 614 391 100 137 592 665 806 742 854 237 249 361 219 724 731 329 503 776 64 376 300 536 156 782 252 66 785 763 276 808 901 154 714 723 793 794 84 88 779 17 324 761 801 280 796 804 408 310 565 399 846 378 352 206 972 113 616 490 923 483 677 69 814 659 546 441 410 555 675 187 326 830 256 651 833 235 346 473 121 838 926 609 108 366 843 844 452 114 387 662 849 653 166 202 853 778 568 892 857 937 340 860 150 821 343 701 589 795 867 851 869 159 764 730 988 197 320 427 145 110 49 313 355 268 379 293 885 82 887 279 639 681 891 671 747 297 657 896 384 848 325 900 789 902 897 921 905 54 541 883 10 74 584 598 295 204 688 943 777 918 919 680 3 468 646 123 837 147 826 850 949 930 474 933 564 31 649 751 71 807 207 12 263 559 864 977 78 277 360 105 146 386 425 458 856 350 955 956 583 331 959 845 969 469 858 964 965 831 637 802 290 985 828 792 309 186 192 676 429 103 979 699 654 210 707 852 924 208 351 406 989 990 437 673 702 375 214 996 669 32 753
  REMOVING [432]
========================================================
996 of 1000
========================================================
     631
631
      27
27
       6

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 483 876 985 141 338 622 105 548 626 214 605 565 832 984 144 228 12 329 752 809 528 164 609 53 507 604 82 774 230 243 297 111 592 250 575 852 356 621 312 708 793 5 541 115 758 773 954 118 122 966 912 828 786 978 264 384 31 642 464 373 595 764 430 513 878 324 505 829 616 781 516 98 986 630 410 154 354 197 226 383 843 222 0 412 847 436 461 288 441 924 179 589 168 342 784 510 155 646 902 123 406 172 999 887 601 429 551 748 799 654 705 639 187 454 403 707 177 18 519 960 139 128 845 711 182 37 785 805 142 636 334 425 862 475 185 602 424 315 921 821 495 741 474 853 153 881 292 276 663 981 660 74 872 244 277 344 620 628 736 246 309 8 949 19 665 64 79 88 395 830 108 571 460 130 836 131 958 619 127 215 335 963 33 451 696 990 674 870 729 327 462 206 859 401 407 929 744 28 97 927 864 540 385 211 683 858 125 790 520 678 961 435 267 767 900 438 86 60 922 263 80 150 484 361 195 555 352 391 274 778 800 987 653 508 613 911 580 930 840 120 447 304 96 576 32 573 899 445 719 386 486 269 357 235 450 618 481 23 433 808 943 599 603 374 506 379 727 112 715 56 40 747 265 680 717 600 448 974 972 83 763 559 650 21 437 39 907 638 350 746 229 690 90 380 465 962 279 976 811 908 294 713 249 792 151 375 905 668 813 162 608 13 709 659 26 345 617 7 779 556 283 290 129 863 964 14 685 364 186 388 699 734 874 584 738 733 93 114 797 313 501 868 337 54 749 755 284 689 695 877 210 367 915 577 254 188 446 846 323 880 633 823 590 788 353 458 882 770 469 124 499 567 310 509 209 459 712 856 449 992 242 349 648 180 136 545 48 587 926 34 308 743 193 358 301 789 896 355 472 894 824 563 583 378 25 366 988 478 664 570 751 553 219 701 416 611 890 44 289 270 531 694 956 760 562 684 753 591 596 419 282 159 725 634 526 41 318 569 918 399 421 568 947 224 181 849 320 117 245 346 78 135 971 979 55 946 822 718 745 750 57 156 16 273 305 867 29 402 854 71 914 598 937 261 266 256 299 883 657 252 204 101 94 675 163 756 534 389 387 440 208 933 231 191 452 76 970 931 466 632 428 955 923 827 489 722 43 658 714 730 720 192 904 45 558 801 369 950 331 547 524 623 782 913 255 704 776 343 10 703 227 17 686 24 574 951 418 812 119 833 835 287 302 723 65 530 457 62 514 126 409 87 166 697 682 463 757 296 63 839 731 965 480 92 196 332 200 844 917 77 527 919 396 691 275 644 59 30 133 4 491 178 382 542 220 726 945 61 149 762 100 895 607 716 73 525 498 543 38 995 326 173 234 681 841 706 935 586 649 754 610 365 676 110 479 529 807 167 898 614 772 487 582 666 871 983 953 624 780 106 967 511 916 488 46 775 218 994 103 3 482 414 408 392 281 549 496 869 803 278 560 669 625 169 434 81 311 492 831 237 50 865 295 909 253 941 688 325 735 673 143 798 998 857 936 49 969 232 537 468 477 579 891 702 404 377 306 330 944 873 47 319 285 322 768 476 427 213 886 146 550 413 993 199 655 348 303 942 661 134 455 280 260 236 503 640 11 293 585 148 739 207 906 239 910 765 160 314 687 247 258 99 671 920 814 221 470 417 138 546 176 561 879 35 991 901 203 233 158 405 259 518 815 394 184 201 742 819 766 202 240 471 390 662 515 262 925 651 698 381 91 578 973 20 493 431 504 248 189 467 170 948 532 121 903 70 198 740 606 850 848 645 679 521 588 52 85 670 190 271 456 564 107 109 629 693 268 272 721 656 566 58 1 453 161 75 817 928 362 512 212 371 539 68 363 997 980 612 307 861 316 737 517 804 732 423 95 795 89 875 932 838 572 393 104 769 341 132 536 837 647 535 538 36 820 777 9 672 860 485 710 497 641 502 298 351 291 818 700 360 439 257 977 810 317 759 855 934 42 724 500 183 442 594 490 825 175 761 251 241 557 884 238 728 194 523 842 157 152 333 473 420 286 834 643 2 783 336 851 321 223 22 938 372 885 225 893 791 422 370 968 411 552 51 897 888 593 982 952 368 137 794 522 165 84 637 72 957 376 692 217 205 959 826 615 889 494 67 892 667 300 140 581 996 69 940 174 147 802 597 66 116 989 15 171 113 400 787 533 652 975 415 102 340 359 677 339 347 866 145 771 806 443 397 554 444 328 939 544 816 426 216 635 398 627 796 432   from: 467 1 2 365 122 728 451 903 201 9 818 11 615 5 600 15 475 383 459 173 37 480 631 936 809 299 975 163 200 29 30 402 153 409 439 442 460 62 768 640 40 431 42 101 998 842 980 47 873 861 335 354 585 951 787 55 318 575 704 626 176 196 404 63 577 839 273 370 940 507 766 359 109 39 987 75 111 533 945 120 80 974 535 800 767 136 529 87 403 57 94 188 92 222 167 674 722 160 262 99 95 215 199 798 117 341 981 769 447 836 906 914 920 261 984 115 715 250 118 687 509 428 872 694 124 983 829 127 797 552 130 23 132 133 134 617 514 695 781 288 520 141 971 748 18 877 696 185 660 209 934 602 102 737 744 221 138 0 664 292 131 608 86 27 725 322 364 712 168 169 993 171 229 177 180 175 394 581 4 286 389 181 344 183 184 85 65 862 91 935 396 513 644 193 191 487 815 629 198 81 162 893 890 203 400 500 957 556 586 517 874 597 551 239 323 976 456 217 258 481 881 440 718 125 174 928 271 760 228 537 155 44 706 233 419 908 189 916 251 213 678 218 242 243 244 60 966 142 248 758 143 349 783 621 140 301 259 771 645 745 240 953 870 820 264 26 194 525 161 904 270 703 236 22 152 275 799 523 588 709 158 334 107 245 291 739 450 931 139 289 518 932 912 884 774 610 327 6 234 267 43 590 302 426 304 283 306 321 752 285 56 962 312 445 434 319 287 317 765 732 738 519 170 679 407 716 915 995 759 812 432 947 692 573 424 50 336 411 338 726 938 53 512 757 119 126 495 347 348 28 755 907 569 382 311 756 729 25 489 911 48 466 886 624 448 16 345 453 368 369 342 230 372 151 478 269 666 963 172 816 986 274 353 925 104 825 308 847 388 20 880 578 392 544 554 254 476 397 501 685 68 948 373 942 195 227 876 449 454 982 594 223 505 413 997 574 522 417 418 416 363 805 791 72 462 35 265 623 421 278 211 257 315 433 420 246 960 970 625 636 38 472 226 106 992 316 446 465 83 762 515 740 45 668 526 710 813 485 253 562 337 398 991 642 790 374 116 655 538 784 298 144 817 978 656 611 780 477 582 824 658 362 21 882 484 380 952 284 488 97 461 46 492 493 913 803 863 497 735 499 282 482 879 41 438 412 627 260 393 773 510 683 690 296 542 508 717 786 634 332 93 521 720 79 524 553 90 281 205 443 530 531 532 367 59 415 381 455 705 944 528 922 775 266 98 545 612 917 628 749 603 377 272 788 682 494 894 827 927 875 13 561 179 371 719 238 549 220 772 721 563 548 572 471 356 633 576 463 405 339 580 70 865 727 128 810 540 587 498 157 543 591 502 811 77 595 596 579 939 599 868 650 89 247 604 822 606 328 571 754 464 895 178 61 613 750 164 135 840 619 620 973 819 232 550 607 663 866 999 534 630 823 855 632 457 635 878 423 638 889 24 422 314 643 686 708 73 224 401 148 734 385 652 909 216 255 33 34 307 570 670 661 504 954 182 390 511 667 496 486 593 165 672 190 149 294 648 835 479 112 560 547 566 51 684 994 899 395 961 736 950 691 506 693 212 231 567 697 871 834 700 711 605 832 305 357 713 8 444 898 558 946 225 888 76 770 19 698 859 527 689 14 96 967 129 941 516 968 7 601 929 618 641 733 430 539 491 435 436 841 622 741 58 743 414 910 746 333 557 241 647 303 330 358 958 470 67 52 36 614 391 100 137 592 665 806 742 854 237 249 361 219 724 731 329 503 776 64 376 300 536 156 782 252 66 785 763 276 808 901 154 714 723 793 794 84 88 779 17 324 761 801 280 796 804 408 310 565 399 846 378 352 206 972 113 616 490 923 483 677 69 814 659 546 441 410 555 675 187 326 830 256 651 833 235 346 473 121 838 926 609 108 366 843 844 452 114 387 662 849 653 166 202 853 778 568 892 857 937 340 860 150 821 343 701 589 795 867 851 869 159 764 730 988 197 320 427 145 110 49 313 355 268 379 293 885 82 887 279 639 681 891 671 747 297 657 896 384 848 325 900 789 902 897 921 905 54 541 883 10 74 584 598 295 204 688 943 777 918 919 680 3 468 646 123 837 147 826 850 949 930 474 933 564 31 649 751 71 807 207 12 263 559 864 977 78 277 360 105 146 386 425 458 856 350 955 956 583 331 959 845 969 469 858 964 965 831 637 802 290 985 828 792 309 186 192 676 429 103 979 699 654 210 707 852 924 208 351 406 989 990 437 673 702 375 214 996 669 32 753
  REMOVING [6]
========================================================
997 of 1000
========================================================
     631
631
      27

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 483 876 985 141 338 622 105 548 626 214 605 565 832 984 144 228 12 329 752 809 528 164 609 53 507 604 82 774 230 243 297 111 592 250 575 852 356 621 312 708 793 5 541 115 758 773 954 118 122 966 912 828 786 978 264 384 31 642 464 373 595 764 430 513 878 324 505 829 616 781 516 98 986 630 410 154 354 197 226 383 843 222 0 412 847 436 461 288 441 924 179 589 168 342 784 510 155 646 902 123 406 172 999 887 601 429 551 748 799 654 705 639 187 454 403 707 177 18 519 960 139 128 845 711 182 37 785 805 142 636 334 425 862 475 185 602 424 315 921 821 495 741 474 853 153 881 292 276 663 981 660 74 872 244 277 344 620 628 736 246 309 8 949 19 665 64 79 88 395 830 108 571 460 130 836 131 958 619 127 215 335 963 33 451 696 990 674 870 729 327 462 206 859 401 407 929 744 28 97 927 864 540 385 211 683 858 125 790 520 678 961 435 267 767 900 438 86 60 922 263 80 150 484 361 195 555 352 391 274 778 800 987 653 508 613 911 580 930 840 120 447 304 96 576 32 573 899 445 719 386 486 269 357 235 450 618 481 23 433 808 943 599 603 374 506 379 727 112 715 56 40 747 265 680 717 600 448 974 972 83 763 559 650 21 437 39 907 638 350 746 229 690 90 380 465 962 279 976 811 908 294 713 249 792 151 375 905 668 813 162 608 13 709 659 26 345 617 7 779 556 283 290 129 863 964 14 685 364 186 388 699 734 874 584 738 733 93 114 797 313 501 868 337 54 749 755 284 689 695 877 210 367 915 577 254 188 446 846 323 880 633 823 590 788 353 458 882 770 469 124 499 567 310 509 209 459 712 856 449 992 242 349 648 180 136 545 48 587 926 34 308 743 193 358 301 789 896 355 472 894 824 563 583 378 25 366 988 478 664 570 751 553 219 701 416 611 890 44 289 270 531 694 956 760 562 684 753 591 596 419 282 159 725 634 526 41 318 569 918 399 421 568 947 224 181 849 320 117 245 346 78 135 971 979 55 946 822 718 745 750 57 156 16 273 305 867 29 402 854 71 914 598 937 261 266 256 299 883 657 252 204 101 94 675 163 756 534 389 387 440 208 933 231 191 452 76 970 931 466 632 428 955 923 827 489 722 43 658 714 730 720 192 904 45 558 801 369 950 331 547 524 623 782 913 255 704 776 343 10 703 227 17 686 24 574 951 418 812 119 833 835 287 302 723 65 530 457 62 514 126 409 87 166 697 682 463 757 296 63 839 731 965 480 92 196 332 200 844 917 77 527 919 396 691 275 644 59 30 133 4 491 178 382 542 220 726 945 61 149 762 100 895 607 716 73 525 498 543 38 995 326 173 234 681 841 706 935 586 649 754 610 365 676 110 479 529 807 167 898 614 772 487 582 666 871 983 953 624 780 106 967 511 916 488 46 775 218 994 103 3 482 414 408 392 281 549 496 869 803 278 560 669 625 169 434 81 311 492 831 237 50 865 295 909 253 941 688 325 735 673 143 798 998 857 936 49 969 232 537 468 477 579 891 702 404 377 306 330 944 873 47 319 285 322 768 476 427 213 886 146 550 413 993 199 655 348 303 942 661 134 455 280 260 236 503 640 11 293 585 148 739 207 906 239 910 765 160 314 687 247 258 99 671 920 814 221 470 417 138 546 176 561 879 35 991 901 203 233 158 405 259 518 815 394 184 201 742 819 766 202 240 471 390 662 515 262 925 651 698 381 91 578 973 20 493 431 504 248 189 467 170 948 532 121 903 70 198 740 606 850 848 645 679 521 588 52 85 670 190 271 456 564 107 109 629 693 268 272 721 656 566 58 1 453 161 75 817 928 362 512 212 371 539 68 363 997 980 612 307 861 316 737 517 804 732 423 95 795 89 875 932 838 572 393 104 769 341 132 536 837 647 535 538 36 820 777 9 672 860 485 710 497 641 502 298 351 291 818 700 360 439 257 977 810 317 759 855 934 42 724 500 183 442 594 490 825 175 761 251 241 557 884 238 728 194 523 842 157 152 333 473 420 286 834 643 2 783 336 851 321 223 22 938 372 885 225 893 791 422 370 968 411 552 51 897 888 593 982 952 368 137 794 522 165 84 637 72 957 376 692 217 205 959 826 615 889 494 67 892 667 300 140 581 996 69 940 174 147 802 597 66 116 989 15 171 113 400 787 533 652 975 415 102 340 359 677 339 347 866 145 771 806 443 397 554 444 328 939 544 816 426 216 635 398 627 796 432 6   from: 467 1 2 365 122 728 451 903 201 9 818 11 615 5 600 15 475 383 459 173 37 480 631 936 809 299 975 163 200 29 30 402 153 409 439 442 460 62 768 640 40 431 42 101 998 842 980 47 873 861 335 354 585 951 787 55 318 575 704 626 176 196 404 63 577 839 273 370 940 507 766 359 109 39 987 75 111 533 945 120 80 974 535 800 767 136 529 87 403 57 94 188 92 222 167 674 722 160 262 99 95 215 199 798 117 341 981 769 447 836 906 914 920 261 984 115 715 250 118 687 509 428 872 694 124 983 829 127 797 552 130 23 132 133 134 617 514 695 781 288 520 141 971 748 18 877 696 185 660 209 934 602 102 737 744 221 138 0 664 292 131 608 86 27 725 322 364 712 168 169 993 171 229 177 180 175 394 581 4 286 389 181 344 183 184 85 65 862 91 935 396 513 644 193 191 487 815 629 198 81 162 893 890 203 400 500 957 556 586 517 874 597 551 239 323 976 456 217 258 481 881 440 718 125 174 928 271 760 228 537 155 44 706 233 419 908 189 916 251 213 678 218 242 243 244 60 966 142 248 758 143 349 783 621 140 301 259 771 645 745 240 953 870 820 264 26 194 525 161 904 270 703 236 22 152 275 799 523 588 709 158 334 107 245 291 739 450 931 139 289 518 932 912 884 774 610 327 6 234 267 43 590 302 426 304 283 306 321 752 285 56 962 312 445 434 319 287 317 765 732 738 519 170 679 407 716 915 995 759 812 432 947 692 573 424 50 336 411 338 726 938 53 512 757 119 126 495 347 348 28 755 907 569 382 311 756 729 25 489 911 48 466 886 624 448 16 345 453 368 369 342 230 372 151 478 269 666 963 172 816 986 274 353 925 104 825 308 847 388 20 880 578 392 544 554 254 476 397 501 685 68 948 373 942 195 227 876 449 454 982 594 223 505 413 997 574 522 417 418 416 363 805 791 72 462 35 265 623 421 278 211 257 315 433 420 246 960 970 625 636 38 472 226 106 992 316 446 465 83 762 515 740 45 668 526 710 813 485 253 562 337 398 991 642 790 374 116 655 538 784 298 144 817 978 656 611 780 477 582 824 658 362 21 882 484 380 952 284 488 97 461 46 492 493 913 803 863 497 735 499 282 482 879 41 438 412 627 260 393 773 510 683 690 296 542 508 717 786 634 332 93 521 720 79 524 553 90 281 205 443 530 531 532 367 59 415 381 455 705 944 528 922 775 266 98 545 612 917 628 749 603 377 272 788 682 494 894 827 927 875 13 561 179 371 719 238 549 220 772 721 563 548 572 471 356 633 576 463 405 339 580 70 865 727 128 810 540 587 498 157 543 591 502 811 77 595 596 579 939 599 868 650 89 247 604 822 606 328 571 754 464 895 178 61 613 750 164 135 840 619 620 973 819 232 550 607 663 866 999 534 630 823 855 632 457 635 878 423 638 889 24 422 314 643 686 708 73 224 401 148 734 385 652 909 216 255 33 34 307 570 670 661 504 954 182 390 511 667 496 486 593 165 672 190 149 294 648 835 479 112 560 547 566 51 684 994 899 395 961 736 950 691 506 693 212 231 567 697 871 834 700 711 605 832 305 357 713 8 444 898 558 946 225 888 76 770 19 698 859 527 689 14 96 967 129 941 516 968 7 601 929 618 641 733 430 539 491 435 436 841 622 741 58 743 414 910 746 333 557 241 647 303 330 358 958 470 67 52 36 614 391 100 137 592 665 806 742 854 237 249 361 219 724 731 329 503 776 64 376 300 536 156 782 252 66 785 763 276 808 901 154 714 723 793 794 84 88 779 17 324 761 801 280 796 804 408 310 565 399 846 378 352 206 972 113 616 490 923 483 677 69 814 659 546 441 410 555 675 187 326 830 256 651 833 235 346 473 121 838 926 609 108 366 843 844 452 114 387 662 849 653 166 202 853 778 568 892 857 937 340 860 150 821 343 701 589 795 867 851 869 159 764 730 988 197 320 427 145 110 49 313 355 268 379 293 885 82 887 279 639 681 891 671 747 297 657 896 384 848 325 900 789 902 897 921 905 54 541 883 10 74 584 598 295 204 688 943 777 918 919 680 3 468 646 123 837 147 826 850 949 930 474 933 564 31 649 751 71 807 207 12 263 559 864 977 78 277 360 105 146 386 425 458 856 350 955 956 583 331 959 845 969 469 858 964 965 831 637 802 290 985 828 792 309 186 192 676 429 103 979 699 654 210 707 852 924 208 351 406 989 990 437 673 702 375 214 996 669 32 753
  REMOVING [27]
========================================================
998 of 1000
========================================================
631

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 483 876 985 141 338 622 105 548 626 214 605 565 832 984 144 228 12 329 752 809 528 164 609 53 507 604 82 774 230 243 297 111 592 250 575 852 356 621 312 708 793 5 541 115 758 773 954 118 122 966 912 828 786 978 264 384 31 642 464 373 595 764 430 513 878 324 505 829 616 781 516 98 986 630 410 154 354 197 226 383 843 222 0 412 847 436 461 288 441 924 179 589 168 342 784 510 155 646 902 123 406 172 999 887 601 429 551 748 799 654 705 639 187 454 403 707 177 18 519 960 139 128 845 711 182 37 785 805 142 636 334 425 862 475 185 602 424 315 921 821 495 741 474 853 153 881 292 276 663 981 660 74 872 244 277 344 620 628 736 246 309 8 949 19 665 64 79 88 395 830 108 571 460 130 836 131 958 619 127 215 335 963 33 451 696 990 674 870 729 327 462 206 859 401 407 929 744 28 97 927 864 540 385 211 683 858 125 790 520 678 961 435 267 767 900 438 86 60 922 263 80 150 484 361 195 555 352 391 274 778 800 987 653 508 613 911 580 930 840 120 447 304 96 576 32 573 899 445 719 386 486 269 357 235 450 618 481 23 433 808 943 599 603 374 506 379 727 112 715 56 40 747 265 680 717 600 448 974 972 83 763 559 650 21 437 39 907 638 350 746 229 690 90 380 465 962 279 976 811 908 294 713 249 792 151 375 905 668 813 162 608 13 709 659 26 345 617 7 779 556 283 290 129 863 964 14 685 364 186 388 699 734 874 584 738 733 93 114 797 313 501 868 337 54 749 755 284 689 695 877 210 367 915 577 254 188 446 846 323 880 633 823 590 788 353 458 882 770 469 124 499 567 310 509 209 459 712 856 449 992 242 349 648 180 136 545 48 587 926 34 308 743 193 358 301 789 896 355 472 894 824 563 583 378 25 366 988 478 664 570 751 553 219 701 416 611 890 44 289 270 531 694 956 760 562 684 753 591 596 419 282 159 725 634 526 41 318 569 918 399 421 568 947 224 181 849 320 117 245 346 78 135 971 979 55 946 822 718 745 750 57 156 16 273 305 867 29 402 854 71 914 598 937 261 266 256 299 883 657 252 204 101 94 675 163 756 534 389 387 440 208 933 231 191 452 76 970 931 466 632 428 955 923 827 489 722 43 658 714 730 720 192 904 45 558 801 369 950 331 547 524 623 782 913 255 704 776 343 10 703 227 17 686 24 574 951 418 812 119 833 835 287 302 723 65 530 457 62 514 126 409 87 166 697 682 463 757 296 63 839 731 965 480 92 196 332 200 844 917 77 527 919 396 691 275 644 59 30 133 4 491 178 382 542 220 726 945 61 149 762 100 895 607 716 73 525 498 543 38 995 326 173 234 681 841 706 935 586 649 754 610 365 676 110 479 529 807 167 898 614 772 487 582 666 871 983 953 624 780 106 967 511 916 488 46 775 218 994 103 3 482 414 408 392 281 549 496 869 803 278 560 669 625 169 434 81 311 492 831 237 50 865 295 909 253 941 688 325 735 673 143 798 998 857 936 49 969 232 537 468 477 579 891 702 404 377 306 330 944 873 47 319 285 322 768 476 427 213 886 146 550 413 993 199 655 348 303 942 661 134 455 280 260 236 503 640 11 293 585 148 739 207 906 239 910 765 160 314 687 247 258 99 671 920 814 221 470 417 138 546 176 561 879 35 991 901 203 233 158 405 259 518 815 394 184 201 742 819 766 202 240 471 390 662 515 262 925 651 698 381 91 578 973 20 493 431 504 248 189 467 170 948 532 121 903 70 198 740 606 850 848 645 679 521 588 52 85 670 190 271 456 564 107 109 629 693 268 272 721 656 566 58 1 453 161 75 817 928 362 512 212 371 539 68 363 997 980 612 307 861 316 737 517 804 732 423 95 795 89 875 932 838 572 393 104 769 341 132 536 837 647 535 538 36 820 777 9 672 860 485 710 497 641 502 298 351 291 818 700 360 439 257 977 810 317 759 855 934 42 724 500 183 442 594 490 825 175 761 251 241 557 884 238 728 194 523 842 157 152 333 473 420 286 834 643 2 783 336 851 321 223 22 938 372 885 225 893 791 422 370 968 411 552 51 897 888 593 982 952 368 137 794 522 165 84 637 72 957 376 692 217 205 959 826 615 889 494 67 892 667 300 140 581 996 69 940 174 147 802 597 66 116 989 15 171 113 400 787 533 652 975 415 102 340 359 677 339 347 866 145 771 806 443 397 554 444 328 939 544 816 426 216 635 398 627 796 432 6 27   from: 467 1 2 365 122 728 451 903 201 9 818 11 615 5 600 15 475 383 459 173 37 480 631 936 809 299 975 163 200 29 30 402 153 409 439 442 460 62 768 640 40 431 42 101 998 842 980 47 873 861 335 354 585 951 787 55 318 575 704 626 176 196 404 63 577 839 273 370 940 507 766 359 109 39 987 75 111 533 945 120 80 974 535 800 767 136 529 87 403 57 94 188 92 222 167 674 722 160 262 99 95 215 199 798 117 341 981 769 447 836 906 914 920 261 984 115 715 250 118 687 509 428 872 694 124 983 829 127 797 552 130 23 132 133 134 617 514 695 781 288 520 141 971 748 18 877 696 185 660 209 934 602 102 737 744 221 138 0 664 292 131 608 86 27 725 322 364 712 168 169 993 171 229 177 180 175 394 581 4 286 389 181 344 183 184 85 65 862 91 935 396 513 644 193 191 487 815 629 198 81 162 893 890 203 400 500 957 556 586 517 874 597 551 239 323 976 456 217 258 481 881 440 718 125 174 928 271 760 228 537 155 44 706 233 419 908 189 916 251 213 678 218 242 243 244 60 966 142 248 758 143 349 783 621 140 301 259 771 645 745 240 953 870 820 264 26 194 525 161 904 270 703 236 22 152 275 799 523 588 709 158 334 107 245 291 739 450 931 139 289 518 932 912 884 774 610 327 6 234 267 43 590 302 426 304 283 306 321 752 285 56 962 312 445 434 319 287 317 765 732 738 519 170 679 407 716 915 995 759 812 432 947 692 573 424 50 336 411 338 726 938 53 512 757 119 126 495 347 348 28 755 907 569 382 311 756 729 25 489 911 48 466 886 624 448 16 345 453 368 369 342 230 372 151 478 269 666 963 172 816 986 274 353 925 104 825 308 847 388 20 880 578 392 544 554 254 476 397 501 685 68 948 373 942 195 227 876 449 454 982 594 223 505 413 997 574 522 417 418 416 363 805 791 72 462 35 265 623 421 278 211 257 315 433 420 246 960 970 625 636 38 472 226 106 992 316 446 465 83 762 515 740 45 668 526 710 813 485 253 562 337 398 991 642 790 374 116 655 538 784 298 144 817 978 656 611 780 477 582 824 658 362 21 882 484 380 952 284 488 97 461 46 492 493 913 803 863 497 735 499 282 482 879 41 438 412 627 260 393 773 510 683 690 296 542 508 717 786 634 332 93 521 720 79 524 553 90 281 205 443 530 531 532 367 59 415 381 455 705 944 528 922 775 266 98 545 612 917 628 749 603 377 272 788 682 494 894 827 927 875 13 561 179 371 719 238 549 220 772 721 563 548 572 471 356 633 576 463 405 339 580 70 865 727 128 810 540 587 498 157 543 591 502 811 77 595 596 579 939 599 868 650 89 247 604 822 606 328 571 754 464 895 178 61 613 750 164 135 840 619 620 973 819 232 550 607 663 866 999 534 630 823 855 632 457 635 878 423 638 889 24 422 314 643 686 708 73 224 401 148 734 385 652 909 216 255 33 34 307 570 670 661 504 954 182 390 511 667 496 486 593 165 672 190 149 294 648 835 479 112 560 547 566 51 684 994 899 395 961 736 950 691 506 693 212 231 567 697 871 834 700 711 605 832 305 357 713 8 444 898 558 946 225 888 76 770 19 698 859 527 689 14 96 967 129 941 516 968 7 601 929 618 641 733 430 539 491 435 436 841 622 741 58 743 414 910 746 333 557 241 647 303 330 358 958 470 67 52 36 614 391 100 137 592 665 806 742 854 237 249 361 219 724 731 329 503 776 64 376 300 536 156 782 252 66 785 763 276 808 901 154 714 723 793 794 84 88 779 17 324 761 801 280 796 804 408 310 565 399 846 378 352 206 972 113 616 490 923 483 677 69 814 659 546 441 410 555 675 187 326 830 256 651 833 235 346 473 121 838 926 609 108 366 843 844 452 114 387 662 849 653 166 202 853 778 568 892 857 937 340 860 150 821 343 701 589 795 867 851 869 159 764 730 988 197 320 427 145 110 49 313 355 268 379 293 885 82 887 279 639 681 891 671 747 297 657 896 384 848 325 900 789 902 897 921 905 54 541 883 10 74 584 598 295 204 688 943 777 918 919 680 3 468 646 123 837 147 826 850 949 930 474 933 564 31 649 751 71 807 207 12 263 559 864 977 78 277 360 105 146 386 425 458 856 350 955 956 583 331 959 845 969 469 858 964 965 831 637 802 290 985 828 792 309 186 192 676 429 103 979 699 654 210 707 852 924 208 351 406 989 990 437 673 702 375 214 996 669 32 753
  REMOVING [631]
========================================================
999 of 1000
 V A L I D    T R E E
*********************************************************
 T E S T:    98
*********************************************************
========================================================

========================================================
                                                             999
                                                             998
                                                     998
                                                             997
                                             997
                                                             996
                                                     996
                                                             995
                                     995
                                                             994
                                                     994
                                                             993
                                             993
                                                             992
                                                             991
                                                     991
                                                             990
                                                     990
                                                             989
                             989
                                                             988
                                                             987
                                                     987
                                                             986
                                                             985
                                                     985
                                                             984
                                             984
                                                             983
                                                     983
                                                             982
                                     982
                                                             981
                                                             980
                                                     980
                                                             979
                                                     979
                                                             978
                                             978
                                                             977
                                                             976
                                                     976
                                                             975
                                             975
                                                             974
                                                     974
                                                             973
                     973
                                                             972
                                                             971
                                                     971
                                                             970
                                                             969
                                                     969
                                                             968
                                                             967
                                             967
                                                             966
                                                             965
                                                     965
                                                             964
                                                             963
                                                     963
                                                             962
                                     962
                                                             961
                                                             960
                                                     960
                                                             959
                                                     959
                                                             958
                                             958
                                                             957
                                                             956
                                                     956
                                                             955
                                             955
                                                             954
                                                     954
                                                             953
                                                             952
                                     952
                                                             951
                                                             950
                                                     950
                                                             949
                                                     949
                                                             948
                                             948
                                                             947
                                                     947
                                                             946
                                                             945
                                                     945
                                                             944
                             944
                                                             943
                                                             942
                                                     942
                                                             941
                                                             940
                                                     940
                                                             939
                                             939
                                                             938
                                                     938
                                                             937
                                     937
                                                             936
                                                             935
                                                     935
                                                             934
                                                             933
                                             933
                                                             932
                                                             931
                                                     931
                                                             930
                                                             929
                     929
                                                             928
                                                     928
                                                             927
                                                             926
                                                     926
                                                             925
                                             925
                                                             924
                                                             923
                                                     923
                                                             922
                                     922
                                                             921
                                                             920
                                                     920
                                                             919
                                                             918
                                             918
                                                             917
                                                     917
                                                             916
                                                             915
                                     915
                                                             914
                                                             913
                                                     913
                                                             912
                                                             911
                                                     911
                                                             910
                                                             909
                                             909
                                                             908
                                                             907
                                                     907
                                                             906
                                                     906
                                                             905
                                                             904
                             904
                                                             903
                                                             902
                                                     902
                                                             901
                                                     901
                                                             900
                                                             899
                                             899
                                                             898
                                                     898
                                                             897
                                     897
                                                             896
                                                             895
                                                     895
                                                             894
                                                     894
                                                             893
                                                             892
                                             892
                                                             891
                                                     891
                                                             890
                                     890
                                                             889
                                                             888
                                                     888
                                                             887
                                             887
                                                             886
                                                             885
                                                     885
                                                             884
                                                             883
                                                     883
                                                             882
             882
                                                             881
                                                             880
                                                     880
                                                             879
                                             879
                                                             878
                                                     878
                                                             877
                                                             876
                                             876
                                                             875
                                                     875
                                                             874
                                     874
                                                             873
                                                             872
                                                     872
                                                             871
                                             871
                                                             870
                                                     870
                                                             869
                                                             868
                                                     868
                                                             867
                             867
                                                             866
                                                             865
                                                     865
                                                             864
                                             864
                                                             863
                                                             862
                                                     862
                                                             861
                                                     861
                                                             860
                                                             859
                                     859
                                                             858
                                                     858
                                                             857
                                                             856
                                                     856
                                                             855
                                             855
                                                             854
                                                     854
                                                             853
                             853
                                                             852
                                                             851
                                                     851
                                                             850
                                                             849
                                                     849
                                                             848
                                             848
                                                             847
                                                     847
                                                             846
                                             846
                                                             845
                                                             844
                                                     844
                                                             843
                                                     843
                                                             842
                                     842
                                                             841
                                                             840
                                                     840
                                                             839
                                             839
                                                             838
                                                             837
                                                     837
                                                             836
                                             836
                                                             835
                                                             834
                                                     834
                                                             833
                                     833
                                                             832
                                                             831
                                                     831
                                                             830
                                             830
                                                             829
                                                             828
                                                     828
                                                             827
                                                     827
                                                             826
                     826
                                                             825
                                                             824
                                                     824
                                                             823
                                             823
                                                             822
                                                             821
                                                     821
                                                             820
                                     820
                                                             819
                                                             818
                                                     818
                                                             817
                                                     817
                                                             816
                                                             815
                                             815
                                                             814
                                                     814
                                                             813
                                                             812
                                                     812
                                                             811
                                     811
                                                             810
                                                             809
                                                     809
                                                             808
                                                     808
                                                             807
                                             807
                                                             806
                                                             805
                                                     805
                                                             804
                                                     804
                                                             803
                                             803
                                                             802
                                                             801
                                                     801
                                                             800
                             800
                                                             799
                                                             798
                                                     798
                                                             797
                                                             796
                                             796
                                                             795
                                                     795
                                                             794
                                                             793
                                     793
                                                             792
                                                             791
                                                     791
                                                             790
                                                             789
                                                     789
                                                             788
                                             788
                                                             787
                                                             786
                                                     786
                                                             785
                                                     785
                                                             784
                                                             783
                                             783
                                                             782
                                                             781
                                                     781
                                                             780
                                                             779
                                                     779
                                                             778
             778
                                                             777
                                                             776
                                                     776
                                                             775
                                                     775
                                                             774
                                             774
                                                             773
                                                             772
                                                     772
                                                             771
                                     771
                                                             770
                                                             769
                                                     769
                                                             768
                                                     768
                                                             767
                                                             766
                                             766
                                                             765
                                                             764
                                                     764
                                                             763
                             763
                                                             762
                                                             761
                                                     761
                                                             760
                                                             759
                                             759
                                                             758
                                                             757
                                                     757
                                                             756
                                     756
                                                             755
                                                             754
                                                     754
                                                             753
                                             753
                                                             752
                                                     752
                                                             751
                     751
                                                             750
                                                             749
                                                     749
                                                             748
                                                     748
                                                             747
                                             747
                                                             746
                                                     746
                                                             745
                                     745
                                                             744
                                                             743
                                                     743
                                                             742
                                             742
                                                             741
                                                             740
                                                     740
                                                             739
                                                             738
                                     738
                                                             737
                                                             736
                                                     736
                                                             735
                                             735
                                                             734
                                                             733
                                                     733
                                                             732
                                                             731
                                             731
                                                             730
                                                             729
                                                     729
                                                             728
                                                     728
                                                             727
                             727
                                                             726
                                                             725
                                                     725
                                                             724
                                                             723
                                             723
                                                             722
                                                             721
                                                     721
                                                             720
                                                             719
                                                     719
                                                             718
                                     718
                                                             717
                                                     717
                                                             716
                                                             715
                                                     715
                                                             714
                                             714
                                                             713
                                                             712
                                                     712
                                                             711
                                                             710
                                             710
                                                             709
                                                     709
                                                             708
     708
                                                             707
                                                             706
                                                     706
                                                             705
                                                     705
                                                             704
                                             704
                                                             703
                                                             702
                                                     702
                                                             701
                                                             700
                                             700
                                                             699
                                                             698
                                                     698
                                                             697
                                                     697
                                                             696
                                     696
                                                             695
                                                             694
                                                     694
                                                             693
                                             693
                                                             692
                                                             691
                                                     691
                                                             690
                                                             689
                                             689
                                                             688
                                                             687
                                                     687
                                                             686
                                                             685
                                                     685
                                                             684
                             684
                                                             683
                                                             682
                                                     682
                                                             681
                                                             680
                                             680
                                                             679
                                                             678
                                                     678
                                                             677
                                                     677
                                                             676
                                             676
                                                             675
                                                     675
                                                             674
                                                             673
                                                     673
                                                             672
                                     672
                                                             671
                                                     671
                                                             670
                                                             669
                                                     669
                                                             668
                                             668
                                                             667
                                                             666
                                                     666
                                                             665
                                                     665
                                                             664
                                     664
                                                             663
                                                     663
                                                             662
                                             662
                                                             661
                                                             660
                                                     660
                                                             659
                                                             658
                     658
                                                             657
                                                             656
                                                     656
                                                             655
                                             655
                                                             654
                                                     654
                                                             653
                                     653
                                                             652
                                                             651
                                                     651
                                                             650
                                                             649
                                             649
                                                             648
                                                             647
                                                     647
                                                             646
                                                     646
                                                             645
                                                             644
                             644
                                                             643
                                                             642
                                                     642
                                                             641
                                             641
                                                             640
                                                             639
                                                     639
                                                             638
                                     638
                                                             637
                                                             636
                                                     636
                                                             635
                                                             634
                                                     634
                                                             633
                                             633
                                                             632
                                                             631
                                                     631
                                                             630
                                                             629
                                                     629
                                                             628
                                             628
                                                             627
                                                     627
                                                             626
                             626
                                                             625
                                                             624
                                                     624
                                                             623
                                             623
                                                             622
                                                             621
                                                     621
                                                             620
                                                     620
                                                             619
                                                             618
                                     618
                                                             617
                                                     617
                                                             616
                                                             615
                                             615
                                                             614
                                                     614
                                                             613
                     613
                                                             612
                                                             611
                                                     611
                                                             610
                                                     610
                                                             609
                                             609
                                                             608
                                                     608
                                                             607
                                     607
                                                             606
                                                             605
                                                     605
                                                             604
                                             604
                                                             603
                                                             602
                                                     602
                                                             601
                                                             600
                             600
                                                             599
                                                     599
                                                             598
                                                             597
                                             597
                                                             596
                                                     596
                                                             595
                                             595
                                                             594
                                                     594
                                                             593
                                     593
                                                             592
                                                             591
                                                     591
                                                             590
                                             590
                                                             589
                                                             588
                                                     588
                                                             587
                                                             586
                                                     586
                                                             585
                                                             584
             584
                                                             583
                                                             582
                                                     582
                                                             581
                                             581
                                                             580
                                                             579
                                                     579
                                                             578
                                             578
                                                             577
                                                             576
                                                     576
                                                             575
                                     575
                                                             574
                                                             573
                                                     573
                                                             572
                                                     572
                                                             571
                                             571
                                                             570
                                                     570
                                                             569
                                                             568
                                                     568
                                                             567
                             567
                                                             566
                                                     566
                                                             565
                                                             564
                                                     564
                                                             563
                                                             562
                                             562
                                                             561
                                                             560
                                                     560
                                                             559
                                     559
                                                             558
                                                             557
                                                     557
                                                             556
                                             556
                                                             555
                                                             554
                                                     554
                                                             553
                     553
                                                             552
                                                             551
                                                     551
                                                             550
                                             550
                                                             549
                                                     549
                                                             548
                                     548
                                                             547
                                                             546
                                                     546
                                                             545
                                             545
                                                             544
                                                     544
                                                             543
                                                             542
                                     542
                                                             541
                                                             540
                                                     540
                                                             539
                                             539
                                                             538
                                                             537
                                                     537
                                                             536
                                                             535
                                                     535
                                                             534
                             534
                                                             533
                                                             532
                                                     532
                                                             531
                                                             530
                                                     530
                                                             529
                                             529
                                                             528
                                                             527
                                                     527
                                                             526
                                                             525
                                     525
                                                             524
                                                             523
                                                     523
                                                             522
                                                     522
                                                             521
                                             521
                                                             520
                                                             519
                                                     519
                                                             518
518
                                                             517
                                                             516
                                                     516
                                                             515
                                                             514
                                             514
                                                             513
                                                             512
                                                     512
                                                             511
                                                     511
                                                             510
                                             510
                                                             509
                                                             508
                                                     508
                                                             507
                                                     507
                                                             506
                                     506
                                                             505
                                                             504
                                                     504
                                                             503
                                                     503
                                                             502
                                                             501
                                             501
                                                             500
                                                             499
                                                     499
                                                             498
                                     498
                                                             497
                                                     497
                                                             496
                                                             495
                                             495
                                                             494
                                                             493
                                                     493
                                                             492
                                             492
                                                             491
                                                     491
                                                             490
                             490
                                                             489
                                                             488
                                                     488
                                                             487
                                                             486
                                                     486
                                                             485
                                             485
                                                             484
                                                     484
                                                             483
                                     483
                                                             482
                                                             481
                                                     481
                                                             480
                                                             479
                                             479
                                                             478
                                                     478
                                                             477
                             477
                                                             476
                                                             475
                                                     475
                                                             474
                                                             473
                                                     473
                                                             472
                                                             471
                                             471
                                                             470
                                                     470
                                                             469
                                                             468
                                             468
                                                             467
                                                     467
                                                             466
                                                             465
                                                     465
                                                             464
                                     464
                                                             463
                                                             462
                                                     462
                                                             461
                                             461
                                                             460
                                                             459
                                                     459
                                                             458
                                             458
                                                             457
                                                     457
                                                             456
                                                             455
                     455
                                                             454
                                                     454
                                                             453
                                                             452
                                                     452
                                                             451
                                             451
                                                             450
                                                     450
                                                             449
                                             449
                                                             448
                                                             447
                                                     447
                                                             446
                                                             445
                                     445
                                                             444
                                                     444
                                                             443
                                                             442
                                             442
                                                             441
                                                     441
                                                             440
                             440
                                                             439
                                                             438
                                                     438
                                                             437
                                             437
                                                             436
                                                             435
                                                     435
                                                             434
                                                     434
                                                             433
                                     433
                                                             432
                                                             431
                                                     431
                                                             430
                                                     430
                                                             429
                                             429
                                                             428
                                                             427
                                                     427
                                                             426
                                                             425
                     425
                                                             424
                                                             423
                                                     423
                                                             422
                                                     422
                                                             421
                                                             420
                                             420
                                                             419
                                                     419
                                                             418
                                     418
                                                             417
                                                             416
                                                     416
                                                             415
                                             415
                                                             414
                                                             413
                                                     413
                                                             412
                                                             411
                             411
                                                             410
                                                             409
                                                     409
                                                             408
                                                             407
                                                     407
                                                             406
                                                             405
                                             405
                                                             404
                                                             403
                                                     403
                                                             402
                                             402
                                                             401
                                                             400
                                                     400
                                                             399
                                     399
                                                             398
                                                             397
                                                     397
                                                             396
                                                             395
                                             395
                                                             394
                                                     394
                                                             393
                                                             392
                                             392
                                                             391
                                                             390
                                                     390
                                                             389
             389
                                                             388
                                                             387
                                                     387
                                                             386
                                                     386
                                                             385
                                             385
                                                             384
                                                             383
                                                     383
                                                             382
                                     382
                                                             381
                                                             380
                                                     380
                                                             379
                                             379
                                                             378
                                                             377
                                                     377
                                                             376
                                                     376
                                                             375
                                     375
                                                             374
                                                             373
                                                     373
                                                             372
                                                     372
                                                             371
                                             371
                                                             370
                                                             369
                                                     369
                                                             368
                                             368
                                                             367
                                                             366
                                                     366
                                                             365
                                                             364
                                                     364
                                                             363
                             363
                                                             362
                                                             361
                                                     361
                                                             360
                                                             359
                                             359
                                                             358
                                                             357
                                                     357
                                                             356
                                             356
                                                             355
                                                             354
                                                     354
                                                             353
                                                     353
                                                             352
                                     352
                                                             351
                                                             350
                                                     350
                                                             349
                                             349
                                                             348
                                                     348
                                                             347
                             347
                                                             346
                                                             345
                                                     345
                                                             344
                                             344
                                                             343
                                                             342
                                                     342
                                                             341
                                     341
                                                             340
                                                             339
                                                     339
                                                             338
                                                             337
                                             337
                                                             336
                                                     336
                                                             335
                     335
                                                             334
                                                             333
                                                     333
                                                             332
                                                             331
                                             331
                                                             330
                                                     330
                                                             329
                                                             328
                                     328
                                                             327
                                                             326
                                                     326
                                                             325
                                             325
                                                             324
                                                     324
                                                             323
                                     323
                                                             322
                                                             321
                                                     321
                                                             320
                                                             319
                                             319
                                                             318
                                                     318
                                                             317
                                                             316
                                             316
                                                             315
                                                     315
                                                             314
                                                             313
                             313
                                                             312
                                                             311
                                                     311
                                                             310
                                             310
                                                             309
                                                             308
                                                     308
                                                             307
                                     307
                                                             306
                                                             305
                                                     305
                                                             304
                                             304
                                                             303
                                                             302
                                                     302
                                                             301
                                                     301
                                                             300
             300
                                                             299
                                                             298
                                                     298
                                                             297
                                             297
                                                             296
                                                             295
                                                     295
                                                             294
                                     294
                                                             293
                                                             292
                                                     292
                                                             291
                                             291
                                                             290
                                                             289
                                                     289
                                                             288
                             288
                                                             287
                                                             286
                                                     286
                                                             285
                                             285
                                                             284
                                                             283
                                                     283
                                                             282
                                             282
                                                             281
                                                     281
                                                             280
                                                             279
                                     279
                                                             278
                                                             277
                                                     277
                                                             276
                                                     276
                                                             275
                                             275
                                                             274
                                                             273
                                                     273
                                                             272
                                                             271
                                             271
                                                             270
                                                     270
                                                             269
                     269
                                                             268
                                                             267
                                                     267
                                                             266
                                             266
                                                             265
                                                     265
                                                             264
                                     264
                                                             263
                                                             262
                                                     262
                                                             261
                                                             260
                                                     260
                                                             259
                                             259
                                                             258
                                                             257
                                                     257
                                                             256
                                                             255
                             255
                                                             254
                                                     254
                                                             253
                                             253
                                                             252
                                                             251
                                                     251
                                                             250
                                             250
                                                             249
                                                     249
                                                             248
                                     248
                                                             247
                                                             246
                                                     246
                                                             245
                                             245
                                                             244
                                                             243
                                                     243
                                                             242
                             242
                                                             241
                                                             240
                                                     240
                                                             239
                                             239
                                                             238
                                                     238
                                                             237
                                                             236
                                     236
                                                             235
                                                     235
                                                             234
                                                             233
                                                     233
                                                             232
                                             232
                                                             231
                                                     231
                                                             230
                                     230
                                                             229
                                                             228
                                                     228
                                                             227
                                                             226
                                             226
                                                             225
                                                     225
                                                             224
                                                             223
                                             223
                                                             222
                                                     222
                                                             221
     221
                                                             220
                                                             219
                                                     219
                                                             218
                                             218
                                                             217
                                                             216
                                                     216
                                                             215
                                     215
                                                             214
                                                             213
                                                     213
                                                             212
                                             212
                                                             211
                                                     211
                                                             210
                                                             209
                                     209
                                                             208
                                                             207
                                                     207
                                                             206
                                                     206
                                                             205
                                             205
                                                             204
                                                     204
                                                             203
                             203
                                                             202
                                                             201
                                                     201
                                                             200
                                                     200
                                                             199
                                             199
                                                             198
                                                             197
                                                     197
                                                             196
                                                             195
                                                     195
                                                             194
                                     194
                                                             193
                                                             192
                                                     192
                                                             191
                                             191
                                                             190
                                                     190
                                                             189
                             189
                                                             188
                                                             187
                                                     187
                                                             186
                                                             185
                                             185
                                                             184
                                                     184
                                                             183
                                             183
                                                             182
                                                             181
                                                     181
                                                             180
                                                             179
                                                     179
                                                             178
                                     178
                                                             177
                                                             176
                                                     176
                                                             175
                                                             174
                                                     174
                                                             173
                                             173
                                                             172
                                                     172
                                                             171
                     171
                                                             170
                                                             169
                                                     169
                                                             168
                                             168
                                                             167
                                                     167
                                                             166
                                                             165
                                                     165
                                                             164
                                     164
                                                             163
                                                             162
                                                     162
                                                             161
                                                             160
                                             160
                                                             159
                                                     159
                                                             158
                                             158
                                                             157
                                                             156
                                                     156
                                                             155
                                                     155
                                                             154
                             154
                                                             153
                                                             152
                                                     152
                                                             151
                                                             150
                                             150
                                                             149
                                                             148
                                                     148
                                                             147
                                             147
                                                             146
                                                             145
                                                     145
                                                             144
                                                             143
                                     143
                                                             142
                                                             141
                                                     141
                                                             140
                                                     140
                                                             139
                                             139
                                                             138
                                                             137
                                                     137
                                                             136
                                             136
                                                             135
                                                             134
                                                     134
                                                             133
                     133
                                                             132
                                                             131
                                                     131
                                                             130
                                             130
                                                             129
                                                             128
                                                     128
                                                             127
                                     127
                                                             126
                                                             125
                                                     125
                                                             124
                                                     124
                                                             123
                                             123
                                                             122
                                                             121
                                                     121
                                                             120
                                                             119
                             119
                                                             118
                                                             117
                                                     117
                                                             116
                                                             115
                                                     115
                                                             114
                                                             113
                                             113
                                                             112
                                                             111
                                                     111
                                                             110
                                                     110
                                                             109
                                     109
                                                             108
                                                             107
                                                     107
                                                             106
                                                             105
                                             105
                                                             104
                                                             103
                                                     103
                                                             102
                                             102
                                                             101
                                                             100
                                                     100
                                                              99
                              99
                                                              98
                                                              97
                                                      97
                                                              96
                                                              95
                                              95
                                                              94
                                                              93
                                                      93
                                                              92
                                      92
                                                              91
                                                              90
                                                      90
                                                              89
                                              89
                                                              88
                                                      88
                                                              87
                                                              86
                                                      86
                                                              85
                                      85
                                                              84
                                                              83
                                                      83
                                                              82
                                                      82
                                                              81
                                                              80
                                              80
                                                              79
                                                      79
                                                              78
                                                              77
                                                      77
                                                              76
                                              76
                                                              75
                                                              74
                                                      74
                                                              73
                                                              72
                                                      72
                                                              71
              71
                                                              70
                                                      70
                                                              69
                                                              68
                                                      68
                                                              67
                                              67
                                                              66
                                                      66
                                                              65
                                      65
                                                              64
                                                              63
                                                      63
                                                              62
                                                              61
                                              61
                                                              60
                                                              59
                                                      59
                                                              58
                                                              57
                              57
                                                              56
                                                              55
                                                      55
                                                              54
                                                              53
                                              53
                                                              52
                                                      52
                                                              51
                                                              50
                                      50
                                                              49
                                                      49
                                                              48
                                              48
                                                              47
                                                              46
                                                      46
                                                              45
                              45
                                                              44
                                                              43
                                                      43
                                                              42
                                                      42
                                                              41
                                                              40
                                              40
                                                              39
                                                              38
                                                      38
                                                              37
                                      37
                                                              36
                                                              35
                                                      35
                                                              34
                                              34
                                                              33
                                                              32
                                                      32
                                                              31
                                                              30
                      30
                                                              29
                                                              28
                                                      28
                                                              27
                                                      27
                                                              26
                                              26
                                                              25
                                                      25
                                                              24
                                                              23
                                      23
                                                              22
                                                      22
                                                              21
                                              21
                                                              20
                                                      20
                                                              19
                                                              18
                                              18
                                                              17
                                                              16
                                                      16
                                                              15
                              15
                                                              14
                                                      14
                                                              13
                                                              12
                                                      12
                                                              11
                                              11
                                                              10
                                                      10
                                                               9
                                       9
                                                               8
                                                       8
                                                               7
                                                               6
                                                       6
                                                               5
                                                               4
                                               4
                                                               3
                                                               2
                                                       2
                                                               1
                                                       1
                                                               0


========================================================
             771
     771
             482
482
             278
     278
              69

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 962 427 775 823 716 357 552 396 751 739 560 793 655 129 398 875 42 901 99 981 406 770 843 633 397 897 231 937 938 334 848 108 811 303 591 559 347 697 853 692 834 413 131 561 222 431 195 377 16 484 240 702 68 390 235 625 663 573 6 825 286 860 289 52 73 916 798 31 699 71 818 349 299 704 768 149 927 763 789 983 324 330 202 553 615 993 641 607 65 280 249 392 460 175 4 325 12 259 670 353 984 893 753 434 288 276 589 632 90 782 62 737 765 646 658 651 513 713 252 153 668 521 408 906 982 639 701 677 66 932 346 176 444 951 380 141 650 556 679 201 435 209 491 477 804 178 678 905 146 908 791 858 998 58 953 866 543 443 773 736 861 912 774 379 14 805 745 813 385 507 356 859 652 426 987 137 537 371 626 359 22 89 619 245 890 461 844 455 985 777 587 884 100 124 414 366 284 900 468 30 103 628 354 876 903 342 387 529 60 898 779 725 40 26 867 934 186 112 712 469 257 803 437 466 75 247 11 852 341 189 575 943 833 999 946 816 889 662 807 180 600 407 92 322 808 440 762 891 977 707 158 428 3 150 166 582 215 837 393 584 784 145 229 410 841 709 41 845 694 261 420 746 135 718 781 794 515 706 695 190 152 161 104 960 714 367 873 220 907 576 450 418 196 902 788 511 265 432 831 56 122 812 294 580 232 84 363 590 666 809 304 700 688 854 606 409 616 313 355 287 451 132 764 996 439 624 142 221 470 754 870 522 87 394 577 416 567 735 327 326 159 760 846 588 9 456 562 538 806 370 230 91 499 980 621 193 117 70 473 492 973 986 869 715 210 847 874 316 493 959 835 315 331 338 448 930 144 979 878 514 827 266 892 487 384 218 8 228 77 750 506 248 524 123 33 462 107 162 167 474 21 530 27 417 446 485 216 273 719 840 597 879 623 320 429 780 776 38 877 314 723 931 548 339 620 203 424 360 976 47 217 165 500 106 669 612 554 862 140 311 925 917 447 608 147 990 839 310 463 636 388 842 796 160 498 227 531 271 85 130 613 128 126 403 629 345 949 191 471 829 826 335 425 705 814 79 464 94 634 358 571 881 44 972 851 125 18 954 941 401 80 971 438 317 767 744 98 605 260 578 542 28 792 601 942 933 523 197 88 740 547 660 742 532 894 237 569 120 693 939 365 312 496 540 181 364 494 400 483 863 945 544 546 769 472 786 78 743 994 411 295 611 415 910 7 399 381 481 637 208 200 549 516 534 219 185 772 551 272 467 967 974 343 585 51 423 298 275 205 947 685 170 755 95 453 422 174 555 586 171 352 274 850 226 935 649 395 989 297 268 204 857 642 618 246 13 54 32 154 672 254 465 579 74 756 727 36 622 888 638 872 691 10 321 225 368 728 441 896 5 721 449 924 351 480 115 386 849 300 970 617 82 267 111 748 749 486 885 25 61 458 922 501 93 15 37 505 630 975 86 177 717 541 101 991 647 536 880 604 683 323 383 539 594 269 592 654 361 504 139 911 595 883 978 308 882 965 290 223 734 53 292 656 741 724 961 258 20 687 936 169 790 614 116 680 211 263 270 148 969 433 333 127 565 689 72 758 645 213 761 926 684 526 671 545 194 489 733 610 459 564 119 452 17 865 277 282 55 703 593 49 676 730 81 319 436 527 710 192 681 799 184 305 568 682 602 525 627 664 899 382 802 63 921 596 509 599 23 864 696 738 182 583 143 778 340 118 179 635 720 895 293 909 307 121 168 698 243 46 328 820 609 2 442 708 512 114 110 603 785 233 283 886 726 913 454 810 958 164 136 535 34 133 64 163 598 478 172 992 430 238 187 955 102 373 212 405 957 457 151 731 183 520 255 944 24 285 134 508 50 67 729 59 445 732 968 640 262 488 224 995 173 43 766 643 306 950 372 821 412 887 296 105 198 244 251 550 45 752 332 675 673 419 659 19 256 557 574 113 329 518 817 199 369 138 35 156 648 344 250 39 510 234 674 337 402 815 923 915 301 76 350 918 856 479 952 83 914 747 239 558 644 838 214 830 519 940 690 309 653 572 362 533 241 948 855 836 497 904 801 236 528 374 495 871 657 929 188 832 928 997 919 391 797 824 868 787 665 503 667 207 475 490 0 566 1 109 686 264 570 96 711 631 502 375 389 404 963 421 757 302 253 378 348 97 966 157 828 291 57 517 822 336 242 206 476 722 318 279 964 563 920 988 800 759 661 956 581 819 783 29 376 795 281 48 155   from: 518 885 477 708 882 133 6 532 8 9 649 898 221 759 14 15 30 553 584 751 20 21 488 735 897 25 680 826 626 154 576 109 935 113 121 147 575 727 566 269 389 567 778 48 599 45 481 483 394 49 993 651 658 864 363 405 846 57 242 482 437 61 833 171 46 65 335 721 570 361 70 71 356 235 92 152 559 915 352 315 684 800 42 10 189 99 100 865 814 139 702 348 243 359 449 119 851 203 98 85 455 275 219 644 211 105 683 707 859 26 444 534 190 371 88 917 648 176 402 506 572 689 662 264 300 454 731 127 989 779 130 178 944 764 962 548 973 914 409 617 839 128 47 425 729 162 146 763 654 150 436 783 55 167 37 440 974 387 145 701 368 571 448 573 164 995 375 539 815 433 170 241 842 581 473 313 385 583 853 179 745 370 353 646 231 310 285 187 633 560 63 323 925 59 194 771 858 4 2 199 507 138 202 982 218 527 422 557 253 50 161 374 376 236 183 415 216 24 984 265 909 153 590 516 631 913 115 600 693 850 978 184 288 254 83 660 933 671 238 776 574 270 215 123 791 245 347 556 979 249 947 40 413 510 76 188 550 675 411 259 728 392 445 499 734 102 414 11 1 274 793 746 103 613 896 949 276 588 672 279 95 281 64 609 225 75 594 386 151 289 382 304 994 324 723 418 34 983 795 299 124 12 604 447 798 562 0 307 807 230 719 311 312 830 916 79 525 168 820 429 476 663 904 439 229 450 911 614 328 938 928 390 346 333 334 74 336 22 23 817 894 417 682 136 344 28 972 677 200 349 789 372 89 881 206 355 255 192 3 712 714 131 538 743 852 309 366 653 226 369 172 228 470 929 709 887 920 367 796 427 726 700 861 204 384 643 547 490 661 992 912 669 948 393 627 615 725 586 937 593 524 457 855 954 674 694 217 391 521 32 939 52 883 135 112 549 419 489 239 416 676 212 812 18 906 143 294 322 282 652 205 80 965 399 434 931 522 738 144 990 943 737 271 197 656 874 82 441 568 891 155 380 287 867 420 442 607 297 458 459 945 724 952 529 464 222 77 137 902 291 758 424 472 946 717 801 785 342 478 451 589 514 296 816 811 963 907 266 730 341 832 924 56 339 808 564 710 497 498 158 321 501 740 503 551 165 398 899 996 509 340 511 591 691 756 843 696 636 540 519 520 692 284 718 357 809 936 908 163 421 690 295 7 533 537 704 177 845 362 404 471 561 542 890 544 90 320 841 443 602 31 784 552 327 997 407 491 697 39 262 623 505 305 543 267 951 462 918 118 794 182 739 258 715 821 36 558 768 578 426 66 831 582 569 395 762 195 587 210 91 38 592 873 292 330 878 54 597 788 699 774 886 531 942 641 605 889 173 608 244 610 668 612 628 198 480 502 528 618 819 620 467 781 678 73 625 308 579 290 940 512 606 175 647 624 114 634 201 638 876 640 772 93 469 224 492 186 639 870 919 650 51 967 504 62 655 664 500 673 871 181 81 961 603 496 60 110 180 611 58 33 379 72 423 517 351 314 905 803 301 966 705 234 13 316 685 637 687 642 69 283 749 515 834 246 695 479 44 403 868 484 555 545 703 847 159 666 107 827 223 485 630 632 713 117 209 716 535 318 248 720 901 722 980 122 101 554 148 872 452 866 237 286 350 769 733 736 19 104 934 595 475 742 755 744 879 900 747 191 207 263 125 752 753 754 596 208 757 132 748 775 773 585 888 156 432 766 257 577 823 108 397 863 232 767 461 530 777 880 169 523 410 487 325 580 126 526 787 598 166 790 955 792 213 326 408 401 999 838 799 958 317 17 456 804 805 806 659 991 508 836 256 621 813 354 196 27 493 818 619 396 922 971 964 824 825 957 840 78 513 985 140 273 67 377 142 810 141 278 84 468 174 665 854 844 430 732 378 848 849 541 565 923 29 388 332 306 364 998 360 860 120 862 975 220 68 969 474 657 869 698 365 616 486 233 875 193 338 941 667 932 345 438 412 884 268 601 358 35 782 446 921 892 893 453 895 835 303 149 329 214 16 129 903 927 97 910 670 750 563 157 635 463 856 877 681 373 293 829 761 431 466 280 381 987 460 111 926 240 770 645 337 277 780 406 383 988 711 495 622 116 765 828 343 536 546 227 250 261 802 688 686 741 953 950 679 956 970 5 959 857 298 302 247 465 106 428 786 968 251 272 134 837 96 400 160 976 760 260 494 41 981 87 185 435 977 986 43 822 629 53 86 331 930 706 252 960 319 94 797
  REMOVING [69]
========================================================
996 of 1000
========================================================
     771
771
     482
482
     278

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 962 427 775 823 716 357 552 396 751 739 560 793 655 129 398 875 42 901 99 981 406 770 843 633 397 897 231 937 938 334 848 108 811 303 591 559 347 697 853 692 834 413 131 561 222 431 195 377 16 484 240 702 68 390 235 625 663 573 6 825 286 860 289 52 73 916 798 31 699 71 818 349 299 704 768 149 927 763 789 983 324 330 202 553 615 993 641 607 65 280 249 392 460 175 4 325 12 259 670 353 984 893 753 434 288 276 589 632 90 782 62 737 765 646 658 651 513 713 252 153 668 521 408 906 982 639 701 677 66 932 346 176 444 951 380 141 650 556 679 201 435 209 491 477 804 178 678 905 146 908 791 858 998 58 953 866 543 443 773 736 861 912 774 379 14 805 745 813 385 507 356 859 652 426 987 137 537 371 626 359 22 89 619 245 890 461 844 455 985 777 587 884 100 124 414 366 284 900 468 30 103 628 354 876 903 342 387 529 60 898 779 725 40 26 867 934 186 112 712 469 257 803 437 466 75 247 11 852 341 189 575 943 833 999 946 816 889 662 807 180 600 407 92 322 808 440 762 891 977 707 158 428 3 150 166 582 215 837 393 584 784 145 229 410 841 709 41 845 694 261 420 746 135 718 781 794 515 706 695 190 152 161 104 960 714 367 873 220 907 576 450 418 196 902 788 511 265 432 831 56 122 812 294 580 232 84 363 590 666 809 304 700 688 854 606 409 616 313 355 287 451 132 764 996 439 624 142 221 470 754 870 522 87 394 577 416 567 735 327 326 159 760 846 588 9 456 562 538 806 370 230 91 499 980 621 193 117 70 473 492 973 986 869 715 210 847 874 316 493 959 835 315 331 338 448 930 144 979 878 514 827 266 892 487 384 218 8 228 77 750 506 248 524 123 33 462 107 162 167 474 21 530 27 417 446 485 216 273 719 840 597 879 623 320 429 780 776 38 877 314 723 931 548 339 620 203 424 360 976 47 217 165 500 106 669 612 554 862 140 311 925 917 447 608 147 990 839 310 463 636 388 842 796 160 498 227 531 271 85 130 613 128 126 403 629 345 949 191 471 829 826 335 425 705 814 79 464 94 634 358 571 881 44 972 851 125 18 954 941 401 80 971 438 317 767 744 98 605 260 578 542 28 792 601 942 933 523 197 88 740 547 660 742 532 894 237 569 120 693 939 365 312 496 540 181 364 494 400 483 863 945 544 546 769 472 786 78 743 994 411 295 611 415 910 7 399 381 481 637 208 200 549 516 534 219 185 772 551 272 467 967 974 343 585 51 423 298 275 205 947 685 170 755 95 453 422 174 555 586 171 352 274 850 226 935 649 395 989 297 268 204 857 642 618 246 13 54 32 154 672 254 465 579 74 756 727 36 622 888 638 872 691 10 321 225 368 728 441 896 5 721 449 924 351 480 115 386 849 300 970 617 82 267 111 748 749 486 885 25 61 458 922 501 93 15 37 505 630 975 86 177 717 541 101 991 647 536 880 604 683 323 383 539 594 269 592 654 361 504 139 911 595 883 978 308 882 965 290 223 734 53 292 656 741 724 961 258 20 687 936 169 790 614 116 680 211 263 270 148 969 433 333 127 565 689 72 758 645 213 761 926 684 526 671 545 194 489 733 610 459 564 119 452 17 865 277 282 55 703 593 49 676 730 81 319 436 527 710 192 681 799 184 305 568 682 602 525 627 664 899 382 802 63 921 596 509 599 23 864 696 738 182 583 143 778 340 118 179 635 720 895 293 909 307 121 168 698 243 46 328 820 609 2 442 708 512 114 110 603 785 233 283 886 726 913 454 810 958 164 136 535 34 133 64 163 598 478 172 992 430 238 187 955 102 373 212 405 957 457 151 731 183 520 255 944 24 285 134 508 50 67 729 59 445 732 968 640 262 488 224 995 173 43 766 643 306 950 372 821 412 887 296 105 198 244 251 550 45 752 332 675 673 419 659 19 256 557 574 113 329 518 817 199 369 138 35 156 648 344 250 39 510 234 674 337 402 815 923 915 301 76 350 918 856 479 952 83 914 747 239 558 644 838 214 830 519 940 690 309 653 572 362 533 241 948 855 836 497 904 801 236 528 374 495 871 657 929 188 832 928 997 919 391 797 824 868 787 665 503 667 207 475 490 0 566 1 109 686 264 570 96 711 631 502 375 389 404 963 421 757 302 253 378 348 97 966 157 828 291 57 517 822 336 242 206 476 722 318 279 964 563 920 988 800 759 661 956 581 819 783 29 376 795 281 48 155 69   from: 518 885 477 708 882 133 6 532 8 9 649 898 221 759 14 15 30 553 584 751 20 21 488 735 897 25 680 826 626 154 576 109 935 113 121 147 575 727 566 269 389 567 778 48 599 45 481 483 394 49 993 651 658 864 363 405 846 57 242 482 437 61 833 171 46 65 335 721 570 361 70 71 356 235 92 152 559 915 352 315 684 800 42 10 189 99 100 865 814 139 702 348 243 359 449 119 851 203 98 85 455 275 219 644 211 105 683 707 859 26 444 534 190 371 88 917 648 176 402 506 572 689 662 264 300 454 731 127 989 779 130 178 944 764 962 548 973 914 409 617 839 128 47 425 729 162 146 763 654 150 436 783 55 167 37 440 974 387 145 701 368 571 448 573 164 995 375 539 815 433 170 241 842 581 473 313 385 583 853 179 745 370 353 646 231 310 285 187 633 560 63 323 925 59 194 771 858 4 2 199 507 138 202 982 218 527 422 557 253 50 161 374 376 236 183 415 216 24 984 265 909 153 590 516 631 913 115 600 693 850 978 184 288 254 83 660 933 671 238 776 574 270 215 123 791 245 347 556 979 249 947 40 413 510 76 188 550 675 411 259 728 392 445 499 734 102 414 11 1 274 793 746 103 613 896 949 276 588 672 279 95 281 64 609 225 75 594 386 151 289 382 304 994 324 723 418 34 983 795 299 124 12 604 447 798 562 0 307 807 230 719 311 312 830 916 79 525 168 820 429 476 663 904 439 229 450 911 614 328 938 928 390 346 333 334 74 336 22 23 817 894 417 682 136 344 28 972 677 200 349 789 372 89 881 206 355 255 192 3 712 714 131 538 743 852 309 366 653 226 369 172 228 470 929 709 887 920 367 796 427 726 700 861 204 384 643 547 490 661 992 912 669 948 393 627 615 725 586 937 593 524 457 855 954 674 694 217 391 521 32 939 52 883 135 112 549 419 489 239 416 676 212 812 18 906 143 294 322 282 652 205 80 965 399 434 931 522 738 144 990 943 737 271 197 656 874 82 441 568 891 155 380 287 867 420 442 607 297 458 459 945 724 952 529 464 222 77 137 902 291 758 424 472 946 717 801 785 342 478 451 589 514 296 816 811 963 907 266 730 341 832 924 56 339 808 564 710 497 498 158 321 501 740 503 551 165 398 899 996 509 340 511 591 691 756 843 696 636 540 519 520 692 284 718 357 809 936 908 163 421 690 295 7 533 537 704 177 845 362 404 471 561 542 890 544 90 320 841 443 602 31 784 552 327 997 407 491 697 39 262 623 505 305 543 267 951 462 918 118 794 182 739 258 715 821 36 558 768 578 426 66 831 582 569 395 762 195 587 210 91 38 592 873 292 330 878 54 597 788 699 774 886 531 942 641 605 889 173 608 244 610 668 612 628 198 480 502 528 618 819 620 467 781 678 73 625 308 579 290 940 512 606 175 647 624 114 634 201 638 876 640 772 93 469 224 492 186 639 870 919 650 51 967 504 62 655 664 500 673 871 181 81 961 603 496 60 110 180 611 58 33 379 72 423 517 351 314 905 803 301 966 705 234 13 316 685 637 687 642 69 283 749 515 834 246 695 479 44 403 868 484 555 545 703 847 159 666 107 827 223 485 630 632 713 117 209 716 535 318 248 720 901 722 980 122 101 554 148 872 452 866 237 286 350 769 733 736 19 104 934 595 475 742 755 744 879 900 747 191 207 263 125 752 753 754 596 208 757 132 748 775 773 585 888 156 432 766 257 577 823 108 397 863 232 767 461 530 777 880 169 523 410 487 325 580 126 526 787 598 166 790 955 792 213 326 408 401 999 838 799 958 317 17 456 804 805 806 659 991 508 836 256 621 813 354 196 27 493 818 619 396 922 971 964 824 825 957 840 78 513 985 140 273 67 377 142 810 141 278 84 468 174 665 854 844 430 732 378 848 849 541 565 923 29 388 332 306 364 998 360 860 120 862 975 220 68 969 474 657 869 698 365 616 486 233 875 193 338 941 667 932 345 438 412 884 268 601 358 35 782 446 921 892 893 453 895 835 303 149 329 214 16 129 903 927 97 910 670 750 563 157 635 463 856 877 681 373 293 829 761 431 466 280 381 987 460 111 926 240 770 645 337 277 780 406 383 988 711 495 622 116 765 828 343 536 546 227 250 261 802 688 686 741 953 950 679 956 970 5 959 857 298 302 247 465 106 428 786 968 251 272 134 837 96 400 160 976 760 260 494 41 981 87 185 435 977 986 43 822 629 53 86 331 930 706 252 960 319 94 797
  REMOVING [482]
========================================================
997 of 1000
========================================================
     771
771
     278

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 962 427 775 823 716 357 552 396 751 739 560 793 655 129 398 875 42 901 99 981 406 770 843 633 397 897 231 937 938 334 848 108 811 303 591 559 347 697 853 692 834 413 131 561 222 431 195 377 16 484 240 702 68 390 235 625 663 573 6 825 286 860 289 52 73 916 798 31 699 71 818 349 299 704 768 149 927 763 789 983 324 330 202 553 615 993 641 607 65 280 249 392 460 175 4 325 12 259 670 353 984 893 753 434 288 276 589 632 90 782 62 737 765 646 658 651 513 713 252 153 668 521 408 906 982 639 701 677 66 932 346 176 444 951 380 141 650 556 679 201 435 209 491 477 804 178 678 905 146 908 791 858 998 58 953 866 543 443 773 736 861 912 774 379 14 805 745 813 385 507 356 859 652 426 987 137 537 371 626 359 22 89 619 245 890 461 844 455 985 777 587 884 100 124 414 366 284 900 468 30 103 628 354 876 903 342 387 529 60 898 779 725 40 26 867 934 186 112 712 469 257 803 437 466 75 247 11 852 341 189 575 943 833 999 946 816 889 662 807 180 600 407 92 322 808 440 762 891 977 707 158 428 3 150 166 582 215 837 393 584 784 145 229 410 841 709 41 845 694 261 420 746 135 718 781 794 515 706 695 190 152 161 104 960 714 367 873 220 907 576 450 418 196 902 788 511 265 432 831 56 122 812 294 580 232 84 363 590 666 809 304 700 688 854 606 409 616 313 355 287 451 132 764 996 439 624 142 221 470 754 870 522 87 394 577 416 567 735 327 326 159 760 846 588 9 456 562 538 806 370 230 91 499 980 621 193 117 70 473 492 973 986 869 715 210 847 874 316 493 959 835 315 331 338 448 930 144 979 878 514 827 266 892 487 384 218 8 228 77 750 506 248 524 123 33 462 107 162 167 474 21 530 27 417 446 485 216 273 719 840 597 879 623 320 429 780 776 38 877 314 723 931 548 339 620 203 424 360 976 47 217 165 500 106 669 612 554 862 140 311 925 917 447 608 147 990 839 310 463 636 388 842 796 160 498 227 531 271 85 130 613 128 126 403 629 345 949 191 471 829 826 335 425 705 814 79 464 94 634 358 571 881 44 972 851 125 18 954 941 401 80 971 438 317 767 744 98 605 260 578 542 28 792 601 942 933 523 197 88 740 547 660 742 532 894 237 569 120 693 939 365 312 496 540 181 364 494 400 483 863 945 544 546 769 472 786 78 743 994 411 295 611 415 910 7 399 381 481 637 208 200 549 516 534 219 185 772 551 272 467 967 974 343 585 51 423 298 275 205 947 685 170 755 95 453 422 174 555 586 171 352 274 850 226 935 649 395 989 297 268 204 857 642 618 246 13 54 32 154 672 254 465 579 74 756 727 36 622 888 638 872 691 10 321 225 368 728 441 896 5 721 449 924 351 480 115 386 849 300 970 617 82 267 111 748 749 486 885 25 61 458 922 501 93 15 37 505 630 975 86 177 717 541 101 991 647 536 880 604 683 323 383 539 594 269 592 654 361 504 139 911 595 883 978 308 882 965 290 223 734 53 292 656 741 724 961 258 20 687 936 169 790 614 116 680 211 263 270 148 969 433 333 127 565 689 72 758 645 213 761 926 684 526 671 545 194 489 733 610 459 564 119 452 17 865 277 282 55 703 593 49 676 730 81 319 436 527 710 192 681 799 184 305 568 682 602 525 627 664 899 382 802 63 921 596 509 599 23 864 696 738 182 583 143 778 340 118 179 635 720 895 293 909 307 121 168 698 243 46 328 820 609 2 442 708 512 114 110 603 785 233 283 886 726 913 454 810 958 164 136 535 34 133 64 163 598 478 172 992 430 238 187 955 102 373 212 405 957 457 151 731 183 520 255 944 24 285 134 508 50 67 729 59 445 732 968 640 262 488 224 995 173 43 766 643 306 950 372 821 412 887 296 105 198 244 251 550 45 752 332 675 673 419 659 19 256 557 574 113 329 518 817 199 369 138 35 156 648 344 250 39 510 234 674 337 402 815 923 915 301 76 350 918 856 479 952 83 914 747 239 558 644 838 214 830 519 940 690 309 653 572 362 533 241 948 855 836 497 904 801 236 528 374 495 871 657 929 188 832 928 997 919 391 797 824 868 787 665 503 667 207 475 490 0 566 1 109 686 264 570 96 711 631 502 375 389 404 963 421 757 302 253 378 348 97 966 157 828 291 57 517 822 336 242 206 476 722 318 279 964 563 920 988 800 759 661 956 581 819 783 29 376 795 281 48 155 69 482   from: 518 885 477 708 882 133 6 532 8 9 649 898 221 759 14 15 30 553 584 751 20 21 488 735 897 25 680 826 626 154 576 109 935 113 121 147 575 727 566 269 389 567 778 48 599 45 481 483 394 49 993 651 658 864 363 405 846 57 242 482 437 61 833 171 46 65 335 721 570 361 70 71 356 235 92 152 559 915 352 315 684 800 42 10 189 99 100 865 814 139 702 348 243 359 449 119 851 203 98 85 455 275 219 644 211 105 683 707 859 26 444 534 190 371 88 917 648 176 402 506 572 689 662 264 300 454 731 127 989 779 130 178 944 764 962 548 973 914 409 617 839 128 47 425 729 162 146 763 654 150 436 783 55 167 37 440 974 387 145 701 368 571 448 573 164 995 375 539 815 433 170 241 842 581 473 313 385 583 853 179 745 370 353 646 231 310 285 187 633 560 63 323 925 59 194 771 858 4 2 199 507 138 202 982 218 527 422 557 253 50 161 374 376 236 183 415 216 24 984 265 909 153 590 516 631 913 115 600 693 850 978 184 288 254 83 660 933 671 238 776 574 270 215 123 791 245 347 556 979 249 947 40 413 510 76 188 550 675 411 259 728 392 445 499 734 102 414 11 1 274 793 746 103 613 896 949 276 588 672 279 95 281 64 609 225 75 594 386 151 289 382 304 994 324 723 418 34 983 795 299 124 12 604 447 798 562 0 307 807 230 719 311 312 830 916 79 525 168 820 429 476 663 904 439 229 450 911 614 328 938 928 390 346 333 334 74 336 22 23 817 894 417 682 136 344 28 972 677 200 349 789 372 89 881 206 355 255 192 3 712 714 131 538 743 852 309 366 653 226 369 172 228 470 929 709 887 920 367 796 427 726 700 861 204 384 643 547 490 661 992 912 669 948 393 627 615 725 586 937 593 524 457 855 954 674 694 217 391 521 32 939 52 883 135 112 549 419 489 239 416 676 212 812 18 906 143 294 322 282 652 205 80 965 399 434 931 522 738 144 990 943 737 271 197 656 874 82 441 568 891 155 380 287 867 420 442 607 297 458 459 945 724 952 529 464 222 77 137 902 291 758 424 472 946 717 801 785 342 478 451 589 514 296 816 811 963 907 266 730 341 832 924 56 339 808 564 710 497 498 158 321 501 740 503 551 165 398 899 996 509 340 511 591 691 756 843 696 636 540 519 520 692 284 718 357 809 936 908 163 421 690 295 7 533 537 704 177 845 362 404 471 561 542 890 544 90 320 841 443 602 31 784 552 327 997 407 491 697 39 262 623 505 305 543 267 951 462 918 118 794 182 739 258 715 821 36 558 768 578 426 66 831 582 569 395 762 195 587 210 91 38 592 873 292 330 878 54 597 788 699 774 886 531 942 641 605 889 173 608 244 610 668 612 628 198 480 502 528 618 819 620 467 781 678 73 625 308 579 290 940 512 606 175 647 624 114 634 201 638 876 640 772 93 469 224 492 186 639 870 919 650 51 967 504 62 655 664 500 673 871 181 81 961 603 496 60 110 180 611 58 33 379 72 423 517 351 314 905 803 301 966 705 234 13 316 685 637 687 642 69 283 749 515 834 246 695 479 44 403 868 484 555 545 703 847 159 666 107 827 223 485 630 632 713 117 209 716 535 318 248 720 901 722 980 122 101 554 148 872 452 866 237 286 350 769 733 736 19 104 934 595 475 742 755 744 879 900 747 191 207 263 125 752 753 754 596 208 757 132 748 775 773 585 888 156 432 766 257 577 823 108 397 863 232 767 461 530 777 880 169 523 410 487 325 580 126 526 787 598 166 790 955 792 213 326 408 401 999 838 799 958 317 17 456 804 805 806 659 991 508 836 256 621 813 354 196 27 493 818 619 396 922 971 964 824 825 957 840 78 513 985 140 273 67 377 142 810 141 278 84 468 174 665 854 844 430 732 378 848 849 541 565 923 29 388 332 306 364 998 360 860 120 862 975 220 68 969 474 657 869 698 365 616 486 233 875 193 338 941 667 932 345 438 412 884 268 601 358 35 782 446 921 892 893 453 895 835 303 149 329 214 16 129 903 927 97 910 670 750 563 157 635 463 856 877 681 373 293 829 761 431 466 280 381 987 460 111 926 240 770 645 337 277 780 406 383 988 711 495 622 116 765 828 343 536 546 227 250 261 802 688 686 741 953 950 679 956 970 5 959 857 298 302 247 465 106 428 786 968 251 272 134 837 96 400 160 976 760 260 494 41 981 87 185 435 977 986 43 822 629 53 86 331 930 706 252 960 319 94 797
  REMOVING [771]
========================================================
998 of 1000
========================================================
278

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 962 427 775 823 716 357 552 396 751 739 560 793 655 129 398 875 42 901 99 981 406 770 843 633 397 897 231 937 938 334 848 108 811 303 591 559 347 697 853 692 834 413 131 561 222 431 195 377 16 484 240 702 68 390 235 625 663 573 6 825 286 860 289 52 73 916 798 31 699 71 818 349 299 704 768 149 927 763 789 983 324 330 202 553 615 993 641 607 65 280 249 392 460 175 4 325 12 259 670 353 984 893 753 434 288 276 589 632 90 782 62 737 765 646 658 651 513 713 252 153 668 521 408 906 982 639 701 677 66 932 346 176 444 951 380 141 650 556 679 201 435 209 491 477 804 178 678 905 146 908 791 858 998 58 953 866 543 443 773 736 861 912 774 379 14 805 745 813 385 507 356 859 652 426 987 137 537 371 626 359 22 89 619 245 890 461 844 455 985 777 587 884 100 124 414 366 284 900 468 30 103 628 354 876 903 342 387 529 60 898 779 725 40 26 867 934 186 112 712 469 257 803 437 466 75 247 11 852 341 189 575 943 833 999 946 816 889 662 807 180 600 407 92 322 808 440 762 891 977 707 158 428 3 150 166 582 215 837 393 584 784 145 229 410 841 709 41 845 694 261 420 746 135 718 781 794 515 706 695 190 152 161 104 960 714 367 873 220 907 576 450 418 196 902 788 511 265 432 831 56 122 812 294 580 232 84 363 590 666 809 304 700 688 854 606 409 616 313 355 287 451 132 764 996 439 624 142 221 470 754 870 522 87 394 577 416 567 735 327 326 159 760 846 588 9 456 562 538 806 370 230 91 499 980 621 193 117 70 473 492 973 986 869 715 210 847 874 316 493 959 835 315 331 338 448 930 144 979 878 514 827 266 892 487 384 218 8 228 77 750 506 248 524 123 33 462 107 162 167 474 21 530 27 417 446 485 216 273 719 840 597 879 623 320 429 780 776 38 877 314 723 931 548 339 620 203 424 360 976 47 217 165 500 106 669 612 554 862 140 311 925 917 447 608 147 990 839 310 463 636 388 842 796 160 498 227 531 271 85 130 613 128 126 403 629 345 949 191 471 829 826 335 425 705 814 79 464 94 634 358 571 881 44 972 851 125 18 954 941 401 80 971 438 317 767 744 98 605 260 578 542 28 792 601 942 933 523 197 88 740 547 660 742 532 894 237 569 120 693 939 365 312 496 540 181 364 494 400 483 863 945 544 546 769 472 786 78 743 994 411 295 611 415 910 7 399 381 481 637 208 200 549 516 534 219 185 772 551 272 467 967 974 343 585 51 423 298 275 205 947 685 170 755 95 453 422 174 555 586 171 352 274 850 226 935 649 395 989 297 268 204 857 642 618 246 13 54 32 154 672 254 465 579 74 756 727 36 622 888 638 872 691 10 321 225 368 728 441 896 5 721 449 924 351 480 115 386 849 300 970 617 82 267 111 748 749 486 885 25 61 458 922 501 93 15 37 505 630 975 86 177 717 541 101 991 647 536 880 604 683 323 383 539 594 269 592 654 361 504 139 911 595 883 978 308 882 965 290 223 734 53 292 656 741 724 961 258 20 687 936 169 790 614 116 680 211 263 270 148 969 433 333 127 565 689 72 758 645 213 761 926 684 526 671 545 194 489 733 610 459 564 119 452 17 865 277 282 55 703 593 49 676 730 81 319 436 527 710 192 681 799 184 305 568 682 602 525 627 664 899 382 802 63 921 596 509 599 23 864 696 738 182 583 143 778 340 118 179 635 720 895 293 909 307 121 168 698 243 46 328 820 609 2 442 708 512 114 110 603 785 233 283 886 726 913 454 810 958 164 136 535 34 133 64 163 598 478 172 992 430 238 187 955 102 373 212 405 957 457 151 731 183 520 255 944 24 285 134 508 50 67 729 59 445 732 968 640 262 488 224 995 173 43 766 643 306 950 372 821 412 887 296 105 198 244 251 550 45 752 332 675 673 419 659 19 256 557 574 113 329 518 817 199 369 138 35 156 648 344 250 39 510 234 674 337 402 815 923 915 301 76 350 918 856 479 952 83 914 747 239 558 644 838 214 830 519 940 690 309 653 572 362 533 241 948 855 836 497 904 801 236 528 374 495 871 657 929 188 832 928 997 919 391 797 824 868 787 665 503 667 207 475 490 0 566 1 109 686 264 570 96 711 631 502 375 389 404 963 421 757 302 253 378 348 97 966 157 828 291 57 517 822 336 242 206 476 722 318 279 964 563 920 988 800 759 661 956 581 819 783 29 376 795 281 48 155 69 482 771   from: 518 885 477 708 882 133 6 532 8 9 649 898 221 759 14 15 30 553 584 751 20 21 488 735 897 25 680 826 626 154 576 109 935 113 121 147 575 727 566 269 389 567 778 48 599 45 481 483 394 49 993 651 658 864 363 405 846 57 242 482 437 61 833 171 46 65 335 721 570 361 70 71 356 235 92 152 559 915 352 315 684 800 42 10 189 99 100 865 814 139 702 348 243 359 449 119 851 203 98 85 455 275 219 644 211 105 683 707 859 26 444 534 190 371 88 917 648 176 402 506 572 689 662 264 300 454 731 127 989 779 130 178 944 764 962 548 973 914 409 617 839 128 47 425 729 162 146 763 654 150 436 783 55 167 37 440 974 387 145 701 368 571 448 573 164 995 375 539 815 433 170 241 842 581 473 313 385 583 853 179 745 370 353 646 231 310 285 187 633 560 63 323 925 59 194 771 858 4 2 199 507 138 202 982 218 527 422 557 253 50 161 374 376 236 183 415 216 24 984 265 909 153 590 516 631 913 115 600 693 850 978 184 288 254 83 660 933 671 238 776 574 270 215 123 791 245 347 556 979 249 947 40 413 510 76 188 550 675 411 259 728 392 445 499 734 102 414 11 1 274 793 746 103 613 896 949 276 588 672 279 95 281 64 609 225 75 594 386 151 289 382 304 994 324 723 418 34 983 795 299 124 12 604 447 798 562 0 307 807 230 719 311 312 830 916 79 525 168 820 429 476 663 904 439 229 450 911 614 328 938 928 390 346 333 334 74 336 22 23 817 894 417 682 136 344 28 972 677 200 349 789 372 89 881 206 355 255 192 3 712 714 131 538 743 852 309 366 653 226 369 172 228 470 929 709 887 920 367 796 427 726 700 861 204 384 643 547 490 661 992 912 669 948 393 627 615 725 586 937 593 524 457 855 954 674 694 217 391 521 32 939 52 883 135 112 549 419 489 239 416 676 212 812 18 906 143 294 322 282 652 205 80 965 399 434 931 522 738 144 990 943 737 271 197 656 874 82 441 568 891 155 380 287 867 420 442 607 297 458 459 945 724 952 529 464 222 77 137 902 291 758 424 472 946 717 801 785 342 478 451 589 514 296 816 811 963 907 266 730 341 832 924 56 339 808 564 710 497 498 158 321 501 740 503 551 165 398 899 996 509 340 511 591 691 756 843 696 636 540 519 520 692 284 718 357 809 936 908 163 421 690 295 7 533 537 704 177 845 362 404 471 561 542 890 544 90 320 841 443 602 31 784 552 327 997 407 491 697 39 262 623 505 305 543 267 951 462 918 118 794 182 739 258 715 821 36 558 768 578 426 66 831 582 569 395 762 195 587 210 91 38 592 873 292 330 878 54 597 788 699 774 886 531 942 641 605 889 173 608 244 610 668 612 628 198 480 502 528 618 819 620 467 781 678 73 625 308 579 290 940 512 606 175 647 624 114 634 201 638 876 640 772 93 469 224 492 186 639 870 919 650 51 967 504 62 655 664 500 673 871 181 81 961 603 496 60 110 180 611 58 33 379 72 423 517 351 314 905 803 301 966 705 234 13 316 685 637 687 642 69 283 749 515 834 246 695 479 44 403 868 484 555 545 703 847 159 666 107 827 223 485 630 632 713 117 209 716 535 318 248 720 901 722 980 122 101 554 148 872 452 866 237 286 350 769 733 736 19 104 934 595 475 742 755 744 879 900 747 191 207 263 125 752 753 754 596 208 757 132 748 775 773 585 888 156 432 766 257 577 823 108 397 863 232 767 461 530 777 880 169 523 410 487 325 580 126 526 787 598 166 790 955 792 213 326 408 401 999 838 799 958 317 17 456 804 805 806 659 991 508 836 256 621 813 354 196 27 493 818 619 396 922 971 964 824 825 957 840 78 513 985 140 273 67 377 142 810 141 278 84 468 174 665 854 844 430 732 378 848 849 541 565 923 29 388 332 306 364 998 360 860 120 862 975 220 68 969 474 657 869 698 365 616 486 233 875 193 338 941 667 932 345 438 412 884 268 601 358 35 782 446 921 892 893 453 895 835 303 149 329 214 16 129 903 927 97 910 670 750 563 157 635 463 856 877 681 373 293 829 761 431 466 280 381 987 460 111 926 240 770 645 337 277 780 406 383 988 711 495 622 116 765 828 343 536 546 227 250 261 802 688 686 741 953 950 679 956 970 5 959 857 298 302 247 465 106 428 786 968 251 272 134 837 96 400 160 976 760 260 494 41 981 87 185 435 977 986 43 822 629 53 86 331 930 706 252 960 319 94 797
  REMOVING [278]
========================================================
999 of 1000
 V A L I D    T R E E
*********************************************************
 T E S T:    99
*********************************************************
========================================================

========================================================
                                                     999
                                                     998
                                             998
                                                     997
                                     997
                                                     996
                                                     995
                                             995
                                                     994
                                                     993
                                             993
                                                     992
                             992
                                                     991
                                                     990
                                             990
                                                     989
                                             989
                                                     988
                                                     987
                                     987
                                                     986
                                                     985
                                             985
                                                     984
                     984
                                                     983
                                                     982
                                             982
                                                     981
                                                     980
                                     980
                                                     979
                                                     978
                                             978
                                                     977
                             977
                                                     976
                                             976
                                                     975
                                     975
                                                     974
                                             974
                                                     973
                     973
                                                     972
                                                     971
                                             971
                                                     970
                                     970
                                                     969
                                                     968
                                             968
                                                     967
                                             967
                                                     966
                             966
                                                     965
                                                     964
                                             964
                                                     963
                                             963
                                                     962
                                                     961
                                     961
                                                     960
                                             960
                                                     959
                             959
                                                     958
                                             958
                                                     957
                                                     956
                                             956
                                                     955
                                                     954
                                     954
                                                     953
                                                     952
                                             952
                                                     951
                                     951
                                                     950
                                             950
                                                     949
             949
                                                     948
                                                     947
                                             947
                                                     946
                                                     945
                                             945
                                                     944
                                     944
                                                     943
                                             943
                                                     942
                                                     941
                             941
                                                     940
                                                     939
                                             939
                                                     938
                                             938
                                                     937
                                                     936
                                     936
                                                     935
                                             935
                                                     934
                                                     933
                                             933
                                                     932
                     932
                                                     931
                                                     930
                                             930
                                                     929
                                             929
                                                     928
                                                     927
                                     927
                                                     926
                                             926
                                                     925
                             925
                                                     924
                                             924
                                                     923
                                                     922
                                     922
                                                     921
                                                     920
                                             920
                                                     919
                     919
                                                     918
                                                     917
                                             917
                                                     916
                                     916
                                                     915
                                             915
                                                     914
                                                     913
                                     913
                                                     912
                                                     911
                                             911
                                                     910
                                                     909
                                             909
                                                     908
                             908
                                                     907
                                             907
                                                     906
                                                     905
                                             905
                                                     904
                                     904
                                                     903
                                                     902
                                             902
                                                     901
                                             901
                                                     900
                                                     899
     899
                                                     898
                                                     897
                                             897
                                                     896
                                             896
                                                     895
                                     895
                                                     894
                                                     893
                                             893
                                                     892
                                             892
                                                     891
                                     891
                                                     890
                                             890
                                                     889
                                                     888
                             888
                                                     887
                                                     886
                                             886
                                                     885
                                             885
                                                     884
                                     884
                                                     883
                                                     882
                                             882
                                                     881
                                                     880
                                             880
                                                     879
                             879
                                                     878
                                                     877
                                             877
                                                     876
                                     876
                                                     875
                                                     874
                                             874
                                                     873
                                                     872
                                     872
                                                     871
                                             871
                                                     870
                                                     869
                                             869
                                                     868
                     868
                                                     867
                                             867
                                                     866
                                                     865
                                             865
                                                     864
                                     864
                                                     863
                                                     862
                                             862
                                                     861
                                                     860
                             860
                                                     859
                                             859
                                                     858
                                     858
                                                     857
                                                     856
                                             856
                                                     855
                                             855
                                                     854
                                                     853
                             853
                                                     852
                                                     851
                                             851
                                                     850
                                     850
                                                     849
                                                     848
                                             848
                                                     847
                                             847
                                                     846
                                     846
                                                     845
                                                     844
                                             844
                                                     843
             843
                                                     842
                                                     841
                                             841
                                                     840
                                     840
                                                     839
                                                     838
                                             838
                                                     837
                                                     836
                                             836
                                                     835
                             835
                                                     834
                                                     833
                                             833
                                                     832
                                                     831
                                             831
                                                     830
                                     830
                                                     829
                                                     828
                                             828
                                                     827
                                                     826
                                             826
                                                     825
                                     825
                                                     824
                                             824
                                                     823
                                                     822
                     822
                                                     821
                                                     820
                                             820
                                                     819
                                                     818
                                             818
                                                     817
                                     817
                                                     816
                                                     815
                                             815
                                                     814
                             814
                                                     813
                                                     812
                                             812
                                                     811
                                                     810
                                     810
                                                     809
                                                     808
                                             808
                                                     807
             807
                                                     806
                                                     805
                                             805
                                                     804
                                                     803
                                             803
                                                     802
                                     802
                                                     801
                                             801
                                                     800
                                     800
                                                     799
                                             799
                                                     798
                             798
                                                     797
                                                     796
                                             796
                                                     795
                                     795
                                                     794
                                                     793
                                             793
                                                     792
                             792
                                                     791
                                             791
                                                     790
                                     790
                                                     789
                                                     788
                                             788
                                                     787
                                             787
                                                     786
                                                     785
                     785
                                                     784
                                                     783
                                             783
                                                     782
                                     782
                                                     781
                                                     780
                                             780
                                                     779
                             779
                                                     778
                                             778
                                                     777
                                                     776
                                             776
                                                     775
                                     775
                                                     774
                                             774
                                                     773
                     773
                                                     772
                                                     771
                                             771
                                                     770
                                     770
                                                     769
                                                     768
                                             768
                                                     767
                             767
                                                     766
                                                     765
                                             765
                                                     764
                                     764
                                                     763
                                                     762
                                             762
                                                     761
     761
                                                     760
                                                     759
                                             759
                                                     758
                                                     757
                                     757
                                                     756
                                             756
                                                     755
                                     755
                                                     754
                                                     753
                                             753
                                                     752
                             752
                                                     751
                                                     750
                                             750
                                                     749
                                     749
                                                     748
                                                     747
                                             747
                                                     746
                                                     745
                                             745
                                                     744
                             744
                                                     743
                                                     742
                                             742
                                                     741
                                                     740
                                             740
                                                     739
                                     739
                                                     738
                                                     737
                                             737
                                                     736
                                             736
                                                     735
                     735
                                                     734
                                                     733
                                             733
                                                     732
                                                     731
                                     731
                                                     730
                                                     729
                                             729
                                                     728
                                             728
                                                     727
                             727
                                                     726
                                             726
                                                     725
                                                     724
                                     724
                                                     723
                                             723
                                                     722
                                                     721
                                             721
                                                     720
                                     720
                                                     719
                                                     718
                                             718
                                                     717
                                                     716
                             716
                                                     715
                                             715
                                                     714
                                     714
                                                     713
                                                     712
                                             712
                                                     711
                                                     710
             710
                                                     709
                                                     708
                                             708
                                                     707
                                             707
                                                     706
                                                     705
                                     705
                                                     704
                                                     703
                                             703
                                                     702
                                             702
                                                     701
                                                     700
                                     700
                                                     699
                                                     698
                                             698
                                                     697
                                             697
                                                     696
                                                     695
                             695
                                                     694
                                                     693
                                             693
                                                     692
                                                     691
                                             691
                                                     690
                                     690
                                                     689
                                                     688
                                             688
                                                     687
                                             687
                                                     686
                             686
                                                     685
                                             685
                                                     684
                                     684
                                                     683
                                                     682
                                             682
                                                     681
                     681
                                                     680
                                             680
                                                     679
                                                     678
                                             678
                                                     677
                                     677
                                                     676
                                                     675
                                             675
                                                     674
                                             674
                                                     673
                                                     672
                                     672
                                                     671
                                             671
                                                     670
                             670
                                                     669
                                                     668
                                             668
                                                     667
                                                     666
                                             666
                                                     665
                                     665
                                                     664
                                                     663
                                             663
                                                     662
662
                                                     661
                                                     660
                                             660
                                                     659
                                             659
                                                     658
                                     658
                                                     657
                                                     656
                                             656
                                                     655
                             655
                                                     654
                                                     653
                                             653
                                                     652
                                     652
                                                     651
                                                     650
                                             650
                                                     649
                                             649
                                                     648
                                     648
                                                     647
                                             647
                                                     646
                     646
                                                     645
                                                     644
                                             644
                                                     643
                                                     642
                                             642
                                                     641
                                     641
                                                     640
                                             640
                                                     639
                             639
                                                     638
                                             638
                                                     637
                                                     636
                                             636
                                                     635
                                     635
                                                     634
                                                     633
                                             633
                                                     632
             632
                                                     631
                                                     630
                                             630
                                                     629
                                     629
                                                     628
                                                     627
                                             627
                                                     626
                             626
                                                     625
                                                     624
                                             624
                                                     623
                                                     622
                                     622
                                                     621
                                                     620
                                             620
                                                     619
                                     619
                                                     618
                                                     617
                                             617
                                                     616
                     616
                                                     615
                                                     614
                                             614
                                                     613
                                     613
                                                     612
                                                     611
                                             611
                                                     610
                             610
                                                     609
                                                     608
                                             608
                                                     607
                                     607
                                                     606
                                                     605
                                             605
                                                     604
                                     604
                                                     603
                                                     602
                                             602
                                                     601
                                                     600
                                             600
                                                     599
                                                     598
             598
                                                     597
                                                     596
                                             596
                                                     595
                                             595
                                                     594
                                                     593
                                     593
                                                     592
                                                     591
                                             591
                                                     590
                                                     589
                                             589
                                                     588
                             588
                                                     587
                                                     586
                                             586
                                                     585
                                             585
                                                     584
                                     584
                                                     583
                                                     582
                                             582
                                                     581
                                                     580
                                             580
                                                     579
                     579
                                                     578
                                                     577
                                             577
                                                     576
                                                     575
                                     575
                                                     574
                                             574
                                                     573
                                                     572
                             572
                                                     571
                                                     570
                                             570
                                                     569
                                     569
                                                     568
                                                     567
                                             567
                                                     566
                                                     565
                                             565
                                                     564
                                     564
                                                     563
                                                     562
                                             562
                                                     561
                                             561
                                                     560
                             560
                                                     559
                                                     558
                                             558
                                                     557
                                     557
                                                     556
                                                     555
                                             555
                                                     554
                                             554
                                                     553
     553
                                                     552
                                                     551
                                             551
                                                     550
                                                     549
                                     549
                                                     548
                                                     547
                                             547
                                                     546
                                     546
                                                     545
                                                     544
                                             544
                                                     543
                             543
                                                     542
                                                     541
                                             541
                                                     540
                                     540
                                                     539
                                             539
                                                     538
                                     538
                                                     537
                                             537
                                                     536
                                                     535
                     535
                                                     534
                                                     533
                                             533
                                                     532
                                     532
                                                     531
                                                     530
                                             530
                                                     529
                                                     528
                                             528
                                                     527
                             527
                                                     526
                                             526
                                                     525
                                                     524
                                     524
                                                     523
                                             523
                                                     522
             522
                                                     521
                                                     520
                                             520
                                                     519
                                             519
                                                     518
                                     518
                                                     517
                                                     516
                                             516
                                                     515
                             515
                                                     514
                                                     513
                                             513
                                                     512
                                                     511
                                             511
                                                     510
                                     510
                                                     509
                                                     508
                                             508
                                                     507
                     507
                                                     506
                                                     505
                                             505
                                                     504
                                                     503
                                     503
                                                     502
                                                     501
                                             501
                                                     500
                                     500
                                                     499
                                                     498
                                             498
                                                     497
                                                     496
                                             496
                                                     495
                             495
                                                     494
                                                     493
                                             493
                                                     492
                                                     491
                                     491
                                                     490
                                                     489
                                             489
                                                     488
                                             488
                                                     487
                                     487
                                                     486
                                             486
                                                     485
                     485
                                                     484
                                                     483
                                             483
                                                     482
                                             482
                                                     481
                                     481
                                                     480
                                                     479
                                             479
                                                     478
                                                     477
                             477
                                                     476
                                                     475
                                             475
                                                     474
                                     474
                                                     473
                                                     472
                                             472
                                                     471
                             471
                                                     470
                                             470
                                                     469
                                                     468
                                     468
                                                     467
                                                     466
                                             466
                                                     465
                                     465
                                                     464
                                                     463
                                             463
                                                     462
                                                     461
                                             461
                                                     460
             460
                                                     459
                                                     458
                                             458
                                                     457
                                     457
                                                     456
                                             456
                                                     455
                                                     454
                             454
                                                     453
                                                     452
                                             452
                                                     451
                                     451
                                                     450
                                             450
                                                     449
                             449
                                                     448
                                                     447
                                             447
                                                     446
                                     446
                                                     445
                                             445
                                                     444
                                                     443
                                     443
                                                     442
                                             442
                                                     441
                     441
                                                     440
                                                     439
                                             439
                                                     438
                                             438
                                                     437
                                                     436
                                     436
                                                     435
                                                     434
                                             434
                                                     433
                                             433
                                                     432
                             432
                                                     431
                                                     430
                                             430
                                                     429
                                     429
                                                     428
                                                     427
                                             427
                                                     426
                                             426
                                                     425
                                                     424
                                     424
                                                     423
                                                     422
                                             422
                                                     421
                                                     420
420
                                                     419
                                                     418
                                             418
                                                     417
                                                     416
                                     416
                                                     415
                                                     414
                                             414
                                                     413
                                                     412
                                             412
                                                     411
                                                     410
                             410
                                                     409
                                             409
                                                     408
                                     408
                                                     407
                                                     406
                                             406
                                                     405
                                                     404
                                             404
                                                     403
                                                     402
                     402
                                                     401
                                                     400
                                             400
                                                     399
                                                     398
                                     398
                                                     397
                                             397
                                                     396
                             396
                                                     395
                                                     394
                                             394
                                                     393
                                             393
                                                     392
                                     392
                                                     391
                                                     390
                                             390
                                                     389
                     389
                                                     388
                                                     387
                                             387
                                                     386
                                                     385
                                             385
                                                     384
                                     384
                                                     383
                                             383
                                                     382
                                                     381
                             381
                                                     380
                                                     379
                                             379
                                                     378
                                             378
                                                     377
                                     377
                                                     376
                                                     375
                                             375
                                                     374
                                                     373
                                     373
                                                     372
                                                     371
                                             371
                                                     370
                                                     369
             369
                                                     368
                                                     367
                                             367
                                                     366
                                     366
                                                     365
                                                     364
                                             364
                                                     363
                             363
                                                     362
                                                     361
                                             361
                                                     360
                                     360
                                                     359
                                                     358
                                             358
                                                     357
                                                     356
                     356
                                                     355
                                                     354
                                             354
                                                     353
                                                     352
                                     352
                                                     351
                                             351
                                                     350
                             350
                                                     349
                                                     348
                                             348
                                                     347
                                     347
                                                     346
                                             346
                                                     345
             345
                                                     344
                                                     343
                                             343
                                                     342
                                                     341
                                             341
                                                     340
                                     340
                                                     339
                                             339
                                                     338
                                     338
                                                     337
                                             337
                                                     336
                                                     335
                             335
                                                     334
                                             334
                                                     333
                                     333
                                                     332
                                                     331
                                             331
                                                     330
                             330
                                                     329
                                                     328
                                             328
                                                     327
                                                     326
                                     326
                                                     325
                                             325
                                                     324
                                                     323
                                             323
                                                     322
                                     322
                                                     321
                                                     320
                                             320
                                                     319
                     319
                                                     318
                                                     317
                                             317
                                                     316
                                                     315
                                             315
                                                     314
                                     314
                                                     313
                                                     312
                                             312
                                                     311
                             311
                                                     310
                                                     309
                                             309
                                                     308
                                                     307
                                     307
                                                     306
                                                     305
                                             305
                                                     304
                             304
                                                     303
                                                     302
                                             302
                                                     301
                                             301
                                                     300
                                     300
                                                     299
                                             299
                                                     298
                     298
                                                     297
                                                     296
                                             296
                                                     295
                                                     294
                                     294
                                                     293
                                             293
                                                     292
                                     292
                                                     291
                                             291
                                                     290
                             290
                                                     289
                                                     288
                                             288
                                                     287
                                     287
                                                     286
                                                     285
                                             285
                                                     284
                                                     283
     283
                                                     282
                                                     281
                                             281
                                                     280
                                     280
                                                     279
                                             279
                                                     278
                                                     277
                                             277
                                                     276
                             276
                                                     275
                                             275
                                                     274
                                                     273
                                     273
                                                     272
                                             272
                                                     271
                             271
                                                     270
                                                     269
                                             269
                                                     268
                                                     267
                                     267
                                                     266
                                                     265
                                             265
                                                     264
                                                     263
                     263
                                                     262
                                                     261
                                             261
                                                     260
                                                     259
                                     259
                                                     258
                                                     257
                                             257
                                                     256
                             256
                                                     255
                                             255
                                                     254
                                     254
                                                     253
                                                     252
                                             252
                                                     251
                                     251
                                                     250
                                                     249
                                             249
                                                     248
             248
                                                     247
                                                     246
                                             246
                                                     245
                                                     244
                                             244
                                                     243
                                     243
                                                     242
                                                     241
                                             241
                                                     240
                             240
                                                     239
                                                     238
                                             238
                                                     237
                                     237
                                                     236
                                                     235
                                             235
                                                     234
                                     234
                                                     233
                                                     232
                                             232
                                                     231
                                                     230
                     230
                                                     229
                                                     228
                                             228
                                                     227
                                             227
                                                     226
                                     226
                                                     225
                                                     224
                                             224
                                                     223
                                                     222
                             222
                                                     221
                                                     220
                                             220
                                                     219
                                                     218
                                     218
                                                     217
                                                     216
                                             216
                                                     215
                                     215
                                                     214
                                                     213
                                             213
                                                     212
             212
                                                     211
                                             211
                                                     210
                                                     209
                                             209
                                                     208
                                                     207
                                     207
                                                     206
                                                     205
                                             205
                                                     204
                             204
                                                     203
                                                     202
                                             202
                                                     201
                                                     200
                                     200
                                                     199
                                             199
                                                     198
                                                     197
                                     197
                                                     196
                                             196
                                                     195
                                                     194
                                             194
                                                     193
                                                     192
                     192
                                                     191
                                             191
                                                     190
                                                     189
                                     189
                                                     188
                                                     187
                                             187
                                                     186
                                             186
                                                     185
                                     185
                                                     184
                                                     183
                                             183
                                                     182
                             182
                                                     181
                                                     180
                                             180
                                                     179
                                             179
                                                     178
                                     178
                                                     177
                                             177
                                                     176
                                                     175
                                     175
                                                     174
                                             174
                                                     173
                             173
                                                     172
                                                     171
                                             171
                                                     170
                                                     169
                                     169
                                                     168
                                             168
                                                     167
                                     167
                                                     166
                                                     165
                                             165
                                                     164
                                                     163
                                             163
                                                     162
     162
                                                     161
                                                     160
                                             160
                                                     159
                                                     158
                                             158
                                                     157
                                                     156
                                     156
                                                     155
                                                     154
                                             154
                                                     153
                                                     152
                                             152
                                                     151
                                                     150
                                     150
                                                     149
                                             149
                                                     148
                                                     147
                                             147
                                                     146
                             146
                                                     145
                                                     144
                                             144
                                                     143
                                             143
                                                     142
                                     142
                                                     141
                                                     140
                                             140
                                                     139
                                                     138
                             138
                                                     137
                                                     136
                                             136
                                                     135
                                     135
                                                     134
                                             134
                                                     133
                                     133
                                                     132
                                                     131
                                             131
                                                     130
                                             130
                                                     129
                     129
                                                     128
                                                     127
                                             127
                                                     126
                                             126
                                                     125
                                     125
                                                     124
                                                     123
                                             123
                                                     122
                                                     121
                             121
                                                     120
                                                     119
                                             119
                                                     118
                                                     117
                                     117
                                                     116
                                                     115
                                             115
                                                     114
                                             114
                                                     113
                     113
                                                     112
                                                     111
                                             111
                                                     110
                                             110
                                                     109
                                     109
                                                     108
                                             108
                                                     107
                                                     106
                                             106
                                                     105
                             105
                                                     104
                                                     103
                                             103
                                                     102
                                                     101
                                             101
                                                     100
                                                      99
                                      99
                                                      98
                                              98
                                                      97
                              97
                                                      96
                                                      95
                                              95
                                                      94
                                              94
                                                      93
                                                      92
                                      92
                                                      91
                                                      90
                                              90
                                                      89
                                              89
                                                      88
                                                      87
                                      87
                                                      86
                                                      85
                                              85
                                                      84
              84
                                                      83
                                                      82
                                              82
                                                      81
                                                      80
                                      80
                                                      79
                                                      78
                                              78
                                                      77
                              77
                                                      76
                                                      75
                                              75
                                                      74
                                      74
                                                      73
                                                      72
                                              72
                                                      71
                      71
                                                      70
                                                      69
                                              69
                                                      68
                                      68
                                                      67
                                              67
                                                      66
                                      66
                                                      65
                                                      64
                                              64
                                                      63
                                                      62
                                              62
                                                      61
                                                      60
                              60
                                                      59
                                              59
                                                      58
                                                      57
                                              57
                                                      56
                                      56
                                                      55
                                                      54
                                              54
                                                      53
                                                      52
                                      52
                                                      51
                                              51
                                                      50
              50
                                                      49
                                                      48
                                              48
                                                      47
                                      47
                                                      46
                                                      45
                                              45
                                                      44
                                      44
                                                      43
                                                      42
                                              42
                                                      41
                                                      40
                              40
                                                      39
                                                      38
                                              38
                                                      37
                                                      36
                                      36
                                                      35
                                              35
                                                      34
                                                      33
                              33
                                                      32
                                                      31
                                              31
                                                      30
                                                      29
                                              29
                                                      28
                                      28
                                                      27
                                                      26
                                              26
                                                      25
                                                      24
                      24
                                                      23
                                              23
                                                      22
                                                      21
                                      21
                                                      20
                                              20
                                                      19
                                                      18
                              18
                                                      17
                                                      16
                                              16
                                                      15
                                      15
                                                      14
                                                      13
                                              13
                                                      12
                      12
                                                      11
                                                      10
                                              10
                                                       9
                                       9
                                                       8
                                               8
                                                       7
                               7
                                                       6
                                                       5
                                               5
                                                       4
                                       4
                                                       3
                                                       2
                                               2
                                                       1
                                                       0


========================================================
             710
     710
             704
704
             254
     254
             247

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 240 438 742 101 556 303 511 456 752 243 294 589 767 740 885 174 695 667 787 42 361 837 444 601 258 570 467 810 43 414 712 756 846 320 733 197 672 270 371 498 974 969 46 86 773 960 517 88 166 592 394 313 341 238 372 915 499 340 301 937 961 441 475 458 367 401 902 788 85 703 841 273 664 296 643 128 249 722 262 611 165 875 140 544 652 300 867 827 522 631 638 451 609 535 618 991 933 984 190 16 360 869 453 473 1 422 949 292 662 998 853 924 632 552 646 377 207 859 409 364 3 71 790 945 912 886 993 797 681 204 679 505 728 275 554 571 431 861 905 276 795 14 87 104 90 824 743 518 882 612 316 148 718 784 944 418 474 723 626 725 870 583 714 814 633 881 445 209 216 558 825 768 175 376 493 999 512 922 242 142 856 939 388 599 892 747 235 513 953 502 921 236 233 751 94 889 463 807 278 403 483 895 8 708 180 617 731 117 0 130 212 851 894 578 685 369 884 32 654 246 106 759 12 26 619 772 24 702 460 335 241 366 439 653 783 213 68 700 947 813 37 80 131 981 809 19 635 720 44 862 791 547 735 224 25 427 218 494 6 820 450 766 977 764 769 442 914 9 749 900 935 107 356 948 968 89 82 358 141 424 17 802 78 99 967 152 678 281 916 443 35 865 831 934 263 122 622 51 711 732 111 972 591 67 541 959 31 549 614 565 673 800 576 447 125 227 602 392 389 20 786 425 383 950 527 338 745 155 164 136 349 566 206 65 927 378 674 598 47 228 344 487 962 430 771 329 56 956 651 350 774 538 280 906 815 384 119 992 133 840 464 309 604 477 891 415 150 726 36 49 676 310 454 83 435 770 198 299 459 437 77 103 476 666 353 901 543 917 231 657 955 234 898 48 413 564 469 22 717 871 994 288 261 918 828 84 472 536 705 176 448 683 684 382 855 105 707 405 211 112 314 928 668 849 259 466 92 199 239 336 883 584 304 744 355 561 319 173 115 11 567 295 189 362 805 847 879 803 271 486 594 896 650 663 852 40 659 876 172 978 806 603 158 167 421 373 606 257 492 171 719 223 526 985 866 808 325 333 689 264 381 563 610 308 878 18 908 138 363 159 716 72 920 266 256 780 66 834 58 232 127 826 187 864 118 2 857 798 291 640 398 428 863 139 577 182 28 30 286 506 741 98 96 943 537 10 829 327 412 624 321 52 958 113 694 616 995 471 195 108 524 328 214 185 629 986 410 580 989 126 670 542 395 799 777 500 93 531 200 509 688 391 449 553 137 822 757 845 110 661 374 81 789 323 287 811 462 838 63 976 671 551 399 123 816 268 836 738 196 970 129 982 572 194 792 746 729 941 696 348 75 352 457 520 62 406 330 380 252 508 39 501 38 778 521 102 170 397 251 623 586 890 156 910 709 293 420 434 782 739 485 290 250 899 754 753 957 975 109 210 229 178 585 954 988 909 186 162 54 215 145 416 925 45 95 557 848 842 596 342 973 605 222 33 642 990 15 379 625 347 495 548 761 930 931 569 649 146 307 839 835 114 677 368 452 192 615 306 208 489 593 326 821 507 607 525 546 938 560 721 478 29 588 484 656 237 793 153 269 639 386 644 490 550 763 724 904 163 396 311 858 936 429 385 305 942 669 53 157 332 116 515 297 595 946 144 987 285 620 868 621 124 636 715 926 343 785 479 923 608 540 400 298 873 965 393 70 516 940 135 312 504 573 691 365 221 874 496 748 963 179 244 779 645 600 781 597 737 181 217 345 61 426 860 581 877 545 282 408 893 630 289 50 693 4 60 433 188 488 5 755 205 801 225 143 613 736 897 265 64 446 692 354 727 844 887 100 907 121 149 69 682 183 168 404 932 284 872 690 964 983 322 818 559 161 470 996 687 440 147 346 370 461 339 582 971 794 701 219 686 390 497 952 880 226 482 357 980 730 55 260 698 201 79 555 411 966 279 854 407 843 765 417 317 267 193 272 387 750 177 318 758 151 833 533 762 680 230 465 713 562 819 274 665 455 160 480 59 817 154 658 184 574 911 641 539 579 402 423 534 832 796 27 929 324 375 734 775 823 331 74 97 13 830 776 587 132 919 532 359 253 850 812 23 432 202 804 568 351 503 255 73 529 888 675 637 169 120 334 699 245 191 491 277 706 628 76 21 7 655 510 203 523 903 634 302 57 481 436 760 34 575 590 220 997 419 660 627 979 315 648 647 530 134 283 248 91 468 337 41 913 697 528 514 951 519   from: 0 932 2 553 162 416 710 761 113 626 369 173 616 843 121 108 655 879 18 588 817 333 598 23 24 535 752 283 360 720 668 230 958 50 544 442 84 818 38 319 579 204 146 899 441 16 919 901 624 7 20 963 40 613 460 80 56 858 226 119 97 240 345 259 71 647 470 876 68 485 731 695 454 844 924 248 189 77 816 381 778 610 82 83 438 85 366 458 670 807 510 787 882 436 424 95 790 959 98 564 491 150 55 215 105 420 733 389 211 814 604 680 12 212 114 263 377 205 422 666 595 440 756 123 935 402 241 415 973 129 662 980 354 192 229 614 495 735 138 736 332 904 580 143 810 674 15 255 26 149 429 421 463 697 172 44 311 646 718 855 378 433 638 163 915 465 126 167 168 66 878 171 92 867 532 500 522 267 178 941 753 785 388 786 432 296 519 271 45 747 275 191 608 656 822 890 346 543 177 199 984 764 202 658 90 103 557 593 276 591 175 607 911 120 709 853 888 868 739 925 218 922 383 298 871 74 898 156 978 615 886 330 902 196 234 235 926 913 232 927 8 182 140 243 992 974 246 813 632 835 622 251 220 852 254 439 256 48 523 262 999 261 479 585 805 265 742 865 767 563 270 225 272 833 773 507 87 312 682 279 280 730 329 350 266 285 838 287 288 540 612 560 397 469 918 949 166 983 947 299 300 290 872 862 304 895 318 631 987 309 640 537 250 798 314 452 214 462 891 659 320 185 322 795 59 325 326 109 449 198 705 331 552 611 101 21 337 258 338 130 257 597 997 207 344 392 321 726 982 559 636 307 975 940 194 419 356 985 227 359 806 799 954 363 364 956 493 367 54 850 884 936 770 133 450 536 744 966 358 286 875 538 681 418 856 487 577 60 76 885 796 477 291 43 775 584 396 561 789 993 400 384 125 702 908 456 406 42 408 409 410 617 412 948 110 549 375 417 217 216 371 582 118 907 909 99 509 554 648 165 39 782 574 154 244 840 33 295 351 147 765 11 35 443 41 445 4 81 57 741 94 734 737 951 179 343 210 962 390 684 707 639 944 152 79 700 315 353 222 600 160 471 434 998 474 72 476 860 690 842 572 481 253 437 484 302 486 370 719 851 594 677 706 427 889 751 446 774 556 499 281 501 518 727 749 546 260 989 508 513 224 836 373 352 839 515 766 586 929 6 745 457 117 893 524 834 526 527 223 694 793 29 328 498 943 89 548 698 530 715 482 830 972 197 142 158 336 828 385 712 195 237 435 372 847 282 533 206 558 269 221 728 174 547 750 900 461 567 755 181 991 431 938 573 832 575 157 772 516 988 141 414 480 317 233 506 578 629 100 869 65 916 592 365 649 759 596 93 910 621 483 864 602 183 78 529 841 334 525 609 413 209 589 376 802 193 58 355 455 946 459 599 859 791 663 134 950 301 874 760 603 339 153 104 122 239 583 723 576 534 642 846 743 161 641 645 633 252 678 625 28 444 652 896 654 62 61 657 788 669 660 661 159 348 686 665 644 67 31 503 430 635 393 673 981 675 539 496 827 679 242 693 683 277 475 685 664 687 278 131 478 691 837 863 187 144 102 164 643 264 466 357 488 335 268 127 569 180 1 47 520 729 494 714 407 650 716 52 451 69 289 601 692 906 724 713 696 590 73 111 155 27 347 64 112 137 426 380 738 70 489 25 401 808 873 323 186 387 748 310 425 274 777 468 570 800 473 341 758 892 145 382 148 327 379 340 88 703 768 877 945 821 238 740 497 619 303 63 308 292 732 671 870 783 784 531 717 404 490 453 203 545 792 405 169 967 689 824 368 551 91 801 135 931 32 447 361 562 391 887 976 550 324 930 809 815 200 779 634 386 995 606 374 823 797 825 826 517 208 829 116 831 411 5 428 249 305 362 781 630 990 75 505 9 623 190 13 136 848 139 754 342 528 464 854 219 571 701 273 231 395 721 403 970 923 957 757 812 423 725 492 521 293 568 49 811 769 905 511 512 37 704 201 176 627 880 555 581 861 313 996 849 448 699 894 46 14 897 284 349 794 820 107 903 803 708 977 541 762 170 30 316 912 19 914 3 965 917 857 819 920 921 637 780 247 934 236 605 928 763 776 952 228 933 398 771 502 937 132 939 514 653 297 587 746 467 394 96 188 667 883 124 151 953 628 955 306 672 651 213 960 961 566 51 964 722 620 36 968 22 17 971 542 128 245 504 86 34 472 979 942 10 115 986 688 845 106 618 804 399 866 881 53 184 711 969 294 565 994 676
  REMOVING [710]
========================================================
996 of 1000
========================================================
     704
704
     254
254
     247

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 240 438 742 101 556 303 511 456 752 243 294 589 767 740 885 174 695 667 787 42 361 837 444 601 258 570 467 810 43 414 712 756 846 320 733 197 672 270 371 498 974 969 46 86 773 960 517 88 166 592 394 313 341 238 372 915 499 340 301 937 961 441 475 458 367 401 902 788 85 703 841 273 664 296 643 128 249 722 262 611 165 875 140 544 652 300 867 827 522 631 638 451 609 535 618 991 933 984 190 16 360 869 453 473 1 422 949 292 662 998 853 924 632 552 646 377 207 859 409 364 3 71 790 945 912 886 993 797 681 204 679 505 728 275 554 571 431 861 905 276 795 14 87 104 90 824 743 518 882 612 316 148 718 784 944 418 474 723 626 725 870 583 714 814 633 881 445 209 216 558 825 768 175 376 493 999 512 922 242 142 856 939 388 599 892 747 235 513 953 502 921 236 233 751 94 889 463 807 278 403 483 895 8 708 180 617 731 117 0 130 212 851 894 578 685 369 884 32 654 246 106 759 12 26 619 772 24 702 460 335 241 366 439 653 783 213 68 700 947 813 37 80 131 981 809 19 635 720 44 862 791 547 735 224 25 427 218 494 6 820 450 766 977 764 769 442 914 9 749 900 935 107 356 948 968 89 82 358 141 424 17 802 78 99 967 152 678 281 916 443 35 865 831 934 263 122 622 51 711 732 111 972 591 67 541 959 31 549 614 565 673 800 576 447 125 227 602 392 389 20 786 425 383 950 527 338 745 155 164 136 349 566 206 65 927 378 674 598 47 228 344 487 962 430 771 329 56 956 651 350 774 538 280 906 815 384 119 992 133 840 464 309 604 477 891 415 150 726 36 49 676 310 454 83 435 770 198 299 459 437 77 103 476 666 353 901 543 917 231 657 955 234 898 48 413 564 469 22 717 871 994 288 261 918 828 84 472 536 705 176 448 683 684 382 855 105 707 405 211 112 314 928 668 849 259 466 92 199 239 336 883 584 304 744 355 561 319 173 115 11 567 295 189 362 805 847 879 803 271 486 594 896 650 663 852 40 659 876 172 978 806 603 158 167 421 373 606 257 492 171 719 223 526 985 866 808 325 333 689 264 381 563 610 308 878 18 908 138 363 159 716 72 920 266 256 780 66 834 58 232 127 826 187 864 118 2 857 798 291 640 398 428 863 139 577 182 28 30 286 506 741 98 96 943 537 10 829 327 412 624 321 52 958 113 694 616 995 471 195 108 524 328 214 185 629 986 410 580 989 126 670 542 395 799 777 500 93 531 200 509 688 391 449 553 137 822 757 845 110 661 374 81 789 323 287 811 462 838 63 976 671 551 399 123 816 268 836 738 196 970 129 982 572 194 792 746 729 941 696 348 75 352 457 520 62 406 330 380 252 508 39 501 38 778 521 102 170 397 251 623 586 890 156 910 709 293 420 434 782 739 485 290 250 899 754 753 957 975 109 210 229 178 585 954 988 909 186 162 54 215 145 416 925 45 95 557 848 842 596 342 973 605 222 33 642 990 15 379 625 347 495 548 761 930 931 569 649 146 307 839 835 114 677 368 452 192 615 306 208 489 593 326 821 507 607 525 546 938 560 721 478 29 588 484 656 237 793 153 269 639 386 644 490 550 763 724 904 163 396 311 858 936 429 385 305 942 669 53 157 332 116 515 297 595 946 144 987 285 620 868 621 124 636 715 926 343 785 479 923 608 540 400 298 873 965 393 70 516 940 135 312 504 573 691 365 221 874 496 748 963 179 244 779 645 600 781 597 737 181 217 345 61 426 860 581 877 545 282 408 893 630 289 50 693 4 60 433 188 488 5 755 205 801 225 143 613 736 897 265 64 446 692 354 727 844 887 100 907 121 149 69 682 183 168 404 932 284 872 690 964 983 322 818 559 161 470 996 687 440 147 346 370 461 339 582 971 794 701 219 686 390 497 952 880 226 482 357 980 730 55 260 698 201 79 555 411 966 279 854 407 843 765 417 317 267 193 272 387 750 177 318 758 151 833 533 762 680 230 465 713 562 819 274 665 455 160 480 59 817 154 658 184 574 911 641 539 579 402 423 534 832 796 27 929 324 375 734 775 823 331 74 97 13 830 776 587 132 919 532 359 253 850 812 23 432 202 804 568 351 503 255 73 529 888 675 637 169 120 334 699 245 191 491 277 706 628 76 21 7 655 510 203 523 903 634 302 57 481 436 760 34 575 590 220 997 419 660 627 979 315 648 647 530 134 283 248 91 468 337 41 913 697 528 514 951 519 710   from: 0 932 2 553 162 416 710 761 113 626 369 173 616 843 121 108 655 879 18 588 817 333 598 23 24 535 752 283 360 720 668 230 958 50 544 442 84 818 38 319 579 204 146 899 441 16 919 901 624 7 20 963 40 613 460 80 56 858 226 119 97 240 345 259 71 647 470 876 68 485 731 695 454 844 924 248 189 77 816 381 778 610 82 83 438 85 366 458 670 807 510 787 882 436 424 95 790 959 98 564 491 150 55 215 105 420 733 389 211 814 604 680 12 212 114 263 377 205 422 666 595 440 756 123 935 402 241 415 973 129 662 980 354 192 229 614 495 735 138 736 332 904 580 143 810 674 15 255 26 149 429 421 463 697 172 44 311 646 718 855 378 433 638 163 915 465 126 167 168 66 878 171 92 867 532 500 522 267 178 941 753 785 388 786 432 296 519 271 45 747 275 191 608 656 822 890 346 543 177 199 984 764 202 658 90 103 557 593 276 591 175 607 911 120 709 853 888 868 739 925 218 922 383 298 871 74 898 156 978 615 886 330 902 196 234 235 926 913 232 927 8 182 140 243 992 974 246 813 632 835 622 251 220 852 254 439 256 48 523 262 999 261 479 585 805 265 742 865 767 563 270 225 272 833 773 507 87 312 682 279 280 730 329 350 266 285 838 287 288 540 612 560 397 469 918 949 166 983 947 299 300 290 872 862 304 895 318 631 987 309 640 537 250 798 314 452 214 462 891 659 320 185 322 795 59 325 326 109 449 198 705 331 552 611 101 21 337 258 338 130 257 597 997 207 344 392 321 726 982 559 636 307 975 940 194 419 356 985 227 359 806 799 954 363 364 956 493 367 54 850 884 936 770 133 450 536 744 966 358 286 875 538 681 418 856 487 577 60 76 885 796 477 291 43 775 584 396 561 789 993 400 384 125 702 908 456 406 42 408 409 410 617 412 948 110 549 375 417 217 216 371 582 118 907 909 99 509 554 648 165 39 782 574 154 244 840 33 295 351 147 765 11 35 443 41 445 4 81 57 741 94 734 737 951 179 343 210 962 390 684 707 639 944 152 79 700 315 353 222 600 160 471 434 998 474 72 476 860 690 842 572 481 253 437 484 302 486 370 719 851 594 677 706 427 889 751 446 774 556 499 281 501 518 727 749 546 260 989 508 513 224 836 373 352 839 515 766 586 929 6 745 457 117 893 524 834 526 527 223 694 793 29 328 498 943 89 548 698 530 715 482 830 972 197 142 158 336 828 385 712 195 237 435 372 847 282 533 206 558 269 221 728 174 547 750 900 461 567 755 181 991 431 938 573 832 575 157 772 516 988 141 414 480 317 233 506 578 629 100 869 65 916 592 365 649 759 596 93 910 621 483 864 602 183 78 529 841 334 525 609 413 209 589 376 802 193 58 355 455 946 459 599 859 791 663 134 950 301 874 760 603 339 153 104 122 239 583 723 576 534 642 846 743 161 641 645 633 252 678 625 28 444 652 896 654 62 61 657 788 669 660 661 159 348 686 665 644 67 31 503 430 635 393 673 981 675 539 496 827 679 242 693 683 277 475 685 664 687 278 131 478 691 837 863 187 144 102 164 643 264 466 357 488 335 268 127 569 180 1 47 520 729 494 714 407 650 716 52 451 69 289 601 692 906 724 713 696 590 73 111 155 27 347 64 112 137 426 380 738 70 489 25 401 808 873 323 186 387 748 310 425 274 777 468 570 800 473 341 758 892 145 382 148 327 379 340 88 703 768 877 945 821 238 740 497 619 303 63 308 292 732 671 870 783 784 531 717 404 490 453 203 545 792 405 169 967 689 824 368 551 91 801 135 931 32 447 361 562 391 887 976 550 324 930 809 815 200 779 634 386 995 606 374 823 797 825 826 517 208 829 116 831 411 5 428 249 305 362 781 630 990 75 505 9 623 190 13 136 848 139 754 342 528 464 854 219 571 701 273 231 395 721 403 970 923 957 757 812 423 725 492 521 293 568 49 811 769 905 511 512 37 704 201 176 627 880 555 581 861 313 996 849 448 699 894 46 14 897 284 349 794 820 107 903 803 708 977 541 762 170 30 316 912 19 914 3 965 917 857 819 920 921 637 780 247 934 236 605 928 763 776 952 228 933 398 771 502 937 132 939 514 653 297 587 746 467 394 96 188 667 883 124 151 953 628 955 306 672 651 213 960 961 566 51 964 722 620 36 968 22 17 971 542 128 245 504 86 34 472 979 942 10 115 986 688 845 106 618 804 399 866 881 53 184 711 969 294 565 994 676
  REMOVING [704]
========================================================
997 of 1000
========================================================
     254
254
     247

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 240 438 742 101 556 303 511 456 752 243 294 589 767 740 885 174 695 667 787 42 361 837 444 601 258 570 467 810 43 414 712 756 846 320 733 197 672 270 371 498 974 969 46 86 773 960 517 88 166 592 394 313 341 238 372 915 499 340 301 937 961 441 475 458 367 401 902 788 85 703 841 273 664 296 643 128 249 722 262 611 165 875 140 544 652 300 867 827 522 631 638 451 609 535 618 991 933 984 190 16 360 869 453 473 1 422 949 292 662 998 853 924 632 552 646 377 207 859 409 364 3 71 790 945 912 886 993 797 681 204 679 505 728 275 554 571 431 861 905 276 795 14 87 104 90 824 743 518 882 612 316 148 718 784 944 418 474 723 626 725 870 583 714 814 633 881 445 209 216 558 825 768 175 376 493 999 512 922 242 142 856 939 388 599 892 747 235 513 953 502 921 236 233 751 94 889 463 807 278 403 483 895 8 708 180 617 731 117 0 130 212 851 894 578 685 369 884 32 654 246 106 759 12 26 619 772 24 702 460 335 241 366 439 653 783 213 68 700 947 813 37 80 131 981 809 19 635 720 44 862 791 547 735 224 25 427 218 494 6 820 450 766 977 764 769 442 914 9 749 900 935 107 356 948 968 89 82 358 141 424 17 802 78 99 967 152 678 281 916 443 35 865 831 934 263 122 622 51 711 732 111 972 591 67 541 959 31 549 614 565 673 800 576 447 125 227 602 392 389 20 786 425 383 950 527 338 745 155 164 136 349 566 206 65 927 378 674 598 47 228 344 487 962 430 771 329 56 956 651 350 774 538 280 906 815 384 119 992 133 840 464 309 604 477 891 415 150 726 36 49 676 310 454 83 435 770 198 299 459 437 77 103 476 666 353 901 543 917 231 657 955 234 898 48 413 564 469 22 717 871 994 288 261 918 828 84 472 536 705 176 448 683 684 382 855 105 707 405 211 112 314 928 668 849 259 466 92 199 239 336 883 584 304 744 355 561 319 173 115 11 567 295 189 362 805 847 879 803 271 486 594 896 650 663 852 40 659 876 172 978 806 603 158 167 421 373 606 257 492 171 719 223 526 985 866 808 325 333 689 264 381 563 610 308 878 18 908 138 363 159 716 72 920 266 256 780 66 834 58 232 127 826 187 864 118 2 857 798 291 640 398 428 863 139 577 182 28 30 286 506 741 98 96 943 537 10 829 327 412 624 321 52 958 113 694 616 995 471 195 108 524 328 214 185 629 986 410 580 989 126 670 542 395 799 777 500 93 531 200 509 688 391 449 553 137 822 757 845 110 661 374 81 789 323 287 811 462 838 63 976 671 551 399 123 816 268 836 738 196 970 129 982 572 194 792 746 729 941 696 348 75 352 457 520 62 406 330 380 252 508 39 501 38 778 521 102 170 397 251 623 586 890 156 910 709 293 420 434 782 739 485 290 250 899 754 753 957 975 109 210 229 178 585 954 988 909 186 162 54 215 145 416 925 45 95 557 848 842 596 342 973 605 222 33 642 990 15 379 625 347 495 548 761 930 931 569 649 146 307 839 835 114 677 368 452 192 615 306 208 489 593 326 821 507 607 525 546 938 560 721 478 29 588 484 656 237 793 153 269 639 386 644 490 550 763 724 904 163 396 311 858 936 429 385 305 942 669 53 157 332 116 515 297 595 946 144 987 285 620 868 621 124 636 715 926 343 785 479 923 608 540 400 298 873 965 393 70 516 940 135 312 504 573 691 365 221 874 496 748 963 179 244 779 645 600 781 597 737 181 217 345 61 426 860 581 877 545 282 408 893 630 289 50 693 4 60 433 188 488 5 755 205 801 225 143 613 736 897 265 64 446 692 354 727 844 887 100 907 121 149 69 682 183 168 404 932 284 872 690 964 983 322 818 559 161 470 996 687 440 147 346 370 461 339 582 971 794 701 219 686 390 497 952 880 226 482 357 980 730 55 260 698 201 79 555 411 966 279 854 407 843 765 417 317 267 193 272 387 750 177 318 758 151 833 533 762 680 230 465 713 562 819 274 665 455 160 480 59 817 154 658 184 574 911 641 539 579 402 423 534 832 796 27 929 324 375 734 775 823 331 74 97 13 830 776 587 132 919 532 359 253 850 812 23 432 202 804 568 351 503 255 73 529 888 675 637 169 120 334 699 245 191 491 277 706 628 76 21 7 655 510 203 523 903 634 302 57 481 436 760 34 575 590 220 997 419 660 627 979 315 648 647 530 134 283 248 91 468 337 41 913 697 528 514 951 519 710 704   from: 0 932 2 553 162 416 710 761 113 626 369 173 616 843 121 108 655 879 18 588 817 333 598 23 24 535 752 283 360 720 668 230 958 50 544 442 84 818 38 319 579 204 146 899 441 16 919 901 624 7 20 963 40 613 460 80 56 858 226 119 97 240 345 259 71 647 470 876 68 485 731 695 454 844 924 248 189 77 816 381 778 610 82 83 438 85 366 458 670 807 510 787 882 436 424 95 790 959 98 564 491 150 55 215 105 420 733 389 211 814 604 680 12 212 114 263 377 205 422 666 595 440 756 123 935 402 241 415 973 129 662 980 354 192 229 614 495 735 138 736 332 904 580 143 810 674 15 255 26 149 429 421 463 697 172 44 311 646 718 855 378 433 638 163 915 465 126 167 168 66 878 171 92 867 532 500 522 267 178 941 753 785 388 786 432 296 519 271 45 747 275 191 608 656 822 890 346 543 177 199 984 764 202 658 90 103 557 593 276 591 175 607 911 120 709 853 888 868 739 925 218 922 383 298 871 74 898 156 978 615 886 330 902 196 234 235 926 913 232 927 8 182 140 243 992 974 246 813 632 835 622 251 220 852 254 439 256 48 523 262 999 261 479 585 805 265 742 865 767 563 270 225 272 833 773 507 87 312 682 279 280 730 329 350 266 285 838 287 288 540 612 560 397 469 918 949 166 983 947 299 300 290 872 862 304 895 318 631 987 309 640 537 250 798 314 452 214 462 891 659 320 185 322 795 59 325 326 109 449 198 705 331 552 611 101 21 337 258 338 130 257 597 997 207 344 392 321 726 982 559 636 307 975 940 194 419 356 985 227 359 806 799 954 363 364 956 493 367 54 850 884 936 770 133 450 536 744 966 358 286 875 538 681 418 856 487 577 60 76 885 796 477 291 43 775 584 396 561 789 993 400 384 125 702 908 456 406 42 408 409 410 617 412 948 110 549 375 417 217 216 371 582 118 907 909 99 509 554 648 165 39 782 574 154 244 840 33 295 351 147 765 11 35 443 41 445 4 81 57 741 94 734 737 951 179 343 210 962 390 684 707 639 944 152 79 700 315 353 222 600 160 471 434 998 474 72 476 860 690 842 572 481 253 437 484 302 486 370 719 851 594 677 706 427 889 751 446 774 556 499 281 501 518 727 749 546 260 989 508 513 224 836 373 352 839 515 766 586 929 6 745 457 117 893 524 834 526 527 223 694 793 29 328 498 943 89 548 698 530 715 482 830 972 197 142 158 336 828 385 712 195 237 435 372 847 282 533 206 558 269 221 728 174 547 750 900 461 567 755 181 991 431 938 573 832 575 157 772 516 988 141 414 480 317 233 506 578 629 100 869 65 916 592 365 649 759 596 93 910 621 483 864 602 183 78 529 841 334 525 609 413 209 589 376 802 193 58 355 455 946 459 599 859 791 663 134 950 301 874 760 603 339 153 104 122 239 583 723 576 534 642 846 743 161 641 645 633 252 678 625 28 444 652 896 654 62 61 657 788 669 660 661 159 348 686 665 644 67 31 503 430 635 393 673 981 675 539 496 827 679 242 693 683 277 475 685 664 687 278 131 478 691 837 863 187 144 102 164 643 264 466 357 488 335 268 127 569 180 1 47 520 729 494 714 407 650 716 52 451 69 289 601 692 906 724 713 696 590 73 111 155 27 347 64 112 137 426 380 738 70 489 25 401 808 873 323 186 387 748 310 425 274 777 468 570 800 473 341 758 892 145 382 148 327 379 340 88 703 768 877 945 821 238 740 497 619 303 63 308 292 732 671 870 783 784 531 717 404 490 453 203 545 792 405 169 967 689 824 368 551 91 801 135 931 32 447 361 562 391 887 976 550 324 930 809 815 200 779 634 386 995 606 374 823 797 825 826 517 208 829 116 831 411 5 428 249 305 362 781 630 990 75 505 9 623 190 13 136 848 139 754 342 528 464 854 219 571 701 273 231 395 721 403 970 923 957 757 812 423 725 492 521 293 568 49 811 769 905 511 512 37 704 201 176 627 880 555 581 861 313 996 849 448 699 894 46 14 897 284 349 794 820 107 903 803 708 977 541 762 170 30 316 912 19 914 3 965 917 857 819 920 921 637 780 247 934 236 605 928 763 776 952 228 933 398 771 502 937 132 939 514 653 297 587 746 467 394 96 188 667 883 124 151 953 628 955 306 672 651 213 960 961 566 51 964 722 620 36 968 22 17 971 542 128 245 504 86 34 472 979 942 10 115 986 688 845 106 618 804 399 866 881 53 184 711 969 294 565 994 676
  REMOVING [247]
========================================================
998 of 1000
========================================================
254

. . . . . . . . . . . . . . . . . . . . . . . . . . . .
deleted: 240 438 742 101 556 303 511 456 752 243 294 589 767 740 885 174 695 667 787 42 361 837 444 601 258 570 467 810 43 414 712 756 846 320 733 197 672 270 371 498 974 969 46 86 773 960 517 88 166 592 394 313 341 238 372 915 499 340 301 937 961 441 475 458 367 401 902 788 85 703 841 273 664 296 643 128 249 722 262 611 165 875 140 544 652 300 867 827 522 631 638 451 609 535 618 991 933 984 190 16 360 869 453 473 1 422 949 292 662 998 853 924 632 552 646 377 207 859 409 364 3 71 790 945 912 886 993 797 681 204 679 505 728 275 554 571 431 861 905 276 795 14 87 104 90 824 743 518 882 612 316 148 718 784 944 418 474 723 626 725 870 583 714 814 633 881 445 209 216 558 825 768 175 376 493 999 512 922 242 142 856 939 388 599 892 747 235 513 953 502 921 236 233 751 94 889 463 807 278 403 483 895 8 708 180 617 731 117 0 130 212 851 894 578 685 369 884 32 654 246 106 759 12 26 619 772 24 702 460 335 241 366 439 653 783 213 68 700 947 813 37 80 131 981 809 19 635 720 44 862 791 547 735 224 25 427 218 494 6 820 450 766 977 764 769 442 914 9 749 900 935 107 356 948 968 89 82 358 141 424 17 802 78 99 967 152 678 281 916 443 35 865 831 934 263 122 622 51 711 732 111 972 591 67 541 959 31 549 614 565 673 800 576 447 125 227 602 392 389 20 786 425 383 950 527 338 745 155 164 136 349 566 206 65 927 378 674 598 47 228 344 487 962 430 771 329 56 956 651 350 774 538 280 906 815 384 119 992 133 840 464 309 604 477 891 415 150 726 36 49 676 310 454 83 435 770 198 299 459 437 77 103 476 666 353 901 543 917 231 657 955 234 898 48 413 564 469 22 717 871 994 288 261 918 828 84 472 536 705 176 448 683 684 382 855 105 707 405 211 112 314 928 668 849 259 466 92 199 239 336 883 584 304 744 355 561 319 173 115 11 567 295 189 362 805 847 879 803 271 486 594 896 650 663 852 40 659 876 172 978 806 603 158 167 421 373 606 257 492 171 719 223 526 985 866 808 325 333 689 264 381 563 610 308 878 18 908 138 363 159 716 72 920 266 256 780 66 834 58 232 127 826 187 864 118 2 857 798 291 640 398 428 863 139 577 182 28 30 286 506 741 98 96 943 537 10 829 327 412 624 321 52 958 113 694 616 995 471 195 108 524 328 214 185 629 986 410 580 989 126 670 542 395 799 777 500 93 531 200 509 688 391 449 553 137 822 757 845 110 661 374 81 789 323 287 811 462 838 63 976 671 551 399 123 816 268 836 738 196 970 129 982 572 194 792 746 729 941 696 348 75 352 457 520 62 406 330 380 252 508 39 501 38 778 521 102 170 397 251 623 586 890 156 910 709 293 420 434 782 739 485 290 250 899 754 753 957 975 109 210 229 178 585 954 988 909 186 162 54 215 145 416 925 45 95 557 848 842 596 342 973 605 222 33 642 990 15 379 625 347 495 548 761 930 931 569 649 146 307 839 835 114 677 368 452 192 615 306 208 489 593 326 821 507 607 525 546 938 560 721 478 29 588 484 656 237 793 153 269 639 386 644 490 550 763 724 904 163 396 311 858 936 429 385 305 942 669 53 157 332 116 515 297 595 946 144 987 285 620 868 621 124 636 715 926 343 785 479 923 608 540 400 298 873 965 393 70 516 940 135 312 504 573 691 365 221 874 496 748 963 179 244 779 645 600 781 597 737 181 217 345 61 426 860 581 877 545 282 408 893 630 289 50 693 4 60 433 188 488 5 755 205 801 225 143 613 736 897 265 64 446 692 354 727 844 887 100 907 121 149 69 682 183 168 404 932 284 872 690 964 983 322 818 559 161 470 996 687 440 147 346 370 461 339 582 971 794 701 219 686 390 497 952 880 226 482 357 980 730 55 260 698 201 79 555 411 966 279 854 407 843 765 417 317 267 193 272 387 750 177 318 758 151 833 533 762 680 230 465 713 562 819 274 665 455 160 480 59 817 154 658 184 574 911 641 539 579 402 423 534 832 796 27 929 324 375 734 775 823 331 74 97 13 830 776 587 132 919 532 359 253 850 812 23 432 202 804 568 351 503 255 73 529 888 675 637 169 120 334 699 245 191 491 277 706 628 76 21 7 655 510 203 523 903 634 302 57 481 436 760 34 575 590 220 997 419 660 627 979 315 648 647 530 134 283 248 91 468 337 41 913 697 528 514 951 519 710 704 247   from: 0 932 2 553 162 416 710 761 113 626 369 173 616 843 121 108 655 879 18 588 817 333 598 23 24 535 752 283 360 720 668 230 958 50 544 442 84 818 38 319 579 204 146 899 441 16 919 901 624 7 20 963 40 613 460 80 56 858 226 119 97 240 345 259 71 647 470 876 68 485 731 695 454 844 924 248 189 77 816 381 778 610 82 83 438 85 366 458 670 807 510 787 882 436 424 95 790 959 98 564 491 150 55 215 105 420 733 389 211 814 604 680 12 212 114 263 377 205 422 666 595 440 756 123 935 402 241 415 973 129 662 980 354 192 229 614 495 735 138 736 332 904 580 143 810 674 15 255 26 149 429 421 463 697 172 44 311 646 718 855 378 433 638 163 915 465 126 167 168 66 878 171 92 867 532 500 522 267 178 941 753 785 388 786 432 296 519 271 45 747 275 191 608 656 822 890 346 543 177 199 984 764 202 658 90 103 557 593 276 591 175 607 911 120 709 853 888 868 739 925 218 922 383 298 871 74 898 156 978 615 886 330 902 196 234 235 926 913 232 927 8 182 140 243 992 974 246 813 632 835 622 251 220 852 254 439 256 48 523 262 999 261 479 585 805 265 742 865 767 563 270 225 272 833 773 507 87 312 682 279 280 730 329 350 266 285 838 287 288 540 612 560 397 469 918 949 166 983 947 299 300 290 872 862 304 895 318 631 987 309 640 537 250 798 314 452 214 462 891 659 320 185 322 795 59 325 326 109 449 198 705 331 552 611 101 21 337 258 338 130 257 597 997 207 344 392 321 726 982 559 636 307 975 940 194 419 356 985 227 359 806 799 954 363 364 956 493 367 54 850 884 936 770 133 450 536 744 966 358 286 875 538 681 418 856 487 577 60 76 885 796 477 291 43 775 584 396 561 789 993 400 384 125 702 908 456 406 42 408 409 410 617 412 948 110 549 375 417 217 216 371 582 118 907 909 99 509 554 648 165 39 782 574 154 244 840 33 295 351 147 765 11 35 443 41 445 4 81 57 741 94 734 737 951 179 343 210 962 390 684 707 639 944 152 79 700 315 353 222 600 160 471 434 998 474 72 476 860 690 842 572 481 253 437 484 302 486 370 719 851 594 677 706 427 889 751 446 774 556 499 281 501 518 727 749 546 260 989 508 513 224 836 373 352 839 515 766 586 929 6 745 457 117 893 524 834 526 527 223 694 793 29 328 498 943 89 548 698 530 715 482 830 972 197 142 158 336 828 385 712 195 237 435 372 847 282 533 206 558 269 221 728 174 547 750 900 461 567 755 181 991 431 938 573 832 575 157 772 516 988 141 414 480 317 233 506 578 629 100 869 65 916 592 365 649 759 596 93 910 621 483 864 602 183 78 529 841 334 525 609 413 209 589 376 802 193 58 355 455 946 459 599 859 791 663 134 950 301 874 760 603 339 153 104 122 239 583 723 576 534 642 846 743 161 641 645 633 252 678 625 28 444 652 896 654 62 61 657 788 669 660 661 159 348 686 665 644 67 31 503 430 635 393 673 981 675 539 496 827 679 242 693 683 277 475 685 664 687 278 131 478 691 837 863 187 144 102 164 643 264 466 357 488 335 268 127 569 180 1 47 520 729 494 714 407 650 716 52 451 69 289 601 692 906 724 713 696 590 73 111 155 27 347 64 112 137 426 380 738 70 489 25 401 808 873 323 186 387 748 310 425 274 777 468 570 800 473 341 758 892 145 382 148 327 379 340 88 703 768 877 945 821 238 740 497 619 303 63 308 292 732 671 870 783 784 531 717 404 490 453 203 545 792 405 169 967 689 824 368 551 91 801 135 931 32 447 361 562 391 887 976 550 324 930 809 815 200 779 634 386 995 606 374 823 797 825 826 517 208 829 116 831 411 5 428 249 305 362 781 630 990 75 505 9 623 190 13 136 848 139 754 342 528 464 854 219 571 701 273 231 395 721 403 970 923 957 757 812 423 725 492 521 293 568 49 811 769 905 511 512 37 704 201 176 627 880 555 581 861 313 996 849 448 699 894 46 14 897 284 349 794 820 107 903 803 708 977 541 762 170 30 316 912 19 914 3 965 917 857 819 920 921 637 780 247 934 236 605 928 763 776 952 228 933 398 771 502 937 132 939 514 653 297 587 746 467 394 96 188 667 883 124 151 953 628 955 306 672 651 213 960 961 566 51 964 722 620 36 968 22 17 971 542 128 245 504 86 34 472 979 942 10 115 986 688 845 106 618 804 399 866 881 53 184 711 969 294 565 994 676
  REMOVING [254]
========================================================
999 of 1000
 V A L I D    T R E E
**************************************************************************
**************************************************************************
             E N D     T E S T: 100 tests of 1000 items: VERIFIED
**************************************************************************
**************************************************************************
Press <RETURN> to close this window...

 */


// OUTPUT VIII (MultiMap test function):
/*




[A|192 199 221 228 321 327 472 956 5026 7140 7202 11067 12179 12986 15168 21107 21506 24233 25700 25766 27970 28410 28992 29086 30989 31207 31539 32564 35558 36928 36934 37408 39062 39281 40605 40856 42893 44331 44352 45467 45694 46491 47460 47761 49490 49692 50348 50463 51025 51881 53419 54336 54506 55938 57487 62935 67344 68868 75094 76635 78897 81025 83664 83889 85748 90090 95194 100656 101691 102808 103372 103639 104566 107782 108093 108753 109286 110409 110853 118924 119622 123840 123962 126693 128567 131981 135454 136043 142756 144511]
[ADES|26829]
[AMARANTA|135012]
[AND|312]
[AURELIANO|28990 37406 127284]
[AUTUMN|95]
[AVON|176 219 304]
[Aaaagh|109284]
[About|21253 41169 59472]
[According|1996 3914 19363 126346]
[Active|3208 135637]
[Actual|137415]
[Actually|42475 45849 56108 70848 71624 73398 76330 101536 124342 125041 127541 130439 136376]
[Adolescence|14325]
[Aegean|5776]
[Africa|5751 137538]
[Aft|76102]
[After|8380 11758 12714 16093 23342 27502 27755 28290 31141 39137 40757 43945 47094 49066 57028 60282 62846 72710 74536 85976 86173 87058 95021 108951 109178 109993 110034 112208 124211 127981 137776 138920 142950 147637]
[Afterward|102303]
[Ag|28257]
[Again|1023]
[Against|49105 65675 66190]
[Ages|139107 139315]
[Aguilar|7534 7603 7647 7824 7871 7952 8033 8307 16138 27831 28323 28407 28543 28741 50588 50600 50658 50813 50842 50862 62620]
[Aided|53346 76537]
[Aires|194]
[Alabama|107761 144783]
[Alacoque|122204]
[Alaska|52630]
[Alb|115800]
[Alexander|26262]
[Alexandria|2068]
[Alfonso|139368 139907 141992 143383 144488]
[Alirio|35692 35716]
[All|257 5297 8308 16889 23754 39868 41339 67881 68351 69519 74004 76420 87582 104386 118439 143732 146479]
[Almost|36365 50589 132888 138814]
[Alone|60140]
[Along|2512 44200]
[Also|81001 89387 135981 137794]
[Alt|143769]
[Althou|7068]
[Althoug|58066]
[Although|5335 8439 13482 15435 17793 22879 25756 31316 34576 36406 37566 48276 48565 49561 51558 54505 65978 67894 74553 76431 84059 85001 93220 93982 98655 108033 108220 136347 137755 138348 139928 145311 146282 146456]
[Alw|2405]
[Always|4266 78708 126927]
[Am|88464 148604]
[Ama|38863 126678]
[Amador|85962 86022 86058 134597 134709]
[Amar|39863 103919]
[Amara|100824]
[Amaran|32517]
[Amarant|12666 39707]
[Amaranta|11039 12646 12744 12917 13036 13596 14443 15600 15696 18369 19891 19966 21602 21973 22223 22553 22695 22763 22873 23277 23356 24921 24995 25273 25338 26855 26936 26967 27028 27045 27436 28677 28902 29712 30718 30813 30856 30881 31178 31274 31343 31366 31495 31739 32175 32328 32720 33562 34200 34402 34506 36648 38509 38874 38926 38967 39101 39339 39472 39554 39627 39736 39776 40003 40087 40301 42692 42734 42797 44086 44136 44302 44323 44788 47388 47875 49637 49667 49695 49738 49853 49927 50058 50091 50115 50263 51132 51187 51231 51311 51428 51480 51512 51760 51871 52539 53464 53466 53525 53752 53924 54021 54067 54132 54208 54238 54314 54825 55114 55792 56718 58259 58306 58338 58523 58640 58742 58775 60947 61501 61599 61677 64946 65264 66838 69286 70185 70976 71841 71995 75397 75454 77370 77537 77781 77875 78644 78723 78850 79191 81833 82935 84331 84415 84682 84755 85909 87210 87437 87631 88363 88447 88556 88983 89100 89317 89881 89912 90122 90229 92398 92440 92489 92707 92752 93088 93133 95542 96085 96429 96656 96753 96904 97263 97509 97812 98006 98519 98643 98815 98855 99165 99335 99370 99568 99687 99783 100113 100211 100255 100298 100348 100505 100578 100692 100736 100832 100868 100884 100912 101050 101160 101252 103646 104791 106713 112734 113436 113597 114260 115676 115938 117152 119389 121077 121853 122007 122324 122533 122610 122630 124090 124571 124676 125847 126292 126421 126485 128873 129420 129756 130015 131980 132118 132165 132687 133339 133702 134450 134997 135694 135934 136061 136183 136542 136590 136785 136895 137247 137426 137476 137764 138388 138619 138891 138999 140488 140931 141066 141284 141514 142115 142323 142486 142634 142733 144897 144985 145065 145325 145456 145576 145662 145824 145868 146007 146089 146182 146283 146421 146499 146577 146813 146894 146978 147040 147159 147286 147488 147544 147705 147755 147891 148453 148618 149016 149325]
[Amarante|31612]
[Amazonian|141641 142948]
[America|52621]
[American|217 97938 98066 98412 102623]
[Americans|98134]
[Among|80562 97929 98220]
[Amparo|21317 23268 23316 23352 23429 23452 23533 23641 31354 31373 31481 53155]
[Amsterdam|880]
[Amused|133180]
[An|7129 8974 12963 17038 44529 59803 63555 106173 108783 112862]
[And|7599 11406 11962 13166 14489 20726 21480 23082 24777 30726 33493 34152 37389 37644 38228 43464 43635 44885 45144 45371 50396 55362 56190 57750 60124 67990 75212 91612 103384 115295 115380 122118 140802 145368 148696]
[Anedio|8177]
[Angel|123971 126405 126625 144797]
[Annoyed|55964]
[Another|46698 52331]
[Antilles|46952]
[Antoni|100746]
[Antonio|66573 66681 66877 67214 71210 77669 77809 86266 90037 96557 106223 123038 123934]
[Anxious|11720]
[Any|54134 127362]
[Anyone|116895 130463]
[Apolinar|20494 20648 20671 20753 20891 20977 21032 21229 21296 21402 22225 25580 26676 29214 29737 31943 34928 35224 35338 35434 35582 35966 36037 36339 36479 36875 37044 37314 37347 38123 38160 38279 38343 44385]
[April|17553 51924 99730 121183 142547]
[Aquiles|55017 55625 55651 55831 55936]
[Ar|605 22171 85032 130893 143334]
[Arab|80005 111570 119369 133021]
[Arabs|13691 14087 16852 20517 26896 118684 118766 144710]
[Aracataca|6]
[Aragonese|6825 6966]
[Arc|87755]
[Arca|12100 69564]
[Arcad|25835 42794]
[Arcadi|11543]
[Arcadio|665 813 995 1094 1315 1441 1461 1760 1839 1939 2007 2229 2320 2588 2637 2924 3061 3291 3415 3570 3659 3748 3917 4251 4479 4609 4686 4821 5066 5174 5315 6010 6093 6178 6241 6359 6460 6482 6510 6564 6920 7239 7469 7526 7549 7582 7660 7709 7754 7981 8013 8041 8231 8270 8651 8750 8932 9150 9208 9232 10236 10479 10549 11018 11177 11315 11371 11429 11477 11584 11647 11808 11842 11894 12008 12082 12160 12229 12256 12285 12359 12410 12523 12608 12729 12871 13009 13144 13269 13489 13496 13594 13709 13872 13882 13940 14024 14095 14142 14388 14441 14641 14699 14760 14825 15598 15694 15704 15929 16051 16107 16443 16791 17215 17601 17744 17828 17957 18036 18118 18163 18203 18676 19591 19737 20000 20180 20457 20611 20664 20697 20930 21007 21201 21372 21408 21476 21511 21916 22070 22202 22355 22590 22761 22803 25089 25147 25171 25251 25370 25500 25561 26265 26324 26388 26393 26423 26515 26623 26706 27255 27672 27806 27883 27918 27997 28104 28271 28400 28446 28493 29508 30273 30335 30382 30437 30479 30517 30559 30609 31751 31971 32210 32544 32868 33038 33204 33485 33580 33627 33701 33793 33901 34018 34099 34129 34212 34278 34380 36695 36729 36753 36819 37242 37696 37717 37856 37996 38019 38096 38134 38186 38206 38269 38329 38471 38607 38686 38719 38752 39427 39435 40198 40230 40265 40289 40345 40497 40570 40628 40679 40727 40798 40864 41052 41173 41193 41198 41215 41425 41465 41479 41575 41621 41641 41720 41747 41781 41835 41889 42055 42161 42183 42267 42387 42476 42554 42591 42690 42714 42835 42885 42923 43118 43192 43306 43385 43485 43514 43571 43610 43660 43661 43787 44768 44778 45719 46255 46289 46362 46408 46449 46670 46691 46746 47333 47359 47383 47471 47480 47575 47745 48049 50404 50517 50687 50995 53276 55070 55110 55195 56853 57020 57120 60876 62073 62517 63258 64136 65141 65230 65318 65371 65599 65662 65880 66257 66421 66812 66933 67029 67097 67169 67593 67710 67803 67864 68522 69527 69611 69726 69795 69874 69936 70004 72502 74405 75606 76475 77634 77972 79435 80403 81344 82169 84266 87409 87595 87633 87657 87895 88339 88665 88849 89370 89465 89739 89932 90311 91170 92202 92433 93436 93725 93907 94029 94415 95402 98552 98570 99008 103853 105408 106152 106258 106428 106673 107178 107243 107361 108014 108335 108556 108813 108842 108862 109060 109081 109139 109313 109364 109580 109635 109801 110001 110095 110238 110316 110483 110846 111083 111195 111574 111647 111777 111867 111953 112097 112268 112345 112628 112742 115733 117381 118517 119739 119790 119926 119962 120104 120145 120268 120316 122226 122273 124480 124569 124804 125053 125219 125269 125353 126911 127164 128166 129411 129763 129936 131105 131150 131298 131330 131366 131777 132248 132932 133275 133383 133557 133623 133689 133775 133996 134034 134083 134137 134317 134421 134467 134658 134694 134759 134831 134973 136708 137217 137781 147380 149076]
[Arcadios|65205 147563]
[Arcaya|85763 85791]
[Archangel|88394 89279]
[Arg|48452 79067 123480]
[Argentina|186]
[Argote|116439]
[Arizona|144441]
[Armenian|6150 6267]
[Around|9043 41997 63591 88658 108654 125360]
[Arsenic|93132]
[Artemio|107271]
[As|5427 19892 21345 27526 31183 42242 44601 47741 48327 49289 50804 53395 55851 56742 56864 75710 83811 86215 97050 99810 103691 104939 105977 107593 108375 110521 110797 112236 126126 127511 135797 135930 146833]
[Ash|77769 86390]
[Asiatic|2110]
[Assistance|203]
[At|374 3058 4024 7415 7634 9324 10762 11935 13502 17409 19463 25832 27139 27333 30121 32007 35259 35317 35814 36723 37975 38139 38486 41776 43111 43667 44367 46154 46899 48469 49638 50312 53484 54815 55161 55892 56220 56250 56300 57459 57783 58027 58852 59175 59232 60289 61044 63164 64081 64175 65704 67430 68080 68750 68811 71815 73186 73950 75913 76150 79674 79726 80159 82017 86143 86438 87031 87896 90899 91667 93002 93655 94244 97160 97865 98517 99089 99563 100575 103089 103562 105417 108705 110965 111248 111403 111509 116581 119001 120288 121655 122996 126958 127384 129481 132992 133651 134243 138976 139782 144062 145702 146164 147312 147868 148442 149147]
[Atlantic|126527]
[Attracted|110063]
[Au|40574 63644 67683 70133 77707 85761 96027 127421]
[Auerliano|13056 13100]
[August|38824 43219 58764 58931 117892 119283 126900 132150]
[Augustine|143315]
[Augusto|123970]
[Augustus|148986]
[Aur|86056 149061]
[Aure|64773 68107 76856 101199 122238 127535 145816]
[Aurel|55567 129140 134296]
[Aureli|25658 73005 78576 91050 149231]
[Aurelia|18509 97966 116564 120416 140406 140588 147628 148260]
[Aurelian|28847]
[Aureliano|357 2252 3714 4538 5388 5513 5830 6569 7682 8576 8875 10765 10972 11670 12689 12794 14251 14315 14411 14513 14577 15083 15700 16161 17016 17084 17207 18362 18779 18925 18970 19008 19049 19094 19214 19420 20014 21249 21528 21856 22200 23462 23548 23651 23690 23751 23793 23903 23922 24174 24272 24304 24403 24468 24469 24646 24671 24778 24817 25117 25515 25715 25996 26086 26197 26278 26545 27315 27376 27993 28027 28063 28422 28432 28481 28681 29074 29265 29340 29650 31824 31844 31861 31907 32072 32332 32537 32780 33605 34358 34721 34764 34955 35089 35291 35358 35431 35470 35564 35655 36079 36227 36294 36396 36501 36540 36586 36794 36829 37015 37107 37138 37175 37194 37311 37386 37401 38071 38578 39424 39449 40295 40304 41675 41934 42143 42283 42372 43856 43975 44054 44089 44263 44372 44475 44556 44578 44689 44798 44969 45010 45090 45200 45326 45874 45979 46223 46500 46713 46850 46979 47011 47098 47386 47415 47438 47467 47885 47945 48512 48557 49006 49182 49319 49543 49583 49972 50209 50316 50386 50392 50568 50674 51134 51204 51348 51499 51589 51725 51808 52004 52068 52149 52202 52238 52467 52497 52552 52724 52842 52881 52974 53035 53272 53712 53784 54096 54146 54287 54343 54370 54473 54571 54790 54878 54910 54961 55049 55066 55327 55455 55490 55646 55666 55692 55746 55779 55849 55889 55897 56068 56110 56228 56343 56392 56437 56523 56951 57088 57134 57221 57249 57471 57554 57819 57868 57909 58024 58086 58209 58357 58829 58878 58909 58962 59136 59422 59458 59592 59650 59700 59772 60278 60329 60446 60496 60580 60666 60710 60777 60952 61108 61130 61392 61668 61699 62050 62139 62206 62855 62997 63265 63480 63618 63697 63742 63770 63936 63979 63995 64117 64223 64304 64501 64597 64796 65090 65233 65337 65352 65581 65684 65802 65967 66138 66254 66265 66294 66357 66401 67279 67307 67366 67436 67538 67718 67811 67861 67867 68019 68050 68220 68341 68429 68575 68617 68636 68752 68813 68902 69019 69114 69678 70626 70710 71048 71196 71324 71907 72119 72237 72329 72511 72616 72661 72700 72905 72936 73076 73315 73399 74322 74367 74422 74444 74759 74832 74979 75055 75169 75296 75385 75892 76109 76195 76415 76542 76568 76649 77104 77258 77337 77466 77596 77676 77950 77996 78303 78340 78420 78534 78975 78986 79156 79164 79171 79341 79417 79460 79506 79522 79560 79585 79830 79923 80627 81693 81710 81855 82191 82435 84562 85012 85028 85031 85078 85081 85085 85094 85215 85333 85493 85639 85666 85695 85790 85842 85961 85988 86021 86115 86393 86639 86892 87066 87320 87362 87683 88705 89677 90080 90095 90381 90474 90660 90736 90866 90997 91151 91241 91306 91348 91422 91657 91681 91747 91785 91843 92002 92231 92599 92629 92653 93068 93346 93646 93912 94228 95207 95315 95724 95953 96542 97084 97163 97315 97542 97634 97700 97915 98235 98345 98428 98467 98734 98962 99153 99347 99866 100625 100660 100703 101100 101456 101707 102312 102331 102945 103326 103862 104064 104098 104152 104756 104813 105701 106412 106438 106459 106509 106579 106968 107161 107544 110570 111100 111310 111330 111441 111488 111559 111714 111724 111765 111811 111828 111880 111960 112220 112467 112726 112962 113294 113334 113395 113463 114333 114441 114492 114542 114597 114678 114744 114824 114986 115039 115120 115163 115223 115319 115432 115989 116501 116668 116720 116736 116827 116909 117002 117156 117362 117567 117645 117687 117867 118005 118135 118242 118556 118809 118847 118962 119060 119101 119163 119485 120056 120588 120643 120805 120834 121433 121657 121828 121871 121918 122108 122225 122330 122536 122652 122763 122944 123212 123533 123663 123688 124469 124611 124691 124699 124740 124812 124863 125020 125029 125069 125106 125327 125367 125445 125558 125678 125770 126059 126264 126297 126477 126703 126841 126916 127211 127461 127491 127517 127597 127665 127696 127776 127858 127859 127894 127953 128199 128839 128902 128912 129000 129176 129217 129558 129586 130069 130113 130447 130764 131038 131124 131263 131290 131300 131662 131740 132190 133078 133172 133196 133233 133483 133921 133944 134026 134110 134252 134309 134426 134435 134596 134603 134660 134708 134779 134829 134949 135526 135604 136705 137166 137182 137351 137773 138070 138082 138124 138206 138278 138381 138552 138713 138772 138882 138946 138988 139113 139350 139453 139493 139753 139929 139983 140024 140063 140108 140175 140236 140306 140562 140719 140822 140911 141086 141254 141325 141360 141374 141810 141815 141938 142086 142212 142330 142399 142414 143185 143612 144021 144560 144895 144983 145163 145290 145312 145384 145480 145671 145742 145866 145949 146087 146213 146316 146442 146495 146544 146671 146718 146735 146748 146811 146908 146976 147154 147284 147397 147413 147660 147703 147807 147844 147951 148235 148244 148288 148421 148491 148731 148794 149001 149156 149395 149517]
[Aurelianos|65195 77656 83899 84993 89668 98728 146619 147572]
[Aurelito|25621 34900 35507 37381 37394]
[Avenue|155]
[Avo|102]
[Avon|87 150 300]
[Aware|147280 148476]
[Aztec|56713]
[B|14389 15945 62856]
[BARD|305]
[BEWILDERMENT|87389]
[BOOKS|177 220]
[BUEND|28991 37407]
[BY|173 79888]
[Babilonia|102062 102144 102192 102260 102305 102421 102483 102525 102579 102688 102839 102880 102908 103093 103305 103394 103554 103780 103944 104009 104185 104523 104946 105098 105294 105672 105945 106033 106597 149518]
[Babyloni|123780]
[Babylonian|138062]
[Babylonish|81396]
[Back|77821 140507]
[Bad|46121]
[Barcelona|85 143656 147129]
[Bard|71 88 301]
[Bastards|43814]
[Be|55663 83190]
[Beating|22622]
[Beauty|53326 53543 58292 58508 58609 61487 62160 65071 70145 70236 70371 70489 70541 70622 70799 70851 71006 71055 71160 72078 72264 72509 77549 78766 82235 82575 82714 82768 82904 83250 83582 83627 83663 83718 83792 83861 83920 84046 84404 84497 84573 84614 84687 84706 84788 84831 84907 89638 98721 103030 124581 128159 131928 135652 145222]
[Because|20963 21487 30634 35084 95029]
[Bede|139127]
[Before|4349 8266 11042 19007 36203 37308 38205 38349 42946 43495 60904 63621 131929 132355 135558 149469]
[Behind|35751 114265]
[Belgian|137438]
[Belgium|126465 141569]
[Believe|146731]
[Bengal|33399]
[Besides|121893 135154]
[Between|86575]
[Bible|107037]
[Big|26791]
[Bishop|48482 78120]
[Blind|55717]
[Blindman|131768]
[Bogot|26]
[Bohemian|21712 117050 120459]
[Books|89 104 151]
[Both|121553 125198 137335]
[Brown|80968 81010 81058 85114 85269 90980 97960 97970 98155 102095 102162 102231 102608 103110 107603 107702 107751 107798 108471 110726 110825 112496 118503 123877 144763]
[Bruno|39234 53149 79964 80043]
[Brus|129759]
[Brussels|124635 125850 126167 126296 126387 126909 137521 137669 140849 141049 144918 145623]
[Bu|52882]
[Bue|142243]
[Buen|8577 20665 146672]
[Buend|358 607 666 814 996 1095 1316 1462 1761 1840 1940 2008 2230 2589 2638 2925 3062 3292 3416 3571 3660 3715 3749 3918 4252 4480 4539 4610 4687 4822 5067 5175 5831 6011 6094 6179 6242 6360 6461 6483 6511 6921 7142 7240 7470 7527 7550 7583 7661 7683 7710 7755 7982 8014 8042 8178 8232 8271 8652 8751 10480 11478 11545 11648 12524 12609 12730 12872 13010 13145 13270 13710 13941 14025 14096 14143 14642 14700 14761 14826 15705 15722 15930 16052 16108 16444 16792 17216 17602 17745 17829 17958 18037 18119 18164 18204 19592 19730 19738 19761 20391 20458 20546 20612 20698 20931 21008 21202 21373 21409 21477 21512 21917 22071 22173 22356 22591 23378 23456 25090 25148 25172 25252 25371 25501 25562 25837 26394 26624 26707 27256 27673 27807 28105 28272 28401 28447 28494 29509 29574 30274 30336 30383 30438 30480 30518 30560 30610 31752 31938 32545 37195 37402 38472 38753 40290 40513 41576 41676 41935 42144 42284 42373 42715 43193 43857 44055 44264 44373 44476 44557 44579 44690 44779 45091 45201 45327 45597 45720 45875 45980 46183 46210 46501 46714 46747 46851 46980 47012 47099 47416 47468 47820 48513 48558 49007 49183 49320 49492 49544 49973 50317 50405 50518 50688 50996 52005 52069 52150 52239 52468 52498 52553 52843 52975 53036 54371 54572 54911 54962 55456 55710 55747 55890 56069 56111 56229 56393 56438 56524 56952 57089 57222 57250 57472 57555 57820 57869 57910 58025 58087 58358 58830 58910 58963 59137 59423 59593 59651 59701 59773 60279 60330 60447 60497 60581 60667 60711 60778 60877 60953 61131 61393 61669 61700 62140 62207 62998 63259 63481 63619 63646 63698 63743 63771 63937 63980 63996 64137 64224 64305 64502 64598 64775 64797 65123 65881 67308 68618 69528 69679 69875 70711 71049 71250 71325 71908 72330 74406 74423 75386 75643 75893 76404 76519 76650 76858 77105 77259 77597 77941 77973 78976 79157 79436 79523 80404 81027 81694 81856 82170 82192 82436 83687 84563 85013 85095 85216 85334 85494 86116 86380 86394 86640 87067 87321 87658 87684 88706 88850 90081 92203 92232 93069 93347 93913 94229 94416 95208 95316 95725 95954 98553 98631 98735 99154 99867 100256 100493 100626 100737 100913 103723 104645 104757 105409 106931 107545 110097 110224 111331 111489 111725 111829 111881 111961 112629 112727 113335 114334 115224 115990 116721 118518 118810 119740 120057 122109 122205 122227 122274 122742 123664 124470 125021 125220 127462 128840 131291 134604 135605 138083 139984 140025 140064 141816 145291 146578 146736 147381 147398 147555]
[Buenos|193]
[But|663 1744 1942 2152 2761 3613 4607 4781 5136 5654 6593 7774 8520 9230 9486 9594 10311 11261 12342 13062 13238 13880 13981 14410 16076 17145 17451 17883 18127 18394 19506 20934 21204 21362 22080 22284 22646 22770 23095 23650 24888 25209 25856 27375 28756 29870 30512 31040 31253 32096 33517 33865 34167 34651 34706 37992 38090 38319 38389 38537 38763 39482 40223 41091 41949 42286 42386 42497 45542 46982 49330 49530 50175 50332 50569 50849 51445 52258 52479 53497 53711 54831 56101 56466 57021 57394 57677 57841 58344 58567 58755 59753 60846 61541 61828 62137 62405 63236 64701 65800 66386 67315 67379 68219 68764 69609 71195 71840 72236 72410 74937 75612 75995 76076 76705 77023 79284 79456 79806 80749 83211 84453 84514 85077 86355 88492 88915 90040 90598 91842 92750 93948 96917 97068 98042 98438 99169 100004 100153 102744 102877 104136 106762 106905 107210 109209 110822 111611 111730 111912 112752 113119 113692 113810 115135 118134 119826 120091 120311 120545 121730 122023 123129 124298 124739 127651 128523 128786 129873 130492 130777 133206 134656 134810 136776 137471 139814 140429 141136 145014 146199 147842 148299 148465]
[By|1917 17514 20660 29582 45841 52097 136802]
[C|64221 131709]
[COLONEL|64 37405 57989]
[COUNTRIES|314]
[Ca|55749]
[Cabo|46941]
[Caf|145760]
[Camila|91252]
[Can|53975]
[Canon|143601]
[Cantabria|140696]
[Cap|46105]
[Captain|43555 45914 46011 46542 46659 46703 55016 55624 55650 55830 55935]
[Card|253]
[Caribbean|33427 35833 42349 46864 52580 56645 137535 140997 143970]
[Carlos|108913]
[Carmelita|55553 55904]
[Carnicero|43557 45916 46013 46108 46544 46661 46705 47172 52079 56762]
[Carpio|65146 70142 72538 76517 106929 116444]
[Carthaginian|143487]
[Castel|132829]
[Catalan|143377]
[Catalo|139086]
[Catalog|252]
[Cataloni|146917]
[Catalonian|127721 130154 131411 137270 137791 139468 140329 141576 143041 144519 145182 145689 147123 147193 148098]
[Catarino|18715 18782 18877 19517 24210 24386 32019 32950 33015 33248 37999 40475 45924 51839 54180 60271 67123 70091 70214 70785]
[Cataure|15873 40377 50940]
[Cate|126122 126482]
[Cates|114690]
[Catholic|60415 71233 121905 126416]
[Catholicism|98832]
[Cease|68947 91048 91060 127231]
[Centeno|79165 79586 85079 85667]
[Center|214]
[Central|52620]
[Centuries|127331 140689]
[Certain|136116]
[Chance|77082]
[Chapter|346 6662 13421 21576 28989 37404 43822 51118 57988 65084 72647 79886 87386 95940 104626 112363 119250 127283 135011 142838]
[Charity|75093]
[Chicago|107828]
[Chief|37504]
[Child|141602 148144]
[Children|14484 16465]
[China|39208]
[Chinese|50088 50150 54272 103236 148608]
[Christ|35063 43090 48639 122562]
[Christian|14805 116454]
[Christianize|29856]
[Christians|67020 89702]
[Christmas|52682 76315 76471 105835 107513 134775]
[Cien|198]
[Co|47169 60759 140082]
[Col|50076 57170 60691 64595]
[Collons|143594]
[Colo|49453 58818 127459]
[Colombia|7]
[Colombian|38]
[Colon|108062]
[Colone|44411 67305 72327]
[Colonel|356 4537 5829 8575 37400 41674 41933 42119 42142 42282 42371 42548 42951 43855 43908 44053 44210 44262 44371 44474 44555 44688 45089 45199 45325 45448 45873 45978 46499 46712 46849 46978 47010 47097 47149 47229 47297 47414 47466 48511 48556 49005 49181 49250 49269 49313 49318 49478 49489 49542 49912 49971 50180 50224 50315 51495 51931 52003 52018 52067 52077 52105 52148 52237 52466 52496 52551 52841 52880 52973 53034 54259 54369 54570 54909 54960 55454 55745 55888 56067 56109 56227 56391 56436 56522 56760 56950 57087 57220 57248 57470 57553 57818 57867 57908 58023 58085 58181 58356 58634 58714 58828 58855 58908 58944 58961 59037 59135 59421 59459 59591 59649 59699 59771 60277 60328 60445 60495 60579 60653 60665 60709 60776 60937 60951 61072 61089 61129 61286 61391 61667 61698 62138 62205 62854 62996 63170 63479 63617 63643 63681 63696 63741 63749 63769 63935 63978 63994 64303 64500 64533 64772 64795 65665 66597 66642 68616 69677 70709 71047 71323 71817 71906 72039 74421 75384 75891 76648 76855 76945 77103 77257 77595 78974 79155 79521 81024 81692 81854 82190 82434 84561 85011 85093 85214 85332 85382 85492 86114 86392 86638 87016 87035 87065 87172 87319 87349 87682 88704 89060 90079 92230 92257 93067 93345 93747 93911 94169 94227 95206 95314 95445 95723 95952 98694 98733 98977 99152 99865 100624 104755 107543 108591 109099 109869 110403 111329 111487 111723 111827 111879 111959 112725 114086 114244 114332 115222 115988 116719 118808 120055 123662 124468 125019 128838 134602 135603 138081 139982 140023 140062 141814 145289 146734 147396 148611]
[Colossus|115265]
[Columbines|72478]
[Come|23677 33877 35505 42847 101344 105987]
[Commander|37502]
[Company|21720 120456]
[Con|52743]
[Congo|137439]
[Congratulations|7567 56166]
[Congress|251]
[Conquered|25244]
[Conser|85204]
[Conservati|52708]
[Conservatism|36474]
[Conservative|35203 35654 36091 36419 46893 47591 52736 56791 59106 59508 60521 64573 64699 66629 71396 75923 77212]
[Conservatives|34967 35032 35674 36290 52265 55632 86935 86949]
[Consult|59076]
[Contrary|40491 47337 145950]
[Convalescence|49426]
[Convinced|117677 124990]
[Cook|120477]
[Copyright|282]
[Cores|68360]
[Coronel|53136]
[Corporation|226]
[Cortes|108914]
[Cot|68725]
[Cotes|67734 68266 68295 68417 68547 68596 68700 68793 68832 68881 69642 72669 72732 72890 72958 73130 73417 75114 75205 75306 85846 90388 90511 90753 90871 91010 91240 91777 91969 92037 96822 97380 97553 97681 97723 98476 101715 104204 106628 112551 112992 113094 114517 114578 114774 114967 114998 118915 119116 119192 120602 120624 120723 120918 121458 121512 121719 123210 123706 125389 127027 127103 128012 128355 146512]
[Cowards|55737]
[Cracow|106091]
[Crazy|30637]
[Cre|39597]
[Crespi|21750 21782 22005 22046 22686 22812 23896 25036 25100 25269 26865 26973 27143 27251 28534 29603 29621 29668 30912 30947 31010 31163 32362 33668 34023 34056 34088 34102 34141 34177 34443 34560 34614 34648 34680 36646 38877 39021 39055 39157 39235 39247 39302 39445 39513 39536 39583 39654 39848 39906 40054 40212 41328 44765 46279 49651 49764 51341 53150 54766 57044 64950 70385 77544 79965 80044 89033 92738 98892 99060 99926 132025]
[Cripple|127315]
[Crusader|33424]
[Cruz|107272]
[Cu|107953]
[Cuba|52662]
[Cura|35799 35836 42337]
[Cyprus|2706]
[DAZZLED|79887]
[DID|127285]
[Dagger|55606]
[Dagoberto|107780]
[Dauphine|145741]
[Dawn|6775]
[Day|39870 65063]
[Days|9403]
[Daz|102501]
[Deaf|36808 68564]
[Dear|69185]
[Death|43392 99694]
[December|1670 18213 36836 60293 64803 76451 135019]
[Decree|108890 111009]
[Defeated|17594]

[...] output truncated

[hun|11992 89390]
[hundred|3385 5945 6986 18573 42937 55918 56840 66351 67900 71422 101289 107965 109933 111847 117797 117817 117936 120172 120206 120865 120888 122921 122925 123034 123896 124161 124981 125471 125924 126227 127681 133516 135189 136632 139203 140139 141617 141881 146779 148956 149544]
[hung|4318 17315 22328 32922 33828 47651 55216 66153 81594 86010 90596 94079 119374 123382]
[hunger|14990 15253 41309 63842 87301 90847 103827 105565 139516 141506 143423 145128 145780 147508]
[hungry|75547 83142]
[hunt|46824 122014]
[hunted|80961 85622]
[hunting|3726 3941 35179 41547 42100 47605 49866 80930 136141]
[hurch|31177]
[hurricane|118607 149393]
[hurricanes|112427]
[hurried|13058]
[hurry|19186 127745]
[hurrying|30659 117016]
[hurt|40104]
[hurting|10615 58587]
[hurts|145098]
[husband|733 2631 3207 5604 6823 6976 7335 7465 7741 7920 9020 9790 12504 13407 13451 14483 20279 31674 38416 38637 41243 41793 43931 43986 46381 47678 57051 64214 67749 74959 75195 76049 76135 86637 90456 90579 90618 92069 92635 92661 97728 101471 104976 106498 113542 113672 115506 115865 116123 116228 116610 116773 125524 127980 128434 135028 135193 135233 135764 136083 136692 136961 137130 140543 140901 141081 142653 144994 145829 145909 146019 146108 147065 147622]
[husbands|4812]
[huts|105285]
[hy|16841 16917]
[hydrologists|80944 81040]
[hymns|81648]
[i|1012 6161 7781 8987 11106 12848 15870 17181 27783 30815 37134 52847 56395 60160 61985 64069 70501 72396 73817 76968 91981 98319 100286 102987 105001 107382 123710 130743 133885 137083 140298 141307 147778]
[ia|47942]
[ial|126308]
[ials|4913]
[iano|55568 129141 134297]
[iated|51918]
[ible|19455 42390 89092]
[ical|19995 80565]
[ice|373 6480 6521 8771 8795 8854 11202 11229 19750 46620 54408 60984 77968 78654 79326 79603 92667 95689 96960 109063 117376 136912]

[...] output truncated

[vomit|24525 106709 148349]
[vomited|24107 33762 96943]
[vomiting|84040]
[von|26263]
[voracious|81427 118495]
[voracity|41230 91185 123611 145341 146973]
[vote|36056]
[voted|35313 36127]
[votes|35372]
[voting|35285]
[vows|120332 129934]
[vulgarity|90279 102300]
[vulnerability|83917]
[vulnerable|127919]
[vulture|26598]
[vultures|95939]
[w|718 1305 1658 3265 6816 8170 10812 12028 12921 16840 18015 18191 20222 21234 22717 23784 24578 32745 34905 35145 35286 38365 38510 43374 44303 45918 55528 57575 60126 61389 62173 62402 63576 65060 68253 68511 69424 70386 73596 78426 78968 79684 84369 87601 93526 93838 94261 95118 96344 97934 99759 104564 106467 115918 119676 121763 122172 123107 127836 131093 132041 133342 142128 144077 147925]
[wa|9877 15756 16765 18299 21523 28632 29998 40383 73936 100017 111873 119524 128343 134881]
[waged|52750 87096]
[wages|52448]
[waging|35119]
[wailing|40030]
[wails|8667]
[waist|28969 33945 37751 40732 56588 114532 138777 142421]
[wait|9178 10287 15135 24625 25731 42421 49164 55586 73391 99285 99320 100762 104464 107145 108407 111245 112565 117898 127133 138764 139063 140483 141164]
[waited|1363 23802 24008 24036 24743 25725 34628 36830 39510 40660 40799 40811 46260 46276 49660 50142 80891 94527 101413 107060 130380 138490 138579 141713 143130]
[waiting|1370 6454 7649 10169 10202 10830 24592 25540 31420 33783 39702 40630 40974 42748 45910 46323 49805 58415 60909 61983 64542 64606 71807 73362 76449 78346 85977 87198 87289 91929 93213 102408 104540 108054 108658 108718 108748 110593 111105 113544 113735 114476 115058 115512 120729 129943 134445 134762 138066 138734 142310 144921]
[waits|99290]
[wake|7701 24799 26838 33874 39933 65434 70777 85827 122295 148324]
[wakeful|146312]
[waking|600 51425 60205 121368 124006 125371]
[walk|25916 53246 81554 83758 92998 112946 126551]
[walked|6751 21569 23216 28577 57070 69919 110946 140262 145215]
[walking|1591 3000 6747 18841 27628 28195 37901 44172 50829 64628 72135 81940 86425 89270 101427 105129 110035 115475 124130]
[wall|17249 20568 22977 27775 43123 43502 43608 43645 46239 46470 50745 57962 86066 94260 110489 115649 117948 122289 148140]
[walled|27740]
[wallow|61023]
[wallowed|53912]
[walls|3262 5686 8764 13814 15297 15368 17856 18007 23186 23952 27765 28468 31700 33736 41298 47836 48288 61923 64419 70907 74573 78073 79023 81945 89178 89244 90890 93279 95121 112435 117055 118759 119493 122983 123562 128573 128769 129252 133590 135322]
[waltz|14137 15647 16569 51604]
[waltzes|77541 98889]
[wan|60090]
[wand|99080]
[wander|25800 37796 80415 92189]
[wandered|86417 132491 148007]
[wanderers|13990 118724]
[wanderi|137986]
[wanderin|129359]
[wandering|8533 11759 20257 40868 70935 84617 89262 89297 93715 97657 112614 116277 124547 127010 134340]
[wanderings|117280]
[wane|23351]
[want|9385 10636 10703 20916 45941 49137 50214 52145 54726 56298 60288 71540 72930 78529 92428 97581 100294 105031 115299 116899 120165 120514 120532 147180]
[wante|16575]
[wanted|6015 9260 9269 9579 9989 10597 15036 16641 16672 16703 16734 20449 23705 25265 25493 29172 29977 31266 44459 50547 57854 68771 73337 75450 83199 84658 89233 91978 98135 99055 99744 108988 116166 120803 127054 130762 134102 136610 136683 145224 146025]
[wanting|34987 97605]
[wants|4986 34518]
[war|1022 1358 8574 14706 21279 28051 34782 34953 35120 35430 35490 35607 36749 37160 37544 37604 38581 38956 39292 39423 40610 41354 41975 42294 43888 45053 46699 47131 47274 48688 49214 49425 49516 49997 50286 50681 51890 52227 52330 52361 52478 52722 52751 52907 52947 53030 53084 53117 53148 53380 53918 53922 54001 54813 55006 56050 56408 56473 56949 57645 58003 58041 58139 58228 58497 58725 58851 59088 59124 59273 59412 60039 60108 60136 60196 60486 60535 61144 61162 61361 61497 61759 62018 62415 62506 62549 63075 63139 64414 64478 64531 64666 64821 65659 66537 67745 67957 68027 69252 69456 69706 71082 71674 71704 71750 76766 77202 77369 77419 79094 81076 85182 85369 86234 86558 87030 87099 87126 87149 87166 87690 87842 88723 92252 94182 94615 95437 99159 108519 111891 111989 128336 132203 132639 147004 147406]
[ward|148721]
[ware|117052]
[warehouse|39167]
[warfare|79444 142660]
[warm|3286 5837 27596 39097 41372 51482 51520 62993 142151 149163]
[warmed|110184]
[warming|12631]
[warmth|12092 41103 60165 138930]
[warn|20999 82499 85998 111193 141283]
[warned|655 44493 55668 82474 83514 117830]
[warning|1626 60851 92891 104317 135040 145971]
[warnings|116241]
[warranted|85293]
[warrior|50161 61524 115257 138195]
[warriors|45313]
[wars|61010 68415 74131 74429 78204 78605 85235 88766 118815 141834 143091 146743 147636]
[was|3 182 210 360 378 414 429 520 651 711 777 801 1054 1170 1181 1261 1577 1630 1633 1835 1899 1977 2041 2099 2118 2237 2313 2467 2618 2677 2725 2736 2763 3200 3295 3367 3371 3388 3396 3491 3662 3694 3801 4105 4294 4303 4365 4395 4412 4455 4547 4562 4974 5077 5104 5138 5254 5321 5347 5407 5527 5557 5617 5623 5646 5735 5763 5771 6154 6189 6194 6332 6346 6377 6410 6425 6442 6905 6935 7002 7022 7072 7207 7376 7387 7454 7466 7472 7562 7648 7653 7719 7789 7829 7877 8000 8056 8125 8147 8218 8376 8441 8468 8603 8675 8857 8863 8922 8942 8993 9009 9023 9085 9202 9416 9482 9596 9644 9741 9775 9922 9978 10006 10021 10074 10119 10136 10378 10439 10857 10998 11040 11053 11108 11179 11344 11440 11526 11642 11779 11795 11801 11816 11821 11855 11874 11957 12053 12059 12196 12203 12404 12444 12461 12617 12642 12648 12680 12825 12943 13092 13095 13137 13155 13162 13426 13437 13484 13506 13526 13592 13623 13822 13868 13900 13944 14129 14139 14181 14214 14223 14363 14492 14504 14551 14578 14609 14653 14702 14746 14768 14797 14860 14929 14996 15022 15060 15077 15111 15302 15343 15443 15472 15555 15560 15578 15617 15677 15747 15868 15876 15961 16061 16128 16328 16372 16380 16505 16520 16532 16630 16839 16932 16939 16969 16980 16988 17015 17022 17059 17109 17126 17178 17308 17322 17387 17476 17486 17538 17557 17578 17629 17780 17789 17796 17812 17886 17911 17924 17998 18023 18028 18049 18147 18152 18206 18218 18222 18247 18259 18407 18481 18534 18547 18570 18645 18746 18806 18870 18885 18923 18937 18944 19002 19057 19095 19277 19281 19289 19330 19576 19624 19708 19721 19837 19845 19936 19969 19990 20101 20183 20362 20405 20415 20465 20593 20831 21111 21206 21214 21404 21558 21584 21620 21677 21783 21898 21919 22091 22145 22154 22250 22463 22540 22602 22743 22773 22779 22854 22868 22876 22895 22951 23108 23125 23336 23348 23365 23538 23576 23696 23740 23758 23763 23774 23884 23890 24042 24175 24189 24445 24492 24713 24890 24911 24982 25072 25084 25261 25440 25477 25570 25735 25748 25758 25782 25790 25870 25875 25889 26071 26224 26248 26626 26670 26688 26701 26722 26769 26779 26945 26981 27003 27026 27038 27184 27211 27350 27432 27452 27660 27972 27998 28015 28111 28219 28255 28300 28372 28376 28437 28440 28784 28836 28905 29015 29091 29095 29157 29185 29199 29225 29473 29476 29572 29577 29590 29618 29702 29749 29762 29804 30101 30217 30327 30378 30388 30492 30515 30619 30674 30688 30716 30769 30872 30949 31107 31255 31318 31345 31442 31470 31483 31547 31647 31725 31828 32143 32166 32190 32202 32206 32279 32559 32578 32606 32620 32631 32658 32782 32865 32870 32904 33139 33191 33265 33274 33495 33533 33669 33800 33838 34079 34110 34253 34359 34364 34573 34669 34688 34723 34758 34780 34824 34853 35270 35277 35293 35417 35540 35649 35748 35762 35968 35985 36121 36138 36152 36270 36284 36408 36436 36557 36624 36632 36726 36731 36776 36859 36873 36893 36900 36932 36942 37046 37243 37302 37478 37582 37635 37690 37811 37843 37942 38092 38188 38281 38481 38742 38755 38832 38902 39162 39179 39239 39367 39371 39397 39461 39476 39624 39712 39817 39942 39969 40125 40178 40225 40266 40339 40390 40531 40555 40615 40629 40638 40896 40902 40968 40973 41017 41050 41174 41481 41530 41616 41701 41759 41855 41919 41924 41939 42244 42273 42332 42375 42388 42428 42452 42481 42694 42744 42770 42943 42990 43009 43087 43119 43213 43325 43414 43577 43647 43749 43811 43825 43865 43917 43954 43974 44040 44087 44158 44168 44171 44226 44402 44696 44804 44866 44870 44880 44917 44994 45329 45429 45480 45591 45726 45800 46083 46112 46136 46197 46202 46335 46545 46551 46630 46758 46765 46896 46930 46935 46959 47003 47114 47144 47174 47211 47294 47303 47357 47458 47514 47587 47684 47695 47703 47729 47735 47900 47947 47998 48036 48102 48358 48374 48408 48431 48441 48473 48477 48492 48515 48545 48601 48689 48699 48702 48864 48914 48937 49021 49046 49054 49101 49238 49322 49401 49482 49511 49623 49642 49797 49900 49998 50116 50228 50296 50412 50485 50505 50520 50527 50543 50577 50586 50656 50676 50684 50704 50755 50768 50878 50888 50903 50916 50935 50939 51032 51173 51207 51234 51290 51298 51412 51435 51459 51615 51775 51785 51794 51811 51843 52008 52023 52054 52114 52174 52229 52251 52335 52372 52381 52441 52490 52520 52530 52555 52605 52612 52647 52697 52706 52772 52792 52867 52913 53031 53038 53051 53099 53132 53152 53180 53213 53221 53224 53414 53545 53668 53695 53723 53781 53926 53962 54073 54148 54365 54404 54437 54502 54523 54592 54601 54668 54731 54958 54964 55081 55208 55365 55461 55492 55525 55579 55602 55612 55695 55744 55765 55834 55856 55859 55869 55950 56015 56023 56053 56081 56124 56154 56183 56255 56329 56376 56450 56462 56488 56519 56561 56601 56652 56674 56711 56755 56825 56890 56923 56964 57023 57107 57199 57209 57338 57466 57570 57993 58058 58148 58197 58258 58285 58307 58320 58414 58509 58513 58538 58617 58623 58650 58654 58708 58835 58840 58892 58948 58970 58976 59056 59080 59208 59227 59293 59355 59504 59566 59703 59761 59785 59915 59990 60027 60067 60149 60172 60188 60306 60454 60573 60768 60780 61100 61157 61241 61254 61332 61339 61373 61434 61449 61461 61600 61646 61770 61912 62028 62032 62091 62128 62214 62242 62282 62423 62507 62526 62641 62644 62653 62697 62719 62780 62859 62883 62963 63031 63045 63244 63530 63570 63648 63716 63738 63815 63839 63909 63931 64101 64168 64199 64205 64231 64244 64259 64279 64287 64326 64481 64540 64551 64577 64648 64676 64684 64709 64755 64759 64806 64856 64978 65051 65078 65114 65335 65351 65361 65379 65383 65472 65491 65617 65625 65652 65714 65823 65934 65961 65969 66070 66078 66146 66175 66184 66203 66208 66215 66382 66487 66676 66683 66691 66778 66830 66899 66924 66928 66960 67114 67120 67291 67299 67349 67368 67373 67549 67558 67589 67595 67619 67732 67765 67805 67833 67896 68035 68104 68125 68247 68279 68283 68356 68431 68536 68701 68716 68740 68897 68925 69162 69181 69359 69481 69582 69721 69792 69835 69857 69904 69938 69998 70006 70062 70130 70146 70179 70251 70310 70330 70373 70404 70456 70464 70578 70601 70628 70748 70795 70852 70861 70889 71016 71041 71056 71063 71110 71134 71168 71174 71223 71252 71282 71306 71318 71328 71353 71407 71552 71628 71658 71678 71738 71751 71901 72006 72079 72134 72208 72231 72373 72452 72535 72650 72752 72810 72876 72947 73089 73258 73304 73317 73433 73437 73490 73497 73593 73600 73627 73658 73663 73678 73702 73717 73815 73824 74006 74008 74012 74236 74329 74629 74749 74762 74816 74944 74964 75009 75025 75189 75269 75455 75467 75546 75615 75805 75948 75964 76010 76016 76037 76081 76187 76232 76269 76371 76394 76476 76539 76665 76668 76719 76788 76806 76826 76868 76914 77013 77071 77487 77613 77644 77706 77838 77989 78018 78084 78128 78212 78216 78258 78406 78428 78565 78632 78639 78822 78947 79073 79104 79174 79222 79293 79333 79360 79399 79425 79451 79526 79579 79731 79771 79847 79862 79983 80052 80171 80211 80254 80267 80317 80338 80354 80389 80506 80663 80708 80877 80921 80984 81078 81101 81206 81326 81490 81538 81551 81729 81834 81905 81934 82090 82094 82111 82151 82153 82236 82241 82249 82327 82389 82523 82545 82596 82606 82632 82638 82657 82676 82682 82701 82726 82785 82810 82839 82956 83083 83109 83131 83141 83160 83254 83284 83296 83316 83318 83331 83402 83431 83471 83551 83587 83610 83666 83741 83771 83945 84051 84071 84089 84114 84116 84130 84211 84225 84231 84255 84470 84510 84530 84542 84574 84688 84708 84798 84803 84923 85352 85386 85641 85668 85675 85714 85731 85764 85784 85801 85822 85897 85960 85965 86023 86071 86105 86300 86378 86446 86521 86642 86765 86781 86917 86924 87039 87564 87587 87697 87779 87797 87873 87884 87901 87930 87963 88029 88047 88076 88092 88112 88245 88364 88409 88448 88488 88507 88557 88566 88577 88585 88597 88820 88831 88842 88857 88865 88894 89115 89139 89221 89261 89287 89327 89380 89419 89424 89430 89513 89560 89570 89651 89723 89746 89799 89883 90016 90055 90078 90117 90185 90215 90317 90373 90429 90452 90462 90602 90646 90686 90807 90904 91085 91115 91243 91308 91328 91362 91383 91404 91482 91491 91510 91542 91586 91614 91677 91683 91766 91787 91928 91987 92004 92022 92080 92120 92176 92226 92234 92364 92399 92444 92460 92532 92586 92631 92683 92716 92739 92802 92831 92852 92909 92962 93022 93053 93089 93107 93122 93200 93334 93350 93362 93372 93397 93411 93485 93549 93555 93634 93659 93727 93789 93841 93849 93959 94062 94105 94205 94273 94303 94401 94418 94519 94564 94570 94631 94635 94654 94682 94748 94759 94902 94951 95057 95106 95112 95125 95269 95335 95360 95368 95381 95397 95412 95523 95532 95561 95596 95700 95814 95934 95960 96003 96031 96104 96191 96311 96442 96493 96500 96518 96553 96797 96828 96876 96894 96905 97041 97113 97120 97245 97253 97259 97273 97322 97373 97384 97476 97512 97544 97557 97565 97588 97652 97705 97744 97912 97958 98080 98144 98177 98237 98300 98353 98520 98544 98547 98650 98657 98708 98738 98801 98822 98856 99013 99044 99135 99145 99200 99235 99243 99249 99298 99336 99371 99378 99520 99543 99558 99623 99660 99676 99701 99709 99732 99755 99856 99875 99887 99974 99999 100012 100037 100132 100193 100240 100258 100279 100346 100373 100404 100482 100517 100573 100670 100676 100689 100739 100802 100848 100851 100991 101136 101255 101281 101295 101299 101308 101335 101396 101452 101460 101466 101481 101486 101517 101571 101653 101683 101750 101841 101889 101914 101958 101989 102036 102060 102073 102110 102120 102151 102157 102167 102180 102278 102296 102382 102397 102407 102429 102435 102470 102497 102557 102626 102671 102675 102691 102726 102812 102825 102909 102936 102996 103017 103019 103045 103065 103105 103159 103172 103232 103250 103296 103307 103603 103611 103688 103700 103736 103772 103813 103821 103993 104022 104029 104141 104209 104216 104292 104324 104403 104527 104539 104653 104672 104801 104886 104921 105159 105480 105574 105708 105887 105934 106028 106132 106154 106273 106329 106370 106381 106403 106473 106511 106551 106675 106750 106770 106785 106802 106811 106825 106887 106898 106934 107115 107136 107162 107349 107363 107374 107453 107457 107655 107703 107747 107854 107911 107934 108011 108016 108021 108035 108044 108091 108373 108473 108480 108509 108558 108616 108648 108663 108816 108833 108954 108993 109007 109217 109248 109330 109357 109408 109480 109522 109640 109651 109663 109714 109721 109818 109922 110008 110050 110083 110115 110118 110130 110192 110388 110445 110554 110590 110707 110839 110857 110885 110905 110993 111011 111081 111103 111198 111210 111314 111418 111491 111514 111593 111649 111696 111733 111787 111869 111875 111963 111992 112044 112151 112286 112295 112316 112341 112469 112532 112612 112653 112668 112687 112754 112761 112765 112810 112843 112885 112909 112969 113149 113218 113228 113231 113283 113327 113331 113350 113397 113453 113543 113562 113589 113600 113625 113658 113713 113723 113745 113858 113951 114056 114062 114069 114090 114159 114178 114207 114365 114398 114410 114561 114581 114611 114618 114657 114699 114717 114727 114751 114923 115020 115094 115127 115175 115218 115253 115330 115434 115456 115471 115474 115522 115539 115562 115606 115687 115787 115835 115907 115949 116058 116068 116070 116084 116131 116294 116321 116325 116333 116387 116424 116427 116506 116588 116614 116715 116766 116774 116787 116790 116818 116867 116962 116986 117077 117146 117206 117210 117302 117363 117372 117383 117390 117453 117562 117629 117638 117928 117933 117953 117998 118025 118107 118137 118272 118297 118323 118333 118338 118378 118497 118534 118671 118740 118916 119054 119088 119103 119107 119128 119170 119182 119202 119441 119454 119782 119801 119829 119964 119981 120049 120075 120086 120151 120215 120302 120373 120547 120552 120696 120859 120907 120938 120969 121122 121150 121173 121247 121256 121267 121442 121529 121548 121765 121813 121830 121929 121973 122001 122009 122071 122105 122301 122374 122377 122389 122428 122442 122461 122488 122509 122557 122594 122619 122782 122935 122969 123001 123050 123118 123123 123196 123227 123266 123279 123298 123311 123421 123440 123554 123574 123594 123606 123618 123690 123698 123712 123729 123803 123863 123868 123949 124018 124022 124271 124370 124430 124521 124546 124692 124885 124900 124935 125004 125055 125119 125126 125206 125222 125234 125283 125439 125518 125588 125720 125786 125797 125828 125831 125938 125951 126078 126086 126153 126200 126362 126364 126373 126388 126571 126592 126739 126778 126913 127238 127429 127522 127537 127543 127595 127691 127727 127770 127852 127879 127898 127939 127994 128020 128214 128224 128270 128280 128314 128320 128361 128416 128432 128438 128515 128547 128552 128576 128738 128795 128821 128850 128917 128948 128964 129009 129075 129254 129266 129272 129302 129338 129364 129486 129557 129582 129605 129620 129708 129777 129783 129937 129942 129967 130077 130084 130095 130207 130229 130490 130494 130673 130754 130901 130913 130943 131047 131080 131106 131222 131521 131580 131641 131673 131815 132002 132242 132362 132531 132554 132574 132713 132861 132933 133007 133075 133119 133197 133369 133453 133474 133535 133599 133611 133883 133942 134073 134124 134132 134170 134188 134289 134313 134323 134345 134392 134493 134547 134555 134581 134595 134669 134760 134832 134925 134934 134944 134955 135086 135436 135469 135483 135504 135512 135581 135627 135654 135739 135805 135921 136067 136185 136210 136269 136295 136349 136467 136481 136535 136544 136564 136766 136787 136962 137049 137114 137205 137352 137363 137367 137395 137410 137431 137478 137525 137598 137609 137885 137931 137957 138016 138111 138158 138201 138224 138227 138382 138468 138599 138651 138733 138796 138847 138906 138959 138980 138989 139054 139177 139241 139257 139274 139334 139343 139423 139472 139528 139749 139834 139863 139924 139962 139972 139988 139998 140037 140102 140285 140331 140435 140474 140490 140513 140616 140621 140628 140936 140991 141005 141013 141094 141149 141168 141176 141187 141317 141516 141538 141597 141605 141673 141768 141812 141871 141978 142015 142039 142081 142123 142181 142235 142247 142267 142314 142394 142403 142554 142589 142641 142753 142775 142869 142928 142942 143012 143177 143182 143223 143340 143355 143447 143458 143535 143540 143564 143785 143835 143850 143940 144069 144170 144296 144321 144329 144400 144478 144506 144527 144555 144562 144609 144625 144699 144784 144862 144882 144954 145038 145313 145324 145372 145385 145397 145633 145792 145799 145847 145927 146001 146037 146076 146136 146214 146443 146490 146493 146501 146507 146539 146574 146592 146614 146658 146670 146924 147103 147118 147133 147166 147206 147550 147595 147693 147757 147780 147850 147896 147920 148105 148196 148297 148302 148468 148497 148639 148703 148738 148855 148938 148968 149018 149107 149195 149274 149281 149327 149366 149375 149422 149489 149531]
[wash|7962 29104 31769 65957 93218 101184 105115 110188 112571 132054]
[washed|26585 48116 64879 86351 92526 95590 103218 103635 117109 119347 126669 135320 142463]
[washing|8168 79686]
[washroom|129357]
[wasn|58409]
[waste|39621 60590 63654 69003 70648 78744 86567 99778 129294 145209]
[wasted|83437 121033 124589 145112]
[wasteland|86517]
[wasting|48745 48756]
[wastrel|116281 127014]
[watc|130235 145137]
[watch|15354 31086 38896 52828 57709 57782 57833 58272 59383 67580 69109 74062 88467 94222 101326]
[watched|4859 28766 30280 35278 51133 74437 76578 84828 88155 108341 114098 114775 142854 145119]
[watchful|56612 92358 97146 132545]
[watching|1510 6403 46236 59648 61995 64753 68664 95740 116782 123811 133138 142544 144479 146659]
[water|395 2473 3331 3861 4664 7866 7874 8096 8156 8806 8949 12892 12989 15038 23989 25966 26446 26471 26565 26652 38036 51408 55763 55959 58438 58866 65876 65952 69551 77851 79613 83073 83286 86354 89515 89993 101180 105583 110186 112917 114189 114528 118367 122079 122525 126560 131070 131138 132809 133314 134909 136869 143875]
[watercolor|39079]
[watercolors|144450]
[watered|73775]
[waterfalls|69759 144104]
[watering|120352]
[waterproof|31798]
[waters|8560 67697 81356 131960]
[watery|11056]
[wattles|104891]
[wave|43656 45499 46350 48406 109446 109475 126846]
[waved|29244 144457]
[waves|59842 92167 119269 122155 122412 130664]
[waving|11538 79832 84832]
[wax|95093 116200]
[waxed|21265 86450 98782]
[way|3318 3519 3647 5619 5738 5788 5809 6183 6745 6896 7005 7515 8297 8549 9679 10752 11861 12546 12823 12854 14170 14601 15151 15937 16955 16994 17107 17329 20868 21079 21248 21654 21981 22726 26483 26757 27084 28204 28288 30598 30766 30895 32752 33218 36903 37305 38238 38536 39959 43563 43666 44143 44484 44586 44977 45125 45414 46343 51400 51437 51730 53935 54441 54547 54968 55489 56355 58582 59716 60631 61707 61737 62168 66655 67304 69146 69194 71059 72087 75285 76190 77443 77895 78798 79634 82331 83134 83333 84459 84611 85026 86962 87550 88401 89632 90937 90959 91039 91486 91554 92564 93057 93147 94500 94741 95514 96715 99480 100118 100136 100432 101106 102372 102740 104362 104826 107376 109498 109785 109895 110850 111067 113372 113403 115262 117034 117565 118092 119532 120187 120540 122405 123624 124897 126800 128022 130189 130251 131426 133710 135478 135821 136994 138642 139073 139484 140782 143143 143200 144378 149050]
[ways|24278 29204 141726]
[we|3029 4989 5011 7768 7857 7937 8204 8208 9501 10655 10679 10682 10690 11967 13294 15918 15938 20711 20736 20822 22273 25692 30144 34653 37715 38427 38588 42880 44003 53997 56285 57212 57406 57419 57639 58565 60458 60488 60526 60562 60604 60636 62201 63371 69195 69198 69780 73332 75916 76421 81687 81702 81999 85244 85597 85979 87116 89247 90086 106167 107013 109055 110803 117755 119634 119640 123569 145111 147086]
[wea|74387]
[weak|46513 84448 130952 134065]
[weaken|70699]
[weakness|19121 36826 63090 114124]
[wealth|14226 30976 121563]
[weapo|35180]
[weapon|1020 1206 7610 42598 48100]
[weapons|3942 33421 35557 35597 37170 37212 44528 52092 60688 62598 97733 108417]
[wear|14295 37915 73339 87259 88397 91980 100610 126524 126542 127056 128382 132063 136280 146680]
[wearier|60051]
[weariness|141206]
[wearing|7151 18229 23630 29269 32579 38978 46596 48000 53565 56562 65336 65362 66216 70335 75026 80567 83473 91684 94312 101890 101990 105911 125173 126740 130914 131642 133008 135041 142293 143984]
[weary|60028]
[weasel|142505 147035]
[weaseling|142498]
[weather|31803 50492]
[weave|73996]
[weaving|92400 92535 98521]
[web|4844 38981 74828 103530 141226]
[webs|128774 136149 147772 148674]
[wed|32412 61425 136855]
[weddi|94059]
[wedding|26988 29090 29182 29495 29617 29652 29663 29700 29748 29801 30758 31228 31263 31352 31440 31526 31563 34283 39374 39443 44666 57764 72981 73407 73786 74846 88130 92356 125568 126895 147222]
[weddings|34748]
[weeded|87670]
[weeds|105775 123581 128586 128757 132380 135274 147347]
[week|4030 4179 21108 27044 29854 31365 31556 36666 44033 46262 46757 49120 49580 49693 52050 52257 58021 61612 74083 74799 77092 85610 92016 92879 92990 94562 98200 100064 102465 102589 103348 104051 106349 110854 114898 114959 116636 118304 121665 121745 126239 126991 127999 132051 142011 143549]
[weekend|107193]
[weekends|136585]
[weekly|120755 125866 137253]
[weeks|2597 4331 12727 13434 15583 16095 21843 24032 26869 29020 33354 37103 42451 43831 50331 50853 52311 53499 54015 59755 64681 65940 67435 68709 74538 74949 79748 80952 92019 92118 92286 106184 114592 123204 129455 138140 138769]
[weep|9224 19433 22852 23052 33466 38246 49932 58783 63383 74287 80109 83858 98706 98899 117501 125387 141431 148120]
[weepin|17979]
[weeping|7821 22857 24091 24714 28540 32861 40017 43949 76426 86626 88840 96681 102804 117331 126006 142154 142182 142907 148285 148411]
[weepy|65117]
[weevils|117135]
[weighed|27820]
[weighing|80828]
[weight|1680 7942 19079 19145 23236 24362 24844 32115 40467 50439 57347 58770 60680 66026 74259 75747 88573 88607 101286 103453 108264 124412 141298 148649]
[weighted|11796 104101]
[welcome|20928]
[welcomed|47433]
[welfare|3099]
[well|3132 3160 8051 9025 12662 14811 16172 17921 19398 20353 21343 21368 21791 25638 34793 42991 43442 44872 47107 54880 55166 56236 56282 57379 70088 70737 70862 73218 74177 77409 77991 77994 79195 81451 83103 84700 85718 85945 91411 98097 108611 113901 115594 116302 116401 116597 121245 124894 126506 130989 131771 132100 133051 137421 137528 140280 142097 149411]
[welts|62304]
[wen|57915]
[went|509 568 613 2409 2772 2804 2894 3987 4013 4184 4228 5519 6096 7148 7285 7511 7712 7912 7990 8986 9302 9568 11088 11514 12019 12563 12638 12690 13284 13760 14455 15264 17253 17380 17737 17969 18721 18780 18985 19789 21166 21187 21250 21289 21425 22681 22847 23054 23680 24124 24200 24825 25399 25509 26084 26562 27834 28072 28420 28496 29961 30045 30067 30222 30920 31157 31705 32690 32748 32801 32946 33240 33726 33810 34301 35173 35688 36602 37997 38543 38579 39574 39661 40088 40136 42050 42311 42615 42676 44464 44512 45917 47474 47663 47679 47774 47789 47823 47844 47861 47888 47935 48016 48364 49149 49466 50535 50992 51706 51824 52165 54178 54311 54714 55594 56772 56837 57716 59889 61207 63704 65101 65324 65944 71262 72618 73078 73157 74106 74903 75156 76127 77500 77773 77914 77998 81843 83352 83443 83719 83818 86905 87660 88419 91024 91197 93101 93157 93443 94215 94394 94800 95475 95628 95728 95842 95923 97471 99503 101722 102092 102250 102873 103391 103681 103999 104408 104794 104997 105372 105465 105501 105728 108147 108410 108606 109834 110070 110334 110430 111164 114009 116576 117744 118558 118575 119062 122587 123160 123597 123767 124001 126294 126475 126563 128075 129525 130804 130831 131116 131301 131488 131511 132433 133189 133919 133945 137239 137826 139069 139079 139511 140809 140945 141375 141501 141852 141903 142364 143418 146628 147503 148017 148492]
[wept|1049 5413 26610 29713 35875 38397 39604 39668 40418 78587 130436 148088]
[wer|11323 36351 87834]
[were|405 1647 2246 3045 3179 3191 3272 3601 3864 4206 4224 4345 4814 5131 5429 5486 5687 5753 5876 5896 6453 7014 7034 7099 7273 7801 7841 8313 8561 8639 9350 9506 9713 9783 9917 9946 10016 10630 11065 11192 11214 11536 12109 12356 13299 13369 13382 13533 13570 13810 13861 13914 13931 14078 14435 14819 14902 14992 15258 15531 16333 16409 16457 16513 16915 16919 17336 17993 18227 18844 18860 19888 20040 20844 21133 21339 21652 21659 21704 21977 22119 22163 22195 22210 22453 22520 23230 23407 24520 24717 25539 25679 25764 25934 26027 26356 27222 27778 28565 28856 28996 29071 29435 29815 31245 32314 32595 32643 32724 33097 33183 33473 33863 34009 34073 34215 34257 34317 34948 34983 35056 35070 35247 35374 35481 35512 35604 35632 35856 36033 36046 36064 36082 36373 36384 36490 36654 36764 37053 37132 37431 37913 37983 38031 38803 39026 39217 39594 40351 41191 41331 41461 42138 42643 42776 43263 43676 43894 44164 44208 44215 44429 44525 44616 44714 44940 45023 45249 45295 45491 45518 45535 45832 45909 46058 46474 46693 46761 46917 47054 47380 47550 48725 50449 51093 51582 51697 51712 51960 52182 52958 53210 53288 53417 53761 54574 55014 55064 55236 55354 55659 55913 56032 56516 56579 56732 57094 58161 58176 59534 59547 59871 59878 59931 59976 59996 60215 61582 61779 61869 62126 62202 62486 62521 62580 62582 63064 63448 63453 63608 63614 63924 64020 64742 64783 64996 65196 65206 65212 65222 65226 65236 65428 65682 65889 65907 66135 66263 66393 67456 67700 68024 68069 68118 68444 68681 68850 69196 69218 69297 69475 69533 69781 69954 70110 70241 70257 70764 70989 71776 72219 72360 72381 72465 72582 72993 73013 73215 73757 73888 74133 74377 74549 74823 75835 75855 75879 76332 76462 77300 77365 77523 77657 77749 77756 77842 78205 78240 78250 78920 79099 79279 79755 80273 80335 80471 80555 80644 80729 81011 81238 81243 81507 81514 81574 81872 82040 82101 82157 82438 82537 82847 83029 83833 83877 83894 83911 84063 84877 85060 85100 85106 85191 85262 85320 85621 86110 86465 86809 87287 87370 88038 88149 88662 89201 89345 89549 89617 89669 89779 90200 90298 90413 90494 90655 90826 91233 91896 92095 92325 92992 93006 93035 93084 93131 93171 93230 93272 93896 93974 94007 94199 94830 95739 96370 96571 96657 96861 97597 97720 97820 97860 97987 98318 98604 98809 98845 100030 100465 100646 100939 101351 102855 102941 103139 103382 103465 103573 103831 103972 104171 104416 104513 104636 104895 105042 105128 105140 105308 105804 105924 106247 106469 106532 106848 107216 107241 107274 107312 107338 107406 107486 107550 107584 107894 108156 108188 108236 108247 108465 108688 108738 108797 109503 109509 109532 110275 110367 110458 110478 110524 110889 110937 111069 111095 111182 111252 111287 111368 111407 111670 111773 112253 112334 112355 112375 112548 112783 113630 113647 114078 114195 114283 114643 114649 114664 115032 115057 115279 115575 115652 115881 116210 116732 116841 117190 117252 117507 117590 117700 117890 118226 118386 118448 118608 118692 118749 118771 119273 119500 119577 119904 120109 120192 120197 120776 121216 121344 121373 121630 122293 122787 122951 122980 123005 123104 123152 123239 123329 123345 123778 124128 124253 124674 124994 125356 125382 125572 125618 125977 126005 126220 126232 126429 126450 126494 126504 126515 126607 126931 126940 126985 127184 127409 127649 128007 128189 128309 128396 128719 128776 129690 129795 129818 129889 130110 130150 131004 131012 131444 131539 131561 131682 131856 132135 132341 132519 133107 133265 133384 133499 134240 134275 135730 135737 135817 135856 135984 136526 136603 136919 137505 137542 138064 138250 138688 139364 139408 139579 139653 139675 139958 140092 140178 140417 140957 141558 141644 141781 142285 142613 142663 142699 142797 142832 142977 143002 143125 143246 143272 143370 143393 144051 144117 144156 144404 144711 144899 145031 145487 145554 145563 145705 145893 146171 146244 146390 146482 146636 146765 146838 146844 146885 147017 147263 147320 147356 147438 147476 147530 147700 147707 147822 147860 147881 148157 148718 148752 148921 149081 149145 149446]
[weren|110329]
[west|3854 22668 118295]
[western|8488 43870 52243]
[wet|25027 43614 64140 112796 113975 121152 122958]
[wets|25632]
[wetting|29135]
[wever|11361 55999]
[wh|14206 15308 26017 47278 47675 61904 65488 94138 115161 116853 118673 124724 129634 130013 144706 144849]
[wha|111984]
[whale|116826]
[whales|113272]
[what|495 942 1998 2116 3706 3842 4828 4833 4972 6345 6545 7482 7560 7749 7921 8145 8672 10004 11412 12002 12169 12641 13231 13897 13988 14900 15526 15901 16127 16813 18729 19931 20462 20661 20887 23124 24489 24876 26221 27655 28031 28109 28598 30732 34224 36230 36381 37169 38426 38520 38656 40493 41048 41758 42134 44645 45316 45409 45798 46195 46785 47358 48838 48848 48861 48957 51305 51563 51569 52728 53716 54949 56191 56888 57678 59892 60286 65548 65713 66406 67003 67664 67971 68957 69163 71625 73327 75208 75453 79061 79110 81098 81236 82002 83317 84207 85058 88015 88391 92361 93125 93990 94558 94651 94671 95698 97610 98025 98049 99122 99380 99561 100865 101359 101658 102136 102670 103102 103491 110761 112560 114055 114750 115296 115911 115925 116067 118205 118273 118339 118856 118873 119779 120845 121172 121377 121669 122372 122431 122435 122679 124427 124797 125093 126312 126324 127816 129015 131772 135530 137197 140659 142746 142783 143180 143574 143642 145952 146667 146732 147183]
[whatever|76706 120530 121966]
[whatsoever|274]
[whe|10994 43304 45365 52535 118712 138386]
[wheel|58518 105508 105637 136209 142275]
[wheelbarrow|55944]
[wheels|81063 114172]
[when|366 1846 2222 2866 2943 3628 4545 4618 4874 4956 5380 5511 5658 7083 7222 7524 7851 8164 9859 10156 10312 10394 11076 11187 11225 12625 12810 12881 13282 13770 14179 14361 14998 15340 15993 16096 16210 16652 16683 16714 16976 17290 17400 17496 17702 17753 18128 18215 18950 19201 19514 20418 21014 21567 21597 22544 23008 23048 23345 23574 23608 24344 25113 25283 26273 26353 26496 26507 27051 27141 28221 28846 29305 29339 30124 30312 30541 30685 30712 31105 31192 31242 31372 31449 32161 32217 32473 32875 33319 33338 33611 33798 33934 34173 34233 34601 34652 35624 36200 37714 37830 37995 38508 38541 38825 39215 40086 40150 40232 40337 40613 40846 41137 41459 41673 41830 41875 43408 43598 44091 44743 44894 45038 45224 45342 45543 45641 46219 46418 48372 48432 48605 48843 48852 48866 48891 48911 49147 49621 49735 49947 49995 50893 51029 51171 51205 51230 51335 51404 51450 51492 51704 52134 52865 53418 53666 53690 54890 55352 55470 55523 55635 55774 55896 56378 56677 57534 58345 58505 58960 59439 60065 60176 60451 60976 61474 61542 61616 61709 61722 61787 62120 62271 62382 62518 62642 62687 62712 62940 63169 63785 63891 64151 64217 64440 64555 64771 64850 64976 65099 65288 65329 65386 65496 65660 65801 65942 66034 66261 66379 66492 66559 67389 67587 67755 67866 68004 68123 68304 68481 68767 69012 69197 69567 69676 69848 70806 70881 71166 71561 71752 72145 72601 72904 73237 73421 73711 74160 74321 74370 74616 74689 74700 74961 75121 75154 75249 75352 75740 76077 76472 76594 76757 77024 77223 77825 77987 78105 78652 78669 78680 78696 79807 79928 80260 80295 80776 81104 81915 81932 82334 82554 82686 83340 83455 83715 84151 84347 84398 84454 84515 84656 84681 84735 85163 85220 85653 85725 85877 86743 86747 87318 87743 87786 87847 87860 87955 88089 88204 88219 88446 88602 88829 89448 89590 89608 90041 90751 91171 91251 91421 91454 91540 91775 91995 92318 92442 92708 92778 92858 93580 93587 93746 94213 94851 94960 95175 95198 95568 95638 95682 95806 95916 96167 96430 96466 96636 96929 97091 97526 98123 98375 98752 99001 99068 99241 99271 99346 99649 99699 99904 100331 100623 101059 101382 101469 102090 102377 102488 102701 102878 104641 104799 104851 105336 105361 105424 105608 105649 105706 105726 105957 106064 106409 106857 107166 108061 108520 108623 110711 110755 110823 111147 111579 111915 112061 112118 112196 112306 112874 112975 113257 113623 113652 114076 114437 114632 114686 115108 115326 115342 115446 115569 115729 115744 115903 116511 116608 117199 117644 117960 117970 117996 118254 118309 118682 118973 119200 119264 119284 119329 120733 120875 121191 121200 121370 121628 121921 122025 122069 122323 122387 123401 123715 124171 124824 124840 124855 125105 125299 125585 125704 126543 127061 127450 127519 127608 127685 127775 128059 128311 128393 128524 128787 129160 129368 129523 129575 129874 130068 130195 130891 131078 131312 131456 132087 134045 134298 134318 134336 134471 134837 135536 135625 136095 136293 136528 136777 137055 137423 137472 137493 138411 138435 138881 138945 139586 139642 139673 139887 139906 139978 140096 140283 140415 140844 140878 141110 141137 141775 141850 141876 142322 142739 143473 143524 143698 143815 144043 144654 145015 145156 145411 145757 146042 146121 146590 147049 147111 147666 147737 148300 148478 148808 149006 149394 149516]
[whenever|5119 14536 30940 75544 134100]
[where|560 1823 3166 3279 3393 3403 3700 3862 3999 4447 5098 5124 5684 5720 6136 6375 6876 7640 8825 8991 9414 9650 9913 9948 9959 10013 10018 11462 11870 12023 12116 12374 12557 12940 13367 13380 14688 15157 15860 17535 17574 17820 17991 18914 19320 19719 19828 20119 20174 20959 22267 24224 24448 25596 26050 26089 26894 27390 28878 29067 30105 32261 32719 32912 32953 35908 36248 36752 38268 38287 39277 39364 40442 40636 40645 41146 41698 42061 42339 43099 43356 43803 44517 47898 47944 48023 48787 52398 55138 55326 55598 56448 56985 57059 57896 58056 59012 59054 60993 62358 62956 63604 64291 65470 65878 68018 69310 71276 72626 73459 74459 74522 74530 74545 77378 77740 77807 79903 80381 80957 81300 81487 81637 82794 82968 84886 85760 85913 86528 86792 87458 87939 88284 88468 88482 88555 93051 96597 96608 96653 97338 97693 97718 97905 97991 98157 98538 103015 103026 103167 103848 103858 104116 104537 105039 105292 105379 105402 105700 105802 105862 106629 108012 108795 109499 109622 110006 110074 110314 111179 111289 111476 111764 113721 114353 114655 114662 115537 116009 116163 116172 116252 117323 118527 118838 119737 121291 121459 121860 122049 122576 122779 123498 123680 125147 125751 125962 126420 126454 127707 127725 128679 128915 129326 129684 129806 130747 131123 131501 131519 131684 131811 132339 132438 132480 132524 133073 133412 133463 133471 133738 133974 134302 136257 136541 136597 136600 136681 137440 137996 138047 138731 139283 139790 139920 139950 140369 142390 142398 143053 144083 144600 144880 145631 145790 145840 146049 146878 146893 147217 148030 148511 149263]
[whereabouts|106456 127839]
[wherever|41937 59326 60892 136431 140232 144286]
[whether|15558 16670 16701 16732 16763 34685 48495 62909 66967 68963 68968 74913 81241 87820 99706 105155 105166 107444 112637 112705 116016 122426 123417 123443 128187]
[whi|117615 146065]
[which|260 404 786 799 869 1152 1437 1581 1699 1952 2144 2676 2892 3839 3906 4394 4643 4719 5253 5481 5841 6224 6436 7679 8063 8086 8098 8609 9712 9943 10919 11497 11594 13688 14039 14052 14085 14093 14237 14680 15072 15211 16629 16635 17331 17395 17475 17586 17910 17917 18101 18161 18425 18502 18858 19809 19905 20155 21022 21127 21983 22114 22337 22867 22916 23398 23799 23894 24910 24958 25071 25957 26176 26330 26344 26352 26666 26735 26818 26908 28184 28317 29566 29725 29783 30175 30580 31155 31580 31681 32100 33168 33412 33483 33995 34423 34751 35276 35881 36445 37490 37594 38985 39498 39771 39785 40426 41540 41976 42068 42978 43258 43333 43558 43844 44835 44983 45032 45831 46249 46270 46989 47113 47586 48254 48292 48615 48655 50179 50636 50762 50776 52965 53172 54221 55611 55949 56064 56397 56508 56600 56782 57175 57590 57603 58047 58839 59159 59330 59718 59806 59968 60298 61408 61431 61853 62509 62609 63152 63423 64029 64647 66010 66125 67082 69470 69505 69699 69709 71770 72005 73324 73489 74403 74420 74435 74729 74782 74921 75347 75360 75585 75602 76108 76918 77499 77578 77643 78280 78391 78563 79292 79433 79548 79846 80316 80669 80858 81220 82322 82668 82884 83976 84461 84785 85738 86079 86130 86156 86191 86326 87482 88037 88058 89028 89053 89404 89710 90109 90281 90442 90916 92143 92349 92514 92524 92671 93323 93868 94318 94822 95322 95334 95587 96017 96110 96133 97126 97986 98263 98506 98644 98690 99082 99470 100301 101210 101849 102025 103018 103410 103752 104703 104828 105306 105329 105475 105510 105923 106291 106566 106736 107348 107386 107810 108694 109479 109787 109815 109888 110191 110656 110991 111513 111604 112133 112252 112261 112380 113061 113885 114144 114206 114326 114364 114454 114738 115915 115929 117036 117094 118128 118544 118661 119033 119757 120178 120377 120632 120981 120999 121030 121121 121139 121149 122943 123370 123614 123875 123899 124072 124376 124497 124850 125298 125307 126185 126492 126514 126802 127408 127621 127731 127841 128775 129186 129743 130206 130342 130647 130692 131175 131221 131230 131538 131606 131863 131919 131992 132278 132286 132361 132394 132628 132642 132867 132905 133521 133548 133621 133994 134122 134151 134176 134452 134465 134635 134741 134924 135159 135202 136074 136206 136237 136533 136861 136918 137016 137181 137285 137325 137554 137670 137817 137903 138012 138190 138226 138488 138650 138679 138795 138893 138905 138958 139256 139492 139689 140196 140223 140396 140748 140943 141456 141612 141977 142085 142114 142880 143115 143392 143720 143779 143957 144129 144551 144761 145043 145055 145752 145916 146258 146427 147202 147262 148496 148573 148586 148603 148617 148967 149000]
[whiff|7443 130619]
[whil|21157 121348]
[while|1943 2010 2303 2786 3028 7339 9175 10454 12033 12172 18231 18450 19860 22039 24187 26371 27130 30238 31468 31919 33899 34544 35353 36888 37232 38570 42613 44914 45907 48758 49747 52262 53033 56252 56307 56467 56548 57489 58305 60936 66173 66478 73598 73700 74893 76133 79137 82051 83400 85819 87064 88146 91674 92224 93356 94679 95853 99170 102994 103379 104401 107058 107653 107783 109323 110175 110551 111161 111924 115381 115520 116729 116764 122592 126605 129236 132215 132980 133195 133687 138978 140760 140899 141981 143270 144167 144828 145370]
[whimpering|25489]
[whims|82981]
[whimsical|4491]
[whimsy|7244]
[whip|38185]
[whipping|15550 57432 133865]
[whirlwind|31708 109517 149379]
[whis|36198]
[whisper|10714 75364]
[whispered|27059 52142 53701 70398 101086]
[whispering|3245 10631 48826 94282 133148 139035]
[whispers|40021 95968]
[whistle|79735 144197 147341]
[whistles|26733 79781 79815 138302 142786]
[whistling|11141 80521]
[white|406 4357 16360 20445 20898 20971 20972 21580 22516 23631 28244 32302 60326 63462 65364 66854 69070 69183 73643 75028 78685 81185 81310 83488 93129 94993 95120 95254 95459 101907 105211 115905 115947 124233 135319 136307 141676]
[whitecaps|143973]
[whiteness|89175 132863]
[whites|40148 40159 49083 87729 145463]
[whitewash|15291 22471 23183 33733 61920 69177 78070]
[whitewashed|41297]
[who|482 650 700 998 1169 1248 1777 1864 2253 2561 2830 3036 3071 3088 3216 3294 3603 3947 4813 5465 5875 5903 5942 5958 6125 6151 6911 7147 7156 8399 8876 8956 9722 9797 10104 10123 10511 11095 11525 11535 11794 11829 11956 11978 12195 12202 12460 12505 12647 12674 13057 13311 13452 13545 13638 13894 13904 13955 14145 14163 14444 14587 14626 14650 14654 14711 14724 14745 15257 15601 15770 16121 16264 16352 16389 16574 16871 16891 17017 17489 17546 17564 18249 18262 18569 18577 18745 18769 19326 19405 19594 20015 20318 20408 20518 20881 21312 21538 21794 22030 22132 22194 22209 22214 22519 22656 22778 22797 23172 23199 24227 24249 24528 24596 24602 24608 25092 25260 25600 25630 25799 26609 26709 26866 26944 27110 27210 27238 27343 27349 27577 27601 27616 28249 28352 28359 28564 29257 29438 29478 29643 29705 29814 30159 30276 30285 30404 30520 30591 30751 30805 31730 31972 32285 32340 32384 32440 32766 32781 33016 33096 33109 33116 33239 33368 33537 33581 34363 34433 34722 35037 35246 35766 35945 36008 36350 36698 36730 36763 36869 37059 37081 37224 37279 37296 37784 37912 38029 38369 38417 38887 39118 39741 40388 40516 40546 41187 41244 41398 42040 42188 42693 42724 42808 43005 43177 43203 43212 43850 43883 44250 44416 45302 45336 45428 45722 45976 46308 46723 46820 47050 47066 47173 47326 47549 47723 48440 50659 50675 50945 51077 51810 51857 51990 52007 52181 52696 52823 52917 53078 53151 53241 53259 53312 53956 53961 54192 54591 55196 55214 55400 55424 55497 55678 55694 55833 56903 57097 57187 57298 57310 58515 58537 58545 58610 58616 58649 59092 59119 59510 59673 59857 59920 59944 59952 59960 59973 60022 60076 60080 60089 60113 60224 61223 61290 61510 61525 61629 62178 62219 62429 62448 62766 63447 63464 63558 63613 63838 64313 64405 64751 64845 64995 65382 65384 65532 65569 65593 65998 66023 66475 66486 66781 66994 67000 67021 67190 67255 67348 67502 67517 67750 67940 67950 68524 68849 68888 69274 69434 69865 69918 69953 70150 70202 70288 70407 70592 70632 71292 71327 71364 72201 72222 72362 72380 72895 73009 73033 73436 73548 74184 74487 75480 75636 75694 76019 76030 76179 76231 76240 76305 76733 76906 76987 77599 77678 77704 77879 77910 78017 78045 78065 78133 78620 78842 78928 78946 79072 79179 79683 79754 79979 80012 80178 80473 80483 80515 80543 80554 80605 80949 81018 81123 81151 81360 81475 81573 81593 81627 81864 81974 82032 82037 82240 82536 82562 82852 83098 83430 83560 83656 83832 84062 84436 84466 84707 84802 85036 85525 85629 85730 85783 85861 86291 86299 86475 86650 86659 86850 87044 87084 87136 87176 87249 87686 88522 88747 89012 89157 89181 89225 89882 90070 90217 90300 90637 90798 90981 91322 91594 92205 93042 93396 93558 93641 93829 94015 94587 94733 94751 95738 96005 96072 96987 97045 97324 97511 97940 98414 98593 98737 100291 100449 100693 101254 101834 102428 102625 102811 103258 103675 103945 104066 104611 104793 105320 105715 106674 106824 107110 107184 107258 107299 107537 107548 107660 108337 108402 108472 109768 109847 109862 109872 110274 110453 111027 111102 111197 112189 112357 112473 113438 113452 113698 113788 113896 115031 115174 115195 115473 115507 115651 115692 115824 115834 115847 115896 115944 115967 116040 116140 116332 116384 116465 116648 116817 116896 117382 117393 117418 117429 117542 117624 118405 118592 118921 119122 119421 119426 119792 120196 120590 120775 121093 121405 121800 122103 122244 122962 123159 123676 123819 123910 123981 124000 124092 124127 124315 124529 124573 125185 125238 125467 126004 126449 127264 127693 127903 127928 127959 128027 128147 128168 128195 128365 128654 128959 129459 130435 130464 130555 131045 131632 131658 131759 132192 132249 132490 132589 132600 132611 132763 133118 133254 133356 134704 134712 135257 135299 135765 135779 136378 136493 136697 136712 137696 138075 138110 138467 139003 139510 139557 139637 139866 139992 140006 140261 140275 140350 141196 141500 141619 141665 141682 141712 141756 141780 141999 142008 142025 142038 142208 142995 143417 143493 143834 144456 144561 144565 144793 144963 145030 145327 145562 146203 146657 147303 147502 147602 147876 148045 148217 149106 149125 149208 149225 149273]
[whoever|14594]
[whole|1679 1833 2754 3832 4421 11391 12150 12330 16183 16296 16500 17233 18134 18719 23869 27463 28730 30695 34326 36401 36452 36864 39174 39670 39996 46052 48193 56267 60679 61993 63387 74258 76412 79664 85453 86340 87710 88122 88606 92813 92952 92989 93424 100207 100281 101039 101425 110103 110835 113927 115965 116526 123670 123902 128171 129091 140316 140356 145966 148327]
[whom|6828 6924 25814 29735 32050 33194 34563 37264 39452 41124 41197 41523 41917 42146 43229 45453 48483 50575 50957 51637 51862 52692 52701 53137 57320 59005 71052 85267 85844 86099 86903 87226 88813 92872 93504 93516 94627 96413 101260 103153 103428 105822 110412 116292 116365 117462 123060 128356 130378 135079 139470 140028 143242 143250 146514]
[whooping|60085]
[whore|40765 143025]
[whores|60211 81395 106283 139636]
[whorish|109620]
[whos|139754]
[whose|609 4070 5918 8559 10023 10026 10337 12696 12795 14793 15843 18695 19684 22230 26919 27554 28013 33374 33547 33677 36196 39127 50166 51613 53159 53206 53967 54680 55867 56916 59274 59543 65792 68269 69552 70126 70237 71850 71996 76367 76803 79990 83900 88985 88992 89199 90455 90653 91635 94702 94709 96180 96469 105517 105741 108159 121185 123086 123092 124910 130092 130177 134128 137881 138098 138698 139362 142465 144617 144801 146620]
[whosufu|75433]
[why|10371 15247 18991 22952 41818 43141 49259 49286 49340 50968 53479 54250 54263 54275 59532 60060 64099 82282 82546 86847 88327 92407 92439 107044 111975 115604 115610 121396 121403 135741]
[wi|3754 19714 38037 86016 86201 96592 100787 109987 115613 138534]
[wic|50729]
[wick|94511]
[wicker|57082 141762 141956 142844]
[wicks|31047]
[wide|41270 43622 47853 48229 52858 75829 82471 84754]
[widen|81751]
[widespread|2137 58145]
[widow|56902 59376 59445 78064 90454]
[widowhood|44793]
[widows|138051]
[wif|25412]
[wife|81 699 1168 1776 5074 5180 6719 6880 7493 7578 7718 7987 12616 14782 20464 21129 21398 25247 25608 25636 27216 32151 36482 36887 43437 52916 57866 62419 75101 76218 86223 88739 90401 90493 90683 91959 92078 96060 97666 104821 115274 116816 125587 127025 136105 136357 136413 137339 137464 141203 146256 146541]
[wig|99408]
[wiggle|116310]
[wigs|82378]
[wild|1275 3586 4021 5169 10740 11352 14499 34348 39769 41415 42538 59645 67963 68206 72138 72965 72983 77684 86308 109406 113122 118509 120966 121559 138300 138673 144788 147525]
[wilder|91083]
[wildest|144316]
[wildflowers|78263]
[wildly|68238 118410]
[wildness|77617]
[wiles|59578]
[will|937 5001 5007 5063 5076 14589 17357 19757 21449 27478 27512 28093 30723 30752 32458 35427 39072 40780 40786 42262 45059 45618 45678 45965 45992 46306 49107 50441 53406 54137 56192 57131 57407 60887 62742 63210 66669 67880 67890 67983 69206 70032 73064 73747 77908 82482 84270 86835 104718 105164 106544 107025 111058 114683 115323 116151 122798 122804 124082 132360 132508 141629 142774 147829]
[willed|23821 38683]
[willful|7334 8953 53279 147559]
[willing|13575]
[willingly|25656]
[willow|136321]
[willows|76427]
[win|31096 57643 61369 67424 120701 147633]
[wind|30991 41275 78230 84740 84814 118475 119287 122145 124174 137570 149161 149293 149504]
[winding|19818 90236]
[window|2288 5188 11520 23840 24020 26010 36214 36264 39857 41347 46244 46388 46422 46453 48415 51040 52140 65083 66195 70618 71003 80459 105358 110569 110776 114104 124181 124275 125172 126724 127565 129027 132682 133168 133965 142552 144394]
[windowpanes|73578]
[windows|6806 6884 20132 27175 29264 29940 32232 41284 47529 64896 65806 78249 79015 79975 81183 90883 105788 105956 112827 119706 120471 124112 135310 137849 142960 145203 148828 149303]
[windowsill|112173]
[winds|20254 33446]
[wine|115906 115922 115948 115956 134168]
[wines|133618]
[wineskin|112660]
[wing|118192 127577 149314]
[winged|139153 144426]
[wings|2138 66231 93828 103063 117198 123369 125181]
[winner|121180]
[winners|126246]
[winning|120741]
[winter|38826 78227 79679 112644 144165 144215]
[wintry|8841]
[wipe|52625 53883 77205 87332 104966 111073 118480]
[wiped|13994 30184 42140 42910 46918 62411 109601 119048 149500]
[wire|58110 81219 110441 117808 133507 141631]
[wired|108642 118445]
[wires|108461 136572]
[wiry|138188]
[wisdom|2159 10883 13970 22581 66331 67211 72256 127932 134193 136475 139471]
[wise|80765 104031 106772 110119 123782 124945 127720 130153 131410 131708 137269 137790 139085 139467 140328 141575 142496 143040 143426 144518 145181 145688 145809 146916 147122 147192 148097]
[wisely|111308]
[wish|45557 45631 50187 52440 54953 55742 59373 66429 85043]
[wished|5122 29258 56411 64038]
[wishes|39983 47343 65681 66058 75804 96075 106984 116362 119787 124457 142867 145983]
[wishing|58697]
[wit|21987 24144 28404 40993 41885 51951 53305 58604 64524 71870 77307 97242 102423 111948 114233]
[witch|43876 103735]
[witchcraft|125621]
[with|79 244 454 475 590 794 836 965 1110 1567 1698 1810 1923 2108 2136 2291 2478 2500 2513 2649 2694 2700 2780 2821 2849 2914 3090 3145 3153 3332 3344 3442 3466 3584 3593 3654 3727 3737 3825 3856 3882 3927 3950 4234 4306 4336 4347 4397 4402 4451 4616 4718 4861 4916 4979 5045 5085 5091 5269 5285 5423 5457 5853 5912 5931 6069 6075 6380 6388 6431 6534 6541 6638 6686 6764 6923 7050 7182 7193 7235 7242 7252 7307 7366 7411 7623 7666 7673 7678 7796 7819 7843 7893 7996 8004 8062 8085 8097 8250 8316 8328 8446 8626 8663 8680 8762 8808 8832 8947 9058 9148 9214 9263 9377 9418 9429 9443 9601 9612 9769 9788 9862 10086 10175 10348 10403 10487 10560 10598 10640 10798 10923 10953 11161 11167 11172 11252 11471 11484 11568 11766 11911 11931 12065 12121 12182 12237 12301 12326 12347 12379 12420 12644 12691 12705 12801 12844 12925 13018 13130 13305 13327 13333 13384 13395 13550 13586 13626 13641 13657 13678 13693 13755 13844 13863 13878 13890 13966 14064 14101 14112 14187 14227 14431 14546 14622 14636 14671 14834 14889 14934 14943 15052 15161 15219 15298 15325 15376 15517 15624 15651 15735 15772 15813 16055 16164 16239 16363 16385 16469 16560 17167 17242 17371 17714 17725 17733 17764 17840 17848 17860 17896 17904 17937 17951 18149 18167 18196 18428 18456 18501 18522 18741 18765 18775 18810 18820 18838 18878 18955 18996 19025 19235 19265 19323 19444 19679 19785 19908 19962 20013 20080 20113 20116 20124 20131 20151 20309 20337 20535 20578 20614 20654 20716 20993 21021 21113 21120 21140 21188 21232 21251 21264 21331 21387 21461 21586 21707 21849 21952 21969 22021 22220 22247 22483 22493 22514 22522 22573 22639 22706 22745 22749 22783 22794 22816 22899 22915 22927 22972 22982 23147 23218 23287 23386 23397 23415 23431 23490 23519 23546 23568 23615 23698 23726 23798 23871 23893 24068 24087 24092 24201 24218 24285 24298 24412 24465 24514 24522 24534 24556 24662 24747 25016 25022 25028 25038 25067 25176 25212 25290 25514 25583 25641 25706 25892 25908 25927 25936 26008 26012 26040 26046 26054 26107 26169 26294 26304 26329 26447 26514 26595 26611 26672 26715 26727 26739 26759 26814 26922 26935 26938 26974 27103 27172 27226 27301 27396 27409 27414 27422 27474 27544 27569 27582 27595 27606 27635 27663 27760 27864 27923 28040 28065 28243 28388 28658 28734 28795 28921 29073 29081 29227 29245 29252 29275 29326 29368 29380 29393 29503 29550 29607 29714 29764 29899 29933 29965 30014 30049 30163 30188 30323 30410 30533 30740 30756 30832 31115 31186 31258 31418 31473 31488 31507 31513 31586 31603 31622 31672 31684 31715 31765 31771 31797 31813 31841 31914 31922 31936 32043 32047 32233 32268 32305 32320 32368 32395 32513 32598 32669 32716 32789 32798 32841 32862 32906 32984 33081 33211 33243 33440 33556 33596 33641 33706 33737 33749 33767 33777 33788 33832 33905 33952 34081 34106 34272 34456 34510 34534 34733 34772 34875 35091 35095 35128 35152 35163 35198 35209 35304 35344 35357 35395 35404 35563 35634 35726 35767 35850 35876 35952 36001 36109 36265 36463 36520 36561 36564 36693 36718 36728 36761 36909 36986 37021 37095 37115 37198 37358 37365 37372 37509 37611 37670 37730 37756 38010 38101 38180 38214 38330 38335 38498 38555 38602 38619 38641 38679 38715 38736 38912 38992 39016 39033 39038 39123 39150 39184 39195 39267 39392 39497 39529 39561 39610 39651 39699 39743 39777 39913 39991 39999 40140 40259 40321 40367 40373 40392 40425 40433 40454 40665 40733 40744 40805 40915 40946 41117 41196 41393 41505 41545 41788 41916 42005 42017 42081 42195 42490 42606 42617 42660 42681 42705 42733 42798 42812 42836 42977 43000 43024 43053 43062 43072 43190 43272 43279 43332 43586 43613 43649 43921 44114 44130 44184 44201 44327 44405 44432 44537 44567 44706 44716 44727 44952 45036 45067 45152 45215 45241 45780 45803 45822 45946 45995 46132 46176 46253 46263 46269 46364 46529 46641 46662 46674 46711 46780 46800 46866 47104 47162 47184 47193 47254 47317 47348 47375 47407 47521 47571 47603 47624 47865 48120 48130 48136 48181 48232 48238 48261 48287 48322 48347 48377 48433 48465 48669 48682 48704 48813 48919 49071 49215 49353 49378 49471 49506 49607 49645 49680 49705 50018 50046 50090 50162 50358 50574 50608 50693 50718 50722 50907 51095 51106 51125 51139 51318 51347 51372 51433 51502 51781 51805 51835 51855 52012 52037 52045 52104 52207 52476 52571 52927 52960 53003 53064 53186 53192 53266 53296 53386 53458 53647 53703 53733 53939 54140 54186 54227 54266 54321 54349 54356 54421 54428 54475 54553 54588 54619 54672 54699 54787 54822 54897 55094 55131 55296 55617 55657 55718 55787 55952 56233 56257 56311 56324 56442 56567 56576 56581 56593 56621 56667 56774 56858 56937 57177 57566 57589 57601 57606 58022 58201 58226 58300 58383 58392 58402 58432 58436 58540 58903 58986 59002 59071 59104 59338 59496 59576 59598 59619 59948 59956 59963 59967 60002 60084 60230 60536 60585 60811 60899 60926 61020 61146 61281 61294 61407 61519 61693 61715 61772 61781 61857 61975 62055 62064 62078 62086 62111 62260 62553 62602 62608 62626 62728 62827 62967 62979 63235 63302 63526 63928 63969 64233 64237 64284 64418 64483 64726 64748 65118 65199 65214 65269 65282 65369 65479 65577 65751 65798 65832 65948 66014 66197 66328 66483 66506 66708 66844 66881 66890 66951 66962 66972 67025 67078 67108 67146 67242 67360 67376 67397 67448 67575 67611 67639 67725 67746 67771 67829 68038 68180 68313 68315 68326 68380 68422 68448 68515 68600 68675 68823 68834 69022 69062 69267 69499 69622 69640 69843 69883 69926 69945 69961 69972 70184 70193 70221 70244 70380 70399 70438 70515 70551 70574 70718 70908 71098 71333 71347 71390 71401 71427 71442 71599 71611 71669 71728 71926 72072 72191 72204 72254 72289 72531 72564 72629 72638 72704 72775 72794 72819 73015 73052 73056 73107 73159 73293 73492 73611 73763 73849 73900 73912 73969 73973 73979 73986 74055 74115 74121 74181 74201 74247 74402 74415 74419 74430 74434 74656 74720 74777 74957 74970 74989 75012 75036 75040 75079 75163 75301 75401 75569 75574 75673 75690 75884 76120 76357 76443 76499 76609 76629 76675 76721 76850 76917 76941 77090 77171 77173 77253 77284 77333 77460 77479 77496 77576 77591 77604 77713 77952 78091 78162 78235 78319 78373 78383 78451 78459 78464 78487 78524 78545 78559 78588 78597 78854 78872 78981 79019 79075 79080 79170 79265 79383 79432 79474 79541 79547 79599 79604 79669 79736 79780 79970 80121 80132 80235 80410 80438 80451 80516 80579 80656 80678 80760 80768 80796 80807 80824 80840 80857 80923 80989 81047 81059 81074 81117 81174 81177 81181 81200 81213 81229 81271 81308 81454 81462 81470 81632 81732 81735 81766 81802 81837 82022 82058 82070 82085 82116 82194 82215 82287 82359 82363 82396 82464 82485 82667 82772 82920 82934 83007 83079 83322 83409 83486 83526 83612 83720 83826 83941 84065 84082 84318 84324 84408 84412 84521 84594 84845 84848 84862 84880 84929 84936 84999 85125 85131 85140 85227 85325 85431 85435 85471 85485 85553 85563 85645 85683 85767 85785 85803 85904 86045 86094 86152 86218 86235 86275 86306 86322 86342 86353 86413 86489 86774 86818 86861 86955 86973 86988 87071 87080 87121 87237 87253 87270 87481 87753 87815 88012 88043 88098 88157 88453 88509 88859 89019 89052 89134 89211 89217 89272 89481 89492 89687 89971 89987 90024 90030 90051 90106 90228 90280 90291 90305 90347 90392 90407 90424 90491 90541 90557 90593 90630 90668 90692 90713 90726 90731 90744 90767 90775 90874 90894 91026 91110 91289 91351 91366 91378 91632 91687 91854 91871 92029 92053 92213 92308 92474 92556 92666 92678 92721 92774 92797 92865 92880 92945 93207 93281 93503 93515 93628 93705 93710 93813 93821 94114 94390 94619 94626 94804 94914 94967 94990 95097 95211 95253 95457 95573 95598 95735 95776 95830 95889 95946 96016 96082 96109 96132 96304 96481 96503 96541 96682 96849 96934 96938 97173 97194 97201 97217 97358 97387 97437 97445 97520 97568 97585 97709 97891 97951 98065 98129 98216 98259 98293 98369 98399 98421 98589 98670 98816 98833 98840 98878 98928 98959 98992 99029 99039 99058 99077 99081 99118 99359 99398 99424 99433 99447 99457 99604 99629 99632 99639 99653 100002 100047 100227 100308 100419 100489 100523 100557 100711 101122 101218 101367 101577 101616 101688 101844 101871 101895 102038 102093 102182 102254 102262 102342 102419 102615 102636 102686 102805 102905 102951 103050 103096 103272 103552 103751 103947 104017 104043 104341 104375 104441 104452 104546 104666 104738 104819 104876 104880 104947 105252 105275 105794 105903 105915 105971 106013 106070 106235 106243 106281 106290 106485 106496 106517 106561 106565 106732 106842 106900 106920 107069 107173 107231 107560 107618 107650 107657 107680 107731 107776 107786 107985 108137 108183 108195 108256 108275 108304 108414 108451 108468 108485 108590 108700 108822 108981 109108 109136 109226 109306 109326 109560 109591 109665 109881 109887 109930 109966 110045 110077 110141 110147 110151 110283 110378 110465 110637 110681 110718 110781 110916 110953 110960 110962 110973 111265 111280 111423 111429 111456 111518 111618 111673 111687 111757 111822 111900 112113 112506 112616 112887 112898 112952 113016 113033 113058 113097 113337 113406 113608 113654 113760 113846 113979 113986 114168 114212 114274 114389 114412 114449 114453 114546 114711 114963 115043 115079 115122 115148 115263 115349 115501 115535 115711 115899 116004 116028 116062 116188 116235 116275 116288 116364 116379 116478 116570 116590 116755 116821 116925 116937 116945 117042 117086 117103 117122 117134 117194 117241 117245 117261 117269 117313 117397 117416 117442 117480 117502 117674 117719 117748 117787 117806 117812 117821 117880 118052 118122 118127 118174 118286 118352 118394 118422 118581 118685 118751 118852 119000 119032 119078 119084 119196 119240 119444 119469 119590 119689 119714 119985 120070 120170 120175 120339 120386 120442 120522 120631 120658 120727 120940 121010 121170 121195 121322 121346 121365 121390 121509 121681 121731 121976 122077 122096 122138 122183 122211 122229 122266 122399 122757 123147 123258 123301 123305 123313 123521 123796 123884 123894 123941 124031 124103 124185 124204 124236 124257 124491 124638 124679 124709 124866 124869 124927 124950 125006 125087 125176 125349 125373 125417 125501 125699 125712 125776 125895 125996 126081 126193 126400 126533 126615 126671 126675 126745 126760 126773 126856 126877 126954 127008 127116 127168 127228 127241 127354 127516 127572 127964 128013 128263 128326 128616 128704 128708 128712 128800 128955 128980 129013 129037 129117 129269 129416 129650 129716 129731 129739 129811 129965 129987 130327 130365 130397 130403 130417 130533 130572 130661 130711 130871 130880 130921 130947 131006 131022 131064 131191 131212 131224 131264 131274 131277 131553 131573 131701 131791 131898 131908 131936 131951 132035 132173 132220 132297 132538 132603 132629 132700 132736 132807 132952 132998 133273 133295 133312 133402 133505 133544 133575 133585 133591 133601 133633 133669 133684 133703 133823 133840 133887 133963 133970 133977 134455 134498 134510 134737 134828 135015 135061 135091 135167 135186 135237 135404 135452 135518 135533 135546 135578 135656 135744 135762 136161 136187 136385 136388 136411 136448 136473 136679 136689 136728 136857 137024 137128 137151 137163 137172 137356 137382 137516 137602 137646 137665 137675 137834 137890 138029 138037 138042 138155 138163 138183 138267 138271 138313 138378 138472 138487 138568 138572 138653 138660 138812 138870 138901 138927 138970 139130 139190 139198 139357 139594 139621 139684 139688 139731 139761 139815 139823 139875 140016 140137 140142 140292 140333 140515 140743 140747 140794 140813 140825 140915 141056 141204 141347 141455 141475 141623 141655 141661 141789 141801 141987 142067 142077 142168 142270 142337 142422 142491 142521 142672 142686 142864 142931 142944 142961 142972 142979 143241 143282 143443 143507 143633 143666 143708 143719 143791 143953 143972 144124 144383 144460 144482 144495 144663 144719 144944 144969 145001 145049 145129 145334 145374 145378 145461 145473 145479 145498 145508 145533 145679 145765 145882 145964 145981 146475 146604 146652 146687 146700 146720 146777 146785 146992 147055 147295 147402 147441 147524 147564 147606 147727 147768 147788 147833 147977 148003 148049 148078 148107 148172 148332 148499 148610 148830 149405]
[withdraw|44549 47161 64273 64468 109018]
[withdrawal|14386 59142 103964]
[withdrawing|6584]
[withdrawn|5410 11717 41348 65197 67333 72793 77632 79088 118045 124694]
[withdrew|39566 65039 131166]
[withered|2846 24296 24634 33549 54023 64965 72615 78673 115013 148220 148271]
[within|6939 10192 10359 27217 28319 30842 31363 46088 47153 64679 84214 95190 101238 103287 103656 107278 117809 125789 127738 144635]
[withou|1624 64297]
[without|951 1570 1596 4181 4499 4519 4743 4920 6485 6883 8900 9320 9882 10614 10626 10704 10753 12167 12994 13346 13616 13816 14165 14567 14894 15012 16228 18933 18989 19307 19424 20294 20460 20722 20756 20789 20795 20902 21281 21862 21866 22016 22631 23144 24361 24677 24695 25332 26484 27795 28940 29827 29889 30178 30277 30487 33234 34857 35257 35759 36504 36972 37125 37622 38257 40812 42029 42167 43153 43270 44173 45383 47871 48529 49895 51543 54446 55091 55118 55292 55411 58297 58440 58564 58586 60203 60908 61621 62210 62951 63015 63138 63141 63308 63368 63666 63955 65555 66787 67174 68140 70820 70920 72426 72445 72696 72959 73363 74396 74449 75292 76801 77073 77887 79247 79501 79615 80746 81362 81582 81820 82305 82314 82908 83444 84634 85193 88181 88310 88535 89302 89341 89771 89952 90832 90970 91463 91725 92253 92437 92888 93077 93447 94544 94693 94871 94875 94905 95438 95485 96458 96644 96661 97148 99762 99923 100081 100185 100496 101789 102789 103165 104010 104012 104014 104068 104591 104594 104597 104784 105348 105985 106080 106506 106621 107387 108338 108844 109506 110216 111126 111791 111921 112205 112993 113159 114778 117015 117729 118904 119396 120011 120801 121436 124101 124324 125844 126807 126810 126922 126997 127037 127345 127394 128076 128254 128482 128485 130657 130774 131252 131485 133396 133867 135039 137585 137822 138677 139141 139661 139879 139881 140441 140702 141293 142175 142525 142568 142677 143673 145948 146240 147928 148908 149065]
[witness|12015 21870 30146 30295 40723 107090 107264 107812]
[witnessed|122386]
[witnessing|6190 11822 65696]
[wits|119745]
[wives|3756 8252 37263 81157 85168 115814]
[wizard|44882]
[wo|10850 32186 70203 117172 132482]
[woke|4334 12282 24585 25458 31566 32938 34323 39808 46171 51819 59794 88852 111145 112838 118200 123132 123214 124267 125772 134480]
[wom|42569 67346 135141]
[woman|842 885 919 3212 3876 7215 9051 9098 9226 9406 9652 9796 9954 10336 11805 11977 12181 12225 12673 12857 13544 14409 15769 15949 16384 16408 17563 18545 18744 19863 22796 22806 25640 27133 27209 27594 27937 31078 33149 33176 33717 34562 34859 37080 37228 40971 41251 42004 42108 43042 45272 45929 54185 54347 54414 54694 55286 63114 65149 65997 67441 67574 67654 67716 67770 68468 68551 69648 72164 73032 73435 73640 74486 74986 78132 78364 78538 79682 82605 83450 84086 84342 85473 85524 85769 85782 89011 91489 94586 94625 94701 95746 98046 99035 99625 100178 101358 101870 102773 103674 104211 105714 108819 109072 109107 109558 109609 109843 109861 110076 110125 110280 110411 122532 123131 123829 124100 128146 130391 130413 135743 137945 138162 141755 142497 147875 148044 148077 149102 149224 149272]
[womanless|19549]
[womb|5418 71173 88914 89220 128208]
[wombs|88940]
[women|4803 5902 13302 24226 24287 24295 24355 26928 32964 33095 33238 35561 37428 39117 42675 51856 55133 57309 59187 62437 66952 67961 70397 70659 72553 74497 80470 81397 82283 84671 88746 94732 97008 105227 105319 107659 108672 116807 123102 123457 126003 132585 132596 137895]
[won|658 7529 19742 27383 30897 35452 35465 36254 38240 38653 42881 45101 46283 46354 47364 55852 56340 61125 63372 64861 66770 79304 88793 90352 120784 143863 144656]
[wonder|501 4594 10475 81097]
[wondered|10802 62908 65397 68956 74912 89743 112704 121376]
[wonderful|2328 47197 111483]
[wondering|9846 64098]
[wonderment|127774]
[wonders|3558 5714]
[wondrous|14079]
[wood|14084 14250 50469 86102 119550]
[wooden|14185 21891 22248 22912 24222 29522 35267 47397 53187 67080 69500 74582 78326 80449 81115 81633 85228 95373 105507 109830 118453 142974]
[woods|4016 108413]
[woodsman|123378]
[wool|32198 143318]
[woolen|60360 75345 94309]
[word|9323 21467 21471 26254 30854 30973 36596 37334 41983 63311 76701 76828 76863 76865 79405 80174 87229 96664 101792 106085 111129 114638 124416 131696 143354]
[words|5182 15655 17393 18295 23396 24366 33084 49956 57446 58174 84067 84391 88198 89865 99967 108930 109104 111981 115705 116031 127230 142130]
[wore|2126 14906 14940 17565 19907 22047 32648 34462 40194 53057 56590 69965 83803 94321 100652 131017 133255 138779 143316]
[work|660 3096 3199 3622 7052 12929 14038 15640 16996 18421 18497 19542 19955 21816 22565 23585 23812 25230 25843 27037 27754 28078 29144 30681 30824 34389 34626 34864 38621 39578 41257 42833 51128 68689 71607 71634 71715 77698 78819 79042 79169 79315 85089 90233 93421 95385 99800 99832 100062 100175 101972 106324 118090 121323 128135 128541 136262]
[workbench|94137 111275 111386 138531]
[worke|116640]
[worked|29 739 16537 21644 31876 68671 94867 95039 99453 102329 103526 104954 112474 125852]
[workers|80182 105288 106157 106199 107309 107485 107570 107629 107792 107835 107888 107944 107975 108401 108526 108671 110660 110720 110894 115781 124925 124965 140101 140128 146760]
[working|3376 21938 22292 23649 25616 27974 41058 52606 54216 83834 90145 93607 107331 108420 128397]
[workings|2951]
[workmen|20314 69225]
[works|71342 144676]
[workshop|18424 25998 26088 27322 27915 28424 28500 28656 28819 31680 31881 32540 36841 37563 60992 68624 68714 71557 71959 75980 77041 77131 77228 81868 85331 92264 93458 93604 94002 94084 94504 94803 94893 95204 95409 95518 100655 104761 104797 111256 111334 140245]
[workshops|13681]
[workta|133126]
[worktable|12992 111686]
[worl|125189]
[world|413 950 1995 3010 3561 4129 5097 5717 6473 7082 8519 9558 11392 11730 17526 17819 18100 18734 19927 20426 23229 24281 29207 29932 32829 33224 34593 35811 38456 39828 40742 57014 58206 59349 62571 63021 64872 66103 66323 66371 67343 70858 71147 71352 72786 73441 73534 74604 77732 78419 79119 79388 80677 81132 82273 82747 84165 84309 89379 91179 92776 98746 99874 100233 100918 101237 106488 109621 116217 118349 118696 120218 121382 121446 121962 123762 124760 125111 129802 130786 132451 132771 134072 134200 134721 135729 135777 139756 139828 140217 140395 141800 142083 142971 143515 144274 145681 145855 146991 147102 148328 148717 148847 149105]
[worldly|81738]
[worm|78324]
[wormhole|78638]
[worms|10906 33455 64113 99446 122252 136873]
[wormseed|10918]
[wormy|99139 132353]
[worn|1970 14916 14946 19465 25388 28414 29684 32701 44663 61046 70411 73112 76375 113674 121632 128857 130584 131831 132022 133486 135228]
[worried|17005 25418 32433 34937 56184 68791 114498]
[worries|11611 57679 57713 68451]
[worry|22066 38762 45622 54930 59216 61315 72741 73020 84143 92577 100320 129922 131848 133081 142299 147816]
[worrying|5155 43155 84283]
[worse|70664 116076 116129 116397 138409]
[worship|145432]
[worst|28329 81793 112759 130607]
[worth|26947 57756 59647 79101 84072 101035 139473 146262]
[worthy|14781 15138 67526 74973 143919]
[wou|44447 48893 72896 97895 113566 142823 145102]
[woul|50110 60014 132704]
[would|445 463 628 1190 1445 1492 1686 2184 2264 2324 2438 2558 2601 2996 3072 3462 3649 3794 4230 4254 4283 4946 5116 5399 6776 6893 6981 7115 7291 7336 7347 7398 7407 7418 8364 8715 8788 8818 8836 10275 10302 10673 10827 12130 13791 13873 13975 15154 15183 15213 15464 15896 16598 16658 16752 16872 16911 17292 17302 17396 17682 18234 18273 18335 18384 18633 18669 19501 19631 19665 20052 20195 20863 20884 21056 21274 21638 21815 22409 22954 22992 23004 23074 23130 23486 23511 23549 23867 23935 23965 24597 24764 24943 25131 25266 25271 25293 25359 25601 25904 25915 26091 26325 26440 26457 26509 27144 27164 27344 27392 27461 27885 27899 27911 28187 28191 28622 28721 28752 29280 29423 29465 29879 29947 29988 30079 30425 30562 30710 30773 30839 31063 31113 31459 31519 31530 31633 31719 31755 31761 31850 31884 31899 31908 32092 32292 32341 32363 32377 32414 32981 33001 33110 33465 33507 33538 34350 34547 34553 34789 35023 36072 36306 36455 36582 36592 36609 36689 36715 37864 37952 38057 38314 38432 38493 38517 38525 38558 38597 38638 38908 38920 38928 39056 39083 39102 39337 39464 39648 39678 39758 39773 39787 39791 39934 40318 40671 40712 40865 41108 41267 41279 41343 41359 41368 42180 42239 42324 43345 44065 44343 45238 45257 45494 45662 45756 45794 46224 46345 46485 46791 46808 46821 46885 47238 47259 48679 48709 48749 48793 49160 49417 49569 49773 49975 49986 50052 50070 50081 50093 50102 50601 50638 50750 50763 50777 50814 50822 50839 51345 51645 51664 51833 52041 52582 52598 52951 53020 53403 53641 53743 53785 53842 54068 54123 54210 54232 54818 54854 55046 55123 55337 55349 55360 55368 56004 56044 56783 57121 58015 58032 58114 58211 58264 58578 59062 59182 59201 59324 59336 59389 59463 59820 59894 61317 61555 61816 61895 62006 62692 63133 63238 63324 63428 64904 65092 65433 65756 66441 66735 66758 67423 67482 67579 67607 67826 67858 67929 67941 67951 68167 68203 68475 68587 68641 68953 68994 69312 69409 69768 70217 70264 70497 70776 70900 71084 71186 71375 71399 71525 71821 71828 71867 71929 71967 72013 72025 72891 73410 73423 73580 73908 73921 74064 74085 74109 74356 74730 74741 74837 74866 74922 75230 75349 75417 75427 75505 76445 77054 77204 77289 78783 78903 79127 79998 80024 80528 81226 81352 81639 81917 81969 82578 82944 82987 83018 83033 83071 83104 83262 83277 83389 83425 83680 83754 84185 84234 84302 84313 84381 84392 84423 84434 84437 84777 85165 85218 85298 85868 86369 86870 87023 87141 87331 87460 87557 87750 87979 88006 88386 88442 88815 88877 89239 89938 90580 90588 90817 90836 90925 90944 91144 91438 91659 92041 92049 92188 92208 92409 92589 92624 92640 92780 92948 92969 93260 93682 93735 93774 93878 93968 94031 94088 94129 94291 94857 95169 95507 96241 96270 96343 96631 96832 96855 96926 97404 97547 97659 97691 97766 97826 97838 97868 97907 97917 98105 98290 98389 99003 99026 99036 99114 99203 99256 99304 99316 99419 99438 99472 99492 99826 100070 100396 100541 100609 100724 100816 100909 101212 101442 101552 101664 101850 101876 102009 102015 102200 102567 102609 102746 102976 102983 103316 103445 103731 103741 104039 104125 104194 104232 104352 104368 104384 104630 104782 104990 105046 105068 106046 106975 107153 107391 107432 107462 107474 107528 107885 108543 108768 108849 108875 109347 109848 110031 111605 112047 112088 112541 112557 112773 112798 112996 113263 113414 113427 113525 113577 113767 113802 113841 113886 113918 113970 114023 114623 115368 117157 117478 117500 117532 117618 117680 117754 117768 117833 117895 118479 118975 118987 119016 119661 119884 120349 120363 120645 120764 120778 121005 121045 121065 121074 121280 121659 121705 122013 122337 122537 122547 122754 122819 123878 123995 124513 124707 124729 125113 125413 125460 125957 125986 126140 126164 126352 126541 126652 126688 126705 126838 127090 127177 127371 127377 127387 127653 127666 127732 127929 128298 128655 129155 129165 129188 129293 129317 129347 129383 129390 129395 129412 129637 129990 130024 130123 130166 130321 130332 130482 131327 131458 131691 131880 131888 131914 131932 131955 132053 132062 132084 132096 132106 132287 132396 132422 132461 132503 132526 132590 132633 132732 132743 132753 132772 132789 132800 132817 132950 132982 133142 133280 133319 133389 133872 134138 134770 134793 134814 135148 135449 135619 135747 135936 136011 136017 136119 136158 136194 136279 136299 136318 136398 136587 136613 136698 136713 136738 137018 137061 137088 137340 137697 137753 138125 138144 138257 138286 138330 138714 138726 138819 138951 139448 139659 139702 139725 139793 140122 140147 140230 140248 140683 140731 140892 140986 141244 141425 141683 141960 142277 143032 143118 143580 143596 143817 144381 145073 145229 145418 145426 145454 145477 145491 145513 145578 146317 146323 146896 146909 146963 147078 147082 147088 147446 147464 147972 148371 149226 149360 149481 149498 149519]
[wouldn|35524 39587]
[wound|37578 48090 110190 110196]
[wounded|43895 53857 55462 72470 72603 97298 125504 141390 141527]
[wounds|87185 123295]
[wove|73605 92545 116174]
[woven|132034 144123]
[wr|126082 140661]
[wrap|63205 89552 106904 110172]
[wrapped|6203 10380 12411 14519 26530 31378 44454 49074 54753 58991 60357 61970 64226 73346 77455 94306 96754 98858 101130 101519 105776 109875 117236 117447 127072 133711 142346]
[wrappings|31331]
[wrath|1710 119198 149389]
[wrathful|140020]
[wreaked|61884]
[wreath|114305 127222 127248 127963]
[wreaths|29230 73607 73998 74080 74391 74463 86155 116176 138046]
[wrestle|7419 32983]
[wretch|116290]
[wretches|85213]
[wrinkled|24630 52649 78407]
[wrist|14954 32605 40684 78548]
[wrists|28952 32400 39915]
[writ|49199]
[write|139 5703 20024 20641 23936 27332 40311 41931 44821 50345 65035 70926 73960 74716 92410 100296 103261 125074 129373 139021 141035 142406 147196]
[writers|143281]
[writes|62803]
[writing|17697 24955 26343 39768 42206 48478 56386 66169 93284 119089 128733 129548 129749 131581 131655 143183 145773]
[written|53 14703 17407 17450 18004 23380 23408 45045 77381 85916 126622 127625 129408 129418 133998 134213 139391 143353 143782 148856 148917 148944 148963 149528]
[wrong|12643 16129 29426 55825 127281 135683]
[wrote|17085 22279 25314 26820 29706 33160 63998 65731 76306 100303 106665 129687 130017 144026 145907 146044]
[wrought|50724]
[wrung|139908]
[ws|26906]
[wterware|79260]
[xcitement|145064]
[xclaimed|52670]
[ximity|4473]
[xpected|98653]
[xplained|36276]
[y|1233 2333 14022 14063 16497 17399 23711 27382 29601 34834 37345 43898 45620 47029 49524 56841 64705 67495 72933 83235 88951 90978 93156 93795 94771 98837 103256 105041 105927 107988 116602 122886 125593 127682 132265 139123 140374 142578 144522 148450]
[yams|1618 91292]
[yard|20240 41293 41491 41700 85278 89613 106602 144741]
[yards|45469]
[yawn|31120]
[year|434 7459 13378 27219 32252 42365 47461 52261 54562 55754 61172 61194 63890 65154 74815 76075 76448 82137 85390 88514 89316 92649 92814 96065 105606 107164 113066 113434 117296 118955 123035 123479 124017 125411 132890 135456 136044 137710 144512]
[yearned|8079 89831 102412 130599]
[yearning|28296 35903 113197 143061]
[years|1361 2903 3365 3399 4000 4535 5402 5812 6942 6987 7165 7248 8477 10199 11996 13568 14149 14177 14612 18386 18574 19297 19373 19913 20073 24258 28292 29285 29888 30780 30844 30905 32215 35724 35778 35940 37601 37651 42827 47565 48308 49619 52410 52456 52519 52643 53367 54604 54784 58570 58754 60561 61042 61387 61834 62233 62849 63073 65057 65735 65921 66081 66211 66308 66352 66763 67901 68139 69249 69419 69713 70308 71080 71423 71701 72357 73550 73552 73674 73709 73955 74274 75750 76025 77417 78082 78220 78932 85348 86572 87155 87393 87544 87701 87859 89392 89603 90196 92485 92583 94243 95162 95430 96364 99010 99199 99592 99804 99902 100829 100979 101290 104845 108871 109343 111848 112368 115102 117902 118376 118477 119337 121598 121778 122391 124094 124162 125103 125192 125472 125925 127674 127740 128954 129050 129858 129926 130053 130679 131101 132637 134264 134711 136353 136523 136779 137142 137984 139058 139610 139677 141884 143331 144734 145660 146691 148957 149545]
[yed|38150]
[yell|79858]
[yellow|16488 26056 27423 51048 67772 70517 70818 73571 74520 78376 80980 102039 102832 104350 104609 105137 105296 105654 105948 123843 128606 131909 133419 149257]
[yellowed|130419 133215]
[yellowish|10531 62739 134016]
[yes|15051 16655 16668 20659 48846 137953]
[yesterday|28460 28522]
[yet|37645 55677 81235 84155 90966 101662 115581 131179 138410 145369]
[yielded|9611]
[ying|125520]
[yo|21376 90716]
[yoke|41223]
[yoked|51583]
[you|1731 5058 5152 7617 7765 7787 8024 8030 10547 10641 10712 10720 11398 12250 12253 13105 19195 19202 19205 20640 20729 20915 20925 20936 20950 20960 21000 21059 21068 21383 21454 21491 21494 24515 24873 25198 27087 27097 28045 28055 28059 30902 30941 33503 33862 34158 34193 34202 34914 35441 35511 35517 35523 37703 38079 38200 38223 38615 38662 38848 39590 39630 39962 40482 40489 40716 40762 40790 44497 44572 44602 44958 45084 45122 45612 49261 49284 49341 49359 49729 50206 50213 50219 50245 51717 51740 52144 53524 53780 53783 54088 54942 56193 56339 57129 57147 57230 57243 57270 57376 57381 57416 57430 57515 57523 57626 57652 57741 57788 57803 57847 57850 57857 57897 60539 60748 60827 60849 60862 60882 60889 60893 60898 60922 61088 61118 62184 62668 62811 63221 63225 63275 63284 63287 64368 66394 67054 67063 67162 68495 68508 68864 69205 72038 72929 73746 75473 77057 77067 77911 83202 83359 83363 84182 84208 84378 84698 86726 87369 87377 87384 88469 88483 89251 91796 96902 98426 101362 103437 103481 103487 103492 109013 110512 115298 115592 115782 119147 119950 119954 120023 122124 126036 131773 132498 142312 143739 146803]
[young|5899 8234 10764 11788 21690 21784 27591 31089 36003 38734 59671 59855 63985 65001 65073 66298 67345 67768 70950 82856 92821 97937 98159 101842 111419 111816 123284 126417 128844]
[younger|19968 21536 24537 26953 39237 40624 100400 139678]
[youngest|77827]
[your|1750 5149 5157 7577 20954 21397 21473 25618 27066 27519 27850 28057 28061 30757 34092 37337 37343 37688 39622 39982 44321 48935 48969 51208 51719 53750 53762 55345 55565 57384 57426 57683 57816 59411 59456 60591 60687 60743 61136 62901 63034 63291 66407 68217 68471 68519 70649 73679 74221 78437 82469 82480 83365 83382 85779 86675 87119 87132 88474 98360 98434 100343 102984 109176 110301 127138 131295 140509]
[yours|7574]
[yourself|1741 60716 83521 127098 146681]
[youth|2921 3746 36045 58244 63107 63804 67314 76995 77193 85518 86510 95665 113127 135341]
[youthful|2816 3069 50131 64930 121544 135611 147044]
[ypsies|5874 6124 33530 81264]
[ys|22385 115654 130121]
[zinc|14188 81118 101908 113076 119316 138844]
[zither|34034 34061 39802 39821]
[zoological|141594]
[zzing|144187]



---------------------------------------------------
---------------------------------------------------
Indices of "ice"
ice: 373 6480 6521 8771 8795 8854 11202 11229 19750 46620 54408 60984 77968 78654 79326 79603 92667 95689 96960 109063 117376 136912



---------------------------------------------------
listing indices from "ask" to "asker"
---------------------------------------------------
[ask|4970 6197 11011 11121 24542 25401 34164 45574 57856 69443 93124 100337 114357 116002 116661 117534 119596 124426 129139 131153 146058]
[asked|3639 6121 8671 9463 10539 12259 12556 14656 15029 16125 16638 16664 16695 16726 16758 19048 20319 20645 20668 23270 23683 24772 25473 28343 28426 28596 28849 30615 32911 33595 34615 35645 36638 37119 37172 43429 44316 45281 45551 48923 49014 49249 50966 51303 51724 53559 53983 56196 56200 59041 60260 60374 60396 60418 62949 63982 64988 65664 65710 66065 66398 66943 66989 67037 69289 72041 74458 74481 78044 80784 82129 84669 84702 86714 89769 89906 90295 92445 94552 94646 96889 99194 99685 100862 100965 101634 103126 104497 107073 108840 110758 111309 111747 112164 112855 114461 115306 115598 116611 118080 119769 122101 123485 126598 127080 127777 128913 134300 137195 138618 141459 146664]



========== E N D  ====================
Press <RETURN> to close this window...

 */


// MISCELLANEOUS & ADDITIONAL

// SHUNTING YARD ALGORITHM FOR: &&, ||, = and ()
/*



================================
H->[Dept]->[CS]->[=]->[Last]->[Olajuwon]->[=]->[&&]->|||

H->[Dept]->[CS]->[=]->[Age]->[22]->[=]->[||]->[State]->[Ohio]->[=]->[&&]->[Last]->[Olajuwon]->[=]->[||]->[First]->[John]->[=]->[&&]->|||

H->[Dept]->[Math]->[=]->[Dept]->[CS]->[=]->[||]->[Age]->[17]->[=]->[Age]->[35]->[=]->[||]->[&&]->[State]->[Ohio]->[=]->[&&]->[State]->[Calfornia]->[=]->[||]->[Age]->[5]->[=]->[First]->[Anna]->[=]->[||]->[Last]->[Ku]->[=]->[&&]->[&&]->|||




================================
Press <RETURN> to close this window...

 */

#endif // Z_OUTPUT_H
