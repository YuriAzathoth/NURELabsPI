--
-- PostgreSQL database dump
--

-- Dumped from database version 12.0
-- Dumped by pg_dump version 12.0

-- Started on 2019-12-10 13:58:58

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
-- TOC entry 202 (class 1259 OID 16398)
-- Name: Alternative; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Alternative" (
    "IdAlt" integer NOT NULL,
    "AName" text NOT NULL
);


ALTER TABLE public."Alternative" OWNER TO postgres;

--
-- TOC entry 203 (class 1259 OID 16401)
-- Name: Alternative_IdAlt_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Alternative" ALTER COLUMN "IdAlt" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Alternative_IdAlt_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- TOC entry 204 (class 1259 OID 16412)
-- Name: Criterion; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Criterion" (
    "IdCrit" integer NOT NULL,
    "CName" text NOT NULL,
    "CRange" numeric(4,0),
    "CWeight" numeric NOT NULL,
    "CType" text NOT NULL,
    "OptimType" text NOT NULL,
    "EdIzmer" text NOT NULL,
    "ScaleType" text NOT NULL
);


ALTER TABLE public."Criterion" OWNER TO postgres;

--
-- TOC entry 205 (class 1259 OID 16417)
-- Name: Criterion_IdCrit_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Criterion" ALTER COLUMN "IdCrit" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Criterion_IdCrit_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- TOC entry 210 (class 1259 OID 16505)
-- Name: LPR; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."LPR" (
    "IdLPR" integer NOT NULL,
    "LName" text NOT NULL,
    "LRange" numeric
);


ALTER TABLE public."LPR" OWNER TO postgres;

--
-- TOC entry 211 (class 1259 OID 16513)
-- Name: LPR_IdLPR_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."LPR" ALTER COLUMN "IdLPR" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."LPR_IdLPR_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- TOC entry 206 (class 1259 OID 16427)
-- Name: Mark; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Mark" (
    "IdMark" integer NOT NULL,
    "MName" text,
    "MRange" numeric(4,0),
    "NumMark" real NOT NULL,
    "NormMark" real NOT NULL,
    "IdCrit" integer NOT NULL
);


ALTER TABLE public."Mark" OWNER TO postgres;

--
-- TOC entry 207 (class 1259 OID 16430)
-- Name: Mark_IdMark_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Mark" ALTER COLUMN "IdMark" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Mark_IdMark_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- TOC entry 212 (class 1259 OID 41215)
-- Name: Result; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Result" (
    "IdRes" integer NOT NULL,
    "IdLPR" integer NOT NULL,
    "IdAlt" integer NOT NULL,
    "Range" numeric,
    "AWeight" numeric NOT NULL
);


ALTER TABLE public."Result" OWNER TO postgres;

--
-- TOC entry 213 (class 1259 OID 41218)
-- Name: Result_IdRes_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Result" ALTER COLUMN "IdRes" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Result_IdRes_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- TOC entry 208 (class 1259 OID 16441)
-- Name: Vector; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Vector" (
    "IdVect" integer NOT NULL,
    "IdAlt" integer NOT NULL,
    "IdMark" integer NOT NULL
);


ALTER TABLE public."Vector" OWNER TO postgres;

--
-- TOC entry 209 (class 1259 OID 16444)
-- Name: Vector_IdVect_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Vector" ALTER COLUMN "IdVect" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Vector_IdVect_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- TOC entry 214 (class 1259 OID 57583)
-- Name: Weight; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Weight" (
    "IdWeight" integer NOT NULL,
    "IdCrit" integer NOT NULL,
    "IdLPR" integer NOT NULL,
    "Weight" real NOT NULL
);


ALTER TABLE public."Weight" OWNER TO postgres;

--
-- TOC entry 215 (class 1259 OID 57586)
-- Name: Weight_IdWeight_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public."Weight" ALTER COLUMN "IdWeight" ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public."Weight_IdWeight_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- TOC entry 2884 (class 0 OID 16398)
-- Dependencies: 202
-- Data for Name: Alternative; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Alternative" ("IdAlt", "AName") FROM stdin;
120	Lenovo IdeaPad Y700 15
121	Asus ZenBook 14
122	Acer Predator Triton 500
108	Xiaomi Mi Notebook Pro 15.6
123	Apple MacBook
\.


--
-- TOC entry 2886 (class 0 OID 16412)
-- Dependencies: 204
-- Data for Name: Criterion; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Criterion" ("IdCrit", "CName", "CRange", "CWeight", "CType", "OptimType", "EdIzmer", "ScaleType") FROM stdin;
47	Видеопамять	50	8	1	1	Гб	Численные
50	Колличество ядер	50	4	1	1	Штук	Численные
51	Объём ОЗУ	50	6	1	1	Гб	Численные
57	Цена	50	2	1	0	Грн	Численные
46	Частота процессора	50	4	1	1	ГГц	Численные
\.


--
-- TOC entry 2892 (class 0 OID 16505)
-- Dependencies: 210
-- Data for Name: LPR; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."LPR" ("IdLPR", "LName", "LRange") FROM stdin;
217	User Two	0.600000024
219	User Four	0.5
216	User One	0.800000012
218	User Three	0.5
220	User Five	0.800000012
\.


--
-- TOC entry 2888 (class 0 OID 16427)
-- Dependencies: 206
-- Data for Name: Mark; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Mark" ("IdMark", "MName", "MRange", "NumMark", "NormMark", "IdCrit") FROM stdin;
545		0	2.9	0.008955041	46
530		0	3.4	0.010499014	46
525		0	4.1	0.012660575	46
540		0	3.2	0.009881424	46
535		0	4.6	0.014204547	46
546		0	8	0.02130682	51
531		0	8	0.02130682	51
526		0	16	0.04261364	51
541		0	4	0.01065341	51
536		0	16	0.04261364	51
548		0	24000	0.037878793	57
533		0	24000	0.037878793	57
528		0	46000	0.07260102	57
543		0	18000	0.028409094	57
538		0	29000	0.04577021	57
549		0	2	0.014204547	50
534		0	4	0.028409094	50
529		0	6	0.04261364	50
544		0	4	0.028409094	50
539		0	4	0.028409094	50
547		0	0	0	47
532		0	2	0.0071022734	47
527		0	8	0.028409094	47
542		0	4	0.014204547	47
537		0	2	0.0071022734	47
\.


--
-- TOC entry 2894 (class 0 OID 41215)
-- Dependencies: 212
-- Data for Name: Result; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Result" ("IdRes", "IdLPR", "IdAlt", "Range", "AWeight") FROM stdin;
1551	217	122	1	100
1552	217	121	2	71
1553	217	108	3	54
470	194	122	1	100
471	194	108	2	95
472	194	120	3	66
654	193	120	1	100
1557	216	122	1	100
1558	216	121	2	71
1559	216	108	3	54
1570	220	122	1	100
1571	220	121	2	71
1572	220	108	3	54
1573	220	120	4	49
1574	220	123	5	42
1515	218	122	1	100
1516	218	121	2	71
1517	218	108	3	54
1533	219	122	1	100
1534	219	121	2	71
1535	219	108	3	54
\.


--
-- TOC entry 2890 (class 0 OID 16441)
-- Dependencies: 208
-- Data for Name: Vector; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Vector" ("IdVect", "IdAlt", "IdMark") FROM stdin;
307	108	530
308	108	531
309	108	532
310	108	533
311	108	534
312	121	535
313	121	536
314	121	537
315	121	538
316	121	539
317	120	540
318	120	541
319	120	542
320	120	543
321	120	544
322	123	545
323	123	546
324	123	547
325	123	548
326	123	549
302	122	525
303	122	526
304	122	527
305	122	528
306	122	529
\.


--
-- TOC entry 2896 (class 0 OID 57583)
-- Dependencies: 214
-- Data for Name: Weight; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public."Weight" ("IdWeight", "IdCrit", "IdLPR", "Weight") FROM stdin;
377	46	217	8
378	47	217	4
379	50	217	4
380	51	217	8
381	57	217	2
382	46	219	2
383	47	219	6
384	50	219	4
385	51	219	6
386	57	219	4
420	46	218	4
421	47	218	2
422	50	218	2
423	51	218	4
424	57	218	8
425	46	220	6
426	47	220	4
427	50	220	6
428	51	220	4
429	57	220	6
435	46	216	4
436	47	216	8
437	50	216	2
438	51	216	6
439	57	216	2
\.


--
-- TOC entry 2917 (class 0 OID 0)
-- Dependencies: 203
-- Name: Alternative_IdAlt_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Alternative_IdAlt_seq"', 123, true);


--
-- TOC entry 2918 (class 0 OID 0)
-- Dependencies: 205
-- Name: Criterion_IdCrit_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Criterion_IdCrit_seq"', 62, true);


--
-- TOC entry 2919 (class 0 OID 0)
-- Dependencies: 211
-- Name: LPR_IdLPR_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."LPR_IdLPR_seq"', 220, true);


--
-- TOC entry 2920 (class 0 OID 0)
-- Dependencies: 207
-- Name: Mark_IdMark_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Mark_IdMark_seq"', 549, true);


--
-- TOC entry 2921 (class 0 OID 0)
-- Dependencies: 213
-- Name: Result_IdRes_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Result_IdRes_seq"', 1574, true);


--
-- TOC entry 2922 (class 0 OID 0)
-- Dependencies: 209
-- Name: Vector_IdVect_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Vector_IdVect_seq"', 326, true);


--
-- TOC entry 2923 (class 0 OID 0)
-- Dependencies: 215
-- Name: Weight_IdWeight_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Weight_IdWeight_seq"', 439, true);


--
-- TOC entry 2729 (class 2606 OID 16416)
-- Name: Alternative Alternative_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Alternative"
    ADD CONSTRAINT "Alternative_pkey" PRIMARY KEY ("IdAlt");


--
-- TOC entry 2732 (class 2606 OID 16426)
-- Name: Criterion Criterion_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Criterion"
    ADD CONSTRAINT "Criterion_pkey" PRIMARY KEY ("IdCrit");


--
-- TOC entry 2745 (class 2606 OID 41224)
-- Name: Result IdRes_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Result"
    ADD CONSTRAINT "IdRes_pkey" PRIMARY KEY ("IdRes");


--
-- TOC entry 2743 (class 2606 OID 16512)
-- Name: LPR LPR_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."LPR"
    ADD CONSTRAINT "LPR_pkey" PRIMARY KEY ("IdLPR");


--
-- TOC entry 2736 (class 2606 OID 16468)
-- Name: Mark Mark_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Mark"
    ADD CONSTRAINT "Mark_pkey" PRIMARY KEY ("IdMark");


--
-- TOC entry 2740 (class 2606 OID 16502)
-- Name: Vector Vector_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Vector"
    ADD CONSTRAINT "Vector_pkey" PRIMARY KEY ("IdVect");


--
-- TOC entry 2748 (class 2606 OID 57628)
-- Name: Weight Weight_IdCrit_IdLPR_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Weight"
    ADD CONSTRAINT "Weight_IdCrit_IdLPR_key" UNIQUE ("IdCrit", "IdLPR");


--
-- TOC entry 2750 (class 2606 OID 57620)
-- Name: Weight Weight_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Weight"
    ADD CONSTRAINT "Weight_pkey" PRIMARY KEY ("IdWeight");


--
-- TOC entry 2730 (class 1259 OID 16438)
-- Name: IdAlt; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX "IdAlt" ON public."Alternative" USING btree ("IdAlt");


--
-- TOC entry 2733 (class 1259 OID 16439)
-- Name: IdCrit; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX "IdCrit" ON public."Criterion" USING btree ("IdCrit");


--
-- TOC entry 2741 (class 1259 OID 16515)
-- Name: IdLPR; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX "IdLPR" ON public."LPR" USING btree ("IdLPR");


--
-- TOC entry 2734 (class 1259 OID 16518)
-- Name: IdMark; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX "IdMark" ON public."Mark" USING btree ("IdMark");


--
-- TOC entry 2738 (class 1259 OID 16504)
-- Name: IdVect; Type: INDEX; Schema: public; Owner: postgres
--

CREATE UNIQUE INDEX "IdVect" ON public."Vector" USING btree ("IdVect");


--
-- TOC entry 2746 (class 1259 OID 41242)
-- Name: fki_IdAlt_fkey; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_IdAlt_fkey" ON public."Result" USING btree ("IdAlt");


--
-- TOC entry 2737 (class 1259 OID 16550)
-- Name: fki_IdCrit; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_IdCrit" ON public."Mark" USING btree ("IdCrit");


--
-- TOC entry 2752 (class 2606 OID 24817)
-- Name: Vector IdAlt_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Vector"
    ADD CONSTRAINT "IdAlt_fkey" FOREIGN KEY ("IdAlt") REFERENCES public."Alternative"("IdAlt") ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2754 (class 2606 OID 41237)
-- Name: Result IdAlt_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Result"
    ADD CONSTRAINT "IdAlt_fkey" FOREIGN KEY ("IdAlt") REFERENCES public."Alternative"("IdAlt") ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2751 (class 2606 OID 24782)
-- Name: Mark IdCrit_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Mark"
    ADD CONSTRAINT "IdCrit_fkey" FOREIGN KEY ("IdCrit") REFERENCES public."Criterion"("IdCrit") ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2755 (class 2606 OID 41243)
-- Name: Result IdLPR_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Result"
    ADD CONSTRAINT "IdLPR_fkey" FOREIGN KEY ("IdAlt") REFERENCES public."Alternative"("IdAlt") ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2753 (class 2606 OID 24827)
-- Name: Vector IdMark_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Vector"
    ADD CONSTRAINT "IdMark_fkey" FOREIGN KEY ("IdMark") REFERENCES public."Mark"("IdMark") ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2756 (class 2606 OID 57609)
-- Name: Weight Weight_IdCrit_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Weight"
    ADD CONSTRAINT "Weight_IdCrit_fkey" FOREIGN KEY ("IdCrit") REFERENCES public."Criterion"("IdCrit") ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2757 (class 2606 OID 57614)
-- Name: Weight Weight_IdLPR_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Weight"
    ADD CONSTRAINT "Weight_IdLPR_fkey" FOREIGN KEY ("IdLPR") REFERENCES public."LPR"("IdLPR") ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2903 (class 0 OID 0)
-- Dependencies: 202
-- Name: TABLE "Alternative"; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON TABLE public."Alternative" FROM postgres;
GRANT ALL ON TABLE public."Alternative" TO postgres WITH GRANT OPTION;
GRANT ALL ON TABLE public."Alternative" TO "moti-user" WITH GRANT OPTION;


--
-- TOC entry 2904 (class 0 OID 0)
-- Dependencies: 203
-- Name: SEQUENCE "Alternative_IdAlt_seq"; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON SEQUENCE public."Alternative_IdAlt_seq" FROM postgres;
GRANT ALL ON SEQUENCE public."Alternative_IdAlt_seq" TO postgres WITH GRANT OPTION;
GRANT ALL ON SEQUENCE public."Alternative_IdAlt_seq" TO "moti-user" WITH GRANT OPTION;


--
-- TOC entry 2905 (class 0 OID 0)
-- Dependencies: 204
-- Name: TABLE "Criterion"; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON TABLE public."Criterion" FROM postgres;
GRANT ALL ON TABLE public."Criterion" TO postgres WITH GRANT OPTION;
GRANT ALL ON TABLE public."Criterion" TO "moti-user" WITH GRANT OPTION;


--
-- TOC entry 2906 (class 0 OID 0)
-- Dependencies: 205
-- Name: SEQUENCE "Criterion_IdCrit_seq"; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON SEQUENCE public."Criterion_IdCrit_seq" FROM postgres;
GRANT ALL ON SEQUENCE public."Criterion_IdCrit_seq" TO postgres WITH GRANT OPTION;
GRANT ALL ON SEQUENCE public."Criterion_IdCrit_seq" TO "moti-user" WITH GRANT OPTION;


--
-- TOC entry 2907 (class 0 OID 0)
-- Dependencies: 210
-- Name: TABLE "LPR"; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON TABLE public."LPR" FROM postgres;
GRANT ALL ON TABLE public."LPR" TO postgres WITH GRANT OPTION;
GRANT ALL ON TABLE public."LPR" TO "moti-user" WITH GRANT OPTION;


--
-- TOC entry 2908 (class 0 OID 0)
-- Dependencies: 211
-- Name: SEQUENCE "LPR_IdLPR_seq"; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON SEQUENCE public."LPR_IdLPR_seq" FROM postgres;
GRANT ALL ON SEQUENCE public."LPR_IdLPR_seq" TO postgres WITH GRANT OPTION;
GRANT ALL ON SEQUENCE public."LPR_IdLPR_seq" TO "moti-user" WITH GRANT OPTION;


--
-- TOC entry 2909 (class 0 OID 0)
-- Dependencies: 206
-- Name: TABLE "Mark"; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON TABLE public."Mark" FROM postgres;
GRANT ALL ON TABLE public."Mark" TO postgres WITH GRANT OPTION;
GRANT ALL ON TABLE public."Mark" TO "moti-user" WITH GRANT OPTION;


--
-- TOC entry 2910 (class 0 OID 0)
-- Dependencies: 207
-- Name: SEQUENCE "Mark_IdMark_seq"; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON SEQUENCE public."Mark_IdMark_seq" FROM postgres;
GRANT ALL ON SEQUENCE public."Mark_IdMark_seq" TO postgres WITH GRANT OPTION;
GRANT ALL ON SEQUENCE public."Mark_IdMark_seq" TO "moti-user" WITH GRANT OPTION;


--
-- TOC entry 2911 (class 0 OID 0)
-- Dependencies: 212
-- Name: TABLE "Result"; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON TABLE public."Result" FROM postgres;
GRANT ALL ON TABLE public."Result" TO postgres WITH GRANT OPTION;
GRANT ALL ON TABLE public."Result" TO "moti-user" WITH GRANT OPTION;


--
-- TOC entry 2912 (class 0 OID 0)
-- Dependencies: 213
-- Name: SEQUENCE "Result_IdRes_seq"; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON SEQUENCE public."Result_IdRes_seq" FROM postgres;
GRANT ALL ON SEQUENCE public."Result_IdRes_seq" TO postgres WITH GRANT OPTION;
GRANT ALL ON SEQUENCE public."Result_IdRes_seq" TO "moti-user" WITH GRANT OPTION;


--
-- TOC entry 2913 (class 0 OID 0)
-- Dependencies: 208
-- Name: TABLE "Vector"; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON TABLE public."Vector" FROM postgres;
GRANT ALL ON TABLE public."Vector" TO postgres WITH GRANT OPTION;
GRANT ALL ON TABLE public."Vector" TO "moti-user" WITH GRANT OPTION;


--
-- TOC entry 2914 (class 0 OID 0)
-- Dependencies: 209
-- Name: SEQUENCE "Vector_IdVect_seq"; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON SEQUENCE public."Vector_IdVect_seq" FROM postgres;
GRANT ALL ON SEQUENCE public."Vector_IdVect_seq" TO postgres WITH GRANT OPTION;
GRANT ALL ON SEQUENCE public."Vector_IdVect_seq" TO "moti-user" WITH GRANT OPTION;


--
-- TOC entry 2915 (class 0 OID 0)
-- Dependencies: 214
-- Name: TABLE "Weight"; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON TABLE public."Weight" FROM postgres;
GRANT ALL ON TABLE public."Weight" TO postgres WITH GRANT OPTION;
GRANT ALL ON TABLE public."Weight" TO "moti-user" WITH GRANT OPTION;


--
-- TOC entry 2916 (class 0 OID 0)
-- Dependencies: 215
-- Name: SEQUENCE "Weight_IdWeight_seq"; Type: ACL; Schema: public; Owner: postgres
--

REVOKE ALL ON SEQUENCE public."Weight_IdWeight_seq" FROM postgres;
GRANT ALL ON SEQUENCE public."Weight_IdWeight_seq" TO postgres WITH GRANT OPTION;
GRANT ALL ON SEQUENCE public."Weight_IdWeight_seq" TO "moti-user" WITH GRANT OPTION;


-- Completed on 2019-12-10 13:58:58

--
-- PostgreSQL database dump complete
--

