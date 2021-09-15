CREATE TABLE DEPT (
DEPTNO NUMBER(4) NOT NULL,
DNAME VARCHAR2(20),
LOC VARCHAR2(20),
INFO VARCHAR2(40),
PRIMARY KEY (DEPTNO)
);


INSERT INTO DEPT (DEPTNO, DNAME, LOC, INFO) VALUES
(10, 'ACCOUNTING', 'NEW YORK', NULL);
INSERT INTO DEPT (DEPTNO, DNAME, LOC, INFO) VALUES
(20, 'RESEARCH', 'DALLAS', NULL);
INSERT INTO DEPT (DEPTNO, DNAME, LOC, INFO) VALUES
(30, 'SALES', 'CHICAGO', NULL); 
INSERT INTO DEPT (DEPTNO, DNAME, LOC, INFO) VALUES
(40, 'OPERATIONS', 'BOSTON', NULL);


CREATE TABLE EMP (
empno NUMBER(6) NOT NULL,
ename VARCHAR2(20),
job VARCHAR2(20),
mgr NUMBER(6),
hiredate date,
sal NUMBER(7,2),
comm NUMBER(7,2),
deptno NUMBER(4) REFERENCES DEPT(DEPTNO),
PRIMARY KEY (empno));


INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno) VALUES (7369, 'SMITH', 'CLERK', 7902, TO_DATE('1980-12-17','YYYY-MM-DD'), 800.00, NULL, 20);
INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno) VALUES (7499, 'ALLEN', 'SALESMAN', 7698, TO_DATE('1981-02-20','YYYY-MM-DD'), 1600.00, 300.00, 30);
INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno) VALUES (7521, 'WARD', 'SALESMAN', 7698, TO_DATE('1981-02-22','YYYY-MM-DD'), 1250.00, 500.00, 30);
INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno) VALUES (7566, 'JONES', 'MANAGER', 7839, TO_DATE('1981-04-02','YYYY-MM-DD'), 2975.00, NULL, 20);
INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno) VALUES (7654, 'MARTIN', 'SALESMAN', 7698, TO_DATE('1981-09-28','YYYY-MM-DD'), 1250.00, 1400.00, 30);
INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno) VALUES (7698, 'BLAKE', 'MANAGER', 7839, TO_DATE('1981-05-01','YYYY-MM-DD'), 2850.00, NULL, 30);
INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno) VALUES (7782, 'CLARK', 'MANAGER', 7839, TO_DATE('1981-06-09','YYYY-MM-DD'), 2450.00, NULL, 10);
INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno) VALUES (7788, 'SCOTT', 'ANALYST', 7566, TO_DATE('1982-09-12','YYYY-MM-DD'), 3000.00, NULL, 20);
INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno) VALUES (7839, 'KING', 'PRESIDENT', NULL, TO_DATE('1981-11-17','YYYY-MM-DD'), 5000.00, NULL, 10);
INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno) VALUES (7844, 'TURNER', 'SALESMAN', 7698, TO_DATE('1981-09-08','YYYY-MM-DD'), 1500.00, 0.00, 30);
INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno) VALUES (7876, 'ADAMS', 'CLERK', 7788, TO_DATE('1983-01-12','YYYY-MM-DD'), 1100.00, NULL, 20);
INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno) VALUES  (7900, 'JAMES', 'CLERK', 7698, TO_DATE('1981-03-12','YYYY-MM-DD'), 950.00, NULL, 30);
INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno) VALUES  (7902, 'FORD', 'ANALYST', 7566, TO_DATE('1981-03-12','YYYY-MM-DD'), 3000.00, NULL, 20);
INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno) VALUES  (7934, 'MILLER', 'CLERK', 7782, TO_DATE('1982-01-23','YYYY-MM-DD'), 1300.00, NULL, 10);