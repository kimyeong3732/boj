select FACTORY_ID, FACTORY_NAME, ADDRESS
from FOOD_FACTORY
where substring(ADDRESS, 1, 3) = '강원도'
order by FACTORY_ID asc;