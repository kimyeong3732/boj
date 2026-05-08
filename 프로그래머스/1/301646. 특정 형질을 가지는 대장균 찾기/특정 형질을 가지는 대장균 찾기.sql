select count(*) as COUNT
from ECOLI_DATA
where floor(GENOTYPE / 2) % 2 = 0 and (GENOTYPE % 2 = 1 or floor(GENOTYPE / 4) % 2 = 1);