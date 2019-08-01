/*Создание Таблицы №1 Роботы-марсоходы*/
-- Надо ещё прикрутить связь многие-ко-многим
CREATE TABLE dbTasks
(
	Id INT IDENTITY (1,1) NOT NULL,
	Id_Марсохода INT references dbBaseRoverInfo(Id),
	Id_Станции INT references dbStatusStation(Id),
	Id_Области INT references dbPlaces(Id),
	ДатаСоздания datetime,
	ДеталиМиссии VARCHAR(200),
)
GO

--Устанавливаем ограничения и добавляем первичный ключ
ALTER TABLE dbTasks ADD CONSTRAINT PK_dbTasks PRIMARY KEY (Id);
ALTER TABLE dbTasks ADD FOREIGN KEY (Id_Марсохода) REFERENCES dbBaseRoverInfo(Id);
ALTER TABLE dbTasks ADD FOREIGN KEY (Id_Станции)   REFERENCES dbStatusStation(Id);
ALTER TABLE dbTasks ADD FOREIGN KEY (Id_Области)   REFERENCES dbPlaces(Id);
ALTER TABLE dbTasks ALTER COLUMN ДатаСоздания datetime NOT NULL;
ALTER TABLE dbTasks ALTER COLUMN ДеталиМиссии VARCHAR(200) NOT NULL;
GO

BULK INSERT dbTasks
FROM 'C:\Users\Александр\Desktop\SQL\1\TTasks.txt'
WITH (fieldterminator = '	', rowterminator = '\n');
GO

select top 4800 * from dbTasks;
GO

/*
DROP TABLE dbTasks
GO
*/
