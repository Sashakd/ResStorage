/*Создание Таблицы №1 Роботы-марсоходы*/
-- Надо ещё прикрутить связь многие-ко-многим
CREATE TABLE dbBaseRoverInfo
(
	Id INT IDENTITY (1,1) NOT NULL,
	ТехИмя VARCHAR(25),
	ТехМодель VARCHAR(25),
	ТехТип VARCHAR(25),
	ДатаСоздания datetime,
	ТехСтрана VARCHAR(50),
	
	Состояние VARCHAR(25),
	Аккумулятор FLOAT,
	НужРемонт VARCHAR(50),
	ДатаПоследнегоОтчёта datetime,
	КоординатаХ INT,
	КоординатаУ INT,
	Высота INT,
)
GO

--Устанавливаем ограничения и добавляем первичный ключ
ALTER TABLE dbBaseRoverInfo ADD CONSTRAINT PK_dbBaseRoverInfo PRIMARY KEY (Id);
ALTER TABLE dbBaseRoverInfo ADD CONSTRAINT U_dbBaseRoverInfo_C1 UNIQUE (ТехИмя);
ALTER TABLE dbBaseRoverInfo ALTER COLUMN ТехМодель VARCHAR(25) NOT NULL;
ALTER TABLE dbBaseRoverInfo ALTER COLUMN ТехТип VARCHAR(25) NOT NULL;
ALTER TABLE dbBaseRoverInfo ALTER COLUMN ДатаСоздания datetime NOT NULL;
ALTER TABLE dbBaseRoverInfo ALTER COLUMN ТехТип VARCHAR(50) NOT NULL;

ALTER TABLE dbBaseRoverInfo ALTER COLUMN Состояние VARCHAR(25) NOT NULL;
ALTER TABLE dbBaseRoverInfo ADD CONSTRAINT CK_dbBaseRoverInfo_C1 CHECK ((Аккумулятор >= 0) AND (Аккумулятор <= 100)); 
ALTER TABLE dbBaseRoverInfo ALTER COLUMN НужРемонт VARCHAR(50) NOT NULL;
ALTER TABLE dbBaseRoverInfo ALTER COLUMN ДатаПоследнегоОтчёта datetime NOT NULL;
GO

BULK INSERT dbBaseRoverInfo
FROM 'C:\Users\Александр\Desktop\SQL\1\TProfile.txt'
WITH (fieldterminator = '	', rowterminator = '\n');
GO

select top 1200 * from dbBaseRoverInfo;
GO

/*
DROP TABLE dbBaseRoverInfo
GO
*/
