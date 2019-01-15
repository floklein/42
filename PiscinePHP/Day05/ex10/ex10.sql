SELECT title AS `Title`, summary AS `Summary`, prod_year FROM film
    JOIN genre ON film.id_genre = genre.id_genre
    WHERE genre.name = 'erotic'
    ORDER BY prod_year DESC;