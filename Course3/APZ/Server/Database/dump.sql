--
-- PostgreSQL database dump
--

-- Dumped from database version 12.1
-- Dumped by pg_dump version 12.1

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

DROP DATABASE "apz-db";
--
-- Name: apz-db; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE "apz-db" WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'C' LC_CTYPE = 'C';


ALTER DATABASE "apz-db" OWNER TO postgres;

\connect -reuse-previous=on "dbname='apz-db'"

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: apz-db; Type: DATABASE PROPERTIES; Schema: -; Owner: postgres
--

ALTER ROLE "apz-server" IN DATABASE "apz-db" SET client_encoding TO 'UTF8';
ALTER ROLE postgres IN DATABASE "apz-db" SET client_encoding TO 'UTF8';


\connect -reuse-previous=on "dbname='apz-db'"

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: category_data; Type: TYPE; Schema: public; Owner: postgres
--

CREATE TYPE public.category_data AS (
	"ID" integer,
	"NAME" text,
	"TMIN" real,
	"TMAX" real,
	"HMIN" integer,
	"HMAX" integer,
	"SPACE" integer
);


ALTER TYPE public.category_data OWNER TO postgres;

--
-- Name: user_data; Type: TYPE; Schema: public; Owner: postgres
--

CREATE TYPE public.user_data AS (
	user_id integer,
	user_login text,
	user_email text,
	user_name text,
	role_id integer
);


ALTER TYPE public.user_data OWNER TO postgres;

--
-- Name: warehouse_data; Type: TYPE; Schema: public; Owner: postgres
--

CREATE TYPE public.warehouse_data AS (
	"ID" integer,
	"ADDRESS" text,
	"TEMPO" real,
	"HUMIDITY" integer,
	"SPACE_BUSY" integer,
	"SPACE_FREE" integer,
	"COST" integer,
	"IP" text
);


ALTER TYPE public.warehouse_data OWNER TO postgres;

--
-- Name: AUTHORIZE_USER(text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."AUTHORIZE_USER"("LOGIN" text, "PASS" text) RETURNS text
    LANGUAGE sql STABLE PARALLEL SAFE
    AS $$SELECT "GENERATE_TOKEN"("user_login", "user_pass") FROM "users"
	WHERE "user_login" = "LOGIN"
	AND "user_pass" = MD5("PASS")
	AND "user_email_valid" = TRUE$$;


ALTER FUNCTION public."AUTHORIZE_USER"("LOGIN" text, "PASS" text) OWNER TO postgres;

--
-- Name: CALCULATE_BEST_WAREHOUSE(text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."CALCULATE_BEST_WAREHOUSE"("PRODUCT" text) RETURNS integer
    LANGUAGE sql
    AS $$SELECT COALESCE("warehouse_id", -1) FROM "warehouses" INNER JOIN "categories"
	ON "warehouse_temperature" >= "temp_min"
	AND "warehouse_temperature" <= "temp_max"
	AND "warehouse_humidity" >= "humidity_min"
	AND "warehouse_humidity" <= "humidity_max"
WHERE "category_id" = (SELECT "category_id" FROM "categories" WHERE "category_name" = "PRODUCT")
ORDER BY "warehouse_cost" ASC
LIMIT 1$$;


ALTER FUNCTION public."CALCULATE_BEST_WAREHOUSE"("PRODUCT" text) OWNER TO postgres;

--
-- Name: CHANGE_USER_EMAIL(text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."CHANGE_USER_EMAIL"("TOKEN" text, "EMAIL" text) RETURNS boolean
    LANGUAGE plpgsql
    AS $_$BEGIN
	IF "EMAIL" ~ '(^[.A-Za-z0-9]+@[A-Za-z0-9]+\.[A-Za-z]+$)'
	THEN
		UPDATE "users" SET "user_email" = "EMAIL"
			WHERE "user_id" = "GET_USER_BY_TOKEN"("TOKEN");
		RETURN TRUE;
	ELSE
		RETURN FALSE;
	END IF;
END$_$;


ALTER FUNCTION public."CHANGE_USER_EMAIL"("TOKEN" text, "EMAIL" text) OWNER TO postgres;

--
-- Name: CHANGE_USER_LOGIN(text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."CHANGE_USER_LOGIN"("TOKEN" text, "LOGIN" text) RETURNS boolean
    LANGUAGE plpgsql
    AS $_$BEGIN
	IF "LOGIN" ~ '(^[A-Za-z0-9]+$)'
	THEN
		UPDATE "users" SET "user_login" = "LOGIN"
			WHERE "user_id" = "GET_USER_BY_TOKEN"("TOKEN");
		RETURN TRUE;
	ELSE
		RETURN FALSE;
	END IF;
END$_$;


ALTER FUNCTION public."CHANGE_USER_LOGIN"("TOKEN" text, "LOGIN" text) OWNER TO postgres;

--
-- Name: CHANGE_USER_NAME(text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."CHANGE_USER_NAME"("TOKEN" text, "NAME" text) RETURNS boolean
    LANGUAGE plpgsql
    AS $_$BEGIN
	IF "NAME" ~ '(^[A-Za-zА-Яа-я]+ [A-Za-zА-Яа-я]+$)'
	THEN
		UPDATE "users" SET "user_name" = "NAME"
			WHERE "user_id" = "GET_USER_BY_TOKEN"("TOKEN");
		RETURN TRUE;
	ELSE
		RETURN FALSE;
	END IF;
END$_$;


ALTER FUNCTION public."CHANGE_USER_NAME"("TOKEN" text, "NAME" text) OWNER TO postgres;

--
-- Name: CHANGE_USER_PASS(text, text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."CHANGE_USER_PASS"("TOKEN" text, "PASS1" text, "PASS2" text) RETURNS boolean
    LANGUAGE plpgsql
    AS $$BEGIN
	IF "PASS1" = "PASS2"
	THEN
		UPDATE "users" SET "user_pass" = MD5("PASS1")
			WHERE "user_id" = "GET_USER_BY_TOKEN"("TOKEN");
		RETURN TRUE;
	ELSE
		RETURN FALSE;
	END IF;
END$$;


ALTER FUNCTION public."CHANGE_USER_PASS"("TOKEN" text, "PASS1" text, "PASS2" text) OWNER TO postgres;

--
-- Name: CONFIRM_EMAIL(text); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public."CONFIRM_EMAIL"("TOKEN" text)
    LANGUAGE sql
    AS $$UPDATE "users" SET "user_email_valid" = TRUE
	WHERE "TOKEN" = MD5(CONCAT("user_login", '>', "user_pass"))$$;


ALTER PROCEDURE public."CONFIRM_EMAIL"("TOKEN" text) OWNER TO postgres;

--
-- Name: DELETE_CATEGORY(integer); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public."DELETE_CATEGORY"("CAT_ID" integer)
    LANGUAGE sql
    AS $$DELETE FROM "categories" WHERE "category_id" = "CAT_ID"$$;


ALTER PROCEDURE public."DELETE_CATEGORY"("CAT_ID" integer) OWNER TO postgres;

--
-- Name: DELETE_WAREHOUSE(integer); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public."DELETE_WAREHOUSE"("WARE_ID" integer)
    LANGUAGE sql
    AS $$DELETE FROM "warehouses" WHERE "warehouse_id" = "WARE_ID"$$;


ALTER PROCEDURE public."DELETE_WAREHOUSE"("WARE_ID" integer) OWNER TO postgres;

--
-- Name: GENERATE_TOKEN(text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."GENERATE_TOKEN"("LOGIN" text, "PASS" text) RETURNS text
    LANGUAGE sql IMMUTABLE PARALLEL SAFE
    AS $$SELECT MD5(CONCAT("LOGIN", '|', MD5("PASS")))$$;


ALTER FUNCTION public."GENERATE_TOKEN"("LOGIN" text, "PASS" text) OWNER TO postgres;

--
-- Name: GET_FREE_SPACE(integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."GET_FREE_SPACE"("WARE_ID" integer) RETURNS integer
    LANGUAGE sql
    AS $$SELECT CAST
(
	"warehouse_space" -
	(SELECT COALESCE(SUM("?column?"), 0) FROM "storage_data" WHERE "warehouse_id" = "WARE_ID")
	AS integer
)
FROM
	"warehouses" WHERE "warehouse_id" = "WARE_ID"$$;


ALTER FUNCTION public."GET_FREE_SPACE"("WARE_ID" integer) OWNER TO postgres;

--
-- Name: GET_USER_BY_TOKEN(text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."GET_USER_BY_TOKEN"("TOKEN" text) RETURNS integer
    LANGUAGE sql STABLE PARALLEL SAFE
    AS $$SELECT "user_id" FROM "users"
	WHERE "TOKEN" = "GENERATE_TOKEN"("user_login", "user_pass")$$;


ALTER FUNCTION public."GET_USER_BY_TOKEN"("TOKEN" text) OWNER TO postgres;

--
-- Name: GET_USER_DATA(text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."GET_USER_DATA"("TOKEN" text) RETURNS public.user_data
    LANGUAGE sql STABLE PARALLEL SAFE
    AS $$SELECT "user_id", "user_login", "user_email", "user_name", "role_id" FROM "users"
	WHERE "TOKEN" = "GENERATE_TOKEN"("user_login", "user_pass")$$;


ALTER FUNCTION public."GET_USER_DATA"("TOKEN" text) OWNER TO postgres;

--
-- Name: LOAD_CATEGORIES(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."LOAD_CATEGORIES"() RETURNS SETOF public.category_data
    LANGUAGE sql STABLE PARALLEL SAFE
    AS $$SELECT "category_id", "category_name", "temp_min", "temp_max",
	"humidity_min", "humidity_max", "storage_space"
	FROM "categories"$$;


ALTER FUNCTION public."LOAD_CATEGORIES"() OWNER TO postgres;

--
-- Name: LOAD_WAREHOUSES(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."LOAD_WAREHOUSES"() RETURNS SETOF public.warehouse_data
    LANGUAGE sql STABLE PARALLEL SAFE
    AS $$SELECT "warehouse_id", "warehouse_address", "warehouse_temperature", "warehouse_humidity", "warehouse_space",
	"GET_FREE_SPACE"("warehouse_id"), "warehouse_cost", "warehouse_iot_ip"
	FROM "warehouses"$$;


ALTER FUNCTION public."LOAD_WAREHOUSES"() OWNER TO postgres;

--
-- Name: REGISTER_CATEGORY(text, real, real, integer, integer, integer); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public."REGISTER_CATEGORY"("NAME" text, "TMIN" real, "TMAX" real, "HMIN" integer, "HMAX" integer, "SPACE" integer)
    LANGUAGE sql
    AS $$INSERT INTO "categories" VALUES
	(DEFAULT, "NAME", "TMIN", "TMAX", "HMIN", "HMAX", "SPACE")$$;


ALTER PROCEDURE public."REGISTER_CATEGORY"("NAME" text, "TMIN" real, "TMAX" real, "HMIN" integer, "HMAX" integer, "SPACE" integer) OWNER TO postgres;

--
-- Name: REGISTER_USER(text, text, text, text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."REGISTER_USER"("LOGIN" text, "PASS1" text, "PASS2" text, "EMAIL" text, "NAME" text) RETURNS integer
    LANGUAGE plpgsql
    AS $$DECLARE
	"V_RESULT" INTEGER;
BEGIN
	"V_RESULT" := "VALIDATE_USER_DATA"
	(
		"LOGIN",
		"PASS1",
		"PASS2",
		"EMAIL",
		"NAME"
	);
	IF ("V_RESULT" = 0)
	THEN
		INSERT INTO "users" VALUES
		(
			DEFAULT,
			"LOGIN",
			MD5("PASS1"),
			"EMAIL",
			"NAME",
			NOW()
		);
	END IF;
	RETURN "V_RESULT";
END$$;


ALTER FUNCTION public."REGISTER_USER"("LOGIN" text, "PASS1" text, "PASS2" text, "EMAIL" text, "NAME" text) OWNER TO postgres;

--
-- Name: REGISTER_WAREHOUSE(text, integer, integer, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."REGISTER_WAREHOUSE"("ADDRESS" text, "SPACE" integer, "COST" integer, "IOT_IP" text) RETURNS integer
    LANGUAGE plpgsql
    AS $$BEGIN
	IF NOT "VALIDATE_IP"("IOT_IP") THEN RETURN 1; END IF;
	IF EXISTS
		(SELECT * FROM "warehouses" WHERE "warehouse_iot_ip" = "IOT_IP")
	THEN RETURN 2; END IF;
	INSERT INTO "warehouses"
	(
		"warehouse_address",
		"warehouse_space",
		"warehouse_cost",
		"warehouse_iot_ip"
	)
	VALUES
	(
		"ADDRESS",
		"SPACE",
		"COST",
		"IOT_IP"
	);
	RETURN 0;
END$$;


ALTER FUNCTION public."REGISTER_WAREHOUSE"("ADDRESS" text, "SPACE" integer, "COST" integer, "IOT_IP" text) OWNER TO postgres;

--
-- Name: REMOVE_PRODUCT(integer); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public."REMOVE_PRODUCT"("ID" integer)
    LANGUAGE sql
    AS $$UPDATE "products"
	SET "product_date_end" = NOW(), "is_active" = FALSE
	WHERE "product_id" = "ID"$$;


ALTER PROCEDURE public."REMOVE_PRODUCT"("ID" integer) OWNER TO postgres;

--
-- Name: SET_USER_ROLE(text, integer); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public."SET_USER_ROLE"("LOGIN" text, "ROLE_ID" integer)
    LANGUAGE sql
    AS $$UPDATE "users" SET "role_id"="ROLE_ID" WHERE "user_id" =
	(SELECT "user_id" FROM "users" WHERE "user_login" = "LOGIN")$$;


ALTER PROCEDURE public."SET_USER_ROLE"("LOGIN" text, "ROLE_ID" integer) OWNER TO postgres;

--
-- Name: STORE_PRODUCT(integer, text, text, integer); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public."STORE_PRODUCT"("WAREHOUSE_ID" integer, "PRODUCT_NAME" text, "USER_TOKEN" text, "COUNT" integer)
    LANGUAGE sql
    AS $$INSERT INTO "products" VALUES
(
	DEFAULT,
	"WAREHOUSE_ID",
	(SELECT "category_id" FROM "categories" WHERE "category_id" =
		(SELECT "category_id" FROM "categories" WHERE "category_name" = "PRODUCT_NAME")),
	(SELECT "GET_USER_BY_TOKEN"("USER_TOKEN")),
	"COUNT",
	NOW()
)$$;


ALTER PROCEDURE public."STORE_PRODUCT"("WAREHOUSE_ID" integer, "PRODUCT_NAME" text, "USER_TOKEN" text, "COUNT" integer) OWNER TO postgres;

--
-- Name: VALIDATE_IP(text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."VALIDATE_IP"("IP" text) RETURNS boolean
    LANGUAGE sql PARALLEL SAFE
    AS $_$SELECT "IP" ~ '(^[0-9]+.[0-9]+.[0-9]+.[0-9]+$)';$_$;


ALTER FUNCTION public."VALIDATE_IP"("IP" text) OWNER TO postgres;

--
-- Name: VALIDATE_USER_DATA(text, text, text, text, text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."VALIDATE_USER_DATA"("LOGIN" text, "PASS1" text, "PASS2" text, "EMAIL" text, "NAME" text) RETURNS integer
    LANGUAGE plpgsql PARALLEL SAFE
    AS $_$DECLARE
	"C_REGEX_LOGIN" CONSTANT TEXT := '(^[A-Za-z0-9]+$)';
	"C_REGEX_EMAIL" CONSTANT TEXT := '(^[.A-Za-z0-9]+@[A-Za-z0-9]+\.[A-Za-z]+$)';
	"C_REGEX_NAME" CONSTANT TEXT := '(^[A-Za-zА-Яа-я]+ [A-Za-zА-Яа-я]+$)';
BEGIN
	-- Check empty
	IF "PASS1" != "PASS2" THEN RETURN 1; END IF;

	-- Check regex
	IF "LOGIN" !~ "C_REGEX_LOGIN" THEN RETURN 2; END IF;
	IF "EMAIL" !~ "C_REGEX_EMAIL" THEN RETURN 3; END IF;
	IF "NAME" !~ "C_REGEX_NAME" THEN RETURN 4; END IF;

	-- Check unique
	IF NOT EXISTS (SELECT * FROM "users" WHERE "user_login" = "LOGIN") = FALSE THEN RETURN 5; END IF;
	IF NOT EXISTS (SELECT * FROM "users" WHERE "user_email" = "EMAIL") = FALSE THEN RETURN 6; END IF;

	RETURN 0;
END$_$;


ALTER FUNCTION public."VALIDATE_USER_DATA"("LOGIN" text, "PASS1" text, "PASS2" text, "EMAIL" text, "NAME" text) OWNER TO postgres;

--
-- Name: VALIDATE_USER_TOKEN(text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public."VALIDATE_USER_TOKEN"("TOKEN" text) RETURNS boolean
    LANGUAGE sql STABLE PARALLEL SAFE
    AS $$SELECT EXISTS (SELECT * FROM "users"
	WHERE "TOKEN" = "GENERATE_TOKEN"("user_login", "user_pass")
	AND "user_email_valid" = TRUE)$$;


ALTER FUNCTION public."VALIDATE_USER_TOKEN"("TOKEN" text) OWNER TO postgres;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: categories; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.categories (
    category_id integer NOT NULL,
    category_name text NOT NULL,
    temp_min real NOT NULL,
    temp_max real NOT NULL,
    humidity_min integer NOT NULL,
    humidity_max integer NOT NULL,
    storage_space integer NOT NULL
);


ALTER TABLE public.categories OWNER TO postgres;

--
-- Name: categories_category_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.categories ALTER COLUMN category_id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.categories_category_id_seq
    START WITH 1000
    INCREMENT BY 1
    MINVALUE 1000
    NO MAXVALUE
    CACHE 1
);


--
-- Name: products; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.products (
    product_id integer NOT NULL,
    warehouse_id integer NOT NULL,
    category_id integer NOT NULL,
    user_id integer NOT NULL,
    product_count integer NOT NULL,
    product_date_begin timestamp without time zone NOT NULL,
    product_date_end timestamp without time zone,
    is_active boolean DEFAULT true NOT NULL
);


ALTER TABLE public.products OWNER TO postgres;

--
-- Name: roles; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.roles (
    role_id integer NOT NULL,
    role_name text NOT NULL
);


ALTER TABLE public.roles OWNER TO postgres;

--
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    user_id integer NOT NULL,
    user_login text NOT NULL,
    user_pass text NOT NULL,
    user_email text NOT NULL,
    user_name text NOT NULL,
    user_reg_date timestamp without time zone NOT NULL,
    role_id integer DEFAULT 0,
    user_email_valid boolean DEFAULT false NOT NULL
);


ALTER TABLE public.users OWNER TO postgres;

--
-- Name: warehouses; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.warehouses (
    warehouse_id integer NOT NULL,
    warehouse_address text NOT NULL,
    warehouse_temperature real,
    warehouse_humidity integer,
    warehouse_space integer NOT NULL,
    warehouse_cost integer NOT NULL,
    warehouse_iot_ip text NOT NULL
);


ALTER TABLE public.warehouses OWNER TO postgres;

--
-- Name: storage_data; Type: VIEW; Schema: public; Owner: postgres
--

CREATE VIEW public.storage_data WITH (security_barrier='false') AS
 SELECT products.product_id,
    categories.category_name,
    products.product_count AS storing_count,
    (products.product_count * categories.storage_space),
    products.product_date_begin AS storing_date_begin,
    products.product_date_end AS storing_date_end,
    warehouses.warehouse_address,
    users.user_login,
    users.user_id,
    products.warehouse_id,
    products.is_active
   FROM (((public.products
     JOIN public.categories ON ((products.category_id = categories.category_id)))
     JOIN public.users ON ((products.user_id = users.user_id)))
     JOIN public.warehouses ON ((products.warehouse_id = warehouses.warehouse_id)))
  WHERE (products.is_active = true);


ALTER TABLE public.storage_data OWNER TO postgres;

--
-- Name: storage_storing_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.products ALTER COLUMN product_id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.storage_storing_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: users_user_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.users ALTER COLUMN user_id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.users_user_id_seq
    START WITH 100
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: warehouses_warehouse_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.warehouses ALTER COLUMN warehouse_id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.warehouses_warehouse_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Data for Name: categories; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.categories (category_id, category_name, temp_min, temp_max, humidity_min, humidity_max, storage_space) FROM stdin;
1016	product.fridge	10	30	20	60	200
1017	product.wheet	10	20	20	40	25
1018	product.meat	-20	-10	10	60	50
1019	product.paper	0	40	10	40	10
1015	product.tv	20	30	20	60	25
\.


--
-- Data for Name: products; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.products (product_id, warehouse_id, category_id, user_id, product_count, product_date_begin, product_date_end, is_active) FROM stdin;
67	23	1016	140	12	2019-12-23 01:32:37.486575	2020-01-07 14:36:09.523296	f
64	23	1016	140	2222	2019-12-23 01:28:00.508089	2020-01-07 14:36:13.976551	f
69	23	1016	140	2	2019-12-23 01:33:34.458875	2020-01-07 14:52:01.63791	f
61	23	1015	140	1	2019-12-23 01:22:36.46052	2020-01-07 14:52:10.011389	f
71	23	1016	140	2	2019-12-23 14:13:36.81688	2020-01-07 14:52:15.329693	f
62	23	1016	140	1	2019-12-23 01:22:48.22294	2020-01-07 14:52:18.458872	f
60	23	1015	140	2	2019-12-23 01:22:32.326512	2020-01-07 14:52:19.81995	f
73	19	1018	140	20	2020-01-07 16:14:53.64111	2020-01-07 16:15:01.581524	f
74	19	1018	140	50	2020-01-07 16:15:10.33314	\N	t
65	23	1016	140	12	2019-12-23 01:29:33.312652	\N	t
68	23	1015	140	8	2019-12-23 01:32:47.424793	\N	t
70	28	1017	140	20	2019-12-23 01:33:40.527286	\N	t
75	23	1019	140	10	2020-01-07 16:18:59.623342	2020-01-07 16:19:03.226949	f
76	23	1019	140	200	2020-01-07 16:19:10.777362	\N	t
\.


--
-- Data for Name: roles; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.roles (role_id, role_name) FROM stdin;
0	User
1	Admin
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.users (user_id, user_login, user_pass, user_email, user_name, user_reg_date, role_id, user_email_valid) FROM stdin;
140	client	ec6a6536ca304edf844d1d248a4f08dc	yurii.zinchenko@nure.ua	Юрiй Зiнченко	2019-12-19 17:32:39.485381	0	t
138	admin	1ef33b2d40399ed366ce31e6958bee9e	iamkiller@mail.com	Юрий Зинченко	2019-12-18 20:37:30.174713	1	t
147	test	0f297b9bb9ce1138f2d9f17beae77351	asmodeus.x5@gmail.com	Test Test	2019-12-23 14:11:09.401997	0	t
\.


--
-- Data for Name: warehouses; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.warehouses (warehouse_id, warehouse_address, warehouse_temperature, warehouse_humidity, warehouse_space, warehouse_cost, warehouse_iot_ip) FROM stdin;
23	Ware E	30	20	5000	10	1.2.3.4
21	Ware C	0	40	5000	20	1.0.1.0
28	Ware B	20	40	5000	10	127.0.0.1:5006
20	Ware	29	95	5000	10	127.0.0.1
19	Ware A	-10	20	5000	20	2.4.6.8
22	Ware D	10	20	5000	10	4.3.2.1
\.


--
-- Name: categories_category_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.categories_category_id_seq', 1019, true);


--
-- Name: storage_storing_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.storage_storing_id_seq', 76, true);


--
-- Name: users_user_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.users_user_id_seq', 147, true);


--
-- Name: warehouses_warehouse_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.warehouses_warehouse_id_seq', 28, true);


--
-- Name: products index_storing_id; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.products
    ADD CONSTRAINT index_storing_id PRIMARY KEY (product_id);

ALTER TABLE public.products CLUSTER ON index_storing_id;


--
-- Name: categories products_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.categories
    ADD CONSTRAINT products_pkey PRIMARY KEY (category_id);


--
-- Name: roles roles_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.roles
    ADD CONSTRAINT roles_pkey PRIMARY KEY (role_id);


--
-- Name: roles roles_role_name_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.roles
    ADD CONSTRAINT roles_role_name_key UNIQUE (role_name);


--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (user_id);


--
-- Name: users users_user_email_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_user_email_key UNIQUE (user_email);


--
-- Name: users users_user_login_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_user_login_key UNIQUE (user_login);


--
-- Name: warehouses warehouses_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.warehouses
    ADD CONSTRAINT warehouses_pkey PRIMARY KEY (warehouse_id);


--
-- Name: index_product_category_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_product_category_id ON public.products USING hash (category_id);


--
-- Name: index_product_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_product_id ON public.categories USING btree (category_id);

ALTER TABLE public.categories CLUSTER ON index_product_id;


--
-- Name: index_product_is_active; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_product_is_active ON public.products USING hash (is_active);


--
-- Name: index_product_user_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_product_user_id ON public.products USING hash (user_id);


--
-- Name: index_product_warehouse_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_product_warehouse_id ON public.products USING hash (warehouse_id);


--
-- Name: index_role_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_role_id ON public.roles USING btree (role_id);

ALTER TABLE public.roles CLUSTER ON index_role_id;


--
-- Name: index_user_email; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_user_email ON public.users USING btree (user_email);

ALTER TABLE public.users CLUSTER ON index_user_email;


--
-- Name: index_user_email_valid; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_user_email_valid ON public.users USING hash (user_email_valid);


--
-- Name: index_user_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_user_id ON public.users USING btree (user_id);


--
-- Name: index_user_login; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_user_login ON public.users USING btree (user_login);


--
-- Name: index_user_role_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_user_role_id ON public.users USING btree (role_id);


--
-- Name: index_warehouse_cost; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_warehouse_cost ON public.warehouses USING brin (warehouse_cost);


--
-- Name: index_warehouse_humidity; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_warehouse_humidity ON public.warehouses USING brin (warehouse_humidity);


--
-- Name: index_warehouse_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_warehouse_id ON public.warehouses USING btree (warehouse_id);


--
-- Name: index_warehouse_temperature; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_warehouse_temperature ON public.warehouses USING brin (warehouse_temperature);


--
-- Name: warehouse_iot_ip; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX warehouse_iot_ip ON public.warehouses USING btree (warehouse_iot_ip);

ALTER TABLE public.warehouses CLUSTER ON warehouse_iot_ip;


--
-- Name: products storing_category_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.products
    ADD CONSTRAINT storing_category_id_fkey FOREIGN KEY (category_id) REFERENCES public.categories(category_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: products storing_user_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.products
    ADD CONSTRAINT storing_user_id_fkey FOREIGN KEY (user_id) REFERENCES public.users(user_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: products storing_warehouse_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.products
    ADD CONSTRAINT storing_warehouse_id_fkey FOREIGN KEY (warehouse_id) REFERENCES public.warehouses(warehouse_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: users users_role_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_role_id_fkey FOREIGN KEY (role_id) REFERENCES public.roles(role_id);


--
-- Name: users users_role_id_fkey1; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_role_id_fkey1 FOREIGN KEY (role_id) REFERENCES public.roles(role_id);


--
-- Name: users users_role_id_fkey2; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_role_id_fkey2 FOREIGN KEY (role_id) REFERENCES public.roles(role_id);


--
-- Name: FUNCTION "AUTHORIZE_USER"("LOGIN" text, "PASS" text); Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON FUNCTION public."AUTHORIZE_USER"("LOGIN" text, "PASS" text) FROM postgres;
GRANT ALL ON FUNCTION public."AUTHORIZE_USER"("LOGIN" text, "PASS" text) TO "apz-server" WITH GRANT OPTION;
GRANT ALL ON FUNCTION public."AUTHORIZE_USER"("LOGIN" text, "PASS" text) TO postgres WITH GRANT OPTION;


--
-- Name: FUNCTION "CALCULATE_BEST_WAREHOUSE"("PRODUCT" text); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON FUNCTION public."CALCULATE_BEST_WAREHOUSE"("PRODUCT" text) TO "apz-server";


--
-- Name: FUNCTION "CHANGE_USER_EMAIL"("TOKEN" text, "EMAIL" text); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON FUNCTION public."CHANGE_USER_EMAIL"("TOKEN" text, "EMAIL" text) TO "apz-server";


--
-- Name: FUNCTION "CHANGE_USER_LOGIN"("TOKEN" text, "LOGIN" text); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON FUNCTION public."CHANGE_USER_LOGIN"("TOKEN" text, "LOGIN" text) TO "apz-server";


--
-- Name: FUNCTION "CHANGE_USER_NAME"("TOKEN" text, "NAME" text); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON FUNCTION public."CHANGE_USER_NAME"("TOKEN" text, "NAME" text) TO "apz-server";


--
-- Name: FUNCTION "CHANGE_USER_PASS"("TOKEN" text, "PASS1" text, "PASS2" text); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON FUNCTION public."CHANGE_USER_PASS"("TOKEN" text, "PASS1" text, "PASS2" text) TO "apz-server";


--
-- Name: PROCEDURE "CONFIRM_EMAIL"("TOKEN" text); Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON PROCEDURE public."CONFIRM_EMAIL"("TOKEN" text) FROM postgres;
GRANT ALL ON PROCEDURE public."CONFIRM_EMAIL"("TOKEN" text) TO "apz-server";
GRANT ALL ON PROCEDURE public."CONFIRM_EMAIL"("TOKEN" text) TO postgres WITH GRANT OPTION;


--
-- Name: PROCEDURE "DELETE_CATEGORY"("CAT_ID" integer); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON PROCEDURE public."DELETE_CATEGORY"("CAT_ID" integer) TO "apz-server";


--
-- Name: PROCEDURE "DELETE_WAREHOUSE"("WARE_ID" integer); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON PROCEDURE public."DELETE_WAREHOUSE"("WARE_ID" integer) TO "apz-server";


--
-- Name: FUNCTION "GENERATE_TOKEN"("LOGIN" text, "PASS" text); Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON FUNCTION public."GENERATE_TOKEN"("LOGIN" text, "PASS" text) FROM postgres;
GRANT ALL ON FUNCTION public."GENERATE_TOKEN"("LOGIN" text, "PASS" text) TO "apz-server" WITH GRANT OPTION;
GRANT ALL ON FUNCTION public."GENERATE_TOKEN"("LOGIN" text, "PASS" text) TO postgres WITH GRANT OPTION;


--
-- Name: FUNCTION "GET_FREE_SPACE"("WARE_ID" integer); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON FUNCTION public."GET_FREE_SPACE"("WARE_ID" integer) TO "apz-server";


--
-- Name: FUNCTION "GET_USER_BY_TOKEN"("TOKEN" text); Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON FUNCTION public."GET_USER_BY_TOKEN"("TOKEN" text) FROM postgres;
GRANT ALL ON FUNCTION public."GET_USER_BY_TOKEN"("TOKEN" text) TO "apz-server" WITH GRANT OPTION;
GRANT ALL ON FUNCTION public."GET_USER_BY_TOKEN"("TOKEN" text) TO postgres WITH GRANT OPTION;


--
-- Name: FUNCTION "GET_USER_DATA"("TOKEN" text); Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON FUNCTION public."GET_USER_DATA"("TOKEN" text) FROM postgres;
GRANT ALL ON FUNCTION public."GET_USER_DATA"("TOKEN" text) TO postgres WITH GRANT OPTION;
GRANT ALL ON FUNCTION public."GET_USER_DATA"("TOKEN" text) TO "apz-server" WITH GRANT OPTION;


--
-- Name: FUNCTION "LOAD_CATEGORIES"(); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON FUNCTION public."LOAD_CATEGORIES"() TO "apz-server";


--
-- Name: FUNCTION "LOAD_WAREHOUSES"(); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON FUNCTION public."LOAD_WAREHOUSES"() TO "apz-server";


--
-- Name: PROCEDURE "REGISTER_CATEGORY"("NAME" text, "TMIN" real, "TMAX" real, "HMIN" integer, "HMAX" integer, "SPACE" integer); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON PROCEDURE public."REGISTER_CATEGORY"("NAME" text, "TMIN" real, "TMAX" real, "HMIN" integer, "HMAX" integer, "SPACE" integer) TO "apz-server";


--
-- Name: FUNCTION "REGISTER_USER"("LOGIN" text, "PASS1" text, "PASS2" text, "EMAIL" text, "NAME" text); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON FUNCTION public."REGISTER_USER"("LOGIN" text, "PASS1" text, "PASS2" text, "EMAIL" text, "NAME" text) TO "apz-server";


--
-- Name: FUNCTION "REGISTER_WAREHOUSE"("ADDRESS" text, "SPACE" integer, "COST" integer, "IOT_IP" text); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON FUNCTION public."REGISTER_WAREHOUSE"("ADDRESS" text, "SPACE" integer, "COST" integer, "IOT_IP" text) TO "apz-server";


--
-- Name: PROCEDURE "REMOVE_PRODUCT"("ID" integer); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON PROCEDURE public."REMOVE_PRODUCT"("ID" integer) TO "apz-server";


--
-- Name: PROCEDURE "SET_USER_ROLE"("LOGIN" text, "ROLE_ID" integer); Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON PROCEDURE public."SET_USER_ROLE"("LOGIN" text, "ROLE_ID" integer) FROM postgres;
GRANT ALL ON PROCEDURE public."SET_USER_ROLE"("LOGIN" text, "ROLE_ID" integer) TO "apz-server" WITH GRANT OPTION;
GRANT ALL ON PROCEDURE public."SET_USER_ROLE"("LOGIN" text, "ROLE_ID" integer) TO postgres WITH GRANT OPTION;


--
-- Name: PROCEDURE "STORE_PRODUCT"("WAREHOUSE_ID" integer, "PRODUCT_NAME" text, "USER_TOKEN" text, "COUNT" integer); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON PROCEDURE public."STORE_PRODUCT"("WAREHOUSE_ID" integer, "PRODUCT_NAME" text, "USER_TOKEN" text, "COUNT" integer) TO "apz-server";


--
-- Name: FUNCTION "VALIDATE_IP"("IP" text); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON FUNCTION public."VALIDATE_IP"("IP" text) TO "apz-server";


--
-- Name: FUNCTION "VALIDATE_USER_DATA"("LOGIN" text, "PASS1" text, "PASS2" text, "EMAIL" text, "NAME" text); Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON FUNCTION public."VALIDATE_USER_DATA"("LOGIN" text, "PASS1" text, "PASS2" text, "EMAIL" text, "NAME" text) FROM postgres;
GRANT ALL ON FUNCTION public."VALIDATE_USER_DATA"("LOGIN" text, "PASS1" text, "PASS2" text, "EMAIL" text, "NAME" text) TO "apz-server" WITH GRANT OPTION;
GRANT ALL ON FUNCTION public."VALIDATE_USER_DATA"("LOGIN" text, "PASS1" text, "PASS2" text, "EMAIL" text, "NAME" text) TO postgres WITH GRANT OPTION;


--
-- Name: FUNCTION "VALIDATE_USER_TOKEN"("TOKEN" text); Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON FUNCTION public."VALIDATE_USER_TOKEN"("TOKEN" text) FROM postgres;
GRANT ALL ON FUNCTION public."VALIDATE_USER_TOKEN"("TOKEN" text) TO "apz-server" WITH GRANT OPTION;
GRANT ALL ON FUNCTION public."VALIDATE_USER_TOKEN"("TOKEN" text) TO postgres WITH GRANT OPTION;


--
-- Name: TABLE categories; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON TABLE public.categories FROM postgres;
GRANT ALL ON TABLE public.categories TO postgres WITH GRANT OPTION;
GRANT ALL ON TABLE public.categories TO "apz-server" WITH GRANT OPTION;


--
-- Name: SEQUENCE categories_category_id_seq; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON SEQUENCE public.categories_category_id_seq TO "apz-server";


--
-- Name: TABLE products; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON TABLE public.products TO "apz-server";


--
-- Name: TABLE roles; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON TABLE public.roles FROM postgres;
GRANT ALL ON TABLE public.roles TO "apz-server" WITH GRANT OPTION;
GRANT ALL ON TABLE public.roles TO postgres WITH GRANT OPTION;


--
-- Name: TABLE users; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON TABLE public.users FROM postgres;
GRANT ALL ON TABLE public.users TO "apz-server" WITH GRANT OPTION;
GRANT ALL ON TABLE public.users TO postgres WITH GRANT OPTION;


--
-- Name: TABLE warehouses; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON TABLE public.warehouses FROM postgres;
GRANT ALL ON TABLE public.warehouses TO postgres WITH GRANT OPTION;
GRANT ALL ON TABLE public.warehouses TO "apz-server" WITH GRANT OPTION;


--
-- Name: TABLE storage_data; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON TABLE public.storage_data TO "apz-server";


--
-- Name: SEQUENCE storage_storing_id_seq; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON SEQUENCE public.storage_storing_id_seq TO "apz-server";


--
-- Name: SEQUENCE users_user_id_seq; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON SEQUENCE public.users_user_id_seq FROM postgres;
GRANT ALL ON SEQUENCE public.users_user_id_seq TO "apz-server" WITH GRANT OPTION;
GRANT ALL ON SEQUENCE public.users_user_id_seq TO postgres WITH GRANT OPTION;


--
-- Name: SEQUENCE warehouses_warehouse_id_seq; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON SEQUENCE public.warehouses_warehouse_id_seq TO "apz-server";


--
-- PostgreSQL database dump complete
--

