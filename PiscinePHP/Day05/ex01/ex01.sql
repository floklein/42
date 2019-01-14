CREATE TABLE `ft_table` (
    `id` int PRIMARY KEY NOT NULL AUTO_INCREMENT,
	`login` varchar(8) NOT NULL DEFAULT 'toto',
	`group` ENUM('staff', 'student', 'other') NOT NULL,
	`creation_date` DATE NOT NULL);