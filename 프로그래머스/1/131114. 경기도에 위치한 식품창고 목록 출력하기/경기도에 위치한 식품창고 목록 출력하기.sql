select WAREHOUSE_ID, WAREHOUSE_NAME, ADDRESS, if(FREEZER_YN is null, 'N', FREEZER_YN) as FREEZER_YN
from FOOD_WAREHOUSE
where substring(ADDRESS, 1, 3) = '경기도'
order by WAREHOUSE_ID asc;