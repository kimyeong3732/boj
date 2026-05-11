select BOOK_ID, PUBLISHED_DATE
from BOOK
where CATEGORY = '인문' and year(PUBLISHED_DATE) = '2021'
order by BOOK_ID desc;