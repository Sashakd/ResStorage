/*�������� ������� �1 ������-���������*/
-- ���� ��� ���������� ����� ������-��-������
CREATE TABLE dbTasks
(
	Id INT IDENTITY (1,1) NOT NULL,
	Id_��������� INT references dbBaseRoverInfo(Id),
	Id_������� INT references dbStatusStation(Id),
	Id_������� INT references dbPlaces(Id),
	������������ datetime,
	������������ VARCHAR(200),
)
GO

--������������� ����������� � ��������� ��������� ����
ALTER TABLE dbTasks ADD CONSTRAINT PK_dbTasks PRIMARY KEY (Id);
ALTER TABLE dbTasks ADD FOREIGN KEY (Id_���������) REFERENCES dbBaseRoverInfo(Id);
ALTER TABLE dbTasks ADD FOREIGN KEY (Id_�������)   REFERENCES dbStatusStation(Id);
ALTER TABLE dbTasks ADD FOREIGN KEY (Id_�������)   REFERENCES dbPlaces(Id);
ALTER TABLE dbTasks ALTER COLUMN ������������ datetime NOT NULL;
ALTER TABLE dbTasks ALTER COLUMN ������������ VARCHAR(200) NOT NULL;
GO

BULK INSERT dbTasks
FROM 'C:\Users\���������\Desktop\SQL\1\TTasks.txt'
WITH (fieldterminator = '	', rowterminator = '\n');
GO

select top 4800 * from dbTasks;
GO

/*
DROP TABLE dbTasks
GO
*/
