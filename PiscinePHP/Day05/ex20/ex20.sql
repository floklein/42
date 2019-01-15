SELECT film.id_genre,
        genre.name AS name_genre,
        distrib.id_distrib,
        distrib.name AS name_distrib,
        film.title AS title_film
    FROM film
        LEFT JOIN genre ON film.id_genre = genre.id_genre
        LEFT JOIN distrib ON film.id_distrib = distrib.id_distrib
    WHERE film.id_genre BETWEEN 4 AND 8;