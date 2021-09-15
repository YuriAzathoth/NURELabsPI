--
-- PostgreSQL database dump
--

-- Dumped from database version 12.2
-- Dumped by pg_dump version 12.2

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

DROP DATABASE "ark-db";
--
-- Name: ark-db; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE "ark-db" WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'C' LC_CTYPE = 'C';


ALTER DATABASE "ark-db" OWNER TO postgres;

\connect -reuse-previous=on "dbname='ark-db'"

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

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    id integer NOT NULL,
    name text NOT NULL,
    surname text NOT NULL,
    password text NOT NULL,
    email text NOT NULL,
    role smallint NOT NULL,
    CONSTRAINT users_email_check CHECK ((email ~ '^[A-Za-zА-Яа-я.]+@[A-Za-zА-Яа-я.]+.[A-Za-zА-Яа-я.]{2,4}$'::text)),
    CONSTRAINT users_name_check CHECK ((name ~ '^[A-Za-zА-Яа-я ]+$'::text)),
    CONSTRAINT users_surname_check CHECK ((surname ~ '^[A-Za-zА-Яа-я ]+$'::text))
);


ALTER TABLE public.users OWNER TO postgres;

--
-- Name: get_user_id_by_token(text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.get_user_id_by_token(token text) RETURNS public.users
    LANGUAGE sql
    AS $$SELECT * FROM "users" WHERE MD5(CONCAT("email", '|', "password")) = "token"$$;


ALTER FUNCTION public.get_user_id_by_token(token text) OWNER TO postgres;

--
-- Name: agricultures; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.agricultures (
    id integer NOT NULL,
    name text NOT NULL,
    humidity_min smallint NOT NULL,
    humidity_max smallint NOT NULL
);


ALTER TABLE public.agricultures OWNER TO postgres;

--
-- Name: agricultures_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.agricultures ALTER COLUMN id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.agricultures_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: fields; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.fields (
    id integer NOT NULL,
    cadastral character(17) NOT NULL COLLATE pg_catalog."C",
    agriculture_id integer NOT NULL,
    user_id integer NOT NULL,
    area smallint NOT NULL,
    CONSTRAINT fields_cadastral_check CHECK ((cadastral ~ '^[0-9]{2}:[0-9]{2}:[0-9]{7}:[0-9]{3}$'::text))
);


ALTER TABLE public.fields OWNER TO postgres;

--
-- Name: fields_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.fields ALTER COLUMN id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.fields_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: irrigation_log; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.irrigation_log (
    id integer NOT NULL,
    field_id integer NOT NULL,
    humidity smallint NOT NULL,
    decission integer NOT NULL,
    count integer NOT NULL,
    logtime timestamp without time zone DEFAULT now() NOT NULL
);


ALTER TABLE public.irrigation_log OWNER TO postgres;

--
-- Name: irrigation_log_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.irrigation_log ALTER COLUMN id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.irrigation_log_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: tasks; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.tasks (
    id integer NOT NULL,
    field_id integer NOT NULL,
    employee_id integer NOT NULL,
    status smallint NOT NULL,
    CONSTRAINT tasks_status_check CHECK (((status >= 0) AND (status <= 1)))
);


ALTER TABLE public.tasks OWNER TO postgres;

--
-- Name: tasks_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.tasks ALTER COLUMN id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.tasks_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.users ALTER COLUMN id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: agricultures_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.agricultures_id_seq', 1, true);


--
-- Name: fields_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.fields_id_seq', 1, true);


--
-- Name: irrigation_log_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.irrigation_log_id_seq', 1, true);


--
-- Name: tasks_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.tasks_id_seq', 1, true);


--
-- Name: users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.users_id_seq', 1, true);


--
-- Name: agricultures index_agriculture_id; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.agricultures
    ADD CONSTRAINT index_agriculture_id PRIMARY KEY (id);


--
-- Name: fields index_fields_id; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.fields
    ADD CONSTRAINT index_fields_id PRIMARY KEY (id);


--
-- Name: irrigation_log index_irrigation_id; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.irrigation_log
    ADD CONSTRAINT index_irrigation_id PRIMARY KEY (id);


--
-- Name: users index_user_id; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT index_user_id PRIMARY KEY (id);


--
-- Name: tasks tasks_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.tasks
    ADD CONSTRAINT tasks_pkey PRIMARY KEY (id);


--
-- Name: users users_email_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_email_key UNIQUE (email);


--
-- Name: index_fields_agriculture; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_fields_agriculture ON public.fields USING btree (agriculture_id);


--
-- Name: index_fields_user_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_fields_user_id ON public.fields USING btree (user_id);


--
-- Name: index_irrigation_field; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_irrigation_field ON public.irrigation_log USING btree (field_id);


--
-- Name: index_irrigation_logtime; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_irrigation_logtime ON public.irrigation_log USING btree (logtime);


--
-- Name: index_tasks_employee_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_tasks_employee_id ON public.tasks USING btree (employee_id);


--
-- Name: index_tasks_field_id; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX index_tasks_field_id ON public.tasks USING btree (field_id);


--
-- Name: index_user_email; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX index_user_email ON public.users USING btree (email);


--
-- Name: fields fields_agriculture_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.fields
    ADD CONSTRAINT fields_agriculture_id_fkey FOREIGN KEY (agriculture_id) REFERENCES public.agricultures(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: fields fields_user_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.fields
    ADD CONSTRAINT fields_user_id_fkey FOREIGN KEY (user_id) REFERENCES public.users(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: irrigation_log irrigation_log_field_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.irrigation_log
    ADD CONSTRAINT irrigation_log_field_id_fkey FOREIGN KEY (field_id) REFERENCES public.fields(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: tasks tasks_employee_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.tasks
    ADD CONSTRAINT tasks_employee_id_fkey FOREIGN KEY (employee_id) REFERENCES public.users(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: tasks tasks_field_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.tasks
    ADD CONSTRAINT tasks_field_id_fkey FOREIGN KEY (field_id) REFERENCES public.fields(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: TABLE users; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON TABLE public.users TO "ark-server" WITH GRANT OPTION;


--
-- Name: FUNCTION get_user_id_by_token(token text); Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON FUNCTION public.get_user_id_by_token(token text) TO "ark-server";


--
-- Name: TABLE agricultures; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON TABLE public.agricultures TO "ark-server" WITH GRANT OPTION;


--
-- Name: SEQUENCE agricultures_id_seq; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON SEQUENCE public.agricultures_id_seq TO "ark-server" WITH GRANT OPTION;


--
-- Name: TABLE fields; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON TABLE public.fields TO "ark-server";


--
-- Name: SEQUENCE fields_id_seq; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON SEQUENCE public.fields_id_seq TO "ark-server";


--
-- Name: TABLE irrigation_log; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON TABLE public.irrigation_log TO "ark-server";


--
-- Name: SEQUENCE irrigation_log_id_seq; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON SEQUENCE public.irrigation_log_id_seq TO "ark-server";


--
-- Name: TABLE tasks; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON TABLE public.tasks TO "ark-server";


--
-- Name: SEQUENCE users_id_seq; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON SEQUENCE public.users_id_seq TO "ark-server" WITH GRANT OPTION;


--
-- PostgreSQL database dump complete
--

