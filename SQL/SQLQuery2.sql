/*Создание Таблицы №2 Станции ПЕРЕДЕЛАТЬ*/
CREATE TABLE dbStatusStation
(
	Id INT IDENTITY (1,1) NOT NULL,
	НазваниеСтанции  VARCHAR (50),
	РазмерСтанции	 VARCHAR(25), 
	ТипСтанции		 VARCHAR(25),
	КоординатаХ			INT,
	КоординатаУ			INT,
	СостояниеСтанции VARCHAR (50),
)
GO

--Устанавливаем ограничения и добавляем первичный ключ
ALTER TABLE dbStatusStation ADD CONSTRAINT PK_dbStatusStation PRIMARY KEY (Id);
--ALTER TABLE dbStatusStation ADD CONSTRAINT U_dbStatusStation_C1 UNIQUE (НазваниеСтанции);
ALTER TABLE dbStatusStation ALTER COLUMN НазваниеСтанции VARCHAR(50) NOT NULL;
ALTER TABLE dbStatusStation ALTER COLUMN РазмерСтанции VARCHAR(25) NOT NULL;
ALTER TABLE dbStatusStation ALTER COLUMN ТипСтанции VARCHAR(25) NOT NULL;
ALTER TABLE dbStatusStation ALTER COLUMN СостояниеСтанции VARCHAR(50) NOT NULL;
GO

BULK INSERT dbStatusStation
FROM 'C:\Users\Александр\Desktop\SQL\1\TStation.txt'
WITH (fieldterminator = '	', rowterminator = '\n');
GO

select top 1200 * from dbStatusStation;
GO

/*
DROP TABLE dbStatusStation
GO
*/
