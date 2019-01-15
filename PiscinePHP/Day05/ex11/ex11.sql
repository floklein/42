SELECT UPPER(user_card.last_name) AS `NAME`, user_card.first_name, subscription.price FROM user_card
    JOIN member ON user_card.id_user = member.id_user_card
    JOIN subscription ON member.id_sub = subscription.id_sub
    WHERE subscription.price > 42
    ORDER BY user_card.last_name ASC,
    user_card.first_name ASC;