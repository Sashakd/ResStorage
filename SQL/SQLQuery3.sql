/*�������� ������� �1 ������-���������*/
-- ���� ��� ���������� ����� ������-��-������
CREATE TABLE dbPlaces
(
	Id INT IDENTITY (1,1) NOT NULL,
	��������������� VARCHAR (100),
	�������������� INT,
	����������� INT,
	����������� INT,
	��������������� VARCHAR (50),
	���������������� FLOAT,
)
GO

--������������� ����������� � ��������� ��������� ����
ALTER TABLE dbPlaces ADD CONSTRAINT PK_dbPlaces PRIMARY KEY (Id);
ALTER TABLE dbPlaces ADD CONSTRAINT U_dbPlaces_C1 UNIQUE (���������������);
ALTER TABLE dbPlaces ALTER COLUMN ��������������� VARCHAR(50) NOT NULL;
ALTER TABLE dbPlaces ADD CONSTRAINT CK_dbPlaces_C1 CHECK ((���������������� >= 0) AND (���������������� <= 100)); 
GO

BULK INSERT dbPlaces
FROM 'C:\Users\���������\Desktop\SQL\1\TPlace.txt'
WITH (fieldterminator = '	', rowterminator = '\n');
GO

select top 1200 * from dbPlaces;
GO

/*
DROP TABLE dbPlaces
GO
*/


