/*Создание Таблицы №1 Роботы-марсоходы*/
-- Надо ещё прикрутить связь многие-ко-многим
CREATE TABLE dbPlaces
(
	Id INT IDENTITY (1,1) NOT NULL,
	НазваниеОбласти VARCHAR (100),
	ПлощадьОбласти INT,
	КоординатаХ INT,
	КоординатаУ INT,
	ПредметИнтереса VARCHAR (50),
	УровеньОпасности FLOAT,
)
GO

--Устанавливаем ограничения и добавляем первичный ключ
ALTER TABLE dbPlaces ADD CONSTRAINT PK_dbPlaces PRIMARY KEY (Id);
ALTER TABLE dbPlaces ADD CONSTRAINT U_dbPlaces_C1 UNIQUE (НазваниеОбласти);
ALTER TABLE dbPlaces ALTER COLUMN ПредметИнтереса VARCHAR(50) NOT NULL;
ALTER TABLE dbPlaces ADD CONSTRAINT CK_dbPlaces_C1 CHECK ((УровеньОпасности >= 0) AND (УровеньОпасности <= 100)); 
GO

BULK INSERT dbPlaces
FROM 'C:\Users\Александр\Desktop\SQL\1\TPlace.txt'
WITH (fieldterminator = '	', rowterminator = '\n');
GO

select top 1200 * from dbPlaces;
GO

/*
DROP TABLE dbPlaces
GO
*/


