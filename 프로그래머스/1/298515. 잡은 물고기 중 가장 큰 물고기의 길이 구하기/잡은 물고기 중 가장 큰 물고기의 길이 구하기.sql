select concat(max(LENGTH), 'cm') as MAX_LENGTH
from FISH_INFO
where LENGTH is not null;