SELECT ABS(DATEDIFF(MAX(`date`), MIN(`date`))) AS uptime FROM member_history
    GROUP BY id_film;