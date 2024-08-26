(define (problem problema.pddl) (:domain navigation)
(:objects
    S1 - fermata
    S2 - fermata
    S3 - fermata
    S4 - fermata
    S5 - fermata
    S6 - fermata
    S7 - fermata
    S8 - fermata
    S9 - fermata
	S10 - fermata
    S11 - fermata
    S12 - fermata
    S13 - fermata
    S14 - fermata
    S15 - fermata
    S16 - fermata
    S17 - fermata
    bicicletta1a bicicletta2a bicicletta3a bicicletta4a bicicletta5a bicicletta6a bicicletta7a bicicletta8a bicicletta9a bicicletta10a bicicletta12a bicicletta13a bicicletta14a bicicletta15a bicicletta16a bicicletta17a - bicicletta
    bicicletta1b bicicletta2b bicicletta3b bicicletta4b bicicletta5b bicicletta6b bicicletta7b bicicletta8b bicicletta9b bicicletta10b bicicletta12b bicicletta13b bicicletta14b bicicletta15b bicicletta16b bicicletta17b - bicicletta
    bicicletta1c bicicletta2c bicicletta3c bicicletta4c bicicletta5c bicicletta6c bicicletta7c bicicletta8c bicicletta9c bicicletta10c bicicletta12c bicicletta13c bicicletta14c bicicletta15c bicicletta16c bicicletta17c - bicicletta
    bicicletta1d bicicletta2d bicicletta3d bicicletta4d bicicletta5d bicicletta6d bicicletta7d bicicletta8d bicicletta9d bicicletta10d bicicletta12d bicicletta13d bicicletta14d bicicletta15d bicicletta16d bicicletta17d - bicicletta
    bicicletta1e bicicletta2e bicicletta3e bicicletta4e bicicletta5e bicicletta9e bicicletta12e bicicletta14e bicicletta15e bicicletta16e - bicicletta
    bicicletta6e bicicletta7e bicicletta8e bicicletta9f bicicletta13e bicicletta9g bicicletta16f bicicletta9h bicicletta9i- bicicletta
    metro1a metro2a metro3a metro4a metro5a metro6a metro7a metro8a metro9a metro10a metro11a metro12a metro13a metro14a metro15a metro16a - metro
    metro2b metro3b metro4b metro5b metro6b metro7b metro8b metro9b metro10b metro11b metro12b metro13b metro14b metro15b metro16b metro17b - metro
	auto1_2 auto2_1 auto1_17 auto17_1 auto2_17 auto17_2 - auto
)

(:init
	(linea_metro S1 S2 metro1a)
	(linea_metro S2 S3 metro2a)
	(linea_metro S3 S4 metro3a)
	(linea_metro S4 S5 metro4a)
	(linea_metro S5 S6 metro5a)
	(linea_metro S6 S7 metro6a)
	(linea_metro S7 S8 metro7a)
	(linea_metro S8 S9 metro8a)
	(linea_metro S9 S10 metro9a)
	(linea_metro S10 S11 metro10a)
	(linea_metro S11 S12 metro11a)
	(linea_metro S12 S13 metro12a)
	(linea_metro S13 S14 metro13a)
	(linea_metro S14 S15 metro14a)
	(linea_metro S15 S16 metro15a)
	(linea_metro S16 S17 metro16a)
	
	(linea_metro S2 S1 metro2b)
	(linea_metro S3 S2 metro3b)
	(linea_metro S4 S3 metro4b)
	(linea_metro S5 S4 metro5b)
	(linea_metro S6 S5 metro6b)
	(linea_metro S7 S6 metro7b)
	(linea_metro S8 S7 metro8b)
	(linea_metro S9 S8 metro9b)
	(linea_metro S10 S9 metro10b)
	(linea_metro S11 S10 metro11b)
	(linea_metro S12 S11 metro12b)
	(linea_metro S13 S12 metro13b)
	(linea_metro S14 S13 metro14b)
	(linea_metro S15 S14 metro15b)
	(linea_metro S16 S15 metro16b)
	(linea_metro S17 S16 metro17b)
	
	(strada S1 S2 auto1_2)
	(strada S2 S1 auto2_1)
	(strada S1 S17 auto1_17)
	(strada S17 S1 auto17_1)
	(strada S2 S17 auto2_17)
	(strada S17 S2 auto17_2)
	
	(ciclabile S1 S2 bicicletta1a)
	(ciclabile S1 S3 bicicletta1a)
	
	(ciclabile S2 S1 bicicletta2a)
	(ciclabile S2 S3 bicicletta2a)
	(ciclabile S2 S4 bicicletta2a)
	
	(ciclabile S3 S1 bicicletta3a)
	(ciclabile S3 S2 bicicletta3a)
	(ciclabile S3 S4 bicicletta3a)
	(ciclabile S3 S5 bicicletta3a)
	
	(ciclabile S4 S2 bicicletta4a)
	(ciclabile S4 S3 bicicletta4a)
	(ciclabile S4 S5 bicicletta4a)
	(ciclabile S4 S6 bicicletta4a)
	
	(ciclabile S4 S2 bicicletta4b)
	(ciclabile S4 S3 bicicletta4b)
	(ciclabile S4 S5 bicicletta4b)
	(ciclabile S4 S6 bicicletta4b)
	
	(ciclabile S4 S2 bicicletta4c)
	(ciclabile S4 S3 bicicletta4c)
	(ciclabile S4 S5 bicicletta4c)
	(ciclabile S4 S6 bicicletta4c)
	
	(ciclabile S4 S2 bicicletta4d)
	(ciclabile S4 S3 bicicletta4d)
	(ciclabile S4 S5 bicicletta4d)
	(ciclabile S4 S6 bicicletta4d)
	
	(ciclabile S4 S2 bicicletta4e)
	(ciclabile S4 S3 bicicletta4e)
	(ciclabile S4 S5 bicicletta4e)
	(ciclabile S4 S6 bicicletta4e)
	
	(ciclabile S5 S3 bicicletta5a)
	(ciclabile S5 S4 bicicletta5a)
	(ciclabile S5 S6 bicicletta5a)
	(ciclabile S5 S7 bicicletta5a)
	
	(ciclabile S5 S3 bicicletta5b)
	(ciclabile S5 S4 bicicletta5b)
	(ciclabile S5 S6 bicicletta5b)
	(ciclabile S5 S7 bicicletta5b)
	
	(ciclabile S5 S3 bicicletta5c)
	(ciclabile S5 S4 bicicletta5c)
	(ciclabile S5 S6 bicicletta5c)
	(ciclabile S5 S7 bicicletta5c)
	
	(ciclabile S6 S4 bicicletta6a)
	(ciclabile S6 S5 bicicletta6a)
	(ciclabile S6 S7 bicicletta6a)
	(ciclabile S6 S8 bicicletta6a)
	
	(ciclabile S6 S4 bicicletta6b)
	(ciclabile S6 S5 bicicletta6b)
	(ciclabile S6 S7 bicicletta6b)
	(ciclabile S6 S8 bicicletta6b)
	
	(ciclabile S6 S4 bicicletta6c)
	(ciclabile S6 S5 bicicletta6c)
	(ciclabile S6 S7 bicicletta6c)
	(ciclabile S6 S8 bicicletta6c)
	
	(ciclabile S6 S4 bicicletta6d)
	(ciclabile S6 S5 bicicletta6d)
	(ciclabile S6 S7 bicicletta6d)
	(ciclabile S6 S8 bicicletta6d)
	
	(ciclabile S7 S5 bicicletta7a)
	(ciclabile S7 S6 bicicletta7a)
	(ciclabile S7 S8 bicicletta7a)
	(ciclabile S7 S9 bicicletta7a)
	
	(ciclabile S7 S5 bicicletta7b)
	(ciclabile S7 S6 bicicletta7b)
	(ciclabile S7 S8 bicicletta7b)
	(ciclabile S7 S9 bicicletta7b)
	
	(ciclabile S7 S5 bicicletta7c)
	(ciclabile S7 S6 bicicletta7c)
	(ciclabile S7 S8 bicicletta7c)
	(ciclabile S7 S9 bicicletta7c)
	
	(ciclabile S7 S5 bicicletta7d)
	(ciclabile S7 S6 bicicletta7d)
	(ciclabile S7 S8 bicicletta7d)
	(ciclabile S7 S9 bicicletta7d)
	
	(ciclabile S8 S6 bicicletta8a)
	(ciclabile S8 S7 bicicletta8a)
	(ciclabile S8 S9 bicicletta8a)
	(ciclabile S8 S10 bicicletta8a)
	
	(ciclabile S8 S6 bicicletta8b)
	(ciclabile S8 S7 bicicletta8b)
	(ciclabile S8 S9 bicicletta8b)
	(ciclabile S8 S10 bicicletta8b)
	
	(ciclabile S8 S6 bicicletta8c)
	(ciclabile S8 S7 bicicletta8c)
	(ciclabile S8 S9 bicicletta8c)
	(ciclabile S8 S10 bicicletta8c)
	
	(ciclabile S8 S6 bicicletta8d)
	(ciclabile S8 S7 bicicletta8d)
	(ciclabile S8 S9 bicicletta8d)
	(ciclabile S8 S10 bicicletta8d)
	
	(ciclabile S9 S7 bicicletta9a)
	(ciclabile S9 S8 bicicletta9a)
	(ciclabile S9 S10 bicicletta9a)
	(ciclabile S9 S11 bicicletta9a)
	
	(ciclabile S9 S7 bicicletta9b)
	(ciclabile S9 S8 bicicletta9b)
	(ciclabile S9 S10 bicicletta9b)
	(ciclabile S9 S11 bicicletta9b)
	
	(ciclabile S9 S7 bicicletta9c)
	(ciclabile S9 S8 bicicletta9c)
	(ciclabile S9 S10 bicicletta9c)
	(ciclabile S9 S11 bicicletta9c)
	
	(ciclabile S9 S7 bicicletta9d)
	(ciclabile S9 S8 bicicletta9d)
	(ciclabile S9 S10 bicicletta9d)
	(ciclabile S9 S11 bicicletta9d)
	
	(ciclabile S9 S7 bicicletta9e)
	(ciclabile S9 S8 bicicletta9e)
	(ciclabile S9 S10 bicicletta9e)
	(ciclabile S9 S11 bicicletta9e)
	
	(ciclabile S9 S7 bicicletta9f)
	(ciclabile S9 S8 bicicletta9f)
	(ciclabile S9 S10 bicicletta9f)
	(ciclabile S9 S11 bicicletta9f)
	
	(ciclabile S9 S7 bicicletta9g)
	(ciclabile S9 S8 bicicletta9g)
	(ciclabile S9 S10 bicicletta9g)
	(ciclabile S9 S11 bicicletta9g)
	
	(ciclabile S9 S7 bicicletta9h)
	(ciclabile S9 S8 bicicletta9h)
	(ciclabile S9 S10 bicicletta9h)
	(ciclabile S9 S11 bicicletta9h)
	
	(ciclabile S9 S7 bicicletta9i)
	(ciclabile S9 S8 bicicletta9i)
	(ciclabile S9 S10 bicicletta9i)
	(ciclabile S9 S11 bicicletta9i)
	
	(ciclabile S10 S8 bicicletta10a)
	(ciclabile S10 S9 bicicletta10a)
	(ciclabile S10 S11 bicicletta10a)
	(ciclabile S10 S12 bicicletta10a)
	
	(ciclabile S10 S8 bicicletta10b)
	(ciclabile S10 S9 bicicletta10b)
	(ciclabile S10 S11 bicicletta10b)
	(ciclabile S10 S12 bicicletta10b)
	
	(ciclabile S10 S8 bicicletta10c)
	(ciclabile S10 S9 bicicletta10c)
	(ciclabile S10 S11 bicicletta10c)
	(ciclabile S10 S12 bicicletta10c)
	
	(ciclabile S12 S10 bicicletta12a)
	(ciclabile S12 S11 bicicletta12a)
	(ciclabile S12 S13 bicicletta12a)
	(ciclabile S12 S14 bicicletta12a)
	
	(ciclabile S12 S10 bicicletta12b)
	(ciclabile S12 S11 bicicletta12b)
	(ciclabile S12 S13 bicicletta12b)
	(ciclabile S12 S14 bicicletta12b)
	
	(ciclabile S12 S10 bicicletta12c)
	(ciclabile S12 S11 bicicletta12c)
	(ciclabile S12 S13 bicicletta12c)
	(ciclabile S12 S14 bicicletta12c)
	
	(ciclabile S12 S10 bicicletta12d)
	(ciclabile S12 S11 bicicletta12d)
	(ciclabile S12 S13 bicicletta12d)
	(ciclabile S12 S14 bicicletta12d)
	
	(ciclabile S12 S10 bicicletta12e)
	(ciclabile S12 S11 bicicletta12e)
	(ciclabile S12 S13 bicicletta12e)
	(ciclabile S12 S14 bicicletta12e)
	
	(ciclabile S13 S11 bicicletta13a)
	(ciclabile S13 S12 bicicletta13a)
	(ciclabile S13 S14 bicicletta13a)
	(ciclabile S13 S15 bicicletta13a)
	
	(ciclabile S13 S11 bicicletta13b)
	(ciclabile S13 S12 bicicletta13b)
	(ciclabile S13 S14 bicicletta13b)
	(ciclabile S13 S15 bicicletta13b)
	
	(ciclabile S13 S11 bicicletta13c)
	(ciclabile S13 S12 bicicletta13c)
	(ciclabile S13 S14 bicicletta13c)
	(ciclabile S13 S15 bicicletta13c)
	
	(ciclabile S13 S11 bicicletta13d)
	(ciclabile S13 S12 bicicletta13d)
	(ciclabile S13 S14 bicicletta13d)
	(ciclabile S13 S15 bicicletta13d)
	
	(ciclabile S16 S14 bicicletta16a)
	(ciclabile S16 S15 bicicletta16a)
	(ciclabile S16 S17 bicicletta16a)
	
	(ciclabile S16 S14 bicicletta16b)
	(ciclabile S16 S15 bicicletta16b)
	(ciclabile S16 S17 bicicletta16b)
	
	(ciclabile S16 S14 bicicletta16c)
	(ciclabile S16 S15 bicicletta16c)
	(ciclabile S16 S17 bicicletta16c)
	
	(ciclabile S16 S14 bicicletta16d)
	(ciclabile S16 S15 bicicletta16d)
	(ciclabile S16 S17 bicicletta16d)
	
	(ciclabile S16 S14 bicicletta16e)
	(ciclabile S16 S15 bicicletta16e)
	(ciclabile S16 S17 bicicletta16e)
	
	(ciclabile S16 S14 bicicletta16f)
	(ciclabile S16 S15 bicicletta16f)
	(ciclabile S16 S17 bicicletta16f)
	
	(ciclabile S16 S14 bicicletta16g)
	(ciclabile S16 S15 bicicletta16g)
	(ciclabile S16 S17 bicicletta16g)
	
	(ciclabile S17 S16 bicicletta17a)
	(ciclabile S17 S15 bicicletta17a)
    
    (at S1)
)
(:goal (and
    (at S14)
))
)
