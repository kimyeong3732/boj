select PT_NAME, PT_NO, GEND_CD, AGE, if(TLNO is null, 'NONE', TLNO) as TLNO
from PATIENT
where GEND_CD = 'W' and AGE <= 12
order by AGE desc, PT_NAME asc;